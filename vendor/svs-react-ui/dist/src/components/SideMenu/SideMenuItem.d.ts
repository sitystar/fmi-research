import { Key } from 'react';
import { SideMenuItemBlock } from '.';
import './SideMenuItem.scss';
export interface SideMenuItemProps {
    subElement: SideMenuItemBlock;
    isSidebarOpen?: boolean;
    onItemActive: (key: Key) => void;
    onOpenSidebar?: () => void;
    isOpen?: boolean;
    isInner?: boolean;
    isCompact: boolean;
    onDropdownOpen?: () => void;
    activeKeys: Key | Key[];
    onItemClick: (subElement: SideMenuItemBlock) => void;
}
export declare const SideMenuItem: ({ subElement, isSidebarOpen, onItemActive, onOpenSidebar, isOpen, isCompact, activeKeys, isInner, onDropdownOpen, onItemClick }: SideMenuItemProps) => import("react/jsx-runtime").JSX.Element;
