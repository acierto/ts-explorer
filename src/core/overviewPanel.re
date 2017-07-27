open Glamor;

let component = ReasonReact.statelessComponent "OverviewPanel";

external jsonStringify : Js.t {..} => string = "JSON.stringify" [@@bs.val];

let upperPanelCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexRowMixin [maxHeight "100%", minHeight "0", overflow "auto", width "auto"];

let quickOverviewCls =
  css @@ CssUtils.mixStyles CssMixins.flexMixin [maxHeight "100%", minHeight "0", width "auto"];

let propertiesOverviewCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexMixin [maxHeight "100%", minHeight "0", overflow "auto", width "auto"];

let make ::interfaces ::superTypes ::propertyDetails ::typeDetails _children => {
  ...component,
  render: fun _ =>
    switch propertyDetails {
    | Some propertyDetails =>
      <div className=propertiesOverviewCls> <PropertyDetails propertyDetails /> </div>
    | None =>
      <div className=quickOverviewCls>
        <div className=upperPanelCls>
          <ReadOnlyView color="#d9534f" itemValues=interfaces title="Interfaces" />
          <ReadOnlyView color="#5bc0de" itemValues=superTypes title="Super Types" />
        </div>
        <TypeDetails typeDetails />
      </div>
    }
};
