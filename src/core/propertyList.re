open Glamor;

let component = ReasonReact.statelessComponent "PropertyList";

let propertyListCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [
      margin "0 15px",
      maxHeight "100%",
      maxWidth SharedCss.panelSize,
      minWidth SharedCss.panelSize,
      minHeight "0",
      overflow "auto",
      width SharedCss.panelSize
    ];

let make ::properties ::selectedPropertyName=? ::onPropertyClick _children => {
  ...component,
  render: fun _ =>
    <div className=SharedCss.flexContainerCls>
      <PanelTitle text="Properties" />
      <div className=propertyListCls onClick=onPropertyClick>
        (
          ReasonReact.arrayToElement (
            Array.map
              (
                fun property => {
                  let propertyName = property##name;
                  switch selectedPropertyName {
                  | Some selectedPropertyNameValue =>
                    let isSelected =
                      property##name == selectedPropertyNameValue;
                    <PanelItem
                      color="#449d44"
                      hoverColor="#398439"
                      isSelected
                      key=propertyName
                      text=propertyName
                    />
                  | None =>
                    <PanelItem
                      color="#449d44"
                      hoverColor="#398439"
                      key=propertyName
                      text=propertyName
                    />
                  }
                }
              )
              properties
          )
        )
      </div>
    </div>
};
