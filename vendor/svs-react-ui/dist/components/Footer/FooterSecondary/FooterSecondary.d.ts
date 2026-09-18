import { HTMLAttributes } from 'react';
import { ContactItem, LinkItem, SocialLink, SocialLinkAlternate } from '../types';
import '../Common.scss';
import './FooterSecondary.scss';
export interface FooterSecondaryProps extends HTMLAttributes<HTMLDivElement> {
    contacts: ContactItem[];
    links: LinkItem[];
    socialLinks: Array<SocialLink | SocialLinkAlternate>;
    copyrightText: string;
}
export declare const FooterSecondary: ({ contacts, links, socialLinks, copyrightText, className, style, ...rest }: FooterSecondaryProps) => import("react/jsx-runtime").JSX.Element;
