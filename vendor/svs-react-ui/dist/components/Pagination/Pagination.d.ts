import { HTMLAttributes } from 'react';
import './Pagination.scss';
/**
 * @deprecated В следующей мажорной версии останется только один аргумент: (pageSize: number) => void.
 * Первый аргумент (n) будет удалён.
 *
 * @param n - [Будет удалён] Возвращает размер страницы. При выборе пункта "Все" - возвращает total.
 * @param pageSize - Возвращает размер страницы. При выборе "Все" - возвращает -1.
 */
export type PaginationOnChangePageSizeChangerType = (n: number, pageSize: number) => void;
export interface PaginationProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    width?: string | number;
    showMore?: boolean;
    showPageSizeChanger?: boolean;
    pageSizeChangerLabel?: string;
    showGoToPage?: boolean;
    goToPageLabel?: string;
    total: number;
    current?: number;
    onChange?: (page: number, pageSize: number) => void;
    pageSizeOptions?: number[];
    onChangePageSizeChanger?: PaginationOnChangePageSizeChangerType;
    /**
     * @deprecated Будет удалено в мажорной версии.
     * вместо этого пропса используйте onChange
     */
    onChangeGoToPage?: (page: number, pageSize: number) => void;
    onChangeMore?: () => void;
    pageSize?: number;
    /**
     * отображает/скрывает опцию "Все" в списке выбора количества на странице
     * @default true
     * */
    showPageSizeOptionAll?: boolean;
    /** отображает/скрывает текст с общим количеством записей
     * @default false
     */
    showTotalRecords?: boolean;
    /** отображает/скрывает кнопки переключения страниц
     * @default true
     */
    showPageChanger?: boolean;
    /** текст для общего количества записей
     * @default "Всего записей"
     */
    totalRecordsLabel?: string;
    /** вариант отображения элементов управления (default - по умолчанию, infinite - предполагается для таблиц и страниц с бесконечной прокруткой для более удобной пагинации с другим расположением, номерами страниц в дропдауне)
     * @default "default"
     */
    variant?: 'default' | 'infinite';
    /** вариант расположения элементов по горизонтали
     * @default "default"
     */
    order?: 'default' | 'reverse';
    /** размер элементов
     * @default m
     */
    size?: 'm' | 's';
    /** начальный индекс загруженных записей для отображения диапазона
     * @default undefined
     */
    loadedFrom?: number;
    /** конечный индекс загруженных записей для отображения диапазона
     * @default undefined
     */
    loadedTo?: number;
}
/** дефолтный размер страницы */
export declare const PAGINATION_DEFAULT_PAGE_SIZE = 15;
export declare const Pagination: ({ width, showMore, showPageSizeChanger, pageSizeChangerLabel, showGoToPage, goToPageLabel, total, current, onChange, onChangePageSizeChanger, onChangeGoToPage, onChangeMore, pageSizeOptions, pageSize, showPageChanger, showPageSizeOptionAll, showTotalRecords, totalRecordsLabel, variant, order, loadedFrom, loadedTo, className, style, size, ...rest }: PaginationProps) => import("react/jsx-runtime").JSX.Element;
