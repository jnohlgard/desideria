if(NOT BOARD)
  message(FATAL_ERROR "Define BOARD to select platform: cmake -DBOARD=foo")
endif()
# Path configuration
set(DERI_BASEDIR ${DERI_BASEDIR} CACHE PATH "Path to the Desidera source tree root")
set(DERI_ARCH_BASEDIR ${DERI_BASEDIR}/arch CACHE PATH "Path to arch component of the Desidera tree")
set(DERI_BSP_BASEDIR ${DERI_BASEDIR}/bsp CACHE PATH "Path to bsp component of the Desidera tree")
set(DERI_BSP_DIR ${DERI_BSP_BASEDIR}/${BOARD} CACHE PATH "Path to board specific code")

# Use deri_configure_target to set all required linker options and libraries for building an executable
macro(deri_configure_target name)
  target_link_libraries(${name} PRIVATE desideria ${DERI_STARTFILES})
  set_target_properties(${name} PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
  target_link_options(${name} PRIVATE LINKER:-Map=$<TARGET_FILE_BASE_NAME:${name}>.map)
endmacro()

# Load board specific CMake settings
list(APPEND CMAKE_MODULE_PATH "${DERI_BSP_DIR}/cmake" "${CMAKE_MODULE_PATH}")
include(deri_platform)
include(deri_common_options)

add_subdirectory(${DERI_BASEDIR} ${CMAKE_CURRENT_BINARY_DIR}/deri)
