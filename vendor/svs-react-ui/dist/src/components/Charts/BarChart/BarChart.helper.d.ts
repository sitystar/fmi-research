import { Selection } from 'd3';
import { BarChartProps } from './BarChart.types';
import { ChartMargin, ChartSeries } from '../charts.types';
interface DrawCategorisedProps extends BarChartProps {
    svg: Selection<SVGSVGElement, unknown, null, undefined>;
    styles: CSSStyleDeclaration;
    margin: Required<ChartMargin>;
    barChartClass: string;
    series: ChartSeries[];
}
export declare function drawCategorised({ width, height, data, barsPadding, groupsPadding, excessMultiplier, svg, styles, margin, barChartClass, rotated, categoryField, series, type, renderAxisXValue, renderAxisYValue, thresholdValue, thresholdColor, thresholdLabel, showBarValues, showBarValuesCentered, showGridX, showGridY }: DrawCategorisedProps): void;
export {};
