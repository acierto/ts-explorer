open Glamor;

let component = ReasonReact.statelessComponent "PropertyItem";

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

let make ::propertyName _children => {
  ...component,
  render: fun _ =>
    <div className=propertyCls>
      <span title=propertyName>
        (ReasonReact.stringToElement propertyName)
      </span>
    </div>
};
