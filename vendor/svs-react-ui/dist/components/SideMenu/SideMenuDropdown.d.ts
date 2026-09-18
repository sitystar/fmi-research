import { Key } from 'react';
import { SideMenuItemBlock } from '.';
import './SideMenu.scss';
export interface SideMenuDropdownProps {
    subElement: SideMenuItemBlock;
    activeKeys: Key[];
    openKeys?: Key[];
    isCompact: boolean;
    isSidebarOpen: boolean;
    onItemActive: (key: Key) => void;
    onOpenSidebar: () => void;
    onItemClick: (subElement: SideMenuItemBlock) => void;
}
export declare const SideMenuDropdown: ({ subElement, activeKeys, openKeys, isCompact, isSidebarOpen, onItemActive, onOpenSidebar, onItemClick }: SideMenuDropdownProps) => import("react/jsx-runtime").JSX.Element;
