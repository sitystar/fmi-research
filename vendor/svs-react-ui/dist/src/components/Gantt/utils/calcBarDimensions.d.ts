import { GanttTimelineItem, GanttTimelineMilestone, GanttTimelineProjectItem, GanttTimelineCustomItem } from '../Gantt.types';
import { LayoutTimeTable } from '../GanttTimeline';
export interface barCoords {
    left: number;
    minStartDate: number;
    maxEndDate: number;
    barWidth: number;
}
/**
 * @description Функция принимает (1) объект task c данными для отрисовки бара,
 * (2) объект layoutTimeTable с данными о времени начала и окончания таймлайна,
 * (3) scale масштаб [px/мс]
 * и возвращет объект, содержащий данные для построения бара:
 * коодинату начала бара, его ширину, время начала и окончания.
 * @param task объект c данными для отрисовки бара,
 * @param layoutTimeTable объект с данными о времени начала и окончания таймлайна,
 * @param scale масштаб временной шкалы [px/мс]
 * @returns  возвращет объект с полями
 *  left:number - координата левого края бара относительно начала таймлайна (px),
 *  barWidth:number - ширина бара (px),
 *  minStartDate:number - начало бара = min из startDate и actualStart,
 *  maxEndDate:number - окончание бара = max из из endDate и actualEnd
 */
export declare const calcBarDimensions: (task: GanttTimelineItem | GanttTimelineMilestone | GanttTimelineProjectItem | GanttTimelineCustomItem, layoutTimeTable: LayoutTimeTable, scale: number) => barCoords;
