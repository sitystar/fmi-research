import { HTMLAttributes, ReactNode, MouseEvent } from 'react';
import './HeaderEcom.scss';
import { DropdownItemType } from '../../Dropdown/DropdownItem';
import { ProfileProps } from '../Profile/Profile';
import { PopupProps } from '../../Popup';
type LogoConfig = {
    icon: ReactNode;
    href?: string;
    onClick?: (event: MouseEvent<HTMLAnchorElement>, link?: string) => void;
};
export interface HeaderEcomProps extends HTMLAttributes<HTMLDivElement> {
    isCatalogModalOpen?: boolean;
    onCatalogModalOpenChange?: () => void;
    bannerContent?: {
        icon?: ReactNode;
        text: string;
    };
    onBannerClick?: (event?: MouseEvent<HTMLDivElement>) => void;
    currentLocation?: string;
    locationOptions?: DropdownItemType[];
    onLocationChange?: (val: DropdownItemType) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте links
     */
    forUsersLink?: string;
    needThemeSwitch?: boolean;
    needCatalogModal?: boolean;
    isDarkTheme?: boolean;
    onThemeChange?: (isDark: boolean) => void;
    profile?: Pick<ProfileProps, 'fio' | 'email' | 'photoSrc' | 'profileStatus'>;
    onProfileClick?: (e: MouseEvent) => void;
    onSignInClick?: () => void;
    cartCount?: number;
    notificationCount?: number;
    needFavorite?: boolean;
    needCart?: boolean;
    needNotifications?: boolean;
    onCatalogClick?: () => void;
    onBellClick?: () => void;
    onFavoriteClick?: () => void;
    onCartClick?: () => void;
    onShareClick?: () => void;
    onBackClick?: () => void;
    onHomeClick?: () => void;
    inputValue?: string;
    onInputChange?: (val: string) => void;
    onInputEnterPress?: (val: string) => void;
    catalogContent?: ReactNode;
    mobileTabbarClassName?: string;
    onInputSubmit?: () => void;
    locationPopupContent?: ReactNode;
    isLocationPopupOpen?: boolean;
    onLocationPopupOpenChange?: PopupProps['onVisibleChange'];
    wrapperClassName?: string;
    isInputClearable?: boolean;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте links
     */
    auctionsLink?: string;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте links
     */
    juridicalInfoLink?: string;
    logo?: ReactNode | LogoConfig;
    logoDescription?: ReactNode | LogoConfig;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте links
     */
    contactsLink?: string;
    cart?: {
        href?: string;
        onClick?: (event: MouseEvent<HTMLAnchorElement>, link?: string) => void;
    };
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте logo.onClick
     */
    onLogoClick?: (event?: MouseEvent<HTMLDivElement | HTMLAnchorElement>) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте logoDescription.onClick
     */
    onDescriptionLogoClick?: (event?: MouseEvent<HTMLDivElement>) => void;
    links?: {
        label: string;
        href: string;
        bold?: boolean;
        icon?: ReactNode;
    }[];
}
export declare const HeaderEcom: ({ isCatalogModalOpen, onCatalogModalOpenChange, className, bannerContent, onBannerClick, currentLocation, locationOptions, onLocationChange, forUsersLink, needThemeSwitch, needCatalogModal, isDarkTheme, onThemeChange, onSignInClick, onProfileClick, profile, cartCount, notificationCount, needFavorite, needCart, needNotifications, onCatalogClick, onBellClick, onFavoriteClick, onCartClick, onShareClick, onBackClick, onHomeClick, inputValue, onInputChange, onInputEnterPress, catalogContent, mobileTabbarClassName, onInputSubmit, locationPopupContent, isLocationPopupOpen, onLocationPopupOpenChange, wrapperClassName, isInputClearable, auctionsLink, juridicalInfoLink, logoDescription, logo, cart, links, contactsLink, onLogoClick, onDescriptionLogoClick, ...rest }: HeaderEcomProps) => import("react/jsx-runtime").JSX.Element;
export {};
