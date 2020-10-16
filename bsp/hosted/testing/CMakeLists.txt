add_library(deri_bsp_${BOARD}_testing STATIC
  hosted_finisher.cpp
  finish.cpp
  include/deri/bsp/hosted_finisher.h
  )
target_include_directories(deri_bsp_${BOARD}_testing PUBLIC include)
target_link_libraries(deri_bsp_${BOARD}_testing PUBLIC deri_core_testing)
