open Glamor;

let flexContainerStyles = [
  display "flex",
  flexFlow "column",
  height "inherit"
];

let flexContainerCls = css flexContainerStyles;

let panelRawSize = 220;

let panelSize = CssUtils.toPx panelRawSize;
