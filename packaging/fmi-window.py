#!/usr/bin/env python3
# Автор: Evgenii I, 2026
"""Нативное окно fmi-coupling (GTK3 + WebKit2).

Запускает сервер в фоне, открывает окно без браузерного UI.
Требует системные пакеты python3-gi, gir1.2-webkit2-4.1 (в Depends deb).
"""
import os
import signal
import subprocess
import sys
import time
import urllib.request

import gi
gi.require_version('Gtk', '3.0')
gi.require_version('WebKit2', '4.1')
from gi.repository import Gtk, WebKit2

SERVER = "/opt/fmi-coupling/fmi-coupling-server"
URL = "http://127.0.0.1:8765"
LOG = os.path.expanduser("~/fmi-coupling/server.log")


def wait_server(timeout=30):
    for _ in range(timeout * 4):
        try:
            urllib.request.urlopen(f"{URL}/api/status", timeout=1)
            return True
        except Exception:
            time.sleep(0.25)
    return False


def main():
    os.makedirs(os.path.dirname(LOG), exist_ok=True)

    # сервер уже жив?
    alive = False
    try:
        urllib.request.urlopen(f"{URL}/api/status", timeout=1)
        alive = True
    except Exception:
        pass

    proc = None
    if not alive:
        logf = open(LOG, "a")
        proc = subprocess.Popen([SERVER], stdout=logf, stderr=logf)
        if not wait_server():
            print("ОШИБКА: сервер не поднялся", file=sys.stderr)
            if proc:
                proc.kill()
            sys.exit(1)

    win = Gtk.Window(title="FMI Coupling — Flogic (IEC 61499, forte) ↔ FMU")
    win.set_default_size(1280, 820)
    win.set_size_request(1024, 600)

    wv = WebKit2.WebView()
    wv.load_uri(URL)
    win.add(wv)
    win.show_all()

    def on_destroy(*_):
        if proc and proc.poll() is None:
            proc.terminate()
            try:
                proc.wait(5)
            except subprocess.TimeoutExpired:
                proc.kill()
        Gtk.main_quit()

    win.connect("destroy", on_destroy)
    signal.signal(signal.SIGINT, signal.SIG_DFL)  # Ctrl+C тоже закрывает
    Gtk.main()


if __name__ == "__main__":
    main()
