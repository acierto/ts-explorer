let getFilteredData data filters => {
  let filteredData = HasInterfaceFilter.doFilter data filters;
  HasPropertyFilter.doFilter filteredData filters;
};