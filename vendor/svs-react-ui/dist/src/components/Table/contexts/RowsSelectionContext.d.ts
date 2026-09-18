import { ReactNode } from 'react';
import { ExtendedTableDataProps, TableProps } from '~/components/Table';
import { EditingSettings } from '~/components/Table/hooks/useEditCell';
interface RowsSelectionContextProps {
    selectedRows: ExtendedTableDataProps[];
    unselectRows?: () => void;
    onSelectAllRows?: (val: boolean) => void;
    onSelectRow?: (row: ExtendedTableDataProps) => void;
}
/** получение данных о выборе строк из контекста */
export declare const useRowSelection: () => RowsSelectionContextProps;
interface RowsSelectionProviderProps extends Pick<TableProps, 'onSelected' | 'data' | 'defaultSelected' | 'keyName' | 'multiple' | 'selectedRowKeys'> {
    children: ReactNode;
    editingSettings: EditingSettings;
}
export declare const RowsSelectionProvider: ({ children, onSelected, data, defaultSelected, keyName, multiple, selectedRowKeys, editingSettings }: RowsSelectionProviderProps) => import("react/jsx-runtime").JSX.Element;
export {};
