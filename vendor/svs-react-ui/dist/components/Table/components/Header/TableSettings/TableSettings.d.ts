import { TableColProps } from '../../../Table';
import './TableSettings.scss';
export interface ITableSettingsType {
    onClosePopup: () => void;
}
export interface ITableSettingsCol extends TableColProps {
    id: string;
    depth: number;
}
export declare const TableSettings: ({ onClosePopup }: ITableSettingsType) => import("react/jsx-runtime").JSX.Element;
