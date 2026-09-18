interface Item<T extends string | number> {
    id: T;
    size: number;
    priority?: number;
}
/**
 * Фильтрует элементы, которые не помещаются в контейнер, учитывая приоритет и промежутки между элементами
 * @param containerSize - ширина контейнера
 * @param items - массив элементов
 * @param gap - промежуток между элементами
 * @returns массив идентификаторов элементов, которые помещаются в контейнер
 */
export declare function filterExceedingItems<T extends string | number>(containerSize: number, items: Item<T>[], { gap }?: {
    gap?: number;
}): T[];
export {};
