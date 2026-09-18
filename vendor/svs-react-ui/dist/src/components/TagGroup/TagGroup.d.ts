import { MouseEvent, HTMLAttributes } from 'react';
import { TagProps } from '../Tag';
import './TagGroup.scss';
import { StatusTagProps } from '../Tag/StatusTag/StatusTag';
import { CheckableTagProps } from '../Tag/CheckableTag/CheckableTag';
export type Item = Pick<TagProps, 'children' | 'icon' | 'disabled'> & Pick<StatusTagProps, 'status' | 'variant'> & {
    value?: string;
};
export type CheckableItem = Pick<TagProps, 'children' | 'icon'> & Pick<CheckableTagProps, 'checked' | 'onChange' | 'onClick' | 'tabIndex'> & {
    value?: string;
};
type TagType = 'default' | 'status' | 'checkable';
export interface TagGroupProps extends Pick<TagProps, 'rounded' | 'size' | 'closable'>, HTMLAttributes<HTMLDivElement> {
    items: Item[] | CheckableItem[];
    onRemove?: (e: MouseEvent<HTMLElement>, item: Item) => void;
    onExpandClick?: (e: MouseEvent<HTMLButtonElement>) => void;
    expand?: boolean;
    closable?: boolean;
    tagType?: TagType;
}
export declare const TagGroup: ({ size, items, rounded, expand, closable, onRemove, tagType, onExpandClick, className, style, ...rest }: TagGroupProps) => import("react/jsx-runtime").JSX.Element;
export {};
