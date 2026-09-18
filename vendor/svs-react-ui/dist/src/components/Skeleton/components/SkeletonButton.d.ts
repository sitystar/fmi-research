import { ButtonSize } from '../../Button';
import { SkeletonCommonProps } from '../Skeleton.common';
export declare enum SkeletonButtonShapes {
    DEFAULT = "default",
    CIRCLE = "circle"
}
export interface SkeletonButtonProps extends SkeletonCommonProps {
    size?: ButtonSize;
    shape?: SkeletonButtonShapes;
    block?: boolean;
}
export declare const SkeletonButton: import("react").ForwardRefExoticComponent<SkeletonButtonProps & import("react").RefAttributes<HTMLDivElement>>;
