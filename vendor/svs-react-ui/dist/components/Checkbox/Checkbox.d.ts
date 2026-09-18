import { CSSProperties, ReactNode, HTMLAttributes } from 'react';
import './Checkbox.scss';
/**
 * @deprecated
 * Размер xl будет удален в мажорной версии
 */
export type CheckboxSize = 'xl' | 'l' | 'm' | 's';
export interface CheckboxProps extends Omit<HTMLAttributes<HTMLInputElement>, 'onChange'> {
    name?: string;
    checked?: boolean;
    indeterminate?: boolean;
    size?: CheckboxSize;
    disabled?: boolean;
    invalid?: boolean;
    onChange?: (value: boolean) => void;
    className?: string;
    style?: CSSProperties;
    children?: ReactNode;
}
export declare const Checkbox: ({ name, checked, indeterminate, size, disabled, invalid, onChange, className, style, children, tabIndex, ...rest }: CheckboxProps) => import("react/jsx-runtime").JSX.Element;
