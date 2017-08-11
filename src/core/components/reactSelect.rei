let make:
  name::string =>
  value::string =>
  options::(array SharedTypes.optionType) =>
  onChange::(string => unit) =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps;
