#!/usr/bin/env bash
# Автор: Evgenii I, 2026
#
# Сборка десктопного приложения: PyInstaller упаковывает python+tkinter ВНУТРЬ
# бинарника (на целевой машине python ставить не нужно), затем dpkg-deb собирает
# .deb-инсталлятор с ярлыком в меню приложений.
#
# Требования на МАШИНЕ СБОРКИ (однократно):
#   sudo apt install -y python3-tk python3-pip binutils
#   /usr/bin/python3 -m pip install --user pyinstaller   (скрипт сделает сам)
#
# Использование:  scripts/../packaging/build_deb.sh
# Результат:      dist/fmi-coupling-gui_<версия>_amd64.deb
# Установка:      sudo apt install ./dist/fmi-coupling-gui_*_amd64.deb
set -eu
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PY=${FMI_GUI_PY:-/usr/bin/python3}
VER=1.1.3
APP=fmi-coupling-gui

command -v "$PY" >/dev/null || { echo "нет /usr/bin/python3" >&2; exit 2; }
"$PY" -c "import tkinter" 2>/dev/null || {
  echo "НЕТ tkinter: sudo apt install -y python3-tk" >&2; exit 2; }
"$PY" -m PyInstaller --version >/dev/null 2>&1 || {
  echo "ставлю pyinstaller (--user)..."; "$PY" -m pip install ${FMI_GUI_PIP_OPTS:---user} pyinstaller; }

echo "== 1/3 PyInstaller: самодостаточный бинарник (python внутри) =="
cd "$ROOT"
"$PY" -m PyInstaller --onefile --windowed --name "$APP" \
  --distpath build-gui/dist --workpath build-gui/work --specpath build-gui \
  scripts/fmi_gui.py

echo "== 2/3 раскладка пакета =="
PKG="build-gui/pkg/$APP"
rm -rf build-gui/pkg
install -D -m 755 "build-gui/dist/$APP"                       "$PKG/opt/fmi-coupling/$APP"

# связыватель: из сборки репозитория или готового бандла (CI-артефакт fmitb)
FMITB_SRC="${FMI_FMITB_DIR:-$ROOT/build-fmitb}"
if [ -f "$FMITB_SRC/FMITerminalBlock" ]; then
  install -D -m 755 "$FMITB_SRC/FMITerminalBlock"             "$PKG/opt/fmi-coupling/fmitb/FMITerminalBlock"
  for lib in "$FMITB_SRC"/libboost*.so* "$FMITB_SRC"/libfmippim.so*; do
    [ -f "$lib" ] && install -m 755 "$lib"                    "$PKG/opt/fmi-coupling/fmitb/"
  done
  echo "  связыватель: $(basename "$FMITB_SRC") + библиотеки"
else
  echo "ОШИБКА: FMITerminalBlock не найден ($FMITB_SRC) — сборка прервана." >&2
  echo "Локально: scripts/setup.sh; в CI: артефакт fmitb после checkout." >&2
  exit 1
fi
install -D -m 644 packaging/fmi-coupling.desktop              "$PKG/usr/share/applications/fmi-coupling.desktop"
install -D -m 644 packaging/icon.svg                          "$PKG/usr/share/icons/hicolor/scalable/apps/fmi-coupling.svg"
install -D -m 644 /dev/stdin "$PKG/DEBIAN/control" << EOF
Package: $APP
Version: $VER
Architecture: amd64
Maintainer: Evgenii I <EvgeniiI@localhost>
Depends:
Section: science
Priority: optional
Description: GUI for coupling Flogic (IEC 61499, forte) with FMU models
 Self-sufficient: FMITerminalBlock coupler with libraries is included.
 Import FMU, pick model, set ports/duration, live log, trace plot.
 Python and Tk are bundled inside the binary. Data goes to ~/fmi-coupling.
EOF

echo "== 3/3 dpkg-deb =="
mkdir -p dist
dpkg-deb --build --root-owner-group "build-gui/pkg/$APP" "dist/${APP}_${VER}_amd64.deb"
echo
echo "Готово: dist/${APP}_${VER}_amd64.deb"
echo "Установка:  sudo apt install ./dist/${APP}_${VER}_amd64.deb"
echo "Запуск:     ярлык «FMI Coupling GUI» в меню приложений (или /opt/fmi-coupling/$APP)"
