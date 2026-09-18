import { HTMLAttributes, ReactNode } from 'react';
import './Typography.scss';
type TypographyWeightType = 'regular' | 'semibold' | 'bold' | number;
export type TypographyStyleType = 'extra-display' | 'display' | 'large-title' | 'title-1' | 'title-2' | 'title-3' | 'subtitle-1' | 'subtitle-2' | 'subtitle-3' | 'body-1' | 'body-2' | 'caption-1' | 'caption-2';
export interface TypographyProps extends HTMLAttributes<HTMLSpanElement> {
    children: ReactNode;
    color?: string;
    styleType?: TypographyStyleType;
    weight?: TypographyWeightType;
    underline?: boolean;
    crossed?: boolean;
    italic?: boolean;
    copyable?: boolean;
    ellipsis?: boolean;
}
export declare const Typography: import("react").ForwardRefExoticComponent<TypographyProps & import("react").RefAttributes<HTMLElement>>;
export {};
