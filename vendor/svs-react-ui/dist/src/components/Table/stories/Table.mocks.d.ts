import { HeaderButtonTypes, TableProps } from '~/components/Table';
export declare const defaultActionsPanel: {
    buttons: {
        label: string;
        onClick: () => void;
    }[];
};
export declare const tableCommonProps: {
    width: string;
    style: {
        height: number;
    };
    storageKey: string;
    textWrapping: boolean;
    actionsPanel: {
        buttons: {
            label: string;
            onClick: () => void;
        }[];
    };
};
export declare const shortTableData: import("~/components/Table").TableData[];
export declare const shortTableDataFlat: {
    parentId: undefined;
}[];
export declare const renderTooltipEllipsis: (content: string) => import("react/jsx-runtime").JSX.Element;
export declare const headerButtons: HeaderButtonTypes[];
export declare const RenderTable: ({ ...args }: TableProps) => import("react/jsx-runtime").JSX.Element;
export declare const editModeHeaderButtons: string[];
export declare const RenderEditableTable: ({ ...args }: TableProps) => import("react/jsx-runtime").JSX.Element;
