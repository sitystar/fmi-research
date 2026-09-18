import { SocialLink, SocialLinkAlternate } from './types';
interface SocialLinksProps {
    items: Array<SocialLink | SocialLinkAlternate>;
    className?: string;
}
export declare const SocialLinks: ({ items, className }: SocialLinksProps) => import("react/jsx-runtime").JSX.Element;
export {};
