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
file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/cross-${ARCH}.txt CONTENT "${meson_cross_out}" CONDITION $<COMPILE_LANGUAGE:C>)

include(ExternalProject)
ExternalProject_Add(picolibc
  GIT_REPOSITORY    https://github.com/gebart/picolibc.git
  GIT_TAG           f25efe360f61ec65dafe23b299e60ae53447f9d4
  GIT_PROGRESS      YES
  GIT_CONFIG        advice.detachedHead=false
  PREFIX            ${CMAKE_CURRENT_BINARY_DIR}
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
  BUILD_BYPRODUCTS
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libc.a
    ${CMAKE_CURRENT_BINARY_DIR}/lib/libm.a
    ${CMAKE_CURRENT_BINARY_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include/math.h
    ${CMAKE_CURRENT_BINARY_DIR}/include/stdlib.h
  )

add_library(c STATIC IMPORTED GLOBAL)
set_target_properties(c PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/lib/libc.a)
add_library(m STATIC IMPORTED GLOBAL)
set_target_properties(m PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/lib/libm.a)
#set_target_properties(c PROPERTIES LINKER_LANGUAGE "C")
#set_target_properties(m PROPERTIES LINKER_LANGUAGE "C")
#add_library(c INTERFACE)
#target_link_libraries(c PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/lib/libc.a)
add_dependencies(c picolibc)
add_dependencies(m picolibc)
#add_library(m INTERFACE)
#target_link_libraries(m PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/lib/libm.a)

# CMake complains if the directory does not exist at generation when it is used by an imported target
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include)
target_include_directories(c INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/include)
target_include_directories(m INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/include)
