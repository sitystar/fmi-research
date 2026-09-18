import './Legend.scss';
import { ChartSeries } from '../charts.types';
interface legendValuesData extends Omit<ChartSeries, 'fieldName'> {
}
export type ChartLegend = {
    data: legendValuesData[];
    hoverWithLegend?: boolean;
    position?: 'top' | 'bottom' | 'right' | 'left';
    highlighted?: (index: number) => boolean;
    onLegendItemEnter?: (index: number) => void;
    onLegendItemLeave?: () => void;
};
export declare const Legend: ({ data, hoverWithLegend, position, highlighted, onLegendItemEnter, onLegendItemLeave }: ChartLegend) => import("react/jsx-runtime").JSX.Element;
export {};
