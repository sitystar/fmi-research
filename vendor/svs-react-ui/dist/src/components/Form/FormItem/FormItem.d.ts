import { ReactNode } from 'react';
import { FieldData, StoreKey, StoreValue } from '../Form.types';
export declare const FormItemContext: import("react").Context<FieldData | null>;
export interface FormItemProps {
    /** Ключ формы к которому подвязывается FormItem */
    name: StoreKey;
    /** Лейбл для дочернего элемента */
    label?: string;
    /** Изначальное значение контрола формы */
    initialValue?: StoreValue;
    children: ReactNode;
}
export declare const FormItem: ({ name, label, initialValue, children }: FormItemProps) => import("react/jsx-runtime").JSX.Element;
