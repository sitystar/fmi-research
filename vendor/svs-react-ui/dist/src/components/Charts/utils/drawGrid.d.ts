import * as d3 from 'd3';
import { Selection } from 'd3';
export interface DrawGridParams {
    svg: Selection<SVGSVGElement, unknown, null, undefined>;
    x: d3.ScaleLinear<number, number, never> | d3.ScaleBand<string>;
    y: d3.ScaleLinear<number, number, never> | d3.ScaleBand<string>;
    width: number;
    height: number;
    margin: {
        top: number;
        right: number;
        bottom: number;
        left: number;
    };
    showGridX: boolean;
    showGridY: boolean;
    className: string;
}
export declare function drawGrid({ svg, x, y, width, height, margin, showGridX, showGridY, className }: DrawGridParams): void;
