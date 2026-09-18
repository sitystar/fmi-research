import './PieChart.scss';
import { PieChartItem, PieChartTypes } from '..';
import { ChartProps } from '../charts.types';
export interface PieChartProps extends ChartProps {
    data: PieChartItem[];
    type?: PieChartTypes;
    legendPosition?: 'top' | 'bottom' | 'right' | 'left';
    showLegend?: boolean;
    innerRadiusScale?: number;
    hover?: boolean;
    hoverWithLegend?: boolean;
    tooltipVisible?: boolean;
}
export declare const PieChart: ({ data, legendPosition, showLegend, type, width, height, margin, innerRadiusScale, hover, hoverWithLegend, tooltipVisible, className, style, ...rest }: PieChartProps) => import("react/jsx-runtime").JSX.Element;
