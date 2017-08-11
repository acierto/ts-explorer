let getAllInterfaces data => {
  let allInterfaces =
    Array.of_list @@
    Array.fold_left
      (
        fun acc item =>
          if (not (Js_undefined.testAny item##interfaces)) {
            List.append acc @@
            Array.fold_left
              (
                fun _acc _item =>
                  if (not @@ List.exists (fun el => el == _item) acc) {
                    List.append _acc [_item]
                  } else {
                    _acc
                  }
              )
              []
              item##interfaces
          } else {
            acc
          }
      )
      []
      data;
  Array.fast_sort compare allInterfaces;
  allInterfaces
};

let getFilteredData data filters =>
  if (not (Js_undefined.testAny filters##hasInterface)) {
    Array.fold_left
      (
        fun acc item =>
          if (List.exists (fun el => el == filters##hasInterface) (Array.to_list item##interfaces)) {
            Array.append acc [|item|]
          } else {
            acc
          }
      )
      [||]
      data
  } else {
    data
  };
