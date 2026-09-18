import { ExtendedTableDataProps, TableColProps } from '..';
/** вычисление цвета ячейки в зависимости от условия */
export declare const getCellBackground: (row: ExtendedTableDataProps, col: TableColProps) => string | undefined;
/** проверка на объект: {} или new MyClass() */
export declare const isObject: (value: any) => boolean;
/** вывод на экран объекта */
export declare const printObject: (value: any) => string;
