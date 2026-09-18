/**
 * Проверка на валидность строки в формате даты
 * @param dateStr дата в виде строки в формате dd.mm.yyyy
 * @returns булево значение
 */
export declare const isValidDate: (dateStr: string) => boolean;
/**
 * Преобразование строки формата dd.mm.yyyy в дату
 * @param dateStr строка
 * @returns дата
 */
export declare const stringToDate: (dateStr: string) => Date;
/**
 * Преобразование даты в строку формата времени
 * @param d дата формата ISO 8601 или объект Date
 * @returns строка в формате hh:MM
 */
export declare const dateTimeToString: (d: Date | string) => string;
/**
 * Проверка на валидность времени
 * @param time строка формата HH:mm или HH:mm:ss или HH:mm:ss.sss
 * @param format - формат времени: HH:mm, HH:mm:ss, HH:mm:ss.sss
 * @returns
 */
export declare const isValidatedTime: (time: string | null, format?: string) => boolean;
/**
 * Проверяет, является ли переданное значение датой формата ISO 8601 или объектом Date
 * @param date дата формата Date
 * @returns `true`, если значение может быть преобразовано в дату, иначе `false`
 */
export declare const isValidDateValue: (date: Date) => boolean;
/**
 * Преобразование date типа Date в формат format
 * Поддерживаемые форматы format:<br>
 * <ul>
 *   <li>YYYY - год, 4 цифры</li>
 *   <li>MM - месяц, 2 цифры, 01-12</li>
 *   <li>DD - день, 2 цифры, 01-31</li>
 * </ul>
 * @param date - значение типа Date
 * @param format - формат
 */
export declare const formatDate: (date: Date, format: string) => string | null;
/**
 * Преобразует строковую дату в заданном формате в объект Date.
 * Строго проверяет разделители. Поддерживает форматы с YYYY, MM и опционально DD.
 * @param dateString Строка с датой (например, "31.12.2023" или "2023.12")
 * @param format Формат даты (например, "DD.MM.YYYY" или "YYYY.MM")
 * @returns Объект Date, если строка валидна и полностью соответствует формату, иначе null.
 */
export declare const stringToDateByFormat: (dateString: string, format: string) => Date | null;
/**
 * Сортирует 2 даты начиная с более ранней
 * @param firstDay - первая дата
 * @param secondDay - вторая дата
 */
export declare const sortIntervalDays: (firstDay: Date, secondDay: Date) => Date[];
