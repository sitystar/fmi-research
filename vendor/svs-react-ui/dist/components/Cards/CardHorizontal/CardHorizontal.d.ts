import { CSSProperties, HTMLAttributes, ReactNode, FC, MouseEvent } from 'react';
import './CardHorizontal.scss';
export interface HorizontalCardProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onClick'> {
    className?: string;
    style?: CSSProperties;
    images: string[];
    imageElement?: ReactNode | FC;
    price?: number;
    oldPrice?: number;
    itemPriceWithNDS: number;
    currency?: string;
    title?: string;
    shopTitle?: string;
    isFavorite?: boolean;
    needFavorite?: boolean;
    submitText?: string;
    addedToCartSubmitText?: string;
    isAddedToCart?: boolean;
    discount?: number;
    onClick?: (event?: MouseEvent<HTMLButtonElement>) => void;
    onLinkProductClick?: (event: MouseEvent<HTMLAnchorElement>, linkProduct?: string) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте onLinkProductClick
     */
    onTitleClick?: (event: MouseEvent<HTMLDivElement>) => void;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте onLinkShopClick
     */
    onShopTitleClick?: (event?: MouseEvent<HTMLDivElement>) => void;
    onLinkShopClick?: (event: MouseEvent<HTMLAnchorElement>, linkShop?: string) => void;
    onFavoriteClick?: () => void;
    stepperValue?: number;
    onStepperPlusClick?: () => void;
    onStepperMinusClick?: () => void;
    onStepperEdit?: () => void;
    inStockValue?: number;
    minimumQuantity?: number;
    units?: string;
    productCode?: number;
    disableCartButton?: boolean;
    disableStepper?: boolean;
    linkProduct?: string;
    linkShop?: string;
    comments?: string;
}
export declare const CardHorizontal: ({ className, price, oldPrice, itemPriceWithNDS, currency, images, imageElement, title, shopTitle, isFavorite, isAddedToCart, submitText, addedToCartSubmitText, discount, onClick, onLinkProductClick, onLinkShopClick, onFavoriteClick, needFavorite, stepperValue, onStepperPlusClick, onStepperMinusClick, onStepperEdit, inStockValue, units, minimumQuantity, productCode, disableCartButton, disableStepper, linkProduct, linkShop, onTitleClick, onShopTitleClick, comments, ...rest }: HorizontalCardProps) => import("react/jsx-runtime").JSX.Element;
