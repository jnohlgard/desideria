#target_include_directories(CodeKata PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
add_executable(hang hang.c)
target_link_libraries(hang PRIVATE arch_${ARCH})
set_target_properties(hang PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})

# target_link_libraries(arch_${ARCH} PRIVATE spin)
