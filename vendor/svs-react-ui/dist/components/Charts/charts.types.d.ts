import { HTMLAttributes } from 'react';
export type ChartColors = 'success' | 'processing' | 'default' | 'error' | 'warning' | 'secondary' | 'tertiary' | 'quaternary' | 'extra' | 'additionally';
export interface ChartMargin {
    top?: number;
    right?: number;
    bottom?: number;
    left?: number;
}
export interface ChartSeries {
    fieldName: string;
    label?: string;
    color?: string;
    barValueColor?: string;
}
export interface ChartThresholdTypes {
    /** Установка значения пороговой линии, которое активирует ее появление  */
    thresholdValue?: number;
    /** Возможность задать цвет для пороговой линии */
    thresholdColor?: string;
    /** Возможность задать подпись для пороговой линии */
    thresholdLabel?: string;
}
export interface ChartCategorizedData extends ChartThresholdTypes {
    [key: string]: string | number | undefined;
}
export interface ChartProps extends HTMLAttributes<HTMLDivElement> {
    width: number;
    height: number;
    showLegend?: boolean;
    rotated?: boolean;
    categoryField?: string;
    series?: ChartSeries[];
    margin?: ChartMargin;
}
export interface ChartGridSettings {
    /**
     * Показать сетку по оси XXXX
     * @default false
     */
    showGridX?: boolean;
    /**
     * Показать сетку по оси Y
     * @default false
     */
    showGridY?: boolean;
}
