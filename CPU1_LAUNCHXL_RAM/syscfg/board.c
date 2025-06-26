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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	INPUTXBAR_init();
	CPUTIMER_init();
	GPIO_init();
	SPI_init();
	XINT_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	// GPIO37/TDO -> DC_control Pinmux
	GPIO_setPinConfig(GPIO_37_GPIO37);
	// GPIO8 -> Reset_control Pinmux
	GPIO_setPinConfig(GPIO_8_GPIO8);
	// GPIO25 -> R_ENC1 Pinmux
	GPIO_setPinConfig(GPIO_25_GPIO25);
	// GPIO26 -> R_ENC2 Pinmux
	GPIO_setPinConfig(GPIO_26_GPIO26);
	//
	// SPIB -> OLED Pinmux
	//
	GPIO_setPinConfig(OLED_SPIPICO_PIN_CONFIG);
	GPIO_setPadConfig(OLED_SPIPICO_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(OLED_SPIPICO_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(OLED_SPIPOCI_PIN_CONFIG);
	// AGPIO -> GPIO mode selected
	// On 100PZ package for F28003x, if "B5, GPIO20" is used in peripheral signal digital mode, 
	// then "B5" can be used for ADC
	// On 100PZ package for F28003x, if "B11, GPIO21" is used in peripheral signal digital mode, 
	// then "B11" can be used for ADC
	GPIO_setAnalogMode(21, GPIO_ANALOG_DISABLED);
	GPIO_setPadConfig(OLED_SPIPOCI_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(OLED_SPIPOCI_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(OLED_SPICLK_PIN_CONFIG);
	GPIO_setPadConfig(OLED_SPICLK_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(OLED_SPICLK_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(OLED_SPIPTE_PIN_CONFIG);
	GPIO_setPadConfig(OLED_SPIPTE_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(OLED_SPIPTE_GPIO, GPIO_QUAL_ASYNC);


}

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
}


//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	DC_control_init();
	Reset_control_init();
	R_ENC1_init();
	R_ENC2_init();
}

void DC_control_init(){
	GPIO_writePin(DC_control, 0);
	GPIO_setPadConfig(DC_control, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(DC_control, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(DC_control, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(DC_control, GPIO_CORE_CPU1);
}
void Reset_control_init(){
	GPIO_writePin(Reset_control, 1);
	GPIO_setPadConfig(Reset_control, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(Reset_control, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(Reset_control, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(Reset_control, GPIO_CORE_CPU1);
}
void R_ENC1_init(){
	GPIO_setPadConfig(R_ENC1, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(R_ENC1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(R_ENC1, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(R_ENC1, GPIO_CORE_CPU1);
}
void R_ENC2_init(){
	GPIO_setPadConfig(R_ENC2, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(R_ENC2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(R_ENC2, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(R_ENC2, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
	myINPUTXBARINPUT0_init();
	myINPUTXBARINPUT1_init();
}

void myINPUTXBARINPUT0_init(){
	XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}
void myINPUTXBARINPUT1_init(){
	XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT1_INPUT, myINPUTXBARINPUT1_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_timer2
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_timer2, &portTICK_ISR);
	Interrupt_disable(INT_timer2);
	
	// Interrupt Settings for INT_R_ENC1_XINT
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_R_ENC1_XINT, &INT_R_ENC1_XINT_ISR);
	Interrupt_enable(INT_R_ENC1_XINT);
	
	// Interrupt Settings for INT_R_ENC2_XINT
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_R_ENC2_XINT, &INT_R_ENC1_XINT_ISR);
	Interrupt_enable(INT_R_ENC2_XINT);
}
//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
void SPI_init(){
	OLED_init();
}

void OLED_init(){
	SPI_disableModule(OLED_BASE);
	SPI_setConfig(OLED_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA1,
				  SPI_MODE_CONTROLLER, OLED_BITRATE, OLED_DATAWIDTH);
	SPI_setPTESignalPolarity(OLED_BASE, SPI_PTE_ACTIVE_LOW);
	SPI_disableFIFO(OLED_BASE);
	SPI_disableLoopback(OLED_BASE);
	SPI_setEmulationMode(OLED_BASE, SPI_EMULATION_FREE_RUN);
	SPI_enableModule(OLED_BASE);
}

//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
void XINT_init(){
	R_ENC1_XINT_init();
	R_ENC2_XINT_init();
}

void R_ENC1_XINT_init(){
	GPIO_setInterruptType(R_ENC1_XINT, GPIO_INT_TYPE_BOTH_EDGES);
	GPIO_setInterruptPin(R_ENC1, R_ENC1_XINT);
	GPIO_enableInterrupt(R_ENC1_XINT);
}
void R_ENC2_XINT_init(){
	GPIO_setInterruptType(R_ENC2_XINT, GPIO_INT_TYPE_BOTH_EDGES);
	GPIO_setInterruptPin(R_ENC2, R_ENC2_XINT);
	GPIO_enableInterrupt(R_ENC2_XINT);
}

