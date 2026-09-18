import { ReactNode, SetStateAction, Dispatch } from 'react';
import { EditingSettings } from '../../../Table/hooks/useEditCell';
import { TableMode, TableProps } from '~/components/Table';
export interface EditModeContextType extends Pick<EditingSettings, 'isAddingNewRow'>, Pick<TableProps, 'editing'> {
    isEditMode: boolean;
    setEditMode: Dispatch<SetStateAction<boolean>>;
}
export declare const useEditMode: () => EditModeContextType;
interface EditModeProviderTypes extends Pick<EditingSettings, 'isAddingNewRow'>, Pick<TableProps, 'editing'> {
    mode: TableMode;
    children: ReactNode;
}
export declare const EditModeProvider: ({ children, mode, isAddingNewRow, editing }: EditModeProviderTypes) => import("react/jsx-runtime").JSX.Element;
export {};
