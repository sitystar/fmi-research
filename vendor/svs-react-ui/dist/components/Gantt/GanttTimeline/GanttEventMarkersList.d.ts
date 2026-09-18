import { GanttEventMarker, LayoutTimeTable } from './GanttTimeline';
interface EventMarkersListListProps {
    eventMarkers: GanttEventMarker[] | undefined;
    scale: number | null;
    layoutTimeTable: LayoutTimeTable;
}
export declare const EventMarkersListList: ({ eventMarkers, layoutTimeTable, scale }: EventMarkersListListProps) => import("react/jsx-runtime").JSX.Element;
export {};
