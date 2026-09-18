import { ThemeProviderProps } from './ThemeProvider';
export interface DefaultThemeProviderProps extends Omit<ThemeProviderProps, 'theme'> {
}
export declare const DefaultThemeProvider: ({ children, ...rest }: DefaultThemeProviderProps) => import("react/jsx-runtime").JSX.Element;
