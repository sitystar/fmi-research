import { ForwardRefExoticComponent, RefAttributes } from 'react';
import './Tag.scss';
import { CheckableTagProps } from './CheckableTag/CheckableTag';
import { TagCommonProps } from './Tag.common';
import { StatusTagProps } from './StatusTag/StatusTag';
export interface TagProps extends TagCommonProps {
    disabled?: boolean;
}
interface TagCompoundedComponent extends ForwardRefExoticComponent<TagProps & RefAttributes<HTMLSpanElement>> {
    CheckableTag: ForwardRefExoticComponent<CheckableTagProps & RefAttributes<HTMLSpanElement>>;
    StatusTag: ForwardRefExoticComponent<StatusTagProps & RefAttributes<HTMLSpanElement>>;
}
export declare const Tag: TagCompoundedComponent;
export {};
