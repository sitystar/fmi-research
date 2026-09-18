import { FormEvent, HTMLAttributes, ReactElement, ReactNode, RefAttributes } from 'react';
import { DropdownItemType, DropdownItemValueTypes } from './DropdownItem';
import './Dropdown.scss';
import { PopoverPlacementType, PopoverProps } from '../Popover';
import { FieldNames } from '../Selector';
export interface DropdownProps<T extends DropdownItemValueTypes = DropdownItemValueTypes> extends Omit<HTMLAttributes<HTMLDivElement>, 'onSelect'>, Pick<PopoverProps, 'appendToBody' | 'offset' | 'closeOnClickOutside'> {
    multiple?: boolean;
    items: DropdownItemType<T>[];
    open?: boolean;
    onSelect?: (val: DropdownItemType<T> | DropdownItemType<T>[]) => void;
    width?: string | number;
    emptyText?: string;
    footer?: boolean;
    selectedValue?: T | T[];
    children?: ReactNode;
    selectable?: boolean;
    trigger?: 'hover' | 'click' | 'focus';
    position?: PopoverPlacementType;
    onVisibleChange?: (val: boolean) => void;
    /**
     * Высота контейнера списка
     *
     * _Заданное значение в виде **строки** не применимо при **virtual = true**_
     * @see virtual
     */
    listHeight?: number | string;
    /**
     * Позволяет задавать пользовательские названия вместо стандартных значений полей объекта items.
     */
    itemKeys?: FieldNames;
    /**
     * Флаг включающий закрывание дропдауна при клике по элементам внутри.
     * В случае `multiple = true` всегда равно `false`
     * @default true
     * */
    closeOnClickInside?: PopoverProps['closeOnClickInside'];
    optionRender?: (item: DropdownItemType<T>) => ReactNode;
    dropdownRender?: (itemsRender: ReactNode) => ReactNode;
    /**
     * Включение/отключение виртуализации списка. Для корректного отображения включенной виртуализации может потребоваться установка width.
     * @default false
     * */
    virtual?: boolean;
    /**
     * Включает/выключает возможность производить поиск по пунктам
     * @default true
     */
    showSearch?: boolean;
    /**
     * Callback-функция, возвращающая набираемый текст в поле поиска
     * @param val - введенное значение
     */
    onSearch?: (val: string) => void;
    /**
     * Включает/выключает отображение переключателя "Показать выбранные"
     * @default false
     */
    showSelectedSwitch?: boolean;
    /**
     * Включает/выключает отображение переключателя "Выбрать всё"
     *
     * Работает только в режиме multiple
     *
     * @default true
     */
    showSelectAll?: boolean;
    /**
     * Callback-функция, вызываемая при вводе текста в поле поиска
     * @param e - событие ввода
     */
    onInput?: (e: FormEvent<HTMLInputElement>) => void;
    /**
     * Максимальное количество выбранных элементов.
     * Работает только в режиме multiple.
     * При достижении лимита остальные пункты меню будут disabled.
     */
    maxCount?: number;
}
export declare const DROPDOWN_CLASS_NAME = "svs-dropdown";
type DropdownType = <T extends DropdownItemValueTypes = DropdownItemValueTypes>(props: DropdownProps<T> & RefAttributes<HTMLDivElement>) => ReactElement;
export declare const Dropdown: DropdownType;
export {};
