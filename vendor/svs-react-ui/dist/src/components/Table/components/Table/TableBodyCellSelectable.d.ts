import { ExtendedTableDataProps } from '../..';
interface TableBodyCellSelectableProps {
    row: ExtendedTableDataProps;
    tabIndex: number;
    checked?: boolean;
    disabled?: boolean;
    className?: string;
}
export declare const TableBodyCellSelectable: import("react").MemoExoticComponent<({ row, tabIndex, checked, disabled, className }: TableBodyCellSelectableProps) => import("react/jsx-runtime").JSX.Element>;
export {};
