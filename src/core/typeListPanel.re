open Glamor;

let component = ReasonReact.statelessComponent "TypeListPanel";

let listOfItemsCls = css [display "flex", height "inherit", flexFlow "column"];

let listOfItemsInnerCls =
  css [flex "1 100%", overflow "auto", width SharedCss.panelSize];

let searchTypeCls =
  css [
    color "grey",
    display "block",
    height "40px",
    marginTop "5px",
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
    padding "9px 10px 9px 28px",
    width (CssUtils.toPx @@ SharedCss.panelRawSize - 9),
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

let getItems keys selectedKey searchCriteria =>
  Array.map
    (
      fun key =>
        <PanelItem
          color="#337ab7"
          hoverColor="#286090"
          isSelected=(key == selectedKey)
          key
          text=key
        />
    )
    (filterKeys keys searchCriteria);

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
      <PanelTitle text="Types" />
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
