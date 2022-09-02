/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Estefanía Garcés Rojas
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

// Librería para tipos de variables booleanas, contiene macros de elementos booleanos y permite
// crear variables de tipo bool
#include <stdbool.h>

// Librería para operaciones matemáticas
#include <math.h>

// Función de C  (no operation), permite que el micro durante un ciclo de reloj no haga nada
#define NOP() __asm("NOP")


// Creación de un prototipo de una función que va a estar definida debajo del main, para que el main las reconozca.
// Esta función no retorno ni recibe nada.
void miPrimeraFuncion (void);

// Función para
uint8_t getMaxChar(void);

// Dentro del main solo ejecutables
int main(void){

	miPrimeraFuncion();
	while(1){

		miPrimeraFuncion();
	}
}

void miPrimeraFuncion(void){

	//Manejo de variables booleanas
	uint8_t miPrimeraBandera = true;
	uint8_t miSegundaBandera = false;

	uint8_t XOR = miPrimeraBandera ^ miSegundaBandera;
	uint8_t OR = miPrimeraBandera || miSegundaBandera;
	uint8_t AND = miPrimeraBandera && miSegundaBandera;

	XOR ^= 1;
	XOR ^= 1;
}


