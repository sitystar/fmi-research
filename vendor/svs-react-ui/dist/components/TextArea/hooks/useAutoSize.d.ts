import { CSSProperties, RefObject } from 'react';
import { TextAreaAutoSizeType } from '../TextArea';
export declare const useAutoSize: (textAreaRef: RefObject<HTMLTextAreaElement | null>, autoSize: boolean | TextAreaAutoSizeType) => {
    textAreaStyle: CSSProperties;
    adjustTextAreaHeight: (el: HTMLElement, value: string) => void;
};
