deri_add_library(deri_dev_sifive_test STATIC
  sifive_test.cpp
  )

deri_target_depends(deri_dev_sifive_test PUBLIC
  deri_dev_common
  deri_core_testing
  )
