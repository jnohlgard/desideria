if(NOT DERI_SOC_DIR)
  message(FATAL_ERROR "DERI_SOC_DIR is not defined")
endif()
add_subdirectory(${DERI_SOC_DIR} deri_soc_${SOC})
