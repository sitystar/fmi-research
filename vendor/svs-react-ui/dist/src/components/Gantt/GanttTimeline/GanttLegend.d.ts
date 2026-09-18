import { RefObject } from 'react';
import { GanttTimeLineSettings } from '../Gantt.types';
interface GanttLegendProps {
    timelineSettings: GanttTimeLineSettings;
    timelineRef: RefObject<HTMLDivElement | null>;
}
export declare const GanttLegend: ({ timelineSettings, timelineRef }: GanttLegendProps) => import("react/jsx-runtime").JSX.Element;
export {};
