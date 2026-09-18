export type GoToFromCellType = (cellElement: HTMLTableCellElement | null, direction: 'up' | 'down' | 'left' | 'right') => void;
export declare const useKeyBoardNavigation: (multiple?: boolean, hasColumnActions?: boolean) => {
    goToFromCell: GoToFromCellType;
};
