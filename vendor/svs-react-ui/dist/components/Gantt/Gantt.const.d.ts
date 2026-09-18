export declare const intervalItems: readonly [{
    readonly value: "00:00:15";
    readonly label: "часы";
    readonly description: "hours";
    readonly countingFromCenter: true;
    readonly defaultNumberOfIntervals: 24;
}, {
    readonly value: "00:01:00";
    readonly label: "день";
    readonly description: "day";
    readonly countingFromCenter: true;
    readonly defaultNumberOfIntervals: 24;
}, {
    readonly value: "00:24:00";
    readonly label: "неделя";
    readonly description: "week";
    readonly countingFromCenter: false;
    readonly defaultNumberOfIntervals: 28;
}, {
    readonly value: "01:00:00";
    readonly label: "месяц";
    readonly description: "month";
    readonly countingFromCenter: false;
    readonly defaultNumberOfIntervals: 31;
}, {
    readonly value: "07:00:00";
    readonly label: "год";
    readonly description: "year";
    readonly countingFromCenter: false;
    readonly defaultNumberOfIntervals: 52;
}];
export type IntervalItem = (typeof intervalItems)[number];
export type IntervalOption = IntervalItem['description'];
export declare const weekDays: readonly ["Вс", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб"];
export declare const months: readonly ["Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"];
export declare const ganttArrowDimensions: {
    readonly pointerWidth: 10;
    readonly pointerHeight: 10;
    readonly tailWidth: 20;
};
export declare const intervalsOffsetStep = 4;
export declare const millisecondsInMinute: number;
export declare const millisecondsInHour: number;
export declare const millisecondsInDay: number;
export declare const millisecondsInWeek: number;
export declare const buttonStyleType = "link";
export type GanttBarColors = 'processing' | 'warning' | 'success' | 'error' | 'secondary' | 'tertiary' | 'quaternary' | 'extra' | 'additional';
export declare const dateKeys: readonly ["start", "end", "actualStart", "actualEnd"];
export declare const ganttClassName = "svs-gantt";
export declare const timeScaleClassName = "svs-gantt__time-scale";
export declare const timeIntervalClassName = "svs-gantt__time-interval";
export declare const barClassName = "svs-gantt__bar";
export declare const barsListClassName = "svs-gantt__bars-list";
export declare const contentClass = "svs-gantt__content";
export declare const legendClass = "svs-gantt__legend";
