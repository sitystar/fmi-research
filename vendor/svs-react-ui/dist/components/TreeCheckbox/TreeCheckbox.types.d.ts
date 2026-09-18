import { ReactNode } from 'react';
export interface TreeCheckboxNode {
    id: string;
    parentId: string | null;
    label: string;
    description?: string;
    afterContent?: ReactNode;
    checked?: boolean;
    disabled?: boolean;
}
export interface TreeCheckboxNodeState {
    checked: boolean;
    indeterminate: boolean;
}
