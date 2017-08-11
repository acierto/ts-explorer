external modalClass : ReasonReact.reactClass = "react-select" [@@bs.module];

let make ::name ::value ::options ::onChange children =>
  ReasonReact.wrapJsForReason
    reactClass::modalClass
    props::{"name": name, "value": value, "options": options, "onChange": onChange}
    children;
