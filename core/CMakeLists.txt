deri_add_library(deri_core INTERFACE
  assert.cpp
  include/deri/assert.h
  include/deri/console.h
  die.cpp
  include/deri/die.h
  init.cpp
  syscalls.cpp
  )
add_library(deri_core_include INTERFACE)
target_include_directories(deri_core_include INTERFACE include)
target_link_libraries(deri_core INTERFACE deri_core_include)

add_subdirectory(cxxabi)
add_subdirectory(testing)

deri_target_depends(deri_core INTERFACE
  deri_dev_common
  deri_core_cxxabi
  deri_bsp
  deri_arch
  )
