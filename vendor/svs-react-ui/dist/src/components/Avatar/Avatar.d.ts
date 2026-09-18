import { ButtonHTMLAttributes, MouseEvent } from 'react';
import './Avatar.scss';
export type AvatarStatuses = 'warning' | 'success' | 'lock' | 'danger';
export type AvatarSizes = 'l' | 'm' | 's';
interface AvatarProps extends Omit<ButtonHTMLAttributes<HTMLButtonElement>, 'size'> {
    status?: AvatarStatuses;
    onClick?: ((e: MouseEvent) => void) | undefined;
    disabled?: boolean;
    size?: AvatarSizes;
    src?: string;
}
export declare const Avatar: ({ disabled, src, size, status, className, onClick, style, ...rest }: AvatarProps) => import("react/jsx-runtime").JSX.Element;
export {};
