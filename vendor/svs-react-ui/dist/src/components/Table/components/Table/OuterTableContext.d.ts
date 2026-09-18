import { RefObject } from 'react';
import { ExtendedTableDataProps, TableDataRowIdValue } from '../..';
export type RowsMetaDataType = Record<string, {
    visible: boolean;
    opened: boolean;
}>;
type CollapseFunctionType = (rowId: TableDataRowIdValue) => void;
type OuterTableContextType = {
    visibleRowsData: ExtendedTableDataProps[];
    setVisibleRowsData: (v: ExtendedTableDataProps[] | ((v: ExtendedTableDataProps[]) => ExtendedTableDataProps[])) => void;
    headerRef: RefObject<HTMLTableSectionElement | null> | null;
    rowRefs: RefObject<HTMLTableRowElement[]> | null;
    wrapperRef: RefObject<HTMLDivElement | null> | null;
    rowsMetaDataMap: RowsMetaDataType;
    setRowsMetaDataMap: (v: RowsMetaDataType | ((v: RowsMetaDataType) => RowsMetaDataType)) => void;
    collapseFunction: CollapseFunctionType;
    setCollapseFunction: (func: CollapseFunctionType) => void;
};
export declare const useOuterTableContext: () => OuterTableContextType;
export declare const OuterTableContextProvider: ({ children }: {
    children: any;
}) => import("react/jsx-runtime").JSX.Element;
export {};
