import { TableSortDirection, TableProps, TableDataValues } from '../../../index';
import './SortButton.scss';
import './FilterButton.scss';
import './CompactDropdownButton.scss';
import { ExtendedTableColProps } from './TableHeaderCell';
interface TableHeaderCellButtonsProps extends Pick<TableProps, 'onSort' | 'filterable' | 'onOpenFilter'> {
    showSortButton: boolean;
    sortedDirection?: TableSortDirection;
    col: ExtendedTableColProps;
    onConfirmFilter?: (colName: string, items: TableDataValues[]) => void;
    onCloseFilter?: () => void;
    filterValues?: TableDataValues[];
    colName: string;
}
export declare const TableHeaderCellButtons: import("react").NamedExoticComponent<TableHeaderCellButtonsProps & import("react").RefAttributes<HTMLDivElement>>;
export {};
