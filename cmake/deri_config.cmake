include_guard(GLOBAL)
include(deri_functions)
# Global configuration variables that can be assumed to be available in all Desideria project configurations

# Check if we are the main project or if this CMake invocation is inside add_subdirectory(desideria)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(DERI_STANDALONE_BUILD ON)
else()
  set(DERI_STANDALONE_BUILD OFF)
endif()

add_library(deri_flags INTERFACE)
add_library(deri_base_flags INTERFACE)
add_library(deri_bsp_flags INTERFACE)
add_library(deri_arch_flags INTERFACE)
target_link_libraries(deri_flags INTERFACE deri_base_flags)
target_link_libraries(deri_flags INTERFACE deri_bsp_flags)
target_link_libraries(deri_flags INTERFACE deri_arch_flags)

# Path configuration
set(DERI_BASEDIR ${PROJECT_SOURCE_DIR} CACHE PATH "Path to the Desideria source tree root")
set(DERI_ARCH_BASEDIR ${DERI_BASEDIR}/arch CACHE PATH "Path to arch component of the Desideria tree")
set(DERI_BSP_BASEDIR ${DERI_BASEDIR}/bsp CACHE PATH "Path to bsp component of the Desideria tree")
set(DERI_BSP_DIR ${DERI_BSP_BASEDIR}/${BOARD} CACHE PATH "Path to board-specific code")

# Load board specific CMake settings
list(PREPEND CMAKE_MODULE_PATH "${DERI_BSP_DIR}/cmake")
include(deri_bsp)

# deri_bsp.cmake above should set ${ARCH}
if(NOT ARCH)
  message(FATAL_ERROR "Missing ARCH setting in deri_bsp.cmake")
endif()
set(DERI_ARCH_DIR "${DERI_ARCH_BASEDIR}/${ARCH}" CACHE PATH "Path to the architecture-specific code")
list(PREPEND CMAKE_MODULE_PATH "${DERI_ARCH_DIR}/cmake")
include(deri_arch)

if (NOT BOARD STREQUAL "hosted")
  set(CMAKE_EXECUTABLE_SUFFIX .elf)
endif ()

option(DERI_WERROR "Build with all warnings as errors" ON)
option(DERI_DEVELHELP "Enable helpful developer settings. This will add some extra checks which indicate programmer mistakes and add some extra debug output in various places." OFF)

# Compress debug info. This saves approximately 50% of disk usage.
# It has no effect if debugging information is not emitted, so it can be left
# on unconditionally.
option(DERI_COMPRESS_DEBUG "Compress debug info" ON)
mark_as_advanced(DERI_COMPRESS_DEBUG)

option(DERI_CC_COLOR "Provide colored compiler output" ON)
mark_as_advanced(DERI_CC_COLOR)
