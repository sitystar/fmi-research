import { ReactNode } from 'react';
type PortalProps = {
    children: ReactNode;
    element?: HTMLElement;
};
export declare const Portal: ({ children, element }: PortalProps) => import("react").ReactPortal | null;
export {};
