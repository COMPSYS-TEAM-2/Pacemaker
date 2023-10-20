#include "../inc/cimp.h"
#include "../inc/timing.h"

double atriumT = 0;
double ventricleT = 0;
int state = 0;

void setupVS();
void setupAS();
void c_reset(CData* d);
void c_tick(CData* d);

void c_logic(CData* d){
	d->AP = 0;
	d->VP = 0;
	switch (state)
	{
	case ATRIUM:
		// Transitions
		if ((ventricleT >= PVARP_VALUE) && d->AS){
			setupVS();
		} else if (ventricleT >= AEI_VALUE) {
			d->AP = 1;
			setupVS();
		}
		break;
	case VENTRICLE:
		// Transitions
		if ((ventricleT >= VRP_VALUE) && d->VS){
			setupAS();
		} else if ((ventricleT >= URI_VALUE) && (atriumT >= AVI_VALUE)){
			d->VP = 1;
			setupAS();
		} else if (ventricleT >= LRI_VALUE) {
			d->VP = 1;
			setupAS();
		}
		break;
	}
}

void setupVS(){
	atriumT = 0;
	state = VENTRICLE;
}

void setupAS(){
	ventricleT = 0;
	state = ATRIUM;
}

void c_reset(CData* d) {
	atriumT = 0;
	ventricleT = 0;
	d->deltaT = 0;
	d->AS = 0;
	d->AP = 0;
	d->VS = 0;
	d->VP = 0;
}

void c_tick(CData* d){
	atriumT += d->deltaT;
	ventricleT += d->deltaT;
	c_logic(d);
}
