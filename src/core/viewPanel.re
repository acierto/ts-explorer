open Glamor;

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
            description=typeDescriptorValue##description
            icon=typeDescriptorValue##icon
            interfaces=typeDescriptorValue##interfaces
            propertyDetails=(
              getPropertyDetails typeDescriptorValue propertyName ()
            )
            superTypes=typeDescriptorValue##superTypes
            root=typeDescriptorValue##root
            virtualType=typeDescriptorValue##_virtual
          />
        </div>
      </div>
    | None => ReasonReact.nullElement
    }
};
