open Glamor;

let component = ReasonReact.statelessComponent "TypeListPanel";

let listOfItemsCls = css [display "flex", height "inherit", flexFlow "column"];

let listOfItemsInnerCls = css [flex "1 100%", overflow "auto", width "200px"];

let searchTypeCls =
  css [
    color "grey",
    display "block",
    height "40px",
    position "relative",
    Selector
      "& i"
      [
        color "grey",
        fontSize "24px",
        left "10px",
        position "absolute",
        top "10px"
      ]
  ];

let searchInputCls =
  css [
    fontSize "13px",
    margin "0 0 0 5px",
    padding "10px 10px 10px 28px",
    width "191px",
    Selector ":focus" [outline "0"]
  ];

let filterKeys keys term =>
  if (term == "") {
    keys
  } else {
    Array.fold_left
      (
        fun acc key =>
          if (
            StringUtils.contains (String.lowercase key) (String.lowercase term)
          ) {
            Array.append acc [|key|]
          } else {
            acc
          }
      )
      [||]
      keys
  };

let getItems keys selectedKey searchCriteria => {
  let itemCls mixin =>
    css @@
    CssUtils.mixStyles
      [
        border "solid 1px #337ab7",
        color "#337ab7",
        cursor "pointer",
        fontWeight "bold",
        margin "5px",
        overflow "hidden",
        padding "10px",
        textOverflow "ellipsis",
        whiteSpace "nowrap"
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
    (filterKeys keys searchCriteria)
};

let make
    ::typeList
    ::onItemClick
    ::onSearchChange
    ::selectedKey
    ::searchCriteria
    _children => {
  ...component,
  render: fun _ =>
    <div className=listOfItemsCls>
      <div className=(css CssUtils.titleStyles)>
        (ReasonReact.stringToElement "Types")
      </div>
      <div className=searchTypeCls>
        <i className="glyphicon glyphicon-search" />
        <input
          className=searchInputCls
          _type="text"
          placeholder="Search"
          onChange=onSearchChange
        />
      </div>
      <div className=listOfItemsInnerCls onClick=onItemClick>
        (
          ReasonReact.arrayToElement @@
          getItems typeList selectedKey searchCriteria
        )
      </div>
    </div>
};
