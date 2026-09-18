import { HTMLAttributes, ReactNode } from 'react';
import './BaseIcon.scss';
interface BaseIconProps extends HTMLAttributes<HTMLSpanElement> {
    children: ReactNode;
    iconName: string;
}
export declare const BaseIcon: import("react").ForwardRefExoticComponent<BaseIconProps & import("react").RefAttributes<HTMLSpanElement>>;
export {};
