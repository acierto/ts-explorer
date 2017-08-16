type typeItem =
  Js.t {
    .
    _type : string,
    _virtual : bool,
    containerType: string,
    description : string,
    icon : string,
    interfaces : array string,
    properties : array (Js.t {. name : string}),
    superTypes : array string,
    root : string
  };

type optionType = Js.t {. value : string, label : string};

type filtersType = Js.t {. hasContainerType: string, hasInterface : string, hasProperty: string, hasSupertype: string};