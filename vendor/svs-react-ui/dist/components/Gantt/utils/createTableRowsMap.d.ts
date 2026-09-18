import { RowsMetaDataType } from '../../Table/components/Table/OuterTableContext';
import { ExtendedTableDataProps } from '../../Table';
/**
 * @description Функция принимает древовидную структуру tableData и объект rowsMetaDataMap, содержащий поля
visible (видимость бара) и opened (состояние бара свернут/развёрнут) и возвращает одномерный массив объектов
с данными, необходимыми для построения баров в том порядке, в котором они представлены в таблице.
 */
export declare const createTableRowsMap: (tableData: ExtendedTableDataProps[], rowsMetaDataMap: RowsMetaDataType, legendTableColField?: string) => any[];
