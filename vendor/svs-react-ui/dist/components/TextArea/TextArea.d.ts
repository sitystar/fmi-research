import './TextArea.scss';
import { ChangeEvent, TextareaHTMLAttributes } from 'react';
export type styleType = 'default' | 'subtle' | 'none';
type ResizeType = 'both' | 'horizontal' | 'vertical' | 'none';
export type TextAreaAutoSizeType = {
    minRows: number;
    maxRows: number;
};
export interface TextAreaProps extends TextareaHTMLAttributes<HTMLTextAreaElement> {
    /**
     * Стилевое оформление поля
     * @default 'default'
     */
    variant?: styleType;
    /**
     * Оформление поля стилем invalid/valid
     * @default 'default'
     */
    invalid?: boolean;
    /**
     * Ширина поля
     */
    width?: string | number;
    /**
     * Высота поля
     */
    height?: string | number;
    /**
     * Направления изменения поля
     * @default 'both'
     */
    resize?: ResizeType;
    /**
     * Подстраивать высоту поля ввода под содержимое.
     * Принимает значение типа `boolean`, либо объект вида `{ minRows: number; maxRows: number }`
     * с указанием минимального и максимального количества строк.
     *
     * @default false
     */
    autoSize?: boolean | TextAreaAutoSizeType;
    /**
     * Блокирует поле ввода
     */
    disabled?: boolean;
    /**
     * Placeholder для поля
     */
    placeholder?: string;
    /**
     * Событие изменения поля
     */
    onChange?: (event: ChangeEvent<HTMLTextAreaElement>) => void;
}
export declare const TextArea: import("react").ForwardRefExoticComponent<TextAreaProps & import("react").RefAttributes<HTMLTextAreaElement>>;
export {};
