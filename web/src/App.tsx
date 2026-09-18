// Автор: Evgenii I, 2026
// Экран связки: модели, переменные SD/RD, параметры запуска, лог, график trace.
// Компоненты и тема ick — svs-react-ui.
import React, { useCallback, useEffect, useRef, useState } from 'react'
import {
  ThemeProvider, ICK_THEME, Button, Table, InputNumber,
  Dropdown, InlineMessage, Drawer, LineChart, Switch,
} from 'svs-react-ui'

const panel = (extra?: React.CSSProperties): React.CSSProperties => ({
  border: '1px solid var(--theme-background-secondary, rgba(128,128,128,.35))',
  background: 'var(--theme-background-secondary, transparent)',
  borderRadius: 8, padding: 12, minWidth: 0, ...extra,
})
import { api, subscribeLogs, ModelInfo, Status, Trace } from './api'

const TYPE_NAME: Record<string, string> = { '0': 'Real', '1': 'Int', '2': 'Bool', '3': 'Str' }

export default function App() {
  const [dark, setDark] = useState(() => localStorage.getItem('theme') === 'dark')
  const [models, setModels] = useState<ModelInfo[]>([])
  const [sel, setSel] = useState<ModelInfo | null>(null)
  const [status, setStatus] = useState<Status | null>(null)
  const [params, setParams] = useState({ out_port: 1499, in_port: 1500, duration: 0, lookahead: 1, loglevel: 'info' })
  const [logs, setLogs] = useState<string[]>([])
  const [drawer, setDrawer] = useState(false)
  const [trace, setTrace] = useState<Trace | null>(null)
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
      const r = await api.run({ model: sel.name, ...params })
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
          <Button styleType="secondary" onClick={() => {
            const p = window.prompt('Рабочий каталог (модели, trace):', status?.root || '')
            if (p) api.setRoot(p).then(() => { refreshModels().catch(() => {}); api.status().then(setStatus).catch(() => {}) })
                      .catch(e => setNotice({ text: String(e.message || e), bad: true }))
          }}>Сменить каталог…</Button>
          <Button styleType="secondary" onClick={() => refreshModels().catch(() => {})}>Обновить</Button>
        </div>

        {notice && (
          <InlineMessage status={notice.bad ? 'danger' : 'default'} text={notice.text}
                         closable onClose={() => setNotice(null)} />
        )}

        {/* основная зона */}
        <div style={{ display: 'flex', gap: 12, flex: 1, minHeight: 0 }}>
          {/* модели */}
          <div style={panel({ width: 330, overflow: 'auto' })}><b>Модели</b>
            <Table
              data={models.map(m => ({ name: m.name, io: `${m.inputs.length}вх/${m.outputs.length}вых` }))}
              cols={[
                { title: 'Имя', name: 'name' },
                { title: 'вх/вых', name: 'io', width: 100 },
              ]}
            />
            <div style={{ display: 'flex', flexDirection: 'column', gap: 4, marginTop: 8 }}>
              {models.map(m => (
                <Button key={m.name} size="s"
                        styleType={sel?.name === m.name ? 'primary' : 'secondary'}
                        onClick={() => setSel(m)}>
                  {m.name} ({m.inputs.length}вх/{m.outputs.length}вых)
                </Button>
              ))}
            </div>
          </div>

          {/* модель и параметры */}
          <div style={{ flex: 1, display: 'flex', flexDirection: 'column', gap: 8, minWidth: 0 }}>
            <div style={panel()}><b>{sel ? `Модель: ${sel.name}` : 'Модель не выбрана'}</b>
              {sel && (
                <div style={{ display: 'flex', gap: 24 }}>
                  <div style={{ flex: 1, maxHeight: 260, overflowY: 'auto' }}>
                    <div style={{ fontWeight: 600, marginBottom: 4 }}>Входы (Flogic → модель), {sel.inputs.length}</div>
                    {sel.inputs.map((v, i) => (
                      <div key={i} style={{ display: 'flex', gap: 8, padding: '2px 0', fontSize: 13, borderBottom: '1px solid var(--theme-background-secondary, #eee)' }}>
                        <span style={{ opacity: 0.6, width: 48 }}>SD_{i + 1}</span>
                        <span style={{ flex: 1 }}>{v.name}</span>
                        <span style={{ opacity: 0.6 }}>{TYPE_NAME[v.type] || v.type}</span>
                      </div>
                    ))}
                  </div>
                  <div style={{ flex: 1, maxHeight: 260, overflowY: 'auto' }}>
                    <div style={{ fontWeight: 600, marginBottom: 4 }}>Выходы (модель → Flogic), {sel.outputs.length}</div>
                    {sel.outputs.map((v, i) => (
                      <div key={i} style={{ display: 'flex', gap: 8, padding: '2px 0', fontSize: 13, borderBottom: '1px solid var(--theme-background-secondary, #eee)' }}>
                        <span style={{ opacity: 0.6, width: 48 }}>RD_{i + 1}</span>
                        <span style={{ flex: 1 }}>{v.name}</span>
                        <span style={{ opacity: 0.6 }}>{TYPE_NAME[v.type] || v.type}</span>
                      </div>
                    ))}
                  </div>
                </div>
              )}
            </div>

            <div style={panel()}><b>Параметры запуска</b>
              <div style={{ display: 'flex', gap: 16, flexWrap: 'wrap', alignItems: 'flex-end' }}>
                <label>Порт приёма<br />
                  <InputNumber value={params.out_port} min={1} max={65535}
                               onChange={v => setParams(p => ({ ...p, out_port: Number(v) }))} /></label>
                <label>Порт отправки<br />
                  <InputNumber value={params.in_port} min={1} max={65535}
                               onChange={v => setParams(p => ({ ...p, in_port: Number(v) }))} /></label>
                <label>Длительность, с (0 = до «Стоп»)<br />
                  <InputNumber value={params.duration} min={0}
                               onChange={v => setParams(p => ({ ...p, duration: Number(v) }))} /></label>
                <label>lookAheadTime, с<br />
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

      <Drawer open={drawer} onClose={() => setDrawer(false)} title="График trace" width={980}
              placement="right">
        {trace && trace.decimated && (
          <LineChart
            width={920} height={440}
            data={trace.decimated.times.map((t, i) => {
              const row: Record<string, number | undefined> = { t: Number(t.toFixed(3)) }
              for (const n of trace.names) {
                const v = trace.decimated.series[n][i]
                row[n] = v === null ? undefined : v
              }
              return row
            })}
            categoryField="t"
            series={trace.names.map(n => ({ fieldName: n, label: n }))}
            showLegend showGridX showGridY />
        )}
      </Drawer>
    </ThemeProvider>
  )
}
