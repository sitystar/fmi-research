import { CSSProperties, HTMLAttributes, MouseEvent, ReactNode, FocusEvent } from 'react';
import './DateTimePicker.scss';
import { DatePickerProps } from '../DatePicker';
import { TimePickerFormatTypes } from '../TimePicker';
import { InputProps, StatusTypes } from '../Input';
export type onChangeData = {
    valueString: string;
    value?: Date | null;
};
export interface DateTimePickerProps extends Partial<Pick<InputProps, 'disabled' | 'size' | 'clearable' | 'className' | 'width' | 'autoComplete' | 'label'>>, Omit<HTMLAttributes<HTMLDivElement>, 'onChange' | 'onBlur'>, Pick<DatePickerProps, 'todayButton'> {
    /**
     * Булев параметр скрытия иконки календаря у поля "Дата"
     * @deprecated Будет удалено в мажорной версии. Вместо этого свойства используйте hideDateIcon
     */
    hideIcon?: boolean;
    /** Булев параметр скрытия иконки календаря у поля "Дата" */
    hideDateIcon?: boolean;
    /** Булев параметр скрытия иконки часов у поля "Время" */
    hideTimeIcon?: boolean;
    /**
     * Событие возвращающее новое значение при вводе дате и времени.<br>
     * ⚠ Не вызывается при невалидном значении, если `allowInvalidOnChange = false`.
     * @param {Object} onChangeData
     * @param onChangeData.valueString - строковое значение
     * @param onChangeData.value - значение типа Date, или `null` / `undefined` при невалидном или пустом вводе.
     */
    onChange?: ({ valueString, value }: onChangeData) => void;
    /**
     * callback-функция, вызывающаяся при очищении даты
     * @param e - событие нажатия на кнопку
     */
    onDateClear?: (e: MouseEvent) => void;
    /**
     * callback-функция, вызывающаяся при очищении времени
     * @param e - событие нажатия на кнопку
     */
    onTimeClear?: (e: MouseEvent) => void;
    /** placeholder для поля "Дата" */
    placeholderDate?: string;
    /** placeholder для поля "Время" */
    placeholderTime?: string;
    /** Статус, в зависимости от которого меняется цвет обводки у поля "Дата" и цвет поля "message" */
    statusDate?: StatusTypes;
    /** Статус, в зависимости от которого меняется цвет обводки у поля "Время" и цвет поля "message" */
    statusTime?: StatusTypes;
    /**
     * Значение по-умолчанию. При изменении заменяется.<br>
     * Принимает строку формата "dateFormat timeFormat", где дата и время разделены пробелом.<br>
     * Принимает значение типа Date
     * @deprecated Поведение этого свойства будет сильно изменено в мажорной версии. Внимательно прочитайте миграцию перед обновлением!
     */
    value?: Date | string | null;
    /** Текст под полями ввода */
    message?: ReactNode;
    /** Список времен для выпадающего списка у поля "Время".<br>
     * Принимает массив строк формата "ЧЧ:ММ". <br>
     * ⚠ Если не передавать "timeList", то по умолчанию список будет начинаться с 00:00 с шагом 30 минут
     */
    timeList?: string[];
    /** Установка style для popup выпадающего списка */
    popupTimeStyle?: CSSProperties;
    /** Установка className для popup выпадающего списка */
    popupTimeClassName?: string;
    /** Установка style для Popover календаря */
    popupDateStyle?: CSSProperties;
    /** Установка className для Popover календаря */
    popupDateClassName?: string;
    /**
     * Формат времени
     * @default HH:mm
     */
    timeFormat?: TimePickerFormatTypes;
    /**
     * Форматирование даты.<br>
     * ⚠ <i>Требует тип value = Date, string ISO 8601 (UTC)</i><br>
     * ⚠ <i>Отключает маску ввода</i><br>
     * Поддерживаемые форматы:<br>
     *   <b>YYYY</b> - год, 4 цифры<br>
     *   <b>MM</b> - месяц, 2 цифры, 01-12<br>
     *   <b>DD</b> - день, 2 цифры, 01-31<br>
     * @default DD.MM.YYYY
     */
    dateFormat?: DatePickerProps['format'];
    /**
     * Управляет вызовом `onChange` в зависимости от валидности данных
     * При `true`: onChange вызывается как для валидных, так и для невалидных значений
     * При `false` (по умолчанию): onChange вызывается только для валидных значений.
     * @default false
     */
    allowInvalidOnChange?: boolean;
    /**
     * Callback-функция, вызывающаяся если фокус не остался и на дате и на времени
     */
    onBlur?: (valueString: string | null, e: FocusEvent<HTMLInputElement>) => void;
    /**
     * Устанавливает фокус на поле ввода после выбора даты или времени
     * @default false
     */
    focusAfterSelect?: boolean;
}
export declare const DateTimePicker: ({ disabled, value, hideIcon, hideDateIcon, hideTimeIcon, size, clearable, onChange, className, style, width, todayButton, onDateClear, onTimeClear, placeholderDate, placeholderTime, autoComplete, statusDate, statusTime, label, message, timeList, popupTimeStyle, popupTimeClassName, popupDateStyle, popupDateClassName, timeFormat, dateFormat, allowInvalidOnChange, onBlur, autoFocus, focusAfterSelect, ...rest }: DateTimePickerProps) => import("react/jsx-runtime").JSX.Element;
