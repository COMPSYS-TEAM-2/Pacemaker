#ifndef C_IMP_H
#define C_IMP_H

#include "timing.h"

typedef struct {
	double deltaT;
	char AS;
	char VS;
	char AP;
	char VP;
} CData;

enum STATE {
	ATRIUM,
	VENTRICLE
};

void c_reset(CData* d);
void c_tick(CData* d);

#endif
