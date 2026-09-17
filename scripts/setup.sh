#!/usr/bin/env bash
# Автор: Evgenii I, 2026
#
# Развёртывание связки на НОВОЙ машине: проверка зависимостей → Boost → сборка
# FMITerminalBlock. Запускать из корня репозитория:
#   scripts/setup.sh
set -eu
ROOT="$(cd "$(dirname "$0")/.." && pwd)"

echo "== 1/3. Инструменты =="
for t in cmake g++ python3 ss unzip; do
  command -v "$t" >/dev/null || { echo "НЕТ: $t — установите и повторите" >&2; exit 2; }
  echo "ок: $t ($($t --version 2>/dev/null | head -1 | cut -d' ' -f2-3))"
done

echo "== 2/3. Boost =="
BOOST_ARGS=()
if ls /usr/lib/x86_64-linux-gnu/libboost_log.so* >/dev/null 2>&1 && [ -d /usr/include/boost/log ]; then
  echo "ок: системный Boost (libboost-log и заголовки на месте)"
elif [ -d "$ROOT/deps/boost/usr" ]; then
  echo "ок: локальный Boost в deps/boost (собранный fetch_boost.sh)"
  BOOST_ARGS=( -DCMAKE_PREFIX_PATH="$ROOT/deps/boost/usr" )
else
  cat >&2 <<'EOF'
НЕТ Boost. Два пути на выбор:
  A) с root:  sudo apt install -y libboost-log-dev libboost-thread-dev \
       libboost-filesystem-dev libboost-date-time-dev libboost-regex-dev
  B) без root: scripts/fetch_boost.sh <версия>   # версию: apt-cache policy libboost-dev
Затем повторите scripts/setup.sh
EOF
  exit 2
fi

echo "== 3/3. Сборка FMITerminalBlock =="
cmake -S "$ROOT/FMITerminalBlock" -B "$ROOT/build-fmitb" \
  "${BOOST_ARGS[@]}" \
  -Dfmipp_PROJECT_DIR="$ROOT/fmipp" \
  -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
  -DBUILD_SWIG=OFF -DBUILD_TESTS=OFF -DFMITerminalBlock_BUILD_TESTS=OFF
cmake --build "$ROOT/build-fmitb" -j"$(nproc)"
[ -x "$ROOT/build-fmitb/FMITerminalBlock" ] && echo "ок: build-fmitb/FMITerminalBlock собран"

echo "== Готово. Дальше: ИНСТРУКЦИЯ.md =="
