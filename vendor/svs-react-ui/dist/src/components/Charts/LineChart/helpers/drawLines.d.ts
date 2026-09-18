import { Selection } from 'd3';
import { ChartMargin } from '../../charts.types';
import { LineChartProps } from '../LineChart.types';
interface DrawLinesProps extends LineChartProps {
    svg: Selection<SVGSVGElement, unknown, null, undefined>;
    styles: CSSStyleDeclaration;
    margin: Required<ChartMargin>;
    renderAxisXValue?: (d: any) => string;
    renderAxisYValue?: (d: any) => string;
    lineChartClass: string;
}
export declare function drawLines({ width, height, data, svg, styles, margin, categoryField, series: lineOptions, type, curve, renderAxisXValue, renderAxisYValue, lineChartClass, showGridX, showGridY }: DrawLinesProps): void;
export {};
