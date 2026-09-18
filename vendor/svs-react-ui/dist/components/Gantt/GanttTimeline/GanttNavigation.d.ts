import { ButtonStyleType } from '../../Button';
export declare enum GanttNavigationDirections {
    'back' = 0,
    'forward' = 1,
    'current' = 2
}
type GanttNavigationProps = {
    onHandleMoveTimetable: (direction: GanttNavigationDirections) => void;
    buttonStyleType: ButtonStyleType;
};
export declare const GanttNavigation: ({ onHandleMoveTimetable, buttonStyleType }: GanttNavigationProps) => import("react/jsx-runtime").JSX.Element;
export {};
