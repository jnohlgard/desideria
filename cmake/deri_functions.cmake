include_guard(GLOBAL)

# Enter all immediate subdirectories which have a CMakeLists.txt file
macro(add_all_subdirectories)
  file(GLOB subdirectory_cmakelists */CMakeLists.txt)
  foreach (cmakelist IN LISTS subdirectory_cmakelists)
    get_filename_component(subdir "${cmakelist}" DIRECTORY)
    add_subdirectory(${subdir})
  endforeach ()
endmacro()

function(deri_add_library target_name library_kind) # ... ARGN sources
  add_library(${target_name} ${library_kind} EXCLUDE_FROM_ALL ${ARGN})
  if (library_kind STREQUAL "INTERFACE")
    set(flags_type "INTERFACE")
  else ()
    set(flags_type "PUBLIC")
  endif ()
  # Make sure we always have a dependency on the compile flags on all targets.
  target_link_libraries(${target_name} ${flags_type} deri_flags)
endfunction()

function(deri_target_depends target_name dep_kind) # ... ARGN dependencies
  target_link_libraries(${target_name} ${dep_kind} ${ARGN})
endfunction()

function(deri_configure_target target_name)
  deri_target_depends(${target_name} PUBLIC deri::deri)
  target_link_options(${target_name} PUBLIC "LINKER:-Map=$<TARGET_FILE:${target_name}>.map")
  if (DERI_SIZE)
    add_custom_command(TARGET ${target_name} POST_BUILD
      COMMAND ${DERI_SIZE} "$<TARGET_FILE_NAME:${target_name}>"
      WORKING_DIRECTORY "$<TARGET_FILE_DIR:${target_name}>"
      COMMENT "Size report for ${target_name}")
  endif ()
  if (CMAKE_OBJCOPY)
    add_custom_command(TARGET ${target_name} POST_BUILD
      COMMAND ${CMAKE_OBJCOPY} "$<TARGET_FILE_NAME:${target_name}>" -O ihex "$<TARGET_FILE_NAME:${target_name}>.hex"
      WORKING_DIRECTORY "$<TARGET_FILE_DIR:${target_name}>"
      COMMENT "Produce ihex file for ${target_name}")
    add_custom_command(TARGET ${target_name} POST_BUILD
      COMMAND ${CMAKE_OBJCOPY} "$<TARGET_FILE_NAME:${target_name}>" -O binary "$<TARGET_FILE_NAME:${target_name}>.bin"
      WORKING_DIRECTORY "$<TARGET_FILE_DIR:${target_name}>"
      COMMENT "Produce bin file for ${target_name}")
  endif ()
endfunction()
