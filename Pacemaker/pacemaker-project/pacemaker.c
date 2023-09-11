/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "timing.h"

#include "pacemaker.h"

void logic(TickData* d) {
  d->_g171 = d->_pg124_e6;
  if (d->_g171) {
    d->_region0_Atrium_PVARP += d->deltaT;
  }
  d->_g172_e1 = !d->_g171;
  d->_cg171 = 1;
  d->_g172 = d->_g171 && d->_cg171;
  d->_g175 = d->_pg166_fix0;
  if (d->_g175) {
    d->_region0_Atrium_AEI += d->deltaT;
  }
  d->_g176_e2 = !d->_g175;
  d->_cg175 = 1;
  d->_g176 = d->_g175 && d->_cg175;
  d->_g179 = d->_pg142;
  if (d->_g179) {
    d->_region0_Atrium_VRP += d->deltaT;
  }
  d->_g180_e3 = !d->_g179;
  d->_cg179 = 1;
  d->_g180 = d->_g179 && d->_cg179;
  d->_g183 = d->_pg136;
  if (d->_g183) {
    d->_region0_Atrium_LRI += d->deltaT;
  }
  d->_g184_e4 = !d->_g183;
  d->_cg183 = 1;
  d->_g184 = d->_g183 && d->_cg183;
  d->_g187 = d->_pg146;
  if (d->_g187) {
    d->_region0_Atrium_AVI += d->deltaT;
  }
  d->_g188_e5 = !d->_g187;
  d->_cg187 = 1;
  d->_g188 = d->_g187 && d->_cg187;
  d->_g191 = d->_pg157;
  if (d->_g191) {
    d->_region0_Atrium_URI += d->deltaT;
  }
  d->_g192_e6 = !d->_g191;
  d->_cg191 = 1;
  d->_g192 = d->_g191 && d->_cg191;
  d->_g176 = (d->_g172_e1 || d->_g172) && (d->_g176_e2 || d->_g176) && (d->_g180_e3 || d->_g180) && (d->_g184_e4 || d->_g184) && (d->_g188_e5 || d->_g188) && (d->_g192_e6 || d->_g192) && (d->_g172 || d->_g176 || d->_g180 || d->_g184 || d->_g188 || d->_g192);
  if (d->_g176) {
    d->_region0_Atrium_PVARP = 0;
    d->_region0_Atrium_VRP = 0;
    d->_region0_Atrium_AEI = 0;
    d->_region0_Atrium_LRI = 0;
    d->_region0_Atrium_URI = 0;
    d->_taken_transitions[5] += 1;
  }
  d->_g188 = d->_GO || d->_g176;
  if (d->_g188) {
    d->_Pacemaker_local__Atrig = 0;
    d->_Pacemaker_local__Atrig1 = 0;
  }
  d->_cg4 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g184_e4 = d->_pg18;
  if (d->_g184_e4) {
    d->_region0_Atrium_AEI += d->deltaT;
  }
  d->_g192_e6 = d->_pg55;
  d->_cg52 = d->_region0_Atrium_AEI >= AVI_VALUE;
  d->_g180_e3 = d->_g192_e6 && d->_cg52;
  if (d->_g180_e3) {
    d->_Pacemaker_local__Atrig = 1;
  }
  d->_g192 = d->_pg180;
  if (d->_g192) {
    d->_region0_Atrium_PVARP += d->deltaT;
  }
  d->_g188_e5 = d->_g192_e6 && !d->_cg52;
  d->_cg55 = d->_region0_Atrium_PVARP >= PVARP_VALUE && d->AS;
  d->_g172_e1 = d->_g188_e5 && d->_cg55;
  if (d->_g172_e1) {
    d->_Pacemaker_local__Atrig1 = 1;
  }
  d->_cg6 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g180 = (d->_g188 && !d->_cg4) || (d->_g192 && !d->_cg6);
  d->_g176_e2 = d->_g192 && d->_cg6;
  d->_g172 = d->_pg184;
  d->_g184 = d->_GO || d->_g172;
  if (d->_g184) {
    d->sleepT = 1000.0;
  }
  d->_cg8 = d->_region0_Atrium_PVARP < PVARP_VALUE;
  d->_g193 = d->_g188 && d->_cg8;
  if (d->_g193) {
    d->sleepT = (d->sleepT < (PVARP_VALUE - d->_region0_Atrium_PVARP)) ? d->sleepT : (PVARP_VALUE - d->_region0_Atrium_PVARP);
  }
  d->_cg9 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g199 = d->_pg9;
  d->_g17 = d->_pg15;
  d->_g12 = d->_g199 || d->_g17;
  d->_cg12 = d->_region0_Atrium_PVARP < PVARP_VALUE;
  d->_g13 = d->_g12 && d->_cg12;
  if (d->_g13) {
    d->sleepT = (d->sleepT < (PVARP_VALUE - d->_region0_Atrium_PVARP)) ? d->sleepT : (PVARP_VALUE - d->_region0_Atrium_PVARP);
  }
  d->_cg13 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g9 = (d->_g193 && !d->_cg9) || (d->_g13 && !d->_cg13);
  d->_g12 = d->_g12 && !d->_cg12;
  d->_cg15 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g13 = (d->_g13 && d->_cg13) || (d->_g12 && d->_cg15);
  d->_g18 = d->_g188 && !d->_cg8;
  d->_cg18 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g15 = (d->_g12 && !d->_cg15) || (d->_g18 && !d->_cg18);
  d->_cg19 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_cg21 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g18 = (d->_g188 && !d->_cg19) || (d->_g184_e4 && !d->_cg21);
  d->_g22 = d->_g184_e4 && d->_cg21;
  d->_cg23 = d->_region0_Atrium_AEI < AVI_VALUE;
  d->_g24 = d->_g188 && d->_cg23;
  if (d->_g24) {
    d->sleepT = (d->sleepT < (AVI_VALUE - d->_region0_Atrium_AEI)) ? d->sleepT : (AVI_VALUE - d->_region0_Atrium_AEI);
  }
  d->_cg24 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g26 = d->_pg24;
  d->_g32 = d->_pg33;
  d->_g27 = d->_g26 || d->_g32;
  d->_cg27 = d->_region0_Atrium_AEI < AVI_VALUE;
  d->_g28 = d->_g27 && d->_cg27;
  if (d->_g28) {
    d->sleepT = (d->sleepT < (AVI_VALUE - d->_region0_Atrium_AEI)) ? d->sleepT : (AVI_VALUE - d->_region0_Atrium_AEI);
  }
  d->_cg28 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g24 = (d->_g24 && !d->_cg24) || (d->_g28 && !d->_cg28);
  d->_g27 = d->_g27 && !d->_cg27;
  d->_cg30 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g28 = (d->_g28 && d->_cg28) || (d->_g27 && d->_cg30);
  d->_g33 = d->_g188 && !d->_cg23;
  d->_cg33 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g33 = (d->_g27 && !d->_cg30) || (d->_g33 && !d->_cg33);
  d->_cg34 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g30 = d->_pg35;
  if (d->_g30) {
    d->_region0_Atrium_VRP += d->deltaT;
  }
  d->_cg36 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g35 = (d->_g188 && !d->_cg34) || (d->_g30 && !d->_cg36);
  d->_g37 = d->_g30 && d->_cg36;
  d->_cg38 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g40 = d->_pg39;
  if (d->_g40) {
    d->_region0_Atrium_LRI += d->deltaT;
  }
  d->_cg40 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g39 = (d->_g188 && !d->_cg38) || (d->_g40 && !d->_cg40);
  d->_g41 = d->_g40 && d->_cg40;
  d->_cg42 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g44 = d->_pg43;
  if (d->_g44) {
    d->_region0_Atrium_AVI += d->deltaT;
  }
  d->_cg44 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g43 = (d->_g188 && !d->_cg42) || (d->_g44 && !d->_cg44);
  d->_g45 = d->_g44 && d->_cg44;
  d->_cg46 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g48 = d->_pg47;
  if (d->_g48) {
    d->_region0_Atrium_URI += d->deltaT;
  }
  d->_cg48 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1;
  d->_g47 = (d->_g188 && !d->_cg46) || (d->_g48 && !d->_cg48);
  d->_g49 = d->_g48 && d->_cg48;
  d->_g55 = d->_g188 || (d->_g188_e5 && !d->_cg55);
  d->_g3 = d->_g180_e3 || d->_g172_e1;
  d->_g56 = !d->_g192;
  d->_g53 = !(d->_g17 || d->_g199);
  d->_g6 = !d->_g184_e4;
  d->_g11 = !(d->_g32 || d->_g26);
  d->_g17 = (d->_g56 || d->_g176_e2) && (d->_g53 || d->_g13) && (d->_g6 || d->_g22) && (d->_g11 || d->_g28);
  d->_g21 = !d->_g30;
  d->_g26 = !d->_g40;
  d->_g32 = !d->_g44;
  d->_g29_e4 = !d->_g48;
  d->_g7_e1 = !d->_g192_e6;
  d->_g22_e3 = d->_g176_e2 || d->_g13 || d->_g22 || d->_g28;
  d->_g14_e2 = d->_g17 && (d->_g21 || d->_g37) && (d->_g26 || d->_g41) && (d->_g32 || d->_g45) && (d->_g29_e4 || d->_g49) && (d->_g7_e1 || d->_g3) && (d->_g22_e3 || d->_g37 || d->_g41 || d->_g45 || d->_g49 || d->_g3);
  d->_g36 = d->_pg40;
  d->_g40 = d->_GO || d->_g36;
  if (d->_g40) {
    d->AP = 0;
    d->VP = 0;
  }
  d->_cg57 = d->_Pacemaker_local__Atrig;
  d->_g44 = d->_g14_e2 && d->_cg57;
  if (d->_g44) {
    d->AP |= 1;
    d->_taken_transitions[0] += 1;
  }
  d->_g48 = d->_g14_e2 && !d->_cg57;
  if (d->_g48) {
    d->_taken_transitions[1] += 1;
  }
  d->_g52 = d->_g44 || d->_g48;
  d->_g29 = d->_pg14;
  if (d->_g29) {
    d->_region0_Atrium_PVARP += d->deltaT;
  }
  d->_g22 = d->_g52 || d->_g29;
  d->_cg61 = 1;
  d->_g7 = d->_g22 && d->_cg61;
  d->_g14 = d->_g22 && !d->_cg61;
  d->_g37 = d->_pg45;
  if (d->_g37) {
    d->_region0_Atrium_AEI += d->deltaT;
  }
  d->_g45_e7 = d->_g52 || d->_g37;
  d->_cg66 = 1;
  d->_g49 = d->_g45_e7 && d->_cg66;
  d->_g45 = d->_g45_e7 && !d->_cg66;
  d->_g41 = d->_pg41_e6;
  if (d->_g41) {
    d->_region0_Atrium_VRP += d->deltaT;
  }
  d->_g54 = d->_g52 || d->_g41;
  d->_cg71 = 1;
  d->_g54_e9 = d->_g54 && d->_cg71;
  d->_g41_e6 = d->_g54 && !d->_cg71;
  d->_g57_fix1 = d->_pg37_e5;
  if (d->_g57_fix1) {
    d->_region0_Atrium_LRI += d->deltaT;
  }
  d->_g57_fix0 = d->_g52 || d->_g57_fix1;
  d->_cg76 = 1;
  d->_g49_e8 = d->_g57_fix0 && d->_cg76;
  d->_g37_e5 = d->_g57_fix0 && !d->_cg76;
  d->_g207 = d->_pg195;
  if (d->_g207) {
    d->_region0_Atrium_AVI += d->deltaT;
  }
  d->_g57 = d->_g52 || d->_g207;
  d->_cg81 = 1;
  d->_g58 = d->_g57 && d->_cg81;
  d->_g195 = d->_g57 && !d->_cg81;
  d->_g64 = d->_pg66;
  if (d->_g64) {
    d->_region0_Atrium_URI += d->deltaT;
  }
  d->_g61 = d->_g52 || d->_g64;
  d->_cg86 = 1;
  d->_g69 = d->_g61 && d->_cg86;
  d->_g66 = d->_g61 && !d->_cg86;
  d->_g74 = !d->_g14;
  d->_g71 = !d->_g45;
  d->_g79 = !d->_g41_e6;
  d->_g76 = !d->_g37_e5;
  d->_g84 = !d->_g195;
  d->_g81 = !d->_g66;
  d->_g59 = (d->_g74 || d->_g7) && (d->_g71 || d->_g49) && (d->_g79 || d->_g54_e9) && (d->_g76 || d->_g49_e8) && (d->_g84 || d->_g58) && (d->_g81 || d->_g69) && (d->_g7 || d->_g49 || d->_g54_e9 || d->_g49_e8 || d->_g58 || d->_g69);
  if (d->_g59) {
    d->_region0_Atrium_AVI = 0;
    d->_taken_transitions[2] += 1;
    d->_Pacemaker_local__Atrig2 = 0;
    d->_Pacemaker_local__Atrig3 = 0;
  }
  d->_cg91 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g89 = d->_pg100;
  if (d->_g89) {
    d->_region0_Atrium_VRP += d->deltaT;
  }
  d->_g86 = d->_pg155;
  d->_cg161 = d->_region0_Atrium_VRP >= VRP_VALUE && d->VS;
  d->_g77_e4 = d->_g86 && d->_cg161;
  if (d->_g77_e4) {
    d->_Pacemaker_local__Atrig2 = 1;
  }
  d->_g62_e1 = d->_pg110;
  if (d->_g62_e1) {
    d->_region0_Atrium_LRI += d->deltaT;
  }
  d->_g77 = d->_pg125;
  if (d->_g77) {
    d->_region0_Atrium_AVI += d->deltaT;
  }
  d->_g67 = d->_pg140;
  if (d->_g67) {
    d->_region0_Atrium_URI += d->deltaT;
  }
  d->_g67_e2 = d->_g86 && !d->_cg161;
  d->_cg164 = d->_region0_Atrium_LRI >= LRI_VALUE || (d->_region0_Atrium_AVI >= AVI_VALUE && d->_region0_Atrium_URI >= URI_VALUE);
  d->_g62 = d->_g67_e2 && d->_cg164;
  if (d->_g62) {
    d->_Pacemaker_local__Atrig3 = 1;
  }
  d->_g72_e3 = d->_pg87_e6;
  if (d->_g72_e3) {
    d->_region0_Atrium_PVARP += d->deltaT;
  }
  d->_cg93 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g87_e6 = (d->_g59 && !d->_cg91) || (d->_g72_e3 && !d->_cg93);
  d->_g87 = d->_g72_e3 && d->_cg93;
  d->_cg95 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g82_e5 = d->_pg82;
  if (d->_g82_e5) {
    d->_region0_Atrium_AEI += d->deltaT;
  }
  d->_cg97 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g82 = (d->_g59 && !d->_cg95) || (d->_g82_e5 && !d->_cg97);
  d->_g72 = d->_g82_e5 && d->_cg97;
  d->_cg99 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_cg101 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g100 = (d->_g59 && !d->_cg99) || (d->_g89 && !d->_cg101);
  d->_g102 = d->_g89 && d->_cg101;
  d->_cg103 = d->_region0_Atrium_VRP < VRP_VALUE;
  d->_g104 = d->_g59 && d->_cg103;
  if (d->_g104) {
    d->sleepT = (d->sleepT < (VRP_VALUE - d->_region0_Atrium_VRP)) ? d->sleepT : (VRP_VALUE - d->_region0_Atrium_VRP);
  }
  d->_cg104 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g106 = d->_pg104;
  d->_g112 = d->_pg113;
  d->_g107 = d->_g106 || d->_g112;
  d->_cg107 = d->_region0_Atrium_VRP < VRP_VALUE;
  d->_g108 = d->_g107 && d->_cg107;
  if (d->_g108) {
    d->sleepT = (d->sleepT < (VRP_VALUE - d->_region0_Atrium_VRP)) ? d->sleepT : (VRP_VALUE - d->_region0_Atrium_VRP);
  }
  d->_cg108 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g104 = (d->_g104 && !d->_cg104) || (d->_g108 && !d->_cg108);
  d->_g107 = d->_g107 && !d->_cg107;
  d->_cg110 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g108 = (d->_g108 && d->_cg108) || (d->_g107 && d->_cg110);
  d->_g113 = d->_g59 && !d->_cg103;
  d->_cg113 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g113 = (d->_g107 && !d->_cg110) || (d->_g113 && !d->_cg113);
  d->_cg114 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_cg116 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g110 = (d->_g59 && !d->_cg114) || (d->_g62_e1 && !d->_cg116);
  d->_g117 = d->_g62_e1 && d->_cg116;
  d->_cg118 = d->_region0_Atrium_LRI < LRI_VALUE;
  d->_g119 = d->_g59 && d->_cg118;
  if (d->_g119) {
    d->sleepT = (d->sleepT < (LRI_VALUE - d->_region0_Atrium_LRI)) ? d->sleepT : (LRI_VALUE - d->_region0_Atrium_LRI);
  }
  d->_cg119 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g121 = d->_pg119;
  d->_g127 = d->_pg128;
  d->_g122 = d->_g121 || d->_g127;
  d->_cg122 = d->_region0_Atrium_LRI < LRI_VALUE;
  d->_g123 = d->_g122 && d->_cg122;
  if (d->_g123) {
    d->sleepT = (d->sleepT < (LRI_VALUE - d->_region0_Atrium_LRI)) ? d->sleepT : (LRI_VALUE - d->_region0_Atrium_LRI);
  }
  d->_cg123 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g119 = (d->_g119 && !d->_cg119) || (d->_g123 && !d->_cg123);
  d->_g122 = d->_g122 && !d->_cg122;
  d->_cg125 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g123 = (d->_g123 && d->_cg123) || (d->_g122 && d->_cg125);
  d->_g128 = d->_g59 && !d->_cg118;
  d->_cg128 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g128 = (d->_g122 && !d->_cg125) || (d->_g128 && !d->_cg128);
  d->_cg129 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_cg131 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g125 = (d->_g59 && !d->_cg129) || (d->_g77 && !d->_cg131);
  d->_g132 = d->_g77 && d->_cg131;
  d->_cg133 = d->_region0_Atrium_AVI < AVI_VALUE;
  d->_g134 = d->_g59 && d->_cg133;
  if (d->_g134) {
    d->sleepT = (d->sleepT < (AVI_VALUE - d->_region0_Atrium_AVI)) ? d->sleepT : (AVI_VALUE - d->_region0_Atrium_AVI);
  }
  d->_cg134 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g136 = d->_pg134;
  d->_g142 = d->_pg143;
  d->_g137 = d->_g136 || d->_g142;
  d->_cg137 = d->_region0_Atrium_AVI < AVI_VALUE;
  d->_g138 = d->_g137 && d->_cg137;
  if (d->_g138) {
    d->sleepT = (d->sleepT < (AVI_VALUE - d->_region0_Atrium_AVI)) ? d->sleepT : (AVI_VALUE - d->_region0_Atrium_AVI);
  }
  d->_cg138 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g134 = (d->_g134 && !d->_cg134) || (d->_g138 && !d->_cg138);
  d->_g137 = d->_g137 && !d->_cg137;
  d->_cg140 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g138 = (d->_g138 && d->_cg138) || (d->_g137 && d->_cg140);
  d->_g143 = d->_g59 && !d->_cg133;
  d->_cg143 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g143 = (d->_g137 && !d->_cg140) || (d->_g143 && !d->_cg143);
  d->_cg144 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_cg146 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g140 = (d->_g59 && !d->_cg144) || (d->_g67 && !d->_cg146);
  d->_g147 = d->_g67 && d->_cg146;
  d->_cg148 = d->_region0_Atrium_URI < URI_VALUE;
  d->_g149 = d->_g59 && d->_cg148;
  if (d->_g149) {
    d->sleepT = (d->sleepT < (URI_VALUE - d->_region0_Atrium_URI)) ? d->sleepT : (URI_VALUE - d->_region0_Atrium_URI);
  }
  d->_cg149 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g151 = d->_pg149;
  d->_g157 = d->_pg158;
  d->_g152 = d->_g151 || d->_g157;
  d->_cg152 = d->_region0_Atrium_URI < URI_VALUE;
  d->_g153 = d->_g152 && d->_cg152;
  if (d->_g153) {
    d->sleepT = (d->sleepT < (URI_VALUE - d->_region0_Atrium_URI)) ? d->sleepT : (URI_VALUE - d->_region0_Atrium_URI);
  }
  d->_cg153 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g149 = (d->_g149 && !d->_cg149) || (d->_g153 && !d->_cg153);
  d->_g152 = d->_g152 && !d->_cg152;
  d->_cg155 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g153 = (d->_g153 && d->_cg153) || (d->_g152 && d->_cg155);
  d->_g158 = d->_g59 && !d->_cg148;
  d->_cg158 = d->_Pacemaker_local__Atrig2 || d->_Pacemaker_local__Atrig3;
  d->_g158 = (d->_g152 && !d->_cg155) || (d->_g158 && !d->_cg158);
  d->_g155 = d->_g59 || (d->_g67_e2 && !d->_cg164);
  d->_g164 = d->_g77_e4 || d->_g62;
  d->_g90 = !d->_g72_e3;
  d->_g165 = !d->_g82_e5;
  d->_g162 = !d->_g89;
  d->_g93 = !(d->_g112 || d->_g106);
  d->_g97 = (d->_g90 || d->_g87) && (d->_g165 || d->_g72) && (d->_g162 || d->_g102) && (d->_g93 || d->_g108);
  d->_g101 = !d->_g62_e1;
  d->_g112 = !(d->_g127 || d->_g121);
  d->_g106 = !d->_g77;
  d->_g102_e3 = d->_g97 && (d->_g101 || d->_g117) && (d->_g112 || d->_g123) && (d->_g106 || d->_g132);
  d->_g109_e4 = !(d->_g142 || d->_g136);
  d->_g98_e2 = !d->_g67;
  d->_g94_e1 = !(d->_g157 || d->_g151);
  d->_g116 = !d->_g86;
  d->_g127 = d->_g87 || d->_g72 || d->_g102 || d->_g108;
  d->_g121 = d->_g102_e3 && (d->_g109_e4 || d->_g138) && (d->_g98_e2 || d->_g147) && (d->_g94_e1 || d->_g153) && (d->_g116 || d->_g164) && (d->_g127 || d->_g117 || d->_g123 || d->_g132 || d->_g138 || d->_g147 || d->_g153 || d->_g164);
  d->_cg166 = d->_Pacemaker_local__Atrig2;
  d->_g131 = d->_g121 && d->_cg166;
  if (d->_g131) {
    d->_taken_transitions[3] += 1;
  }
  d->_g117_e5 = d->_g121 && !d->_cg166;
  if (d->_g117_e5) {
    d->VP |= 1;
    d->_taken_transitions[4] += 1;
  }
  d->_g132_e7 = d->_g131 || d->_g117_e5;
  d->_cg169 = 1;
  d->_g124_e6 = (d->_g132_e7 && !d->_cg169) || (d->_g171 && !d->_cg171);
  d->_cg173 = 1;
  d->_g166_fix0 = (d->_g132_e7 && !d->_cg173) || (d->_g175 && !d->_cg175);
  d->_cg177 = 1;
  d->_g142 = (d->_g132_e7 && !d->_cg177) || (d->_g179 && !d->_cg179);
  d->_cg181 = 1;
  d->_g136 = (d->_g132_e7 && !d->_cg181) || (d->_g183 && !d->_cg183);
  d->_cg185 = 1;
  d->_g146 = (d->_g132_e7 && !d->_cg185) || (d->_g187 && !d->_cg187);
  d->_cg189 = 1;
  d->_g157 = (d->_g132_e7 && !d->_cg189) || (d->_g191 && !d->_cg191);
}

void reset(TickData* d) {
  d->_GO = 1;
  d->_TERM = 0;
  d->_region0_Atrium_PVARP = 0.0;
  d->_region0_Atrium_AEI = 0.0;
  d->_region0_Atrium_VRP = 0.0;
  d->_region0_Atrium_LRI = 0.0;
  d->_region0_Atrium_AVI = 0.0;
  d->_region0_Atrium_URI = 0.0;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
  d->AP = 0;
  d->VP = 0;
  d->_taken_transitions[0] = 0;
  d->_taken_transitions[1] = 0;
  d->_taken_transitions[2] = 0;
  d->_taken_transitions[3] = 0;
  d->_taken_transitions[4] = 0;
  d->_taken_transitions[5] = 0;
  d->_pg124_e6 = 0;
  d->_pg166_fix0 = 0;
  d->_pg142 = 0;
  d->_pg136 = 0;
  d->_pg146 = 0;
  d->_pg157 = 0;
  d->_pg18 = 0;
  d->_pg55 = 0;
  d->_pg180 = 0;
  d->_pg184 = 0;
  d->_pg9 = 0;
  d->_pg15 = 0;
  d->_pg24 = 0;
  d->_pg33 = 0;
  d->_pg35 = 0;
  d->_pg39 = 0;
  d->_pg43 = 0;
  d->_pg47 = 0;
  d->_pg40 = 0;
  d->_pg14 = 0;
  d->_pg45 = 0;
  d->_pg41_e6 = 0;
  d->_pg37_e5 = 0;
  d->_pg195 = 0;
  d->_pg66 = 0;
  d->_pg100 = 0;
  d->_pg155 = 0;
  d->_pg110 = 0;
  d->_pg125 = 0;
  d->_pg140 = 0;
  d->_pg87_e6 = 0;
  d->_pg82 = 0;
  d->_pg104 = 0;
  d->_pg113 = 0;
  d->_pg119 = 0;
  d->_pg128 = 0;
  d->_pg134 = 0;
  d->_pg143 = 0;
  d->_pg149 = 0;
  d->_pg158 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg124_e6 = d->_g124_e6;
  d->_pg166_fix0 = d->_g166_fix0;
  d->_pg142 = d->_g142;
  d->_pg136 = d->_g136;
  d->_pg146 = d->_g146;
  d->_pg157 = d->_g157;
  d->_pg18 = d->_g18;
  d->_pg55 = d->_g55;
  d->_pg180 = d->_g180;
  d->_pg184 = d->_g184;
  d->_pg9 = d->_g9;
  d->_pg15 = d->_g15;
  d->_pg24 = d->_g24;
  d->_pg33 = d->_g33;
  d->_pg35 = d->_g35;
  d->_pg39 = d->_g39;
  d->_pg43 = d->_g43;
  d->_pg47 = d->_g47;
  d->_pg40 = d->_g40;
  d->_pg14 = d->_g14;
  d->_pg45 = d->_g45;
  d->_pg41_e6 = d->_g41_e6;
  d->_pg37_e5 = d->_g37_e5;
  d->_pg195 = d->_g195;
  d->_pg66 = d->_g66;
  d->_pg100 = d->_g100;
  d->_pg155 = d->_g155;
  d->_pg110 = d->_g110;
  d->_pg125 = d->_g125;
  d->_pg140 = d->_g140;
  d->_pg87_e6 = d->_g87_e6;
  d->_pg82 = d->_g82;
  d->_pg104 = d->_g104;
  d->_pg113 = d->_g113;
  d->_pg119 = d->_g119;
  d->_pg128 = d->_g128;
  d->_pg134 = d->_g134;
  d->_pg143 = d->_g143;
  d->_pg149 = d->_g149;
  d->_pg158 = d->_g158;
  d->_GO = 0;
}
