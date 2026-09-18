import { CSSProperties, ReactNode, HTMLAttributes } from 'react';
import './Tooltip.scss';
import { PopoverPlacementType } from '../Popover';
export interface TooltipProps extends Omit<HTMLAttributes<HTMLDivElement>, 'content'> {
    visible?: boolean;
    placement?: PopoverPlacementType;
    fixedWidth?: boolean;
    title?: string;
    content?: string;
    corner?: boolean;
    children: ReactNode;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте className
     */
    tooltipClassName?: string;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте style
     */
    tooltipStyle?: CSSProperties;
    autoPosition?: boolean;
    disabled?: boolean;
    onVisibleChange?: (value: boolean) => void;
    appendToBody?: boolean;
    /**
     * Задержка скрытия всплывающего элемента
     * после того как курсор мыши покидает область наведения.
     *
     * Указывается в **секундах**.
     *
     * @default 0.5
     */
    mouseLeaveDelay?: number;
}
export declare const Tooltip: import("react").ForwardRefExoticComponent<TooltipProps & import("react").RefAttributes<HTMLDivElement>>;
