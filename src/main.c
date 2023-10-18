// Call to chart.c when there is a "tick"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <system.h>
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_uart.h>
#include <altera_avalon_uart_regs.h>
#include <alt_types.h>

#include "../inc/chart.h"
#include "../inc/cimp.h"
#include "../inc/state.h"
#include "../inc/defines.h"

// ISR for pacemaker timing
alt_u32 timerISR(void* context){
	int* timeCount = (int*) context;
	(*timeCount)++;
	return 1; // next time out is 1ms
}

void updateButtonInputs(char * AS, char * VS);
void updateUartInputs(char * AS, char * VS);

void updateUARTOutputs(char AP, char VP);
void updateLEDOutputs(char AP, char VP, char AS, char VS, double deltaT);

int main()
{
	// Pacemaker init
	uint8_t state = -1;

	// Button init
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x7);

	// SC Chart Init
	TickData sData;
	reset(&sData);
	tick(&sData);

	// C code init
	CData cData;
	c_reset(&cData);
	c_tick(&cData);

	// Timer Init
	uint64_t systemTime = 0;
	uint64_t prevTime = 0;

	alt_alarm ticker;
	void* timerContext = (void*) &systemTime;
	alt_alarm_start(&ticker, 1, timerISR, timerContext);


	// Reset LED
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x00);

	while(1){
		// update Time
	    sData.deltaT = systemTime - prevTime;
	    cData.deltaT = sData.deltaT;
	    prevTime = systemTime;

	    // Update State
	    updateState(&state);

	    // Update Pacemaker
	    switch ((state >> MODE) & 0b1){
	    case CHART:
	    	tick(&sData);
	    	break;
	    case CODE:
	    	c_tick(&cData);
	    	break;
	    default:
			tick(&sData);
	    	break;
	    }

	    // Update Inputs
		switch ((state >> INPUT) & 0b1)
		{
		case BUTTONS:
			updateButtonInputs(&(sData.AS), &(sData.VS));
			updateButtonInputs(&(cData.AS), &(cData.VS));
			break;
		case UART:
			updateUartInputs(&(sData.AS), &(sData.VS));
			updateUartInputs(&(cData.AS), &(cData.VS));
			break;
		}

	    // UART output
	    if (((state >> INPUT) & 0b1) == UART) {
			switch ((state >> MODE) & 0b1){
				case CHART:
					updateUARTOutputs(sData.AP, sData.VP);
					break;
				case CODE:
					updateUARTOutputs(cData.AP, cData.VP);
					break;
				// No default
			}
	    }

	    // LED output
		switch ((state >> MODE) & 0b1){
			case CHART:
				updateLEDOutputs(sData.AP, sData.VP, sData.AS, sData.VS, sData.deltaT);
				break;
			case CODE:
				updateLEDOutputs(cData.AP, cData.VP, cData.AS, cData.VS, cData.deltaT);
				break;
			// No default
		}
	}
	return 0;
}

void updateButtonInputs(char * AS, char * VS)
{
	uint8_t key = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

	// Set inputs
	(*AS) = 0;
	(*VS) = 0;
	if(key == 1) {
		*AS = 1;
	} else if (key == 2){
		*VS = 1;
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

void updateUARTOutputs(char AP, char VP)
{
	if (AP){
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'A');
	} else if (VP){
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'V');
	}
}

void updateLEDOutputs(char AP, char VP, char AS, char VS, double deltaT)
{
	static uint8_t apT, vpT, asT, vsT = -1;
	// Set outputs
	if (AP || apT < 50){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x01);
		apT = apT + deltaT;
	} else if (VP || vpT < 50){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x02);
		vpT = vpT + deltaT;
	} else {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x00);
		apT = -1;
		vpT = -1;
	}
	// Set outputs
	if (AS || asT < 50){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x01);
		asT = asT + deltaT;
	} else if (VS || vsT < 50){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x02);
		vsT = vsT + deltaT;
	} else {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x00);
		asT = -1;
		vsT = -1;
	}
}

