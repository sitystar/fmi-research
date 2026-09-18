import { CSSProperties, HTMLAttributes, ReactNode, FC, MouseEvent } from 'react';
import './CardSelectable.scss';
export interface CardSelectableProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onClick'> {
    className?: string;
    style?: CSSProperties;
    images: string[];
    imageElement?: ReactNode | FC;
    price?: number;
    oldPrice?: number;
    itemPriceWithNDS: number;
    currency?: string;
    title?: string;
    isFavorite?: boolean;
    needFavorite?: boolean;
    buyButtonText?: string;
    discount?: number;
    onBuyClick?: (event?: MouseEvent<HTMLButtonElement>) => void;
    onLinkProductClick?: (event: MouseEvent<HTMLAnchorElement>, linkProduct?: string) => void;
    onFavoriteClick?: () => void;
    stepperValue?: number;
    onStepperPlusClick?: () => void;
    onStepperMinusClick?: () => void;
    onStepperEdit?: (value: string) => void;
    inStockValue?: number;
    minimumQuantity?: number;
    units?: string;
    onDeleteClick?: () => void;
    onChangeCheck?: (value: boolean) => void;
    disableCard?: boolean;
    needDeleteButton?: boolean;
    isCheck?: boolean;
    disableCardText?: string;
    article: string;
    needBuyButton?: boolean;
    needCheckbox?: boolean;
    availabilityWarning?: boolean;
    availabilityWarningText?: string;
    disableBuyButton?: boolean;
    disableStepper?: boolean;
    linkProduct?: string;
    /**
     * @deprecated
     * Будет удалено в мажорной версии. Вместо этого свойства используйте onLinkProductClick
     */
    onTitleClick?: (event?: MouseEvent<HTMLDivElement>) => void;
}
export declare const CardSelectable: ({ className, price, oldPrice, itemPriceWithNDS, currency, images, imageElement, title, isFavorite, discount, onBuyClick, onLinkProductClick, onFavoriteClick, needFavorite, stepperValue, onStepperPlusClick, onStepperMinusClick, onStepperEdit, inStockValue, units, minimumQuantity, onDeleteClick, onChangeCheck, disableCard, needDeleteButton, isCheck, buyButtonText, disableCardText, article, needBuyButton, needCheckbox, availabilityWarning, availabilityWarningText, disableBuyButton, disableStepper, linkProduct, onTitleClick, ...rest }: CardSelectableProps) => import("react/jsx-runtime").JSX.Element;
