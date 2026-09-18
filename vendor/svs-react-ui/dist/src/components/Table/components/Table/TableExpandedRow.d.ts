import { TableProps } from '../../Table';
interface TableExpandedRow extends Pick<TableProps, 'multiple'> {
    content?: React.ReactNode;
    colSpan?: number;
}
export declare const TableExpandedRow: import("react").MemoExoticComponent<({ content, colSpan, multiple }: TableExpandedRow) => import("react/jsx-runtime").JSX.Element>;
export {};
