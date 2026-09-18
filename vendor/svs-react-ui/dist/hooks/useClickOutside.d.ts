import { RefObject } from 'react';
type Handler = (event: MouseEvent | TouchEvent) => void;
export declare function useOnClickOutside<T extends Node>(ref: RefObject<T | null> | RefObject<T | null>[], handler: Handler): void;
export {};
