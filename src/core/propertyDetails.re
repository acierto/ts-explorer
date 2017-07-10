open Glamor;

external entries : Js.t {..} => array (array string) =
  "Object.entries" [@@bs.val];

let component = ReasonReact.statelessComponent "PropertyDetails";

let propertyDetailsCls =
  css [
    display "inline-block",
    left "260px",
    position "absolute",
    top "45px",
    width "400px"
  ];

let tableCls = css [borderSpacing "5px", display "table", width "auto"];

let rowCls = css [display "table-row", width "auto"];

let cellCls = css [border "solid 1px", display "table-cell", width "200px"];

let make ::propertyDetails _children => {
  ...component,
  render: fun _ =>
    <div className=propertyDetailsCls>
      <span title=propertyDetails##name>
        <div className=tableCls>
          (
            ReasonReact.arrayToElement (
              Array.map
                (
                  fun entry =>
                    <div key=entry.(0) className=rowCls>
                      <div className=cellCls>
                        (ReasonReact.stringToElement entry.(0))
                      </div>
                      <div className=cellCls>
                        (ReasonReact.stringToElement entry.(1))
                      </div>
                    </div>
                )
                (entries propertyDetails)
            )
          )
        </div>
      </span>
    </div>
};
