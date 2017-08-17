open Glamor;

external entries : Js.t {..} => array (string, string) =
  "Object.entries" [@@bs.val];

external jsonStringify : Js.t {..} => string = "JSON.stringify" [@@bs.val];

let component = ReasonReact.statelessComponent "ViewPanel";

let viewPanelCls =
  css @@ CssUtils.mixStyles CssMixins.flexMixin [height "inherit"];

let viewInnerPanelCls =
  css @@
  CssUtils.mixStyles
    CssMixins.flexRowMixin [height "inherit", position "relative"];

let titleCls = css [fontSize "24px", textAlign "center"];

let sortProperties itemProperties => {
  let compareByName a b =>
    compare (String.lowercase a##name) (String.lowercase b##name);
  Array.fast_sort compareByName itemProperties;
  itemProperties
};

let getTypeDetails typeDescriptor () => {
  let isEqual key item => key === item;
  let excludedItems = ["properties", "superTypes", "interfaces", "type"];
  let descriptorEtries = entries typeDescriptor;
  Array.fold_left
    (
      fun acc (key, value) =>
        List.exists (isEqual key) excludedItems ?
          acc : Array.append [|(StringUtils.capitalize key, value)|] acc
    )
    [||]
    descriptorEtries
};

let getPropertyDetails typeDescriptor propertyName () => {
  let props = typeDescriptor##properties;
  Array.fold_left
    (
      fun acc x =>
        if (x##name == propertyName) {
          Some x
        } else {
          acc
        }
    )
    None
    props
};

let make ::typeDescriptor=? ::propertyName ::onPropertyClick _children => {
  ...component,
  render: fun _ =>
    switch typeDescriptor {
    | Some typeDescriptorValue =>
      <div className=viewPanelCls>
        <div className=viewInnerPanelCls>
          <PropertyList
            onPropertyClick
            properties=(sortProperties typeDescriptorValue##properties)
            selectedPropertyName=propertyName
          />
          <OverviewPanel
            interfaces=typeDescriptorValue##interfaces
            propertyDetails=(
              getPropertyDetails typeDescriptorValue propertyName ()
            )
            superTypes=typeDescriptorValue##superTypes
            typeDetails=(getTypeDetails typeDescriptorValue ())
          />
        </div>
      </div>
    | None => ReasonReact.nullElement
    }
};