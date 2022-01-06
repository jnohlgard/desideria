deri_add_library(deri_dev_timer_riscv STATIC
  timer_riscv.cpp
  ../../include/deri/dev/timer_riscv.hpp
  ../../include/deri/soc/mtime_dev.hpp
  )

target_include_directories(deri_dev_timer_riscv PUBLIC ../../include)
deri_target_depends(deri_dev_timer_riscv PUBLIC deri_soc)
