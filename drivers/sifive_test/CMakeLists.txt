add_library(sifive_test STATIC
  sifive_test.cpp
  include/deri/dev/sifive_test.h)

target_include_directories(sifive_test PUBLIC include)
