#include "deri/arch/irq.h"

extern "C" void hang();

const int const_data[2] = {999, 1123456};
int bss_var;
int global_var = 1;
int global_arr[2] = {1234, 5678};
void hang() {
  global_arr[0] = const_data[1];
  while (1) {
    ++bss_var;
    ++global_var;
    {
      const InterruptGuard irq_lock;
      global_arr[0]++;
    }
  }
}
