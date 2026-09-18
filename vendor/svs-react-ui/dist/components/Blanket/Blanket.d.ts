import { ReactNode, CSSProperties } from 'react';
import './Blanket.scss';
export interface BlanketProps {
    active?: boolean;
    disableAnimation?: boolean;
    onClick?: () => void;
    style?: CSSProperties;
    className?: string;
    children?: ReactNode;
    absolute?: boolean;
    /**
     * Стилевое оформление blanket:
     *
     *  - primary - темный фон
     *  - secondary - светлый фон
     *  @default primary
     */
    styleType?: 'primary' | 'secondary';
}
export declare const Blanket: import("react").ForwardRefExoticComponent<BlanketProps & import("react").RefAttributes<HTMLDivElement>>;
