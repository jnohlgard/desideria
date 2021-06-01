# interface for running tests in QEMU
deri_add_library(deri_bsp_${BOARD}_testing STATIC
  finish.cpp
  )
target_link_libraries(deri_bsp_${BOARD}_testing PUBLIC
  deri_bsp_${BOARD}
  deri_core_testing
  deri_dev_sifive_test
  )
