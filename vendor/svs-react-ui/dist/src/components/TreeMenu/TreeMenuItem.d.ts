import { useSortable } from '@dnd-kit/sortable';
import { ItemKeyType, TreeMenuPropItem } from './TreeMenu';
import { Projection } from './TreeMenu.helper';
interface TreeMenuItemProps extends Pick<TreeMenuPropItem, 'onClick'> {
    item: TreeMenuPropItem;
    isCurrent: boolean;
    hasIcons?: boolean;
    depth: number;
    parent?: ItemKeyType;
    expandedList: ItemKeyType[];
    isDragging?: boolean;
    isOverlay?: boolean;
    isOver?: boolean;
    dropIndicator?: 'before' | 'after' | null;
    showDragHandle?: boolean;
    dragListeners?: ReturnType<typeof useSortable>['listeners'];
    dragAttributes?: ReturnType<typeof useSortable>['attributes'];
    projection?: Projection | null;
    isDraggable?: boolean;
}
export declare const TreeMenuItem: import("react").ForwardRefExoticComponent<TreeMenuItemProps & import("react").RefAttributes<HTMLAnchorElement>>;
export {};
