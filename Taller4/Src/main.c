/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
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

#define SUMA '+'
#define MULTIPLICACION '*'
#define RESTA '-'
#define DIVISION '/'

int16_t resultadoOperacion(int8_t numero1, int8_t numero2, uint8_t Operacion);

int main(void)
{
	int8_t variableA = 15;
	int16_t variableB = 25;

	int16_t resultadoSuma = resultadoOperacion(variableA, (int8_t)variableB, SUMA);

	resultadoSuma ++;

    /* Loop forever */
	while(1){

	}
}

int16_t resultadoOperacion(int8_t numero1, int8_t numero2, uint8_t Operacion){

	int16_t resultado = 0;

	switch(Operacion){

	case SUMA:
	{
		resultado = numero1 + numero2;
		break;
	}
	case RESTA:
	{
		resultado = numero1 - numero2;
		break;
	}
	case MULTIPLICACION:
	{
		resultado = numero1 * numero2;
		break;
	}
	case DIVISION:
	{
		resultado = numero1 / numero2;
		break;
	}
	default:
	{
		resultado = 0;
		break;
	}
	}

	return resultado;
}
