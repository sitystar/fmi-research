import './DropdownItem.scss';
import { HTMLAttributes, KeyboardEvent, MouseEvent, ReactElement, ReactNode, RefAttributes } from 'react';
import { FieldNames } from '../Selector';
export type DropdownItemValueTypes = number | string | boolean | symbol | bigint | null;
export interface DropdownItemType<T extends DropdownItemValueTypes = DropdownItemValueTypes> {
    value?: T;
    label?: string;
    description?: string;
    icon?: {
        content: ReactNode;
        position?: 'left' | 'right';
    };
    disabled?: boolean;
    [name: string]: any;
}
interface DropdownItemProps<T extends DropdownItemValueTypes = DropdownItemValueTypes> extends Omit<HTMLAttributes<HTMLDivElement>, 'onClick'> {
    item: DropdownItemType<T>;
    multiple?: boolean;
    isActive: boolean;
    isIndeterminate?: boolean;
    onClick?: (item: DropdownItemType<T>, event: MouseEvent | KeyboardEvent) => void;
    className?: string;
    isIconBefore?: boolean;
    itemKeys: FieldNames;
    optionRender?: (item: DropdownItemType<T>) => ReactNode;
}
type InternalDropdownItemType = <T extends DropdownItemValueTypes = DropdownItemValueTypes>(props: DropdownItemProps<T> & RefAttributes<HTMLDivElement>) => ReactElement;
export declare const DropdownItem: InternalDropdownItemType;
export {};
