// Call to chart.c when there is a "tick"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <system.h>
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>
#include <altera_avalon_pio_regs.h>

#include "../inc/chart.h"

alt_u32 timerISR(void* context){
	int* timeCount = (int*) context;
	(*timeCount)++;
	return 1; // next time out is 1ms
}

void keyISR(void* context, alt_u32 id){
	int* temp = (void*) context;
	(*temp)++;
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

}

int main()
{
  printf("Hello from Nios II!\n");
  // Button init
  int key = 0;
  void* keysContext = (void*) &key;
  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
  IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x02);
  alt_irq_register(KEYS_IRQ, keysContext, keyISR);

  // SC Chart Init
  TickData data;
  reset(&data);
  tick(&data); // init tick
  // Timer Init
  alt_alarm ticker;
  uint64_t systemTime = 0;
  void* timerContext = (void*) &systemTime;
  alt_alarm_start(&ticker, 1, timerISR, timerContext);
  uint64_t prevTime = 0;

  // Reset LED
  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x00);

  // UART
  printf("Pacemaker");

  while(1){
	  // update time
	  data.deltaT = systemTime - prevTime;
	  prevTime = systemTime;

	  // update inputs

	  tick(&data);

	  // update outputs
	  if(data.AP){
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x01);
	  } else if (data.VP){
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x02);
	  } else {
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x00);
	  }

	  if(key){
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x00);
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x01);
		  printf("System Shutting Down... Goodbye!\n");
		  break;
	  }
  }
  return 0;
}
