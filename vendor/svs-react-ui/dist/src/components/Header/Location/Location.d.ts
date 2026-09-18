import { HTMLAttributes } from 'react';
import './Location.scss';
import { DropdownItemType } from '../../Dropdown/DropdownItem';
interface LocationProps extends HTMLAttributes<HTMLDivElement> {
    currentLocation?: string;
    locationOptions?: DropdownItemType[];
    onLocationChange?: (value: DropdownItemType) => void;
}
export declare const Location: ({ currentLocation, onLocationChange, locationOptions }: LocationProps) => import("react/jsx-runtime").JSX.Element;
export {};
