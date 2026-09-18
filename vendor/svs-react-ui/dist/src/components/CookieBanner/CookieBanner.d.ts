import { HTMLAttributes, ReactNode, MouseEvent } from 'react';
import { ButtonProps } from '../Button';
import './CookieBanner.scss';
export interface CookieProps extends HTMLAttributes<HTMLDivElement> {
    text?: ReactNode;
    buttonText?: string;
    beforeButtonContent?: ButtonProps['beforeContent'];
    afterButtonContent?: ButtonProps['afterContent'];
    onAgreeClick?: (e?: MouseEvent<HTMLButtonElement>) => void;
}
export declare const CookieBanner: ({ text, buttonText, onAgreeClick, afterButtonContent, beforeButtonContent, className, ...rest }: CookieProps) => import("react/jsx-runtime").JSX.Element;
