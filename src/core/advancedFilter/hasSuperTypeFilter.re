let doFilter filters data =>
  if (DataUtils.hasValue filters##hasSupertype) {
    Array.fold_left
      (
        fun acc item =>
          if (List.exists (fun el => el == filters##hasSupertype) (Array.to_list item##superTypes)) {
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
