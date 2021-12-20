add_all_subdirectories()

deri_add_library(deri_dev_common INTERFACE
  include/deri/dev/charbuf.hpp
  include/deri/dev/charnull.hpp
  include/deri/dev/gpio.hpp
  include/deri/dev/timer.hpp
  include/deri/dev/uart.hpp
  include/deri/registers.hpp
  )
target_include_directories(deri_dev_common INTERFACE include)
deri_target_depends(deri_dev_common INTERFACE deri_core_include)
