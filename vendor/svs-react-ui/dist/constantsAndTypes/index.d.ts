export declare const THEME_COLORS: readonly ["light", "dark"];
export declare const RESPONSIVE_FILENAME = "responsive";
export declare const TOKENS_FILENAME = "tokens";
export type ThemeColorsType = (typeof THEME_COLORS)[number];
export type TokenFileNamesType = ThemeColorsType | typeof RESPONSIVE_FILENAME;
export type CSSFilesMapType = Record<TokenFileNamesType, string>;
export type AnyObject = Record<PropertyKey, any>;
