type InputSize = 'l' | 'm' | 's';
type ButtonSize = 'xl' | 'l' | 'm';
export declare const getSize: (size: InputSize) => {
    button: ButtonSize;
    input: InputSize;
};
export {};
