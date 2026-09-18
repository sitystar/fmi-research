import { KeyboardEvent, TdHTMLAttributes } from 'react';
import { ColAlignTypes, TableStatusCell } from '../..';
interface TableBodyCellTemplateProps extends TdHTMLAttributes<HTMLTableCellElement> {
    selected?: boolean;
    editing?: boolean;
    align?: ColAlignTypes;
    width?: string | number;
    fix?: boolean;
    lastFixed?: boolean;
    name?: string;
    className?: string;
    color?: string;
    onKeyDown?: (event: KeyboardEvent) => void;
    status?: TableStatusCell | null;
}
export declare const TableBodyCellTemplate: import("react").NamedExoticComponent<TableBodyCellTemplateProps & import("react").RefAttributes<HTMLTableCellElement>>;
export {};
