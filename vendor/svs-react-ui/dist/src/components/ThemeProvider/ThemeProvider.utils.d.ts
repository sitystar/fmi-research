import { ThemeColorsType } from '../../constantsAndTypes';
import { ThemeType } from './ThemeProvider';
export declare const generateCSSVariables: (variables: Record<string, string>) => string;
export declare const createCSS: (data: ThemeType, themeColor: ThemeColorsType, uniqId: string, scoped?: boolean) => [string | undefined, string];
