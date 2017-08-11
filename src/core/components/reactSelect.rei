let make:
  name::string =>
  value::string =>
  options::array (Js.t{..}) =>
  onChange::(string => unit) =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
