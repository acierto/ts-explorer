open Glamor;

let component = ReasonReact.statelessComponent "OverviewPanel";

external jsonStringify : Js.t {..} => string = "JSON.stringify" [@@bs.val];

let upperPanelCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexRowMixin
    [maxHeight "100%", minHeight "0", overflow "auto", width "auto"];

let quickOverviewCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin
    [maxHeight "100%", minHeight "0", overflow "auto", width "auto"];

let showRootInformation data =>
  Js_undefined.testAny data ?
    ReasonReact.nullElement :
    <div>
      <span> (ReasonReact.stringToElement "Root: ") </span>
      <span> (ReasonReact.stringToElement data) </span>
    </div>;

let make
    ::description
    ::icon
    ::interfaces
    ::superTypes
    ::propertyDetails
    ::root
    ::virtualType
    _children => {
  ...component,
  render: fun _ =>
    switch propertyDetails {
    | Some propertyDetails =>
      <div className=quickOverviewCls>
        <PropertyDetails propertyDetails />
      </div>
    | None =>
      <div className=quickOverviewCls>
        <div className=upperPanelCls>
          <InterfacesView interfaces />
          <SuperTypesView superTypes />
        </div>
        <TypeDetails description icon root virtualType />
      </div>
    }
};
