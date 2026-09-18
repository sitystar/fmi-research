import { TableProps } from '~/components/Table';
interface TableRowFreeSpaceProps extends Pick<TableProps, 'emptyContent'> {
    colSpan: number;
    dataLength: number;
}
export declare const TableRowFreeSpace: ({ colSpan, emptyContent, dataLength }: TableRowFreeSpaceProps) => import("react/jsx-runtime").JSX.Element;
export {};
