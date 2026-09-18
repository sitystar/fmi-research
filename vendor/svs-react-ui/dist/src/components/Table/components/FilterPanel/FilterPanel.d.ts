import './FilterPanel.scss';
import { TableFilterPanelSettings, TableProps } from '~/components/Table';
interface FilterPanelProps extends Pick<TableProps, 'onConfirmFilter'> {
    filterPanelSettings?: TableFilterPanelSettings;
}
export declare const FilterPanel: ({ onConfirmFilter, filterPanelSettings }: FilterPanelProps) => import("react/jsx-runtime").JSX.Element | null;
export {};
