deri_add_library(deri_dev_sifive_test STATIC
  sifive_test.cpp
  ../include/deri/dev/sifive_test.h
  )

target_include_directories(deri_dev_sifive_test PUBLIC ../include)
deri_target_depends(deri_dev_sifive_test PUBLIC deri_core_testing)
