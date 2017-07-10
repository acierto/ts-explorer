open Glamor;

external entries : Js.t {..} => array (array string) =
  "Object.entries" [@@bs.val];

let component = ReasonReact.statelessComponent "PropertyDetails";

let propertyDetailsCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [
      border "solid 1px lightgrey",
      margin "15px",
      maxHeight "100%",
      minHeight "0",
      overflow "auto",
      padding "0 15px",
      width "auto"
    ];

let tableCls = css [borderSpacing "5px", display "table", width "auto"];

let rowCls = css [display "table-row"];

let cellStyle = [display "table-cell", padding "10px", width "200px"];

let keyCellCls =
  css @@ CssUtils.mixStyles cellStyle [background "#e6f5ff", minWidth "150px"];

let valueCellCls =
  css @@ CssUtils.mixStyles cellStyle [wordBreak "break-word", width "auto"];

let make ::propertyDetails _children => {
  ...component,
  render: fun _ =>
    <div className=propertyDetailsCls>
      <div className=tableCls>
        (
          ReasonReact.arrayToElement (
            Array.map
              (
                fun entry =>
                  <div key=entry.(0) className=rowCls>
                    <div className=keyCellCls>
                      (ReasonReact.stringToElement entry.(0))
                    </div>
                    <div className=valueCellCls>
                      (ReasonReact.stringToElement entry.(1))
                    </div>
                  </div>
              )
              (entries propertyDetails)
          )
        )
      </div>
    </div>
};
