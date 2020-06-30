add_executable(test_minimal main.cpp)
deri_configure_target(test_minimal)
target_link_libraries(test_minimal PRIVATE deri_testing)
add_test(NAME minimal COMMAND test_minimal)
