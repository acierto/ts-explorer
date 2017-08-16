open Glamor;

let typeSystemPanelCls = css [display "flex", height "inherit", flexFlow "row"];

external eventToFilters : 'a => SharedTypes.filtersType = "Object.assign" [@@bs.val];

type state = {
  isOpenedFilter: bool,
  advancedFilters: SharedTypes.filtersType,
  searchTypeTerm: string,
  selectedKey: string,
  selectedProperty: string
};

let component = ReasonReact.statefulComponent "TypeSystem";

type typeItems = array SharedTypes.typeItem;

let handleSearchChange event {ReasonReact.state: state} => {
  let searchTypeTerm = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
  ReasonReact.Update {...state, searchTypeTerm}
};

let handleTypeClick event {ReasonReact.state: state} => {
  let selectedKey = (ReactDOMRe.domElementToObj (ReactEventRe.Mouse.target event))##innerText;
  ReasonReact.Update {...state, selectedKey, selectedProperty: ""}
};

let handlePropertyClick event {ReasonReact.state: state} => {
  let selectedProperty = (ReactDOMRe.domElementToObj (ReactEventRe.Mouse.target event))##innerText;
  ReasonReact.Update {...state, selectedProperty}
};

let findTypeByKey typeItems ::key () =>
  Array.fold_left
    (
      fun acc x =>
        if (x##_type == key) {
          Some x
        } else {
          acc
        }
    )
    None
    typeItems;

let handleOpenFilter _event {ReasonReact.state: state} =>
  ReasonReact.Update {...state, isOpenedFilter: true};

let handleCloseFilter _event {ReasonReact.state: state} =>
  ReasonReact.Update {...state, isOpenedFilter: false};

let handleApplyFilter _event {ReasonReact.state: state} => {
  let advancedFilters = eventToFilters _event;
  ReasonReact.Update {...state, isOpenedFilter: false, advancedFilters}
};

let getSortedKeys data => {
  let keys = Array.map (fun typeItem => typeItem##_type) data;
  Array.fast_sort compare keys;
  keys
};

let make ::data _children => {
  ...component,
  initialState: fun () => {
    isOpenedFilter: false,
    advancedFilters: Js.Obj.empty (),
    searchTypeTerm: "",
    selectedKey: "",
    selectedProperty: ""
  },
  render: fun {state, update} => {
    let filteredData = AdvancedFilterUtils.getFilteredData data state.advancedFilters;
    let selectedType = findTypeByKey filteredData key::state.selectedKey ();
    <div className=typeSystemPanelCls>
      <AdvancedFilter
        containerTypes=(DataUtils.getAllContainerTypes data)
        interfaces=(DataUtils.getAllInterfaces data)
        propertyNames=(DataUtils.getAllPropertyNames data)
        superTypes=(DataUtils.getAllSuperTypes data)
        isOpenedFilter=state.isOpenedFilter
        onApplyFilter=(update handleApplyFilter)
        onCloseFilter=(update handleCloseFilter)
      />
      <TypeListPanel
        selectedKey=state.selectedKey
        searchCriteria=state.searchTypeTerm
        typeList=(getSortedKeys filteredData)
        onOpenFilter=(update handleOpenFilter)
        onSearchChange=(update handleSearchChange)
        onItemClick=(update handleTypeClick)
      />
      <ViewPanel
        typeDescriptor=?selectedType
        propertyName=state.selectedProperty
        onPropertyClick=(update handlePropertyClick)
      />
    </div>
  }
};