import { ReactNode, MouseEvent } from 'react';
type SettingsItem = {
    content: ReactNode;
    onClick?: (e: MouseEvent) => void;
    closeOnClick?: boolean;
};
export type SideMenuServicesFooterData = {
    user?: {
        photoURL?: string;
        name?: string;
        onClick?: (e: MouseEvent) => void;
    };
    buttons?: {
        settings?: {
            onClick?: (e: MouseEvent) => void;
            items?: SettingsItem[];
        };
        notifications?: {
            onClick?: (e: MouseEvent) => void;
        };
    };
};
export interface SideMenuServicesFooterProps {
    sideMenuClassName: string;
    collapsed: boolean;
    data: SideMenuServicesFooterData;
    isCompact: boolean;
}
export declare const SideMenuServicesFooter: import("react").ForwardRefExoticComponent<SideMenuServicesFooterProps & import("react").RefAttributes<HTMLDivElement>>;
export {};
