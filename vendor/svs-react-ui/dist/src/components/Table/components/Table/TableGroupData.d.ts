import { JSX } from 'react';
import { TableGroupedDataTypes } from '../../hooks/useGroup';
import { ExtendedTableDataProps, TableProps } from '../../Table';
interface TableGroupDataProps extends Pick<TableProps, 'cols' | 'multiple' | 'columnActions'> {
    data: TableGroupedDataTypes[];
    level?: number;
    renderRows: (rows: ExtendedTableDataProps[], indent: number, displayIndex: number) => (JSX.Element | null)[];
    foldedGroup: string[];
    onChangeGroup: (groupKey: string) => void;
}
export declare const TableGroupData: ({ data, level, ...rest }: TableGroupDataProps) => (import("react/jsx-runtime").JSX.Element | null)[][];
export {};
