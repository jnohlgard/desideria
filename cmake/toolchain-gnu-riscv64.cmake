include("${CMAKE_CURRENT_LIST_DIR}/include/toolchain-cross-base.cmake")

set(CMAKE_SYSTEM_PROCESSOR riscv)

set(CMAKE_C_COMPILER "riscv64-unknown-elf-gcc")
set(CMAKE_CXX_COMPILER "riscv64-unknown-elf-g++")

include("${CMAKE_CURRENT_LIST_DIR}/include/toolchain-gnu-common.cmake")
