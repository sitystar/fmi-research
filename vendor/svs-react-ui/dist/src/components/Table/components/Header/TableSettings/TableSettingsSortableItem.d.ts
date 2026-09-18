import { ReactNode } from 'react';
import { ITableSettingsCol } from './TableSettings';
type TableSettingsSortableItemProps = {
    dragging: boolean;
    col: ITableSettingsCol;
    children: ReactNode;
};
export declare const TableSettingsSortableItem: ({ children, col, dragging }: TableSettingsSortableItemProps) => import("react/jsx-runtime").JSX.Element;
export {};
