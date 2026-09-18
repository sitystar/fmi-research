/**
 * @description Функция принимает html элемент
 * и направление ('vertical' | 'horizontal')
 * и возвращает суммарную ширину всех padding и border
 * в выбранном направлении.
 */
export declare const getPaddingsAndBorders: (el: HTMLElement, direction: "vertical" | "horizontal") => number;
