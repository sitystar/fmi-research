import { ReactNode } from 'react';
import './Search.scss';
import { TableProps } from '../..';
interface TableSearchProps extends Pick<TableProps, 'onSearch'> {
    searchRef: React.RefObject<HTMLDivElement | null>;
    open: boolean;
    history: string[];
    onCancel: () => void;
    onRemoveFromHistory: (text: string) => void;
    children: ReactNode;
    onVisibleChange?: (val: boolean) => void;
}
export declare const TableSearch: ({ searchRef, open, history, onSearch, onCancel, onRemoveFromHistory, children, onVisibleChange }: TableSearchProps) => import("react/jsx-runtime").JSX.Element;
export {};
