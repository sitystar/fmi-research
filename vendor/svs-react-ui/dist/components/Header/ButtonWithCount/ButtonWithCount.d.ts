import { ButtonProps } from '../../Button';
import './ButtonWithCount.scss';
interface ButtonWithCountProps extends ButtonProps {
    counter?: number;
    buttonClassName?: string;
}
export declare const ButtonWithCount: ({ counter, className, buttonClassName, ...rest }: ButtonWithCountProps) => import("react/jsx-runtime").JSX.Element;
export {};
