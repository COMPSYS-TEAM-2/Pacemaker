// Call to chart.c when there is a "tick"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <system.h>
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>
#include <alt_types.h>
#include <altera_avalon_pio_regs.h>

#include "../inc/chart.h"
#include "../inc/cimp.h"
#include "../inc/state.h"
#include "../inc/defines.h"
#include "../inc/inputs.h"
#include "../inc/outputs.h"

// ISR for pacemaker timing
/*alt_u32 timerISR(void* context){
	int* timeCount = (int*) context;
	(*timeCount)++;
	return 1; // next time out is 1ms
}*/

int main()
{
	// Pacemaker init
	uint8_t state = -1;

	// Button init
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0b11);

	// SC Chart Init
	TickData sData;
	reset(&sData);
	tick(&sData);

	// C code init
	CData cData;
	c_reset(&cData);
	c_tick(&cData);

	// Timer Init
	//uint64_t systemTime = 0;
	clock_t systemTime;
	uint64_t prevTime = 0;

	//alt_alarm ticker;
	//void* timerContext = (void*) &systemTime;
	//alt_alarm_start(&ticker, 1, timerISR, timerContext);

	while(1){
		systemTime = clock();
		// update Time
	    sData.deltaT = systemTime - prevTime;
	    cData.deltaT = systemTime - prevTime;
	    prevTime = systemTime;

	    // Update State
	    updateState(&state);

	    // Update Inputs
		updateInputs(state, &sData, &cData);

	    // Update Pacemaker
	    switch ((state >> MODE) & 0b1){
	    case CHART:
	    	tick(&sData);
	    	break;
	    case CODE:
	    	c_tick(&cData);
	    	break;
	    }

	    // UART output
	    if (((state >> INPUT) & 0b1) == UART) {
			uartOutputs(state, &sData, &cData);
	    }

	    // LED output
	    ledOutputs(state, &sData, &cData);
	}
	return 0;
}





