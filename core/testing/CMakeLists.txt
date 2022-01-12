deri_add_library(deri_core_testing STATIC
  console_finish.cpp
  include/deri/unit_test.hpp
  unit_test.cpp
  )
target_include_directories(deri_core_testing PUBLIC include)
deri_target_depends(deri_core_testing PUBLIC
  deri_core
  )
