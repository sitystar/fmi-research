import './Grid.scss';
import { HTMLAttributes } from 'react';
import { RowContextTypes } from './RowContext';
type JustifyTypes = 'start' | 'end' | 'center' | 'space-around' | 'space-between' | 'space-evenly';
type AlignTypes = 'top' | 'middle' | 'bottom' | 'stretch';
export type RowProps = {
    justify?: JustifyTypes;
    align?: AlignTypes;
} & RowContextTypes;
export declare const Row: import("react").ForwardRefExoticComponent<HTMLAttributes<HTMLDivElement> & {
    justify?: JustifyTypes;
    align?: AlignTypes;
} & RowContextTypes & import("react").RefAttributes<HTMLDivElement>>;
export {};
