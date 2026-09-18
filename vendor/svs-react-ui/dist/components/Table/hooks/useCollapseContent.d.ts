import { RowSettings, TableDataRowIdValue } from '../../Table';
/**
 * хук для строк с collapseContent
 * @param rowSettings - настройка для строк таблицы
 */
export declare const useCollapseContent: (rowSettings?: RowSettings) => {
    expandedCollapsingRowsId: string[];
    handleCollapseContentChange: (rowId: TableDataRowIdValue) => void;
};
