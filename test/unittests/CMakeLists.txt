add_executable(unittests unittest_main.cpp
  list/test_forward_list.cpp
  )
deri_configure_target(unittests)
target_link_libraries(unittests PRIVATE deri_testing)
target_link_options(unittests PUBLIC LINKER:--defsym=_main_stack_size=4096)
add_test(NAME unittests COMMAND unittests)
