import { HTMLAttributes } from 'react';
import './ProgressBar.scss';
export interface ProgressBarProps extends HTMLAttributes<HTMLDivElement> {
    progress: number;
}
export declare const ProgressBar: ({ progress, style, className }: ProgressBarProps) => import("react/jsx-runtime").JSX.Element;
