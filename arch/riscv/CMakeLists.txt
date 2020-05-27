add_library(arch_riscv STATIC
  startup.c
  include/riscv/asm.h
  )
target_include_directories(arch_riscv PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(arch_riscv PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/include)
