import { GanttTimelineProps, TableDimensions } from '../GanttTimeline';
import { BarListProps, GanttBarListStylesTypes } from '../GanttTimeline/GanttBarList/GanttBarList';
export type GanttArrowMap = {
    [key: string | number]: (string | number)[];
};
interface useArrowProps extends Pick<GanttTimelineProps, 'timelineData'>, Pick<BarListProps, 'rowsMap'>, Pick<TableDimensions, 'scale'> {
    styles: GanttBarListStylesTypes;
}
/** Хук вычисления данных для построения стрелки */
export declare const useArrow: ({ timelineData, rowsMap, scale, styles }: useArrowProps) => {
    createArrowProps: (barId: number | string | undefined, rowId: number, maxEndDate: number, rowIndex: number) => {
        parent: number | string;
        child: number;
        arrowWidth: number;
        arrowHeight: number;
        childChildrenLength: number;
    }[];
};
export {};
