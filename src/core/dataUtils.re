module SS = Set.Make String;

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
