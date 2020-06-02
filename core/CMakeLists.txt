add_library(deri_core STATIC
  init.cpp
  include/deri/die.h
  die.cpp
  include/deri/console.h
  )
target_include_directories(deri_core PUBLIC include)

add_subdirectory(cxxabi)
add_subdirectory(testing)

target_link_libraries(deri_core PUBLIC deri_dev_common deri_cxxabi deri_bsp)
