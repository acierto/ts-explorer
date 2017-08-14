let doFilter data filters =>
  if (DataUtils.hasValue filters##hasProperty) {
    Array.fold_left
      (
        fun acc item =>
          if (List.exists (fun el => el == filters##hasProperty) (Array.to_list @@ DataUtils.getTypeProperties item)) {
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
