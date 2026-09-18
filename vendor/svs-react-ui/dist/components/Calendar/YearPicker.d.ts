export interface YearPickerHeaderProps {
    year: number;
    onPrevDecade: () => void;
    onNextDecade: () => void;
}
export interface YearPickerProps {
    year: number;
    onYearSelect: (year: number) => void;
}
export declare const YearPickerHeader: ({ year, onPrevDecade, onNextDecade }: YearPickerHeaderProps) => import("react/jsx-runtime").JSX.Element;
export declare const YearPicker: ({ year, onYearSelect }: YearPickerProps) => import("react/jsx-runtime").JSX.Element;
