import './InlineMessage.scss';
import { HTMLAttributes, ReactNode } from 'react';
export type InlineMessageStatus = 'default' | 'warning' | 'danger' | 'simple' | string;
export type IconStatus = 'warning' | 'error' | 'success' | 'info' | ReactNode;
/**
 * @deprecated
 * Данный компонент является легаси. В будущих мажорных релизах компонент InlineMessage будет удален, а InlineMessage2 будет переименован в InlineMessage. Сейчас используйте InlineMessage2.
 */
export interface InlineMessageProps extends HTMLAttributes<HTMLDivElement> {
    text?: ReactNode;
    closable?: boolean;
    status?: InlineMessageStatus;
    icon?: IconStatus;
    wrap?: boolean;
    onClose?: () => void;
}
/**
 * @deprecated
 * Данный компонент является легаси. В будущих мажорных релизах компонент InlineMessage будет удален, а InlineMessage2 будет переименован в InlineMessage. Сейчас используйте InlineMessage2.
 */
export declare const InlineMessage: ({ text, status, closable, icon, wrap, className, onClose, ...rest }: InlineMessageProps) => false | import("react/jsx-runtime").JSX.Element;
