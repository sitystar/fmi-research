import { CSSProperties, ReactNode } from 'react';
import { GanttCSSVariables, GanttTimelineProps, LayoutTimeTable, TableDimensions } from '../GanttTimeline';
import { createTableRowsMap } from '../../utils/createTableRowsMap';
import { barCoords } from '../../utils/calcBarDimensions';
import { GanttTimelineCustomItem, GanttCustomBarRenderer, GanttProps } from '../../Gantt.types';
export type GanttBarListStylesTypes = {
    barsListStyle: CSSProperties;
    barHeightStyle: CSSProperties;
    labelHeightStyle: CSSProperties;
    tableRowsHeaderHeight: number | null;
};
export interface customBarWithCoords extends GanttTimelineCustomItem, barCoords {
}
export interface BarListProps extends Pick<GanttTimelineProps, 'timelineData'>, Pick<GanttProps, 'onBar'> {
    tableDimensions: TableDimensions;
    layoutTimeTable: LayoutTimeTable;
    showBarCollapseButtons: boolean;
    ganttCSSVariables: GanttCSSVariables;
    customBarRenderer?: (customBarListData: GanttCustomBarRenderer) => ReactNode;
    /**
     * массив строк данных с параметрами
     */
    rowsMap: ReturnType<typeof createTableRowsMap>;
}
export declare const BarList: ({ timelineData, tableDimensions, layoutTimeTable, showBarCollapseButtons, ganttCSSVariables, customBarRenderer, rowsMap, onBar }: BarListProps) => import("react/jsx-runtime").JSX.Element;
