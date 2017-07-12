open Glamor;

let typeSystemPanelCls =
  css [display "flex", height "inherit", flexFlow "row"];

type state = {
  keys: array string,
  searchTypeTerm: string,
  selectedKey: string,
  selectedProperty: string
};

let component = ReasonReact.statefulComponent "TypeSystem";

type typeItems = array SharedTypes.typeItem;

let handleSearchChange event {ReasonReact.state: state} => {
  let searchTypeTerm = (
                         ReactDOMRe.domElementToObj (
                           ReactEventRe.Form.target event
                         )
                       )##value;
  ReasonReact.Update {...state, searchTypeTerm}
};

let handleTypeClick event {ReasonReact.state: state} => {
  let selectedKey = (
                      ReactDOMRe.domElementToObj (
                        ReactEventRe.Mouse.target event
                      )
                    )##innerText;
  ReasonReact.Update {...state, selectedKey, selectedProperty: ""}
};

let handlePropertyClick event {ReasonReact.state: state} => {
  let selectedProperty = (
                           ReactDOMRe.domElementToObj (
                             ReactEventRe.Mouse.target event
                           )
                         )##innerText;
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

let make ::data _children => {
  ...component,
  initialState: fun () => {
    let keys = Array.map (fun typeItem => typeItem##_type) data;
    Array.fast_sort compare keys;
    {keys, searchTypeTerm: "", selectedKey: "", selectedProperty: ""}
  },
  render: fun {state, update} => {
    let selectedType = findTypeByKey data key::state.selectedKey ();
    <div className=typeSystemPanelCls>
      <TypeListPanel
        selectedKey=state.selectedKey
        searchCriteria=state.searchTypeTerm
        typeList=state.keys
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
