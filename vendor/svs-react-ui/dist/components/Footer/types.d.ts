import { ReactNode } from 'react';
import { SOCIAL_LINKS } from './constants';
export type FooterTypes = 'primary' | 'secondary' | 'extra';
export interface Language {
    key: string;
    value: string;
}
export interface LinkItem {
    text: string;
    url?: string;
    children?: ReactNode;
    external?: boolean;
}
export type ContactItem = Omit<LinkItem, 'external'> & {
    option?: string;
    type?: string;
};
export interface SocialLink {
    type: (typeof SOCIAL_LINKS)[number];
    url: string;
}
export interface SocialLinkAlternate {
    url: string;
    icon?: ReactNode;
    title?: string;
}
