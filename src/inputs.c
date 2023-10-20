/*
 * inputs.c
 *
 *  Created on: 19/10/2023
 *      Author: fosu562
 */

#include <altera_avalon_pio_regs.h>
#include <altera_avalon_uart.h>
#include <altera_avalon_uart_regs.h>

#include "../inc/defines.h"
#include "../inc/inputs.h"

void updateButtonInputs(char * AS, char * VS);
void updateUartInputs(char * AS, char * VS);

void updateInputs(uint8_t state, TickData* sData, CData* cData){
	switch (state) {
		case ((BUTTONS << INPUT) | (CHART << MODE)):
			updateButtonInputs(&(sData->AS), &(sData->VS));
			break;
		case ((BUTTONS << INPUT) | (CODE << MODE)):
			updateButtonInputs(&(cData->AS), &(cData->VS));
			break;
		case ((UART << INPUT) | (CHART << MODE)):
			updateUartInputs(&(sData->AS), &(sData->VS));
			break;
		case ((UART << INPUT) | (CODE << MODE)):
			updateUartInputs(&(cData->AS), &(cData->VS));
			break;
	}
}

void updateButtonInputs(char * AS, char * VS)
{
	uint8_t key = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

	// Set inputs
	(*AS) = 0;
	(*VS) = 0;
	if(key & 0b1) {
		*VS = 1;
	}
	if (key & 0b10){
		*AS = 1;
	}
}

void updateUartInputs(char * AS, char * VS)
{
	static char input;
	*VS = 0;
	*AS = 0;
	if (input != IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE)){
		input = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
		if (input == 'V'){
			*VS = 1;
		} else if (input == 'A'){
			*AS = 1;
		}
	} else {
		*AS = 0;
		*VS = 0;
	}
}
