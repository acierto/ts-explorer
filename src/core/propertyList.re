open Glamor;

let component = ReasonReact.statelessComponent "PropertyList";

let propertyListContainerCls =
  css [display "flex", flexFlow "column", height "inherit"];

let propertyTitleCls =
  css @@
  CssUtils.mixStyles CssUtils.titleStyles [padding "0 30px", height "30px"];

let propertyListCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [
      border "solid 1px lightgrey",
      margin "5px 15px",
      maxHeight "100%",
      maxWidth "200px",
      minWidth "200px",
      minHeight "0",
      overflow "auto",
      padding "0 10px",
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

let make ::properties ::selectedPropertyName ::onPropertyClick _children => {
  ...component,
  render: fun _ =>
    <div className=propertyListContainerCls>
      <div className=propertyTitleCls>
        (ReasonReact.stringToElement "Properties")
      </div>
      <div className=propertyListCls onClick=onPropertyClick>
        (
          ReasonReact.arrayToElement (
            Array.map
              (
                fun property => {
                  let isSelected = property##name == selectedPropertyName;
                  let propertyName = property##name;
                  <PropertyItem propertyName key=propertyName isSelected />
                }
              )
              properties
          )
        )
      </div>
    </div>
};
