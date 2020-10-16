# picolibc subproject build

set(picolibc_extra_config_default
  -Dtests=false
  -Dpicolib=false
  -Dpicocrt=false
  -Dtinystdio=true
  )
if (ARCH STREQUAL hosted)
  list(APPEND picolibc_extra_config_default
    -Dtls-model=global-dynamic
    -Dposix-console=true
    -Dnewlib-global-atexit=true
    )
  set(picolibc_cross_options
    -Dspecsdir=none
    )
else ()
  # Get the CMake compile/link options lists and convert to Meson list format
  get_directory_property(cflags COMPILE_OPTIONS)
  # Newlib has a bunch of warnings, we need to disable -Werror
  list(REMOVE_ITEM cflags -Werror)
  set(MESON_COMPILE_OPTIONS "['$<JOIN:${cflags},', '>']")
  get_directory_property(linkflags LINK_OPTIONS)
  set(MESON_LINK_OPTIONS "['$<JOIN:${linkflags},', '>']")

  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/meson-cross-template.txt" meson_cross_in)
  string(CONFIGURE "${meson_cross_in}" meson_cross_out)
  # picolibc only requires C
  file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/cross-${ARCH}.txt CONTENT "${meson_cross_out}" CONDITION $<COMPILE_LANGUAGE:C>)

  set(picolibc_cross_options
    "-Dspecsdir=<INSTALL_DIR>/lib"
    --cross-file "${CMAKE_CURRENT_BINARY_DIR}/cross-${ARCH}.txt"
    )
endif ()

set(PICOLIBC_EXTRA_CONFIG ${picolibc_extra_config_default}
  CACHE STRING "Extra command line options to pass to meson setup in picolibc")

include(ExternalProject)
ExternalProject_Add(picolibc
  URL               ${CMAKE_CURRENT_SOURCE_DIR}/picolibc/
  PREFIX            ${CMAKE_CURRENT_BINARY_DIR}
  SOURCE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/picolibc/
  BINARY_DIR        ${CMAKE_CURRENT_BINARY_DIR}/picolibc-build/
  STAMP_DIR         ${CMAKE_CURRENT_BINARY_DIR}/picolibc-stamp/
  INSTALL_DIR       ${CMAKE_CURRENT_BINARY_DIR}
  LOG_DIR           ${CMAKE_CURRENT_BINARY_DIR}
  LOG_OUTPUT_ON_FAILURE YES
  LOG_MERGED_STDOUTERR YES
  LOG_CONFIGURE     YES
  LOG_BUILD         YES
  LOG_INSTALL       YES
  CONFIGURE_COMMAND
    meson setup <SOURCE_DIR>
    --prefix <INSTALL_DIR>
    -Dincludedir=include
    -Dlibdir=lib
    -Dmultilib=false
    ${PICOLIBC_EXTRA_CONFIG}
    ${picolibc_cross_options}
  BUILD_COMMAND     meson compile
  INSTALL_COMMAND   meson install
  TEST_COMMAND      meson test
  DOWNLOAD_COMMAND  ""
  UPDATE_COMMAND    ""
  TEST_EXCLUDE_FROM_MAIN YES
  BUILD_BYPRODUCTS
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libc.a
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libm.a
    ${CMAKE_CURRENT_BINARY_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include/math.h
    ${CMAKE_CURRENT_BINARY_DIR}/include/stdlib.h
  )

set(picolibc_clean_files
  "${CMAKE_CURRENT_BINARY_DIR}/picolibc-build"
  "${CMAKE_CURRENT_BINARY_DIR}/lib"
  "${CMAKE_CURRENT_BINARY_DIR}/include"
  )
set_target_properties(picolibc PROPERTIES ADDITIONAL_CLEAN_FILES "${picolibc_clean_files}")

set(picolibc_link_flags "-L${CMAKE_CURRENT_BINARY_DIR}/lib")
if (CMAKE_CROSSCOMPILING AND CMAKE_C_COMPILER_ID STREQUAL GNU)
  string(APPEND picolibc_link_flags " -specs=${CMAKE_CURRENT_BINARY_DIR}/lib/picolibc.specs")
endif ()
set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_BINARY_DIR}/include" CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES "${CMAKE_C_STANDARD_INCLUDE_DIRECTORIES}" CACHE INTERNAL "")
set(CMAKE_C_STANDARD_LIBRARIES "${picolibc_link_flags}" CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_C_STANDARD_LIBRARIES}" CACHE INTERNAL "")

add_library(deri_iob OBJECT iob.cpp)
add_dependencies(deri_iob picolibc)
target_link_libraries(deri_iob PUBLIC deri_dev_common)
set(DERI_STARTFILES "${DERI_STARTFILES};deri_iob" CACHE INTERNAL "")
