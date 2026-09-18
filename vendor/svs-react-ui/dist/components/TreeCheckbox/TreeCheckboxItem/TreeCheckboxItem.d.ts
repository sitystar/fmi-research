import { JSX } from 'react';
import { TreeCheckboxNode, TreeCheckboxNodeState } from '../TreeCheckbox.types';
import './TreeCheckboxItem.scss';
export interface TreeCheckboxItemProps {
    data: TreeCheckboxNode[];
    node: TreeCheckboxNode;
    hover?: boolean;
    active?: boolean;
    collapsable?: boolean;
    isCollapsed: boolean;
    level: number;
    handleCheck: (id: string) => void;
    checkedState: Record<string, TreeCheckboxNodeState>;
    renderTreeNodes: (parentId: string) => JSX.Element[];
    toggleCollapse: () => void;
}
export declare const TreeCheckboxItem: ({ data, node, hover, active, collapsable, isCollapsed, level, handleCheck, checkedState, renderTreeNodes, toggleCollapse }: TreeCheckboxItemProps) => import("react/jsx-runtime").JSX.Element;
