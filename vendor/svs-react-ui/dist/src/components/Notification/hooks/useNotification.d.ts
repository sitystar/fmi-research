import { NotificationId, NotificationProps } from '../Notification';
import '../Notification.scss';
export interface AddNotificationProps extends Omit<NotificationProps, 'stackInfo' | 'onClose' | 'onShown'> {
}
export interface UseNotificationProps {
    placement?: 'top-left' | 'bottom-left' | 'top-right' | 'bottom-right' | 'top-center' | 'bottom-center';
    /**
     * @deprecated
     * Проп ни на что не влияет и будет удален в будущих обновлениях
     */
    size?: 'l' | 'm';
    closable?: boolean;
    stackThreshold?: number;
    onClose?: (id: NotificationId) => void;
    /** Время в миллисекундах до того как уведомление будет закрыто */
    duration?: number;
}
export declare const DEFAULT_THRESHOLD = 3;
export declare const useNotification: ({ placement, size, closable, stackThreshold, onClose, duration }: UseNotificationProps) => {
    addNotification: (args: AddNotificationProps) => void;
    closeNotification: (id?: NotificationId) => void;
    contentHolder: import("react/jsx-runtime").JSX.Element;
};
