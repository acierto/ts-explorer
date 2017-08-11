open Glamor;

let component = ReasonReact.statefulComponent "AdvancedFilterModalComponent";

external jsonStringify : 'a => string = "JSON.stringify" [@@bs.val];

external makeOption : label::string => value::string => unit => SharedTypes.optionType =
  "" [@@bs.obj];

let buttonsPanelCls = css [bottom "10px", position "absolute", right "10px"];

let noOutlineStyles = [outline "none"];

let btnCls = css [Selector ":focus, &:active:focus" noOutlineStyles];

let headerCls = css [textAlign "center"];

let changeFilterHasInterface _event {ReasonReact.state} => ReasonReact.Update (state + 1);

let hasInterfaceFilterCls =
  css [
    Selector
      "> .filter-label" [display "inline-block", lineHeight "35px", verticalAlign "text-bottom"],
    Selector
      "> .filter-label > span"
      [
        display "inline-block",
        lineHeight "1em",
        marginRight "10px",
        top "15px",
        verticalAlign "middle"
      ],
    Selector "> .Select" [display "inline-block", width "200px"]
  ];

let createOptions values => Array.map (fun value => makeOption label::value ::value ()) values;

let make ::interfaces ::isOpenedFilter ::onCloseFilter ::onApplyFilter _children => {
  ...component,
  initialState: fun () => 0,
  render: fun {state, update} =>
    <ReactModal contentLabel="Filter" isOpen=isOpenedFilter>
      <h3 className=headerCls> (ReasonReact.stringToElement "Advanced Filter") </h3>
      <div className=hasInterfaceFilterCls>
        <span className="filter-label">
          <span> (ReasonReact.stringToElement "Has interface") </span>
        </span>
        <ReactSelect
          name="has-interface"
          value=""
          options=(createOptions interfaces)
          onChange=(update changeFilterHasInterface)
        />
      </div>
      <div className=buttonsPanelCls>
        <button className=(btnCls ^ " btn btn-link") onClick=onCloseFilter _type="button">
          (ReasonReact.stringToElement "Close")
        </button>
        <button className=(btnCls ^ " btn btn-primary") onClick=onApplyFilter _type="button">
          (ReasonReact.stringToElement "Apply")
        </button>
      </div>
    </ReactModal>
};
