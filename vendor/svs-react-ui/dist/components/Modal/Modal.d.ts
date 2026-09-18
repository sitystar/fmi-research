import { CSSProperties, HTMLAttributes, ReactNode } from 'react';
import './Modal.scss';
export type ModalIndicatorStatus = 'warning' | 'success' | 'error' | 'info' | 'extra';
interface BaseModalProps extends Omit<HTMLAttributes<HTMLDivElement>, 'title'> {
    open?: boolean;
    onClose?: () => void;
    needCloseIcon?: boolean;
    centered?: boolean;
    wrapperClassName?: string;
    wrapperStyle?: CSSProperties;
    indicator?: ModalIndicatorStatus;
    title?: ReactNode;
    footer?: ReactNode;
    width?: number | string;
    height?: number | string;
    fullscreenOnMobile?: boolean;
    disableBody?: boolean;
    animation?: {
        disable?: boolean;
    };
    closeOnClickOutside?: boolean;
    destroyOnClose?: boolean;
    afterClose?: () => void;
    /**
     * Режим управления высотой модального окна
     * - true: максимальная высота ограничивается высотой экрана. Контент модального окна начинает прокручиваться.
     * - false: высота определяется содержимым (`max-content`)
     * @default false
     */
    limitedHeight?: boolean;
}
interface ModalPropsWithExtra extends BaseModalProps {
    indicator: 'extra';
    extraIcon: ReactNode;
}
interface ModalPropsWithoutExtra extends BaseModalProps {
    indicator?: Exclude<ModalIndicatorStatus, 'extra'>;
    extraIcon?: never;
}
export type ModalProps = ModalPropsWithExtra | ModalPropsWithoutExtra;
export declare const Modal: ({ open, onClose, needCloseIcon, children, centered, className, wrapperClassName, indicator, extraIcon, title, footer, height, width, disableBody, fullscreenOnMobile, animation, closeOnClickOutside, destroyOnClose, afterClose, limitedHeight, style, wrapperStyle }: ModalProps) => import("react/jsx-runtime").JSX.Element;
export {};
