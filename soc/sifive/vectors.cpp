/* *** Generated with Desideria SVD converter *** */
#include "deri/soc/vectors.hpp"

namespace deri::soc {
[[gnu::used,
  gnu::section(".vectors"),
  gnu::aligned(512)]] arch::isr_func *const vector_table[] = {
    isr_unused,    // 0
    isr_WATCHDOG,  // 1
    isr_RTC,       // 2
    isr_UART0,     // 3
    isr_UART1,     // 4
    isr_QSPI0,     // 5
    isr_QSPI1,     // 6
    isr_QSPI2,     // 7
    isr_GPIO0,     // 8
    isr_GPIO1,     // 9
    isr_GPIO2,     // 10
    isr_GPIO3,     // 11
    isr_GPIO4,     // 12
    isr_GPIO5,     // 13
    isr_GPIO6,     // 14
    isr_GPIO7,     // 15
    isr_GPIO8,     // 16
    isr_GPIO9,     // 17
    isr_GPIO10,    // 18
    isr_GPIO11,    // 19
    isr_GPIO12,    // 20
    isr_GPIO13,    // 21
    isr_GPIO14,    // 22
    isr_GPIO15,    // 23
    isr_GPIO16,    // 24
    isr_GPIO17,    // 25
    isr_GPIO18,    // 26
    isr_GPIO19,    // 27
    isr_GPIO20,    // 28
    isr_GPIO21,    // 29
    isr_GPIO22,    // 30
    isr_GPIO23,    // 31
    isr_GPIO24,    // 32
    isr_GPIO25,    // 33
    isr_GPIO26,    // 34
    isr_GPIO27,    // 35
    isr_GPIO28,    // 36
    isr_GPIO29,    // 37
    isr_GPIO30,    // 38
    isr_GPIO31,    // 39
    isr_PWM0CMP0,  // 40
    isr_PWM0CMP1,  // 41
    isr_PWM0CMP2,  // 42
    isr_PWM0CMP3,  // 43
    isr_PWM1CMP0,  // 44
    isr_PWM1CMP1,  // 45
    isr_PWM1CMP2,  // 46
    isr_PWM1CMP3,  // 47
    isr_PWM2CMP0,  // 48
    isr_PWM2CMP1,  // 49
    isr_PWM2CMP2,  // 50
    isr_PWM2CMP3,  // 51
    isr_I2C0,      // 52
};
static_assert(sizeof(vector_table) == sizeof(arch::isr_func *) * 53);
}  // namespace deri::soc
