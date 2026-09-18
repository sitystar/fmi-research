import { CalendarProps } from './Calendar';
interface RenderDaysProps extends Pick<CalendarProps, 'disabledDate'> {
    month: number;
    year: number;
    selected: null | Date;
    previouslySelected: null | Date;
    onSelectDay: (d: Date) => void;
    currentDay: number;
    currentMonth: number;
    currentYear: number;
}
declare const RenderDays: ({ month, year, selected, previouslySelected, onSelectDay, currentDay, currentMonth, currentYear, disabledDate }: RenderDaysProps) => import("react/jsx-runtime").JSX.Element;
export default RenderDays;
