open Glamor;

external entries : Js.t {..} => array (string, string) =
  "Object.entries" [@@bs.val];

let component = ReasonReact.statelessComponent "PropertyDetails";

let propertyDetailsCls =
  css @@
  CssUtils.mixStyles
    SharedCss.flexContainerStyles [margin "0 auto", width "80%"];

let make ::propertyDetails _children => {
  ...component,
  render: fun _ =>
    <div className=propertyDetailsCls>
      <PanelTitle text="Property Details" />
      <TableComponent keyValueEntries=(entries propertyDetails) />
    </div>
};
