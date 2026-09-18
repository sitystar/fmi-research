import { HTMLAttributes, ReactNode } from 'react';
import './Calendar.scss';
export interface CalendarProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    /**
     * Конечная выбранная дата в интервале
     *
     * _Позволяет управлять состоянием компонента_
     */
    previouslySelected?: Date | null;
    /**
     * Выбранная дата / Начальная выбранная дата в интервале
     *
     * _Позволяет управлять состоянием компонента_
     */
    selected?: Date | null;
    /**
     * Выбранная дата по умолчанию / Начальная дата по умолчанию для интервала
     * @default null
     */
    defaultSelected?: Date | null;
    /**
     * Конечная дата интервала по-умолчанию
     * @default null
     */
    defaultPreviouslySelected?: Date | null;
    /**
     * Обработчик изменения выбранной даты.
     * Вызывается при выборе даты или диапазона дат.
     * @param date - Выбранная дата или массив дат (при выборе интервала).
     */
    onChange?: (date: Date | (Date | null)[]) => void;
    /**
     * Свойство управляющее видимостью календаря.
     * @default true
     */
    isVisible?: boolean;
    /**
     * Включает режим выбора интервала дат (диапазон).
     * @default false
     */
    isInterval?: boolean;
    /**
     * Показывает кнопку "Сегодня" для быстрого выбора текущей даты.
     * @default false
     */
    todayButton?: boolean;
    /**
     * Свойство принимающее обратную функцию, позволяющее указывать даты, которые нельзя выбрать.
     *
     * Должна возвращать true, если дата недоступна для выбора.
     *
     * @example
     * (date: Date) => {
     *   const now = new Date()
     *   const today = new Date(now.getFullYear(), now.getMonth(), now.getDate())
     *
     *   return +date === +today
     * }
     *
     * @default undefined
     */
    disabledDate?: (currentDate: Date) => boolean;
    /**
     * Дополнительный контент для отображения в футере календаря.
     *
     * Если есть кнопка "Сегодня", то отображается над ней, иначе в самом низу
     * @default null
     */
    footerContent?: ReactNode;
    /**
     * Определяет вариант выбора.
     *
     * 'days' - позволяет выбирать полную дату (день, месяц, год).
     *
     * 'months' - позволяет выбирать только месяц и год.
     * @default 'days'
     */
    picker?: 'date' | 'month';
}
export declare const CALENDAR_CLASS_NAME = "svs-calendar";
export declare const Calendar: ({ previouslySelected, selected, defaultSelected, defaultPreviouslySelected, onChange, isVisible, className, isInterval, todayButton, disabledDate, footerContent, picker, ...rest }: CalendarProps) => import("react/jsx-runtime").JSX.Element;
