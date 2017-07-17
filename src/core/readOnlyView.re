open Glamor;

let component = ReasonReact.statelessComponent "ReadOnlyView";

let panelVeiwCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [
      height "200px",
      maxHeight "200px",
      overflow "auto",
      width SharedCss.panelSize
    ];

let getHtmlItems ::color ::values =>
  Array.map
    (fun itemValue => <PanelItem color text=itemValue key=itemValue />) values;

let make ::color ::itemValues ::title _children => {
  ...component,
  render: fun _ =>
    Js_undefined.testAny itemValues ?
      ReasonReact.nullElement :
      <div className=SharedCss.flexContainerCls>
        <PanelTitle text=title />
        <div className=panelVeiwCls>
          (
            ReasonReact.arrayToElement @@
            getHtmlItems values::itemValues ::color
          )
        </div>
      </div>
};
