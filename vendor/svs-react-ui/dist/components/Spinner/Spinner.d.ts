import { ReactNode, CSSProperties } from 'react';
import './Spinner.scss';
type SpinnerSize = 's' | 'm' | 'l' | 'xl' | '2xl';
type SpinnerMode = 'none' | 'text' | 'icon';
type SpinnerState = 'default' | 'success' | 'danger';
export interface SpinnerProps {
    text?: string;
    state: SpinnerState;
    size: SpinnerSize;
    mode: SpinnerMode;
    icon?: ReactNode;
    style?: CSSProperties;
    className?: string;
}
export declare const Spinner: ({ text, size, mode, icon, state, className, style }: SpinnerProps) => import("react/jsx-runtime").JSX.Element;
export {};
