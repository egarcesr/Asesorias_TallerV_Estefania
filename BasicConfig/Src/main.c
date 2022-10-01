/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Estefanía Garcés Rojas
 * @brief          : Configuración básica de un proyecto
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "GPIOxDriver.h"
#include "BasicTimer.h"
#include "USARTxDriver.h"

BasicTimer_Handler_t 		handlerTimer2 		= {0};
GPIO_Handler_t 				handlerBlinkyLed 	= {0};
uint8_t 					blinky 				= 0;
USART_Handler_t 			handlerUSART1		= {0};
GPIO_Handler_t				handlerTX			= {0};


int main(void)
{
	// Deseamos trabajar con el puerto GPIOA
	handlerBlinkyLed.pGPIOx 										= GPIOA;
	handlerBlinkyLed.GPIO_PinConfig.GPIO_PinNumber					= PIN_5;
	handlerBlinkyLed.GPIO_PinConfig.GPIO_PinMode					= GPIO_MODE_OUT;
	handlerBlinkyLed.GPIO_PinConfig.GPIO_PinOPType					= GPIO_OTYPE_PUSHPULL;
	handlerBlinkyLed.GPIO_PinConfig.GPIO_PinPuPdControl				= GPIO_PUPDR_NOTHING;
	handlerBlinkyLed.GPIO_PinConfig.GPIO_PinSpeed					= GPIO_OSPEED_MEDIUM;
	handlerBlinkyLed.GPIO_PinConfig.GPIO_PinAltFunMode				= AF0;

	GPIO_Config(&handlerBlinkyLed);
	GPIO_WritePin(&handlerBlinkyLed, SET);

	handlerTimer2.ptrTIMx 									= TIM2;
	handlerTimer2.TIMx_Config.TIMx_mode 					= BTIMER_MODE_UP;
	handlerTimer2.TIMx_Config.TIMx_speed 					= BTIMER_SPEED_100us;
	handlerTimer2.TIMx_Config.TIMx_period 					= 2500;
	handlerTimer2.TIMx_Config.TIMx_interruptEnable 			= 1;

	BasicTimer_Config(&handlerTimer2);

	handlerTX.pGPIOx										= GPIOA;
	handlerTX.GPIO_PinConfig.GPIO_PinNumber					= PIN_9;
	handlerTX.GPIO_PinConfig.GPIO_PinMode					= GPIO_MODE_ALTFN;
	handlerTX.GPIO_PinConfig.GPIO_PinOPType					= GPIO_OTYPE_PUSHPULL;
	handlerTX.GPIO_PinConfig.GPIO_PinPuPdControl			= GPIO_PUPDR_NOTHING;
	handlerTX.GPIO_PinConfig.GPIO_PinSpeed					= GPIO_OSPEED_MEDIUM;
	handlerTX.GPIO_PinConfig.GPIO_PinAltFunMode				= AF7;

	GPIO_Config(&handlerTX);

	handlerUSART1.ptrUSARTx									= USART1;
	handlerUSART1.USART_Config.USART_mode					= USART_MODE_TX;
	handlerUSART1.USART_Config.USART_baudrate				= USART_BAUDRATE_19200;
	handlerUSART1.USART_Config.USART_datasize               = USART_DATASIZE_8BIT;
	handlerUSART1.USART_Config.USART_parity					= USART_PARITY_NONE;
	handlerUSART1.USART_Config.USART_stopbits				= USART_STOPBIT_1;

	USART_Config(&handlerUSART1);

    /* Loop forever */
	while(1){
	}
	return 0;
}

/*
 * Callback del Timer 2
 */

void BasicTimer2_Callback(void){
	blinky = !blinky;

	writeChar(&handlerUSART1, 'E');

	if (blinky){
		GPIO_WritePin(&handlerBlinkyLed, SET);
	}
	else{
		GPIO_WritePin(&handlerBlinkyLed, RESET);
	}
}
