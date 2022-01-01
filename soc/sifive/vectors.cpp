/* *** Generated with Desideria SVD converter *** */
#include "deri/soc/vectors.hpp"

#include "deri/arch/irq.hpp"

namespace deri::soc {
[[gnu::used, gnu::section(".vectors"), gnu::aligned(128)]] void
clint_vector_table() {
  asm volatile(
      ".option norvc\n\t"
      "j deri_exception_handler\n\t"                        // 0
      "j isr_unused\n\t"                                    // 1
      "j isr_unused\n\t"                                    // 2
      "j isr_software\n\t"                                  // 3
      "j isr_unused\n\t"                                    // 4
      "j isr_unused\n\t"                                    // 5
      "j isr_unused\n\t"                                    // 6
      "j isr_mtime\n\t"                                     // 7
      "j isr_unused\n\t"                                    // 8
      "j isr_unused\n\t"                                    // 9
      "j isr_unused\n\t"                                    // 10
      "j _ZN4deri3dev3irq7IrqPlic16external_handlerEv\n\t"  // 11
      "j isr_unused\n\t"                                    // 12
      "j isr_unused\n\t"                                    // 13
      "j isr_unused\n\t"                                    // 14
      "j isr_unused\n\t"                                    // 15
  );
}

arch::isr_func *const vector_table[] = {
    plic_unused,    // 0
    plic_WATCHDOG,  // 1
    plic_RTC,       // 2
    plic_UART0,     // 3
    plic_UART1,     // 4
    plic_QSPI0,     // 5
    plic_QSPI1,     // 6
    plic_QSPI2,     // 7
    plic_GPIO0,     // 8
    plic_GPIO1,     // 9
    plic_GPIO2,     // 10
    plic_GPIO3,     // 11
    plic_GPIO4,     // 12
    plic_GPIO5,     // 13
    plic_GPIO6,     // 14
    plic_GPIO7,     // 15
    plic_GPIO8,     // 16
    plic_GPIO9,     // 17
    plic_GPIO10,    // 18
    plic_GPIO11,    // 19
    plic_GPIO12,    // 20
    plic_GPIO13,    // 21
    plic_GPIO14,    // 22
    plic_GPIO15,    // 23
    plic_GPIO16,    // 24
    plic_GPIO17,    // 25
    plic_GPIO18,    // 26
    plic_GPIO19,    // 27
    plic_GPIO20,    // 28
    plic_GPIO21,    // 29
    plic_GPIO22,    // 30
    plic_GPIO23,    // 31
    plic_GPIO24,    // 32
    plic_GPIO25,    // 33
    plic_GPIO26,    // 34
    plic_GPIO27,    // 35
    plic_GPIO28,    // 36
    plic_GPIO29,    // 37
    plic_GPIO30,    // 38
    plic_GPIO31,    // 39
    plic_PWM0CMP0,  // 40
    plic_PWM0CMP1,  // 41
    plic_PWM0CMP2,  // 42
    plic_PWM0CMP3,  // 43
    plic_PWM1CMP0,  // 44
    plic_PWM1CMP1,  // 45
    plic_PWM1CMP2,  // 46
    plic_PWM1CMP3,  // 47
    plic_PWM2CMP0,  // 48
    plic_PWM2CMP1,  // 49
    plic_PWM2CMP2,  // 50
    plic_PWM2CMP3,  // 51
    plic_I2C0,      // 52
};
static_assert(sizeof(vector_table) == sizeof(arch::isr_func *) * 53);
}  // namespace deri::soc
