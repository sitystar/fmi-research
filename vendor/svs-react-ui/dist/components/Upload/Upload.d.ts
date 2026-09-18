import { InputHTMLAttributes, CSSProperties, ReactNode } from 'react';
import './Upload.scss';
export type UploaderSize = 'l' | 'm' | 's';
export type UploaderStyleType = 'primary' | 'attention';
export interface UploaderProps extends InputHTMLAttributes<HTMLInputElement> {
    uploaderSize?: UploaderSize;
    styleType?: UploaderStyleType;
    disabled?: boolean;
    isLoading?: boolean;
    isSelected?: boolean;
    loaderIcon?: ReactNode;
    icon?: ReactNode;
    style?: CSSProperties;
    children?: ReactNode;
}
export declare const Upload: ({ uploaderSize, styleType, disabled, isLoading, isSelected, style, className, loaderIcon, icon, children, width, ...rest }: UploaderProps) => import("react/jsx-runtime").JSX.Element;
