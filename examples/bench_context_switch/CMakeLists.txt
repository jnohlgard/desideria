add_executable(bench_context_switch bench_context_switch.cpp)
deri_target_depends(bench_context_switch PUBLIC deri_sys_time)
deri_configure_target(bench_context_switch)
