import { HTMLAttributes, ReactNode } from 'react';
import './TabbarButton.scss';
interface TabBarButtonProps extends HTMLAttributes<HTMLButtonElement> {
    icon?: (props: any) => ReactNode | Promise<ReactNode>;
    counter?: number;
}
export declare const TabBarButton: ({ icon, counter, className, children, ...rest }: TabBarButtonProps) => import("react/jsx-runtime").JSX.Element;
export {};
