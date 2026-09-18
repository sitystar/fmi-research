/**
 * @description Функция принимает объект с размерами html элементов,
 * заданными строкой или числом.
 * И, если они заданы строкой, извлекает из них числовое значение,
 * если заданы числом, оставляет их без изменений.
 * Возвращает новый объект с теми же названиями полей.
 *  @example
 * dimensionsToNumber({width: "200px", height: "200px"})
 * вернёт
 * {width: 200, height: 200}
 */
export declare const dimensionsToNumber: (dimensions: {
    [key: string]: string | number;
}) => {
    [key: string]: number;
};
