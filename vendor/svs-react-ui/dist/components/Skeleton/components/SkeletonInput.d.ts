import { SkeletonCommonProps } from '../Skeleton.common';
export interface SkeletonInputProps extends SkeletonCommonProps {
    size?: 'l' | 'm' | 's';
    block?: boolean;
}
export declare const SkeletonInput: import("react").ForwardRefExoticComponent<SkeletonInputProps & import("react").RefAttributes<HTMLDivElement>>;
