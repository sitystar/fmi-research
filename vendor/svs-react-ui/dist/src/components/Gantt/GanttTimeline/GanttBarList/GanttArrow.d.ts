import { CSSProperties } from 'react';
import { GanttCSSVariables } from '../GanttTimeline';
interface GanttArrowProps {
    width: number;
    height: number;
    childrenLength: number;
    childChildrenLength: number;
    barStyle: CSSProperties | undefined;
    ganttCSSVariables: GanttCSSVariables;
    customBar?: boolean;
}
export declare const GanttArrow: ({ width, height, childrenLength, childChildrenLength, barStyle, ganttCSSVariables, customBar }: GanttArrowProps) => import("react/jsx-runtime").JSX.Element | null;
export {};
