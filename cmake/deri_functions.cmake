include_guard(GLOBAL)

# Enter all immediate subdirectories which have a CMakeLists.txt file
macro(add_all_subdirectories)
  file(GLOB subdirectory_cmakelists */CMakeLists.txt)
  foreach (cmakelist IN LISTS subdirectory_cmakelists)
    get_filename_component(subdir "${cmakelist}" DIRECTORY)
    add_subdirectory(${subdir})
  endforeach()
endmacro()


function(deri_add_library target_name library_kind) # ... ARGN sources
  add_library(${target_name} ${library_kind} EXCLUDE_FROM_ALL)
  # INTERFACE libraries can be used to get conditional compilation and weak symbols
  # working better by propagating the sources all the way down to the main executable target.
  if (library_kind STREQUAL "INTERFACE")
    set(source_type "INTERFACE")
    set(flags_type "INTERFACE")
  else()
    set(source_type "PRIVATE")
    set(flags_type "PUBLIC")
  endif()
  target_sources(${target_name} ${source_type} ${ARGN})
  # Here we make sure we always have a dependency on the compile flags on all targets.
  target_link_libraries(${target_name} ${flags_type} deri_flags)
endfunction()

function(deri_target_depends target_name dep_kind) # ... ARGN dependencies
  target_link_libraries(${target_name} ${dep_kind} ${ARGN})
  foreach(dep IN LISTS ARGN)
    # propagate interface sources
    target_sources(${target_name} INTERFACE $<TARGET_PROPERTY:${dep},INTERFACE_SOURCES>)
  endforeach()
endfunction()

function(deri_configure_target target_name)
  deri_target_depends(${target_name} PUBLIC deri::deri)
  if (DERI_SIZE)
    add_custom_command(TARGET ${target_name} POST_BUILD
      COMMAND ${DERI_SIZE} "$<TARGET_FILE_NAME:${target_name}>"
      WORKING_DIRECTORY "$<TARGET_FILE_DIR:${target_name}>"
      COMMENT "Size report for ${target_name}")
  endif ()
endfunction()
