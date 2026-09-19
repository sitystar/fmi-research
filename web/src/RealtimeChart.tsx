// Автор: Evgenii I, 2026
// Canvas-график трейса в реальном времени: стриминг, скролл, масштаб.
import { useCallback, useEffect, useRef, useState } from 'react'
import { Button } from 'svs-react-ui'

export interface TracePoint { t: number; [key: string]: number | undefined }
export type TraceBuffer = Map<string, TracePoint[]> // name → points

const COLORS = ['#1f77b4', '#d62728', '#2ca02c', '#9467bd', '#ff7f0e', '#8c564b', '#17becf', '#e377c2']
const MAX_POINTS = 10000

interface Props {
  dark: boolean
  hidden: Set<string>
  onHiddenChange: (s: Set<string>) => void
  names: string[]
  buffer: TraceBuffer
  running: boolean
}

export default function RealtimeChart({ dark, hidden, onHiddenChange, names, buffer, running }: Props) {
  const canvasRef = useRef<HTMLCanvasElement>(null)
  const [autoScroll, setAutoScroll] = useState(true)
  const [view, setView] = useState<{ start: number; span: number } | null>(null)
  const dragRef = useRef<{ x: number; start: number } | null>(null)

  // данные для отображения
  const allPoints = names.length > 0 ? (buffer.get(names[0]) || []) : []
  const tMin = allPoints.length > 0 ? allPoints[0].t : 0
  const tMax = allPoints.length > 0 ? allPoints[allPoints.length - 1].t : 1

  // видимое окно
  const vStart = view ? view.start : Math.max(tMin, tMax - (view?.span || 20))
  const vSpan = view?.span || Math.max(5, tMax - tMin)
  const vEnd = vStart + vSpan

  // Y-границы по видимым данным (вычисляем до draw)
  let _ymin = Infinity, _ymax = -Infinity
  for (const name of names) {
    if (hidden.has(name)) continue
    const pts = buffer.get(name) || []
    for (const p of pts) {
      if (p.t >= vStart && p.t <= vEnd && p[name] !== undefined) {
        const v = p[name] as number
        if (v < _ymin) _ymin = v
        if (v > _ymax) _ymax = v
      }
    }
  }
  if (_ymin === Infinity) { _ymin = 0; _ymax = 1 }
  if (_ymin === _ymax) _ymax = _ymin + 1
  const yPad = (_ymax - _ymin) * 0.05
  _ymin -= yPad; _ymax += yPad

  const draw = useCallback(() => {
    const canvas = canvasRef.current
    if (!canvas) return
    const ctx = canvas.getContext('2d')
    if (!ctx) return
    const ymin = _ymin, ymax = _ymax

    const W = canvas.width, H = canvas.height
    const ML = 55, MR = 10, MT = 10, MB = 28
    const PW = W - ML - MR, PH = H - MT - MB

    // фон
    ctx.fillStyle = dark ? '#0d1117' : '#fff'
    ctx.fillRect(0, 0, W, H)

    const X = (t: number) => ML + ((t - vStart) / (vSpan || 1)) * PW
    const Y = (v: number) => MT + PH - ((v - ymin) / (ymax - ymin || 1)) * PH

    // сетка
    const grid = dark ? '#21262d' : '#e8eaed'
    const text = dark ? '#8b949e' : '#57606a'
    ctx.strokeStyle = grid
    ctx.fillStyle = text
    ctx.font = '10px sans-serif'
    ctx.lineWidth = 0.5
    for (let i = 0; i <= 5; i++) {
      const y = MT + (i / 5) * PH
      ctx.beginPath(); ctx.moveTo(ML, y); ctx.lineTo(W - MR, y); ctx.stroke()
      const val = ymax - (i / 5) * (ymax - ymin)
      ctx.textAlign = 'right'
      ctx.fillText(val.toFixed(2), ML - 5, y + 3)
    }
    for (let i = 0; i <= 5; i++) {
      const x = ML + (i / 5) * PW
      ctx.beginPath(); ctx.moveTo(x, MT); ctx.lineTo(x, MT + PH); ctx.stroke()
      const val = vStart + (i / 5) * vSpan
      ctx.textAlign = 'center'
      ctx.fillText(val.toFixed(1), x, H - MB + 14)
    }

    // оси
    ctx.strokeStyle = dark ? '#30363d' : '#d0d7de'
    ctx.lineWidth = 1
    ctx.beginPath(); ctx.moveTo(ML, MT); ctx.lineTo(ML, MT + PH); ctx.stroke()
    ctx.beginPath(); ctx.moveTo(ML, MT + PH); ctx.lineTo(W - MR, MT + PH); ctx.stroke()

    // линии данных
    for (let ni = 0; ni < names.length; ni++) {
      const name = names[ni]
      if (hidden.has(name)) continue
      const pts = buffer.get(name) || []
      ctx.strokeStyle = COLORS[ni % COLORS.length]
      ctx.lineWidth = 1.5
      ctx.beginPath()
      let started = false
      let lastX = -1
      for (const p of pts) {
        if (p.t < vStart || p.t > vEnd) continue
        if (p[name] === undefined) continue
        const x = X(p.t), y = Y(p[name] as number)
        // прореживание: пропускаем если x не изменился
        if (Math.abs(x - lastX) < 0.5) continue
        lastX = x
        if (!started) { ctx.moveTo(x, y); started = true }
        else ctx.lineTo(x, y)
      }
      ctx.stroke()
    }
  }, [dark, hidden, names, buffer, vStart, vSpan, vEnd, _ymin, _ymax])

  // рендер
  useEffect(() => {
    const loop = () => { draw(); requestAnimationFrame(loop) }
    const raf = requestAnimationFrame(loop)
    return () => cancelAnimationFrame(raf)
  }, [draw])

  // обработчики мыши
  const onWheel = (e: React.WheelEvent) => {
    e.preventDefault()
    const factor = e.deltaY > 0 ? 1.2 : 0.8
    const newSpan = Math.max(0.5, Math.min(tMax - tMin || 1, vSpan * factor))
    // zoom вокруг позиции курсора
    const canvas = canvasRef.current
    if (canvas) {
      const rect = canvas.getBoundingClientRect()
      const frac = (e.clientX - rect.left - 55) / (rect.width - 65)
      const anchor = vStart + frac * vSpan
      const newStart = Math.max(tMin, Math.min(tMax - newSpan, anchor - newSpan * frac))
      setView({ start: newStart, span: newSpan })
      setAutoScroll(false)
    }
  }

  const onMouseDown = (e: React.MouseEvent) => {
    dragRef.current = { x: e.clientX, start: vStart }
  }
  const onMouseMove = (e: React.MouseEvent) => {
    if (!dragRef.current) return
    const canvas = canvasRef.current
    if (!canvas) return
    const dx = e.clientX - dragRef.current.x
    const dt = -(dx / (canvas.width - 65)) * vSpan
    const newStart = Math.max(tMin, Math.min(tMax - vSpan, dragRef.current.start + dt))
    setView(prev => ({ start: newStart, span: prev?.span || vSpan }))
    setAutoScroll(false)
  }
  const onMouseUp = () => { dragRef.current = null }

  // при автоскролле — следуем за последними данными
  useEffect(() => {
    if (autoScroll) {
      setView({ start: Math.max(tMin, tMax - vSpan), span: vSpan })
    }
  }, [autoScroll, tMax]) // eslint-disable-line

  return (
    <div style={{ display: 'flex', flexDirection: 'column', height: '100%' }}>
      {/* панель управления */}
      <div style={{ display: 'flex', alignItems: 'center', gap: 8, marginBottom: 4 }}>
        <Button size="xs" styleType={autoScroll ? 'primary' : 'secondary'}
                onClick={() => { setAutoScroll(!autoScroll); if (!autoScroll) setView(null) }}>
          {autoScroll ? '⏸ Пауза' : '▶ Продолжить'}
        </Button>
        <Button size="xs" styleType="secondary"
                onClick={() => { setAutoScroll(true); setView(null) }}>
          ⟲ Сброс
        </Button>
        <span style={{ fontSize: 12, opacity: 0.7 }}>
          {autoScroll ? 'автоскролл' : `${vStart.toFixed(1)}с — ${vEnd.toFixed(1)}с`} из ${tMax.toFixed(1)}с
        </span>
        <div style={{ flex: 1 }} />
        {/* легенда */}
        {names.map((n, i) => (
          <button key={n} onClick={() => {
            const s = new Set(hidden)
            if (s.has(n)) s.delete(n); else s.add(n)
            onHiddenChange(s)
          }} style={{
            display: 'flex', alignItems: 'center', gap: 3,
            background: 'transparent', border: 'none', cursor: 'pointer',
            opacity: hidden.has(n) ? 0.3 : 1, fontSize: 12, color: 'inherit',
          }}>
            <span style={{ width: 14, height: 3, background: COLORS[i % COLORS.length], borderRadius: 2 }} />
            {n}
          </button>
        ))}
      </div>
      {/* canvas */}
      <canvas
        ref={el => {
          if (el) {
            const parent = el.parentElement
            if (parent) {
              el.width = parent.clientWidth
              el.height = parent.clientHeight - 32
            }
          }
          canvasRef.current = el
        }}
        onWheel={onWheel}
        onMouseDown={onMouseDown}
        onMouseMove={onMouseMove}
        onMouseUp={onMouseUp}
        onMouseLeave={onMouseUp}
        style={{ flex: 1, cursor: dragRef.current ? 'grabbing' : 'crosshair' }}
      />
    </div>
  )
}
