import { IntervalItem } from '../Gantt.const';
/**
 * @description Функция принимает объект типа IntervalItem
 * и возвращет длительность интервала в мс, соответствующую строке, содержащейся в ключе value.
 * @param interval объект типа IntervalItem
 * @returns длительность интервала в мс
 * @example
 *  calcIntervalDurationMs({
      "value": "00:00:15",
      "label": "часы",
      "description": "hours",
      "countingFromCenter": true,
      "defaultNumberOfIntervals": 24
    })
 * вернёт
 * 900000
 */
export declare function calcIntervalDurationMs(interval: IntervalItem): number;
