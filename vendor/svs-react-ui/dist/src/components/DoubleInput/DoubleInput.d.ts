import { HTMLAttributes } from 'react';
import { InputProps } from '../Input';
import './DoubleInput.scss';
export type DoubleInputValues = {
    valueFrom: string;
    valueTo: string;
};
export interface DoubleInputProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    placeholderFrom?: string;
    placeholderTo?: string;
    initialValues?: Partial<DoubleInputValues>;
    inputFromProps?: InputProps;
    inputToProps?: InputProps;
    onChange?: (values: DoubleInputValues) => void;
    valueFrom?: string;
    valueTo?: string;
}
export declare const DoubleInput: ({ className, placeholderFrom, placeholderTo, inputFromProps, inputToProps, onChange, valueTo, valueFrom, style }: DoubleInputProps) => import("react/jsx-runtime").JSX.Element;
