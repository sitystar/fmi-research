import { TagProps } from '../Tag';
import './StatusTag.scss';
export interface StatusTagProps extends Omit<TagProps, 'disabled'> {
    status?: 'error' | 'warning' | 'success' | 'edited' | 'neutral';
    variant?: 'outline' | 'fill';
}
export declare const StatusTag: import("react").ForwardRefExoticComponent<StatusTagProps & import("react").RefAttributes<HTMLSpanElement>>;
