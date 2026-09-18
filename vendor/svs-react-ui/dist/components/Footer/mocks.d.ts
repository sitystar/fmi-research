export declare const footerPrimaryMocks: {
    contacts: ({
        text: string;
        url: string;
        option: string;
        children?: undefined;
    } | {
        text: string;
        url: string;
        option?: undefined;
        children?: undefined;
    } | {
        text: string;
        children: import("react/jsx-runtime").JSX.Element;
        url?: undefined;
        option?: undefined;
    })[];
    links: ({
        text: string;
        url: string;
        external: boolean;
    } | {
        text: string;
        url: string;
        external?: undefined;
    })[];
    subscribeText: string;
    subscribeCallback: () => void;
    subscribeOption: string;
    socialLinks: {
        type: string;
        url: string;
    }[];
    socialLinksOption: string;
    languages: {
        key: string;
        value: string;
    }[];
    onChangeLanguage: (value: string) => void;
    copyrightText: string;
    politicsText: string;
    politicsUrl: string;
    yandexPoliticsText: string;
    yandexPoliticsLinkText: string;
    yandexPoliticsUrl: string;
    cookieSettingsText: string;
    cookieSettingsUrl: string;
};
export declare const footerSecondaryMocks: {
    contacts: {
        text: string;
        url: string;
        type: string;
    }[];
    links: ({
        text: string;
        url: string;
        external?: undefined;
    } | {
        text: string;
        url: string;
        external: boolean;
    })[];
    socialLinks: ({
        url: string;
        title: string;
        type?: undefined;
    } | {
        type: string;
        url: string;
        title?: undefined;
    })[];
    copyrightText: string;
};
