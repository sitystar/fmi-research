import { SkeletonCommonProps } from '../Skeleton.common';
export interface SkeletonImageProps extends SkeletonCommonProps {
    width?: number | string;
    height?: number | string;
}
export declare const SkeletonImage: import("react").ForwardRefExoticComponent<SkeletonImageProps & import("react").RefAttributes<HTMLDivElement>>;
