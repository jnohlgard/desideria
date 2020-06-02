add_library(deri_cxxabi STATIC
  cxa_pure_virtual.cpp
  operator_delete.cpp
  )
target_link_libraries(deri_cxxabi PRIVATE deri_core)
