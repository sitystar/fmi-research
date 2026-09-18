import { HTMLAttributes, ReactNode } from 'react';
import './Notification.scss';
import { UseNotificationProps } from './hooks/useNotification';
export type NotificationIconStatus = 'warning' | 'error' | 'success' | 'info' | ReactNode;
interface StackInfo {
    length: number;
    index: number;
    fold: boolean;
    height?: number;
}
export type NotificationId = string | number;
export interface NotificationProps extends Pick<UseNotificationProps, 'closable' | 'duration'>, Omit<HTMLAttributes<HTMLDivElement>, 'content' | 'id'> {
    id?: NotificationId;
    stackInfo: StackInfo;
    icon?: NotificationIconStatus;
    title: string;
    content?: ReactNode;
    footerContent?: ReactNode;
    description?: string;
    onClose?: (id: NotificationId) => void;
    onRender?: (el: HTMLDivElement) => void;
}
export declare const Notification: import("react").ForwardRefExoticComponent<NotificationProps & import("react").RefAttributes<HTMLDivElement>>;
export {};
