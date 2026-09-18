import './Progress.scss';
import { HTMLAttributes } from 'react';
export type ProgressStyleType = 'line' | 'circle';
export type ProgressSize = 's' | 'm' | 'l';
export type ProgressStatus = 'default' | 'warning' | 'error' | 'success';
export interface ProgressProps extends HTMLAttributes<HTMLDivElement> {
    progressValue: number;
    styleType?: ProgressStyleType;
    size?: ProgressSize;
    status?: ProgressStatus;
    icon?: boolean;
}
export declare const Progress: ({ progressValue, styleType, size, status, icon, className, ...rest }: ProgressProps) => import("react/jsx-runtime").JSX.Element;
