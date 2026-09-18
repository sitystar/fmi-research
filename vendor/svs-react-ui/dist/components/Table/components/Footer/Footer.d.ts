import { TablePaginationProps, TableProps } from '../..';
interface FooterProps extends Pick<TableProps, 'isTotalRows'> {
    pagination?: TablePaginationProps;
}
export declare const Footer: ({ pagination, isTotalRows }: FooterProps) => import("react/jsx-runtime").JSX.Element;
export {};
