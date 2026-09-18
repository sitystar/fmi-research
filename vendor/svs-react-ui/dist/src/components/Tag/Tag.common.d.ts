import { HTMLAttributes, MouseEvent, ReactNode } from 'react';
export type TagSize = 'xl' | 'l' | 'm' | 's';
export interface TagCommonProps extends HTMLAttributes<HTMLSpanElement> {
    size?: TagSize;
    children: ReactNode;
    icon?: ReactNode;
    rounded?: boolean;
    closable?: boolean;
    onRemove?: (e: MouseEvent<HTMLElement>) => void;
}
export declare const getTagCommonClassNames: (size: TagSize, rounded: boolean, closable: boolean, icon?: ReactNode) => string;
