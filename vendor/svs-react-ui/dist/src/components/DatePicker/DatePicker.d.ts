import { CSSProperties, FocusEvent, HTMLAttributes } from 'react';
import { CalendarProps } from '../Calendar/Calendar';
import { InputProps, StatusTypes, type Variant } from '../Input';
import './DatePicker.scss';
export interface DatePickerProps extends Partial<Pick<InputProps, 'disabled' | 'size' | 'onEnter' | 'width' | 'className' | 'clearable' | 'label' | 'message' | 'placeholder' | 'autoFocus' | 'onClear' | 'autoComplete'>>, Omit<HTMLAttributes<HTMLDivElement>, 'onBlur' | 'onChange' | 'onSelect'>, Pick<CalendarProps, 'todayButton' | 'disabledDate' | 'picker'> {
    /**
     * Стиль оформления поля
     * @default default
     */
    variant?: Variant;
    /**
     * Булев параметр скрытия иконки календаря
     * @default false
     */
    hideIcon?: boolean;
    /**
     * Событие возвращающее новое валидное значение.<br>
     * ⚠ Не вызывается при невалидном значении, если `allowInvalidOnChange = false`.
     * @param valueString - новое строковое значение
     * @param valueDate - значение в формате Date. При isInterval = true - первое значение в интервале
     * @param valueDateEnd - значение в формате Date. При isInterval = true - второе значение в интервале, при isInterval = false - null
     */
    onChange?: (valueString: string | null, valueDate: Date | null, valueDateEnd: Date | null) => void;
    /**
     * Событие возвращающее новое значение при потере фокуса
     * @param valueString - строковое значение
     * @param valueDate - значение в формате Date. При isInterval = true: первое значение в интервале
     * @param valueDateEnd - значение в формате Date. При isInterval = true: второе значение в интервале, при isInterval = false - null
     * @deprecated будет удалено в мажорной версии. Вместо этого свойства используйте onBlur
     */
    onChanged?: (valueString: string | null, valueDate: Date | null, valueDateEnd: Date | null) => void;
    /**
     * Событие возвращающее значение при потере фокуса
     * @param valueString - строковое значение
     * @param valueDate - значение в формате Date. При isInterval = true: первое значение в интервале
     * @param valueDateEnd - значение в формате Date. При isInterval = true: второе значение в интервале, при isInterval = false - null
     * @param e - событие blur компонента Input
     */
    onBlur?: (valueString: string | null, valueDate: Date | null, valueDateEnd: Date | null, e: FocusEvent<HTMLInputElement>) => void;
    /**
     * Возможность выбора интервала дат
     * @default false
     */
    isInterval?: boolean;
    /**
     * Отображение статуса валидности
     */
    status?: StatusTypes;
    /**
     * Значение по-умолчанию. При изменении заменяется.
     * @deprecated Поведение этого свойства будет сильно изменено в мажорной версии. Внимательно прочитайте миграцию перед обновлением!
     */
    value?: Date | string | null;
    /**
     * callback-функция, вызывается когда открывается или закрывается календарь
     * @param open - текущее состояние календаря
     */
    onOpenChange?: (open: boolean) => void;
    /** Установка style для Popover календаря */
    popupStyle?: CSSProperties;
    /** Установка className для Popover календаря */
    popupClassName?: string;
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
    format?: string;
    /**
     * Управляет вызовом `onChange` в зависимости от валидности данных
     * При `true`: onChange вызывается как для валидных, так и для невалидных значений
     * При `false` (по умолчанию): onChange вызывается только для валидных значений.
     * @default false
     */
    allowInvalidOnChange?: boolean;
    /**
     * Событие, возвращающее выбранную из календаря дату или интервал дат
     * @param val - выбранное значение
     */
    onSelect?: (valueString: string | null, valueDate: Date | null, valueDateEnd: Date | null) => void;
    /**
     * Устанавливает фокус на поле ввода после выбора даты в календаре
     * @default false
     */
    focusAfterSelect?: boolean;
}
export declare const DatePicker: ({ disabled, value, size, variant, onChange, onChanged, onBlur, onEnter, width, hideIcon, clearable, className, label, isInterval, style, message, status, placeholder, autoFocus, todayButton, onClear, onOpenChange, autoComplete, popupStyle, popupClassName, format, allowInvalidOnChange, focusAfterSelect, disabledDate, onSelect, picker, ...rest }: DatePickerProps) => import("react/jsx-runtime").JSX.Element;
