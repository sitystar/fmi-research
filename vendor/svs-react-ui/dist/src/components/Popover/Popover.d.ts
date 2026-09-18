import { ReactNode, CSSProperties, MouseEvent, HTMLAttributes } from 'react';
import './Popover.scss';
export declare const POPOVER_DEFAULT_MOUSELEAVE_DELAY = 0.5;
export type PopoverRef = {
    close: () => void;
};
export type PopoverPlacementType = 'top-left' | 'top-right' | 'top' | 'bottom-left' | 'bottom-right' | 'bottom' | 'right-bottom' | 'right-top' | 'right' | 'left-bottom' | 'left-top' | 'left';
export type popoverParent = 'dropdown' | 'tooltip' | 'popup' | 'date-picker' | 'time-picker';
type PopoverTriggerTypes = 'hover' | 'click' | 'focus';
export type PopoverOnVisibleChangeTriggerTypes = PopoverTriggerTypes | 'clickOutside';
export type PopoverProps = Pick<HTMLAttributes<HTMLDivElement>, 'onMouseEnter' | 'onMouseLeave'> & {
    visible?: boolean;
    trigger?: PopoverTriggerTypes;
    position: PopoverPlacementType;
    content: ReactNode;
    children?: ReactNode;
    className?: string;
    popoverStyle?: CSSProperties;
    disabled?: boolean;
    closeOnClickInside?: boolean;
    closeOnClickOutside?: boolean;
    onVisibleChange?: (value: boolean, trigger: PopoverOnVisibleChangeTriggerTypes) => void;
    onPositionChange?: (position: PopoverPlacementType) => void;
    autoPosition?: boolean;
    animationDuration?: number;
    offset?: number;
    appendToBody?: boolean;
    width?: string | number;
    height?: number;
    triggerClassName?: string;
    triggerStyle?: CSSProperties;
    parent?: popoverParent;
    /**
     * Свойство позволяющее отключить повторные вычисления положения всплывающего контента
     */
    preventPositionUpdate?: boolean;
    onContentMouseEnter?: (event: MouseEvent<HTMLDivElement>) => void;
    onContentMouseLeave?: (event: MouseEvent<HTMLDivElement>) => void;
    /**
     * Задержка скрытия всплывающего элемента
     * после того как курсор мыши покидает область наведения.
     *
     * Работает только в случае `trigger = 'hover'`
     *
     * Указывается в **секундах**.
     *
     * @default 0.5
     */
    mouseLeaveDelay?: number;
};
export declare const Popover: import("react").ForwardRefExoticComponent<Pick<HTMLAttributes<HTMLDivElement>, "onMouseEnter" | "onMouseLeave"> & {
    visible?: boolean;
    trigger?: PopoverTriggerTypes;
    position: PopoverPlacementType;
    content: ReactNode;
    children?: ReactNode;
    className?: string;
    popoverStyle?: CSSProperties;
    disabled?: boolean;
    closeOnClickInside?: boolean;
    closeOnClickOutside?: boolean;
    onVisibleChange?: (value: boolean, trigger: PopoverOnVisibleChangeTriggerTypes) => void;
    onPositionChange?: (position: PopoverPlacementType) => void;
    autoPosition?: boolean;
    animationDuration?: number;
    offset?: number;
    appendToBody?: boolean;
    width?: string | number;
    height?: number;
    triggerClassName?: string;
    triggerStyle?: CSSProperties;
    parent?: popoverParent;
    /**
     * Свойство позволяющее отключить повторные вычисления положения всплывающего контента
     */
    preventPositionUpdate?: boolean;
    onContentMouseEnter?: (event: MouseEvent<HTMLDivElement>) => void;
    onContentMouseLeave?: (event: MouseEvent<HTMLDivElement>) => void;
    /**
     * Задержка скрытия всплывающего элемента
     * после того как курсор мыши покидает область наведения.
     *
     * Работает только в случае `trigger = 'hover'`
     *
     * Указывается в **секундах**.
     *
     * @default 0.5
     */
    mouseLeaveDelay?: number;
} & import("react").RefAttributes<PopoverRef>>;
export {};
