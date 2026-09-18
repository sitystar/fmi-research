/**
 * Ограничивает значение заданным диапазоном min/max.
 * @param val Значение для ограничения. Предполагается, что val НЕ null.
 * @param min Минимальное значение. Если null/undefined, ограничение не применяется.
 * @param max Максимальное значение. Если null/undefined, ограничение не применяется.
 * @returns Ограниченное значение.
 */
export declare const clampValue: (val: number | bigint, min?: number | bigint | null, max?: number | bigint | null) => number | bigint;
/**
 * Проверяет, находится ли числовое значение в допустимом диапазоне min/max.
 * @param val Значение для проверки.
 * @param min Минимальное допустимое значение. Если null/undefined, ограничение не применяется.
 * @param max Максимальное допустимое значение. Если null/undefined, ограничение не применяется.
 * @returns true, если значение валидно, иначе false.
 */
export declare const isInRange: (val: number | bigint | null, min?: number | bigint | null, max?: number | bigint | null) => boolean;
/** округление числа */
export declare const applyPrecision: (val: number | bigint, precision?: number) => number | bigint;
/** преобразование введенного текста в число */
export declare const defaultParser: (displayValue: string) => number | bigint;
/** преобразование введенного текста в bigint */
export declare const bigIntParser: (displayValue: string) => bigint | null;
/** Функция для безопасного преобразования в BigInt, отбрасывая дробную часть */
export declare const safeConvertToBigInt: (val: number | bigint | string | null) => bigint | null;
/**
 * Безопасное выполнение арифметической операции над числом с дробной частью.
 * Если задана точность, она используется для определения масштабирования,
 * иначе вычисляется на основании максимального числа цифр после запятой в num и step.
 */
export declare const operate: (num: number | bigint, step: number | bigint, operation: "add" | "subtract", precision?: number) => number | bigint;
export declare const isNumeric: (val: unknown) => val is number | bigint;
