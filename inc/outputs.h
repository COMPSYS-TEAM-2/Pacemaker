/*
 * outputs.h
 *
 *  Created on: 19/10/2023
 *      Author: fosu562
 */

#ifndef OUTPUTS_H
#define OUTPUTS_H

#include <stdint.h>

#include "../inc/chart.h"
#include "../inc/cimp.h"

void uartOutputs(uint8_t state, TickData* sData, CData* cData);
void ledOutputs(uint8_t state, TickData* sData, CData* cData);


#endif /* OUTPUTS_H */
