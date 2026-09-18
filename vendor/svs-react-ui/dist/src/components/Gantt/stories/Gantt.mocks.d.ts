import { IconsNameType } from '../../SvgIcon';
import { TableDataValues } from '~/components/Table';
interface ContentProps {
    iconTitle?: IconsNameType;
    title?: string;
    iconOption?: IconsNameType;
    option?: string;
}
export declare const MockContent: ({ iconTitle, title, iconOption, option }: ContentProps) => import("react/jsx-runtime").JSX.Element;
export declare const mockAfterBarContent: import("react/jsx-runtime").JSX.Element;
export declare const RenderProgressBar: (value: TableDataValues) => import("react/jsx-runtime").JSX.Element;
export {};
