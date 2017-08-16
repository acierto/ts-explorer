open Glamor;

type filterState = {
  hasContainerTypeTerm: string,
  hasInterfaceTerm: string,
  hasSupertypeTerm: string,
  hasPropertyTerm: string
};

let eventToObjectType: 'a => SharedTypes.optionType = [%bs.raw
  {|function(val){
    return val && (val !== null) ? Object.assign(val): {};
}|}
];

let component = ReasonReact.statefulComponent "AdvancedFilter";

external jsonStringify : 'a => string = "JSON.stringify" [@@bs.val];

external makeOption : label::string => value::string => unit => SharedTypes.optionType =
  "" [@@bs.obj];

external makeFilters :
  hasContainerType::string =>
  hasInterface::string =>
  hasProperty::string =>
  hasSupertype::string =>
  unit =>
  SharedTypes.filtersType =
  "" [@@bs.obj];

let buttonsPanelCls = css [bottom "10px", position "absolute", right "10px"];

let noOutlineStyles = [outline "none"];

let btnCls = css [Selector ":focus, &:active:focus" noOutlineStyles];

let headerCls = css [textAlign "center"];

let handleHasInterfaceTermChange event {ReasonReact.state: state} =>
  ReasonReact.Update {...state, hasInterfaceTerm: (eventToObjectType event)##value};

let handleHasSupertypeTermChange event {ReasonReact.state: state} =>
  ReasonReact.Update {...state, hasSupertypeTerm: (eventToObjectType event)##value};

let handleHasPropertyTermChange event {ReasonReact.state: state} =>
  ReasonReact.Update {...state, hasPropertyTerm: (eventToObjectType event)##value};

let handleHasContainerTypeTermChange event {ReasonReact.state: state} =>
  ReasonReact.Update {...state, hasContainerTypeTerm: (eventToObjectType event)##value};

let filterElementCls =
  css [
    Selector
      "> .filter-label"
      [display "inline-block", lineHeight "35px", verticalAlign "text-bottom", width "150px"],
    Selector
      "> .filter-label > span"
      [
        display "inline-block",
        lineHeight "1em",
        marginRight "10px",
        top "15px",
        verticalAlign "middle"
      ],
    Selector "> .Select" [display "inline-block", width "300px"]
  ];

let createOptions values => Array.map (fun value => makeOption label::value ::value ()) values;

let handleApply fn st _ =>
  fn @@
  makeFilters
    hasInterface::st.hasInterfaceTerm
    hasSupertype::st.hasSupertypeTerm
    hasProperty::st.hasPropertyTerm
    ();

let filterLabelElement labelText =>
  <span className="filter-label"> <span> (ReasonReact.stringToElement labelText) </span> </span>;

let make
    ::containerTypes
    ::interfaces
    ::propertyNames
    ::superTypes
    ::isOpenedFilter
    ::onCloseFilter
    ::onApplyFilter
    _children => {
  ...component,
  initialState: fun () => {
    hasContainerTypeTerm: "",
    hasInterfaceTerm: "",
    hasPropertyTerm: "",
    hasSupertypeTerm: ""
  },
  render: fun {state, update} =>
    <ReactModal contentLabel="Filter" isOpen=isOpenedFilter>
      <h3 className=headerCls> (ReasonReact.stringToElement "Advanced Filter") </h3>
      <div className=filterElementCls>
        (filterLabelElement "Has interface")
        <ReactSelect
          name="has-interface"
          value=state.hasInterfaceTerm
          options=(createOptions interfaces)
          onChange=(update handleHasInterfaceTermChange)
        />
      </div>
      <div className=filterElementCls>
        (filterLabelElement "Has supertype")
        <ReactSelect
          name="has-supertype"
          value=state.hasSupertypeTerm
          options=(createOptions superTypes)
          onChange=(update handleHasSupertypeTermChange)
        />
      </div>
      <div className=filterElementCls>
        (filterLabelElement "Has property")
        <ReactSelect
          name="has-property"
          value=state.hasPropertyTerm
          options=(createOptions propertyNames)
          onChange=(update handleHasPropertyTermChange)
        />
      </div>
      <div className=filterElementCls>
        (filterLabelElement "Has container type")
        <ReactSelect
          name="has-container-type"
          value=state.hasContainerTypeTerm
          options=(createOptions containerTypes)
          onChange=(update handleHasContainerTypeTermChange)
        />
      </div>
      <div className=buttonsPanelCls>
        <button className=(btnCls ^ " btn btn-link") onClick=onCloseFilter _type="button">
          (ReasonReact.stringToElement "Close")
        </button>
        <button
          className=(btnCls ^ " btn btn-primary")
          onClick=(handleApply onApplyFilter state)
          _type="button">
          (ReasonReact.stringToElement "Apply")
        </button>
      </div>
    </ReactModal>
};
