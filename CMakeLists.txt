cmake_minimum_required(VERSION 3.14)

project(desideria LANGUAGES C CXX ASM)

if(NOT BOARD)
  message(FATAL_ERROR "Define BOARD to select platform: cmake -DBOARD=foo")
endif()
set(DERI_ARCH_BASEDIR ${CMAKE_CURRENT_SOURCE_DIR}/arch)
set(DERI_BSP_BASEDIR ${CMAKE_CURRENT_SOURCE_DIR}/bsp)
set(CMAKE_MODULE_PATH "${DERI_BSP_BASEDIR}/${BOARD}/cmake" "${CMAKE_MODULE_PATH}")
include(deri_platform)

if (MSVC)
  # warning level 4 and all warnings as errors
  add_compile_options(/W4 /WX)
else()
  # lots of warnings and all warnings as errors
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_compile_options(-ffreestanding -nostdlib)
add_compile_options(-fno-common -fdata-sections -ffunction-sections)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)
add_compile_options(-finline-small-functions -findirect-inlining)
add_link_options(-fno-rtti -fno-exceptions)
add_link_options(-nostdlib LINKER:--gc-sections)

set(CMAKE_EXECUTABLE_SUFFIX .elf)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(arch)
add_library(deri INTERFACE)
add_subdirectory(bsp)
add_subdirectory(core)
target_link_libraries(deri INTERFACE
  deri_arch_${ARCH}
  deri_bsp_${BOARD}
  deri_core
  )

add_library(deri_testing INTERFACE)
target_link_libraries(deri_testing INTERFACE
  deri_bsp_${BOARD}_testing
  deri_core_testing
  )

add_subdirectory(dev)

add_subdirectory(examples)

add_subdirectory(test)
