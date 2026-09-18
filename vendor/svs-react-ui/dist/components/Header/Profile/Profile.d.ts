import { HTMLAttributes } from 'react';
import { AvatarStatuses } from '../../Avatar';
import './Profile.scss';
export interface ProfileProps extends HTMLAttributes<HTMLDivElement> {
    fio?: string;
    email?: string;
    photoSrc?: string;
    profileStatus?: AvatarStatuses;
}
export declare const Profile: ({ fio, email, photoSrc, profileStatus, className, ...rest }: ProfileProps) => import("react/jsx-runtime").JSX.Element;
