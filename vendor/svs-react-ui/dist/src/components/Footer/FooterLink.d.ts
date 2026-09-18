import { LinkItem } from './types';
type FooterLinkProps = LinkItem & {
    className?: string;
};
export declare const FooterLink: ({ text, external, url, children, className }: FooterLinkProps) => import("react/jsx-runtime").JSX.Element;
export {};
