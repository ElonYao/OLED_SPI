/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************
//
// GPIO37 - GPIO Settings
//
#define DC_control_GPIO_PIN_CONFIG GPIO_37_GPIO37
//
// GPIO8 - GPIO Settings
//
#define Reset_control_GPIO_PIN_CONFIG GPIO_8_GPIO8
//
// GPIO25 - GPIO Settings
//
#define R_ENC1_GPIO_PIN_CONFIG GPIO_25_GPIO25
//
// GPIO26 - GPIO Settings
//
#define R_ENC2_GPIO_PIN_CONFIG GPIO_26_GPIO26

//
// SPIB -> OLED Pinmux
//
//
// SPIB_PICO - GPIO Settings
//
#define GPIO_PIN_SPIB_PICO 7
#define OLED_SPIPICO_GPIO 7
#define OLED_SPIPICO_PIN_CONFIG GPIO_7_SPIB_SIMO
//
// SPIB_POCI - GPIO Settings
//
#define GPIO_PIN_SPIB_POCI 21
#define OLED_SPIPOCI_GPIO 21
#define OLED_SPIPOCI_PIN_CONFIG GPIO_21_SPIB_SOMI
//
// SPIB_CLK - GPIO Settings
//
#define GPIO_PIN_SPIB_CLK 22
#define OLED_SPICLK_GPIO 22
#define OLED_SPICLK_PIN_CONFIG GPIO_22_SPIB_CLK
//
// SPIB_PTE - GPIO Settings
//
#define GPIO_PIN_SPIB_PTE 23
#define OLED_SPIPTE_GPIO 23
#define OLED_SPIPTE_PIN_CONFIG GPIO_23_SPIB_STE

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define DC_control 37
void DC_control_init();
#define Reset_control 8
void Reset_control_init();
#define R_ENC1 25
void R_ENC1_init();
#define R_ENC2 26
void R_ENC2_init();

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define myINPUTXBARINPUT0_SOURCE 25
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT4
void myINPUTXBARINPUT0_init();
#define myINPUTXBARINPUT1_SOURCE 26
#define myINPUTXBARINPUT1_INPUT XBAR_INPUT5
void myINPUTXBARINPUT1_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_timer2
// ISR need to be defined for the registered interrupts
#define INT_timer2 INT_TIMER2
extern __interrupt void portTICK_ISR(void);

// Interrupt Settings for INT_R_ENC1_XINT
// ISR need to be defined for the registered interrupts
#define INT_R_ENC1_XINT INT_XINT1
#define INT_R_ENC1_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_R_ENC1_XINT_ISR(void);

// Interrupt Settings for INT_R_ENC2_XINT
// ISR need to be defined for the registered interrupts
#define INT_R_ENC2_XINT INT_XINT2
#define INT_R_ENC2_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_R_ENC1_XINT_ISR(void);

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define OLED_BASE SPIB_BASE
#define OLED_BITRATE 4000000
#define OLED_DATAWIDTH 8
void OLED_init();

//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
#define R_ENC1_XINT GPIO_INT_XINT1
#define R_ENC1_XINT_TYPE GPIO_INT_TYPE_BOTH_EDGES
void R_ENC1_XINT_init();
#define R_ENC2_XINT GPIO_INT_XINT2
#define R_ENC2_XINT_TYPE GPIO_INT_TYPE_BOTH_EDGES
void R_ENC2_XINT_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	CPUTIMER_init();
void	GPIO_init();
void	INPUTXBAR_init();
void	INTERRUPT_init();
void	SPI_init();
void	XINT_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
