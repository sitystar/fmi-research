import { ReactElement, ReactNode, HTMLAttributes } from 'react';
import './Results.scss';
import { ButtonProps } from '../Button';
interface ResultProps extends HTMLAttributes<HTMLDivElement> {
    icon?: 'info' | 'warning' | 'error' | 'success';
    customIcon?: ReactNode;
    header?: ReactNode;
    text?: ReactNode;
    buttons?: ReactElement<ButtonProps>[];
}
export declare const Results: ({ icon, customIcon, header, text, buttons, className, style, ...rest }: ResultProps) => import("react/jsx-runtime").JSX.Element;
export {};
