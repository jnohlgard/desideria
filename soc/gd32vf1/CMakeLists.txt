deri_add_library(deri_soc INTERFACE
  )
target_link_directories(deri_soc INTERFACE ld)
if (SOC_MODEL MATCHES "gd32vf103")
  target_include_directories(deri_soc INTERFACE gd32vf103/include)
endif()
