import { CSSProperties, ReactNode, ComponentType, HTMLAttributes } from 'react';
import { AnyObject } from '../../constantsAndTypes';
import './Flex.scss';
import { FlexGapSizes } from './enums';
type CustomComponent<P = AnyObject> = ComponentType<P> | string;
export interface FlexProps<P = AnyObject> extends HTMLAttributes<HTMLElement> {
    vertical?: boolean;
    wrap?: boolean | CSSProperties['flexWrap'];
    justify?: CSSProperties['justifyContent'];
    align?: CSSProperties['alignItems'];
    alignContent?: CSSProperties['alignContent'];
    flex?: CSSProperties['flex'];
    gap?: CSSProperties['gap'] | FlexGapSizes;
    children?: ReactNode;
    component?: CustomComponent<P>;
}
export declare const Flex: import("react").ForwardRefExoticComponent<FlexProps<AnyObject> & import("react").RefAttributes<HTMLDivElement>>;
export {};
