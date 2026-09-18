import './Breadcrumbs.scss';
import { AnchorHTMLAttributes, HTMLAttributes, MouseEvent, ReactNode } from 'react';
export interface BreadcrumbItemProps extends Omit<AnchorHTMLAttributes<HTMLAnchorElement>, 'title'> {
    title: ReactNode;
    path?: string;
}
export interface BreadcrumbsProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onClick'> {
    items: BreadcrumbItemProps[];
    onClick?: (e: MouseEvent<HTMLAnchorElement>, item: BreadcrumbItemProps) => void;
}
/**
 * Компонент для отрисовки хлебных крошек
 * */
export declare const Breadcrumbs: ({ items, className, onClick, ...rest }: BreadcrumbsProps) => import("react/jsx-runtime").JSX.Element;
