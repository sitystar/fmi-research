import { ReactNode } from 'react';
import { TableProps } from '~/components/Table';
interface CellSelectionContextType {
    selectedCells: Set<string>;
    selectedColumns: Set<string>;
    startCell: string | null;
    onCellClick: (rowId: string, colId: string, event?: React.MouseEvent) => void;
    onColumnClick: (colId: string, rows: any[], event?: React.MouseEvent) => void;
    onMouseDown: (rowId: string, colId: string, event?: React.MouseEvent) => void;
    onMouseMove: (rowId: string, colId: string, event?: React.MouseEvent) => void;
    onMouseUp: (event?: React.MouseEvent) => void;
    getSelectionBounds: (startCell: string, lastCell: string) => {
        minRow: number;
        maxRow: number;
        minCol: number;
        maxCol: number;
    };
    isLastSelectedCell: () => number[];
    fullySelectedColumns: Set<string>;
    multipleCells: Set<string>;
    isSelecting: boolean;
    clearSelection: () => void;
}
export declare const useCellSelectionContext: () => CellSelectionContextType;
interface CellSelectionProviderProps extends Pick<TableProps, 'onSelectCells' | 'data' | 'cols'> {
    children: ReactNode;
}
export declare const CellSelectionProvider: ({ children, onSelectCells, data, cols }: CellSelectionProviderProps) => import("react/jsx-runtime").JSX.Element;
export {};
