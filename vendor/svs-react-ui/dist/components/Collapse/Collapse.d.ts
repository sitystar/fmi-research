import { CSSProperties, ReactNode } from 'react';
import './Collapse.scss';
type KeyType = string | number;
export type CollapseItem = {
    key?: KeyType;
    label?: ReactNode;
    content?: ReactNode;
    rightContent?: ReactNode;
};
type CustomIconType = {
    close?: ReactNode;
    open?: ReactNode;
};
export interface CollapseProps {
    /**
     * Список элементов коллапса:
     *
     *     {
     *       key?: string | number -  ключ элемента
     *       label?: ReactNode - заголовок хидера элемента
     *       content?: ReactNode - контент для показа
     *       rightContent?: ReactNode - контент в правой части хидера
     *     }
     */
    items: CollapseItem[];
    /**
     * Позволяет сворачивать все элементы при раскрытии одного
     *
     * @default false
     */
    accordion?: boolean;
    /**
     * Добавляет нижнюю границу к элементу. Не работает со стилем ghost
     *
     * @default false
     */
    bordered?: boolean;
    /**
     * Вариант отображения анимарованой стрелки: right (открытый элемент - стрелка право, закрытый - вниз), bottom (открытый элемент - стрелка вниз, закрытый - вверх)
     *
     * @default 'right'
     */
    iconType?: 'bottom' | 'right';
    /**
     * Позволяет добавить кастомный вариант иконки (для закрытого и открытого типа), close|open
     */
    icon?: CustomIconType;
    /**
     * Тригер открытия элемента - по хидеру или иконке: header|icon
     *
     * @default 'header'
     */
    trigger?: 'header' | 'icon';
    /**
     * Массив из ключей элементов, либо их индексов, открытых по-умолчанию
     *
     * Если у элемента задан `key`, то открытие элемента по-умолчанию будет работать только по ключу, а не по индексу
     */
    defaultExpanded?: KeyType[];
    className?: string;
    style?: CSSProperties;
    /**
     * Событие открытия/закрытия элемента. Возврашает ключ или порядковый номер элемента
     */
    onChange?: (key: KeyType) => void;
    /**
     * Событие нажатия на кнопку Подробнее в теле элемента
     */
    onClickButton?: (item: CollapseItem) => void;
    /**
     * Возможность отображения кнопки Подробнее
     *
     * @default false
     */
    hasButton?: boolean;
    /**
     * Ширина коллапса. Принимает строку или число
     */
    width?: string | number;
    /**
     * Стиль отображения колапса
     *
     * @default 'primary'
     */
    styleType?: 'primary' | 'secondary' | 'ghost';
    /**
     * Кастомный отступ между элементами. Принимает число. По умолчанию есть только в стиле ghost
     */
    gap?: number;
}
export declare const Collapse: ({ items, defaultExpanded, accordion, bordered, iconType, trigger, onChange, onClickButton, hasButton, icon, className, style, width, styleType, gap }: CollapseProps) => import("react/jsx-runtime").JSX.Element;
export {};
