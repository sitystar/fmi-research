/**
 * @description Функция принимает длительность интервала в мс и (опционально) значение времени в мс
 * и возвращает время в мс, округлённое до ближайшего значения, кратного переданному интервалу.
 * Если параметр времени отсутствует, берётся текущее время.
 * @param intervalDurationMs длительность интервала в мс
 * @param time значение времени в мс
 * @returns время в мс, округлённое до ближайшего значения, кратного переданному интервалу.
 * @example  getRoundedCurrentTime(900000)
 * вернёт
 * 1721738700000
 */
export declare function getRoundedCurrentTime(intervalDurationMs: number, time?: number): number;
