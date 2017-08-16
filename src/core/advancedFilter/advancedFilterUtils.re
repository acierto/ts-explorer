let getFilteredData data filters =>
  HasInterfaceFilter.doFilter filters data |> HasPropertyFilter.doFilter filters |>
  HasSuperTypeFilter.doFilter filters |>
  HasContainerTypeFilter.doFilter filters;
