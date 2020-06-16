# picolibc subproject build

# Get the CMake compile/link options lists and convert to Meson list format
get_directory_property(cflags COMPILE_OPTIONS)
# Newlib has a bunch of warnings, we need to disable -Werror
list(REMOVE_ITEM cflags -Werror)
set(MESON_COMPILE_OPTIONS "['$<JOIN:${cflags},', '>']" )
get_directory_property(linkflags LINK_OPTIONS)
set(MESON_LINK_OPTIONS "['$<JOIN:${linkflags},', '>']" )

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/meson-cross-template.txt" meson_cross_in)
string(CONFIGURE "${meson_cross_in}" meson_cross_out)
# picolibc only requires C
file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/cross-${ARCH}.txt" CONTENT "${meson_cross_out}" CONDITION $<COMPILE_LANGUAGE:C>)

include(ExternalProject)
ExternalProject_Add(picolibc
  GIT_REPOSITORY    https://github.com/gebart/picolibc.git
  GIT_TAG           f25efe360f61ec65dafe23b299e60ae53447f9d4
  GIT_PROGRESS      YES
  GIT_CONFIG        advice.detachedHead=false
  PREFIX            "${CMAKE_CURRENT_BINARY_DIR}"
  LOG_DIR           "${CMAKE_CURRENT_BINARY_DIR}"
  LOG_OUTPUT_ON_FAILURE YES
  LOG_MERGED_STDOUTERR YES
  LOG_CONFIGURE     YES
  LOG_BUILD         YES
  LOG_INSTALL       YES
  CONFIGURE_COMMAND meson setup <SOURCE_DIR>
                    --prefix "<INSTALL_DIR>"
                    "-Dspecsdir=<INSTALL_DIR>"
                    -Dincludedir=include
                    -Dlibdir=lib
                    -Dmultilib=false
                    -Dtests=true
                    --cross-file "${CMAKE_CURRENT_BINARY_DIR}/cross-${ARCH}.txt"
  BUILD_COMMAND     meson compile
  INSTALL_COMMAND   meson install
  TEST_COMMAND      meson test
  TEST_EXCLUDE_FROM_MAIN YES
  )
