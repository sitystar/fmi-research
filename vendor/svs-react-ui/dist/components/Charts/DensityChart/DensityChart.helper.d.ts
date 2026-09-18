import { Selection } from 'd3';
import { ChartMargin } from '../charts.types';
import { DensityChartProps } from './DensityChart.types';
export declare function drawHistogram({ width, height, data, barsPadding, excessMultiplier, svg, styles, margin, color, customColor, densityChartClass, rotated, thresholds, showGridX, showGridY }: DensityChartProps & {
    svg: Selection<SVGSVGElement, unknown, null, undefined>;
    styles: CSSStyleDeclaration;
    margin: Required<ChartMargin>;
    densityChartClass: string;
}): void;
