let collectItems getListOfItemsFn getItemValueFn data => {
  let items =
    Array.of_list @@
    Array.fold_left
      (
        fun acc item => {
          let _items = getListOfItemsFn item;
          if (not (Js_undefined.testAny _items)) {
            List.append acc @@
            Array.fold_left
              (
                fun _acc _item => {
                  let itemValue = getItemValueFn _item;
                  if (not @@ List.exists (fun el => el == itemValue) acc) {
                    List.append _acc [itemValue]
                  } else {
                    _acc
                  }
                }
              )
              []
              _items
          } else {
            acc
          }
        }
      )
      []
      data;
  Array.fast_sort compare items;
  items
};

let getAllInterfaces data => {
  let getListOfItemsFn item => item##interfaces;
  let getItemValueFn item => item;
  collectItems getListOfItemsFn getItemValueFn data
};

let getAllSuperTypes data => {
  let getListOfItemsFn item => item##superTypes;
  let getItemValueFn item => item;
  collectItems getListOfItemsFn getItemValueFn data
};

let getAllPropertyNames data => {
  let getListOfItemsFn item => item##properties;
  let getItemValueFn item => item##name;
  collectItems getListOfItemsFn getItemValueFn data
};

let getAllContainerTypes data => {
  let getListOfItemsFn item => [|item##containerType|];
  let getItemValueFn item => item;
  collectItems getListOfItemsFn getItemValueFn data
};

let hasValue _value => not (Js_undefined.testAny _value) && _value != "";

let getTypeProperties _type =>
  Array.fold_left (fun acc property => Array.append acc [|property##name|]) [||] _type##properties;
