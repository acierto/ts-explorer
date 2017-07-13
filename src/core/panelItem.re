open Glamor;

let component = ReasonReact.statelessComponent "PanelItem";

let getItemCls ::_color ::_hoverColor=? ::isSelected () =>
  css @@
  CssUtils.mixStyles
    [
      border "solid 1px #337ab7",
      color _color,
      fontWeight "bold",
      fontSize "12px",
      margin "5px",
      minHeight "40px",
      overflow "hidden",
      padding "10px",
      textDecoration "none",
      textOverflow "ellipsis",
      whiteSpace "nowrap"
    ]
    (
      switch _hoverColor {
      | Some hc =>
        if isSelected {
          [
            backgroundColor _color,
            borderColor _color,
            color "#fff",
            cursor "pointer"
          ]
        } else {
          [
            backgroundColor "#fff",
            borderColor _color,
            Selector
              ":hover" [backgroundColor hc, borderColor hc, color "#fff"]
          ]
        }
      | None => []
      }
    );

let make ::color ::hoverColor=? ::isSelected=false ::text _children => {
  ...component,
  render: fun _ =>
    <div
      className=(
        getItemCls _color::color _hoverColor::hoverColor ::isSelected ()
      )>
      <span title=text> (ReasonReact.stringToElement text) </span>
    </div>
};
