open Glamor;

external jsonStringify : 'a => string = "JSON.stringify" [@@bs.val];

let buttonsPanelCls = css [bottom "10px", position "absolute", right "10px"];

let noOutlineStyles = [outline "none"];

let btnCls = css [Selector ":focus, &:active:focus" noOutlineStyles];

let headerCls = css [textAlign "center"];

let component = ReasonReact.statelessComponent "AdvancedFilterModalComponent";

let make ::interfaces ::isOpenedFilter ::onCloseFilter ::onApplyFilter _children => {
  ...component,
  render: fun _ =>
    <ReactModal contentLabel="Filter" isOpen=isOpenedFilter>
      <h3 className=headerCls>(ReasonReact.stringToElement "Advanced Filter")</h3>
      <div>
      	<span>(ReasonReact.stringToElement "Has interface")</span>
	<span>(PrintUtils.valueToElement interfaces)</span>
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
