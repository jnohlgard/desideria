/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <cstdint>
#include "deri/bsp_init.h"

extern "C" void deri_init();

extern "C" int main(int argc = 0, char *argv[] = nullptr,
                    char *env[] = nullptr);

extern uint32_t _bss_begin[];
extern uint32_t _bss_end[];

extern const uint32_t _data_load[];
extern uint32_t _data_begin[];
extern uint32_t _data_end[];

extern "C" typedef void (*init_func_t)();
extern init_func_t __preinit_array_start[];
extern init_func_t __preinit_array_end[];
extern init_func_t __init_array_start[];
extern init_func_t __init_array_end[];

void deri_init() {
  for (uint32_t *dst = &_bss_begin[0]; dst < &_bss_end[0]; ++dst) {
    *dst = 0UL;
  }

  const uint32_t *src = &_data_load[0];
  for (uint32_t *dst = &_data_begin[0]; dst < &_data_end[0]; ++dst, ++src) {
    *dst = *src;
  }

  // Call initializer code
  for (init_func_t *preinit_func = &__preinit_array_start[0];
       preinit_func < &__preinit_array_end[0]; ++preinit_func) {
    (*preinit_func)();
  }

  // Call constructors and other init functions
  for (init_func_t *init_func = &__init_array_start[0];
       init_func < &__init_array_end[0]; ++init_func) {
    (*init_func)();
  }

  deri::bsp::init();

  __extension__ main();
}
