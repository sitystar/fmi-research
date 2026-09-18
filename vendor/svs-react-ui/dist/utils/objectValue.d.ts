/**
 * получение значения из объекта
 * @param entity - объект, в котором будет происходить поиск
 * @param path - массив вложенных ключей, по которым будет произведен поиск
 */
export declare const getObjectValue: (entity: unknown, path?: PropertyKey[]) => unknown;
/**
 * Установка значения ключа объекта по пути
 * @param obj - изменяемый объект
 * @param path - массив вложенных ключей, по которым будет произведен поиск
 * @param value - значение для изменения
 */
export declare const setObjectValue: (obj: any, path: PropertyKey[], value: any) => any;
