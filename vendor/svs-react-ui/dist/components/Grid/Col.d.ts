import './Grid.scss';
import { HTMLAttributes } from 'react';
type SpanType = number | 'auto';
export type ColProps = HTMLAttributes<HTMLDivElement> & {
    span?: SpanType;
    xs?: SpanType;
    sm?: SpanType;
    md?: SpanType;
    lg?: SpanType;
    offset?: number;
};
export declare const Col: import("react").ForwardRefExoticComponent<HTMLAttributes<HTMLDivElement> & {
    span?: SpanType;
    xs?: SpanType;
    sm?: SpanType;
    md?: SpanType;
    lg?: SpanType;
    offset?: number;
} & import("react").RefAttributes<HTMLDivElement>>;
export {};
