import './RadioGroup.scss';
import { HTMLAttributes, ReactNode } from 'react';
import { RadioValues } from './Radio';
export type RadioVariants = 'default' | 'button';
export interface RadioGroupOwnProps {
    name?: string;
    size?: 'l' | 'm' | 's';
    variant?: RadioVariants;
    value?: RadioValues;
    disabled?: boolean;
    invalid?: boolean;
    onChange?: (value: RadioValues) => void;
    children?: ReactNode;
    inline?: boolean;
}
export interface RadioGroupProps extends RadioGroupOwnProps, Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
}
export declare const useRadioGroup: () => RadioGroupOwnProps | undefined;
export declare const RadioGroup: ({ name, size, variant, inline, value, disabled, invalid, onChange, className, children, ...rest }: RadioGroupProps) => import("react/jsx-runtime").JSX.Element;
