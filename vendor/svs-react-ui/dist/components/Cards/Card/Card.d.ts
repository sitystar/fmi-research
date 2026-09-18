import { CSSProperties, HTMLAttributes, ReactNode, FC, MouseEvent } from 'react';
import './Card.scss';
export interface CardProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onClick'> {
    className?: string;
    style?: CSSProperties;
    images: string[];
    imageElement?: ReactNode | FC;
    price?: number;
    oldPrice?: number;
    currency?: string;
    title?: string;
    shopTitle?: string;
    isFavoriteShop?: boolean;
    isFavorite?: boolean;
    needFavorite?: boolean;
    submitText?: string;
    addedToCartSubmitText?: string;
    isAddedToCart?: boolean;
    discount?: number;
    disableTitleTooltip?: boolean;
    footer?: ReactNode | null;
    needFooter?: boolean;
    onClick?: (event?: MouseEvent<HTMLButtonElement>) => void;
    onFavoriteClick?: () => void;
    disableCartButton?: boolean;
    product?: {
        href?: string;
        onClick?: (event: MouseEvent<HTMLAnchorElement>, link?: string) => void;
    };
    shop?: {
        href?: string;
        onClick?: (event: MouseEvent<HTMLAnchorElement>, link?: string) => void;
    };
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте product.onClick
     */
    onTitleClick?: (event?: MouseEvent<HTMLDivElement>) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте shop.onClick
     */
    onShopTitleClick?: (event?: MouseEvent<HTMLDivElement>) => void;
}
export declare const Card: import("react").MemoExoticComponent<({ className, style, price, oldPrice, currency, images, imageElement, title, shopTitle, isFavoriteShop, isFavorite, isAddedToCart, submitText, addedToCartSubmitText, discount, onClick, disableTitleTooltip, onFavoriteClick, footer, needFooter, needFavorite, disableCartButton, product, shop, onTitleClick, onShopTitleClick, ...rest }: CardProps) => import("react/jsx-runtime").JSX.Element>;
