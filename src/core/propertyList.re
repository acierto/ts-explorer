open Glamor;

let component = ReasonReact.statelessComponent "PropertyList";

let propertyListCls =
  css [
    border "solid 1px lightgrey",
    display "inline-block",
    flexBasis "auto",
    flexFlow "column nowrap",
    flexGrow "1",
    flexShrink "1",
    height "0",
    margin "15px",
    maxHeight "100%",
    minHeight "0",
    overflow "auto",
    padding "0 15px",
    width "200px"
  ];

let propertyCls =
  css [
    padding "5px 0",
    Selector
      "& span"
      [
        display "inline-block",
        overflow "hidden",
        textOverflow "ellipsis",
        width "200px"
      ]
  ];

let make ::properties ::onPropertyClick _children => {
  ...component,
  render: fun _ =>
    <div className=propertyListCls onClick=onPropertyClick>
      (
        ReasonReact.arrayToElement (
          Array.map
            (
              fun property => {
                let propertyName = property##name;
                <PropertyItem propertyName key=propertyName />
              }
            )
            properties
        )
      )
    </div>
};
