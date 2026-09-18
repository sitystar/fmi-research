import { ColumnActions, ExtendedTableDataProps, TableProps } from '../..';
interface TableBodyCellActionsProps extends Pick<ColumnActions, 'buttons' | 'content' | 'textWrapping'>, Pick<TableProps, 'size'> {
    row: ExtendedTableDataProps;
}
export declare const TableBodyCellActions: import("react").MemoExoticComponent<({ buttons, content, row, size: tableSize, textWrapping }: TableBodyCellActionsProps) => import("react/jsx-runtime").JSX.Element>;
export {};
