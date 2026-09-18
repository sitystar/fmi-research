import { HTMLAttributes } from 'react';
import './Slider.scss';
import { InputProps } from '../Input';
export type TSliderValues = {
    minValue: string;
    maxValue: string;
};
export type TSliderOnChangeDataValues = {
    minRangeValue: string;
    maxRangeValue: string;
    minInputValue?: string;
    maxInputValue?: string;
};
export interface SliderProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    onChange?: (values: TSliderOnChangeDataValues) => void;
    minValue: string;
    maxValue: string;
    currentInputMinValue?: string;
    currentInputMaxValue?: string;
    currentSliderMinValue?: string;
    currentSliderMaxValue?: string;
    needInput?: boolean;
    inputFromProps?: Omit<InputProps, 'min' | 'type'>;
    inputToProps?: Omit<InputProps, 'max' | 'type'>;
}
export declare const Slider: ({ className, onChange, maxValue, minValue, needInput, currentInputMaxValue, currentInputMinValue, currentSliderMinValue, currentSliderMaxValue, inputToProps, inputFromProps, ...rest }: SliderProps) => import("react/jsx-runtime").JSX.Element;
