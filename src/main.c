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

	    // Update Inputs
		switch (state) {
			case ((BUTTONS << INPUT) | (CHART << MODE)):
				updateButtonInputs(&(sData.AS), &(sData.VS));
				break;
			case ((BUTTONS << INPUT) | (CODE << MODE)):
				updateButtonInputs(&(cData.AS), &(cData.VS));
				break;
			case ((UART << INPUT) | (CHART << MODE)):
				updateUartInputs(&(sData.AS), &(sData.VS));
				break;
			case ((UART << INPUT) | (CODE << MODE)):
				updateUartInputs(&(cData.AS), &(cData.VS));
				break;
		}

		// Button inputs
		switch ((state >> MODE) & 0b1){
			case CHART:
				updateLEDOutputs(sData.AP, sData.VP, sData.AS, sData.VS, sData.deltaT);
				break;
			case CODE:
				updateLEDOutputs(cData.AP, cData.VP, cData.AS, cData.VS, cData.deltaT);
				break;
			// No default
		}

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
	static uint8_t apT, vpT, asT, vsT;
	uint8_t ledG = 0;
	uint8_t ledR = 0;
	// Set outputs
	if (AP){
		ledG |= 0b1;
		apT = 0;
	} else if (apT < LEDTIME) {
		ledG |= 0b1;
		apT = apT + deltaT;
	}

	if (VP){
		ledG |= 0b10;
		vpT = 0;
	} else if (vpT < LEDTIME) {
		ledG |= 0b10;
		vpT = vpT + deltaT;
	}

	// Set outputs
	if (AS){
		ledR |= 0b1;
		asT = 0;
	} else if (asT < LEDTIME) {
		ledR |= 0b1;
		asT = asT + deltaT;
	}

	if (VS){
		ledR |= 0b10;
		vsT = 0;
	} else if (vsT < LEDTIME) {
		ledR |= 0b10;
		vsT = vsT + deltaT;
	}

	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, ledG);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, ledR);
}

