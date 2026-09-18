import { MouseEventHandler, ReactNode, MouseEvent } from 'react';
import './Tabs.scss';
import { TabSizes } from './Tabs';
export interface TabProps {
    active: boolean;
    onClick?: MouseEventHandler<HTMLButtonElement>;
    disabled?: boolean;
    label: ReactNode;
    size: TabSizes;
    closable?: boolean;
    onRemove?: (event: MouseEvent<HTMLSpanElement>) => void;
}
export declare const Tab: ({ active, label, onClick, size, disabled, closable, onRemove }: TabProps) => import("react/jsx-runtime").JSX.Element;
