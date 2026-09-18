import { ReactNode } from 'react';
export type PriorityOverflowListItem = {
    priority?: number;
    content: ReactNode;
    ignored?: boolean;
};
type PriorityOverflowListProps = {
    items: PriorityOverflowListItem[];
    className?: string;
};
export declare function PriorityOverflowList({ items, className }: PriorityOverflowListProps): import("react/jsx-runtime").JSX.Element;
export {};
