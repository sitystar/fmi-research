// Автор: Evgenii I, 2026
// Типы и обмен с локальным сервером (scripts/fmi_server.py)

export interface Var { name: string; type: string }
export interface ModelInfo {
  name: string
  dir: string
  inputs: Var[]
  outputs: Var[]
}
export interface Status {
  root: string
  fmitb: string
  forte_ready: boolean
  running: boolean
  model: string | null
  run_dir: string | null
}
export interface Trace {
  names: string[]
  times: number[]
  decimated: { step: number; times: number[]; series: Record<string, (number | null)[]> }
}

const j = async (url: string, init?: RequestInit) => {
  const r = await fetch(url, init)
  const body = await r.json().catch(() => ({}))
  if (!r.ok) throw new Error(body.error || `${r.status} ${r.statusText}`)
  return body
}

export const api = {
  models: () => j('/api/models') as Promise<ModelInfo[]>,
  status: () => j('/api/status') as Promise<Status>,
  run: (p: Record<string, unknown>) =>
    j('/api/run', { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(p) }),
  stop: () => j('/api/stop', { method: 'POST' }),
  trace: () => j('/api/trace') as Promise<Trace>,
  setRoot: (path: string) =>
    j('/api/root', { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify({ path }) }),
  importFmu: async (file: File) => {
    const fd = new FormData()
    fd.append('file', file)
    return j('/api/import', { method: 'POST', body: fd })
  },
}

/** Подписка на живой лог; возвращает функцию отписки. */
export function subscribeLogs(onLine: (line: string) => void): () => void {
  const proto = location.protocol === 'https:' ? 'wss' : 'ws'
  let ws: WebSocket | null = null
  let closed = false
  let retry: number | undefined
  const open = () => {
    ws = new WebSocket(`${proto}://${location.host}/api/logs`)
    ws.onmessage = (e) => onLine(e.data)
    ws.onclose = () => { if (!closed) retry = window.setTimeout(open, 1000) }
  }
  open()
  return () => { closed = true; if (retry) clearTimeout(retry); ws?.close() }
}
