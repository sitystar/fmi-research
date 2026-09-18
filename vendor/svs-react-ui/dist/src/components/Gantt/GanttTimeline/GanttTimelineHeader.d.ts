import { CSSProperties, ReactNode } from 'react';
import { DropdownItemType } from '../../../components/Dropdown';
import { GanttTimelineHeaderItem } from '~/components/Gantt';
interface GanttTimelineHeaderProps {
    intervalItems: DropdownItemType[];
    selectedValue: DropdownItemType;
    style?: CSSProperties;
    onHandleIntervalSelect: (interval: DropdownItemType | DropdownItemType[]) => void;
    onHandleMoveTimetable: any;
    timelineHeaderCustomContent?: ReactNode;
    timelineHeaderItems?: GanttTimelineHeaderItem[] | null;
}
export declare const GanttTimelineHeader: ({ intervalItems, selectedValue, style, onHandleIntervalSelect, onHandleMoveTimetable, timelineHeaderCustomContent, timelineHeaderItems }: GanttTimelineHeaderProps) => import("react/jsx-runtime").JSX.Element;
export {};
