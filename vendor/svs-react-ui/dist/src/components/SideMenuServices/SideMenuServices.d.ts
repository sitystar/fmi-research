import { Dispatch, HTMLAttributes, ReactElement, ReactNode, SetStateAction } from 'react';
import './SideMenuServices.scss';
import { SideMenuServicesItem } from './SideMenuServicesItem';
import { SideMenuServicesFooterData } from './SideMenuServicesFooter';
type SideLevelType = Pick<SideMenuServicesItem, 'items' | 'sideLevelIcon' | 'sideLevelLabel'>;
type SideMenuServicesContextType = {
    sideOpenedItems: SideLevelType[];
    setSideOpenedItems: (newSideOpenedItems: SideLevelType[]) => void;
    itemFullscreenContent: ReactElement | null;
    setItemFullscreenContent: Dispatch<SetStateAction<ReactElement | null>>;
    setIsCollapsed: (v: boolean | ((v: boolean) => boolean)) => void;
};
export declare const SideMenuServicesContext: import("react").Context<SideMenuServicesContextType>;
/**
 * Логотипы для двух состояний бокового меню: развернутое и свернутое
 */
export type SideMenuServicesLogo = {
    /**
     * Логотип в развернутом состоянии
     */
    default: HTMLAttributes<HTMLImageElement> & {
        src: string;
    };
    /**
     * Логотип в свернутом состоянии
     */
    collapsed: HTMLAttributes<HTMLImageElement> & {
        src: string;
    };
};
export interface SideMenuServicesProps extends Omit<HTMLAttributes<HTMLElement>, 'onChange'> {
    /**
     * Отвечает за начальное состояние компонента скрыто/раскрыто
     * @default false
     */
    defaultCollapsed?: boolean;
    /**
     * Объект в который передаются данные о логотипе
     */
    logo?: SideMenuServicesLogo;
    /**
     * Свойство позволяющее передать логотип в произвольном виде
     */
    customLogo?: ReactNode;
    /**
     * Массив пунктов меню
     */
    items?: SideMenuServicesItem[];
    /**
     * Ширина меню в развернутом состоянии (в пикселях)
     * @default 320
     */
    width?: number;
    /**
     * Ширина меню в свернутом состоянии (в пикселях)
     * @default 68
     */
    collapsedWidth?: number;
    /**
     * Данные для отображения футера в меню
     */
    footer?: SideMenuServicesFooterData;
    /**
     * Свойство позволяющее управлять скрываемостью меню
     * @default true
     */
    collapsible?: boolean;
    /**
     * Брейкпоинт (в пикселях), при котором меню переходит в компактный режим
     * @default 1279
     */
    compactViewBreakpoint?: number;
    /**
     * Основной контент страницы, который отображается рядом с меню
     */
    children?: ReactNode;
    /**
     * Событие, отрабатывающее при открытии/закрытии меню
     */
    onChange?: (collapsed: boolean) => void;
    /**
     * Управляет состоянием открытия/закрытия меню
     */
    collapsed?: boolean;
}
export declare const SideMenuServices: import("react").MemoExoticComponent<({ defaultCollapsed, collapsed, logo, customLogo, items, width, collapsedWidth, footer, collapsible, compactViewBreakpoint, className, children, onChange, ...rest }: SideMenuServicesProps) => import("react/jsx-runtime").JSX.Element>;
export {};
