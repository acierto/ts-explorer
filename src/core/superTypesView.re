open Glamor;

let component = ReasonReact.statelessComponent "SuperTypesView";

let superTypesVeiwCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [
      height "200px",
      maxHeight "200px",
      overflow "auto",
      width SharedCss.panelSize
    ];

let getInterfaceItems superTypes =>
  Array.map
    (
      fun superType =>
        <PanelItem color="#5bc0de" text=superType key=superType />
    )
    superTypes;

let make ::superTypes _children => {
  ...component,
  render: fun _ =>
    <div className=SharedCss.flexContainerCls>
      <PanelTitle text="Super Types" />
      <div className=superTypesVeiwCls>
        (ReasonReact.arrayToElement @@ getInterfaceItems superTypes)
      </div>
    </div>
};
