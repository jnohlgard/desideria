if(NOT DERI_ARCH_DIR)
  message(FATAL_ERROR "DERI_ARCH_DIR is not defined")
endif()

deri_add_library(deri_arch INTERFACE)
add_subdirectory(common)
add_subdirectory(${DERI_ARCH_DIR} deri_arch_${ARCH})
deri_target_depends(deri_arch INTERFACE deri_arch_${ARCH})
