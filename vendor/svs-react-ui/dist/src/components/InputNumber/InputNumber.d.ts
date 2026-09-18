import { ReactNode } from 'react';
import { InputProps } from '../Input/Input';
import './InputNumber.scss';
type ControlsType = boolean | {
    upIcon?: ReactNode;
    downIcon?: ReactNode;
};
export interface InputNumberProps extends Omit<InputProps, 'value' | 'defaultValue' | 'onChange' | 'onBlur' | 'mask' | 'type' | 'onEnter' | 'clearable' | 'onClear' | 'iconAfter' | 'onChanged' | 'step' | 'max' | 'min'> {
    /**
     * Текущее значение. Включает управляемый режим над компонентом.
     * Если включен режим isBigInt, работа с дробями будет отброшена
     */
    value?: number | bigint | null;
    /**
     * Значение по-умолчанию.
     * Если включен режим isBigInt, работа с дробями будет отброшена
     */
    defaultValue?: number | bigint | null;
    onChange?: (value: number | bigint | null) => void;
    onBlur?: (value: number | bigint | null) => void;
    onEnter?: (value: number | bigint | null) => void;
    step?: number | bigint;
    controls?: ControlsType;
    /**
     * Количество знаков после запятой, до которых округляется итоговое число.
     * Например, precision=2 превратит 3.14159 в 3.14. Не работает с BigInt.
     */
    precision?: number;
    min?: number | bigint;
    max?: number | bigint;
    parser?: (displayValue: string) => number | bigint;
    formatter?: (value: number | bigint | null) => string;
    type?: 'text' | 'number';
    /**
     * Флаг для работы с числами, более 2^53 (BigInt),
     * при включении работа с дробями будет отброшена (значение после запятой будет обрезано)
     * @default false
     */
    isBigInt?: boolean;
}
export declare const InputNumber: import("react").ForwardRefExoticComponent<InputNumberProps & import("react").RefAttributes<HTMLInputElement>>;
export {};
