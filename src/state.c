#include "../inc/state.h"
#include "../inc/defines.h"

#include <system.h>
#include <stdio.h>
#include <altera_avalon_pio_regs.h>

void updateState(uint8_t *state)
{
    if ((*state) != (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x3)){
    	(*state) = (IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x3);
    	FILE* lcd_fp = fopen(LCD_NAME, "w");
    	if (((*state) & 0x1) == CHART){
    		fprintf(lcd_fp, "Mode : SCChart\n");
    	} else {
    		fprintf(lcd_fp, "Mode : Code\n");
    	}
    	if (((*state) & 0x2) == BUTTONS) {
    		fprintf(lcd_fp, "Input: Buttons\n");
    	} else {
    		fprintf(lcd_fp, "Input: UART\n");
    	}
    	fclose(lcd_fp);
    }
}
