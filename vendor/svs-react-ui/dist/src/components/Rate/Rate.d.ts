import { HTMLAttributes } from 'react';
import './Rate.scss';
export interface RateProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    size?: number;
    onChange?: (rate: number) => void;
}
export declare const Rate: ({ className, size, onChange, ...rest }: RateProps) => import("react/jsx-runtime").JSX.Element;
