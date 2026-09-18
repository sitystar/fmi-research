/**
 * @description Функция сравнения элементов для передачи в качестве
 * коллбэка в метод Array.prototype.sort() для сортировки массивов объектов.
 * @param field - поле объекта, по которому осуществяется сортировка.
 * @param {"asc" | "desc"} order - направление сортировки.
 * @param {Function} primer - функция, которую нужно применить к каждому элементу
 *  перед сравнением (например, toUpperCase, parseInt и т.д.)
 * @returns number
 */
export declare const sortBy: <T>(field: string, order: "asc" | "desc", primer?: ((arg: any) => any) | null) => (prev: {
    [key: string]: T;
}, next: {
    [key: string]: T;
}) => number;
