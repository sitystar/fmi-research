import { TableBody } from './TableBody';
export type RowVisibilityMapType = Record<string, boolean>;
interface TableRowProps extends TableBody {
}
export declare const TableRows: ({ size, ...rest }: TableRowProps) => import("react/jsx-runtime").JSX.Element | (import("react/jsx-runtime").JSX.Element | null)[];
export {};
