/* *** Generated with Desideria SVD converter *** */
#pragma once

/* Hardware module map for FE310 */
/* The FE310-G000 is the first Freedom E300 SoC, and forms the basis of the HiFive1 development board for the Freedom E300 family. The FE310-G000 is built around the E31 Coreplex instantiated in the Freedom E300 platform. */
PROVIDE(CLINT$           = 0x2000000);
PROVIDE(PLIC$            = 0xc000000);
PROVIDE(WDOG$            = 0x10000000);
PROVIDE(RTC$             = 0x10000040);
PROVIDE(AONCLK$          = 0x10000070);
PROVIDE(BACKUP$          = 0x10000080);
PROVIDE(PMU$             = 0x10000100);
PROVIDE(PRCI$            = 0x10008000);
PROVIDE(OTP$             = 0x10010000);
PROVIDE(GPIO0$           = 0x10012000);
PROVIDE(UART0$           = 0x10013000);
PROVIDE(QSPI0$           = 0x10014000);
PROVIDE(PWM0$            = 0x10015000);
PROVIDE(I2C0$            = 0x10016000);
PROVIDE(UART1$           = 0x10023000);
PROVIDE(QSPI1$           = 0x10024000);
PROVIDE(PWM1$            = 0x10025000);
PROVIDE(QSPI2$           = 0x10034000);
PROVIDE(PWM2$            = 0x10035000);

/* C++ mangled names below */
PROVIDE(_ZN4deri4mmio5CLINTE = CLINT$);
PROVIDE(_ZN4deri4mmio4PLICE = PLIC$);
PROVIDE(_ZN4deri4mmio4WDOGE = WDOG$);
PROVIDE(_ZN4deri4mmio3RTCE = RTC$);
PROVIDE(_ZN4deri4mmio6AONCLKE = AONCLK$);
PROVIDE(_ZN4deri4mmio6BACKUPE = BACKUP$);
PROVIDE(_ZN4deri4mmio3PMUE = PMU$);
PROVIDE(_ZN4deri4mmio4PRCIE = PRCI$);
PROVIDE(_ZN4deri4mmio3OTPE = OTP$);
PROVIDE(_ZN4deri4mmio5GPIO0E = GPIO0$);
PROVIDE(_ZN4deri4mmio5UART0E = UART0$);
PROVIDE(_ZN4deri4mmio5QSPI0E = QSPI0$);
PROVIDE(_ZN4deri4mmio4PWM0E = PWM0$);
PROVIDE(_ZN4deri4mmio4I2C0E = I2C0$);
PROVIDE(_ZN4deri4mmio5UART1E = UART1$);
PROVIDE(_ZN4deri4mmio5QSPI1E = QSPI1$);
PROVIDE(_ZN4deri4mmio4PWM1E = PWM1$);
PROVIDE(_ZN4deri4mmio5QSPI2E = QSPI2$);
PROVIDE(_ZN4deri4mmio4PWM2E = PWM2$);


/* Interrupt handlers weakly defined to point to the default handler */
PROVIDE(isr_unused = isr_unhandled);
PROVIDE(isr_WATCHDOG = isr_unhandled);
PROVIDE(isr_RTC = isr_unhandled);
PROVIDE(isr_UART0 = isr_unhandled);
PROVIDE(isr_UART1 = isr_unhandled);
PROVIDE(isr_QSPI0 = isr_unhandled);
PROVIDE(isr_QSPI1 = isr_unhandled);
PROVIDE(isr_QSPI2 = isr_unhandled);
PROVIDE(isr_GPIO0 = isr_unhandled);
PROVIDE(isr_GPIO1 = isr_unhandled);
PROVIDE(isr_GPIO2 = isr_unhandled);
PROVIDE(isr_GPIO3 = isr_unhandled);
PROVIDE(isr_GPIO4 = isr_unhandled);
PROVIDE(isr_GPIO5 = isr_unhandled);
PROVIDE(isr_GPIO6 = isr_unhandled);
PROVIDE(isr_GPIO7 = isr_unhandled);
PROVIDE(isr_GPIO8 = isr_unhandled);
PROVIDE(isr_GPIO9 = isr_unhandled);
PROVIDE(isr_GPIO10 = isr_unhandled);
PROVIDE(isr_GPIO11 = isr_unhandled);
PROVIDE(isr_GPIO12 = isr_unhandled);
PROVIDE(isr_GPIO13 = isr_unhandled);
PROVIDE(isr_GPIO14 = isr_unhandled);
PROVIDE(isr_GPIO15 = isr_unhandled);
PROVIDE(isr_GPIO16 = isr_unhandled);
PROVIDE(isr_GPIO17 = isr_unhandled);
PROVIDE(isr_GPIO18 = isr_unhandled);
PROVIDE(isr_GPIO19 = isr_unhandled);
PROVIDE(isr_GPIO20 = isr_unhandled);
PROVIDE(isr_GPIO21 = isr_unhandled);
PROVIDE(isr_GPIO22 = isr_unhandled);
PROVIDE(isr_GPIO23 = isr_unhandled);
PROVIDE(isr_GPIO24 = isr_unhandled);
PROVIDE(isr_GPIO25 = isr_unhandled);
PROVIDE(isr_GPIO26 = isr_unhandled);
PROVIDE(isr_GPIO27 = isr_unhandled);
PROVIDE(isr_GPIO28 = isr_unhandled);
PROVIDE(isr_GPIO29 = isr_unhandled);
PROVIDE(isr_GPIO30 = isr_unhandled);
PROVIDE(isr_GPIO31 = isr_unhandled);
PROVIDE(isr_PWM0CMP0 = isr_unhandled);
PROVIDE(isr_PWM0CMP1 = isr_unhandled);
PROVIDE(isr_PWM0CMP2 = isr_unhandled);
PROVIDE(isr_PWM0CMP3 = isr_unhandled);
PROVIDE(isr_PWM1CMP0 = isr_unhandled);
PROVIDE(isr_PWM1CMP1 = isr_unhandled);
PROVIDE(isr_PWM1CMP2 = isr_unhandled);
PROVIDE(isr_PWM1CMP3 = isr_unhandled);
PROVIDE(isr_PWM2CMP0 = isr_unhandled);
PROVIDE(isr_PWM2CMP1 = isr_unhandled);
PROVIDE(isr_PWM2CMP2 = isr_unhandled);
PROVIDE(isr_PWM2CMP3 = isr_unhandled);
PROVIDE(isr_I2C0 = isr_unhandled);
