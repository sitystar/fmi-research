import { KeyboardEvent, FC, FocusEvent } from 'react';
import { TableColTypes, TableDataValues } from '../../Table';
interface EditableCellInputProps {
    type: TableColTypes;
    value: TableDataValues;
    onChange: (value: TableDataValues) => void;
    onSelect?: (value: TableDataValues) => void;
    onClear?: () => void;
    onBlur?: (value: TableDataValues, e: FocusEvent<HTMLInputElement>) => void;
    onKeyDown?: (event: KeyboardEvent) => void;
    autoFocus?: boolean;
}
export declare const TableBodyCellControl: FC<EditableCellInputProps>;
export {};
