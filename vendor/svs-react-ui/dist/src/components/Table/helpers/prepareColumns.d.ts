import { TableColProps, TableProps } from '..';
import { ExtendedTableColProps } from '../components/Table/TableHeader/TableHeaderCell';
/** устанавливаем style left для всех ячеек фиксированной колонки */
export declare const setPositionLeftFixedColumn: (table: HTMLTableElement, initLeft: number, cols: TableColProps[]) => void;
export declare const setStyleWidth: (el?: HTMLElement, width?: number) => void;
export declare const getColSpanColumns: (cols?: TableColProps[], span?: number) => number;
export declare const prepareHeaderRows: (cols: ExtendedTableColProps[], multiple: TableProps["multiple"]) => {
    rows: ExtendedTableColProps[][];
    maxIndex: number;
};
/**
 * Получение списка колонок в плоском виде (только те, которые содержат данные)
 */
export declare const flatColumns: (cols: TableColProps[], flatArray?: TableColProps[], depth?: number, parentFix?: boolean | undefined) => TableColProps<import("..").TableData>[];
/**
 * Обогащение колонок перед выводом
 * @param cols
 * @param storageKey
 * @returns
 */
export declare const prepareFlatColumns: (cols: TableColProps[], storageKey?: string) => TableColProps<import("..").TableData>[];
/**
 * Приведение колонок к плоскому формату для сохранения в LocalStorage
 * @param cols
 * @param flatCols
 * @param depth
 * @returns массив массивов из name колонок, где каждый вложенный массив - строка в хедере
 */
export declare const prepareStorageColumnsOrder: (cols: TableColProps[], flatCols?: string[][], depth?: number) => string[][];
/**
 * Сохранение порядка колонок в LocalStorage
 * @param order порядок из prepareStorageColumnsOrder()
 * @param storageKey
 * @returns
 */
export declare const updateLocalStorageOrderColumns: (order: string[][], storageKey?: string) => void;
/**
 * Сортировка колонок
 * @param cols массив колонок
 * @param dragColumn name перемещаемой колонки
 * @param dropColumn name колонки куда будет помещена dragColumn
 * @returns
 */
export declare const sortColumns: (cols: TableColProps[], dragColumn: string, dropColumn: string) => TableColProps<import("..").TableData>[];
/** Подготовка столбцов */
export declare const prepareColumns: (cols: TableColProps[], rowSettings: TableProps["rowSettings"], storageKey?: string) => TableColProps<import("..").TableData>[];
/** обновление списка скрытых столбцов в localStorage */
export declare const updateLocalStorageHideColumns: (hideList: string[], storageKey?: string) => void;
