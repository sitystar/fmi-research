import { HTMLAttributes, ReactNode } from 'react';
import { CheckboxProps } from '../Checkbox';
import { DatePickerProps } from '../DatePicker';
import { DropdownItemType } from '../Dropdown/DropdownItem';
import { InputProps } from '../Input';
import { SelectorProps } from '../Selector';
import { TableColTypes } from '../Table';
import { TimePickerProps } from '../TimePicker';
import './SideFilter.scss';
export type FilterValues = ReactNode | string | number | boolean | DropdownItemType | DropdownItemType[] | null;
export type FilterItemOptionsTypes = InputProps | DatePickerProps | SelectorProps | TimePickerProps | CheckboxProps;
export interface FilterItem<T extends string = string> {
    name: T;
    label: string;
    type: TableColTypes;
    component?: 'Selector' | 'Input' | 'TimePicker' | 'DatePicker' | 'Checkbox';
    defaultValue?: FilterValues;
    options?: FilterItemOptionsTypes;
}
export type ConfirmValues<T extends string = string> = {
    [K in T]?: FilterValues;
};
interface ISideFilter<T extends string = string> extends Omit<HTMLAttributes<HTMLDivElement>, 'title'> {
    /**
     * Состояние открыт/закрыт
     * @default false
     * */
    open: boolean;
    className?: string;
    /** Callback-функция возвращающая объект с параметрами фильтрации при нажатии на кнопку Применить */
    onConfirm?: (items: ConfirmValues<T>) => void;
    /** Callback-функция вызывающаяся при закрытии компонента */
    onClose?: () => void;
    /**
     * Свойство запрещающее/разрешающее закрывать компонент по нажатии по кнопке Подтвердить
     * @default false
     */
    closeOnConfirm?: boolean;
    /**
     * Заголовок компонента
     * @default Фильтр
     * */
    title?: ReactNode;
    /** Ширина компонента */
    width?: string | number;
    /** Рендер-функция для кастомизации футера компонента */
    renderFooter?: ReactNode;
    /**
     * Callback-функция, вызываемая при нажатии на кнопку очистки.
     * Позволяет вручную сбросить или изменить выбранные параметры фильтрации.
     *
     * Если callback не передан, все параметры фильтрации будут очищены.
     *
     * @param currentValues - текущие выбранные параметры фильтрации
     * @returns возвращает обработанные параметры фильтрации
     * */
    onClear?: (currentValues: ConfirmValues<T>) => ConfirmValues<T> | Promise<ConfirmValues<T>> | undefined | null;
    /**
     * Текст кнопки подтвержжения применения фильтра.
     * @default Применить
     */
    confirmButtonText?: string;
    /**
     * Текст кнопки очистки фильтра.
     * @default Очистить
     */
    clearButtonText?: string;
}
export interface ISideFilterWithItems<T extends string = string> extends ISideFilter<T> {
    /** Массив фильтруемых столбцов */
    items: FilterItem<T>[];
    /** Рендер-функция для кастомизации содержимого компонента */
    renderContent?: ReactNode;
}
export interface ISideFilterWithRenderContent<T extends string = string> extends ISideFilter<T> {
    /** Массив фильтруемых столбцов */
    items?: FilterItem[];
    /** Рендер-функция для кастомизации содержимого компонента */
    renderContent: ReactNode;
}
export type SideFilterProps<T extends string = string> = ISideFilterWithItems<T> | ISideFilterWithRenderContent<T>;
export declare const SideFilter: <T extends string = string>({ open, className, items, onConfirm, onClose, closeOnConfirm, title, width, renderContent, renderFooter, onClear, confirmButtonText, clearButtonText, ...rest }: SideFilterProps<T>) => import("react/jsx-runtime").JSX.Element;
export {};
