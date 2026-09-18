import { DragEvent } from 'react';
export declare function useDragging(): {
    handleColumnDragStart: (e: DragEvent<HTMLDivElement>) => void;
    handleColumnDragEnd: (e: DragEvent<HTMLDivElement>) => void;
    handleColumnDrop: (e: DragEvent<HTMLDivElement>) => void;
    handleColumnDragEnter: (e: DragEvent<HTMLDivElement>) => void;
    handleColumnDragLeave: (e: DragEvent<HTMLDivElement>) => void;
};
