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
#include "../inc/state.h"
#include "../inc/defines.h"

// ISR for pacemaker timing
alt_u32 timerISR(void* context){
	int* timeCount = (int*) context;
	(*timeCount)++;
	return 1; // next time out is 1ms
}

void updateButtonInputs(uint8_t * AS, uint8_t * VS);
void updateUartInputs(uint8_t * AS, uint8_t * VS);

void updateUARTOutputs();
void updateLEDOutputs();

int main()
{
	// Pacemaker init
	uint8_t state = -1;

	// Button init
	int key = 0;
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x7);

	// SC Chart Init
	TickData data;
	reset(&data);
	tick(&data);

	// Timer Init
	uint64_t systemTime = 0;
	uint64_t prevTime = 0;
	uint64_t apTime = -1;
	uint64_t vpTime = -1;
	uint64_t asTime = -1;
	uint64_t vsTime = -1;

	alt_alarm ticker;
	void* timerContext = (void*) &systemTime;
	alt_alarm_start(&ticker, 1, timerISR, timerContext);


	// Reset LED
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x00);

	while(1){
		// update Time
	    data.deltaT = systemTime - prevTime;
	    prevTime = systemTime;

	    // Update State
	    updateState(&state);

	    // Update Inputs
	    switch ((state >> INPUT) & 0b1)
	    {
	    case BUTTONS:
	    	updateButtonInputs(&(data.AS), &(data.VS));
	    	break;
	    case UART:
	    	updateUartInputs(&(data.AS), &(data.VS));
	    	break;
	    }

	    // Update Pacemaker
	    switch (state & 0b1){
	    case CHART:
	    	tick(&data);
	    	break;
	    case CODE:
	    	break;
	    default:
			tick(&data);
	    	break;
	    }


	    // UART Output
	    if (((state >> INPUT) & 0b1) == UART) {
	    	if (data.AP){
	    		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'A');
	    	} else if (data.VP){
	    		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, 'V');
	    	}
	    }

	    // Set outputs
	    if((data.AP) || (apTime < 50)){
		    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x01);
		    apTime++;
	    } else if ((data.VP) || (vpTime < 50)){
		    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x02);
		    vpTime++;
	    } else {
		    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x00);
		    apTime = -1;
		    vpTime = -1;
	    }
	    // Set outputs
	    if((data.AS) || (asTime < 50)){
		    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x01);
		    asTime++;
	    } else if ((data.VS) || (vsTime < 50)){
		    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x02);
		    vsTime++;
	    } else {
		    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x00);
		    asTime = -1;
		    vsTime = -1;
	    }
	}
	return 0;
}

void updateButtonInputs(uint8_t * AS, uint8_t * VS)
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

void updateUartInputs(uint8_t * AS, uint8_t * VS)
{
	*VS = 0;
	*AS = 0;
	if (IORD_ALTERA_AVALON_UART_STATUS(UART_BASE)){
		uint8_t input = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
		if (input == 'V'){
			*VS = 1;
		} else if (input == 'A'){
			*AS = 1;
		}
	}
}

void updateUARTOutputs()
{
}

void updateLEDOutputs()
{
}
}
