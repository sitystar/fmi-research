#!/usr/bin/env bash
# Автор: Evgenii I, 2026
#
# Локальная (БЕЗ root) установка Boost для сборки FMITerminalBlock — для машин,
# где нельзя поставить системные libboost-*-dev. Скачивает deb-пакеты, распаковывает
# в deps/boost и генерирует CMake-конфиги компонентов.
#
# Использование:  scripts/fetch_boost.sh <версия>
#   версию узнать: apt-cache policy libboost-dev | head -2   (например 1.90.0)
set -eu
[ $# -eq 1 ] || { grep '^#' "$0" | sed 's/^# \{0,1\}//'; exit 2; }
VER="$1"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
mkdir -p "$ROOT/deps/debs" "$ROOT/deps/boost"
cd "$ROOT/deps/debs"

echo "Скачиваю Boost $VER (без root)..."
apt-get download \
  "libboost${VER}-dev" \
  "libboost-log-dev" "libboost-log${VER}" \
  "libboost-filesystem-dev" "libboost-filesystem${VER}" \
  "libboost-date-time-dev" \
  "libboost-regex-dev" "libboost-regex${VER}" \
  "libboost-thread-dev" "libboost-thread${VER}"

echo "Распаковываю в deps/boost ..."
for d in ./*.deb; do dpkg -x "$d" "$ROOT/deps/boost"; done

echo "Генерирую CMake-конфиги компонентов..."
python3 "$ROOT/scripts/gen_boost_configs.py" "$VER" "$ROOT/deps/boost"
echo "Готово: $ROOT/deps/boost/usr  (далее scripts/setup.sh подхватит сам)"
