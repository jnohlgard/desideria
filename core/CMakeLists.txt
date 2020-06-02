add_library(deri_core STATIC
  init.cpp
  include/deri/die.h
  die.cpp
  )
target_include_directories(deri_core PUBLIC include)
