/* *** Generated with Desideria SVD converter *** */
#pragma once

namespace deri::mmio {
// Forward declarations of MMIO peripheral register maps
struct ADC_regs;
struct AFIO_regs;
struct BKP_regs;
struct CAN_regs;
struct CRC_regs;
struct DAC_regs;
struct DBG_regs;
struct DMA_regs;
struct EXMC_regs;
struct EXTI_regs;
struct FMC_regs;
struct FWDGT_regs;
struct I2C_regs;
struct ECLIC_regs;
struct PMU_regs;
struct RCU_regs;
struct RTC_regs;
struct SPI_regs;
struct TIMER_regs;
struct USART_regs;
struct UART_regs;
struct USBFS_GLOBAL_regs;
struct USBFS_HOST_regs;
struct USBFS_DEVICE_regs;
struct USBFS_PWRCLK_regs;
struct WWDGT_regs;
struct GPIO_regs;

// MMIO peripheral instances
// These symbols need to be provided by the linker scripts
extern ADC_regs ADC0;
extern ADC_regs ADC1;
extern AFIO_regs AFIO;
extern BKP_regs BKP;
extern CAN_regs CAN0;
extern CAN_regs CAN1;
extern CRC_regs CRC;
extern DAC_regs DAC;
extern DBG_regs DBG;
extern DMA_regs DMA0;
extern DMA_regs DMA1;
extern EXMC_regs EXMC;
extern EXTI_regs EXTI;
extern FMC_regs FMC;
extern FWDGT_regs FWDGT;
extern GPIO_regs GPIOA;
extern GPIO_regs GPIOB;
extern GPIO_regs GPIOC;
extern GPIO_regs GPIOD;
extern GPIO_regs GPIOE;
extern I2C_regs I2C0;
extern I2C_regs I2C1;
extern ECLIC_regs ECLIC;
extern PMU_regs PMU;
extern RCU_regs RCU;
extern RTC_regs RTC;
extern SPI_regs SPI0;
extern SPI_regs SPI1;
extern SPI_regs SPI2;
extern TIMER_regs TIMER0;
extern TIMER_regs TIMER1;
extern TIMER_regs TIMER2;
extern TIMER_regs TIMER3;
extern TIMER_regs TIMER4;
extern TIMER_regs TIMER5;
extern TIMER_regs TIMER6;
extern USART_regs USART0;
extern USART_regs USART1;
extern USART_regs USART2;
extern UART_regs UART3;
extern UART_regs UART4;
extern USBFS_GLOBAL_regs USBFS_GLOBAL;
extern USBFS_HOST_regs USBFS_HOST;
extern USBFS_DEVICE_regs USBFS_DEVICE;
extern USBFS_PWRCLK_regs USBFS_PWRCLK;
extern WWDGT_regs WWDGT;
}  // namespace deri::mmio
