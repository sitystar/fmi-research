import { FC, HTMLAttributes, MouseEvent, ReactNode } from 'react';
import './CardImage.scss';
interface CardImageProps extends HTMLAttributes<HTMLDivElement> {
    imageElement?: ReactNode | FC;
    images: string[];
    onTitleClick?: (event?: MouseEvent<HTMLDivElement>) => void;
    discount?: number;
    wrapperClassName?: string;
    stepsClassName?: string;
}
export declare const CardImage: ({ className, images, imageElement, discount, onTitleClick, wrapperClassName, stepsClassName }: CardImageProps) => import("react/jsx-runtime").JSX.Element;
export {};
