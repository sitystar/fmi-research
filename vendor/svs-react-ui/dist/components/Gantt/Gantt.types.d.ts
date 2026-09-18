import { HTMLAttributes, ReactNode } from 'react';
import { GanttBarColors, IntervalItem, IntervalOption } from './Gantt.const';
import { customBarWithCoords } from './GanttTimeline/GanttBarList/GanttBarList';
import { GanttTimelineDataType } from './GanttTimeline';
import { TableProps } from '~/components/Table';
import { GanttEventMarker } from '~/components/Gantt/GanttTimeline';
export declare enum GanttBarTypes {
    DEFAULT = "default",
    MILESTONE = "milestone",
    CUSTOM = "custom",
    PROJECT = "project"
}
/** список общих типов для бара (GanttTimelineItem) */
interface GanttTimelineItemCommonTypes {
    /** id бара в строке */
    id?: number | string;
    /** Список id баров от которых стрелки будут нарисованы к данному бару.
     *
     *  - _Для корректного отображения требует у текущего бара указать id_
     *  - _Заменяет dependingLinkedColumnValues при использовании в этом же баре_
     * */
    dependingBarIds?: (number | string)[];
}
/**
 * @interface GanttTimelineItem
 * @prop {GanttBarTypes.DEFAULT} barType?: Стандартный бар
 * @prop {number | string} linkedTableColumnValue: Поле для связки элемента таймлайна с элементом таблицы
 * @prop {Date} start: Дата планируемого старта элемента таймлайна
 * @prop {Date} end: Дата планируемого окончания элемента таймлайна
 * @prop {Date} actualStart?: Дата фактического старта элемента таймлайна. При отрисовке элемента будет выбрана min из start и actualStart.
 * @prop {Date} actualEnd?: Дата фактического окончания элемента таймлайна. Разница между actualEnd и end отображается, как просроченное время.
 * @prop {number | string} parentLinkedTableColumnValues?: Указание на id родительского элемента в таблице
 * @prop {ReactNode} beforeContent?: Контент в левой части элемента таймлайна
 * @prop {ReactNode} afterContent?: Контент в правой части элемента таймлайна
 * @prop {ReactNode} content?: Основной контент элемента таймлайна
 * @prop {ReactNode} beforeBarContent?: Контент между кнопкой collapse и элементом таймлайна
 * @prop {ReactNode} afterBarContent?: Контент справа от элемента таймлайна. Пример: кнопка с (+) для добавления комментария
 * @prop {GanttBarColors} barColor?: Цвет элемента таймлайна
 * @prop {number} fullness?: Процент заполнения бара
 * @prop {(number | string)[] | null} dependingLinkedColumnValues?: Список, от каких элементов рисовать стрелки к данному элементу.
 */
export interface GanttTimelineItem extends GanttTimelineItemCommonTypes {
    barType?: GanttBarTypes.DEFAULT;
    linkedTableColumnValue: number | string;
    start: Date;
    end: Date;
    actualStart?: Date;
    actualEnd?: Date;
    parentLinkedTableColumnValues?: number | string;
    beforeContent?: ReactNode;
    afterContent?: ReactNode;
    content?: ReactNode;
    beforeBarContent?: ReactNode;
    afterBarContent?: ReactNode;
    barColor?: GanttBarColors;
    fullness?: number;
    dependingLinkedColumnValues?: (number | string)[] | null;
}
/**
 * @interface GanttTimelineProjectItem
 * @prop {GanttBarTypes.PROJECT} barType?: Проектный бар
 * @prop {number | string} linkedTableColumnValue: Поле для связки элемента таймлайна с элементом таблицы
 * @prop {Date} start: Дата планируемого старта элемента таймлайна
 * @prop {Date} end: Дата планируемого окончания элемента таймлайна
 * @prop {Date} actualStart?: Дата фактического старта элемента таймлайна. При отрисовке элемента будет выбрана min из start и actualStart.
 * @prop {Date} actualEnd?: Дата фактического окончания элемента таймлайна. Разница между actualEnd и end отображается, как просроченное время.
 * @prop {number | string} parentLinkedTableColumnValues?: Указание на id родительского элемента в таблице
 * @prop {ReactNode} content?: Основной контент элемента таймлайна
 * @prop {ReactNode} beforeBarContent?: Контент между кнопкой collapse и элементом таймлайна
 * @prop {ReactNode} afterBarContent?: Контент справа от элемента таймлайна. Пример: кнопка с (+) для добавления комментария
 * @prop {GanttBarColors} barColor?: Цвет элемента таймлайна
 * @prop {(number | string)[] | null} dependingLinkedColumnValues?: Список, от каких элементов рисовать стрелки к данному элементу.
 */
export interface GanttTimelineProjectItem extends GanttTimelineItemCommonTypes {
    barType: GanttBarTypes.PROJECT;
    linkedTableColumnValue: number | string;
    start: Date;
    end: Date;
    actualStart?: Date;
    actualEnd?: Date;
    parentLinkedTableColumnValues?: number | string;
    content?: ReactNode;
    beforeBarContent?: ReactNode;
    afterBarContent?: ReactNode;
    barColor?: GanttBarColors;
    dependingLinkedColumnValues?: (number | string)[] | null;
}
/**
 * @interface GanttTimelineMilestone
 * @prop {GanttBarTypes.MILESTONE} barType?: "Веха"
 * @prop {Date} start: Дата планируемого старта элемента таймлайна
 * @prop {number | string} linkedTableColumnValue: Поле для связки элемента таймлайна с элементом таблицы
 * @prop {number | string} parentLinkedTableColumnValues?: Указание на id родительского элемента в таблице
 * @prop {(number | string)[] | null} dependingLinkedColumnValues?: Список, от каких элементов рисовать стрелки к данному элементу.
 * @prop {ReactNode} beforeBarContent?: Контент слева от бара
 * @prop {ReactNode} afterBarContent?: Контент справа от бара
 */
export interface GanttTimelineMilestone extends GanttTimelineItemCommonTypes {
    barType: GanttBarTypes.MILESTONE;
    start: Date;
    linkedTableColumnValue: number | string;
    parentLinkedTableColumnValues?: number | string;
    dependingLinkedColumnValues?: (number | string)[] | null;
    beforeBarContent?: ReactNode;
    afterBarContent?: ReactNode;
}
/**
 * @interface GanttTimelineCustomItem
 * @prop {GanttBarTypes.CUSTOM} barType?: Кастомный бар
 * @prop {Date} start: Дата планируемого старта элемента таймлайна
 * @prop {Date} end: Дата планируемого окончания элемента таймлайна
 * @prop {number | string} linkedTableColumnValue: Поле для связки элемента таймлайна с элементом таблицы
 * @prop {number | string} parentLinkedTableColumnValues?: Указание на id родительского элемента в таблице
 * @prop {(number | string)[] | null} dependingLinkedColumnValues?: Список, от каких элементов рисовать стрелки к данному элементу.
 * @prop {[key: string]: any} ... Любые данные которые прокинутся в аргумент item функции render
 */
export interface GanttTimelineCustomItem extends Record<any, any>, GanttTimelineItemCommonTypes {
    barType: GanttBarTypes.CUSTOM;
    start: Date;
    end: Date;
    linkedTableColumnValue: number | string;
    parentLinkedTableColumnValues?: number | string;
    dependingLinkedColumnValues?: (number | string)[] | null;
}
/**
 * @interface GanttTimeScaleRenderer
 * @prop {number} timeTableStart: время начала таблицы
 * @prop {number} timeTableEnd: время окончания таблицы
 * @prop {number} width: ширина временной шкалы, px
 * @prop {number} height: высота временной шкалы, px
 * @prop {IntervalItem} interval: Какой интервал сейчас выбран (день, месяц, год и т.д.)
 */
export interface GanttTimeScaleRenderer {
    timeTableStart: number;
    timeTableEnd: number;
    width: number;
    height: number;
    interval: IntervalItem;
}
/**
 * @type GanttCustomBarRenderer
 * @prop {{ timelineStart: Date; timelineEnd: Date; timelineWidth: number }} timeline: данные таймлайна: дата начала, дата конца, ширина таймлайна в пикселях.
 * @prop {customBarWithCoords[]} customBarsInLineList: данные кастомных баров с опциональными дополнительными аргументами.
 * @prop {[key: string]: any} ... Любые данные которые прокинутся в аргумент item функции render
 */
export type GanttCustomBarRenderer = Record<any, any> & {
    timeline: {
        timelineStart: Date;
        timelineEnd: Date;
        timelineWidth: number;
    };
    customBarsInLineList: customBarWithCoords[];
};
/**
 * Типы компонентов для хедера.
 */
export type GanttTimelineHeaderItem = 'intervalSelector' | 'navigationPanel' | ReactNode;
export type GanttTimeLineSettings = {
    timelineData: GanttTimelineDataType[];
    timelineHeaderCustomContent?: ReactNode;
    timelineHeaderItems?: GanttTimelineHeaderItem[] | null;
    defaultInterval?: IntervalOption;
    intervals?: IntervalOption[];
    legendTableColField?: string;
    striped?: boolean;
};
export interface GanttTableData {
    colText: string;
    colLongText: string;
    id: number;
    parentId?: number;
    colProgress?: string;
    start: Date;
    end: Date;
}
export type GanttBarDataTypes = Omit<GanttTimelineItem, 'linkedTableColumnValue'> | Omit<GanttTimelineMilestone, 'linkedTableColumnValue'> | Omit<GanttTimelineCustomItem, 'linkedTableColumnValue'> | Omit<GanttTimelineProjectItem, 'linkedTableColumnValue'>;
export interface GanttTimelineItemTypes extends GanttTableData {
    tasks: GanttBarDataTypes[];
}
export interface GanttProps {
    /**
     * @deprecated Будет удалено в мажорной версии.
     * вместо этого пропса используйте showBarCollapseButtons
     */
    tableWidth?: number | string;
    /**
     * Ширина таймлайна. Если значение не задано, таймлайн будет занимать всё свободное место в контейнере, оставшееся после таблицы.
     */
    timelineWidth?: number | string;
    /**
     * Высота диаграммы Гантта. Если значение не задано, высота определяется количеством строк в таблице.
     */
    height?: number | string;
    /**
     * [Настройки](/?path=/docs/complex-components-table--docs) таблицы.
     *
     * Диаграмма Гантта переиспользует компонент `Table` и повторяет его поведение и функционал.
     * За исключением: параметр `hiddenHeader` всегда установлен в `true`.
     */
    tableSettings: TableProps;
    /**
     * Данные для таймлайна.
     *
     * #### Свойства:
     * - `intervals` - список возможных значений периода таймлайна.
     * Принимает массив вида `("hours" | "day" | "week" | "month" | "year")[]`
     *
     * - `defaultInterval` - длительность периода таймлайна по умолчанию.
     * Может принимать значения `"hours" | "day" | "week" | "month" | "year"`. Значение по умолчанию `"hours"`.
     * Если передан массив `intervals`, `defaultInterval` должен соответствовать одному из значений этого массива.
     * В противном случае в качестве `defaultInterval` будет принято первое значение массива `intervals`.
     *
     * - `timelineHeaderItems` — элементы, отображаемые в хэдере таймлайна.
     * Принимает массив значений типа `TimelineHeaderComponent`.
     *
     *    Доступные значения `TimelineHeaderComponent`:
     *    - `"intervalSelector"` — выпадающий список для выбора интервала
     *    - `"navigationPanel"` — кнопки навигации (вперёд / назад / сегодня)
     *    - `ReactNode` — любой пользовательский компонент
     *
     *   По умолчанию используется `["intervalSelector", "navigationPanel"]`.
     *   Порядок отображения соответствует порядку в массиве.
     *
     *   Чтобы скрыть все компоненты передайте в `timelineHeaderItems` `null` или `[]`
     *
     * - `timelineHeaderCustomContent` - свободный контент для области слева от `timelineHeaderItems` в хэдере таймлайна.
     * Принимает объект типа `"ReactNode"`.
     *
     * - `legendTableColField` - название колонки таблицы, данные из ячеек которой используются для комментариев к барам в легенде таймлайна.
     *
     * - `striped` - выделять строки диаграммы через одну акцентным цветом.
     * Принимает значение типа boolean.
     *
     * - `timelineData` - данные для отображения в таймлайне.
     * Принимает массив из объектов типа `(GanttTimelineItem | GanttTimelineMilestone | GanttTimelineCustomItem | GanttTimelineProjectItem)[]`
     *
     * #### Поддерживаемые типы данных в `timelineData`:
     *
     * 1. **GanttTimelineItem** стандартный бар:
     * - `id?: number | string` - id бара в строке
     * - `barType: GanttBarTypes.DEFAULT`.
     * - `linkedTableColumnValue: number | string` - Поле для связки элемента таймлайна с элементом таблицы.
     * - `dependingBarIds?: (number | string)[]` - список id баров от которых стрелки будут нарисованы к данному бару.
     * Заменяет `dependingLinkedColumnValues` при использовании в этом же баре.
     * Для корректного отображения требует у текущего бара указать id
     * - `start: Date` - Дата планируемого старта элемента таймлайна.
     * - `end: Date` - Дата планируемого окончания элемента таймлайна.
     * - `actualStart: Date` - Дата фактического старта элемента таймлайна. При отрисовке элемента будет выбрана `min` из `start` и `actualStart`.
     * - `actualEnd: Date` - Дата фактического окончания элемента таймлайна. Разница между `actualEnd` и `end` отображается, как просроченное время.
     * - `parentLinkedTableColumnValues: number | string` - Указание на id родительского элемента в таблице.
     * - `beforeContent: ReactNode` - Контент в левой части элемента таймлайна.
     * - `content: ReactNode` - Основной контент элемента таймлайна.
     * - `afterContent: ReactNode` - Контент в правой части элемента таймлайна.
     * - `beforeBarContent: ReactNode` - Контент между кнопкой collapse и элементом таймлайна.
     * - `afterBarContent: ReactNode` - Контент справа от элемента таймлайна. Пример: кнопка с (+) для добавления комментария.
     * - `barColor: GanttBarColors` - Цвет элемента таймлайна.
     * - `fullness: number` - Процент заполнения бара.
     * - `dependingLinkedColumnValues: (number | string)[] | null` - Список, от каких элементов рисовать стрелки к данному элементу.
     *
     *      Пример:
     *
     *      ```
     *      [
     *        {
     *          barType: GanttBarTypes.DEFAULT,
     *          linkedTableColumnValue: 2
     *          start: new Date('Tue Jul 16 2024 16:00:00 GMT+0300 (Москва, стандартное время)'),
     *          end: new Date('Thu Jul 18 2024 16:00:00 GMT+0300 (Москва, стандартное время)'),
     *          actualStart: new Date('Mon Jul 15 2024 16:00:00 GMT+0300 (Москва, стандартное время)'),
     *          actualEnd: new Date('Fri Jul 19 2024 16:00:00 GMT+0300 (Москва, стандартное время)'),
     *          parentLinkedTableColumnValues: [1]
     *          beforeContent: <Content title='Azalia Estrada' />,
     *          content: <Content iconTitle='user-circle' title='Success' />,
     *          afterContent: <Content title='50%' />,
     *          beforeBarContent?: ReactNode
     *          afterBarContent?: ReactNode
     *          barColor: 'success',
     *          fullness: 50
     *          dependingLinkedColumnValues: [1]
     *        }
     *      ]
     *      ```
     *
     * 2. **GanttTimelineProjectItem** — проектный бар.
     * - Структура объекта аналогична `GanttTimelineItem` за исключением:
     *      - значение поля `barType: GanttBarTypes.PROJECT`
     *      - отсутствуют поля `barType`, `beforeContent`, `afterContent`, `fullness`
     *
     * 3. **GanttTimelineMilestone** — веха. Служит для отображения события, не имеющего продолжительности по времени.
     * Объект со следующими полями:
     * - `barType: GanttBarTypes.MILESTONE`
     * - `linkedTableColumnValue: number | string` — Поле для связки элемента таймлайна с элементом таблицы
     * - `start: Date` — Дата планируемого старта элемента таймлайна
     * - `dependingLinkedColumnValues: (number | string)[] | null` — Список, от каких элементов рисовать стрелки к данному элементу.
     * - `beforeBarContent: ReactNode` — Контент слева от бара
     * - `afterBarContent: ReactNode` — Контент справа от бара
     *
     *      Пример:
     *
     *      ```
     *      [
     *        {
     *          barType: GanttBarTypes.MILESTONE,
     *          linkedTableColumnValue: 20,
     *          start: new Date('Tue Jul 16 2024 16:00:00 GMT+0300 (Москва, стандартное время)'),
     *          dependingLinkedColumnValues: [1]
     *        }
     *      ]
     *      ```
     *
     * 4. **GanttTimelineCustomItem** — кастомный бар.
     * Бар с произвольным пользовательским дизайном, который рендерится при помощи функции customBarRenderer.
     * Объект со следующими полями:
     * - `barType: GanttBarTypes.CUSTOM`
     * - `linkedTableColumnValue: number | string` - Поле для связки элемента таймлайна с элементом таблицы
     * - `start: Date` - Дата планируемого старта элемента таймлайна
     * - `end: Date` - Дата планируемого окончания элемента таймлайна
     * - `left: number` - координата левого края бара относительно начала таймлайна.
     * - `width: number` - ширина бара.
     * - `dependingLinkedColumnValues?: (number | string)[] | null` - Список, от каких элементов рисовать стрелки к данному элементу.
     *
     *      Пример:
     *
     *      ```
     *      [
     *        {
     *          barType: GanttBarTypes.CUSTOM,
     *          linkedTableColumnValue: 21,
     *          start: new Date('Tue Jul 16 2024 16:00:00 GMT+0300 (Москва, стандартное время)'),
     *          end: new Date('Thu Jul 18 2024 16:00:00 GMT+0300 (Москва, стандартное время)'),
     *          left: 456,
     *          width: 400,
     *          dependingLinkedColumnValues: [1]
     *        }
     *      ]
     *      ```
     */
    timelineSettings: GanttTimeLineSettings;
    /**
     * Временные маркеры для обозначения сроков, дедлайнов и т.д.
     *
     * Принимает массив из объектов со следующими полями:
     * - `date: Date` — дата маркера времени (обязательное поле)
     * - `content: ReactNode` — контент, отображаемый справа от линии маркера (необязательно)
     * - `color: string` — цвет линии маркера (необязательно)
     *
     * Пример:
     *
     * ```
     * [
     *   {
     *     date: new Date('2024-07-20T17:00:00Z'),
     *     content: 'ГИП 2024',
     *     color: '#f00'
     *   }
     * ]
     * ```
     */
    eventMarkers?: GanttEventMarker[];
    /**
     * @deprecated Будет удалено в мажорной версии.
     * вместо этого пропса используйте showBarCollapseButtons
     */
    showTimelineCollapseButton?: boolean;
    /** Показывать кнопку, позволяющую развернуть/скрыть дочерние элементы бара */
    showBarCollapseButtons?: boolean;
    /** Показывать кнопку сворачивания таблицы */
    showTableCollapseButton?: boolean;
    style?: CSSStyleDeclaration;
    className?: string;
    /** Отображать легенду внизу диаграммы. */
    showLegend?: boolean;
    /** Показывать таблицу. */
    showTable?: boolean;
    /** Показывать таймлайн. */
    showTimeline?: boolean;
    /**
     * Функция для отрисовки пользовательской шкалы времени.
     * Если функция не передана, будет отрисована стандартная шкала.
     */
    timeScaleRenderer?: (args: GanttTimeScaleRenderer) => ReactNode;
    /**
     * Функция для отрисовки пользовательских кастомных баров.
     * Все бары, имеющие тип `GanttBarTypes.CUSTOM`, будут отрендерены при помощи этой функции.
     */
    customBarRenderer?: (args: {
        timeline: {
            timelineStart: Date;
            timelineEnd: Date;
            timelineWidth: number;
        };
        customBarsInLineList: customBarWithCoords[];
    }) => ReactNode;
    /**
     * Функция позволяющая добавить HTML-атрибуты бару в строке, например: onBar: (bar, barIndex) => ({onDoubleClick: () => console.log(bar, barIndex)})
     * @param bar - возвращает настройки бара
     * @param barIndex - возвращает порядковый номер бара в строке
     * @returns Объект с HTML-атрибутами, которые будут применены к элементу бара
     */
    onBar?: (bar: GanttTimelineDataType, barIndex: number) => HTMLAttributes<HTMLDivElement>;
    /**
     * Отображение иконки-шеврона, позволяющего свернуть/развернуть все строки
     * @default false
     */
    showCollapseAllIcon?: boolean;
}
export {};
