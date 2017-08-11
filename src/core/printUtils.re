external createString : 'a => string = "String" [@@bs.new];

external jsonStringify : 'a => string = "JSON.stringify" [@@bs.val];

external isArray : 'a => bool = "Array.isArray" [@@bs.val];

let printValue value =>
  if (isArray value) {
    createString @@ jsonStringify value
  } else {
    createString value
  };

let valueToElement value => ReasonReact.stringToElement @@ printValue value