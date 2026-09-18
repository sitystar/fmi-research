import { HTMLAttributes, Key, ReactNode } from 'react';
import './SideMenu.scss';
export interface SideMenuItemBlock {
    key: Key;
    title: string;
    description: string;
    icon: ReactNode;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте popupContent
     */
    tooltipContent?: ReactNode;
    popupContent?: ReactNode;
    afterContent?: ReactNode;
    afterText?: ReactNode;
    items?: Omit<SideMenuItemBlock, 'items'>[];
}
export interface SideMenuGroup {
    key?: number | string;
    label: string;
    items?: SideMenuItemBlock[];
}
export interface SideMenuProps extends HTMLAttributes<HTMLElement> {
    width?: string | number;
    onItemClick?: (subElement: SideMenuItemBlock) => void;
    data: SideMenuGroup[];
    closeText?: string;
    defaultCollapsed?: boolean;
    showToggle?: boolean;
    defaultOpenKeys?: Key[];
    defaultSelectedKeys?: Key[];
    onToggle?: () => void;
}
export declare const SideMenu: ({ data, className, width, onItemClick, closeText, defaultCollapsed, showToggle, onToggle, defaultSelectedKeys, defaultOpenKeys, style, ...rest }: SideMenuProps) => import("react/jsx-runtime").JSX.Element;
