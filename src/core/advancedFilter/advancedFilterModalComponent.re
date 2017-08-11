open Glamor;

external jsonStringify : 'a => string = "JSON.stringify" [@@bs.val];

let buttonsPanelCls = css [bottom "10px", position "absolute", right "10px"];

let noOutlineStyles = [outline "none"];

let btnCls = css [Selector ":focus, &:active:focus" noOutlineStyles];

let headerCls = css [textAlign "center"];

let component = ReasonReact.statelessComponent "AdvancedFilterModalComponent";

let changeHasInterface _val => Js.log @@ "Selected: " ^ _val;

let hasInterfaceFilterCls = css [
    Selector "> .filter-label" [display "inline-block", lineHeight "35px", verticalAlign "text-bottom"],
    Selector "> .filter-label > span" [
	display "inline-block", lineHeight "1em", marginRight "10px", top "15px", verticalAlign "middle"],
    Selector "> .Select" [display "inline-block", width "200px"]
];

let options = [||];

let make ::interfaces ::isOpenedFilter ::onCloseFilter ::onApplyFilter _children => {
  ...component,
  render: fun _ =>
    <ReactModal contentLabel="Filter" isOpen=isOpenedFilter>
      <h3 className=headerCls> (ReasonReact.stringToElement "Advanced Filter") </h3>
      <div className=hasInterfaceFilterCls>
        <span className="filter-label">
            <span>(ReasonReact.stringToElement "Has interface")</span>
        </span>
        <ReactSelect name="has-interface" value="one" options onChange=changeHasInterface />
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
