import { TableColProps, TableDataValues, TableProps } from '../Table';
type UseGroupProps = Pick<TableProps, 'data' | 'cols'>;
export interface TableGroupedDataTypes {
    label: string;
    value: TableDataValues;
    rows: TableGroupedDataTypes[] | TableProps['data'];
    render: TableColProps['groupRender'];
    hasData: boolean;
    groupIndex: NonNullable<TableColProps['groupIndex']>;
    hideGroupAggregation: TableColProps['hideGroupAggregation'];
    hideGroupAggregationOnCollapse: TableColProps['hideGroupAggregationOnCollapse'];
    groupKey: string;
}
/**
 * хук группировки данных в таблице
 * @param data - данные таблицы
 * @param cols - столбцы таблицы
 * @return список ключей свернутых групп, событие клика на иконку сворачивания, сгруппированные данные
 */
export declare const useGroup: ({ data, cols }: UseGroupProps) => {
    foldedGroup: string[];
    onChangeGroup: (groupKey: string) => void;
    groupedData: TableGroupedDataTypes[] | null;
};
export {};
