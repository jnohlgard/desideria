deri_add_library(deri_dev_clock_sifive STATIC
  clock_sifive.cpp
  ../../include/deri/dev/clock_sifive.hpp
  )

target_include_directories(deri_dev_clock_sifive PUBLIC ../../include)
deri_target_depends(deri_dev_clock_sifive PUBLIC deri_soc)
