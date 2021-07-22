# picolibc subproject build

set(picolibc_extra_config_default
  -Datomic-ungetc=false
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
  get_directory_property(linkflags LINK_OPTIONS)
  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/meson-cross-template.txt" meson_cross_in)
  # Populate the compiler
  string(CONFIGURE "${meson_cross_in}" meson_cross_out @ONLY)
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
  URL               "${CMAKE_CURRENT_SOURCE_DIR}/picolibc/"
  PREFIX            "${CMAKE_CURRENT_BINARY_DIR}"
  SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/picolibc/"
  BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/picolibc-build/"
  STAMP_DIR         "${CMAKE_CURRENT_BINARY_DIR}/picolibc-stamp/"
  INSTALL_DIR       "${CMAKE_CURRENT_BINARY_DIR}"
  LOG_DIR           "${CMAKE_CURRENT_BINARY_DIR}"
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
  STEP_TARGETS install
  BUILD_BYPRODUCTS
    "${CMAKE_CURRENT_BINARY_DIR}/lib/libc.a"
    "${CMAKE_CURRENT_BINARY_DIR}/lib/libm.a"
    "${CMAKE_CURRENT_BINARY_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}/include/math.h"
    "${CMAKE_CURRENT_BINARY_DIR}/include/stdlib.h"
  )

set(picolibc_clean_files
  "${CMAKE_CURRENT_BINARY_DIR}/picolibc-build"
  "${CMAKE_CURRENT_BINARY_DIR}/lib"
  "${CMAKE_CURRENT_BINARY_DIR}/include"
  )
set_target_properties(picolibc PROPERTIES ADDITIONAL_CLEAN_FILES "${picolibc_clean_files}")

target_link_directories(deri_libc INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/lib")
if (CMAKE_CROSSCOMPILING AND CMAKE_C_COMPILER_ID STREQUAL GNU)
  target_link_options(deri_libc INTERFACE "-specs=${CMAKE_CURRENT_BINARY_DIR}/lib/picolibc.specs")
  # Workaround to get #include_next <stdlib.h> in libstdc++ headers to find picolibc stdlib.h instead of the newlib one.
  # We hoist the C++ library headers include path to come before the picolibc include path.
  target_compile_options(deri_libc INTERFACE
    -isystem=/include/c++/${CMAKE_CXX_COMPILER_VERSION}
    -isystem "${CMAKE_CURRENT_BINARY_DIR}/include"
    )
else ()
  target_compile_options(deri_libc INTERFACE
    -isystem "${CMAKE_CURRENT_BINARY_DIR}/include"
    )
endif ()

add_dependencies(deri_libc picolibc-install)
add_dependencies(deri_flags picolibc-install)
deri_add_library(deri_iob INTERFACE iob.cpp)
deri_target_depends(deri_iob INTERFACE deri_libc)
deri_target_depends(deri_iob INTERFACE deri_dev_common)
deri_target_depends(deri_core INTERFACE deri_iob)
