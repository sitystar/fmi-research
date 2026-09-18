import { ChartColors, ChartGridSettings, ChartProps } from '../charts.types';
export type DensityChartTypes = 'standard';
export type DensityChartData = number;
export interface DensityChartProps extends ChartProps, ChartGridSettings {
    data: DensityChartData[];
    barsPadding?: number;
    excessMultiplier?: number;
    type?: DensityChartTypes;
    thresholds?: number;
    color?: ChartColors;
    customColor?: string;
}
