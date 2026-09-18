import { TableColProps, ExtendedTableDataProps, TableProps } from '../../Table';
interface AggregateRowProps extends Pick<TableProps, 'multiple' | 'columnActions'> {
    flatColumns: TableColProps[];
    rows: ExtendedTableDataProps[];
    groupIndex?: number;
}
export declare const TableAggregateRow: ({ multiple, flatColumns, columnActions, rows, groupIndex }: AggregateRowProps) => import("react/jsx-runtime").JSX.Element;
export {};
