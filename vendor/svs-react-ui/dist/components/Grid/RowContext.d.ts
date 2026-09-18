export type GutterType = number | [number, number];
export type RowContextTypes = {
    gutter?: GutterType;
};
declare const RowContext: import("react").Context<RowContextTypes>;
export default RowContext;
