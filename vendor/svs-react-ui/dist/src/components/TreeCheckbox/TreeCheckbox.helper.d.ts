import { TreeCheckboxNode, TreeCheckboxNodeState } from './TreeCheckbox.types';
export declare const getChildrenIds: (data: TreeCheckboxNode[], parentId: string) => string[];
export declare const updateParentState: (data: TreeCheckboxNode[], nodeId: string, updatedState: Record<string, TreeCheckboxNodeState>) => void;
export declare const updateChildState: (data: TreeCheckboxNode[], nodeId: string, checked: boolean, updatedState: Record<string, TreeCheckboxNodeState>) => void;
