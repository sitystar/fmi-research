#!/usr/bin/env python3
# Автор: Evgenii I, 2026
"""
Графический интерфейс связки FORTE ↔ FMU (fmi-research).

Возможности:
  · импорт FMU: выбор .fmu → распаковка в models/<имя>.fmu.dir;
  · список импортированных моделей (сканирование models/);
  · выбор переменных (входы/выходы) и параметров запуска, которые раньше
    задавались в консоли (порты, длительность, lookAhead, лог);
  · запуск/остановка FMITerminalBlock, живой хвост лога, открытие trace.

АРХИТЕКТУРНОЕ ПРАВИЛО: Flogic (IEC 61499, forte) (IEC 61499, forte) запускается и останавливается ТОЛЬКО оркестратором.
GUI лишь проверяет готовность его портов и управляет FMITerminalBlock.

Запуск: /usr/bin/python3 scripts/fmi_gui.py        (нужен пакет python3-tk)
Без GUI (проверка логики): --scan | --args <ИмяМодели>
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
    ROOT = root
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
    import glob
    candidates = []
    env = os.environ.get("FMI_RESEARCH_HOME")
    if env:
        candidates.append(env)
    try:
        candidates.append(json.load(open(CONFIG_PATH))["root"])
    except Exception:
        pass
    # режим разработки: скрипт лежит внутри fmi-research/scripts
    here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if _looks_like_root(here):
        candidates.append(here)
    # типичные места рядом с домашней папкой
    candidates += sorted(glob.glob(os.path.expanduser("~/*/fmi-research")))
    for c in candidates:
        if c and _looks_like_root(c):
            return c
    return None


def remember_root(path):
    os.makedirs(os.path.dirname(CONFIG_PATH), exist_ok=True)
    json.dump({"root": path}, open(CONFIG_PATH, "w"))


# стартовая инициализация путей (для режимов без GUI: --scan/--args);
# в GUI она переигрывается через resolve_root()/_apply_root()
_apply_root(resolve_root() or os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


# ---------------------------------------------------------------- модельный слой
class ModelEntry:
    def __init__(self, fmu_dir):
        self.dir = fmu_dir
        self.name, self.inputs, self.outputs = "", [], []
        self.parse()

    def parse(self):
        xml_path = os.path.join(self.dir, "modelDescription.xml")
        root = ET.parse(xml_path).getroot()
        self.name = root.get("modelName") or os.path.basename(self.dir)
        for v in root.iter("ScalarVariable"):
            typ = next((TYPES[ch.tag] for ch in v if ch.tag in TYPES), None)
            if typ is None or v.get("name") == "time":
                continue
            entry = (v.get("name"), typ)
            if v.get("causality") == "input":
                self.inputs.append(entry)
            elif v.get("causality") == "output":
                self.outputs.append(entry)


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
    for i, (v, t) in enumerate(inputs):
        argv += [f"in.0.{i}={v}", f"in.0.{i}.type={t}",
                 "in.0.protocol=CompactASN.1-TCP", f"in.0.addr=127.0.0.1:{params['in_port']}"]
    for i, (v, t) in enumerate(outputs):
        argv += [f"out.0.{i}={v}", f"out.0.{i}.type={t}",
                 "out.0.protocol=CompactASN.1-TCP", f"out.0.addr=127.0.0.1:{params['out_port']}"]
    argv += [f"app.lookAheadTime={params['lookahead']}", f"app.logLevel={params['loglevel']}"]
    return argv


def ports_ready(out_port, in_port):
    for p in (out_port, in_port):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.settimeout(0.4)
            if s.connect_ex(("127.0.0.1", p)) != 0:
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
            print(f"{m.name:20s} входы={[v for v, _ in m.inputs]} выходы={[v for v, _ in m.outputs]}")
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


# ---------------------------------------------------------------- GUI
def run_gui():
    import tkinter as tk
    from tkinter import filedialog, messagebox, ttk

    root_path = resolve_root()
    if not root_path:
        # установленное приложение: рабочий каталог по умолчанию создаём тихо
        root_path = DEFAULT_WORKDIR
        os.makedirs(os.path.join(root_path, "models"), exist_ok=True)
        os.makedirs(os.path.join(root_path, "runs"), exist_ok=True)
        remember_root(root_path)
    _apply_root(root_path)

    st = load_state()
    models = scan_models()
    runner = {"proc": None, "logq": queue.Queue(), "run_dir": None, "thread": None}

    app = tk.Tk()
    app.title(f"fmi-research — связка Flogic (IEC 61499, forte) ↔ FMU  [{os.path.basename(root_path)}]")
    app.geometry("1000x640")

    # --- верх
    top = ttk.Frame(app, padding=6)
    top.pack(fill=tk.X)
    ttk.Label(top, text="Рабочий каталог (модели, trace):", font=("", 10, "bold")).pack(side=tk.LEFT)
    dir_var = tk.StringVar(value=root_path)
    ttk.Label(top, textvariable=dir_var, foreground="#0a5a0a").pack(side=tk.LEFT, padx=12)
    ttk.Button(top, text="Сменить каталог…", command=lambda: change_root()).pack(side=tk.RIGHT, padx=3)
    ttk.Button(top, text="Импорт FMU…", command=lambda: do_import()).pack(side=tk.RIGHT, padx=3)
    ttk.Button(top, text="Обновить список", command=lambda: refresh()).pack(side=tk.RIGHT, padx=3)

    # --- нижние полосы (запаковываются первыми после шапки: лог — самый низ
    #     на всю ширину, над ним полоса кнопок; затем уже боковые панели)
    logtxt = tk.Text(app, height=14, state=tk.DISABLED, wrap=tk.NONE)
    logtxt.pack(side=tk.BOTTOM, fill=tk.BOTH, expand=True, padx=6, pady=(0, 6))

    bf = ttk.Frame(app, padding=(6, 2))
    bf.pack(side=tk.BOTTOM, fill=tk.X)
    run_btn = ttk.Button(bf, text="▶ Запустить", command=lambda: do_run())
    run_btn.pack(side=tk.LEFT, padx=3)
    stop_btn = ttk.Button(bf, text="■ Остановить", command=lambda: do_stop(), state=tk.DISABLED)
    stop_btn.pack(side=tk.LEFT, padx=3)
    ttk.Button(bf, text="График trace", command=lambda: show_plot()).pack(side=tk.LEFT, padx=3)
    ttk.Button(bf, text="data.csv", command=lambda: do_open_trace()).pack(side=tk.LEFT, padx=3)

    # --- левая колонка
    left = ttk.Frame(app, padding=6)
    left.pack(side=tk.LEFT, fill=tk.Y)
    listfrm = ttk.Frame(left)
    listfrm.pack(fill=tk.Y, expand=True)
    model_list = tk.Listbox(listfrm, width=28, exportselection=False)
    model_sb = ttk.Scrollbar(listfrm, orient=tk.VERTICAL, command=model_list.yview)
    model_list.configure(yscrollcommand=model_sb.set)
    model_list.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
    model_sb.pack(side=tk.LEFT, fill=tk.Y)
    model_list.bind("<<ListboxSelect>>", lambda e: on_select())
    forte_lbl = ttk.Label(left, text="FORTE: ?")
    forte_lbl.pack(pady=4)

    def change_root():
        nonlocal root_path
        p = filedialog.askdirectory(title="Каталог fmi-research")
        if p and _looks_like_root(p):
            remember_root(p)
            root_path = p
            _apply_root(p)
            dir_var.set(p)
            refresh()
        elif p:
            messagebox.showwarning("Каталог", "В выбранном каталоге нет build-fmitb и models — это не fmi-research?")

    # --- правая колонка
    right = ttk.Frame(app, padding=6)
    right.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
    info = ttk.Label(right, text="Выберите модель слева", wraplength=560)
    info.pack(anchor=tk.W)

    varsfrm = ttk.Frame(right)
    varsfrm.pack(fill=tk.X, pady=4)
    ttk.Label(varsfrm, text="Входы (Flogic (IEC 61499, forte) → модель):").grid(row=0, column=0, sticky=tk.W)
    ttk.Label(varsfrm, text="Выходы (модель → Flogic (IEC 61499, forte)):").grid(row=0, column=2, sticky=tk.W, padx=(16, 0))
    in_box = ttk.Treeview(varsfrm, columns=("n", "t"), show="headings", height=12)
    in_box.heading("n", text="переменная"); in_box.heading("t", text="тип")
    in_box.column("n", width=170); in_box.column("t", width=60)
    in_sb = ttk.Scrollbar(varsfrm, orient=tk.VERTICAL, command=in_box.yview)
    in_box.configure(yscrollcommand=in_sb.set)
    in_box.grid(row=1, column=0, sticky="nsw")
    in_sb.grid(row=1, column=1, sticky="ns")
    out_box = ttk.Treeview(varsfrm, columns=("n", "t"), show="headings", height=12)
    out_box.heading("n", text="переменная"); out_box.heading("t", text="тип")
    out_box.column("n", width=170); out_box.column("t", width=60)
    out_sb = ttk.Scrollbar(varsfrm, orient=tk.VERTICAL, command=out_box.yview)
    out_box.configure(yscrollcommand=out_sb.set)
    out_box.grid(row=1, column=2, sticky="nsw", padx=(16, 0))
    out_sb.grid(row=1, column=3, sticky="ns")

    # --- параметры
    pf = ttk.LabelFrame(right, text="Параметры запуска", padding=6)
    pf.pack(fill=tk.X, pady=4)
    ttk.Label(pf, text="Порт приёма (OUT):").grid(row=0, column=0, sticky=tk.W)
    out_port_var = tk.StringVar(value=str(st.get("out_port", 1499)))
    ttk.Entry(pf, textvariable=out_port_var, width=7).grid(row=0, column=1)
    ttk.Label(pf, text="Порт отправки (IN):").grid(row=0, column=2, sticky=tk.W, padx=(12, 0))
    in_port_var = tk.StringVar(value=str(st.get("in_port", 1500)))
    ttk.Entry(pf, textvariable=in_port_var, width=7).grid(row=0, column=3)
    ttk.Label(pf, text="Длительность, с (0 = до «Стоп»):").grid(row=1, column=0, sticky=tk.W)
    dur_var = tk.StringVar(value=str(st.get("duration", 0)))
    ttk.Entry(pf, textvariable=dur_var, width=7).grid(row=1, column=1)
    ttk.Label(pf, text="lookAheadTime, с:").grid(row=1, column=2, sticky=tk.W, padx=(12, 0))
    la_var = tk.StringVar(value=str(st.get("lookahead", 1)))
    ttk.Entry(pf, textvariable=la_var, width=7).grid(row=1, column=3)
    ttk.Label(pf, text="Лог:").grid(row=2, column=0, sticky=tk.W)
    log_var = tk.StringVar(value=st.get("loglevel", "info"))
    ttk.Combobox(pf, textvariable=log_var, values=("info", "debug"), width=7, state="readonly").grid(row=2, column=1)

    # ---------- логика
    def cur_model():
        sel = model_list.curselection()
        return models[sel[0]] if sel else None

    def refresh(select=None):
        nonlocal models
        models = scan_models()
        model_list.delete(0, tk.END)
        for m in models:
            model_list.insert(tk.END, f"{m.name}  ({len(m.inputs)}вх/{len(m.outputs)}вых)")
        if select:
            for i, m in enumerate(models):
                if m.name == select:
                    model_list.selection_set(i)
        on_select()

    def on_select():
        m = cur_model()
        in_box.delete(*in_box.get_children()); out_box.delete(*out_box.get_children())
        if not m:
            info.config(text="Выберите модель слева")
            return
        info.config(text=f"Модель: {m.name}   каталог: {os.path.relpath(m.dir, ROOT)}", wraplength=560)
        for n, t in m.inputs:
            in_box.insert("", tk.END, values=(f"SD_{len(in_box.get_children())+1}: {n}", "Real" if t == "0" else {"1": "Int", "2": "Bool", "3": "Str"}.get(t, t)))
        for n, t in m.outputs:
            out_box.insert("", tk.END, values=(f"RD_{len(out_box.get_children())+1}: {n}", "Real" if t == "0" else {"1": "Int", "2": "Bool", "3": "Str"}.get(t, t)))

    def do_import():
        src = filedialog.askopenfilename(title="Выберите FMU", filetypes=[("FMU", "*.fmu"), ("Все файлы", "*.*")])
        if not src:
            return
        try:
            entry = import_fmu(src)
        except Exception as e:
            messagebox.showerror("Импорт", f"Не удалось: {e}")
            return
        refresh(select=entry.name)
        messagebox.showinfo("Импорт", f"Импортировано: {entry.name}\n{os.path.relpath(entry.dir, ROOT)}")

    def params():
        return dict(out_port=int(out_port_var.get()), in_port=int(in_port_var.get()),
                    lookahead=float(la_var.get()), loglevel=log_var.get())

    def do_run():
        m = cur_model()
        if not m:
            return
        if runner["proc"] is not None:
            return
        p = params()
        if not ports_ready(p["out_port"], p["in_port"]):
            if not messagebox.askyesno("Flogic (IEC 61499, forte) не найден",
                    f"Порты {p['out_port']}/{p['in_port']} не слушаются.\n"
                    "Flogic (IEC 61499, forte) должен быть запущен оркестратором с приложением.\nЗапустить всё равно?"):
                return
        save_state({**p, "duration": dur_var.get()})
        runner["run_dir"] = os.path.join(RUNS_DIR, f"{m.name}-{datetime.now().strftime('%d%H%M%S')}")
        os.makedirs(runner["run_dir"], exist_ok=True)
        argv = build_argv(m, m.inputs, m.outputs, p)
        argv.append(f"app.dataFile={os.path.join(runner['run_dir'], 'data.csv')}")
        env = os.environ.copy()
        env["LD_LIBRARY_PATH"] = os.path.dirname(FMITB) + os.pathsep + BOOST_LIBS + os.pathsep + env.get("LD_LIBRARY_PATH", "")
        logf = open(os.path.join(runner["run_dir"], "fmitb.log"), "w")
        logtxt.config(state=tk.NORMAL); logtxt.delete("1.0", tk.END); logtxt.config(state=tk.DISABLED)
        runner["proc"] = subprocess.Popen(argv, stdout=logf, stderr=subprocess.STDOUT, env=env, cwd=ROOT)
        dur = float(dur_var.get() or 0)
        threading.Thread(target=_tail, args=(os.path.join(runner["run_dir"], "fmitb.log"), dur, runner["proc"]), daemon=True).start()
        run_btn.config(state=tk.DISABLED); stop_btn.config(state=tk.NORMAL)
        append_log(f"=== запуск {m.name}, trace: {runner['run_dir']}/data.csv ===\n")

    def _tail(logpath, dur, proc):
        with open(logpath) as f:
            deadline = None if dur <= 0 else __import__("time").monotonic() + dur
            while proc.poll() is None:
                line = f.readline()
                if line:
                    runner["logq"].put(line)
                else:
                    __import__("time").sleep(0.2)
                    if deadline and __import__("time").monotonic() > deadline:
                        do_stop()
                        break

    def do_stop():
        proc = runner["proc"]
        if proc and proc.poll() is None:
            proc.terminate()
            try:
                proc.wait(5)
            except subprocess.TimeoutExpired:
                proc.kill()
        runner["proc"] = None
        run_btn.config(state=tk.NORMAL); stop_btn.config(state=tk.DISABLED)
        append_log(f"=== остановлено, trace: {runner['run_dir']}/data.csv ===\n")

    def show_plot():
        path = None
        if runner["run_dir"]:
            p = os.path.join(runner["run_dir"], "data.csv")
            path = p if os.path.isfile(p) else None
        if not path:
            path = filedialog.askopenfilename(title="Trace (data.csv)",
                                              filetypes=[("CSV trace", "data.csv"), ("Все файлы", "*.*")])
        if not path:
            return
        try:
            names, times, cols = parse_trace(path)
        except Exception as e:
            messagebox.showerror("График", f"Не удалось прочитать trace: {e}")
            return
        if not times:
            messagebox.showwarning("График", "Trace пуст")
            return
        win = tk.Toplevel(app)
        win.title(f"График trace — {os.path.basename(os.path.dirname(path)) or path}")
        W, H = 940, 540
        cv = tk.Canvas(win, width=W, height=H, bg="white", highlightthickness=0)
        cv.pack()
        ml, mr, mt, mb = 60, 14, 34, 36
        tmin, tmax = times[0], (times[-1] or times[0] + 1)
        ys = [v for serie in cols.values() for v in serie if v is not None] or [0.0, 1.0]
        ymin, ymax = min(ys), max(ys)
        if ymin == ymax:
            ymax = ymin + 1.0
        span_t = (tmax - tmin) or 1.0
        span_y = (ymax - ymin) or 1.0

        def X(tt):
            return ml + (tt - tmin) / span_t * (W - ml - mr)

        def Y(v):
            return H - mb - (v - ymin) / span_y * (H - mt - mb)

        for i in range(6):
            yy = mt + i * (H - mt - mb) / 5
            cv.create_line(ml, yy, W - mr, yy, fill="#e9e9e9")
            cv.create_text(ml - 6, yy, text=f"{ymax - i * span_y / 5:.4g}", anchor=tk.E, font=("", 8))
        for i in range(6):
            xx = ml + i * (W - ml - mr) / 5
            cv.create_line(xx, mt, xx, H - mb, fill="#f2f2f2")
            cv.create_text(xx, H - mb + 16, text=f"{tmin + i * span_t / 5:.4g}", font=("", 8))
        cv.create_line(ml, mt, ml, H - mb, width=2)
        cv.create_line(ml, H - mb, W - mr, H - mb, width=2)
        palette = ["#1f77b4", "#d62728", "#2ca02c", "#9467bd", "#ff7f0e", "#8c564b", "#17becf"]
        lx = 10
        for k, name in enumerate(names):
            colr = palette[k % len(palette)]
            pts = [(X(tt), Y(v)) for tt, v in zip(times, cols[name]) if v is not None]
            if len(pts) > 1:
                step = max(1, len(pts) // 2000)  # прореживание: длинные trace рисуются мгновенно
                flat = [c for p in pts[::step] for c in p]
                if (len(pts) - 1) % step:
                    flat += [pts[-1][0], pts[-1][1]]
                cv.create_line(*flat, fill=colr, width=2)
            cv.create_rectangle(lx, 8, lx + 12, 20, fill=colr, outline=colr)
            cv.create_text(lx + 16, 14, text=name, anchor=tk.W, font=("", 9, "bold"))
            lx += 28 + 8 * len(name)

    def do_open_trace():
        if runner["run_dir"] and os.path.isfile(os.path.join(runner["run_dir"], "data.csv")):
            subprocess.Popen(["xdg-open", os.path.join(runner["run_dir"], "data.csv")])

    def append_log(s):
        logtxt.config(state=tk.NORMAL)
        logtxt.insert(tk.END, s)
        logtxt.see(tk.END)
        logtxt.config(state=tk.DISABLED)

    def poll_log():
        try:
            while True:
                append_log(runner["logq"].get_nowait())
        except queue.Empty:
            pass
        ok = ports_ready(int(out_port_var.get()), int(in_port_var.get()))
        forte_lbl.config(text=f"Flogic (IEC 61499, forte): {'● готов' if ok else '○ порты не слушаются'}",
                         foreground="#0a0" if ok else "#a00")
        app.after(300, poll_log)

    refresh(select=models[0].name if models else None)
    app.after(300, poll_log)
    app.mainloop()


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1].startswith("--"):
        sys.exit(selftest(sys.argv[1:]))
    run_gui()
