import { TagProps } from '../Tag';
import './CheckableTag.scss';
export interface CheckableTagProps extends Omit<TagProps, 'closable' | 'onRemove' | 'onChange' | 'disabled' | 'tabIndex'> {
    checked: boolean;
    onChange?: (checked: boolean) => void;
    tabIndex?: number;
}
export declare const CheckableTag: import("react").ForwardRefExoticComponent<CheckableTagProps & import("react").RefAttributes<HTMLSpanElement>>;
