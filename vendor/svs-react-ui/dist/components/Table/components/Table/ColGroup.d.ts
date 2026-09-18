import { TableColProps, TableProps } from '../../Table';
interface ColGroup extends Pick<TableProps, 'multiple' | 'columnActions'> {
    flatCols: TableColProps[];
}
export declare const ColGroup: ({ flatCols, multiple, columnActions }: ColGroup) => import("react/jsx-runtime").JSX.Element;
export {};
