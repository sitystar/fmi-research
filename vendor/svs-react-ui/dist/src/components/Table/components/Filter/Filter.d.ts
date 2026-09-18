import { ReactNode, RefObject } from 'react';
import './Filter.scss';
import { TableColFilter, TableColProps, TableDataValues, TableProps } from '../..';
export interface TableFilterProps extends Pick<TableProps, 'onSearch'>, Pick<TableColFilter, 'items' | 'render' | 'renderItem'> {
    open: boolean;
    onCancel?: () => void;
    onConfirm?: (items: TableDataValues[]) => void;
    loading?: boolean;
    loaderIcon?: ReactNode;
    children: ReactNode;
    onVisibleChange?: (val: boolean) => void;
    colName: TableColProps['name'];
    filterPopupRef?: RefObject<HTMLDivElement>;
}
export declare const TableFilter: import("react").MemoExoticComponent<(props: TableFilterProps) => import("react/jsx-runtime").JSX.Element>;
