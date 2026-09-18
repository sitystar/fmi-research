import { ReactNode } from 'react';
import { GanttProps, GanttTimelineMilestone } from '~/components/Gantt';
interface MileStoneProps extends Pick<GanttProps, 'onBar'> {
    size: number;
    left: number;
    beforeBarContent?: ReactNode;
    afterBarContent?: ReactNode;
    bar: GanttTimelineMilestone;
    barIndex: number;
}
export declare const MileStone: ({ left, size, beforeBarContent, afterBarContent, onBar, bar, barIndex }: MileStoneProps) => import("react/jsx-runtime").JSX.Element;
export {};
