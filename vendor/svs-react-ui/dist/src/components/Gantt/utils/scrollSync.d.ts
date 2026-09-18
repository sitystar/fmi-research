export declare enum scrollDirections {
    VERTICAL = "vertical",
    HORIZONTAL = "horizontal"
}
/**
 * @description Функция принимает массив HTML элементов и синхронизирует вертикальный или горизонтальный скролл между ними.
 * @param elements массив HTML элементов
 * @param direction направление синхронизации скролла.
 */
export declare function scrollSync(elements: HTMLDivElement[], direction?: scrollDirections): void;
