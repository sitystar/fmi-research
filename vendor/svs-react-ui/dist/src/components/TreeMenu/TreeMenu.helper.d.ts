import { ItemKeyType, TreeMenuPropItem } from './TreeMenu';
/**
 * Поиск ключей всех дочерних элементов включая родителя
 * @param item - элемент дерева
 * @param keys - список ключей
 */
export declare const getAllChildrenKeys: (item: TreeMenuPropItem, keys?: ItemKeyType[]) => ItemKeyType[];
/**
 * Получение ключей всех пунктов с defaultOpened = true
 * @param items
 * @param keys
 */
export declare const getDefaultOpenedKeys: (items: TreeMenuPropItem[], keys?: ItemKeyType[]) => ItemKeyType[];
/**
 * получение списка ключей всех пунктов меню
 * @param items
 * @param keys
 */
export declare const getAllItemsKeys: (items: TreeMenuPropItem[], keys?: ItemKeyType[]) => ItemKeyType[];
export interface FlattenedItem extends TreeMenuPropItem {
    parentId: ItemKeyType | null;
    depth: number;
    index: number;
}
export declare const flattenTree: (items: TreeMenuPropItem[], parentId?: ItemKeyType | null, depth?: number) => FlattenedItem[];
export declare const buildTree: (flattenedItems: FlattenedItem[]) => TreeMenuPropItem[];
export interface Projection {
    depth: number;
    parentId: ItemKeyType | null;
    isNesting: boolean;
}
export declare function getProjection(items: FlattenedItem[], activeId: ItemKeyType, overId: ItemKeyType, dragOffset: number, indentationWidth: number): Projection;
