// Call to chart.c when there is a "tick"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <system.h>
#include <altera_avalon_pio_regs.h>

#include "../inc/chart.h"
#include "../inc/cimp.h"
#include "../inc/state.h"
#include "../inc/defines.h"
#include "../inc/inputs.h"
#include "../inc/outputs.h"

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
	uint64_t systemTime;
	uint64_t prevTime = 0;

	while(1){
		// Get system time
		systemTime = clock() * (1000 / CLOCKS_PER_SEC); // Works because CPS = 1000

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

	    updateOutputs(state, &sData, &cData);
	}
	return 0;
}





