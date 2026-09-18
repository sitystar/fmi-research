import { HTMLAttributes } from 'react';
import { CheckboxSize } from '../Checkbox/Checkbox';
import './CheckboxGroup.scss';
export interface CheckboxGroupProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    value: string[];
    disabled?: boolean;
    size?: CheckboxSize;
    className?: string;
    onChange?: (checkedCheckboxes: string[]) => void;
}
export declare const CheckboxGroup: ({ value, disabled, size, className, onChange, ...rest }: CheckboxGroupProps) => import("react/jsx-runtime").JSX.Element;
