import { RefObject } from 'react';
import { IntervalItem } from '../Gantt.const';
import { createTableRowsMap } from '../utils/createTableRowsMap';
import { TableDimensions } from './GanttTimeline';
interface GanttTimeIntervalListProps {
    interval: IntervalItem;
    firstTimeIntervalRef: RefObject<HTMLDivElement | null>;
    numberOfIntervals: number;
    tableDimensions: TableDimensions;
    rowsMap: ReturnType<typeof createTableRowsMap>;
    striped?: boolean;
}
export declare const TimeIntervalList: ({ interval, firstTimeIntervalRef, numberOfIntervals, tableDimensions, rowsMap, striped }: GanttTimeIntervalListProps) => import("react/jsx-runtime").JSX.Element;
export {};
