external entries : Js.t {..} => array (string, string) =
  "Object.entries" [@@bs.val];

let component = ReasonReact.statelessComponent "PropertyDetails";

let make ::propertyDetails _children => {
  ...component,
  render: fun _ =>
    <div className=SharedCss.flexContainerCls>
      <PanelTitle text="Property Details" />
      <TableComponent keyValueEntries=(entries propertyDetails) />
    </div>
};
