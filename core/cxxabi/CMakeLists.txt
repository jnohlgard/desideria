add_library(deri_cxxabi STATIC
  cxa_pure_virtual.cpp
  operator_delete.cpp
  )
target_link_libraries(deri_cxxabi PRIVATE deri_core)
set_target_properties(deri_cxxabi PROPERTIES LINK_INTERFACE_MULTIPLICITY 3)
