import './Badge.scss';
import { ReactNode, HTMLAttributes } from 'react';
export type BadgeStatus = 'success' | 'processing' | 'default' | 'error' | 'warning' | 'secondary' | 'tertiary' | 'quaternary' | 'extra' | 'additionally';
export type BadgeIndicatorName = 'dot' | 'dot-empty' | 'square' | 'square-empty' | 'line' | 'line-dotted' | 'diagonal-lines';
export interface BadgeProps extends HTMLAttributes<HTMLDivElement> {
    /**
     * Цветовой вариант `Badge`.
     *
     * @default default
     */
    status: BadgeStatus;
    /**
     * Содержимое внутри `Badge`.
     */
    count?: ReactNode;
    /**
     * Дочерний элемент относительно которого выводится `Badge`.
     */
    children?: ReactNode;
    /**
     * Отображение `Badge` в виде точки.
     *
     * @default false
     * @deprecated
     * Будет удалено в мажорной версии.
     * Вместо этого свойства используйте `indicator` со значением `"dot"`.
     */
    dot?: boolean;
    /**
     * Максимальное числовое значение, после которого показывается `overflowCount+`.
     */
    overflowCount?: number;
    /**
     * Отображать 0, если `count` отсутствует или равен 0.
     */
    showZero?: boolean;
    /**
     * Текст, отображаемый справа от бейджа.
     * При использовании отменяет отображение `children`.
     */
    text?: ReactNode;
    /**
     * Размер `Badge`.
     *
     * @default s
     */
    size?: 's' | 'm';
    /**
     * Собственный цвет заливки `Badge`.
     */
    color?: string;
    /**
     * Смещение `Badge` по горизонтали и вертикали.
     *
     * Формат: [смещение по X, смещение по Y]
     */
    offset?: [number, number];
    /**
     * Вид индикатора.
     *
     * Если задан, `Badge` отображается в виде соответствующего индикатора, а содержимое скрывается.
     */
    indicator?: BadgeIndicatorName;
}
export declare const Badge: ({ status, count, dot, children, className, overflowCount, text, showZero, size, color, offset, style, indicator, ...rest }: BadgeProps) => import("react/jsx-runtime").JSX.Element;
