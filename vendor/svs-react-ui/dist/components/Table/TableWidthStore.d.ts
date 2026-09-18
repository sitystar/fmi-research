type Listener = () => void;
/**
 * Мини-хранилище (store) для ширины таблицы.
 *
 * - Хранит текущее значение ширины (width)
 * - Позволяет подписываться на изменения
 * - Позволяет обновлять ширину и оповещать подписчиков
 */
declare class TableWidthStore {
    private width;
    private listeners;
    /** Возвращает актуальное значение ширины */
    getSnapshot: () => number;
    /**
     * Подписывает функцию-слушатель на изменения ширины.
     * Возвращает функцию для отписки.
     */
    subscribe: (listener: Listener) => () => void;
    /**
     * Устанавливает новую ширину.
     * Если значение изменилось, оповещает всех подписчиков.
     */
    setWidth: (nextWidth: number) => void;
}
/**
 * Контекст, в который кладём TableWidthStore.
 */
export declare const TableWidthStoreContext: import("react").Context<TableWidthStore | null>;
/**
 * Хук для чтения ширины таблицы.
 * Использует useSyncExternalStore, чтобы подписаться только на изменения ширины.
 */
export declare function useTableWrapperWidth(): number;
/**
 * Фабрика для создания стора (каждой таблице нужен свой).
 */
export declare function createTableWidthStore(): TableWidthStore;
export {};
