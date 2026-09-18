import { ForwardRefExoticComponent, RefAttributes } from 'react';
import { SkeletonAvatarProps } from './components/SkeletonAvatar';
import { SkeletonButtonProps } from './components/SkeletonButton';
import { SkeletonChartBarsProps } from './components/SkeletonChartBars';
import { SkeletonChartPieProps } from './components/SkeletonChartPie';
import { SkeletonHeadingProps } from './components/SkeletonHeading';
import { SkeletonImageProps } from './components/SkeletonImage';
import { SkeletonInputProps } from './components/SkeletonInput';
import { SkeletonParagraphProps } from './components/SkeletonParagraph';
import { SkeletonCommonProps } from './Skeleton.common';
import './Skeleton.scss';
interface SkeletonProps extends SkeletonCommonProps {
    avatar?: boolean | SkeletonAvatarProps;
    paragraph?: boolean | SkeletonParagraphProps;
    heading?: boolean | SkeletonHeadingProps;
}
interface CompoundedComponent extends ForwardRefExoticComponent<SkeletonProps & RefAttributes<HTMLDivElement>> {
    Avatar: ForwardRefExoticComponent<SkeletonAvatarProps & RefAttributes<HTMLDivElement>>;
    Button: ForwardRefExoticComponent<SkeletonButtonProps & RefAttributes<HTMLDivElement>>;
    ChartPie: ForwardRefExoticComponent<SkeletonChartPieProps & RefAttributes<HTMLDivElement>>;
    ChartBars: ForwardRefExoticComponent<SkeletonChartBarsProps & RefAttributes<HTMLDivElement>>;
    Paragraph: ForwardRefExoticComponent<SkeletonParagraphProps & RefAttributes<HTMLDivElement>>;
    Heading: ForwardRefExoticComponent<SkeletonHeadingProps & RefAttributes<HTMLDivElement>>;
    Input: ForwardRefExoticComponent<SkeletonInputProps & RefAttributes<HTMLDivElement>>;
    Image: ForwardRefExoticComponent<SkeletonImageProps & RefAttributes<HTMLDivElement>>;
}
export declare const Skeleton: CompoundedComponent;
export {};
