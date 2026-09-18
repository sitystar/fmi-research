import './InputMessage.scss';
import { InputSize, StatusTypes } from './Input';
export interface InputMessageProps {
    status?: StatusTypes;
    size: InputSize;
    showDangerIcon: boolean;
    showSuccessIcon: boolean;
    message: string;
    disabled?: boolean;
    className?: string;
}
export declare const InputMessage: ({ status, size, showDangerIcon, showSuccessIcon, message, disabled, className }: InputMessageProps) => import("react/jsx-runtime").JSX.Element;
