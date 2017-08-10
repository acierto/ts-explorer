let component = ReasonReact.statelessComponent "AdvancedFilterModalComponent";

let make ::isOpenedFilter ::onCloseFilter _children => {
  ...component,
  render: fun _ => {
      <ReactModal contentLabel="Filter" isOpen=isOpenedFilter>
        <button onClick=onCloseFilter _type="button">
          (ReasonReact.stringToElement "Apply")
        </button>
      </ReactModal>
  }
};
