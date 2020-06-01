set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR riscv)

set(CMAKE_C_COMPILER "riscv64-unknown-elf-gcc")
set(CMAKE_CXX_COMPILER "riscv64-unknown-elf-g++")

# never look in the target sysroot for programs and tools
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# look for libraries and headers on the target sysroot only
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
