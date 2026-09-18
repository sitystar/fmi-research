import { RefObject, TextareaHTMLAttributes } from 'react';
import { onChangeData } from '../DateTimePicker';
import { SelectorProps } from '../Selector';
type InputValue = string;
type CheckboxValue = boolean;
type RadioValue = string;
type TextareaValue = TextareaHTMLAttributes<HTMLTextAreaElement>['value'];
type TimePickerValue = string;
type DatePickerValue = string;
type DateTimePickerValue = onChangeData;
type SelectorValue = SelectorProps['selectedValue'];
type ControlValue = InputValue | CheckboxValue | TextareaValue | RadioValue | TimePickerValue | DatePickerValue | DateTimePickerValue | SelectorValue | null;
export type StoreKey = string;
export type StoreValue = ControlValue;
export type Store = Map<StoreKey, StoreValue>;
export type StoreObject = {
    [key: StoreKey]: StoreValue;
};
export interface FieldData {
    name: StoreKey;
    label?: string;
    initialValue?: ControlValue;
    setValue: (value: ControlValue) => void;
}
export interface FormInstance {
    registerFormRef: (formRef: RefObject<HTMLFormElement>) => void;
    registerFormField: (formField: FieldData) => void;
    getFieldValue: (name: StoreKey) => StoreValue;
    getFieldsValue: () => StoreObject;
    getInitialValues: () => Store;
    getInitialValue: (name: StoreKey) => StoreValue;
    setFieldValue: (name: StoreKey, value: StoreValue) => void;
    setFieldsValue: (values: StoreObject) => void;
    setInitialValues: (initialValues: StoreObject) => void;
    setInitialValue: (name: StoreKey, value: StoreValue) => void;
    submit: () => void;
}
export {};
