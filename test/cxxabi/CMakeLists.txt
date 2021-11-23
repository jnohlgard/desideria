add_executable(test_cxxabi
  global_ctor_test.cpp
  main.cpp
  global_ctor_test.hpp
  )
deri_configure_target(test_cxxabi)
target_link_libraries(test_cxxabi PRIVATE deri_testing)

add_test(NAME cxxabi COMMAND test_cxxabi)
