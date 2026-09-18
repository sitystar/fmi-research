/**
 * @description Функция принимает дату и время в формате строки и возвращает объект даты,
 * соответствующий этим дате и времени.
 * @param {string} dateLocale строка, содержащая дату и время в локальном часовом поясе.
 * @returns Возвращает объект даты.
 * @example
 * convertLocalStringToDate('19.07.2024, 15:16:44')
 * вернёт
 * Fri Jul 19 2024 15:16:44 GMT+0300 (Москва, стандартное время)
 */
export declare function convertLocalStringToDate(dateLocale: string): Date;
