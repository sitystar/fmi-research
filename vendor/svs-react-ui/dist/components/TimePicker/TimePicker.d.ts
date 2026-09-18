import { HTMLAttributes, CSSProperties } from 'react';
import './TimePicker.scss';
import { InputProps, StatusTypes } from '../Input';
export type TimePickerFormatTypes = 'HH:mm' | 'HH:mm:ss';
export interface TimePickerProps extends Pick<InputProps, 'disabled' | 'value' | 'size' | 'width' | 'clearable' | 'label' | 'onChanged' | 'onBlur' | 'message' | 'className' | 'placeholder' | 'autoFocus' | 'variant' | 'onClear' | 'autoComplete'>, Omit<HTMLAttributes<HTMLDivElement>, 'onBlur' | 'onChange' | 'onSelect'> {
    /**
     * Событие, возвращающее новое значение.
     * ⚠ Не вызывается при невалидном значении, если `allowInvalidOnChange = false`.
     * @param val - новое строковое значение или null
     */
    onChange?: (val: string | null) => void;
    status?: StatusTypes;
    /** фокус в поле ввода не сбрасывается после выбора времени в списке */
    focusAfterSelect?: boolean;
    hideIcon?: boolean;
    timeList?: string[];
    popupStyle?: CSSProperties;
    popupClassName?: string;
    format?: TimePickerFormatTypes;
    /**
     * Управляет вызовом `onChange` в зависимости от валидности данных
     * При `true`: onChange вызывается как для валидных, так и для невалидных значений
     * При `false` (по умолчанию): onChange вызывается только для валидных значений.
     * @default false
     */
    allowInvalidOnChange?: boolean;
    /** Событие, возвращающее выбранное из списка значение */
    onSelect?: (val: string | null) => void;
}
export declare const TIMEPICKER_CLASS_NAME = "svs-timepicker";
export declare const TimePicker: ({ disabled, value, size, variant, onChange, onChanged, onSelect, onBlur, width, clearable, label, style, message, status, className, placeholder, autoFocus, onClear, focusAfterSelect, hideIcon, autoComplete, timeList, popupStyle, popupClassName, format, allowInvalidOnChange, ...rest }: TimePickerProps) => import("react/jsx-runtime").JSX.Element;
