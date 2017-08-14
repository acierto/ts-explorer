type typeItem =
  Js.t {
    .
    _type : string,
    _virtual : bool,
    description : string,
    icon : string,
    interfaces : array string,
    properties : array (Js.t {. name : string}),
    superTypes : array string,
    root : string
  };

type optionType = Js.t {. value : string, label : string};

type filtersType = Js.t {. hasInterface : string, hasProperty: string};