# interface for running tests in QEMU
add_library(deri_bsp_${BOARD}_testing STATIC
  finish.cpp
  )
target_include_directories(deri_bsp_${BOARD}_testing PRIVATE include)
target_link_libraries(deri_bsp_${BOARD}_testing PUBLIC
  deri_bsp_${BOARD}
  deri_core_testing
  deri_dev_sifive_test
  )
