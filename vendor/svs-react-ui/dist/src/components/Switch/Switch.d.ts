import { CSSProperties, HTMLAttributes, ChangeEvent } from 'react';
import './Switch.scss';
export type SwitchSize = 'm' | 's';
export interface SwitchProps extends HTMLAttributes<HTMLInputElement> {
    checked?: boolean;
    className?: string;
    disabled?: boolean;
    size?: SwitchSize;
    style?: CSSProperties;
    onChange?: (event: ChangeEvent<HTMLInputElement>) => void;
    showIcon?: boolean;
    wrapperWidth?: number | string;
    clickableLabel?: boolean;
    wrapText?: boolean;
    labelPosition?: 'left' | 'right';
    loading?: boolean;
}
export declare const Switch: ({ checked, className, disabled, size, style, onChange, showIcon, wrapperWidth, children, clickableLabel, wrapText, labelPosition, loading, ...rest }: SwitchProps) => import("react/jsx-runtime").JSX.Element;
