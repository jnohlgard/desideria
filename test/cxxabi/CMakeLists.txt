add_executable(test_cxxabi
  global_ctor_test.cpp
  main.cpp global_ctor_test.h)
target_include_directories(test_cxxabi PRIVATE .)
target_link_libraries(test_cxxabi PRIVATE deri deri_testing)

add_test(NAME cxxabi COMMAND test_cxxabi)
