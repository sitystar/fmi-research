import { DragEndEvent, DragMoveEvent, DragOverEvent, DragStartEvent } from '@dnd-kit/core';
import { ItemKeyType, TreeMenuPropItem } from '../TreeMenu';
import { FlattenedItem, getProjection } from '../TreeMenu.helper';
export interface useTreeDnDReturn {
    activeId: ItemKeyType | null;
    overId: ItemKeyType | null;
    offsetLeft: number;
    activeItem: FlattenedItem | null | undefined;
    projection: ReturnType<typeof getProjection> | null;
    handleDragStart: (event: DragStartEvent) => void;
    handleDragOver: (event: DragOverEvent) => void;
    handleDragMove: (event: DragMoveEvent) => void;
    handleDragEnd: (event: DragEndEvent) => void;
    handleDragCancel: () => void;
}
interface UseTreeDnDProps {
    items: TreeMenuPropItem[];
    onItemsChange?: (items: TreeMenuPropItem[]) => void;
    draggable?: boolean;
    openKeys?: ItemKeyType[];
    expandedList: ItemKeyType[];
    onOpenChange?: (keys: ItemKeyType[]) => void;
    setExpandedList: (setter: (prev: ItemKeyType[]) => ItemKeyType[]) => void;
}
export declare const useTreeDnD: ({ items, onItemsChange, draggable, openKeys, expandedList, onOpenChange, setExpandedList }: UseTreeDnDProps) => useTreeDnDReturn;
export {};
