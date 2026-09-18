import { HTMLAttributes, ReactNode } from 'react';
import './TimelineHorizontal.scss';
export type TimelineHorizontalStatus = {
    statusTitle: string;
    icon: ReactNode;
    statusIsCompleted?: boolean;
};
export interface TimelineHorizontalProps extends HTMLAttributes<HTMLDivElement> {
    statuses: TimelineHorizontalStatus[];
    colorProgress?: string;
    width?: number | string;
}
export declare const TimelineHorizontal: ({ statuses, colorProgress, className, width, style, ...rest }: TimelineHorizontalProps) => import("react/jsx-runtime").JSX.Element;
