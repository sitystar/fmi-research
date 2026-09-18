import './Radio.scss';
import { CSSProperties, HTMLAttributes, ReactNode } from 'react';
export type RadioValues = string | number;
export interface RadioProps extends Omit<HTMLAttributes<HTMLInputElement | HTMLButtonElement>, 'onChange'> {
    name?: string;
    size?: 'l' | 'm' | 's';
    value?: RadioValues;
    checked?: boolean;
    disabled?: boolean;
    invalid?: boolean;
    onChange?: (value: RadioValues) => void;
    className?: string;
    style?: CSSProperties;
    children?: ReactNode;
}
export declare const Radio: ({ name, size, value, checked, disabled, invalid, onChange, className, style, children, ...rest }: RadioProps) => import("react/jsx-runtime").JSX.Element;
