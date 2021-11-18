/*
 * Copyright (c) 2021 Joakim Nohlgård
 */

#pragma once

#include "deri/arch/irq.h"

extern "C" {
void isr_unused();
void isr_CLIC_INT_SFT();
void isr_CLIC_INT_TMR();
void isr_CLIC_INT_BWEI();
void isr_CLIC_INT_PMOVI();
void isr_WWDGT();
void isr_LVD();
void isr_Tamper();
void isr_RTC();
void isr_FMC();
void isr_RCU();
void isr_EXTI_Line0();
void isr_EXTI_Line1();
void isr_EXTI_Line2();
void isr_EXTI_Line3();
void isr_EXTI_Line4();
void isr_DMA0_Channel0();
void isr_DMA0_Channel1();
void isr_DMA0_Channel2();
void isr_DMA0_Channel3();
void isr_DMA0_Channel4();
void isr_DMA0_Channel5();
void isr_DMA0_Channel6();
void isr_ADC0_1();
void isr_CAN0_TX();
void isr_CAN0_RX0();
void isr_CAN0_RX1();
void isr_CAN0_EWMC();
void isr_EXTI_line9_5();
void isr_TIMER0_BRK();
void isr_TIMER0_UP();
void isr_TIMER0_TRG_CMT();
void isr_TIMER0_Channel();
void isr_TIMER1();
void isr_TIMER2();
void isr_TIMER3();
void isr_I2C0_EV();
void isr_I2C0_ER();
void isr_I2C1_EV();
void isr_I2C1_ER();
void isr_SPI0();
void isr_SPI1();
void isr_USART0();
void isr_USART1();
void isr_USART2();
void isr_EXTI_line15_10();
void isr_RTC_Alarm();
void isr_USBFS_WKUP();
void isr_TIMER4();
void isr_SPI2();
void isr_UART3();
void isr_UART4();
void isr_TIMER5();
void isr_TIMER6();
void isr_DMA1_Channel0();
void isr_DMA1_Channel1();
void isr_DMA1_Channel2();
void isr_DMA1_Channel3();
void isr_DMA1_Channel4();
void isr_CAN1_TX();
void isr_CAN1_RX0();
void isr_CAN1_RX1();
void isr_CAN1_EWMC();
void isr_USBFS();
}  // extern "C"

namespace deri::soc {
extern arch::isr_func *const vector_table[];
}
