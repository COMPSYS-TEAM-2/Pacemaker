/*
 * outputs.h
 *
 *  Created on: 19/10/2023
 *      Author: fosu562
 */

#ifndef INC_OUTPUTS_H_
#define INC_OUTPUTS_H_

#include <stdint.h>

#include "../inc/defines.h"
#include "../inc/chart.h"
#include "../inc/cimp.h"

void uartOutputs(uint8_t state, TickData* sData, CData* cData);
void ledOutputs(uint8_t state, TickData* sData, CData* cData);


#endif /* INC_OUTPUTS_H_ */
