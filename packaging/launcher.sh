#!/usr/bin/env bash
# Автор: Evgenii I, 2026
# Лаунчер fmi-coupling: запускает локальный сервер (если не жив) и открывает
# браузер. FORTE/Flogic не трогает — сервер управляет только FMITerminalBlock.
set -u
APP_DIR=/opt/fmi-coupling
URL=http://127.0.0.1:8765
LOG="$HOME/fmi-coupling/server.log"

mkdir -p "$HOME/fmi-coupling"

# уже жив?
if ! curl -s -o /dev/null --max-time 1 "$URL/api/status"; then
  nohup "$APP_DIR/fmi-coupling-server" >>"$LOG" 2>&1 &
  for i in $(seq 1 40); do
    curl -s -o /dev/null --max-time 1 "$URL/api/status" && break
    sleep 0.25
  done
fi

xdg-open "$URL" >/dev/null 2>&1 &
