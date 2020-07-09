add_library(deri_core STATIC
  assert.cpp
  include/deri/assert.h
  include/deri/console.h
  die.cpp
  include/deri/die.h
  init.cpp
  syscalls.cpp
  )
target_include_directories(deri_core PUBLIC include)

add_subdirectory(cxxabi)
add_subdirectory(testing)

target_link_libraries(deri_core PUBLIC deri_dev_common deri_cxxabi deri_bsp)
