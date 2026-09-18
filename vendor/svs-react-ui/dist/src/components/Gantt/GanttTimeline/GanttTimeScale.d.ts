import { ReactNode, RefObject } from 'react';
import { IntervalItem } from '../Gantt.const';
import { GanttTimeScaleRenderer } from '../Gantt.types';
import { GanttCSSVariables, LayoutTimeTable, TableDimensions } from './GanttTimeline';
interface TimeScaleProps {
    timeScaleRef: RefObject<HTMLDivElement | null>;
    interval: IntervalItem;
    tableDimensions: TableDimensions;
    ganttCSSVariables: GanttCSSVariables;
    numberOfIntervals: number;
    centralInterval: number;
    intervalDurationMs: number;
    layoutTimeTable: LayoutTimeTable;
    timeScaleRenderer?: (args: GanttTimeScaleRenderer) => ReactNode;
    showTable?: boolean;
    isTableVisible: boolean;
    onHandleChangeTableVisibility: () => void;
    showTableCollapseButton: boolean;
    hasScrollPadding: boolean;
}
export declare const TimeScale: ({ timeScaleRef, tableDimensions, ganttCSSVariables, interval, numberOfIntervals, centralInterval, intervalDurationMs, layoutTimeTable, timeScaleRenderer, showTable, isTableVisible, onHandleChangeTableVisibility, showTableCollapseButton, hasScrollPadding }: TimeScaleProps) => import("react/jsx-runtime").JSX.Element;
export {};
