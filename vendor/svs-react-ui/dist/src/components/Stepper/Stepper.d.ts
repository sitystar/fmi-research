import { HTMLAttributes } from 'react';
import './Stepper.scss';
export interface StepperProps extends HTMLAttributes<HTMLDivElement> {
    value?: number;
    minDisable?: boolean;
    maxDisable?: boolean;
    disabled?: boolean;
    onMinusClick?: () => void;
    onPlusClick?: () => void;
    onEdit?: (value: string) => void;
    size?: 'l' | 'm' | 's';
}
export declare const Stepper: ({ value, minDisable, maxDisable, disabled, className, onMinusClick, onPlusClick, onEdit, size, ...rest }: StepperProps) => import("react/jsx-runtime").JSX.Element;
