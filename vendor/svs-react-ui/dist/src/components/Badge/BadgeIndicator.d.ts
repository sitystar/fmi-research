import './BadgeIndicator.scss';
import { BadgeIndicatorName, BadgeProps } from './Badge';
export interface BadgeIndicatorProps extends Pick<BadgeProps, 'color' | 'status'> {
    indicator: BadgeIndicatorName;
}
export declare const BadgeIndicator: ({ status, indicator, color }: BadgeIndicatorProps) => import("react/jsx-runtime").JSX.Element | null;
