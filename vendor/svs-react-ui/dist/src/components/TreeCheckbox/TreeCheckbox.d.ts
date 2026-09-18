import { HTMLAttributes } from 'react';
import { TreeCheckboxNode } from './TreeCheckbox.types';
import './TreeCheckbox.scss';
export interface TreeCheckboxProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    data: TreeCheckboxNode[];
    hover?: boolean;
    active?: boolean;
    collapsable?: boolean;
    openState?: boolean;
    onChange?: (checkedCheckboxes: TreeCheckboxNode[]) => void;
}
export declare const TreeCheckbox: ({ data, hover, active, collapsable, openState, className, onChange, ...rest }: TreeCheckboxProps) => import("react/jsx-runtime").JSX.Element;
