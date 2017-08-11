external modalClass : ReasonReact.reactClass = "default" [@@bs.module "react-modal"];

let make ::contentLabel ::isOpen children =>
  ReasonReact.wrapJsForReason
    reactClass::modalClass
    props::{"contentLabel": contentLabel, "isOpen": Js.Boolean.to_js_boolean isOpen}
    children;
