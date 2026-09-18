import { TableProps } from '../..';
import { EditingSettings } from '../../hooks/useEditCell';
interface HeaderProps extends Pick<TableProps, 'onOpenSideFilters' | 'onImport' | 'onExport' | 'onSearch' | 'buttons' | 'actionsPanel' | 'title' | 'afterTitle' | 'multiple' | 'onEditModeChange'> {
    onAddRow: () => void;
    onSave: () => void;
    editingSettings: EditingSettings;
    allowAdding?: boolean;
}
export declare const Header: ({ title, onAddRow, onSave, onOpenSideFilters, onImport, onExport, onSearch, buttons, actionsPanel, editingSettings, allowAdding, afterTitle, multiple, onEditModeChange }: HeaderProps) => import("react/jsx-runtime").JSX.Element;
export {};
