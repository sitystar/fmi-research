import { RefObject } from 'react';
import { TextAreaProps } from '../TextArea';
export declare const useResize: (element: RefObject<HTMLElement | null>, options: TextAreaProps) => {
    onStartResize: (e: React.MouseEvent) => void;
};
