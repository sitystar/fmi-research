#!/usr/bin/env bash
# Автор: Evgenii I, 2026
# Универсальный запуск связки FORTE ↔ FMU. Любая модель — БЕЗ правок этого скрипта.
#
# Использование:
#   scripts/run_fmu.sh <каталог_FMU> <имя_модели> ["auto"|входы] ["auto"|выходы] [сек]
#
#     входы/выходы — какие переменные модели соединяются с FORTE:
#       auto       — взять ВСЕ входы/выходы из modelDescription.xml модели (по умолчанию)
#       var:type,… — явный список через запятую (type: 0=Real, 1=Integer, 2=Bool)
#                   нужен, когда подключаем не всё или важен порядок
#     [сек]        — длительность. Не задано или 0 = без счётчика (остановка Ctrl-C)
#
# Примеры:
#   scripts/run_fmu.sh models/Tank.fmu.dir Tank                  # всё автоматически
#   scripts/run_fmu.sh models/Tank.fmu.dir Tank auto auto 60     # всё входы/выходы, 60с
#   scripts/run_fmu.sh models/M.fmu.dir M "u:0" "y1:0,y2:2" 120  # явный список
#
# ВАЖНО: параметры модели (коэффициенты уравнений) нигде не перечисляются — они
# заданы в .mo при экспорте. Здесь только входы/выходы (чем управляем и что читаем).
#
# Скрипт ждёт готовности FORTE и управляет только FMITerminalBlock.
#
# Настройки окружением:
#   IN_PORT=1500 OUT_PORT=1499      — порты SERVER_ в приложении FORTE
#   WAIT_SECS=60                    — сколько ждать готовности FORTE
#   LOOKAHEAD=1                     — горизонт предсказания FMITB, с
#   RUN_DIR=...                     — куда класть артефакты (по умолч. runs/<модель>-<время>)
set -u
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
[ $# -ge 2 ] || { grep '^#' "$0" | sed 's/^# \{0,1\}//'; exit 2; }

FMU_DIR="$1"; FMU_NAME="$2"
INS="${3:-auto}"; OUTS="${4:-auto}"; DUR="${5:-0}"
# допуск: третий аргумент — число (duration) при опущенных списках
if [[ "$INS" =~ ^[0-9]+$ ]]; then DUR="$INS"; INS=auto; OUTS=auto; fi
IN_PORT="${IN_PORT:-1500}"; OUT_PORT="${OUT_PORT:-1499}"
WAIT_SECS="${WAIT_SECS:-60}"; LOOKAHEAD="${LOOKAHEAD:-1}"
FMITB="$ROOT/build-fmitb/FMITerminalBlock"
export LD_LIBRARY_PATH="$ROOT/deps/boost/usr/lib/x86_64-linux-gnu${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"

# --- автособирание списка переменных из modelDescription.xml ---
resolve_list() { # $1: auto|список, $2: input|output
  if [ "$1" != "auto" ]; then echo "$1"; return; fi
  python3 - "$ROOT/$FMU_DIR/modelDescription.xml" "$2" << 'PYEOF'
import sys, xml.etree.ElementTree as ET
types = {"Real": "0", "Integer": "1", "Boolean": "2", "String": "3"}
items = []
for v in ET.parse(sys.argv[1]).getroot().iter("ScalarVariable"):
    if v.get("causality") != sys.argv[2]:
        continue
    typ = next((types[ch.tag] for ch in v if ch.tag in types), None)
    if typ and v.get("name") != "time":
        items.append(f"{v.get('name')}:{typ}")
print(",".join(items))
PYEOF
}
INS="$(resolve_list "$INS" input)"
OUTS="$(resolve_list "$OUTS" output)"
[ -n "$INS" ]  || { echo "ОШИБКА: у модели не найдено входов (causality=input)" >&2; exit 2; }
[ -n "$OUTS" ] || { echo "ОШИБКА: у модели не найдено выходов (causality=output)" >&2; exit 2; }
echo "Входы модели  (FORTE → модель): $INS"
echo "Выходы модели (модель → FORTE): $OUTS"

# --- собрать аргументы каналов из списков var:type ---
chan_args=()
split_list() { echo "$1" | tr ',' '\n'; }
i=0; while IFS=: read -r v t; do [ -n "$v" ] && chan_args+=( "in.0.$i=$v" "in.0.$i.type=$t" "in.0.protocol=CompactASN.1-TCP" "in.0.addr=127.0.0.1:$IN_PORT" ) && i=$((i+1)); done < <(split_list "$INS")
i=0; while IFS=: read -r v t; do [ -n "$v" ] && chan_args+=( "out.0.$i=$v" "out.0.$i.type=$t" "out.0.protocol=CompactASN.1-TCP" "out.0.addr=127.0.0.1:$OUT_PORT" ) && i=$((i+1)); done < <(split_list "$OUTS")

# --- health-check внешнего FORTE (оркестратор) ---
port_open() { ss -ltn 2>/dev/null | grep -qE ":$1\b"; }
echo "Жду FORTE (оркестратор): порты $OUT_PORT/$IN_PORT, максимум ${WAIT_SECS}s..."
w=0; until port_open "$OUT_PORT" && port_open "$IN_PORT"; do
  sleep 1; w=$((w+1))
  if [ "$w" -ge "$WAIT_SECS" ]; then
    echo "ОШИБКА: FORTE не слушает $OUT_PORT/$IN_PORT за ${WAIT_SECS}s." >&2
    echo "Поднимите оркестратор с приложением, слушающим эти порты, и повторите." >&2
    exit 2
  fi
done

RUN="${RUN_DIR:-$ROOT/runs/$(basename "$FMU_NAME")-$(date +%d%H%M%S)}"
mkdir -p "$RUN"

FMITB_ARGS=( "fmu.path=file://$ROOT/$FMU_DIR" "fmu.name=$FMU_NAME"
  app.startTime=0 app.directOutputDependency=1 "${chan_args[@]}"
  "app.lookAheadTime=$LOOKAHEAD" "app.dataFile=$RUN/data.csv" app.logLevel=info )

stop_fmitb() { [ -n "${FMITB_PID:-}" ] && kill -TERM "$FMITB_PID" 2>/dev/null; }
trap stop_fmitb INT TERM

if [ "$DUR" = "0" ]; then
  echo "Гоню $FMU_NAME без счётчика — остановите Ctrl-C. Артефакты: $RUN"
  "$FMITB" "${FMITB_ARGS[@]}" > "$RUN/fmitb.log" 2>&1 &
  FMITB_PID=$!
  wait "$FMITB_PID"
  trap - INT TERM
else
  echo "Гоню $FMU_NAME ${DUR}s → $RUN"
  "$FMITB" "${FMITB_ARGS[@]}" > "$RUN/fmitb.log" 2>&1 &
  FMITB_PID=$!
  ( sleep "$DUR"; stop_fmitb ) &
  WATCHDOG=$!
  wait "$FMITB_PID"
  kill "$WATCHDOG" 2>/dev/null
  trap - INT TERM
fi

echo
echo "Трасса:    $RUN/data.csv"
echo "Лог FMITB: $RUN/fmitb.log"
