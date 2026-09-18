import { MouseEvent, HTMLAttributes } from 'react';
import './Carousel.scss';
export type Item = {
    image: string;
    title?: string[];
    subtitle?: string;
    buttonText?: string;
    onClick: (event: MouseEvent, item: Item) => void;
    link?: string;
};
export interface CarouselProps extends HTMLAttributes<HTMLDivElement> {
    infinite: boolean;
    items: Item[];
    backgroundSize: 'contain' | 'cover';
    transitionDuration: number;
}
export declare const CAROUSEL_CLASS_NAME = "svs-carousel";
export declare const Carousel: ({ infinite, items, backgroundSize, transitionDuration, className, ...rest }: CarouselProps) => import("react/jsx-runtime").JSX.Element;
