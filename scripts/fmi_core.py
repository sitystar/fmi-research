#!/usr/bin/env python3
# Автор: Evgenii I, 2026
"""Ядро связки Flogic ↔ FMU: общая логика для GUI и веб-сервера.

Пути, модели (скан/импорт FMU), аргументы FMITerminalBlock, статус портов Flogic,
парсинг trace, сохранение состояния. Без импорта tkinter/библиотек интерфейса.
"""
import json
import os
import queue
import shutil
import socket
import subprocess
import sys
import threading
import zipfile
import xml.etree.ElementTree as ET
from datetime import datetime

CONFIG_PATH = os.path.expanduser("~/.config/fmi-coupling/config.json")
DEFAULT_WORKDIR = os.path.expanduser("~/fmi-coupling")          # модели и trace
INSTALLED_FMITB = "/opt/fmi-coupling/fmitb/FMITerminalBlock"    # из deb-пакета
TYPES = {"Real": "0", "Integer": "1", "Boolean": "2", "String": "3", "Enumeration": "1"}


def _apply_root(root):
    """Переназначить пути. Связыватель: сборка репозитория (режим разработки)
    или бандл из deb-пакета /opt/fmi-coupling/fmitb."""
    global ROOT, MODELS_DIR, RUNS_DIR, FMITB, BOOST_LIBS, STATE_FILE
    ROOT = os.path.normpath(root)
    os.makedirs(os.path.join(ROOT, "models"), exist_ok=True)
    os.makedirs(os.path.join(root, "runs"), exist_ok=True)
    MODELS_DIR = os.path.join(ROOT, "models")
    RUNS_DIR = os.path.join(ROOT, "runs")
    repo_fmitb = os.path.join(ROOT, "build-fmitb", "FMITerminalBlock")
    FMITB = repo_fmitb if os.path.isfile(repo_fmitb) else INSTALLED_FMITB
    BOOST_LIBS = os.path.join(ROOT, "deps", "boost", "usr", "lib", "x86_64-linux-gnu")
    STATE_FILE = os.path.join(ROOT, "gui_state.json")


def _looks_like_root(p):
    return os.path.isdir(os.path.join(p, "models")) or os.path.isdir(os.path.join(p, "build-fmitb"))


def resolve_root():
    """Где лежит fmi-research: env → ~/.config → рядом со скриптом (режим разработки)."""
    candidates = []
    env = os.environ.get("FMI_RESEARCH_HOME")
    if env:
        candidates.append(env)
    try:
        candidates.append(os.path.normpath(os.path.abspath(json.load(open(CONFIG_PATH))["root"])))
    except Exception:
        pass
    # режим разработки: только если скрипт запущен из репозитория напрямую
    # (в PyInstaller __file__ — временный каталог, проверка не сработает)
    here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if os.path.isdir(os.path.join(here, "build-fmitb")) and os.path.isdir(os.path.join(here, "models")):
        candidates.append(here)
    # ~/fmi-coupling — каталог по умолчанию, принимается ВСЕГДА
    # (структура создаётся при первом обращении)
    return DEFAULT_WORKDIR


def remember_root(path):
    path = os.path.normpath(os.path.abspath(path))
    os.makedirs(os.path.dirname(CONFIG_PATH), exist_ok=True)
    json.dump({"root": path}, open(CONFIG_PATH, "w"))


# стартовая инициализация путей (для режимов без GUI: --scan/--args);
# в GUI она переигрывается через resolve_root()/_apply_root()
_apply_root(resolve_root())


# ---------------------------------------------------------------- модельный слой
class ModelEntry:
    def __init__(self, fmu_dir):
        self.dir = fmu_dir
        self.name, self.inputs, self.outputs, self.parameters = "", [], [], []
        self.parse()

    def parse(self):
        xml_path = os.path.join(self.dir, "modelDescription.xml")
        root = ET.parse(xml_path).getroot()
        self.name = root.get("modelName") or os.path.basename(self.dir)
        for v in root.iter("ScalarVariable"):
            typ = next((TYPES[ch.tag] for ch in v if ch.tag in TYPES), None)
            if typ is None or v.get("name") == "time":
                continue
            entry = (v.get("name"), typ, v.get("description") or "")
            if v.get("causality") == "input":
                self.inputs.append(entry)
            elif v.get("causality") == "output":
                self.outputs.append(entry)
            elif v.get("causality") == "parameter":
                start = ""
                for ch in v:
                    if ch.tag == "Real" and ch.get("start"):
                        start = ch.get("start")
                        break
                self.parameters.append((v.get("name"), start, v.get("description") or ""))


def scan_models():
    if not os.path.isdir(MODELS_DIR):
        return []
    out = []
    for d in sorted(os.listdir(MODELS_DIR)):
        if d.endswith(".fmu.dir") and os.path.isfile(os.path.join(MODELS_DIR, d, "modelDescription.xml")):
            try:
                out.append(ModelEntry(os.path.join(MODELS_DIR, d)))
            except Exception as e:
                print(f"пропуск {d}: {e}", file=sys.stderr)
    return out


def import_fmu(src_path, name_override=None):
    """Распаковка .fmu в models/<stem>.fmu.dir; возвращает ModelEntry."""
    stem = name_override or os.path.splitext(os.path.basename(src_path))[0]
    dest = os.path.join(MODELS_DIR, stem + ".fmu.dir")
    if os.path.exists(dest):
        shutil.rmtree(dest)
    os.makedirs(dest, exist_ok=True)
    with zipfile.ZipFile(src_path) as z:
        z.extractall(dest)
    if not os.path.isfile(os.path.join(dest, "modelDescription.xml")):
        raise RuntimeError("в FMU нет modelDescription.xml — это FMU?")
    return ModelEntry(dest)


def build_argv(entry, inputs, outputs, params):
    """Аргументы FMITerminalBlock (эквивалент scripts/run_fmu.sh)."""
    argv = [FMITB, f"fmu.path=file://{entry.dir}", f"fmu.name={entry.name}",
            "app.startTime=0", "app.directOutputDependency=1"]
    for i, (v, t, _) in enumerate(inputs):
        argv += [f"in.0.{i}={v}", f"in.0.{i}.type={t}",
                 "in.0.protocol=CompactASN.1-TCP", f"in.0.addr={params.get('host', '127.0.0.1')}:{params['in_port']}"]
    for i, (v, t, _) in enumerate(outputs):
        argv += [f"out.0.{i}={v}", f"out.0.{i}.type={t}",
                 "out.0.protocol=CompactASN.1-TCP", f"out.0.addr={params.get('host', '127.0.0.1')}:{params['out_port']}"]
    argv += [f"app.lookAheadTime={params['lookahead']}", f"app.logLevel={params['loglevel']}"]
    for pname, pval in params.get("param_overrides", {}).items():
        argv.append(f"in.default.{pname}={pval}")
    return argv


def ports_ready(out_port, in_port, host="127.0.0.1"):
    for p in (out_port, in_port):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.settimeout(0.4)
            if s.connect_ex((host, p)) != 0:
                return False
    return True


def parse_trace(path):
    """data.csv от FMITB → (имена переменных, времена, {имя: [значения/None]}).
    Пустая ячейка = значение не менялось → forward-fill предыдущим."""
    import csv as _csv
    with open(path, newline="") as f:
        rdr = _csv.reader(f, delimiter=";")
        names = next(rdr)[1:]
        next(rdr)  # строка типов
        times, cols = [], {n: [] for n in names}
        last = {n: None for n in names}
        for r in rdr:
            if not r or not r[0]:
                continue
            try:
                times.append(float(r[0]))
            except ValueError:
                continue
            for n, v in zip(names, r[1:]):
                if v != "":
                    try:
                        last[n] = float(v)
                    except ValueError:
                        pass
                cols[n].append(last[n])
    return names, times, cols


def load_state():
    try:
        return json.load(open(STATE_FILE))
    except Exception:
        return {}


def save_state(st):
    try:
        json.dump(st, open(STATE_FILE, "w"))
    except Exception:
        pass


# ---------------------------------------------------------------- самопроверка без GUI
def selftest(argv):
    if argv[0] == "--scan":
        for m in scan_models():
            print(f"{m.name:20s} входы={[v for v, _, _ in m.inputs]} выходы={[v for v, _, _ in m.outputs]}")
        return 0
    if argv[0] == "--plot-test":
        names, times, cols = parse_trace(argv[1])
        print(f"переменных: {len(names)}, точек времени: {len(times)}")
        for n in names:
            defined = sum(1 for v in cols[n] if v is not None)
            vs = [v for v in cols[n] if v is not None]
            rng = f"{min(vs):.4g}..{max(vs):.4g}" if vs else "-"
            print(f"  {n:12s} определено {defined}/{len(times)}, диапазон {rng}")
        return 0
    if argv[0] == "--args":
        name = argv[1]
        m = next((x for x in scan_models() if x.name == name), None)
        if not m:
            print(f"модель {name} не найдена", file=sys.stderr)
            return 2
        p = dict(in_port=1500, out_port=1499, lookahead=1, loglevel="info")
        for a in build_argv(m, m.inputs, m.outputs, p):
            print(a)
        return 0
    print(__doc__)
    return 2


# ---------------------------------------------------------------- самопроверка без GUI
def selftest(argv):
    if argv[0] == "--scan":
        for m in scan_models():
            print(f"{m.name:20s} входы={[v for v, _, _ in m.inputs]} выходы={[v for v, _, _ in m.outputs]}")
        return 0
    if argv[0] == "--plot-test":
        names, times, cols = parse_trace(argv[1])
        print(f"переменных: {len(names)}, точек времени: {len(times)}")
        for n in names:
            defined = sum(1 for v in cols[n] if v is not None)
            vs = [v for v in cols[n] if v is not None]
            rng = f"{min(vs):.4g}..{max(vs):.4g}" if vs else "-"
            print(f"  {n:12s} определено {defined}/{len(times)}, диапазон {rng}")
        return 0
    if argv[0] == "--args":
        m = next((x for x in scan_models() if x.name == argv[1]), None)
        if not m:
            print(f"модель {argv[1]} не найдена", file=sys.stderr)
            return 2
        p = dict(in_port=1500, out_port=1499, lookahead=1, loglevel="info")
        for a in build_argv(m, m.inputs, m.outputs, p):
            print(a)
        return 0
    print(__doc__)
    return 2


if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        sys.exit(selftest(sys.argv[1:]))
    print(__doc__)
    sys.exit(2)
