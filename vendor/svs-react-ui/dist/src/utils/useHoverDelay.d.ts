type UseHoverDelayProps = {
    onVisibleChange?: (visible: boolean) => void;
    /**
     * Задержка скрытия всплывающего элемента
     * после того как курсор мыши покидает область наведения.
     *
     * Указывается в **секундах**.
     */
    hideDelay: number;
};
export declare const useHoverDelay: ({ onVisibleChange, hideDelay }: UseHoverDelayProps) => {
    showElement: () => void;
    hideElement: () => void;
    clearHoverTimeout: () => void;
};
export {};
