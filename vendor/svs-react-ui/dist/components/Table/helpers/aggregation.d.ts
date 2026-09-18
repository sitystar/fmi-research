import { ExtendedTableDataProps, TableDataValues } from '..';
export declare const getCount: (elements: ExtendedTableDataProps[]) => number;
export declare const getSum: (elements: TableDataValues[]) => number;
export declare const getMaxMin: (elements: TableDataValues[], type: "max" | "min") => number | "-";
