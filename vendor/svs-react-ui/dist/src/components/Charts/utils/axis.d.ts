import * as d3 from 'd3';
import { Selection } from 'd3';
import { ChartMargin } from '../charts.types';
export declare function drawAxis(settings: {
    margin: Required<ChartMargin>;
    size: {
        width: number;
        height: number;
    };
    svg: Selection<SVGSVGElement, unknown, null, undefined>;
    yDomain: number[] | string[];
    variant: string;
    xDomain: number[] | string[];
    styles: CSSStyleDeclaration;
    renderAxisXValue?: (d: any) => string;
    renderAxisYValue?: (d: any) => string;
}): {
    x: d3.ScaleLinear<number, number, never> | d3.ScaleBand<string>;
    y: d3.ScaleLinear<number, number, never> | d3.ScaleBand<string>;
};
