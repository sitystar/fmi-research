import { ReactNode, Dispatch, SetStateAction } from 'react';
import { TableProps } from '../../Table';
import { PaginationProps } from '~/components/Pagination';
interface TablePaginationContextTypes extends Pick<TableProps, 'data'>, PaginationProps {
    currentPage?: number;
    onChangeCurrentPage?: (n: number) => void;
    setPageSizeChanger?: Dispatch<SetStateAction<number | undefined>>;
    countRows: number;
}
/**
 * хук получения данных о пагинации
 */
export declare const useTablePagination: () => TablePaginationContextTypes;
interface TablePaginationProviderProps extends Pick<TableProps, 'data' | 'pagination' | 'defaultSelected' | 'selectedRowKeys' | 'scrollToSelected' | 'keyName' | 'parentKeyName'> {
    children: ReactNode;
}
/** провайдер пагинации */
export declare const TablePaginationProvider: ({ children, data, pagination, selectedRowKeys, scrollToSelected, keyName, defaultSelected, parentKeyName }: TablePaginationProviderProps) => import("react/jsx-runtime").JSX.Element;
export {};
