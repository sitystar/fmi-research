import { HTMLAttributes } from 'react';
import './Steps.scss';
export interface StepsProps extends HTMLAttributes<HTMLDivElement> {
    itemsCount: number;
    currentItem: number;
    onStepClick: (stepIndex: number) => void;
}
export declare const Steps: import("react").MemoExoticComponent<({ itemsCount, currentItem, onStepClick, className, ...rest }: StepsProps) => import("react/jsx-runtime").JSX.Element>;
