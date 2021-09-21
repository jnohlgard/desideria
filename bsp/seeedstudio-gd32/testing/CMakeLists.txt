deri_add_library(deri_bsp_testing INTERFACE)
deri_target_depends(deri_bsp_testing INTERFACE
  deri_core_testing
  )
