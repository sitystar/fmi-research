import { ReactNode, ButtonHTMLAttributes, CSSProperties } from 'react';
import './Chip.scss';
export type ChipSize = 'l' | 'm' | 's';
export interface ChipProps extends ButtonHTMLAttributes<HTMLButtonElement> {
    size?: ChipSize;
    htmlType?: 'button' | 'submit' | 'reset';
    disabled?: boolean;
    style?: CSSProperties;
    className?: string;
    children?: ReactNode;
}
export declare const Chip: ({ size, htmlType, disabled, style, className, children, ...rest }: ChipProps) => import("react/jsx-runtime").JSX.Element;
