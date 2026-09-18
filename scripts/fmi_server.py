#!/usr/bin/env python3
# Автор: Evgenii I, 2026
"""Локальный веб-сервер связки Flogic (IEC 61499, forte) ↔ FMU.

REST/WS API поверх fmi_core + раздача статики веб-интерфейса (web/dist).
Слушает только 127.0.0.1:8765. Запуск: python3 fmi_server.py
(FMI_SERVER_PORT / FMI_RESEARCH_HOME — переменными окружения).

Правило то же: Flogic запускает только оркестратор — сервер управляет
исключительно FMITerminalBlock.
"""
import asyncio
import os
import subprocess
import threading
import time
from collections import deque
from datetime import datetime

import uvicorn
from fastapi import FastAPI, UploadFile, WebSocket, WebSocketDisconnect
from fastapi.responses import JSONResponse
from fastapi.staticfiles import StaticFiles

import fmi_core as core

PORT = int(os.environ.get("FMI_SERVER_PORT", "8765"))

app = FastAPI(title="fmi-coupling", docs_url=None, redoc_url=None)

# ---------------------------------------------------------------- состояние прогона
class RunState:
    def __init__(self):
        self.proc = None
        self.run_dir = None
        self.model = None
        self.started_at = None
        self.log = deque(maxlen=5000)   # (n, строка) — n для передачи «с места»
        self.lock = threading.Lock()

    @property
    def running(self):
        return self.proc is not None and self.proc.poll() is None

    def append_log(self, line):
        with self.lock:
            self.log.append((len(self.log), line))


run_state = RunState()


def _tail_proc(proc, log_path):
    """Хвост stdout процесса в буфер + файл."""
    with open(log_path, "rb") as f:
        while proc.poll() is None:
            line = f.readline()
            if line:
                try:
                    run_state.append_log(line.decode("utf-8", "replace"))
                except Exception:
                    pass
            else:
                time.sleep(0.2)


def _watchdog(proc, seconds):
    time.sleep(seconds)
    if proc.poll() is None:
        proc.terminate()
        try:
            proc.wait(5)
        except subprocess.TimeoutExpired:
            proc.kill()


# ---------------------------------------------------------------- API
@app.get("/api/models")
def api_models():
    return [{"name": m.name,
             "dir": os.path.relpath(m.dir, core.ROOT),
             "inputs": [{"name": n, "type": t} for n, t in m.inputs],
             "outputs": [{"name": n, "type": t} for n, t in m.outputs]}
            for m in core.scan_models()]


@app.post("/api/import")
async def api_import(file: UploadFile):
    dest_zip = os.path.join("/tmp", file.filename)
    with open(dest_zip, "wb") as f:
        f.write(await file.read())
    try:
        entry = core.import_fmu(dest_zip)
    except Exception as e:
        return JSONResponse(status_code=400, content={"error": str(e)})
    finally:
        os.unlink(dest_zip)
    return {"name": entry.name, "dir": os.path.relpath(entry.dir, core.ROOT)}


@app.get("/api/status")
def api_status():
    return {"root": core.ROOT,
            "fmitb": core.FMITB,
            "forte_ready": core.ports_ready(_params_cache["out_port"], _params_cache["in_port"]),
            "running": run_state.running,
            "model": run_state.model,
            "run_dir": run_state.run_dir}


_params_cache = {"out_port": 1499, "in_port": 1500}


@app.post("/api/root")
def api_root(body: dict):
    path = body.get("path", "")
    if not core._looks_like_root(path):
        return JSONResponse(status_code=400,
                            content={"error": "нет каталогов models/build-fmitb — это не рабочий каталог"})
    path = os.path.normpath(path)
    core._apply_root(path)
    core.remember_root(path)
    return {"root": core.ROOT}


@app.post("/api/run")
def api_run(body: dict):
    if run_state.running:
        return JSONResponse(status_code=409, content={"error": "прогон уже идёт — сначала /api/stop"})
    name = body.get("model")
    entry = next((m for m in core.scan_models() if m.name == name), None)
    if not entry:
        return JSONResponse(status_code=404, content={"error": f"модель {name} не найдена"})
    p = dict(out_port=int(body.get("out_port", 1499)),
             in_port=int(body.get("in_port", 1500)),
             lookahead=float(body.get("lookahead", 1)),
             loglevel=body.get("loglevel", "info"))
    _params_cache.update(out_port=p["out_port"], in_port=p["in_port"])
    duration = float(body.get("duration", 0) or 0)

    if not core.ports_ready(p["out_port"], p["in_port"]):
        return JSONResponse(status_code=409, content={
            "error": f"Flogic не слушает порты {p['out_port']}/{p['in_port']} "
                     "(должен быть запущен оркестратором с приложением)"})

    run_state.run_dir = os.path.join(core.RUNS_DIR, f"{entry.name}-{datetime.now().strftime('%d%H%M%S')}")
    os.makedirs(run_state.run_dir, exist_ok=True)
    argv = core.build_argv(entry, entry.inputs, entry.outputs, p)
    argv.append(f"app.dataFile={os.path.join(run_state.run_dir, 'data.csv')}")

    env = os.environ.copy()
    env["LD_LIBRARY_PATH"] = os.path.dirname(core.FMITB) + os.pathsep + core.BOOST_LIBS + os.pathsep + env.get("LD_LIBRARY_PATH", "")
    logf = open(os.path.join(run_state.run_dir, "fmitb.log"), "w")
    run_state.log.clear()
    run_state.model = entry.name
    run_state.started_at = datetime.now().isoformat(timespec="seconds")
    run_state.append_log(f"=== запуск {entry.name}, trace: {run_state.run_dir}/data.csv ===\n")
    run_state.proc = subprocess.Popen(argv, stdout=logf, stderr=subprocess.STDOUT, env=env, cwd=core.ROOT)
    threading.Thread(target=_tail_proc, args=(run_state.proc, os.path.join(run_state.run_dir, "fmitb.log")), daemon=True).start()
    if duration > 0:
        threading.Thread(target=_watchdog, args=(run_state.proc, duration), daemon=True).start()
    return {"run_dir": run_state.run_dir, "pid": run_state.proc.pid}


@app.post("/api/stop")
def api_stop():
    proc = run_state.proc
    if proc and proc.poll() is None:
        proc.terminate()
        try:
            proc.wait(5)
        except subprocess.TimeoutExpired:
            proc.kill()
    if run_state.proc is not None:
        run_state.proc = None
        run_state.append_log(f"=== остановлено, trace: {run_state.run_dir}/data.csv ===\n")
    return {"running": run_state.running}


@app.get("/api/trace")
def api_trace(run: str | None = None):
    """Разобранный trace: имена, времена, серии (None = значение не определено)."""
    d = run or run_state.run_dir
    if not d:
        return JSONResponse(status_code=404, content={"error": "прогонов ещё не было"})
    path = os.path.join(d, "data.csv")
    if not os.path.isfile(path):
        return JSONResponse(status_code=404, content={"error": "data.csv не найден"})
    names, times, cols = core.parse_trace(path)
    return {"names": names, "times": times, "series": cols,
            "decimated": _decimate(names, times, cols)}


def _decimate(names, times, cols, max_points=2000):
    """Прореживание для графика: не более max_points точек на серию."""
    step = max(1, len(times) // max_points)
    return {"step": step,
            "times": times[::step],
            "series": {n: [None if v is None else round(v, 6) for v in cols[n][::step]] for n in names}}


@app.websocket("/api/logs")
async def ws_logs(ws: WebSocket):
    await ws.accept()
    last = 0
    try:
        while True:
            with run_state.lock:
                items = [(n, l) for n, l in run_state.log if n >= last]
                if items:
                    last = items[-1][0] + 1
            for _, line in items:
                await ws.send_text(line)
            await asyncio.sleep(0.3)
    except WebSocketDisconnect:
        pass


# ---------------------------------------------------------------- статика веб-интерфейса
for ui_dir in (os.path.join(core.ROOT, "web", "dist"),
               "/opt/fmi-coupling/ui"):
    if os.path.isdir(ui_dir):
        app.mount("/", StaticFiles(directory=ui_dir, html=True), name="ui")
        break


if __name__ == "__main__":
    import threading
    import time as _time
    import urllib.request

    def _serve():
        uvicorn.run(app, host="127.0.0.1", port=PORT, log_level="warning")

    threading.Thread(target=_serve, daemon=True).start()

    # ждём готовности сервера
    for _ in range(60):
        _time.sleep(0.25)
        try:
            urllib.request.urlopen(f"http://127.0.0.1:{PORT}/api/status", timeout=1)
            break
        except Exception:
            continue

    try:
        import webview
        webview.create_window(
            "FMI Coupling — Flogic (IEC 61499, forte) ↔ FMU",
            f"http://127.0.0.1:{PORT}",
            width=1280, height=820, min_size=(1024, 600),
        )
        webview.start()  # блокирующий вызов; окно закрыто → сервер останавливается
    except ImportError:
        # запасной вариант: браузер
        import webbrowser
        print(f"fmi-coupling server → http://127.0.0.1:{PORT}  (корень: {core.ROOT})")
        webbrowser.open(f"http://127.0.0.1:{PORT}")
        try:
            while True:
                _time.sleep(1)
        except KeyboardInterrupt:
            pass
