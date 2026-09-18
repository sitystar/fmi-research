import { HTMLAttributes, ReactNode } from 'react';
import './Drawer.scss';
export interface DrawerProps extends HTMLAttributes<HTMLDivElement> {
    open: boolean;
    onClose?: () => void;
    showCloseIcon?: boolean;
    placement?: 'top' | 'left' | 'right' | 'bottom';
    wrapperClassName?: string;
    title?: string;
    disableBody?: boolean;
    footer?: ReactNode;
    extra?: ReactNode;
    width?: number;
    height?: number;
}
export declare const Drawer: ({ open, onClose, showCloseIcon, children, placement, className, wrapperClassName, title, disableBody, footer, extra, height, width, style, ...rest }: DrawerProps) => import("react/jsx-runtime").JSX.Element;
