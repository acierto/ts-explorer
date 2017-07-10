open Glamor;

let mixStyles firstCls secondCls => List.append firstCls secondCls;

let titleStyles = [
  display "inline-block",
  fontWeight "bold",
  height "39px",
  lineHeight "30px",
  textAlign "center",
  width "200px"
];
