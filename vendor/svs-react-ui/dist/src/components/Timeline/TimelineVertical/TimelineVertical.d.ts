import { HTMLAttributes, ReactNode } from 'react';
import './TimelineVertical.scss';
export type TimelineVerticalStatus = {
    statusTitle?: string;
    date?: string;
    time?: string;
    icon?: ReactNode;
    statusIsCompleted?: boolean;
};
export interface TimelineVerticalProps extends HTMLAttributes<HTMLDivElement> {
    statuses: TimelineVerticalStatus[];
    colorProgress?: string;
    width?: number | string;
}
export declare const TimelineVertical: ({ statuses, colorProgress, className, width, style, ...rest }: TimelineVerticalProps) => import("react/jsx-runtime").JSX.Element;
