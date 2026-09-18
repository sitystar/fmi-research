import { FooterPrimaryProps } from '../FooterPrimary';
import './FooterExtra.scss';
export type FooterExtraProps = Omit<FooterPrimaryProps, 'titleElement'>;
export declare const FooterExtra: ({ className, ...rest }: FooterExtraProps) => import("react/jsx-runtime").JSX.Element;
