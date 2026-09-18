import { CSSProperties } from 'react';
import { ITableSettingsCol } from './TableSettings';
type TableSettingsColumn = {
    col: ITableSettingsCol;
    style?: CSSProperties;
};
export declare const TableSettingsColumn: import("react").ForwardRefExoticComponent<TableSettingsColumn & import("react").RefAttributes<HTMLDivElement>>;
export {};
