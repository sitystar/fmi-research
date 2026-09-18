import { TableColProps, TableDataValues, TableProps } from '../../../Table';
import './TableGroupRow.scss';
interface TableGroupRowProps extends Pick<TableColProps, 'groupRender'> {
    groupValue: TableDataValues;
    colSpan: number;
    onChange: (groupKey: string) => void;
    groupKey: string;
    isFolded: boolean;
    groupLabel: string;
    rows: TableProps['data'];
    indent: number;
}
export declare const TableGroupRow: (props: TableGroupRowProps) => import("react/jsx-runtime").JSX.Element;
export {};
