// Автор: Evgenii I, 2026
// Экран связки: модели, переменные SD/RD, параметры запуска, лог, график trace.
// Компоненты и тема ick — svs-react-ui.
import React, { useCallback, useEffect, useRef, useState } from 'react'
import {
  ThemeProvider, ICK_THEME, Button, Table, InputNumber, Input,
  Dropdown, InlineMessage, Drawer, Switch,
} from 'svs-react-ui'

const panel = (extra?: React.CSSProperties): React.CSSProperties => ({
  border: '1px solid var(--theme-background-secondary, rgba(128,128,128,.35))',
  background: 'var(--theme-background-secondary, transparent)',
  borderRadius: 8, padding: 12, minWidth: 0, ...extra,
})
import { api, subscribeLogs, ModelInfo, Status, Trace } from './api'

function BrowseDir({ onPick }: { onPick: (path: string) => void }) {
  const [path, setPath] = useState('/home')
  const [data, setData] = useState<{ path: string; dirs: string[]; parent: string | null } | null>(null)
  useEffect(() => {
    api.fs(path).then(setData).catch(e => console.error(e))
  }, [path])
  if (!data) return <div>…</div>
  return (
    <div>
      <div style={{ fontWeight: 600, marginBottom: 8, wordBreak: 'break-all' }}>{data.path}</div>
      {data.parent && (
        <Button size="s" styleType="secondary" onClick={() => setPath(data.parent!)}
                style={{ marginBottom: 8 }}>← вверх</Button>
      )}
      <Button size="s" styleType="primary" onClick={() => onPick(data.path)}
              style={{ marginBottom: 8, marginLeft: 8 }}>Выбрать этот каталог</Button>
      <div style={{ display: 'flex', flexDirection: 'column', gap: 2 }}>
        {data.dirs.map(d => (
          <Button key={d} size="s" styleType="link"
                  onClick={() => setPath(data.path + '/' + d)}
                  style={{ textAlign: 'left', justifyContent: 'flex-start' }}>
            📁 {d}
          </Button>
        ))}
        {data.dirs.length === 0 && <div style={{ opacity: 0.5, padding: 8 }}>поддиректорий нет</div>}
      </div>
    </div>
  )
}


function SvgChart({ trace, hidden, dark }: {
  trace: Trace | null
  hidden: Set<string>
  dark: boolean
}) {
  if (!trace || !trace.decimated || trace.decimated.times.length < 2) {
    return <div style={{ textAlign: 'center', padding: 40, opacity: 0.5, color: dark ? '#8b949e' : '#666' }}>
      нет данных для отображения
    </div>
  }

  const d = trace.decimated
  const times = d.times
  const names = trace.names.filter(n => !hidden.has(n))
  if (names.length === 0) return <div style={{ textAlign: 'center', padding: 40, opacity: 0.5 }}>все графики скрыты</div>

  // вычисляем границы
  let ymin = Infinity, ymax = -Infinity
  for (const n of names) {
    for (const v of d.series[n] || []) {
      if (v !== null && v !== undefined && isFinite(v)) {
        if (v < ymin) ymin = v
        if (v > ymax) ymax = v
      }
    }
  }
  if (ymin === Infinity) { ymin = 0; ymax = 1 }
  if (ymin === ymax) ymax = ymin + 1
  const tmin = times[0], tmax = times[times.length - 1]
  const tSpan = tmax - tmin || 1
  const ySpan = ymax - ymin

  // размеры
  const W = 1000, H = 500
  const ML = 60, MR = 15, MT = 15, MB = 35
  const PW = W - ML - MR, PH = H - MT - MB

  const X = (t: number) => ML + ((t - tmin) / tSpan) * PW
  const Y = (v: number) => MT + PH - ((v - ymin) / ySpan) * PH

  const gridColor = dark ? '#21262d' : '#e1e4e8'
  const textColor = dark ? '#8b949e' : '#586069'
  const axisColor = dark ? '#30363d' : '#d1d5da'

  // полилинии для каждой серии
  const lines = names.map((n, idx) => {
    const color = SERIES_COLORS[trace.names.indexOf(n) % SERIES_COLORS.length]
    const points: string[] = []
    for (let i = 0; i < times.length; i++) {
      const v = d.series[n]?.[i]
      if (v !== null && v !== undefined && isFinite(v)) {
        points.push(`${X(times[i]).toFixed(1)},${Y(v).toFixed(1)}`)
      }
    }
    return { color, name: n, points: points.join(' ') }
  }).filter(l => l.points.length > 0)

  return (
    <svg viewBox={`0 0 ${W} ${H}`} style={{ width: '100%', height: '100%' }}>
      {/* сетка */}
      {Array.from({ length: 6 }, (_, i) => {
        const y = MT + (i / 5) * PH
        return <g key={`gy${i}`}>
          <line x1={ML} y1={y} x2={W - MR} y2={y} stroke={gridColor} strokeWidth={0.5} />
          <text x={ML - 8} y={y + 3} textAnchor="end" fontSize={10} fill={textColor}>
            {(ymax - (i / 5) * ySpan).toFixed(2)}
          </text>
        </g>
      })}
      {Array.from({ length: 6 }, (_, i) => {
        const x = ML + (i / 5) * PW
        return <g key={`gx${i}`}>
          <line x1={x} y1={MT} x2={x} y2={MT + PH} stroke={gridColor} strokeWidth={0.5} />
          <text x={x} y={H - MB + 15} textAnchor="middle" fontSize={10} fill={textColor}>
            {(tmin + (i / 5) * tSpan).toFixed(1)}
          </text>
        </g>
      })}
      {/* оси */}
      <line x1={ML} y1={MT} x2={ML} y2={MT + PH} stroke={axisColor} strokeWidth={1} />
      <line x1={ML} y1={MT + PH} x2={W - MR} y2={MT + PH} stroke={axisColor} strokeWidth={1} />
      {/* линии данных */}
      {lines.map(l => (
        <polyline key={l.name} points={l.points} fill="none" stroke={l.color} strokeWidth={1.5} />
      ))}
    </svg>
  )
}

const SERIES_COLORS = ['#1f77b4', '#d62728', '#2ca02c', '#9467bd', '#ff7f0e', '#8c564b', '#17becf', '#e377c2']

const TYPE_NAME: Record<string, string> = { '0': 'Real', '1': 'Int', '2': 'Bool', '3': 'Str' }

export default function App() {
  const [dark, setDark] = useState(() => localStorage.getItem('theme') === 'dark')
  const [models, setModels] = useState<ModelInfo[]>([])
  const [sel, setSel] = useState<ModelInfo | null>(null)
  const [status, setStatus] = useState<Status | null>(null)
  const [params, setParams] = useState({ out_port: 1499, in_port: 1500, duration: 0, lookahead: 1, loglevel: 'info', host: '127.0.0.1' })
  const [logs, setLogs] = useState<string[]>([])
  const [drawer, setDrawer] = useState(false)
  const [trace, setTrace] = useState<Trace | null>(null)
  const [browse, setBrowse] = useState(false)
  const [showParams, setShowParams] = useState(false)
  const [hiddenSeries, setHiddenSeries] = useState<Set<string>>(new Set())
  const [paramEdits, setParamEdits] = useState<Record<string, string>>({})
  const [notice, setNotice] = useState<{ text: string; bad?: boolean } | null>(null)
  const logRef = useRef<HTMLPreElement>(null)
  const fileRef = useRef<HTMLInputElement>(null)

  const refreshModels = useCallback(async (keep?: string) => {
    const ms = await api.models()
    setModels(ms)
    setSel(m => (keep ? m && ms.find(x => x.name === keep) || null : m && ms.find(x => x.name === m.name) || ms[0] || null))
  }, [])

  useEffect(() => { refreshModels().catch(e => setNotice({ text: String(e), bad: true })) }, [refreshModels])

  useEffect(() => {
    const t = setInterval(() => api.status().then(setStatus).catch(() => {}), 2000)
    api.status().then(setStatus).catch(() => {})
    return () => clearInterval(t)
  }, [])

  useEffect(() => subscribeLogs(l => setLogs(prev => [...prev.slice(-1500), l])), [])

  useEffect(() => {
    if (logRef.current) logRef.current.scrollTop = logRef.current.scrollHeight
  }, [logs])

  const doRun = async () => {
    if (!sel) return
    setNotice(null)
    try {
      const r = await api.run({ model: sel.name, ...params, param_overrides: Object.keys(paramEdits).length > 0 ? paramEdits : undefined })
      setLogs([])
      setNotice({ text: `Прогон запущен: ${r.run_dir}` })
    } catch (e) {
      setNotice({ text: String(e instanceof Error ? e.message : e), bad: true })
    }
  }

  const doStop = async () => {
    await api.stop().catch(() => {})
    setNotice({ text: 'Остановлено' })
  }

  const doImport = async (f: File | undefined) => {
    if (!f) return
    try {
      const r = await api.importFmu(f)
      await refreshModels(r.name)
      setNotice({ text: `Импортировано: ${r.name}` })
    } catch (e) {
      setNotice({ text: `Импорт не удался: ${e instanceof Error ? e.message : e}`, bad: true })
    }
  }

  const showTrace = async () => {
    try {
      const t = await api.trace()
      setTrace(t)
      setDrawer(true)
    } catch (e) {
      setNotice({ text: `trace недоступен: ${e instanceof Error ? e.message : e}`, bad: true })
    }
  }

  const running = status?.running
  const run_state_model = status?.model

  return (
    <ThemeProvider theme={ICK_THEME} dark={dark}>
      <div style={{
        display: 'flex', flexDirection: 'column', height: '100vh',
        gap: 8, padding: 12, boxSizing: 'border-box',
        background: dark ? 'var(--theme-background-primary, #141925)' : 'var(--theme-background-tertiary, #dbe1e8)',
        color: dark ? '#e8ecf1' : '#1a1a2e',
        transition: 'background 0.2s, color 0.2s',
      }}>
        {/* шапка */}
        <div style={{ display: 'flex', alignItems: 'center', gap: 12 }}>
          <b style={{ fontSize: 18 }}>fmi-coupling — Flogic (IEC 61499, forte) ↔ FMU</b>
          <span style={{ opacity: 0.8, fontSize: 13 }}>каталог: {status?.root}</span>
          <div style={{ flex: 1 }} />
          <label style={{ display: 'flex', alignItems: 'center', gap: 6, fontSize: 13 }}>
            <span>{dark ? 'ick' : 'default'}</span>
            <Switch checked={dark} onChange={e => { setDark(e.target.checked); localStorage.setItem("theme", e.target.checked ? "dark" : "light") }} />
          </label>
          <Button styleType="secondary" onClick={() => fileRef.current?.click()}>Импорт FMU…</Button>
          <input ref={fileRef} type="file" accept=".fmu" style={{ display: 'none' }}
                 onChange={e => { doImport(e.target.files?.[0]); e.target.value = '' }} />
          <Button styleType="secondary" onClick={() => setBrowse(true)}>Сменить каталог…</Button>
          <Button styleType="secondary" onClick={() => refreshModels().catch(() => {})}>Обновить</Button>
        </div>

        {notice && (
          <InlineMessage status={notice.bad ? 'danger' : 'default'} text={notice.text}
                         closable onClose={() => setNotice(null)} />
        )}

        {/* основная зона */}
        <div style={{ display: 'flex', gap: 12, flex: 1, minHeight: 0 }}>
          {/* модели: две раздельные секции */}
          <div style={{ width: 330, display: 'flex', flexDirection: 'column', gap: 8, minHeight: 0 }}>
            {/* верхняя: таблица импортированных моделей (70%) */}
            <div style={{ flex: 7, position: 'relative', overflow: 'hidden', minHeight: 0 }}>
              <div style={{
                position: 'absolute', inset: 0,
                transform: showParams ? 'translateX(100%)' : 'translateX(0)',
                transition: 'transform 0.3s ease',
                border: '1px solid var(--theme-background-secondary, rgba(128,128,128,.35))',
                background: 'var(--theme-background-secondary, transparent)',
                borderRadius: 8, padding: 12, display: 'flex', flexDirection: 'column',
              }}>
                <b style={{ marginBottom: 6 }}>Импортированные модели</b>
                <div style={{ flex: 1, overflowY: 'auto', minHeight: 0 }}>
                  <Table
                    data={models.map(m => ({ name: m.name, io: `${m.inputs.length}вх/${m.outputs.length}вых` }))}
                    cols={[
                      { title: 'Имя', name: 'name' },
                      { title: 'вх/вых', name: 'io', width: 100 },
                    ]}
                  />
                </div>
              </div>
              <div style={{
                position: 'absolute', inset: 0,
                transform: showParams ? 'translateX(0)' : 'translateX(-100%)',
                transition: 'transform 0.3s ease',
                border: '1px solid var(--theme-background-secondary, rgba(128,128,128,.35))',
                background: 'var(--theme-background-secondary, transparent)',
                borderRadius: 8, padding: 12, display: 'flex', flexDirection: 'column',
              }}>
                <b style={{ marginBottom: 6 }}>Параметры: {sel?.name || '—'}</b>
                <div style={{ flex: 1, overflowY: 'auto', minHeight: 0, display: 'flex', flexDirection: 'column', gap: 6 }}>
                  {(sel?.parameters || []).map(p => (
                    <label key={p.name} style={{ display: 'flex', flexDirection: 'column', gap: 2, fontSize: 13 }}>
                      <span title={p.desc} style={{ cursor: 'help' }}>
                        <b>{p.name}</b>{p.desc ? ` — ${p.desc}` : ''}
                      </span>
                      <Input
                        value={paramEdits[p.name] ?? p.value}
                        onChange={e => {
                          const val = typeof e === 'string' ? e : e?.target?.value ?? String(e)
                          setParamEdits(prev => ({ ...prev, [p.name]: val }))
                        }}
                      />
                    </label>
                  ))}
                  {(!sel || !sel.parameters || sel.parameters.length === 0) && (
                    <div style={{ opacity: 0.5, padding: 8 }}>параметров нет</div>
                  )}
                </div>
                <div style={{ display: 'flex', gap: 6, marginTop: 8 }}>
                  <Button size="s" styleType="primary" onClick={() => setShowParams(false)}>Применить</Button>
                  <Button size="s" styleType="secondary" onClick={() => setParamEdits({})}>Сбросить</Button>
                </div>
              </div>
            </div>
            {/* нижняя: выбор модели для работы (30%, зафиксирована) */}
            <div style={panel({ flex: 3, display: 'flex', flexDirection: 'column', minHeight: 0 })}>
              <b style={{ marginBottom: 6 }}>Выбор модели</b>
              {sel && sel.parameters && sel.parameters.length > 0 && (
                <Button size="xs" styleType="secondary"
                        onClick={() => setShowParams(!showParams)}
                        style={{ marginBottom: 4 }}>
                  {showParams ? '← К списку' : '⚙ Изменить параметры'}
                </Button>
              )}
              <div style={{ flex: 1, overflowY: 'auto', minHeight: 0, display: 'flex', flexDirection: 'column', gap: 3 }}>
                {models.map(m => (
                  <Button key={m.name} size="xs"
                          styleType={sel?.name === m.name ? 'primary' : 'secondary'}
                          onClick={() => setSel(m)}>
                    {m.name} ({m.inputs.length}/{m.outputs.length})
                  </Button>
                ))}
              </div>
            </div>
          </div>

          {/* модель и параметры */}
          <div style={{ flex: 1, display: 'flex', flexDirection: 'column', gap: 8, minWidth: 0 }}>
            <div style={panel()}><b>{sel ? `Модель: ${sel.name}` : 'Модель не выбрана'}</b>
              {sel && (
                <div style={{ display: 'flex', gap: 24 }}>
                  <div style={{ flex: 1, maxHeight: 260, overflowY: 'auto', paddingRight: 10 }}>
                    <div style={{ fontWeight: 600, marginBottom: 4 }}>Входы (Flogic → модель), {sel.inputs.length}</div>
                    {sel.inputs.map((v, i) => (
                      <div key={i} style={{ display: 'flex', gap: 8, padding: '2px 0', fontSize: 13, borderBottom: '1px solid var(--theme-background-secondary, #eee)' }}>
                        <span style={{ opacity: 0.6, width: 42 }}>SD_{i + 1}</span>
                        <span style={{ width: 110, overflow: 'hidden', textOverflow: 'ellipsis' }}>{v.name}</span>
                        <span style={{ opacity: 0.6, width: 34 }}>{TYPE_NAME[v.type] || v.type}</span>
                        <span style={{ flex: 1, opacity: 0.7, overflow: 'hidden', textOverflow: 'ellipsis', whiteSpace: 'nowrap' }} title={v.desc}>{v.desc || '—'}</span>
                      </div>
                    ))}
                  </div>
                  <div style={{ flex: 1, maxHeight: 260, overflowY: 'auto', paddingRight: 10 }}>
                    <div style={{ fontWeight: 600, marginBottom: 4 }}>Выходы (модель → Flogic), {sel.outputs.length}</div>
                    {sel.outputs.map((v, i) => (
                      <div key={i} style={{ display: 'flex', gap: 8, padding: '2px 0', fontSize: 13, borderBottom: '1px solid var(--theme-background-secondary, #eee)' }}>
                        <span style={{ opacity: 0.6, width: 42 }}>RD_{i + 1}</span>
                        <span style={{ width: 110, overflow: 'hidden', textOverflow: 'ellipsis' }}>{v.name}</span>
                        <span style={{ opacity: 0.6, width: 34 }}>{TYPE_NAME[v.type] || v.type}</span>
                        <span style={{ flex: 1, opacity: 0.7, overflow: 'hidden', textOverflow: 'ellipsis', whiteSpace: 'nowrap' }} title={v.desc}>{v.desc || '—'}</span>
                      </div>
                    ))}
                  </div>
                </div>
              )}
            </div>

            <div style={panel()}><b>Параметры запуска</b>
              <div style={{ display: 'flex', gap: 16, flexWrap: 'wrap', alignItems: 'flex-end' }}>
                <label title="IP-адрес или имя ПК, где запущен Flogic (оркестратор). По умолчанию: этот же ПК."
                       style={{ cursor: 'help' }}>
                  Адрес Flogic<br />
                  <Input value={params.host}
                         onChange={e => setParams(p => ({ ...p, host: e.target.value }))}
                         placeholder="127.0.0.1" />
                </label>
                <label>Порт приёма<br />
                  <InputNumber value={params.out_port} min={1} max={65535}
                               onChange={v => setParams(p => ({ ...p, out_port: Number(v) }))} /></label>
                <label>Порт отправки<br />
                  <InputNumber value={params.in_port} min={1} max={65535}
                               onChange={v => setParams(p => ({ ...p, in_port: Number(v) }))} /></label>
                <label>Длительность, с (0 = до «Стоп»)<br />
                  <InputNumber value={params.duration} min={0}
                               onChange={v => setParams(p => ({ ...p, duration: Number(v) }))} /></label>
                <label title="Если значения модели не меняются дольше этого времени, FMITerminalBlock принудительно отправляет текущие данные контроллеру. Меньше значение = чаще обновления. По умолчанию: 1 с."
                       style={{ cursor: 'help' }}>
                  Макс. пауза данных, с ⓘ<br />
                  <InputNumber value={params.lookahead} min={0.1} step={0.5}
                               onChange={v => setParams(p => ({ ...p, lookahead: Number(v) }))} /></label>
                <label>Лог<br />
                  <Dropdown items={[{ value: 'info' }, { value: 'debug' }]} selectedValue={params.loglevel}
                            onSelect={v => setParams(p => ({ ...p, loglevel: String((Array.isArray(v) ? v[0] : v).value ?? v) }))} /></label>
                <div style={{ flex: 1 }} />
                <Button styleType="primary" disabled={!sel || !!running} onClick={doRun}>▶ Запустить</Button>
                <Button styleType="warning" disabled={!running} onClick={doStop}>■ Остановить</Button>
                <Button styleType="secondary" onClick={showTrace}>График trace</Button>
              </div>
              <div style={{ marginTop: 8 }}>
                <InlineMessage
                  status={status?.forte_ready ? 'success' : 'warning'}
                  text={status?.forte_ready
                    ? 'Flogic: порты слушаются — готов к запуску'
                    : 'Flogic: порты не слушаются (запустите оркестратор с приложением)'} />
              </div>
            </div>

            {/* лог */}
            <div style={panel({ flex: 1, minHeight: 120, overflow: 'hidden', display: 'flex', flexDirection: 'column' })}><b>Журнал{status?.model ? ` — ${status.model}` : ''}</b>
              <pre ref={logRef}
                   style={{
                     margin: 0, flex: 1, overflow: 'auto', fontSize: 12, lineHeight: 1.45,
                     fontFamily: 'ui-monospace, Menlo, Consolas, monospace', whiteSpace: 'pre-wrap',
                     background: dark ? '#0d1117' : '#f6f8fa',
                     color: dark ? '#c9d1d9' : '#24292f',
                     padding: 8, borderRadius: 6,
                   }}>
                {logs.join('') || '— пусто —'}
              </pre>
            </div>
          </div>
        </div>
      </div>

      <Drawer open={browse} onClose={() => setBrowse(false)} title="Выбор рабочего каталога" width={480} placement="right">
        <BrowseDir onPick={async p => {
          try {
            await api.setRoot(p)
            await refreshModels()
            api.status().then(setStatus).catch(() => {})
            setBrowse(false)
          } catch (e) {
            setNotice({ text: String(e instanceof Error ? e.message : e), bad: true })
          }
        }} />
      </Drawer>

      {/* трейс: div-overlay (Drawer в WebKit2 убивает GTK-окно) */}
      {drawer && (
        <div style={{
          position: 'fixed', inset: 0, zIndex: 1000,
          background: dark ? 'rgba(0,0,0,0.7)' : 'rgba(255,255,255,0.9)',
          display: 'flex', flexDirection: 'column',
          padding: 20,
        }}>
          <div style={{ display: 'flex', alignItems: 'center', gap: 12, marginBottom: 12 }}>
            <b style={{ fontSize: 16 }}>График trace — {run_state_model || 'последний прогон'}</b>
            <div style={{ flex: 1 }} />
            {/* легенда: имя + цвет, клик = вкл/выкл */}
            <div style={{ display: 'flex', gap: 10, alignItems: 'center' }}>
              {(trace?.names || []).map((n, i) => {
                const color = SERIES_COLORS[i % SERIES_COLORS.length]
                const visible = !hiddenSeries.has(n)
                return (
                  <button key={n}
                          onClick={() => setHiddenSeries(prev => {
                            const s = new Set(prev)
                            if (s.has(n)) s.delete(n); else s.add(n)
                            return s
                          })}
                          style={{
                            display: 'flex', alignItems: 'center', gap: 4,
                            background: 'transparent', border: 'none', cursor: 'pointer',
                            opacity: visible ? 1 : 0.35,
                            fontSize: 13,
                          }}>
                    <span style={{ width: 14, height: 3, background: color, borderRadius: 2 }} />
                    <span style={{ color: visible ? 'inherit' : '#999' }}>{n}</span>
                  </button>
                )
              })}
            </div>
            <Button styleType="secondary" size="s" onClick={() => setDrawer(false)}>✕ Закрыть</Button>
          </div>
          {/* график */}
          <div style={{
            flex: 1, borderRadius: 8, padding: 8, overflow: 'hidden',
            background: dark ? '#0d1117' : '#fff',
            border: '1px solid rgba(128,128,128,0.3)',
          }}>
            <SvgChart trace={trace} hidden={hiddenSeries} dark={dark} />
          </div>
        </div>
      )}
    </ThemeProvider>
  )
}
