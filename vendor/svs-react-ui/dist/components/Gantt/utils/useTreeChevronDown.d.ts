import { RefObject } from 'react';
import { KeyFieldValues, TableRef } from '~/components/Table';
import { IconValue } from '~/icons';
import { GanttProps } from '~/components/Gantt';
/**
 * Хук, возвращающий иконку-шеврон для сворачивания/разворачивания всех строк дерева таблицы
 * @param tableSettings - настройки таблицы
 * @param tableRef - ref ссылка на таблицу
 * @param Icon - исходная иконка для вывода
 * @param showCollapseAllIcon - флаг отображения иконки
 */
export declare const useTreeChevronDown: (tableSettings: GanttProps["tableSettings"], tableRef: RefObject<TableRef | null>, Icon: IconValue, showCollapseAllIcon: GanttProps["showCollapseAllIcon"]) => {
    tableTreeChevronDown: import("react/jsx-runtime").JSX.Element | null;
    handleTableExpandedRowsChange: (expandedRowKeys: KeyFieldValues[]) => void;
};
