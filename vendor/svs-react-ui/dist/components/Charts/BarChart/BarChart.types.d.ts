import { ChartCategorizedData, ChartGridSettings, ChartProps, ChartSeries, ChartThresholdTypes } from '../charts.types';
export type BarChartData = ChartCategorizedData[];
export type BarChartTypes = 'standard' | 'stacked';
export interface BarChartProps extends ChartProps, ChartThresholdTypes, ChartGridSettings {
    /**
     * Массив данных с категориями (группами баров).
     *
     * Следующие поля являются зарезервированными:
     *
     * @property {string} categoryName - Название категории (используется для оси X)
     * @property {number} thresholdValue - Значение пороговой линии, отображаемой поверх группы, необязательное
     * @property {string} thresholdColor - Цвет пороговой линии (по умолчанию — красный), необязательное
     * @property {string} thresholdLabel - Текстовая подпись пороговой линии, необязательное
     *
     * @example
     * data: [
     *   {
     *     categoryName: 'Категория 1',
     *     revenue: 120,
     *     cost: 90,
     *     thresholdValue: 100,
     *     thresholdColor: '#ff0000',
     *     thresholdLabel: 'Целевой уровень'
     *   },
     *   {
     *     categoryName: 'Категория 1',
     *     revenue: 120,
     *     cost: 90,
     *   },
     *   ...
     * ]
     */
    data: BarChartData;
    barsPadding?: number;
    groupsPadding?: number;
    type?: BarChartTypes;
    series?: ChartSeries[];
    excessMultiplier?: number;
    renderAxisXValue?: (d: any) => string;
    renderAxisYValue?: (d: any) => string;
    showBarValues?: boolean;
    showBarValuesCentered?: boolean;
}
