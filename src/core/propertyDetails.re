open Glamor;

let component = ReasonReact.statelessComponent "PropertyDetails";

let propertyDetailsCls =
  css [
    display "inline-block",
    left "260px",
    position "absolute",
    top "45px",
    width "400px"
  ];

let make ::propertyDetails _children => {
  ...component,
  render: fun _ =>
    <div className=propertyDetailsCls>
      <span title=propertyDetails##name>
        (
          ReasonReact.arrayToElement (
            Array.map
              (
                fun propertyName => {
                  Js.log propertyDetails;
                  <div key=propertyName>
                    (ReasonReact.stringToElement propertyName)
                  </div>
                }
              )
              (Js.Obj.keys propertyDetails)
          )
        )
      </span>
    </div>
};
