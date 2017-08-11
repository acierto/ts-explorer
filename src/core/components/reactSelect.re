external modalClass : ReasonReact.reactClass = "default" [@@bs.module "react-select"];

let make ::name ::value ::options ::onChange children =>
  ReasonReact.wrapJsForReason
    reactClass::modalClass
    props::{"name": name, "value": value, "options": options, "onChange": onChange}
    children;
