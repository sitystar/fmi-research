import { HTMLAttributes, ReactNode } from 'react';
/**
 * Размерности табов.
 */
export type TabSizes = 'l' | 'm' | 's';
/**
 * Положение табов.
 * - `'top'` (по умолчанию) — горизонтальное расположение сверху от выводимого контента.
 * - `'left'` — вертикальное расположение слева от выводимого контента.
 * - `'right'` — вертикальное расположение справа от выводимого контента.
 */
export type TabPosition = 'left' | 'right' | 'top';
/**
 * Тип действия для callback onEdit.
 * - `'add'` — добавление таба.
 * - `'remove'` — удаление таба.
 */
export type TabEditAction = 'add' | 'remove';
export interface TabItem {
    /** Уникальный ключ таба. */
    key: string;
    /** Содержимое таба. */
    label: ReactNode;
    /** Содержимое, отображаемое при выборе активной вкладки. */
    children?: ReactNode;
    /** Отключение таба. */
    disabled?: boolean;
    /** Показывать ли кнопку закрытия таба. Работает только если передана функция onEdit - в таком случае по умолчанию все табы будут закрываемыми */
    closable?: boolean;
    /** Кастомная иконка закрытия. Работает только если передана функция onEdit */
    closeIcon?: ReactNode;
}
export interface TabsProps extends Omit<HTMLAttributes<HTMLDivElement>, 'onChange'> {
    /**
     * Управляемый ключ активного таба.
     * Если передан, компонент становится контролируемым.
     */
    activeKey?: string;
    /**
     * Неуправляемый активный ключ по умолчанию.
     * Используется при отсутствии `activeKey`.
     */
    defaultActiveKey?: string;
    /** Массив элементов таба */
    items: TabItem[];
    /**
     * Размер табов.
     * @default 'm'
     */
    size?: TabSizes;
    /**
     * Положение табов относительно выводимого ими контента.
     * @default 'top'
     */
    tabPosition?: TabPosition;
    /**
     * Callback при переключении таба.
     * Получает новый `activeKey`.
     */
    onChange?: (activeKey: string) => void;
    /**
     * Callback при добавлении или удалении таба.
     * Работает только при type="editable-card".
     * Получает `targetKey` и тип действия `action` - 'add' или 'remove'.
     */
    onEdit?: (targetKey: string, action: TabEditAction) => void;
    /**
     * Флаг, определяющий поведение контента скрытых табов:
     *
     * - `true` — контент неактивных табов размонтируется
     * - `false` — контент активных и неактивных табов не размонтируется
     *
     * @default true
     */
    destroyInactiveTabContent?: boolean;
}
/**
 * Компонент отображающий переключаемую группу табов с контентом.
 */
export declare const Tabs: ({ activeKey: propActiveKey, defaultActiveKey, items, size, tabPosition, onChange, onEdit, className, destroyInactiveTabContent, ...rest }: TabsProps) => import("react/jsx-runtime").JSX.Element;
