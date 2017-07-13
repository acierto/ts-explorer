open Glamor;

let component = ReasonReact.statelessComponent "InterfacesView";

let interfacesPanelCls =
  css @@ CssUtils.mixStyles SharedCss.flexContainerStyles [];

let interfacesVeiwCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [
      height "200px",
      margin "0 15px",
      maxHeight "200px",
      overflow "auto",
      width SharedCss.panelSize
    ];

let getInterfaceItems interfaces =>
  Array.map
    (
      fun interface =>
        <PanelItem color="#d9534f" text=interface key=interface />
    )
    interfaces;

let make ::interfaces _children => {
  ...component,
  render: fun _ =>
    <div className=interfacesPanelCls>
      <PanelTitle text="Interfaces" />
      <div className=interfacesVeiwCls>
        (ReasonReact.arrayToElement @@ getInterfaceItems interfaces)
      </div>
    </div>
};
