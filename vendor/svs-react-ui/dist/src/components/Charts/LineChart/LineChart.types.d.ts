import { ChartGridSettings, ChartProps, ChartSeries } from '../charts.types';
export type LineChartData = {
    [key: string]: string | number;
};
export type LineChartTypes = 'line' | 'spline';
export interface LineChartProps extends Omit<ChartProps, 'color' | 'rotated'>, ChartGridSettings {
    data: LineChartData[];
    showLegend?: boolean;
    type?: LineChartTypes;
    categoryField?: string;
    series?: ChartSeries[];
    curve?: number;
    renderAxisXValue?: (d: any) => string;
    renderAxisYValue?: (d: any) => string;
}
