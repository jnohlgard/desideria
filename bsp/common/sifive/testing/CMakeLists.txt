# interface for running tests in QEMU
deri_add_library(deri_bsp_testing INTERFACE)
deri_target_depends(deri_bsp_testing INTERFACE
  deri_bsp
  deri_core_testing
  deri_dev_sifive_test
  deri_core_testing_console_finisher # TODO: Rewrite test harness
  )
