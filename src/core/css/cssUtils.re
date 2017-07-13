let toPx rawSize => string_of_int rawSize ^ "px";

let mixStyles firstCls secondCls => List.append firstCls secondCls;
