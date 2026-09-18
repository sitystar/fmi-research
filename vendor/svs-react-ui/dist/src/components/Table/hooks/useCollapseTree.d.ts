import { TableData, KeyFieldValues, TableDataRowIdValue } from '..';
export declare const useCollapseTree: (rows: TableData[]) => {
    expandedTreeRowsId: KeyFieldValues[];
    handleCollapse: (rowId: TableDataRowIdValue) => void;
};
