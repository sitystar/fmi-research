import { ExtendedTableDataProps, RowSettings, TableData, TableDataRowIdValue } from '..';
/** преобразовывает строки из плоского вида в древовидную структуру */
export declare const prepareRows: (rows: ExtendedTableDataProps[], parentKeyName?: string, keyName?: string) => ExtendedTableDataProps[];
/** возвращает все дочерние элементы ноды дерева */
export declare const getChildrenNodeTree: (tree: ExtendedTableDataProps[], keyName: string, rowId: TableDataRowIdValue) => ExtendedTableDataProps[];
/** возвращает все дочерние элементы ноды плоского дерева */
export declare const getChildrenNodeFlatTree: (tree: TableData[], keyName: string, parentKeyName: string, rowId: TableDataRowIdValue, children?: TableData[]) => TableData[];
/**
 * получение списка ключей строк содержащих collapseContent
 * @param rowSettings - настройка таблицы содержащая collapseContent
 */
export declare const getAllRowsKeyWithCollapseContent: (rowSettings?: RowSettings) => string[];
