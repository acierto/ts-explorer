module SS = Set.Make String;

let getAllInterfaces data => {
  let s = SS.empty;
  let result = Array.fold_left
    (
      fun acc item =>
        if (not (Js_undefined.testAny item##interfaces)) {
          List.fold_right SS.add item##interfaces acc
        } else {
          acc
        }
    )
    s
    data;
  SS.elements result;
};
