if(NOT SOC_MODEL)
  message(FATAL_ERROR "Missing SOC_MODEL setting in deri_bsp.cmake")
endif()

set(ARCH hosted)
set(CPU_CORE hosted)
set(CPU hosted)
