import { ItemKeyType, TreeMenuPropItem } from '../TreeMenu';
import { Projection } from './TreeMenu.helper';
interface DraggableTreeItemProps extends Pick<TreeMenuPropItem, 'onClick'> {
    id: ItemKeyType;
    item: TreeMenuPropItem;
    depth: number;
    isCurrent: boolean;
    hasIcons?: boolean;
    parent?: ItemKeyType;
    expandedList: ItemKeyType[];
    dropIndicator: 'before' | 'after' | null;
    isOver: boolean;
    showDragHandle?: boolean;
    projection?: Projection | null;
    isDraggable?: boolean;
}
export declare const DraggableTreeItem: ({ id, showDragHandle, ...props }: DraggableTreeItemProps) => import("react/jsx-runtime").JSX.Element;
export {};
