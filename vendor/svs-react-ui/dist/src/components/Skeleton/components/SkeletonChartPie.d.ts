import { SkeletonCommonProps } from '../Skeleton.common';
import { PieChartTypes } from '../../../components/Charts/PieChart';
export interface SkeletonChartPieProps extends SkeletonCommonProps {
    size: string | number;
    innerRadiusScale?: number;
    shape?: PieChartTypes;
}
export declare const SkeletonChartPie: import("react").ForwardRefExoticComponent<SkeletonChartPieProps & import("react").RefAttributes<HTMLDivElement>>;
