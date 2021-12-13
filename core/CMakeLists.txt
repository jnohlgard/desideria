deri_add_library(deri_core STATIC
  include/deri/assert.hpp
  include/deri/console.hpp
  include/deri/die.hpp
  include/deri/idle.hpp
  include/deri/list.hpp
  include/deri/mutex.hpp
  include/deri/panic.hpp
  include/deri/syscall.hpp
  include/deri/thread.hpp
  assert.cpp
  die.cpp
  idle.cpp
  thread.cpp
  )
deri_add_library(deri_core_obj OBJECT
  init.cpp
  syscalls.cpp
  )
deri_add_library(deri_core_include INTERFACE)
target_include_directories(deri_core_include INTERFACE include)
deri_target_depends(deri_core PUBLIC deri_core_obj $<TARGET_OBJECTS:deri_core_obj>)
deri_target_depends(deri_core PUBLIC deri_core_include)
deri_target_depends(deri_core_obj PUBLIC deri_core_include)
deri_target_depends(deri_core_obj PUBLIC deri_bsp_common deri_bsp_periph)

add_subdirectory(cxxabi)
add_subdirectory(testing)

deri_target_depends(deri_core PUBLIC
  deri_dev_common
  deri_core_cxxabi
  deri_arch
  )
