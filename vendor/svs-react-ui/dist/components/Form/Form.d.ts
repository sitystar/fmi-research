import { HTMLAttributes } from 'react';
import { FormInstance, StoreObject } from './Form.types';
export declare const FormContext: import("react").Context<FormInstance | null>;
export interface FormProps extends Omit<HTMLAttributes<HTMLFormElement>, 'onSubmit'> {
    form?: FormInstance;
    initialValues?: StoreObject;
    onFinish?: (form: FormInstance) => void;
}
export declare const Form: ({ form, onFinish, initialValues, children, ...rest }: FormProps) => import("react/jsx-runtime").JSX.Element;
