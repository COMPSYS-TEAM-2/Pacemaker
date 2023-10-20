/*
 * outputs.c
 *
 *  Created on: 19/10/2023
 *      Author: fosu562
 */

#include <altera_avalon_uart.h>
#include <altera_avalon_uart_regs.h>
#include <altera_avalon_pio_regs.h>

#include "../inc/outputs.h"
#include "../inc/defines.h"

void updateUARTOutputs(char AP, char VP);
void updateLEDOutputs(char AP, char VP, char AS, char VS, double deltaT);

void uartOutputs(uint8_t state, TickData* sData, CData* cData);
void ledOutputs(uint8_t state, TickData* sData, CData* cData);


void updateOutputs(uint8_t state, TickData* sData, CData* cData){
	// UART output
	if (((state >> INPUT) & 0b1) == UART) {
		uartOutputs(state, sData, cData);
	}

	// LED output
	ledOutputs(state, sData, cData);
}

// UART output
void uartOutputs(uint8_t state, TickData* sData, CData* cData){
	switch ((state >> MODE) & 0b1){
		case CHART:
			updateUARTOutputs(sData->AP, sData->VP);
			break;
		case CODE:
			updateUARTOutputs(cData->AP, cData->VP);
			break;
		// No default
	}
}

// LED output
void ledOutputs(uint8_t state, TickData* sData, CData* cData){
	switch ((state >> MODE) & 0b1){
		case CHART:
			updateLEDOutputs(sData->AP, sData->VP, sData->AS, sData->VS, sData->deltaT);
			break;
		case CODE:
			updateLEDOutputs(cData->AP, cData->VP, cData->AS, cData->VS, cData->deltaT);
			break;
		// No default
	}
}

void updateUARTOutputs(char AP, char VP)
{
	if (AP){
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'A');
	}
	if (VP){
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'V');
	}
}

void updateLEDOutputs(char AP, char VP, char AS, char VS, double deltaT)
{
	static uint8_t apT, vpT, asT, vsT;
	uint8_t ledG = 0;
	uint8_t ledR = 0;
	// Set outputs
	if (AP){
		ledG |= 0b10;
		apT = 0;
	} else if (apT < LEDTIME) {
		ledG |= 0b10;
		apT = apT + deltaT;
	}

	if (VP){
		ledG |= 0b1;
		vpT = 0;
	} else if (vpT < LEDTIME) {
		ledG |= 0b1;
		vpT = vpT + deltaT;
	}

	// Set outputs
	if (AS){
		ledR |= 0b10;
		asT = 0;
	} else if (asT < LEDTIME) {
		ledR |= 0b10;
		asT = asT + deltaT;
	}

	if (VS){
		ledR |= 0b1;
		vsT = 0;
	} else if (vsT < LEDTIME) {
		ledR |= 0b1;
		vsT = vsT + deltaT;
	}

	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ledG);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, ledR);
}


