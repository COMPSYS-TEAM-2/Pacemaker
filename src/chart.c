/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "../inc/timing.h"
#include "../inc/chart.h"


void logic(TickData* d) {
  d->_g45 = d->_pg36;
  if (d->_g45) {
    d->_region0_Atrium_VentricleTimer += d->deltaT;
  }
  d->_g46_e1 = !d->_g45;
  d->_g97 = d->_pg59;
  d->_cg97 = d->_region0_Atrium_VentricleTimer >= VRP_VALUE && d->VS;
  d->_g98 = d->_g97 && d->_cg97;
  if (d->_g98) {
    d->_Pacemaker_local__Atrig2 = 1;
  }
  d->_g82 = d->_pg45;
  if (d->_g82) {
    d->_region0_Atrium_AtriumTimer += d->deltaT;
  }
  d->_g100 = d->_g97 && !d->_cg97;
  d->_cg100 = d->_region0_Atrium_VentricleTimer >= URI_VALUE && d->_region0_Atrium_AtriumTimer >= AVI_VALUE;
  d->_g101 = d->_g100 && d->_cg100;
  if (d->_g101) {
    d->_Pacemaker_local__Atrig3 = 1;
  }
  d->_g100 = d->_g100 && !d->_cg100;
  d->_cg102 = d->_region0_Atrium_VentricleTimer >= LRI_VALUE;
  d->_g103 = d->_g100 && d->_cg102;
  if (d->_g103) {
    d->_Pacemaker_local__Atrig4 = 1;
  }
  d->_cg45 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g46 = d->_g45 && d->_cg45;
  d->_g56 = d->_pg14;
  d->_g50 = d->_pg33;
  d->_g53_e2 = !(d->_g56 || d->_g50);
  d->sleepT = 1000.0;
  d->_g56 = d->_g50 || d->_g56;
  d->_cg51 = d->_region0_Atrium_VentricleTimer < VRP_VALUE;
  d->_g50 = d->_g56 && d->_cg51;
  if (d->_g50) {
    d->sleepT = (d->sleepT < (VRP_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (VRP_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg52 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g51 = d->_g56 && !d->_cg51;
  d->_cg54 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g53 = d->_g50 && d->_cg52 || d->_g51 && d->_cg54;
  d->_g67 = d->_pg38_e5;
  d->_g61 = d->_pg7;
  d->_g64_e3 = !(d->_g67 || d->_g61);
  d->_g67 = d->_g61 || d->_g67;
  d->_cg62 = d->_region0_Atrium_VentricleTimer < URI_VALUE;
  d->_g61 = d->_g67 && d->_cg62;
  if (d->_g61) {
    d->sleepT = (d->sleepT < (URI_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (URI_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg63 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g62 = d->_g67 && !d->_cg62;
  d->_cg65 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g64 = d->_g61 && d->_cg63 || d->_g62 && d->_cg65;
  d->_g78 = d->_pg41;
  d->_g72 = d->_pg14_e2;
  d->_g75_e4 = !(d->_g78 || d->_g72);
  d->_g78 = d->_g72 || d->_g78;
  d->_cg73 = d->_region0_Atrium_VentricleTimer < LRI_VALUE;
  d->_g72 = d->_g78 && d->_cg73;
  if (d->_g72) {
    d->sleepT = (d->sleepT < (LRI_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (LRI_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg74 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g73 = d->_g78 && !d->_cg73;
  d->_cg76 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g75 = d->_g72 && d->_cg74 || d->_g73 && d->_cg76;
  d->_g83_e5 = !d->_g82;
  d->_cg82 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g83 = d->_g82 && d->_cg82;
  d->_g93 = d->_pg54;
  d->_g87 = d->_pg52;
  d->_g90_e6 = !(d->_g93 || d->_g87);
  d->_g93 = d->_g87 || d->_g93;
  d->_cg88 = d->_region0_Atrium_AtriumTimer < AVI_VALUE;
  d->_g87 = d->_g93 && d->_cg88;
  if (d->_g87) {
    d->sleepT = (d->sleepT < (AVI_VALUE - d->_region0_Atrium_AtriumTimer)) ? d->sleepT : (AVI_VALUE - d->_region0_Atrium_AtriumTimer);
  }
  d->_cg89 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g88 = d->_g93 && !d->_cg88;
  d->_cg91 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g90 = d->_g87 && d->_cg89 || d->_g88 && d->_cg91;
  d->_g97 = !d->_g97;
  d->_g101 = d->_g98 || d->_g101 || d->_g103;
  d->_g103 = (d->_g46_e1 || d->_g46) && (d->_g53_e2 || d->_g53) && (d->_g64_e3 || d->_g64) && (d->_g75_e4 || d->_g75) && (d->_g83_e5 || d->_g83) && (d->_g90_e6 || d->_g90) && (d->_g97 || d->_g101) && (d->_g46 || d->_g53 || d->_g64 || d->_g75 || d->_g83 || d->_g90 || d->_g101);
  d->_cg104 = d->_Pacemaker_local__Atrig2;
  d->_g98 = d->_pg64_e3;
  d->_g64_e3 = d->_GO || d->_g98;
  if (d->_g64_e3) {
    d->AP = 0;
    d->VP = 0;
  }
  d->_g99 = d->_g103 && !d->_cg104;
  d->_cg106 = d->_Pacemaker_local__Atrig3;
  d->_g46 = d->_g99 && d->_cg106;
  if (d->_g46) {
    d->VP |= 1;
  }
  d->_g46_e1 = d->_g99 && !d->_cg106;
  if (d->_g46_e1) {
    d->VP |= 1;
  }
  d->_g64 = d->_g103 && d->_cg104 || d->_g46 || d->_g46_e1;
  if (d->_g64) {
    d->_region0_Atrium_VentricleTimer = 0;
  }
  d->_g53 = d->_GO || d->_g64;
  if (d->_g53) {
    d->_Pacemaker_local__Atrig = 0;
    d->_Pacemaker_local__Atrig1 = 0;
  }
  d->_cg4 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g75 = d->_pg99_e7;
  if (d->_g75) {
    d->_region0_Atrium_VentricleTimer += d->deltaT;
  }
  d->_g83_e5 = d->_pg3;
  d->_cg36 = d->_region0_Atrium_VentricleTimer >= PVARP_VALUE && d->AS;
  d->_g83 = d->_g83_e5 && d->_cg36;
  if (d->_g83) {
    d->_Pacemaker_local__Atrig = 1;
  }
  d->_g53_e2 = d->_g83_e5 && !d->_cg36;
  d->_cg39 = d->_region0_Atrium_VentricleTimer >= AEI_VALUE;
  d->_g90 = d->_g53_e2 && d->_cg39;
  if (d->_g90) {
    d->_Pacemaker_local__Atrig1 = 1;
  }
  d->_cg6 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g99_e7 = d->_g53 && !d->_cg4 || d->_g75 && !d->_cg6;
  d->_g75_e4 = d->_g75 && d->_cg6;
  d->_cg8 = d->_region0_Atrium_VentricleTimer < PVARP_VALUE;
  d->_g90_e6 = d->_g53 && d->_cg8;
  if (d->_g90_e6) {
    d->sleepT = (d->sleepT < (PVARP_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (PVARP_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg9 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g118 = d->_pg108;
  d->_g106 = d->_pg13;
  d->_g107 = d->_g118 || d->_g106;
  d->_cg12 = d->_region0_Atrium_VentricleTimer < PVARP_VALUE;
  d->_g104 = d->_g107 && d->_cg12;
  if (d->_g104) {
    d->sleepT = (d->sleepT < (PVARP_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (PVARP_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg13 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g108 = d->_g90_e6 && !d->_cg9 || d->_g104 && !d->_cg13;
  d->_g105 = d->_g107 && !d->_cg12;
  d->_cg15 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g9 = d->_g104 && d->_cg13 || d->_g105 && d->_cg15;
  d->_g12 = d->_g53 && !d->_cg8;
  d->_cg18 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g13 = d->_g105 && !d->_cg15 || d->_g12 && !d->_cg18;
  d->_cg19 = d->_region0_Atrium_VentricleTimer < AEI_VALUE;
  d->_g15 = d->_g53 && d->_cg19;
  if (d->_g15) {
    d->sleepT = (d->sleepT < (AEI_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (AEI_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg20 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g18 = d->_pg20;
  d->_g28 = d->_pg26;
  d->_g23 = d->_g18 || d->_g28;
  d->_cg23 = d->_region0_Atrium_VentricleTimer < AEI_VALUE;
  d->_g24 = d->_g23 && d->_cg23;
  if (d->_g24) {
    d->sleepT = (d->sleepT < (AEI_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (AEI_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg24 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g20 = d->_g15 && !d->_cg20 || d->_g24 && !d->_cg24;
  d->_g23 = d->_g23 && !d->_cg23;
  d->_cg26 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g24 = d->_g24 && d->_cg24 || d->_g23 && d->_cg26;
  d->_g29 = d->_g53 && !d->_cg19;
  d->_cg29 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g26 = d->_g23 && !d->_cg26 || d->_g29 && !d->_cg29;
  d->_cg30 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g29 = d->_pg31;
  if (d->_g29) {
    d->_region0_Atrium_AtriumTimer += d->deltaT;
  }
  d->_cg32 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g31 = d->_g53 && !d->_cg30 || d->_g29 && !d->_cg32;
  d->_g33 = d->_g29 && d->_cg32;
  d->_g3 = d->_g53 || d->_g53_e2 && !d->_cg39;
  d->_g39 = d->_g83 || d->_g90;
  d->_g40 = !d->_g75;
  d->_g37 = !(d->_g106 || d->_g118);
  d->_g6 = !(d->_g28 || d->_g18);
  d->_g11 = !d->_g29;
  d->_g17 = !d->_g83_e5;
  d->_g22 = (d->_g40 || d->_g75_e4) && (d->_g37 || d->_g9) && (d->_g6 || d->_g24) && (d->_g11 || d->_g33) && (d->_g17 || d->_g39) && (d->_g75_e4 || d->_g9 || d->_g24 || d->_g33 || d->_g39);
  d->_cg41 = d->_Pacemaker_local__Atrig;
  d->_g28 = d->_g22 && !d->_cg41;
  if (d->_g28) {
    d->AP |= 1;
  }
  d->_g32 = d->_g22 && d->_cg41 || d->_g28;
  if (d->_g32) {
    d->_region0_Atrium_AtriumTimer = 0;
    d->_Pacemaker_local__Atrig2 = 0;
    d->_Pacemaker_local__Atrig3 = 0;
    d->_Pacemaker_local__Atrig4 = 0;
  }
  d->_cg43 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g36 = d->_g32 && !d->_cg43 || d->_g45 && !d->_cg45;
  d->_cg47 = d->_region0_Atrium_VentricleTimer < VRP_VALUE;
  d->_g38 = d->_g32 && d->_cg47;
  if (d->_g38) {
    d->sleepT = (d->sleepT < (VRP_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (VRP_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg48 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g33 = d->_g38 && !d->_cg48 || d->_g50 && !d->_cg52;
  d->_g25 = d->_g32 && !d->_cg47;
  d->_cg57 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g14 = d->_g51 && !d->_cg54 || d->_g25 && !d->_cg57;
  d->_cg58 = d->_region0_Atrium_VentricleTimer < URI_VALUE;
  d->_g33_e4 = d->_g32 && d->_cg58;
  if (d->_g33_e4) {
    d->sleepT = (d->sleepT < (URI_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (URI_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg59 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g7 = d->_g33_e4 && !d->_cg59 || d->_g61 && !d->_cg63;
  d->_g7_e1 = d->_g32 && !d->_cg58;
  d->_cg68 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g38_e5 = d->_g62 && !d->_cg65 || d->_g7_e1 && !d->_cg68;
  d->_cg69 = d->_region0_Atrium_VentricleTimer < LRI_VALUE;
  d->_g25_e3 = d->_g32 && d->_cg69;
  if (d->_g25_e3) {
    d->sleepT = (d->sleepT < (LRI_VALUE - d->_region0_Atrium_VentricleTimer)) ? d->sleepT : (LRI_VALUE - d->_region0_Atrium_VentricleTimer);
  }
  d->_cg70 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g14_e2 = d->_g25_e3 && !d->_cg70 || d->_g72 && !d->_cg74;
  d->_g109 = d->_g32 && !d->_cg69;
  d->_cg79 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g41 = d->_g73 && !d->_cg76 || d->_g109 && !d->_cg79;
  d->_cg80 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g45 = d->_g32 && !d->_cg80 || d->_g82 && !d->_cg82;
  d->_cg84 = d->_region0_Atrium_AtriumTimer < AVI_VALUE;
  d->_g48 = d->_g32 && d->_cg84;
  if (d->_g48) {
    d->sleepT = (d->sleepT < (AVI_VALUE - d->_region0_Atrium_AtriumTimer)) ? d->sleepT : (AVI_VALUE - d->_region0_Atrium_AtriumTimer);
  }
  d->_cg85 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g52 = d->_g48 && !d->_cg85 || d->_g87 && !d->_cg89;
  d->_g57 = d->_g32 && !d->_cg84;
  d->_cg94 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4;
  d->_g54 = d->_g88 && !d->_cg91 || d->_g57 && !d->_cg94;
  d->_g59 = d->_g32 || d->_g100 && !d->_cg102;
}

void reset(TickData* d) {
  d->_GO = 1;
  d->_TERM = 0;
  d->_region0_Atrium_VentricleTimer = 0.0;
  d->_region0_Atrium_AtriumTimer = 0.0;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
  d->_pg36 = 0;
  d->_pg59 = 0;
  d->_pg45 = 0;
  d->_pg14 = 0;
  d->_pg33 = 0;
  d->_pg38_e5 = 0;
  d->_pg7 = 0;
  d->_pg41 = 0;
  d->_pg14_e2 = 0;
  d->_pg54 = 0;
  d->_pg52 = 0;
  d->_pg64_e3 = 0;
  d->_pg99_e7 = 0;
  d->_pg3 = 0;
  d->_pg108 = 0;
  d->_pg13 = 0;
  d->_pg20 = 0;
  d->_pg26 = 0;
  d->_pg31 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg36 = d->_g36;
  d->_pg59 = d->_g59;
  d->_pg45 = d->_g45;
  d->_pg14 = d->_g14;
  d->_pg33 = d->_g33;
  d->_pg38_e5 = d->_g38_e5;
  d->_pg7 = d->_g7;
  d->_pg41 = d->_g41;
  d->_pg14_e2 = d->_g14_e2;
  d->_pg54 = d->_g54;
  d->_pg52 = d->_g52;
  d->_pg64_e3 = d->_g64_e3;
  d->_pg99_e7 = d->_g99_e7;
  d->_pg3 = d->_g3;
  d->_pg108 = d->_g108;
  d->_pg13 = d->_g13;
  d->_pg20 = d->_g20;
  d->_pg26 = d->_g26;
  d->_pg31 = d->_g31;
  d->_GO = 0;
}
