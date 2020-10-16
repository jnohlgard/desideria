cmake_minimum_required(VERSION 3.14)
project(desideria
  VERSION 0.1.0
  HOMEPAGE_URL https://github.com/gebart/desideria
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

# This internal cache variable is required to pass the list of object library files to the top level CMakeLists
set(DERI_STARTFILES "" CACHE INTERNAL "Linker dependencies that must be explicitly linked with any executable")

# Path configuration
set(DERI_BASEDIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to the Desideria source tree root")
set(DERI_ARCH_BASEDIR ${DERI_BASEDIR}/arch CACHE PATH "Path to arch component of the Desideria tree")
set(DERI_BSP_BASEDIR ${DERI_BASEDIR}/bsp CACHE PATH "Path to bsp component of the Desideria tree")
set(DERI_BSP_DIR ${DERI_BSP_BASEDIR}/${BOARD} CACHE PATH "Path to board specific code")

option(DERI_WERROR "Build with all warnings as errors" ON)

# Use deri_configure_target to set all required linker options and libraries for building an executable
macro(deri_configure_target name)
  target_link_libraries(${name} PRIVATE desideria ${DERI_STARTFILES})
  if (LINKER_SCRIPT)
    set_target_properties(${name} PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
  endif ()
  if (NOT ARCH STREQUAL hosted OR NOT CMAKE_SYSTEM_NAME STREQUAL Darwin)
    # Xcode ld64 does not support -Map
    target_link_options(${name} PRIVATE LINKER:-Map=$<TARGET_FILE_BASE_NAME:${name}>.map)
  endif ()
endmacro()

# Load board specific CMake settings
list(APPEND CMAKE_MODULE_PATH "${DERI_BSP_DIR}/cmake" "${DERI_BASEDIR}/cmake")
include(deri_platform)
include(deri_common_options)

if (MSVC)
  add_compile_options(/W4)
  if (DERI_WERROR)
    add_compile_options(/WX)
  endif ()
else ()
  # lots of warnings and all warnings as errors
  #-Wshadow -Wundef
  add_compile_options(-Wall -Wextra -pedantic)
  if (DERI_WERROR)
    add_compile_options(-Werror)
  endif ()
  add_compile_options(-Wdouble-promotion -Wconversion)
  add_compile_options(-Wswitch-enum)
  add_compile_options(-Wuninitialized -Winit-self)
  add_compile_options(-Wformat=2)
  if (CMAKE_C_COMPILER_ID STREQUAL GNU)
    add_compile_options(-Wformat-truncation -Wformat-signedness)
  endif ()
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>)
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Weffc++>)
endif ()

add_subdirectory(arch)
add_library(desideria INTERFACE)
add_subdirectory(bsp)
add_subdirectory(core)
target_link_libraries(desideria INTERFACE
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
add_subdirectory(lib)
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(test)
endif ()
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_EXAMPLES)
  add_subdirectory(examples)
endif ()

