/*
 * Copyright (C) 2020 Joakim Nohlgård <joakim@nohlgard.se>
 */

#include <cstdint>

extern "C" void deri_init();

extern "C" int main(int argc = 0, char *argv[] = nullptr,
                    char *env[] = nullptr);

extern uint32_t _bss_begin[];
extern uint32_t _bss_end[];

extern const uint32_t _data_load[];
extern uint32_t _data_begin[];
extern uint32_t _data_end[];

void deri_init() {
  for (uint32_t *dst = &_bss_begin[0]; dst < &_bss_end[0]; ++dst) {
    *dst = 0UL;
  }

  const uint32_t *src = &_data_load[0];
  for (uint32_t *dst = &_data_begin[0];
       dst < &_data_end[0]; ++dst, ++src) {
    *dst = *src;
  }

  __extension__ main();
}
