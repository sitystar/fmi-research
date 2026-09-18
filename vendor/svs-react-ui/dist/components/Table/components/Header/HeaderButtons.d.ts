import { TableProps } from '../..';
interface HeaderButtonsProps extends Pick<TableProps, 'buttons' | 'onEditModeChange'> {
    isEditMode: boolean;
    isSavedChanges: boolean;
    isAddNewRowDisabled: boolean;
    onAddRow: () => void;
    onSave: () => void;
    allowAdding?: boolean;
    onOpenSideFilters?: () => void;
    onImport?: (files: FileList) => void;
    onExport?: (format: string) => void;
    onSearch?: (value: string) => void;
    editingProcess: boolean;
}
export declare const HeaderButtons: import("react").MemoExoticComponent<({ buttons, isEditMode, isSavedChanges, isAddNewRowDisabled, onAddRow, onSave, allowAdding, onOpenSideFilters, onImport, onExport, onSearch, editingProcess, onEditModeChange }: HeaderButtonsProps) => import("react/jsx-runtime").JSX.Element>;
export {};
