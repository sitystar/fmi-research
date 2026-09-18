import { SkeletonCommonProps } from '../Skeleton.common';
export interface SkeletonChartBarsProps extends SkeletonCommonProps {
    width?: number | string;
    height?: number | string;
    barsHeightRatio?: number[];
    gapToWidthRatio?: number;
}
export declare const SkeletonChartBars: import("react").ForwardRefExoticComponent<SkeletonChartBarsProps & import("react").RefAttributes<HTMLDivElement>>;
