/* *** Generated with Desideria SVD converter *** */
#pragma once

#include "deri/mmio/RCU.hpp"

#include <cstdint>

namespace deri::mmio {
/**
 * Bitmasks for RCU CTL
 *
 * Control register
 */
enum class RCU_regs::CTL_bits : uint32_t {
  IRC8MEN = (1 << 0),  ///< Internal 8MHz RC oscillator Enable
  IRC8MSTB =
      (1 << 1),  ///< IRC8M Internal 8MHz RC Oscillator stabilization Flag
  IRC8MADJ_mask =
      (0x1f << 3),  ///< Internal 8MHz RC Oscillator clock trim adjust value
  IRC8MCALIB_mask =
      (0xff << 8),  ///< Internal 8MHz RC Oscillator calibration value register
  HXTALEN = (1 << 16),   ///< External High Speed oscillator Enable
  HXTALSTB = (1 << 17),  ///< External crystal oscillator (HXTAL) clock
                         ///< stabilization flag
  HXTALBPS = (1 << 18),  ///< External crystal oscillator (HXTAL) clock bypass
                         ///< mode enable
  CKMEN = (1 << 19),     ///< HXTAL Clock Monitor Enable
  PLLEN = (1 << 24),     ///< PLL enable
  PLLSTB = (1 << 25),    ///< PLL Clock Stabilization Flag
  PLL1EN = (1 << 26),    ///< PLL1 enable
  PLL1STB = (1 << 27),   ///< PLL1 Clock Stabilization Flag
  PLL2EN = (1 << 28),    ///< PLL2 enable
  PLL2STB = (1 << 29),   ///< PLL2 Clock Stabilization Flag
  Reserved_mask = 0xc0f00004  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::CTL_bits);

/**
 * Bit shifts for RCU CTL
 */
enum class RCU_regs::CTL_shift : unsigned {
  IRC8MEN = 0,
  IRC8MSTB = 1,
  IRC8MADJ = 3,
  IRC8MCALIB = 8,
  HXTALEN = 16,
  HXTALSTB = 17,
  HXTALBPS = 18,
  CKMEN = 19,
  PLLEN = 24,
  PLLSTB = 25,
  PLL1EN = 26,
  PLL1STB = 27,
  PLL2EN = 28,
  PLL2STB = 29,
};

/**
 * Bitmasks for RCU CFG0
 *
 * Clock configuration register 0 (RCU_CFG0)
 */
enum class RCU_regs::CFG0_bits : uint32_t {
  SCS_mask = (0x3 << 0),          ///< System clock switch
  SCSS_mask = (0x3 << 2),         ///< System clock switch status
  AHBPSC_mask = (0xf << 4),       ///< AHB prescaler selection
  APB1PSC_mask = (0x7 << 8),      ///< APB1 prescaler selection
  APB2PSC_mask = (0x7 << 11),     ///< APB2 prescaler selection
  ADCPSC_1_0_mask = (0x3 << 14),  ///< ADC clock prescaler selection
  PLLSEL = (1 << 16),             ///< PLL Clock Source Selection
  PREDV0_LSB = (1 << 17),         ///< The LSB of PREDV0 division factor
  PLLMF_3_0_mask = (0xf << 18),   ///< The PLL clock multiplication factor
  USBFSPSC_mask = (0x3 << 22),    ///< USBFS clock prescaler selection
  CKOUT0SEL_mask = (0xf << 24),   ///< CKOUT0 Clock Source Selection
  ADCPSC_2 = (1 << 28),           ///< Bit 2 of ADCPSC
  PLLMF_4 = (1 << 29),            ///< Bit 4 of PLLMF
  Reserved_mask = 0xc0000000      ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::CFG0_bits);

/**
 * Bit shifts for RCU CFG0
 */
enum class RCU_regs::CFG0_shift : unsigned {
  SCS = 0,
  SCSS = 2,
  AHBPSC = 4,
  APB1PSC = 8,
  APB2PSC = 11,
  ADCPSC_1_0 = 14,
  PLLSEL = 16,
  PREDV0_LSB = 17,
  PLLMF_3_0 = 18,
  USBFSPSC = 22,
  CKOUT0SEL = 24,
  ADCPSC_2 = 28,
  PLLMF_4 = 29,
};

/**
 * Bitmasks for RCU INT
 *
 * Clock interrupt register (RCU_INT)
 */
enum class RCU_regs::INT_bits : uint32_t {
  IRC40KSTBIF = (1 << 0),     ///< IRC40K stabilization interrupt flag
  LXTALSTBIF = (1 << 1),      ///< LXTAL stabilization interrupt flag
  IRC8MSTBIF = (1 << 2),      ///< IRC8M stabilization interrupt flag
  HXTALSTBIF = (1 << 3),      ///< HXTAL stabilization interrupt flag
  PLLSTBIF = (1 << 4),        ///< PLL stabilization interrupt flag
  PLL1STBIF = (1 << 5),       ///< PLL1 stabilization interrupt flag
  PLL2STBIF = (1 << 6),       ///< PLL2 stabilization interrupt flag
  CKMIF = (1 << 7),           ///< HXTAL Clock Stuck Interrupt Flag
  IRC40KSTBIE = (1 << 8),     ///< IRC40K Stabilization interrupt enable
  LXTALSTBIE = (1 << 9),      ///< LXTAL Stabilization Interrupt Enable
  IRC8MSTBIE = (1 << 10),     ///< IRC8M Stabilization Interrupt Enable
  HXTALSTBIE = (1 << 11),     ///< HXTAL Stabilization Interrupt Enable
  PLLSTBIE = (1 << 12),       ///< PLL Stabilization Interrupt Enable
  PLL1STBIE = (1 << 13),      ///< PLL1 Stabilization Interrupt Enable
  PLL2STBIE = (1 << 14),      ///< PLL2 Stabilization Interrupt Enable
  IRC40KSTBIC = (1 << 16),    ///< IRC40K Stabilization Interrupt Clear
  LXTALSTBIC = (1 << 17),     ///< LXTAL Stabilization Interrupt Clear
  IRC8MSTBIC = (1 << 18),     ///< IRC8M Stabilization Interrupt Clear
  HXTALSTBIC = (1 << 19),     ///< HXTAL Stabilization Interrupt Clear
  PLLSTBIC = (1 << 20),       ///< PLL stabilization Interrupt Clear
  PLL1STBIC = (1 << 21),      ///< PLL1 stabilization Interrupt Clear
  PLL2STBIC = (1 << 22),      ///< PLL2 stabilization Interrupt Clear
  CKMIC = (1 << 23),          ///< HXTAL Clock Stuck Interrupt Clear
  Reserved_mask = 0xff008000  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::INT_bits);

/**
 * Bit shifts for RCU INT
 */
enum class RCU_regs::INT_shift : unsigned {
  IRC40KSTBIF = 0,
  LXTALSTBIF = 1,
  IRC8MSTBIF = 2,
  HXTALSTBIF = 3,
  PLLSTBIF = 4,
  PLL1STBIF = 5,
  PLL2STBIF = 6,
  CKMIF = 7,
  IRC40KSTBIE = 8,
  LXTALSTBIE = 9,
  IRC8MSTBIE = 10,
  HXTALSTBIE = 11,
  PLLSTBIE = 12,
  PLL1STBIE = 13,
  PLL2STBIE = 14,
  IRC40KSTBIC = 16,
  LXTALSTBIC = 17,
  IRC8MSTBIC = 18,
  HXTALSTBIC = 19,
  PLLSTBIC = 20,
  PLL1STBIC = 21,
  PLL2STBIC = 22,
  CKMIC = 23,
};

/**
 * Bitmasks for RCU APB2RST
 *
 * APB2 reset register (RCU_APB2RST)
 */
enum class RCU_regs::APB2RST_bits : uint32_t {
  AFRST = (1 << 0),           ///< Alternate function I/O reset
  PARST = (1 << 2),           ///< GPIO port A reset
  PBRST = (1 << 3),           ///< GPIO port B reset
  PCRST = (1 << 4),           ///< GPIO port C reset
  PDRST = (1 << 5),           ///< GPIO port D reset
  PERST = (1 << 6),           ///< GPIO port E reset
  ADC0RST = (1 << 9),         ///< ADC0 reset
  ADC1RST = (1 << 10),        ///< ADC1 reset
  TIMER0RST = (1 << 11),      ///< Timer 0 reset
  SPI0RST = (1 << 12),        ///< SPI0 reset
  USART0RST = (1 << 14),      ///< USART0 Reset
  Reserved_mask = 0xffffa182  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::APB2RST_bits);

/**
 * Bit shifts for RCU APB2RST
 */
enum class RCU_regs::APB2RST_shift : unsigned {
  AFRST = 0,
  PARST = 2,
  PBRST = 3,
  PCRST = 4,
  PDRST = 5,
  PERST = 6,
  ADC0RST = 9,
  ADC1RST = 10,
  TIMER0RST = 11,
  SPI0RST = 12,
  USART0RST = 14,
};

/**
 * Bitmasks for RCU APB1RST
 *
 * APB1 reset register (RCU_APB1RST)
 */
enum class RCU_regs::APB1RST_bits : uint32_t {
  TIMER1RST = (1 << 0),       ///< TIMER1 timer reset
  TIMER2RST = (1 << 1),       ///< TIMER2 timer reset
  TIMER3RST = (1 << 2),       ///< TIMER3 timer reset
  TIMER4RST = (1 << 3),       ///< TIMER4 timer reset
  TIMER5RST = (1 << 4),       ///< TIMER5 timer reset
  TIMER6RST = (1 << 5),       ///< TIMER6 timer reset
  WWDGTRST = (1 << 11),       ///< Window watchdog timer reset
  SPI1RST = (1 << 14),        ///< SPI1 reset
  SPI2RST = (1 << 15),        ///< SPI2 reset
  USART1RST = (1 << 17),      ///< USART1 reset
  USART2RST = (1 << 18),      ///< USART2 reset
  UART3RST = (1 << 19),       ///< UART3 reset
  UART4RST = (1 << 20),       ///< UART4 reset
  I2C0RST = (1 << 21),        ///< I2C0 reset
  I2C1RST = (1 << 22),        ///< I2C1 reset
  CAN0RST = (1 << 25),        ///< CAN0 reset
  CAN1RST = (1 << 26),        ///< CAN1 reset
  BKPIRST = (1 << 27),        ///< Backup interface reset
  PMURST = (1 << 28),         ///< Power control reset
  DACRST = (1 << 29),         ///< DAC reset
  Reserved_mask = 0xc18137c0  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::APB1RST_bits);

/**
 * Bit shifts for RCU APB1RST
 */
enum class RCU_regs::APB1RST_shift : unsigned {
  TIMER1RST = 0,
  TIMER2RST = 1,
  TIMER3RST = 2,
  TIMER4RST = 3,
  TIMER5RST = 4,
  TIMER6RST = 5,
  WWDGTRST = 11,
  SPI1RST = 14,
  SPI2RST = 15,
  USART1RST = 17,
  USART2RST = 18,
  UART3RST = 19,
  UART4RST = 20,
  I2C0RST = 21,
  I2C1RST = 22,
  CAN0RST = 25,
  CAN1RST = 26,
  BKPIRST = 27,
  PMURST = 28,
  DACRST = 29,
};

/**
 * Bitmasks for RCU AHBEN
 *
 * AHB enable register
 */
enum class RCU_regs::AHBEN_bits : uint32_t {
  DMA0EN = (1 << 0),          ///< DMA0 clock enable
  DMA1EN = (1 << 1),          ///< DMA1 clock enable
  SRAMSPEN = (1 << 2),        ///< SRAM interface clock enable when sleep mode
  FMCSPEN = (1 << 4),         ///< FMC clock enable when sleep mode
  CRCEN = (1 << 6),           ///< CRC clock enable
  EXMCEN = (1 << 8),          ///< EXMC clock enable
  USBFSEN = (1 << 12),        ///< USBFS clock enable
  Reserved_mask = 0xffffeea8  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::AHBEN_bits);

/**
 * Bit shifts for RCU AHBEN
 */
enum class RCU_regs::AHBEN_shift : unsigned {
  DMA0EN = 0,
  DMA1EN = 1,
  SRAMSPEN = 2,
  FMCSPEN = 4,
  CRCEN = 6,
  EXMCEN = 8,
  USBFSEN = 12,
};

/**
 * Bitmasks for RCU APB2EN
 *
 * APB2 clock enable register (RCU_APB2EN)
 */
enum class RCU_regs::APB2EN_bits : uint32_t {
  AFEN = (1 << 0),            ///< Alternate function IO clock enable
  PAEN = (1 << 2),            ///< GPIO port A clock enable
  PBEN = (1 << 3),            ///< GPIO port B clock enable
  PCEN = (1 << 4),            ///< GPIO port C clock enable
  PDEN = (1 << 5),            ///< GPIO port D clock enable
  PEEN = (1 << 6),            ///< GPIO port E clock enable
  ADC0EN = (1 << 9),          ///< ADC0 clock enable
  ADC1EN = (1 << 10),         ///< ADC1 clock enable
  TIMER0EN = (1 << 11),       ///< TIMER0 clock enable
  SPI0EN = (1 << 12),         ///< SPI0 clock enable
  USART0EN = (1 << 14),       ///< USART0 clock enable
  Reserved_mask = 0xffffa182  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::APB2EN_bits);

/**
 * Bit shifts for RCU APB2EN
 */
enum class RCU_regs::APB2EN_shift : unsigned {
  AFEN = 0,
  PAEN = 2,
  PBEN = 3,
  PCEN = 4,
  PDEN = 5,
  PEEN = 6,
  ADC0EN = 9,
  ADC1EN = 10,
  TIMER0EN = 11,
  SPI0EN = 12,
  USART0EN = 14,
};

/**
 * Bitmasks for RCU APB1EN
 *
 * APB1 clock enable register (RCU_APB1EN)
 */
enum class RCU_regs::APB1EN_bits : uint32_t {
  TIMER1EN = (1 << 0),        ///< TIMER1 timer clock enable
  TIMER2EN = (1 << 1),        ///< TIMER2 timer clock enable
  TIMER3EN = (1 << 2),        ///< TIMER3 timer clock enable
  TIMER4EN = (1 << 3),        ///< TIMER4 timer clock enable
  TIMER5EN = (1 << 4),        ///< TIMER5 timer clock enable
  TIMER6EN = (1 << 5),        ///< TIMER6 timer clock enable
  WWDGTEN = (1 << 11),        ///< Window watchdog timer clock enable
  SPI1EN = (1 << 14),         ///< SPI1 clock enable
  SPI2EN = (1 << 15),         ///< SPI2 clock enable
  USART1EN = (1 << 17),       ///< USART1 clock enable
  USART2EN = (1 << 18),       ///< USART2 clock enable
  UART3EN = (1 << 19),        ///< UART3 clock enable
  UART4EN = (1 << 20),        ///< UART4 clock enable
  I2C0EN = (1 << 21),         ///< I2C0 clock enable
  I2C1EN = (1 << 22),         ///< I2C1 clock enable
  CAN0EN = (1 << 25),         ///< CAN0 clock enable
  CAN1EN = (1 << 26),         ///< CAN1 clock enable
  BKPIEN = (1 << 27),         ///< Backup interface clock enable
  PMUEN = (1 << 28),          ///< Power control clock enable
  DACEN = (1 << 29),          ///< DAC clock enable
  Reserved_mask = 0xc18137c0  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::APB1EN_bits);

/**
 * Bit shifts for RCU APB1EN
 */
enum class RCU_regs::APB1EN_shift : unsigned {
  TIMER1EN = 0,
  TIMER2EN = 1,
  TIMER3EN = 2,
  TIMER4EN = 3,
  TIMER5EN = 4,
  TIMER6EN = 5,
  WWDGTEN = 11,
  SPI1EN = 14,
  SPI2EN = 15,
  USART1EN = 17,
  USART2EN = 18,
  UART3EN = 19,
  UART4EN = 20,
  I2C0EN = 21,
  I2C1EN = 22,
  CAN0EN = 25,
  CAN1EN = 26,
  BKPIEN = 27,
  PMUEN = 28,
  DACEN = 29,
};

/**
 * Bitmasks for RCU BDCTL
 *
 * Backup domain control register (RCU_BDCTL)
 */
enum class RCU_regs::BDCTL_bits : uint32_t {
  LXTALEN = (1 << 0),         ///< LXTAL enable
  LXTALSTB = (1 << 1),        ///< External low-speed oscillator stabilization
  LXTALBPS = (1 << 2),        ///< LXTAL bypass mode enable
  RTCSRC_mask = (0x3 << 8),   ///< RTC clock entry selection
  RTCEN = (1 << 15),          ///< RTC clock enable
  BKPRST = (1 << 16),         ///< Backup domain reset
  Reserved_mask = 0xfffe7cf8  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::BDCTL_bits);

/**
 * Bit shifts for RCU BDCTL
 */
enum class RCU_regs::BDCTL_shift : unsigned {
  LXTALEN = 0,
  LXTALSTB = 1,
  LXTALBPS = 2,
  RTCSRC = 8,
  RTCEN = 15,
  BKPRST = 16,
};

/**
 * Bitmasks for RCU RSTSCK
 *
 * Reset source /clock register (RCU_RSTSCK)
 */
enum class RCU_regs::RSTSCK_bits : uint32_t {
  IRC40KEN = (1 << 0),        ///< IRC40K enable
  IRC40KSTB = (1 << 1),       ///< IRC40K stabilization
  RSTFC = (1 << 24),          ///< Reset flag clear
  EPRSTF = (1 << 26),         ///< External PIN reset flag
  PORRSTF = (1 << 27),        ///< Power reset flag
  SWRSTF = (1 << 28),         ///< Software reset flag
  FWDGTRSTF = (1 << 29),      ///< Free Watchdog timer reset flag
  WWDGTRSTF = (1 << 30),      ///< Window watchdog timer reset flag
  LPRSTF = (1 << 31),         ///< Low-power reset flag
  Reserved_mask = 0x02fffffc  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::RSTSCK_bits);

/**
 * Bit shifts for RCU RSTSCK
 */
enum class RCU_regs::RSTSCK_shift : unsigned {
  IRC40KEN = 0,
  IRC40KSTB = 1,
  RSTFC = 24,
  EPRSTF = 26,
  PORRSTF = 27,
  SWRSTF = 28,
  FWDGTRSTF = 29,
  WWDGTRSTF = 30,
  LPRSTF = 31,
};

/**
 * Bitmasks for RCU AHBRST
 *
 * AHB reset register
 */
enum class RCU_regs::AHBRST_bits : uint32_t {
  USBFSRST = (1 << 12),       ///< USBFS reset
  Reserved_mask = 0xffffefff  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::AHBRST_bits);

/**
 * Bit shifts for RCU AHBRST
 */
enum class RCU_regs::AHBRST_shift : unsigned {
  USBFSRST = 12,
};

/**
 * Bitmasks for RCU CFG1
 *
 * Clock Configuration register 1
 */
enum class RCU_regs::CFG1_bits : uint32_t {
  PREDV0_mask = (0xf << 0),   ///< PREDV0 division factor
  PREDV1_mask = (0xf << 4),   ///< PREDV1 division factor
  PLL1MF_mask = (0xf << 8),   ///< The PLL1 clock multiplication factor
  PLL2MF_mask = (0xf << 12),  ///< The PLL2 clock multiplication factor
  PREDV0SEL = (1 << 16),      ///< PREDV0 input Clock Source Selection
  I2S1SEL = (1 << 17),        ///< I2S1 Clock Source Selection
  I2S2SEL = (1 << 18),        ///< I2S2 Clock Source Selection
  Reserved_mask = 0xfff80000  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::CFG1_bits);

/**
 * Bit shifts for RCU CFG1
 */
enum class RCU_regs::CFG1_shift : unsigned {
  PREDV0 = 0,
  PREDV1 = 4,
  PLL1MF = 8,
  PLL2MF = 12,
  PREDV0SEL = 16,
  I2S1SEL = 17,
  I2S2SEL = 18,
};

/**
 * Bitmasks for RCU DSV
 *
 * Deep sleep mode Voltage register
 */
enum class RCU_regs::DSV_bits : uint32_t {
  DSLPVS_mask = (0x3 << 0),   ///< Deep-sleep mode voltage select
  Reserved_mask = 0xfffffffc  ///< All reserved bits
};
void HasBitwiseOperators(RCU_regs::DSV_bits);

/**
 * Bit shifts for RCU DSV
 */
enum class RCU_regs::DSV_shift : unsigned {
  DSLPVS = 0,
};

static_assert(offsetof(RCU_regs, CTL) == 0x0);
static_assert(offsetof(RCU_regs, CFG0) == 0x4);
static_assert(offsetof(RCU_regs, INT) == 0x8);
static_assert(offsetof(RCU_regs, APB2RST) == 0xc);
static_assert(offsetof(RCU_regs, APB1RST) == 0x10);
static_assert(offsetof(RCU_regs, AHBEN) == 0x14);
static_assert(offsetof(RCU_regs, APB2EN) == 0x18);
static_assert(offsetof(RCU_regs, APB1EN) == 0x1c);
static_assert(offsetof(RCU_regs, BDCTL) == 0x20);
static_assert(offsetof(RCU_regs, RSTSCK) == 0x24);
static_assert(offsetof(RCU_regs, AHBRST) == 0x28);
static_assert(offsetof(RCU_regs, CFG1) == 0x2c);
static_assert(offsetof(RCU_regs, DSV) == 0x34);
}  // namespace deri::mmio
