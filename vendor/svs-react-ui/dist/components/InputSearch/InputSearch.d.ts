import React, { ReactNode } from 'react';
import { InputProps } from '../Input/Input';
import './InputSearch.scss';
export interface InputSearchProps extends Omit<InputProps, 'label' | 'message' | 'onEnter'> {
    /**
     * Определяет отображение кнопки поиска:
      - true: кнопка в primary-стиле с иконкой поиска
      - false: кнопка в tertiary-стиле с иконкой поиска
      - ReactNode: кастомное содержимое кнопки в primary-стиле
      @default true
     */
    enterButton?: boolean | ReactNode;
    /**
     * Callback-функция, возвращающая новое значение после:
     * - нажатия клавиши Enter
     * - клика на кнопку поиска
     */
    onSearch?: (value: string) => void;
}
export declare const InputSearch: React.ForwardRefExoticComponent<InputSearchProps & React.RefAttributes<HTMLInputElement>>;
