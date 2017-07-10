open Glamor;

let component = ReasonReact.statelessComponent "PropertyItem";

let propertyStyle = [
  cursor "pointer",
  padding "5px 0",
  Selector
    "& span"
    [
      display "inline-block",
      overflow "hidden",
      textOverflow "ellipsis",
      width "180px"
    ]
];

let getItemCls isSelected =>
  css @@
  CssUtils.mixStyles
    propertyStyle
    (
      if isSelected {
        [color "#337ab7", fontWeight "bold"]
      } else {
        [Selector ":hover" [fontWeight "bold"]]
      }
    );

let make ::propertyName ::isSelected _children => {
  ...component,
  render: fun _ =>
    <div className=(getItemCls isSelected)>
      <span title=propertyName>
        (ReasonReact.stringToElement propertyName)
      </span>
    </div>
};
