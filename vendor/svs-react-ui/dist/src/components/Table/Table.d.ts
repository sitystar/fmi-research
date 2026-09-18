import { CSSProperties, ReactNode, Dispatch, SetStateAction, ThHTMLAttributes, TdHTMLAttributes, ReactElement, RefAttributes, RefObject, ColHTMLAttributes } from 'react';
import './Table.scss';
import { DropdownItemType } from '../Dropdown';
import { ButtonProps } from '../Button';
import { PaginationProps } from '../Pagination';
import { ActionsPanelButtonProps } from './components/ActionsPanel';
import { EditingCell } from './hooks/useEditCell';
import { TableFilterProps } from './components/Filter';
export type TableDataValues = any;
export type TableData = Record<PropertyKey, TableDataValues>;
export type CellSizeTypes = 'l' | 'm' | 's';
export type ExtendedTableDataProps = TableData & {
    _children?: ExtendedTableDataProps[];
};
export type TableDataRowIdValue = string | number;
/** ***************** const ************************ */
export declare const COMPONENT_CLASS_NAME = "svs-table";
export declare const DEFAULT_KEY_NAME = "id";
export declare const DEFAULT_PARENT_KEY_NAME = "parentId";
export declare const TABLE_DEFAULT_EXPAND_ALL_ROWS = false;
export declare const TABLE_DEFAULT_SIZE = "l";
export declare const DEFAULT_PAGE_SIZE = 15;
export type AggregateResult = {
    label: string;
    value: string | number;
};
export type ColAggregateFunctionsTypes = 'sum' | 'count' | 'min' | 'max';
export type ColAggregateProps = ColAggregateFunctionsTypes | ((args: TableDataValues[]) => AggregateResult | ReactElement);
export type TableColTypes = 'string' | 'boolean' | 'number' | 'date' | 'dateTime' | 'dateTimeWithSeconds' | 'time' | 'HH:mm' | 'HH:mm:ss';
export type ColAlignTypes = 'left' | 'center' | 'right';
export type TableColFilterRenderType = Omit<TableFilterProps, 'children' | 'render' | 'colName'>;
export interface TableColFilter {
    items?: TableDataValues[];
    filtered?: boolean;
    loading?: boolean;
    enabled?: boolean;
    render?: (props: TableColFilterRenderType) => ReactNode;
    renderItem?: (value: TableDataValues) => ReactNode;
}
export type TableColColorConditionsType = {
    color: string;
    conditions: {
        value: TableDataValues | TableDataValues[];
        colName?: string;
        operand?: '=' | '!==' | '<' | '>' | '<=' | '>=' | 'exist' | 'notExist' | 'inArray' | 'notInArray';
    }[];
};
export type TableStatusCell = 'error' | 'disabled' | 'not-editable';
export type TableSortDirection = 'asc' | 'desc' | null;
export type TableMode = 'view' | 'edit';
export interface TableColProps<RecordType = TableData> {
    title: string;
    name?: string;
    type?: TableColTypes;
    width?: string | number;
    sortable?: boolean;
    /**
     Параметр, позволяющий агрегировать значения в колонке таблицы.
  
     Может быть одной из встроенных агрегатных функций:
  
     `'sum'` — суммирование всех числовых значений
  
     `'count'` — подсчет количества элементов
  
     `'min'` — минимальное значение
  
     `'max'` — максимальное значение
  
     Или пользовательской функцией, которая принимает массив значений столбца и возвращает объект с `label` и `value`, либо `ReactElement` для произвольного рендера.
  
     @example
     // Использование предустановленной функции агрегирования
     aggregate: 'sum'
     @example
     // Пользовательская функция для среднего значения
     aggregate: (values) => {
     const numeric = values.filter(v => typeof v === 'number') as number[]
     const avg = numeric.length ? numeric.reduce((a, b) => a + b, 0) / numeric.length : 0
     return { label: 'Среднее значение', value: avg }
     }
     @example
     // Пользовательская функция, возвращающая `ReactElement`
     aggregate: (values) => <strong>{values.length} items</strong>
     @see AggregateResult
     @see TableDataValues
     */
    aggregate?: ColAggregateProps;
    /**
     * Функция агрегации на уровне групп. Принимает функцию, возвращаемую такой же тип данных, который принимает параметр `aggregate`
     * @param groupIndex - индекс группы в которой отрисовывается групповая агрегация. Может быть полезно при разной отрисовке для разных групп
     * @example
     * // Использование предустановленной функции агрегирования
     * aggregateByGroup: () => 'sum'
     * @see TableColProps.aggregate
     */
    aggregateByGroup?: (groupIndex: TableColProps['groupIndex']) => ColAggregateProps;
    align?: ColAlignTypes;
    fix?: boolean;
    filter?: TableColFilter;
    children?: TableColProps<RecordType>[];
    color?: string | TableColColorConditionsType[];
    render?: (value: TableDataValues, row: RecordType, index: number) => ReactNode;
    /**
     * Позволяет задать функцию для рендера заголовка колонки таблицы.
     *
     * Функция получает объект с данными текущей колонки:
     * @param colData.col             Данные и настройки колонки
     * @param colData.filtered        Флаг, показывающий, применён ли к этой колонке фильтр
     * @param colData.sortedDirection Направление сортировки
     *
     * @returns ReactNode — результат, который будет отображен вместо стандартного заголовка.
     */
    renderTitle?: (colData: {
        col: TableColProps<RecordType>;
        filtered: boolean;
        sortedDirection?: TableSortDirection;
    }) => ReactNode;
    visible?: boolean;
    onHeaderCell?: (column: TableColProps<RecordType>) => ThHTMLAttributes<HTMLTableCellElement>;
    onCell?: (row: RecordType, rowIndex: number) => TdHTMLAttributes<HTMLTableCellElement>;
    cellEditor?: (cellValue: TableDataValues, endEdit?: (newValue: TableDataValues) => void, column?: TableColProps<RecordType>, row?: RecordType) => ReactNode;
    status?: (value: TableDataValues, row: RecordType, index: number) => TableStatusCell | null;
    /** Позиция для вывода элемента в элементе-заголовке таблицы перед title */
    beforeTitle?: ReactNode;
    dataIndex?: string | string[];
    /** возможность скрыть столбец, по умолчанию включено */
    hideable?: boolean;
    /** Индекс группировки колонки */
    groupIndex?: number;
    /**
     * Управляет скрытием групповой агрегации на колонке-группе.
     * Работает только с установленным `groupIndex` на текущей колонке и наличием `aggregateByGroup` на другой.
     * @default false
     */
    hideGroupAggregation?: boolean;
    /**
     * Управляет скрытием групповой агрегации на колонке-группе при сворачивании элементов группы.
     * Работает только с установленным `groupIndex` на текущей колонке и наличием `aggregateByGroup` на другой.
     *
     * Игнорируется при установке `hideGroupAggregation` равным `true`
     * @default false
     */
    hideGroupAggregationOnCollapse?: boolean;
    /** рендер функция пользовательского отображения строки группировки */
    groupRender?: (value: TableDataValues, rows: RecordType[]) => ReactNode;
    /** Устанавливает иконку сортировки колонки в указанное направление сортировки */
    sortOrder?: TableSortDirection;
    /**
     * Управление переносом текста в ячейках колонки таблицы.
     * - `true` — текст в ячейках переносится на новую строку.
     * - `false` — текст в ячейках обрезается, перенос запрещён.
     *
     * Имеет приоритет над глобальной настройкой {@link TableProps.textWrapping}.
     * @default false
     */
    textWrapping?: boolean;
    /**
     * Функция позволяющая добавить HTML-атрибуты тегу col в colgroup, например: onColGroup: (name) => ({ style: {min-width: '150px'} })
     *  - Принимает параметр colName - название столбца и col - настройки колонки
     *  - Возвращает объект с HTML-атрибутами, которые будут применены к col
     */
    onColGroup?: (colName: string, col: TableColProps<RecordType>) => ColHTMLAttributes<HTMLTableColElement>;
}
export interface TableSort extends Pick<TableColProps, 'dataIndex'> {
    name: string;
    direction?: TableSortDirection;
}
export interface TableButtonsMore extends DropdownItemType {
    onClick?: () => void;
}
/** @deprecated свойство export будет удалено в одной из следующих мажорных версиях (ориентировочно октябрь 2025) */
type TableHeaderLegacyExportButtonType = 'export';
type TableDefaultHeaderButtons = 'search' | 'filter' | 'import' | 'undo' | 'redo' | 'fullScreen' | 'edit' | 'settings';
export type TableHeaderExportButtonType = {
    type: 'export';
    items: DropdownItemType[];
};
export type TableHeaderEditButtonType = {
    type: 'edit';
    hint: string;
};
/**
 * Типы кнопок для хедера таблицы.
 * Внимание: свойство export является deprecated и будет удалено в одной из следующих мажорных версиях (ориентировочно октябрь 2025)
 */
export type HeaderButtonTypes = TableDefaultHeaderButtons | TableHeaderLegacyExportButtonType | TableButtonsMore[] | TableHeaderExportButtonType | TableHeaderEditButtonType | ReactNode;
/** Список названий кнопок хедера таблицы */
export type TableHeaderButtonNames = Omit<TableDefaultHeaderButtons, 'edit'> | 'export' | 'more';
export interface ColumnActionsButtons extends Omit<ButtonProps, 'onClick'> {
    onClick?: (row: ExtendedTableDataProps) => void;
}
export interface ColumnActions {
    title?: string;
    buttons?: ColumnActionsButtons[] | ((row: TableData) => ColumnActionsButtons[] | undefined);
    content?: ReactNode | ((row: TableData) => ReactNode);
    /**
     * Управление переносом текста в ячейках колонки столбца действий.
     * - `true` — текст в ячейках переносится на новую строку.
     * - `false` — текст в ячейках обрезается, перенос запрещён.
     *
     * Имеет приоритет над глобальной настройкой {@link TableProps.textWrapping}.
     * @default false
     */
    textWrapping?: boolean;
    /**
     * Управляет видимостью колонки в момент редактирования таблицы
     *
     * По умолчанию колонка скрывается в режиме редактирования
     *
     * Если передано значение `true`, то колонка действий будет отображаться и в редиме редактирования таблицы
     *
     * @default undefined
     */
    visibleWhileEditing?: boolean;
}
export interface TablePaginationProps extends Partial<Pick<PaginationProps, 'showMore' | 'goToPageLabel' | 'pageSize' | 'pageSizeChangerLabel' | 'pageSizeOptions' | 'showGoToPage' | 'showPageSizeChanger' | 'total' | 'onChange' | 'onChangePageSizeChanger' | 'current' | 'showPageSizeOptionAll' | 'showTotalRecords' | 'variant' | 'loadedFrom' | 'size' | 'loadedTo'>> {
    enabled?: boolean;
}
export type AppliedFilters = Record<PropertyKey, TableDataValues[]>;
export type KeyFieldValues = string | number | null;
export type RowSettings = Record<TableDataRowIdValue, {
    color?: 'success' | 'error' | string[];
    collapseContent?: ReactNode;
}>;
export interface SelectedCellsData {
    numberRow: number;
    numberCol: number;
    nameCol: string;
    value: TableDataValues;
}
type ActionPanel = {
    visible?: boolean;
    buttons?: ActionsPanelButtonProps[];
    overlay?: boolean;
};
type TableLayoutTypes = 'auto' | 'fixed';
export type TableFilterPanelSettings = {
    title?: ReactNode;
    hideButtonText?: ReactNode;
    showButtonText?: ReactNode;
    removeButtonText?: ReactNode;
};
type TableMethods = {
    /**
     * метод завершения редактирования. Скрывает поля ввода и снимает подсветку редактируемых ячеек
     */
    endEditing: () => void;
    /** метод отмены/завершения редактирования добавленных строк */
    cancelAddingRows: () => void;
    /** метод разворачивания всех строк */
    expandAllRows: () => void;
    /** метод сворачивания всех строк */
    collapseAllRows: () => void;
};
export type TableRef = TableMethods & HTMLDivElement;
export interface TableProps<RecordType extends TableData = TableData> {
    data: RecordType[];
    cols: TableColProps<RecordType>[];
    title?: string;
    isTotalRows?: boolean;
    sortable?: boolean;
    /**
     * Свойство позволяющее настраивать вид отображения сортировки
     *
     *   Указывает вид отображения и область клика для сортировки:
     *
     *   - **'button'** — отображается кнопка сортировки и срабатывает только при клике на эту кнопку.
     *   - **'headerCell'** — иконка сортировки не отображается, сортировка срабатывает при клике на любую часть заголовочной ячейки (кроме других интерактивных элементов).
     * @default button
     */
    sortTrigger?: 'button' | 'headerCell';
    multiple?: boolean;
    /**
     * Управление переносом текста во всех ячейках таблицы.
     * - `true` — текст переносится на новую строку.
     * - `false` — текст обрезается и не переносится.
     *
     * @default false
     */
    textWrapping?: boolean;
    onSelected?: (rows: RecordType[], selectedRowKeys: KeyFieldValues[]) => void;
    onSaveNewRows?: (rows: RecordType[]) => void;
    onSaveEditingCells?: (cells: EditingCell[]) => void;
    onSort?: ({ name, direction, dataIndex }: TableSort) => void;
    onOpenSideFilters?: () => void;
    onImport?: (files: FileList) => void;
    onExport?: (type: string) => void;
    onSearch?: (text: string) => void;
    buttons?: HeaderButtonTypes[];
    striped?: boolean;
    orderable?: boolean;
    className?: string;
    resizable?: boolean;
    /**
     * Настройки столбца действий.
     *
     * -`title?` — название столбца действий.
     *
     * - `textWrapping?` — Управление переносом текста в ячейках колонки.
     *    - `true` — текст в ячейках переносится на новую строку.
     *    - `false` — текст в ячейках обрезается, перенос запрещён.
     *
     *      Имеет приоритет над глобальной настройкой {@link TableProps.textWrapping}.
     *
     * - `content`:
     *    - произвольный контент,
     *    - или функция `(row: TableData) => ReactNode` (возвращает контент для выбранной строки).
     *
     * - `buttons`:
     *    - массив настроек кнопок `ColumnActionsButtons[]` (будут выведены в каждой строке, настройки аналогичны параметрам компонента Button),
     *    - или функция `(row: TableData) => ColumnActionsButtons[] | undefined` (возвращает массив кнопок для выбранной строки).
     *
     *    В `ColumnActionsButtons` поле `title?` работает как `children` у кнопки.
     *
     *    Порядок отображения: `content` → `buttons`
     */
    columnActions?: ColumnActions;
    onConfirmFilter?: (items: AppliedFilters) => void;
    onOpenFilter?: (name: string, dataIndex?: string | string[]) => void;
    onCloseFilter?: () => void;
    onSelectCells?: (selectedCellsData: SelectedCellsData[]) => void;
    filterable?: boolean;
    tableStyle?: CSSProperties;
    tableMode?: TableMode;
    /**
     * Настройки редактирования таблицы:
     *
     *  - **mode**?: 'single' | 'batch' - варианты редактирования данных
     *  - **allowAdding**?: boolean - разрешение/запрет добавления новых строк
     *  - **allowEditing**?: boolean - разрешение/запрет редактирования ячеек
     *  - **allowSelection**?: boolean - разрешение/запрет выделения ячеек
     *  - **saveButtonDisabled**?: boolean - Управление состоянием блокировки кнопки Сохранить
     *  - **addButtonDisabled**?: boolean - Управление состоянием блокировки кнопки Добавить
     *  - **hideControlsOnSave**?: boolean - Скрывать поля ввода и подсветку после нажатия на кнопку Сохранить
     *  - **onAddRow**?: () => void - Функция, вызывающаяся при клике на кнопке Добавить
     *  - **endEditingAfterSave**?: boolean - Выход ячейки из режима редактирования после отправки onSaveNewRows и onSaveEditingCells по кнопке "Сохранить":
     *   - При **true** ячейка выходит из режима редактирования после нажатия на кнопку сохранить
     *   - При **false** ячейка не выходит из режима редактирования после нажатия на кнопку сохранить. Для завершения редактирования необходимо вызвать метод endEditing/cancelAddingRows
     */
    editing?: {
        /**
         * Режим редактирования таблицы
         * @default batch
         *
         * - `single` - при потере фокуса данные сохраняются и отправляются разработчику
         * - `batch` - при потере фокуса данные сохраняются и подсвечиваются. Данные отправляются разработчику после нажатия кнопки Сохранить
         */
        mode?: 'single' | 'batch';
        /**
         * Возможность добавлять новые данные
         * @default true
         */
        allowAdding?: boolean;
        /**
         * Возможность редактировать существующие данные
         * @default true
         */
        allowEditing?: boolean;
        /**
         * Возможность выделять ячейки по одной, группой через зажатие ЛКМ, с помощью shift или весь столбец
         * @default false
         */
        allowSelection?: boolean;
        /**
         * Управление состоянием блокировки кнопки Сохранить
         * @default false
         */
        saveButtonDisabled?: boolean;
        /**
         * Управление состоянием блокировки кнопки Добавить
         * @default false
         */
        addButtonDisabled?: boolean;
        /**
         * Скрывать поля ввода и подсветку после нажатия кнопку Сохранить
         * @default true
         */
        hideControlsOnSave?: boolean;
        /**
         * Функция, вызывающаяся при клике на кнопке Добавить
         */
        onAddRow?: () => void;
        /**
         * Выход ячейки из режима редактирования после отправки onSaveNewRows и onSaveEditingCells по кнопке Сохранить
         *  - При true - ячейка выходит из режима редактирования после нажатия кнопки сохранить
         *  - При false - ячейка не выходит из режима редактирования после нажатия кнопки сохранить. Для завершения редактирования необходимо вызвать метод endEditing/cancelAddingRows
         * @default true
         * @see onSaveNewRows
         * @see onSaveEditingCells
         */
        endEditingAfterSave?: boolean;
    };
    pagination?: TablePaginationProps;
    hiddenFooter?: boolean;
    hiddenHeader?: boolean;
    /**
     * Управление переносом текста в ячейках заголовка столбца.
     *
     * По умолчанию — `false`.
     *
     * Возможные значения:
     * - `true` — Запрет переноса: весь текст в одной строке; не влезший текст обрезается с троеточием.
     * - `false` (по умолчанию) — Обычный перенос по словам.
     * - `'multilineWrap'` — Многострочный перенос по словам; длинные слова обрезаются с троеточием.
     */
    headerColumnWrap?: boolean | 'multilineWrap';
    /**
     * Настройка вида отображения кнопок в ячейке заголовка колонки.
     *
     * По умолчанию — `'default'`.
     *
     * Возможные значения:
     * - `'default'` — Кнопки всегда видны.
     * - `'onHover'` — Кнопки появляются только при наведении.
     * - `'compact'` — Кнопки скрыты в выпадающем меню.
     * - `'compactOnHover'` — Кнопки скрыты в выпадающем меню, которое показывается при наведении.
     */
    headerCellControlsStyle?: 'default' | 'onHover' | 'compact' | 'compactOnHover';
    /**
     * Свойство включающее режим перетаскивания столбцов за ячейку заголовка столбца, вместо отдельной иконки перетаскивания.
     * Работает только при orderable = true
     */
    dragByHeaderCell?: boolean;
    rowSettings?: RowSettings;
    style?: CSSProperties;
    size?: CellSizeTypes;
    actionsPanel?: ActionPanel;
    width?: string | number;
    keyName?: string;
    parentKeyName?: string;
    storageKey?: string;
    defaultSelected?: KeyFieldValues | KeyFieldValues[];
    scrollToSelected?: boolean;
    selectedRowKeys?: KeyFieldValues[];
    afterTitle?: ReactNode;
    loading?: boolean;
    tableLayout?: TableLayoutTypes;
    emptyContent?: ReactNode;
    /**
     * Свойство позволяющее включить панель фильтров внизу таблицы.
     * Панель появляется при активных фильтрах и позволяет централизованно
     * включать, отключать или сбрасывать их.
     * @default false
     */
    showFilterPanel?: boolean;
    /**
     * Свойство позволяющее настраивать панель фильтров
     * @see TableProps.showFilterPanel
     */
    filterPanel?: TableFilterPanelSettings;
    /**
     * Раскрывает все строки по умолчанию
     * @default false
     */
    defaultExpandAllRows?: boolean;
    /**
     * Callback-функция вызывается когда изменяется состояние раскрываемых строк
     * @param expandedRowKeys - список ключей строк, которые изменили свое состояние
     */
    onExpandedRowsChange?: (expandedRowKeys: KeyFieldValues[]) => void;
    /**
     * функция, возвращающая объект с настройками предустановленных кнопок хедера
     * @param buttonName - название кнопки
     */
    onHeaderButton?: (buttonName: TableHeaderButtonNames) => ButtonProps;
    /**
     * Функция, вызываемая при изменении состояния редактирования таблицы.
     * @param isEditing - текущее состояние редактирования: `true` — редактируется, `false` — нет
     */
    onEditModeChange?: (isEditing: boolean) => void;
    /**
     * Функция, вызываемая при изменении порядка столбцов.
     * @param prevColumnsNames - массив массивов, содержащих `name` колонок до изменения порядка,
     * где каждый следующий массив представляет вложенный уровень хедера.
     * @param newColumnsNames - массив массивов, содержащих `name` колонок после изменения порядка,
     * где каждый следующий массив представляет вложенный уровень хедера.
     */
    onColumnsOrderChange?: (prevColumnsNames: string[][], newColumnsNames: string[][]) => void;
}
/** внутренние типы методов сворачивания/разворачивания строк в дереве и строк с контентом */
type ExpandRowsMethodsType = {
    expandAllRowsWithTree: TableMethods['expandAllRows'];
    collapseAllRowsWithTree: TableMethods['expandAllRows'];
    expandAllRowsWithContent: TableMethods['expandAllRows'];
    collapseAllRowsWithContent: TableMethods['expandAllRows'];
};
interface TableContext extends Pick<TableProps, 'keyName' | 'parentKeyName' | 'storageKey' | 'defaultSelected' | 'scrollToSelected' | 'orderable' | 'size' | 'emptyContent' | 'headerColumnWrap' | 'headerCellControlsStyle' | 'dragByHeaderCell' | 'defaultExpandAllRows' | 'onExpandedRowsChange' | 'onHeaderButton' | 'onColumnsOrderChange'> {
    columns: TableColProps[];
    flatCols: TableColProps[];
    setColumns: Dispatch<SetStateAction<TableColProps[]>>;
    appliedFilters: AppliedFilters;
    setAppliedFilters: Dispatch<SetStateAction<AppliedFilters>>;
    expandRowMethodsRef: RefObject<ExpandRowsMethodsType>;
}
export declare const TableContext: import("react").Context<TableContext>;
type TableComponentType = <RecordType extends TableData = TableData>(props: TableProps<RecordType> & RefAttributes<HTMLDivElement>) => ReactElement;
export declare const Table: TableComponentType;
export {};
