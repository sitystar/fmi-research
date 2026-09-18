import { ReactNode } from 'react';
import { IntervalOption } from '../Gantt.const';
import { customBarWithCoords } from './GanttBarList/GanttBarList';
import { GanttTimelineItem, GanttTimelineMilestone, GanttTimelineCustomItem, GanttTimelineProjectItem, GanttTimeScaleRenderer, GanttTimelineHeaderItem, GanttProps } from '../Gantt.types';
export type GanttEventMarker = {
    date: Date;
    content?: ReactNode;
    color?: string;
};
export interface TableDimensions {
    scale: number | null;
    tableRowHeight: number | null;
    tableRowsHeaderHeight: number | null;
    timeIntervalWidth: number | null;
    timeTableWidth: number | null;
}
export interface GanttCSSVariables {
    ganttHeaderHeight: number | null;
    progressHeight: number | null;
    progressHeightChildren: number | null;
    ganttProgressWidth: number | null;
    ganttMilestoneSize: number | null;
    ganttItemsDateHeightMin: number | null;
    scrollbarHeight: number | null;
}
export type GanttTimelineDataType = GanttTimelineItem | GanttTimelineMilestone | GanttTimelineCustomItem | GanttTimelineProjectItem;
export interface GanttTimelineProps extends Pick<GanttProps, 'onBar'> {
    defaultInterval?: IntervalOption;
    intervals?: IntervalOption[];
    timelineData: GanttTimelineDataType[];
    eventMarkers?: GanttEventMarker[];
    isTableVisible: boolean;
    onHandleChangeTableVisibility: () => void;
    ganttWrapperWidth: string | number | undefined;
    showBarCollapseButtons: boolean;
    showTableCollapseButton: boolean;
    showTable?: boolean;
    showTimeline?: boolean;
    timeScaleRenderer?: (args: GanttTimeScaleRenderer) => ReactNode;
    customBarRenderer?: (args: {
        timeline: {
            timelineStart: Date;
            timelineEnd: Date;
            timelineWidth: number;
        };
        customBarsInLineList: customBarWithCoords[];
    }) => ReactNode;
    timelineHeaderCustomContent?: ReactNode;
    timelineHeaderItems?: GanttTimelineHeaderItem[] | null;
    striped?: boolean;
}
export type LayoutTimeTable = {
    start: number;
    end: number;
};
export type ArrowProps = {
    parent: number | string;
    child: number;
    arrowWidth: number;
    arrowHeight: number;
    childChildrenLength: number;
}[];
export declare const GanttTimeline: ({ defaultInterval, intervals: userIntervals, timelineData, eventMarkers, onHandleChangeTableVisibility, isTableVisible, ganttWrapperWidth, showBarCollapseButtons, showTableCollapseButton, showTable, timeScaleRenderer, customBarRenderer, timelineHeaderCustomContent, timelineHeaderItems, showTimeline, striped, onBar }: GanttTimelineProps) => import("react/jsx-runtime").JSX.Element;
