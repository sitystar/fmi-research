#!/usr/bin/env bash
# Автор: Evgenii I, 2026
# Запуск fmi-coupling: бинарник сам открывает нативное окно (pywebview).
# Запуск в фоне — окно появится через ~2 секунды.
set -u
exec /opt/fmi-coupling/fmi-coupling-server
