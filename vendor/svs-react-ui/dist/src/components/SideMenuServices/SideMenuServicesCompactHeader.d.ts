import { ReactNode } from 'react';
import { SideMenuServicesLogo } from './SideMenuServices';
type SideMenuServicesCompactHeaderProps = {
    sideMenuClassName: string;
    logo?: SideMenuServicesLogo;
    customLogo?: ReactNode;
    isCompactMenuOpened: boolean;
    closeCompactMenu: () => void;
};
export declare const SideMenuServicesCompactHeader: import("react").ForwardRefExoticComponent<SideMenuServicesCompactHeaderProps & import("react").RefAttributes<HTMLDivElement>>;
export {};
