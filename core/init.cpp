/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include "deri/bsp_init.h"

#include <algorithm>
#include <cstdint>

extern "C" void deri_init();

extern "C" int main(int argc = 0,
                    char *argv[] = nullptr,
                    char *env[] = nullptr);

extern uint32_t _bss_begin[];
extern uint32_t _bss_end[];

extern const uint32_t _data_load_begin[];
extern const uint32_t _data_load_end[];
extern uint32_t _data_begin[];

extern "C" typedef void (*init_func_t)();
extern init_func_t __preinit_array_start[];
extern init_func_t __preinit_array_end[];
extern init_func_t __init_array_start[];
extern init_func_t __init_array_end[];

void deri_init() {
  // Wipe .bss
  std::fill(_bss_begin, _bss_end, 0UL);

  // Populate .data
  std::copy(_data_load_begin, _data_load_end, _data_begin);

  // Call initializer code
  std::for_each(__preinit_array_start, __preinit_array_end, [](auto init_func) {
    init_func();
  });

  // Call constructors and other init functions
  std::for_each(__init_array_start, __init_array_end, [](auto init_func) {
    init_func();
  });

  deri::bsp::init();

  __extension__ main();
}
