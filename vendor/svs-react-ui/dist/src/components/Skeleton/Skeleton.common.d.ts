import { HTMLAttributes, JSX } from 'react';
export interface SkeletonCommonProps extends HTMLAttributes<HTMLDivElement> {
    active?: boolean;
    loading?: boolean;
    children?: JSX.Element | JSX.Element[];
}
export declare const skeletonCommonClass: (active: boolean, vertical?: boolean) => string;
