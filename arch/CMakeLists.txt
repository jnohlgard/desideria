if(NOT DERI_ARCH_DIR)
  message(FATAL_ERROR "DERI_ARCH_DIR is not defined")
endif()

add_subdirectory(${DERI_ARCH_DIR} deri_arch_${ARCH})
add_subdirectory(common)
