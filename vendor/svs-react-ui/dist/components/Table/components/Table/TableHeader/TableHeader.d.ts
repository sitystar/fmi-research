import { RefObject } from 'react';
import { TableColProps, TableProps } from '../../../Table';
import { MainProps } from '../Table';
export interface TableHeaderProps extends Pick<TableProps, 'cols' | 'multiple' | 'onCloseFilter' | 'onConfirmFilter' | 'onOpenFilter'>, Pick<MainProps, 'onSort' | 'columnActions' | 'sortable' | 'sortTrigger' | 'orderable' | 'resizable' | 'filterable'>, Pick<TableColProps, 'beforeTitle'> {
    tableRef: RefObject<HTMLTableElement | null>;
    wrapperTableRef: RefObject<HTMLDivElement | null>;
    countDataRows: number;
}
export declare const TableHeader: import("react").MemoExoticComponent<({ cols, multiple, onSort, columnActions, sortable, sortTrigger, orderable, resizable, filterable, onCloseFilter, onConfirmFilter, onOpenFilter, tableRef, wrapperTableRef, countDataRows }: TableHeaderProps) => import("react/jsx-runtime").JSX.Element>;
