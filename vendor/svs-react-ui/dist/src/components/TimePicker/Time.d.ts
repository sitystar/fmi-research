import { HTMLAttributes } from 'react';
import { TimePickerProps } from '~/components/TimePicker';
interface TimeProps extends Pick<HTMLAttributes<HTMLLIElement>, 'onMouseDown' | 'className' | 'style'>, Pick<TimePickerProps, 'format'> {
    onClick: (time: string) => void;
    width?: number | string;
    timeList?: string[];
}
export declare const Time: ({ onClick, width, onMouseDown, timeList, className, style, format }: TimeProps) => import("react/jsx-runtime").JSX.Element;
export {};
