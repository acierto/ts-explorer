type typeItem =
  Js.t {
    .
    _type : string,
    _virtual : bool,
    description : string,
    icon : string,
    interfaces : list string,
    properties : array (Js.t {. name : string}),
    superTypes : list string,
    root : string
  };