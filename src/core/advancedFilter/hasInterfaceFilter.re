let doFilter data filters =>
  if (DataUtils.hasValue filters##hasInterface) {
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
