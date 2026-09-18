import { ExtendedTableDataProps, TableColProps, TableDataRowIdValue, TableDataValues, TableProps } from '../Table';
export interface EditingCell extends Pick<TableColProps, 'dataIndex'> {
    rowId: number | string;
    colName: string;
    prevValue: TableDataValues;
    value: TableDataValues;
}
export interface EditingSettings {
    editingCells: Record<string, EditingCell>;
    editedCells: Record<string, EditingCell>;
    newRows: ExtendedTableDataProps[];
    addNewRow: (defaultValues?: object) => void;
    handleChangeCell: (cell: EditingCell) => void;
    handleDoubleClick: (rowId: TableDataRowIdValue, col: TableColProps, prevValue: TableDataValues) => void;
    handleBlurOrEnter: (rowId: TableDataRowIdValue, col: TableColProps, newValue: TableDataValues) => void;
    handleCancelEdit: (rowId: TableDataRowIdValue, colName: string) => void;
    isBatchMode: boolean;
    editingProcess: boolean;
    generateCellKey: (rowId: TableDataRowIdValue, colName: string) => string;
    isRowEditingNewRow: (rowId: TableDataRowIdValue) => boolean;
    isAddingNewRow: boolean;
    hasUnsavedChanges: boolean;
    endEditing?: () => void;
    cancelAddingRows?: () => void;
}
interface useEditCellProps extends Pick<TableProps, 'editing' | 'cols' | 'keyName' | 'onSaveNewRows'> {
    onSaveCells?: (cells: EditingCell[]) => void;
}
type TableEditingCellsType = Record<string, EditingCell>;
export declare const useEditCell: ({ cols, keyName, editing, onSaveCells, onSaveNewRows }: useEditCellProps) => {
    editingCells: TableEditingCellsType;
    editedCells: TableEditingCellsType;
    newRows: ExtendedTableDataProps[];
    addNewRow: () => void;
    handleChangeCell: (cell: EditingCell) => void;
    handleDoubleClick: (rowId: TableDataRowIdValue, col: TableColProps, prevValue: TableDataValues) => void;
    handleBlurOrEnter: (rowId: TableDataRowIdValue, col: TableColProps, newValue: TableDataValues) => void;
    handleCancelEdit: (rowId: TableDataRowIdValue, colName: string) => void;
    saveAllChanges: () => void;
    isBatchMode: boolean;
    editingProcess: boolean;
    generateCellKey: (rowId: TableDataRowIdValue, colName: string) => string;
    isRowEditingNewRow: (rowId: TableDataRowIdValue) => boolean;
    isAddingNewRow: boolean;
    hasUnsavedChanges: boolean;
    endEditing: () => void;
    cancelAddingRows: () => void;
};
export {};
