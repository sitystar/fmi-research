export interface RenderHeaderProps {
    onPrevMonth: () => void;
    onNextMonth: () => void;
    month: number;
    year: number;
    onMonthClick: () => void;
    onYearClick: () => void;
}
declare const RenderHeader: ({ month, year, onPrevMonth, onNextMonth, onMonthClick, onYearClick }: RenderHeaderProps) => import("react/jsx-runtime").JSX.Element;
export default RenderHeader;
