
#include "../inc/cimp.h"
#include "../inc/timing.h"

int atriumT = 0;
int ventricleT = 0;
int state = 0;

void c_logic(CData* d){
	d->AP = 0;
	d->VP = 0;
	if (state == ATRIUM) {
		// Transitions
		if ((ventricleT >= PVARP_VALUE) && d->AS){
			tVent();
		} else if (ventricleT >= AEI_VALUE) {
			d->AP = 1;
			tVent();
		}
	} else if (state == VENTRICLE) {
		// Transitions
		if ((ventricleT >= VRP_VALUE) && d->VS){
			tAtr();
		} else if ((ventricleT >= URI_VALUE) && (atriumT >= AVI_VALUE)){
			d->VP = 1;
			tAtr();
		} else if (ventricleT >= LRI_VALUE) {
			d->VP = 1;
			tAtr();
		}
	} else {
		state = ATRIUM;
	}
}

void tVent(){
	atriumT = 0;
	state = VENTRICLE;
}

void tAtr() {
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
