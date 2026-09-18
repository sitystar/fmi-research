import { ButtonHTMLAttributes, ReactNode } from 'react';
import { TagSize } from './Tag.common';
export interface StatusTagProps extends ButtonHTMLAttributes<HTMLButtonElement> {
    children?: ReactNode;
    status?: 'default' | 'error' | 'warning' | 'success' | 'edited';
    icon?: ReactNode;
    rounded?: boolean;
    className?: string;
    size?: TagSize;
}
/**
 * @deprecated
 * Будет удален в следующей мажорной версии. Используйте компонент Tag.StatusTag
 */
export declare const StatusTag: ({ children, icon, rounded, status, className, size, ...rest }: StatusTagProps) => import("react/jsx-runtime").JSX.Element;
