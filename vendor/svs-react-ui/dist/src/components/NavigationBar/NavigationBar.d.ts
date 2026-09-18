import { ReactNode } from 'react';
import { BreadcrumbsProps } from '../Breadcrumbs';
import './NavigationBar.scss';
export interface NavigationBarProps extends BreadcrumbsProps {
    rightContent?: ReactNode;
}
export declare const NavigationBar: ({ items, onClick, rightContent, className, style, ...rest }: NavigationBarProps) => import("react/jsx-runtime").JSX.Element;
