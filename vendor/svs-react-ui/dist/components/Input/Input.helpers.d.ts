import { ChangeEvent } from 'react';
export declare const prepareMaskTime: (value: string, defaultValue: string) => string;
export declare const PHONE_DIGITS_LENGTH = 11;
export declare const preparePhoneMask: (value: string, e: ChangeEvent<HTMLInputElement>) => string;
/**
 * форматирование введенных данных по маске даты DD.MM.YYYY
 * @param value - новое значение
 * @param defaultValue - предыдущее значение
 */
export declare const prepareDateMask: (value: string, defaultValue: string) => string;
export declare const prepareDateIntervalMask: (value: string, defaultValue: string) => string;
/**
 * Форматирует значение времени в маске HH:mm:ss
 * @param inputValue - текущее значение (берется из e.target.value)
 * @param prevValue - предыдущее введенное значение (берется из e.target.prevValue)
 * @returns Отформатированная строка времени
 */
export declare const prepareMaskTimeWithSeconds: (inputValue: string, prevValue?: string) => string;
interface UUIDdMaskProps {
    inputValue: string;
    prevValue?: string;
    selectionStart: number | null;
}
export declare const prepareUUIDMask: ({ inputValue, prevValue, selectionStart }: UUIDdMaskProps) => string;
/**
 * форматирование введенных данных по маске месяца YYYY.MM
 * @param value - новое значение
 * @param defaultValue - предыдущее значение
 */
export declare const prepareMonthMask: (value: string, defaultValue: string) => string;
export {};
