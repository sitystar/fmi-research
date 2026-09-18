import { TableProps } from '../../Table';
import { MainProps } from './Table';
export interface TableBody extends Pick<TableProps, 'data' | 'parentKeyName' | 'keyName' | 'multiple' | 'columnActions' | 'onSelectCells' | 'size' | 'cols'>, Pick<MainProps, 'rowSettings' | 'editingSettings'> {
}
export declare const TableBody: ({ cols, data, parentKeyName, keyName, multiple, rowSettings, columnActions, onSelectCells, size, editingSettings }: TableBody) => import("react/jsx-runtime").JSX.Element;
