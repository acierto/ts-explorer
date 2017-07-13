open Glamor;

let component = ReasonReact.statelessComponent "PanelItem";

let getItemCls
    ::_color
    _hoverColor::(hoverColorOption: option string)
    ::isSelected
    () =>
  css @@
  CssUtils.mixStyles
    [
      border "solid 1px",
      borderColor _color,
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
      switch hoverColorOption {
      | Some hoverColor =>
        if isSelected {
          [backgroundColor _color, color "#fff", cursor "pointer"]
        } else {
          [
            backgroundColor "#fff",
            Selector
              ":hover"
              [
                backgroundColor hoverColor,
                borderColor hoverColor,
                color "#fff",
                cursor "pointer"
              ]
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
