import { CSSProperties } from 'react';
import { PopoverPlacementType } from '.';
export declare const changePosition: (isMount: boolean, parentRef: React.RefObject<HTMLDivElement | null>, popoverRef: React.RefObject<HTMLDivElement | null>, placement: PopoverPlacementType, autoPosition: boolean, appendToBody: boolean, paddingBetweenObjects: number) => {
    coordinates: CSSProperties;
    newPlacement: PopoverPlacementType;
};
