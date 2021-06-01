cmake_minimum_required(VERSION 3.19)
project(desideria
  VERSION 0.1.0
  HOMEPAGE_URL https://github.com/jnohlgard/desideria
  LANGUAGES C CXX ASM
  )

if (NOT BOARD)
  message(FATAL_ERROR "Define BOARD to select platform: cmake -DBOARD=foo")
endif ()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
  option(BUILD_EXAMPLES "Build all Desideria examples" ON)
endif ()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Load board specific CMake settings
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(deri_config)
include(deri_functions)
include(deri_modules)
include(deri_flags)

add_subdirectory(core)
add_subdirectory(arch)
add_subdirectory(bsp)
add_subdirectory(dev)
add_subdirectory(lib)

if (BUILD_TESTING AND DERI_STANDALONE_BUILD)
  add_subdirectory(test)
endif ()
if (BUILD_EXAMPLES AND DERI_STANDALONE_BUILD)
  add_subdirectory(examples)
endif ()

