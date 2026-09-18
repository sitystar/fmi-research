import { ButtonHTMLAttributes, CSSProperties, ReactNode } from 'react';
import './Button.scss';
export type ButtonSize = 'xl' | 'l' | 'm' | 's' | 'xs';
export type ButtonStyleType = 'primary' | 'secondary' | 'tertiary' | 'warning' | 'link' | 'link-secondary';
export interface ButtonProps extends ButtonHTMLAttributes<HTMLButtonElement> {
    size?: ButtonSize;
    styleType?: ButtonStyleType;
    disabled?: boolean;
    isLoading?: boolean;
    isSelected?: boolean;
    htmlType?: 'button' | 'submit' | 'reset';
    iconOnly?: ReactNode;
    beforeContent?: ReactNode;
    afterContent?: ReactNode;
    loaderIcon?: ReactNode;
    style?: CSSProperties;
    className?: string;
    children?: ReactNode;
    wrap?: boolean;
    width?: string | number;
}
export declare const Button: import("react").ForwardRefExoticComponent<ButtonProps & import("react").RefAttributes<HTMLButtonElement>>;
