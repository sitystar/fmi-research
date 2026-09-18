import { TableHTMLAttributes } from 'react';
import { TableProps, CellSizeTypes } from '../../Table';
import { EditingSettings } from '../../hooks/useEditCell';
export interface MainProps extends TableProps, TableHTMLAttributes<HTMLTableElement> {
    size: CellSizeTypes;
    editingSettings: EditingSettings;
}
export declare const TABLE_CLASS_NAME = "svs-table__main-table";
export declare const TABLE_CELL_MIN_WIDTH = 40;
export declare const Main: ({ data, cols, keyName, sortable, sortTrigger, multiple, onSort, orderable, resizable, columnActions, parentKeyName, onConfirmFilter, onOpenFilter, onCloseFilter, onSelectCells, filterable, hiddenHeader, headerColumnWrap, rowSettings, editingSettings, size, textWrapping, tableLayout, ...rest }: Omit<MainProps, "ref">) => import("react/jsx-runtime").JSX.Element;
