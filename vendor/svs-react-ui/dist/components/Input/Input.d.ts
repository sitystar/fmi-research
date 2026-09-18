import { CSSProperties, ChangeEvent, FocusEvent, InputHTMLAttributes, MouseEvent, ReactNode } from 'react';
import './Input.scss';
/**
 * @deprecated Вариант subtle будет удален в мажорной версии
 */
type DeprecatedVariant = 'subtle';
export type Variant = 'default' | 'square' | 'none' | DeprecatedVariant;
export type StatusTypes = 'error' | 'success';
export type Mask = 'time' | 'date' | 'dateInterval' | 'phone' | 'HH:mm' | 'HH:mm:ss' | 'month' | 'uuid';
export type InputSize = 'l' | 'm' | 's';
/**
 * @deprecated Тип RegExp будет удален в мажорной версии
 */
type InputMaskRegExp = RegExp;
export interface InputProps extends Omit<InputHTMLAttributes<HTMLInputElement>, 'value' | 'size' | 'onChange' | 'onBlur'> {
    label?: ReactNode;
    variant?: Variant;
    size?: InputSize;
    disabled?: boolean;
    iconBefore?: ReactNode;
    iconAfter?: ReactNode;
    message?: string;
    placeholder?: string;
    value?: string | null;
    onChange?: (e: ChangeEvent<HTMLInputElement>, formattedValue?: string) => void;
    onChanged?: (val: string) => void;
    onEnter?: (val: string) => void;
    onBlur?: (val: string, e: FocusEvent<HTMLInputElement>) => void;
    mask?: Mask | InputMaskRegExp;
    clearable?: boolean;
    onClear?: (e: MouseEvent) => void;
    wrapperClassName?: string;
    wrapperStyle?: CSSProperties;
    children?: ReactNode;
    status?: StatusTypes;
    loading?: boolean;
}
export declare const Input: import("react").ForwardRefExoticComponent<InputProps & import("react").RefAttributes<HTMLInputElement>>;
export {};
