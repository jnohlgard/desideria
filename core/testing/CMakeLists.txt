deri_add_library(deri_core_testing INTERFACE)
target_include_directories(deri_core_testing INTERFACE include)

deri_add_library(deri_core_testing_console_finisher STATIC
  console_finish.cpp
  )
deri_target_depends(deri_core_testing_console_finisher PUBLIC
  deri_core
  deri_core_testing
  )
