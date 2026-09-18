import { MouseEvent } from 'react';
import { ExtendedTableColProps } from '../components/Table/TableHeader/TableHeaderCell';
import { TableProps } from '../Table';
type useCellSelectionProps = Pick<TableProps, 'onSelectCells' | 'data' | 'cols'>;
export declare const useCellSelection: ({ onSelectCells, data, cols }: useCellSelectionProps) => {
    selectedCells: Set<string>;
    selectedColumns: Set<string>;
    startCell: string | null;
    multipleCells: Set<string>;
    onCellClick: (rowId: string, colId: string, event?: MouseEvent) => void;
    onColumnClick: (colId: string, rows: ExtendedTableColProps[], event?: MouseEvent) => void;
    onMouseDown: (rowId: string, colId: string, event?: MouseEvent) => void;
    onMouseMove: (rowId: string, colId: string, event?: MouseEvent) => void;
    onMouseUp: () => void;
    isLastSelectedCell: () => number[];
    getSelectionBounds: (startCell: string, lastCell: string) => {
        minRow: number;
        maxRow: number;
        minCol: number;
        maxCol: number;
    };
    fullySelectedColumns: Set<string>;
    isSelecting: boolean;
    clearSelection: () => void;
};
export {};
