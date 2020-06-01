add_executable(test_minimal main.cpp)
target_link_libraries(test_minimal PRIVATE deri deri_testing deri_dev_sifive_test)

add_test(NAME minimal COMMAND test_minimal)
