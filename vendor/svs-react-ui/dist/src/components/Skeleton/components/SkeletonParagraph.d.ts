import { SkeletonCommonProps } from '../Skeleton.common';
export interface SkeletonParagraphProps extends SkeletonCommonProps {
    rows?: number;
    width?: number | string;
}
export declare const SkeletonParagraph: import("react").ForwardRefExoticComponent<SkeletonParagraphProps & import("react").RefAttributes<HTMLDivElement>>;
