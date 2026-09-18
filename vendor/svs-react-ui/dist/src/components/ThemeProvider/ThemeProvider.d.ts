import { HTMLAttributes } from 'react';
import { RESPONSIVE_FILENAME, ThemeColorsType } from '../../constantsAndTypes';
import { StringObject } from '../../../types/stringObject';
import { IconPack } from '../../icons/iconTypes';
export declare enum DEFAULT_THEMES {
    DEFAULT = "default",
    ICK = "ick"
}
export type ResponsiveType = Record<string, StringObject>;
export type ThemeType = {
    themeColors?: Partial<Record<ThemeColorsType, StringObject>>;
    [RESPONSIVE_FILENAME]?: ResponsiveType;
};
export interface ThemeProviderProps extends HTMLAttributes<HTMLDivElement> {
    /**
     * Тема оформления, содержащая набор токенов и их значений в нужной структуре.
     *
     * Темы, поставляемые с библиотекой:
     * - `DEFAULT_THEME` - тема по умолчанию
     * - `ICK_THEME` - тема "ИЦК"
     *
     * Также можно использовать свою тему, передав объект `ThemeType`, описывающий переменные темы.
     *
     * @default DEFAULT_THEME
     */
    theme: ThemeType;
    /**
     * Включает тёмную тему.
     *
     * Если установлено `true`, применяются CSS-переменные, соответствующие тёмной теме `theme.themeColors.dark`.
     * Если `false`, используются CSS-переменные светлой темы `theme.themeColors.light`.
     *
     * @default false
     */
    dark?: boolean;
    /**
     * Определяет область применения темы.
     *
     * Если `true`, CSS-переменные темы применяются только внутри `ThemeProvider`.
     * Если `false`, переменные применяются глобально - на уровне `:root`.
     *
     * @default false
     */
    scoped?: boolean;
    /**
     * Иконки, используемые в компонентах библиотеки
     *
     * Библиотека поддерживает 2 набора иконок, используемых в компонентах:
     * - `DEFAULT_PACK` - иконки по умолчанию
     * - `ICK_PACK` - иконки ИЦК
     *
     * Также можно передать свои иконки, полностью или частично переопределяя стандартные.
     * Для этого нужно передать объект `IconPack`
     *
     * @default DEFAULT_PACK
     */
    iconPack?: IconPack;
}
export declare const ThemeProvider: ({ children, theme, dark, scoped, iconPack, ...rest }: ThemeProviderProps) => import("react/jsx-runtime").JSX.Element;
