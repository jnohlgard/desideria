deri_add_library(deri_sys_time STATIC
  time.cpp
  ../include/deri/time.hpp
  )

target_include_directories(deri_sys_time PUBLIC ../include)
deri_target_depends(deri_sys_time PUBLIC deri_soc deri_bsp)
