import './InlineMessage2.scss';
import { HTMLAttributes, ReactNode } from 'react';
export type InlineMessage2Status = 'warning' | 'error' | 'success' | 'info';
export type InlineMessage2Type = 'default' | 'colorful' | 'bright';
export interface InlineMessage2Props extends HTMLAttributes<HTMLDivElement> {
    /** Текст */
    text?: ReactNode;
    /** Присутствие кнопки закрытия
     * @default true
     */
    closable?: boolean;
    /** Статус сообщения: warning, error, success, info
     * @default 'info'
     */
    status?: InlineMessage2Status;
    /** Свою иконку вместо дефолтной в зависимости от status, либо false чтобы полностью скрыть иконку */
    icon?: ReactNode | false;
    /** Возможность перенести текст на следующую строку
     * @default true
     */
    wrap?: boolean;
    /** Выполняется при закрытии */
    onClose?: () => void;
    /** Тип отображения: default, colorful, bright
     * @default 'default'
     */
    type?: InlineMessage2Type;
    /** Дополнительный контент после текста */
    afterContent?: ReactNode;
}
export declare const InlineMessage2: ({ text, status, type: messageType, closable, icon, wrap, className, onClose, afterContent, ...rest }: InlineMessage2Props) => import("react/jsx-runtime").JSX.Element | null;
