import { CSSProperties } from 'react';
import { DropdownItemType } from '../Dropdown/DropdownItem';
import { FieldNames, SelectorProps } from './Selector';
import { InputSize } from '../Input';
export interface TagProps extends Pick<SelectorProps, 'status'> {
    item: DropdownItemType;
    selectedItems: DropdownItemType[];
    onRemove?: (items: DropdownItemType[]) => void;
    disabled?: boolean;
    style?: CSSProperties;
    itemKeys: FieldNames;
    size: InputSize;
}
export declare const SelectorTag: import("react").ForwardRefExoticComponent<TagProps & import("react").RefAttributes<HTMLButtonElement>>;
