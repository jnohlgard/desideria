deri_add_library(deri_dev_clock_gd32 STATIC
  rcu_gd32.cpp
  ../../include/deri/dev/clock_gd32.h
  )

target_include_directories(deri_dev_clock_gd32 PUBLIC ../../include)
deri_target_depends(deri_dev_clock_gd32 PUBLIC deri_soc)
