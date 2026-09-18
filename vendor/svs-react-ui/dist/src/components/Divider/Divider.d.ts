import './Divider.scss';
import { HTMLAttributes, MouseEventHandler } from 'react';
export interface DividerProps extends HTMLAttributes<HTMLDivElement> {
    type?: 'horizontal' | 'vertical';
    styleType?: 'default' | 'secondary';
    padding?: 's' | 'm' | 'none';
    onMouseDown?: MouseEventHandler<HTMLDivElement>;
}
export declare const Divider: ({ padding, type, styleType, className, ...rest }: DividerProps) => import("react/jsx-runtime").JSX.Element;
