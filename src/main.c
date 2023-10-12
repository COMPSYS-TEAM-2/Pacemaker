// Call to chart.c when there is a "tick"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <system.h>
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>
#include <altera_avalon_pio_regs.h>
#include <alt_types.h>

#include "../inc/chart.h"

alt_u32 timerISR(void* context){
	int* timeCount = (int*) context;
	(*timeCount)++;
	return 1; // next time out is 1ms
}

/*void keyISR(void* context, alt_u32 id){
	int* temp = (void*) context;
	(*temp) = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	printf("button: %i\n", *temp);
}*/

int main()
{
	printf("Pacemaker\n");

	// Button init
	int key = 0;
	//void* keysContext = (void*) &key;
	//IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x7);
	//alt_irq_register(KEYS_IRQ, keysContext, keyISR);

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

	    // update inputs
	    tick(&data);

	    key = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
		IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

	    // Set inputs
	    if(key == 1) {
	  	    data.AS = 1;
	    } else if (key == 2){
		    data.VS = 1;
	    } else {
		    data.AS = 0;
		    data.VS = 0;
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

/*	    // Reset key to 0
	    key = 0;
*/
	}
	return 0;
}
