import { RefObject } from 'react';
import { DropdownItemType } from '../../Dropdown';
import { DropdownItemValueTypes } from '~/components/Dropdown/DropdownItem';
import { FieldNames, SelectorItemsType, SelectorProps } from '~/components/Selector';
import { InputSize } from '~/components/Input';
export declare const useTags: <T extends DropdownItemValueTypes = DropdownItemValueTypes>(selectedItems: SelectorItemsType[], internalInputRef: RefObject<HTMLInputElement | null>, handleDropdownItemClick: (item: DropdownItemType<T> | DropdownItemType<T>[]) => void, disabled: boolean, itemKeys: FieldNames, size: InputSize, readonly: boolean, status: SelectorProps["status"]) => {
    tagsRender: import("react/jsx-runtime").JSX.Element;
    hiddenTagsCount: number;
};
