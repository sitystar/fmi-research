import { ButtonProps } from '../../../Button';
import './ActionsPanel.scss';
import { TableProps } from '../..';
import { DropdownItemType } from '../../../Dropdown';
export interface ActionsPanelButtonProps extends Omit<ButtonProps, 'value'>, Omit<DropdownItemType, 'label'> {
    label?: string;
    onClick?: () => void;
}
export interface HeaderActionsPanelProps extends Pick<TableProps, 'title' | 'multiple'> {
    buttons?: ActionsPanelButtonProps[];
    count: number;
    overlay?: boolean;
}
export declare const ActionsPanel: ({ buttons, count, overlay, multiple }: HeaderActionsPanelProps) => import("react/jsx-runtime").JSX.Element;
