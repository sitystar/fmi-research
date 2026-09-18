export interface MonthPickerHeaderProps {
    year: number;
    onPrevYear: () => void;
    onNextYear: () => void;
    onYearClick: () => void;
}
export interface MonthPickerProps {
    month: number;
    onMonthSelect: (month: number) => void;
}
export declare const MonthPickerHeader: ({ year, onPrevYear, onNextYear, onYearClick }: MonthPickerHeaderProps) => import("react/jsx-runtime").JSX.Element;
export declare const MonthPicker: ({ month, onMonthSelect }: MonthPickerProps) => import("react/jsx-runtime").JSX.Element;
