open Glamor;

let typeSystemPanelCls = css [height "inherit"];

type state = {
  keys: array string,
  selectedKey: string,
  selectedProperty: string
};

let component = ReasonReact.statefulComponent "TypeSystem";

type typeItems = array SharedTypes.typeItem;

let handleTypeClick event {ReasonReact.state: state} => {
  let selectedKey = (
                      ReactDOMRe.domElementToObj (
                        ReactEventRe.Mouse.target event
                      )
                    )##innerText;
  ReasonReact.Update {...state, selectedKey}
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
    {keys, selectedKey: "", selectedProperty: ""}
  },
  render: fun {state, update} => {
    let selectedType = findTypeByKey data key::state.selectedKey ();
    <div className=typeSystemPanelCls>
      <TypeListPanel
        selectedKey=state.selectedKey
        typeList=state.keys
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
