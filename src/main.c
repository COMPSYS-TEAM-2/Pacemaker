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
#include "../inc/main.h"

// ISR for pacemaker timing
alt_u32 timerISR(void* context){
	int* timeCount = (int*) context;
	(*timeCount)++;
	return 1; // next time out is 1ms
}


int main()
{
	// Pacemaker init
	Pacemaker pacemaker_t;
	pacemaker_t.state = CHART;
	printf("Pacemaker\n");

	// Button init
	int key = 0;
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x7);

	// Display init
	FILE* fp;
	fp = fopen(LCD_NAME,"w");
	fprintf(fp, "Mode: SCChart\n\n");
	fclose(fp);

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

	    if (pacemaker_t.state != (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x3)){
	    	pacemaker_t.state = (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x3);
	    	//fp = freopen(NULL ,"w", fp);
	    	fp = fopen(LCD_NAME, "w");
	    	if (pacemaker_t.state == CHART){
	    		fprintf(fp, "Mode: SCChart\n\n");
	    	} else if (pacemaker_t.state == CODE) {
	    		fprintf(fp, "Mode: Code\n\n");
	    	}
	    	fclose(fp);
	    	printf("State %i\n", pacemaker_t.state);

	    }


	    // Update inputs
	    switch (pacemaker_t.state & 0b1){
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
	}
	fclose(fp);
	return 0;
}
