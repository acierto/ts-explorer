let doFilter filters data =>
  if (DataUtils.hasValue filters##hasContainerType) {
    Array.fold_left
      (
        fun acc item =>
          if (item##containerType == filters##hasContainerType) {
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
