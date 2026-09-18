import { RefObject, Ref } from 'react';
declare const useCombinedRefs: <T extends HTMLElement>(...refs: Array<Ref<T> | undefined>) => RefObject<T | null>;
export default useCombinedRefs;
