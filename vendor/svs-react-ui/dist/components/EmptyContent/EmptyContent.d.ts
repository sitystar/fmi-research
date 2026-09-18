import './EmptyContent.scss';
import { HTMLAttributes, ReactNode } from 'react';
type EmptyContentIconType = 'folder-open' | 'table' | 'file-magnifying-glass' | 'warning' | 'arrow-circle-down';
export interface EmptyContentProps extends HTMLAttributes<HTMLDivElement> {
    /** Заголовок */
    title: string;
    /** Описание */
    description?: string;
    /**
     * Набор иконок для вывода перед заголовком. Принимает пользовательскую иконку
     * @default 'folder-open'
     */
    icon?: ReactNode | EmptyContentIconType;
    /** Пользовательский контент после описания */
    afterContent?: ReactNode;
}
export declare const EmptyContent: ({ title, description, icon, afterContent, className, ...rest }: EmptyContentProps) => import("react/jsx-runtime").JSX.Element;
export {};
