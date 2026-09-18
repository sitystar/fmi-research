import { RefObject, MouseEvent as ReactMouseEvent } from 'react';
export declare function useResizing(tableRef: RefObject<HTMLTableElement | null>, wrapperTableRef: RefObject<HTMLDivElement | null>): {
    handleResizerMouseDown: (e: ReactMouseEvent) => void;
    handleAutoResize: (e: ReactMouseEvent) => void;
};
