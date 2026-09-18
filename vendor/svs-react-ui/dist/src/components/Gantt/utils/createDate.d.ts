/**
 * @description Функция создаёт две даты со смещением на определённое количество часов вперёд или назад
 * от текущего момента времени.
 * @param {number} from - на сколько часов (+/-) сместить отметку времени для даты start
 * @param {number} to - на сколько часов (+/-) сместить отметку времени для даты end
 * @returns Возвращает объект с полями:
 *
 * start: дата, смещённая на количество часов from от текущего момета времени
 *
 * end: дата, смещённая на количество часов to от текущего момета времени
 *
 * startDateLocale: дата start, конвертированная в формат строки (toLocaleString)
 *
 * endDateLocale: дата end, конвертированная в формат строки (toLocaleString)
 *
 * @example
 * Текущее время 2024 июль 19 12:11
 * createDate(-2, 2) вернёт объект:
 *
 * {
    "start": "2024-07-19T07:11:06.734Z",
    "end": "2024-07-19T11:11:06.734Z",
    "startDateLocale": "19.07.2024, 10:11:06",
    "endDateLocale": "19.07.2024, 14:11:06"
*  }
*/
export declare function createDate(from: number, to: number): {
    start: Date;
    end: Date;
    startDateLocale: string;
    endDateLocale: string;
};
