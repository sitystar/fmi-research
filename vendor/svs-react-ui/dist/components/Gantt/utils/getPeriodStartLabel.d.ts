import { IntervalOption } from '../Gantt.const';
/**
 * @description Функция принимает параметры visibleIntervalTime, соответсвующий времени первого отображаемого
 * интервала в таймлайне и description, соответствующий длительности периода таймлайна.
 * И возвращает строку с описанием даты начала текущего периода.
 * @param visibleIntervalTime время, соответсвующее первому отображаемому
 * интервалу в таймлайне в мс
 * @param description длительность периода таймлайна.
 * @returns строка с описанием даты начала текущего периода.
 * @example getPreviousPeriod(1721730600000, "hours")
 * (1721730600000 соответствует времени "Tue Jul 23 2024 13:30:00 GMT+0300 (Москва, стандартное время)")
 * вернёт
 * "Июль 23, 2024"
 */
export declare function getPeriodStartLabel(visibleIntervalTime: number, description: IntervalOption): string;
