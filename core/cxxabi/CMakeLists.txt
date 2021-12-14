deri_add_library(deri_core_cxxabi STATIC
  cxa_pure_virtual.cpp
  cxa_guard.cpp
  operator_delete.cpp
  )
target_link_libraries(deri_core_cxxabi PRIVATE deri_core_include deri_arch)
