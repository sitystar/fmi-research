import { DragEventHandler, ThHTMLAttributes, MouseEventHandler } from 'react';
import { TableSortDirection, TableColProps, TableProps, TableDataValues } from '../../..';
export interface ExtendedTableColProps extends TableColProps {
    colSpan?: number;
    rowSpan?: number;
    colgroupColIndex?: number | string;
    _drag?: boolean;
    _drop?: boolean;
    _over?: boolean;
    _lastFixed?: boolean;
}
interface TableHeaderCellProps extends Pick<TableProps, 'onSort' | 'sortTrigger' | 'resizable' | 'filterable' | 'onOpenFilter'>, ThHTMLAttributes<HTMLTableCellElement>, Pick<TableColProps, 'beforeTitle'> {
    tableSortable?: boolean;
    tableOrderable?: boolean;
    sortedDirection?: TableSortDirection;
    col: ExtendedTableColProps;
    onDragEnter?: DragEventHandler<HTMLElement>;
    onDragLeave?: DragEventHandler<HTMLElement>;
    onDrop?: DragEventHandler<HTMLElement>;
    onDragStart?: DragEventHandler<HTMLElement>;
    onDragEnd?: DragEventHandler<HTMLElement>;
    onResizerMouseDown?: MouseEventHandler<HTMLDivElement>;
    onResizerDoubleClick?: MouseEventHandler<HTMLDivElement>;
    onConfirmFilter?: (colName: string, items: TableDataValues[]) => void;
    onCloseFilter?: () => void;
    onColumnClick?: MouseEventHandler<HTMLTableCellElement>;
    filterValues?: TableDataValues[];
}
export declare const TableHeaderCell: ({ col, tableSortable, sortTrigger, onSort, sortedDirection, onDragEnter, onDragLeave, onDrop, onDragStart, onDragEnd, tableOrderable, resizable, onResizerMouseDown, onResizerDoubleClick, onConfirmFilter, onOpenFilter, onCloseFilter, onColumnClick, filterable, filterValues, className, beforeTitle, ...rest }: TableHeaderCellProps) => import("react/jsx-runtime").JSX.Element;
export {};
