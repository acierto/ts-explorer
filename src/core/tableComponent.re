open Glamor;

let component = ReasonReact.statelessComponent "TableComponent";

let tableCls =
  css [borderSpacing "0 5px", display "table", margin "0 auto", width "100%"];

let rowCls = css [display "table-row"];

let cellStyle = [display "table-cell", padding "10px", width "200px"];

let borderCellStyle = "solid 1px black";

let keyCellCls =
  css @@
  CssUtils.mixStyles
    cellStyle
    [
      backgroundColor "#337ab7",
      border borderCellStyle,
      borderRadius "30px 0 0 30px",
      borderRight "none",
      color "#fff",
      fontWeight "bold",
      minWidth "150px",
      textAlign "center",
      verticalAlign "middle"
    ];

let valueCellCls =
  css @@
  CssUtils.mixStyles
    cellStyle
    [
      border borderCellStyle,
      borderRadius "0 30px 30px 0",
      borderLeft "none",
      fontWeight "bold",
      wordBreak "break-word",
      width "auto"
    ];

let scrollableAreaCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [maxHeight "100%", minHeight "0", overflow "auto", width "auto"];

let make keyValueEntries::(entries: array (string, string)) _children => {
  ...component,
  render: fun _ =>
    <div className=scrollableAreaCls>
      <div className=tableCls>
        (
          ReasonReact.arrayToElement @@
          Array.map
            (
              fun (key, value) =>
                Js_undefined.testAny value ?
                  ReasonReact.nullElement :
                  <div className=rowCls key>
                    <span className=keyCellCls>
                      (ReasonReact.stringToElement key)
                    </span>
                    <span className=valueCellCls>
                      (ReasonReact.stringToElement value)
                    </span>
                  </div>
            )
            entries
        )
      </div>
    </div>
};
