import { SkeletonCommonProps } from '../Skeleton.common';
export interface SkeletonAvatarProps extends SkeletonCommonProps {
    size?: 'l' | 'm' | 's';
}
export declare const SkeletonAvatar: import("react").ForwardRefExoticComponent<SkeletonAvatarProps & import("react").RefAttributes<HTMLDivElement>>;
