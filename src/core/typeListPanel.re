open Glamor;

let component = ReasonReact.statelessComponent "TypeListPanel";

let listOfItemsCls =
  css [
    cssFloat "left",
    display "inline-block",
    flex "0 0 auto",
    height "inherit",
    overflow "auto",
    width "200px"
  ];

let listOfItemsInnerCls = css [display "inline-block", width "100%"];

let getItems keys selectedKey => {
  let itemCls mixin =>
    css @@
    CssUtils.mixStyles
      [
        border "solid 1px rgb(51, 51, 51)",
        color "rgb(51, 51, 51)",
        cursor "pointer",
        margin "5px",
        overflow "hidden",
        padding "10px",
        textOverflow "ellipsis"
      ]
      mixin;
  Array.map
    (
      fun key => {
        let mixin =
          if (key == selectedKey) {
            [backgroundColor "#337ab7", color "#fff"]
          } else {
            [
              backgroundColor "#fff",
              Selector
                ":hover"
                [
                  color "#555",
                  textDecoration "none",
                  backgroundColor "#f5f5f5"
                ]
            ]
          };
        <div className=(itemCls mixin) key>
          (ReasonReact.stringToElement key)
        </div>
      }
    )
    keys
};

let make ::typeList ::onItemClick ::selectedKey _children => {
  ...component,
  render: fun _ =>
    <div className=listOfItemsCls onClick=onItemClick>
      <div className=listOfItemsInnerCls>
        (ReasonReact.arrayToElement @@ getItems typeList selectedKey)
      </div>
    </div>
};
