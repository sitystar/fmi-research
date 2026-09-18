import { ReactNode, HTMLAttributes } from 'react';
import { Language, ContactItem, LinkItem, SocialLink, SocialLinkAlternate } from '../types';
import '../Common.scss';
import './FooterPrimary.scss';
export interface FooterPrimaryProps extends HTMLAttributes<HTMLDivElement> {
    contacts: ContactItem[];
    links: LinkItem[];
    subscribeText: string;
    subscribeCallback: () => void;
    subscribeOption?: string;
    socialLinks: Array<SocialLink | SocialLinkAlternate>;
    socialLinksOption?: string;
    languages: Language[];
    onChangeLanguage?: (value: string) => void;
    copyrightText: string;
    politicsText: string;
    politicsUrl: string;
    yandexPoliticsText: string;
    yandexPoliticsLinkText: string;
    yandexPoliticsUrl: string;
    cookieSettingsText: string;
    cookieSettingsUrl: string;
    titleElement?: ReactNode;
}
export declare const FOOTER_CLASS_NAME = "svs-footer";
export declare const FooterPrimary: ({ titleElement, contacts, links, subscribeText, subscribeCallback, subscribeOption, socialLinks, socialLinksOption, languages, onChangeLanguage, copyrightText, politicsText, politicsUrl, yandexPoliticsText, yandexPoliticsLinkText, yandexPoliticsUrl, cookieSettingsText, cookieSettingsUrl, className, style, ...rest }: FooterPrimaryProps) => import("react/jsx-runtime").JSX.Element;
