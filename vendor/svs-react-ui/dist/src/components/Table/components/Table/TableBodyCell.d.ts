import { TdHTMLAttributes } from 'react';
import { ExtendedTableDataProps, TableDataRowIdValue, TableDataValues, KeyFieldValues } from '../..';
import { ExtendedTableColProps } from './TableHeader/TableHeaderCell';
import { EditingSettings } from '../../hooks/useEditCell';
import { GoToFromCellType } from '../../hooks/useKeyBoardNavigation';
export interface TableBodyCellProps extends TdHTMLAttributes<HTMLTableCellElement> {
    row: ExtendedTableDataProps;
    col: ExtendedTableColProps;
    editing: boolean;
    isNewRow: boolean;
    onTreeCollapse: (rowId: TableDataRowIdValue) => void;
    onCollapseContentChange: (rowId: TableDataRowIdValue) => void;
    rowsIdExpanded: KeyFieldValues[];
    hasChildren: boolean;
    indent?: number;
    className: string;
    hasCollapseContent: boolean;
    color?: string;
    rowIndex: number;
    editingSettings: EditingSettings;
    onTabPress: () => void;
    rowId?: TableDataValues;
    onKeyBoardNavigation: GoToFromCellType;
}
export declare const TableBodyCell: ({ row, col, editing, isNewRow, rowsIdExpanded, onTreeCollapse, hasChildren, indent, onCollapseContentChange, hasCollapseContent, onClick, onMouseDown, className, color, rowIndex, editingSettings, onTabPress, rowId, onKeyBoardNavigation, ...rest }: TableBodyCellProps) => import("react/jsx-runtime").JSX.Element;
