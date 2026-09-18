import { ReactElement, ReactNode, MouseEvent } from 'react';
import './SideMenuServicesItem.scss';
export interface SideMenuServicesClickedItem extends Pick<SideMenuServicesItem, 'type' | 'content' | 'href'> {
}
export interface SideMenuServicesItemProps {
    type?: 'item' | 'group' | 'custom';
    content: ReactNode;
    collapsedCustomContent?: ReactNode;
    icon?: ReactNode;
    active?: boolean;
    href?: string;
    target?: '_self' | '_blank';
    onClick?: (e: MouseEvent, item: SideMenuServicesClickedItem) => void;
    opened?: boolean;
    sideLevelIcon?: ReactNode;
    sideLevelLabel?: ReactNode;
    items?: SideMenuServicesItemProps[];
    fullscreenContent?: ReactElement;
    openingStrategy?: 'default' | 'side';
    indent: number;
    drawIndent: boolean;
    collapsed: boolean;
}
export interface SideMenuServicesItem extends Omit<SideMenuServicesItemProps, 'items' | 'indent' | 'drawIndent' | 'collapsed'> {
    items?: SideMenuServicesItem[];
}
export declare const SideMenuServicesItemComponent: import("react").ForwardRefExoticComponent<SideMenuServicesItemProps & import("react").RefAttributes<HTMLAnchorElement>>;
