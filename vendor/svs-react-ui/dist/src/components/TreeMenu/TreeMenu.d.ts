import { CSSProperties, MouseEvent as ReactMouseEvent, ReactNode } from 'react';
import './TreeMenu.scss';
export type TreeMenuItemClickEvent = ReactMouseEvent<HTMLAnchorElement, MouseEvent>;
export type ItemKeyType = string | number;
export interface TreeMenuPropItem {
    label?: ReactNode;
    icon?: ReactNode;
    key: ItemKeyType;
    onClick?: (event: TreeMenuItemClickEvent, item: TreeMenuPropItem) => void;
    children?: TreeMenuPropItem[];
    href?: string;
    target?: '_self' | '_blank';
    defaultOpened?: boolean;
}
export interface TreeMenuProps {
    items: TreeMenuPropItem[];
    /**
     * Включает режим перетаскивания (Drag-and-Drop) для элементов дерева.
     * @default false
     */
    draggable?: boolean;
    /**
     * Callback, который срабатывает после успешного завершения перетаскивания.
     * Возвращает новую, измененную структуру `items`.
     * Работает только в режиме `draggable=true`.
     */
    onItemsChange?: (items: TreeMenuPropItem[]) => void;
    /**
     * Определяет, будет ли отображаться тригер-иконка перетаскивания элемента.
     * Если `false`, перетаскивать можно будет за всю строку элемента.
     * Если 'true', перетаскивать можно только за тригер-иконку
     * Работает только в режиме `draggable=true`.
     * @default true
     */
    showDragHandle?: boolean;
    title?: string;
    className?: string;
    style?: CSSProperties;
    width?: string | number;
    openKeys?: ItemKeyType[];
    onOpenChange?: (openKeys: ItemKeyType[]) => void;
    onSelect?: (selectedKey: ItemKeyType, event: TreeMenuItemClickEvent) => void;
    selectedKey?: ItemKeyType;
}
/**
 * @deprecated
 * Будет удалено в мажорной версии. Вместо этого типа используйте openKeys и тип TreeMenuProps
 */
export type TreeMenuRefType = {
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте openKeys
     */
    expandItem: (key: ItemKeyType) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте openKeys
     */
    collapseItem: (key: ItemKeyType) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте openKeys
     */
    expandItems: (keys: ItemKeyType[]) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте openKeys
     */
    collapseItems: (keys: ItemKeyType[]) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте openKeys
     */
    expandAll: () => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте openKeys
     */
    collapseAll: () => void;
};
export declare const INDENTATION_WIDTH = 32;
export declare const TreeMenu: import("react").ForwardRefExoticComponent<TreeMenuProps & import("react").RefAttributes<TreeMenuRefType>>;
