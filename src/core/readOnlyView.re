open Glamor;

let component = ReasonReact.statelessComponent "ReadOnlyView";

let panelVeiwCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [
      maxHeight "100%",
      overflow "auto",
      width SharedCss.panelSize
    ];

let getHtmlItems ::color ::values =>
  List.map
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
            TsReact.listToElement @@
            getHtmlItems values::itemValues ::color
          )
        </div>
      </div>
};
