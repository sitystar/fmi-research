import { Ref, ReactNode, HTMLAttributes, CSSProperties, ReactElement, RefAttributes } from 'react';
import { DropdownProps } from '../Dropdown';
import { DropdownItemType, DropdownItemValueTypes } from '../Dropdown/DropdownItem';
import { InputProps } from '../Input';
import './Selector.scss';
export type SelectorItemsType<T extends DropdownItemValueTypes = DropdownItemValueTypes> = DropdownItemType<T>;
export type FieldNames = {
    value: string;
    label: string;
};
export declare const getItemByValue: <T extends DropdownItemValueTypes = DropdownItemValueTypes>(items: DropdownItemType<T>[], value: T, itemKeys: FieldNames) => DropdownItemType<T>;
export interface SelectorProps<T extends DropdownItemValueTypes = DropdownItemValueTypes> extends Omit<HTMLAttributes<HTMLDivElement>, 'onSelect' | 'onChange' | 'onBlur'>, Pick<InputProps, 'label' | 'size' | 'clearable' | 'autoComplete' | 'onClear' | 'loading' | 'status' | 'onBlur'>, Pick<DropdownProps, 'listHeight' | 'optionRender' | 'dropdownRender' | 'virtual' | 'onSearch' | 'onVisibleChange' | 'showSelectedSwitch' | 'maxCount'> {
    variant?: 'default' | 'none';
    width?: string | number;
    disabled?: boolean;
    message?: string;
    iconBefore?: ReactNode;
    placeholder?: string;
    onChange?: (val: T, item?: DropdownItemType<T>) => void;
    multiple?: boolean;
    items: DropdownItemType<T>[];
    onSelect?: (val: DropdownItemType<T> | DropdownItemType<T>[]) => void;
    emptyText?: string;
    footer?: boolean;
    selectedValue?: T | T[];
    readonly?: boolean;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте ref
     */
    inputRef?: Ref<HTMLInputElement | null>;
    appendToBody?: boolean;
    fieldNames?: FieldNames;
    filterOption?: (string: string, item: DropdownItemType<T>) => void;
    dropdownStyle?: CSSProperties;
    dropdownClassName?: string;
    /**
     * Включает/выключает возможность производить поиск по пунктам
     * @default true
     */
    showSearch?: boolean;
    /**
     * Callback-функция, вызываемая при вводе текста в поле поиска
     */
    onInput?: (e: React.FormEvent<HTMLInputElement>) => void;
    /**
     * Включает/выключает отображение переключателя "Выбрать всё"
     *
     * Работает только в режиме multiple
     *
     * @default false
     */
    showSelectAll?: boolean;
}
type SelectorType = <T extends DropdownItemValueTypes = DropdownItemValueTypes>(props: SelectorProps<T> & RefAttributes<HTMLInputElement>) => ReactElement;
export declare const Selector: SelectorType;
export {};
