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
		// update time
	    data.deltaT = systemTime - prevTime;
	    prevTime = systemTime;

	    // Update state
	    updateState(&state);

	    // Update inputs
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

	    key = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
		IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

		// Set inputs
	    if ((state & 0x2) == BUTTONS) {
			if(key == 1) {
				data.AS = 1;
			} else if (key == 2){
				data.VS = 1;
			} else {
				data.AS = 0;
				data.VS = 0;
			}
	    } else { // UART
	    	static char input = 0;
	    	if (input != IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE)){
	    		input = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
				if (input == 'V'){
					data.VS = 1;
					data.AS = 0;
				} else if (input == 'A'){
					data.AS = 1;
					data.VS = 0;
				} else {
					data.VS = 0;
					data.AS = 0;
				}
	    	} else {
				data.VS = 0;
				data.AS = 0;
			}

	    	// UART Output
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
