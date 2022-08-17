#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with sympy 1.9                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_80014774094776572) {
   out_80014774094776572[0] = delta_x[0] + nom_x[0];
   out_80014774094776572[1] = delta_x[1] + nom_x[1];
   out_80014774094776572[2] = delta_x[2] + nom_x[2];
   out_80014774094776572[3] = delta_x[3] + nom_x[3];
   out_80014774094776572[4] = delta_x[4] + nom_x[4];
   out_80014774094776572[5] = delta_x[5] + nom_x[5];
   out_80014774094776572[6] = delta_x[6] + nom_x[6];
   out_80014774094776572[7] = delta_x[7] + nom_x[7];
   out_80014774094776572[8] = delta_x[8] + nom_x[8];
   out_80014774094776572[9] = delta_x[9] + nom_x[9];
   out_80014774094776572[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9144507820461143592) {
   out_9144507820461143592[0] = -nom_x[0] + true_x[0];
   out_9144507820461143592[1] = -nom_x[1] + true_x[1];
   out_9144507820461143592[2] = -nom_x[2] + true_x[2];
   out_9144507820461143592[3] = -nom_x[3] + true_x[3];
   out_9144507820461143592[4] = -nom_x[4] + true_x[4];
   out_9144507820461143592[5] = -nom_x[5] + true_x[5];
   out_9144507820461143592[6] = -nom_x[6] + true_x[6];
   out_9144507820461143592[7] = -nom_x[7] + true_x[7];
   out_9144507820461143592[8] = -nom_x[8] + true_x[8];
   out_9144507820461143592[9] = -nom_x[9] + true_x[9];
   out_9144507820461143592[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_3038444346073204801) {
   out_3038444346073204801[0] = 1.0;
   out_3038444346073204801[1] = 0;
   out_3038444346073204801[2] = 0;
   out_3038444346073204801[3] = 0;
   out_3038444346073204801[4] = 0;
   out_3038444346073204801[5] = 0;
   out_3038444346073204801[6] = 0;
   out_3038444346073204801[7] = 0;
   out_3038444346073204801[8] = 0;
   out_3038444346073204801[9] = 0;
   out_3038444346073204801[10] = 0;
   out_3038444346073204801[11] = 0;
   out_3038444346073204801[12] = 1.0;
   out_3038444346073204801[13] = 0;
   out_3038444346073204801[14] = 0;
   out_3038444346073204801[15] = 0;
   out_3038444346073204801[16] = 0;
   out_3038444346073204801[17] = 0;
   out_3038444346073204801[18] = 0;
   out_3038444346073204801[19] = 0;
   out_3038444346073204801[20] = 0;
   out_3038444346073204801[21] = 0;
   out_3038444346073204801[22] = 0;
   out_3038444346073204801[23] = 0;
   out_3038444346073204801[24] = 1.0;
   out_3038444346073204801[25] = 0;
   out_3038444346073204801[26] = 0;
   out_3038444346073204801[27] = 0;
   out_3038444346073204801[28] = 0;
   out_3038444346073204801[29] = 0;
   out_3038444346073204801[30] = 0;
   out_3038444346073204801[31] = 0;
   out_3038444346073204801[32] = 0;
   out_3038444346073204801[33] = 0;
   out_3038444346073204801[34] = 0;
   out_3038444346073204801[35] = 0;
   out_3038444346073204801[36] = 1.0;
   out_3038444346073204801[37] = 0;
   out_3038444346073204801[38] = 0;
   out_3038444346073204801[39] = 0;
   out_3038444346073204801[40] = 0;
   out_3038444346073204801[41] = 0;
   out_3038444346073204801[42] = 0;
   out_3038444346073204801[43] = 0;
   out_3038444346073204801[44] = 0;
   out_3038444346073204801[45] = 0;
   out_3038444346073204801[46] = 0;
   out_3038444346073204801[47] = 0;
   out_3038444346073204801[48] = 1.0;
   out_3038444346073204801[49] = 0;
   out_3038444346073204801[50] = 0;
   out_3038444346073204801[51] = 0;
   out_3038444346073204801[52] = 0;
   out_3038444346073204801[53] = 0;
   out_3038444346073204801[54] = 0;
   out_3038444346073204801[55] = 0;
   out_3038444346073204801[56] = 0;
   out_3038444346073204801[57] = 0;
   out_3038444346073204801[58] = 0;
   out_3038444346073204801[59] = 0;
   out_3038444346073204801[60] = 1.0;
   out_3038444346073204801[61] = 0;
   out_3038444346073204801[62] = 0;
   out_3038444346073204801[63] = 0;
   out_3038444346073204801[64] = 0;
   out_3038444346073204801[65] = 0;
   out_3038444346073204801[66] = 0;
   out_3038444346073204801[67] = 0;
   out_3038444346073204801[68] = 0;
   out_3038444346073204801[69] = 0;
   out_3038444346073204801[70] = 0;
   out_3038444346073204801[71] = 0;
   out_3038444346073204801[72] = 1.0;
   out_3038444346073204801[73] = 0;
   out_3038444346073204801[74] = 0;
   out_3038444346073204801[75] = 0;
   out_3038444346073204801[76] = 0;
   out_3038444346073204801[77] = 0;
   out_3038444346073204801[78] = 0;
   out_3038444346073204801[79] = 0;
   out_3038444346073204801[80] = 0;
   out_3038444346073204801[81] = 0;
   out_3038444346073204801[82] = 0;
   out_3038444346073204801[83] = 0;
   out_3038444346073204801[84] = 1.0;
   out_3038444346073204801[85] = 0;
   out_3038444346073204801[86] = 0;
   out_3038444346073204801[87] = 0;
   out_3038444346073204801[88] = 0;
   out_3038444346073204801[89] = 0;
   out_3038444346073204801[90] = 0;
   out_3038444346073204801[91] = 0;
   out_3038444346073204801[92] = 0;
   out_3038444346073204801[93] = 0;
   out_3038444346073204801[94] = 0;
   out_3038444346073204801[95] = 0;
   out_3038444346073204801[96] = 1.0;
   out_3038444346073204801[97] = 0;
   out_3038444346073204801[98] = 0;
   out_3038444346073204801[99] = 0;
   out_3038444346073204801[100] = 0;
   out_3038444346073204801[101] = 0;
   out_3038444346073204801[102] = 0;
   out_3038444346073204801[103] = 0;
   out_3038444346073204801[104] = 0;
   out_3038444346073204801[105] = 0;
   out_3038444346073204801[106] = 0;
   out_3038444346073204801[107] = 0;
   out_3038444346073204801[108] = 1.0;
   out_3038444346073204801[109] = 0;
   out_3038444346073204801[110] = 0;
   out_3038444346073204801[111] = 0;
   out_3038444346073204801[112] = 0;
   out_3038444346073204801[113] = 0;
   out_3038444346073204801[114] = 0;
   out_3038444346073204801[115] = 0;
   out_3038444346073204801[116] = 0;
   out_3038444346073204801[117] = 0;
   out_3038444346073204801[118] = 0;
   out_3038444346073204801[119] = 0;
   out_3038444346073204801[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_5331942404729498203) {
   out_5331942404729498203[0] = dt*state[3] + state[0];
   out_5331942404729498203[1] = dt*state[4] + state[1];
   out_5331942404729498203[2] = dt*state[5] + state[2];
   out_5331942404729498203[3] = state[3];
   out_5331942404729498203[4] = state[4];
   out_5331942404729498203[5] = state[5];
   out_5331942404729498203[6] = dt*state[7] + state[6];
   out_5331942404729498203[7] = dt*state[8] + state[7];
   out_5331942404729498203[8] = state[8];
   out_5331942404729498203[9] = state[9];
   out_5331942404729498203[10] = state[10];
}
void F_fun(double *state, double dt, double *out_3160440324773884395) {
   out_3160440324773884395[0] = 1;
   out_3160440324773884395[1] = 0;
   out_3160440324773884395[2] = 0;
   out_3160440324773884395[3] = dt;
   out_3160440324773884395[4] = 0;
   out_3160440324773884395[5] = 0;
   out_3160440324773884395[6] = 0;
   out_3160440324773884395[7] = 0;
   out_3160440324773884395[8] = 0;
   out_3160440324773884395[9] = 0;
   out_3160440324773884395[10] = 0;
   out_3160440324773884395[11] = 0;
   out_3160440324773884395[12] = 1;
   out_3160440324773884395[13] = 0;
   out_3160440324773884395[14] = 0;
   out_3160440324773884395[15] = dt;
   out_3160440324773884395[16] = 0;
   out_3160440324773884395[17] = 0;
   out_3160440324773884395[18] = 0;
   out_3160440324773884395[19] = 0;
   out_3160440324773884395[20] = 0;
   out_3160440324773884395[21] = 0;
   out_3160440324773884395[22] = 0;
   out_3160440324773884395[23] = 0;
   out_3160440324773884395[24] = 1;
   out_3160440324773884395[25] = 0;
   out_3160440324773884395[26] = 0;
   out_3160440324773884395[27] = dt;
   out_3160440324773884395[28] = 0;
   out_3160440324773884395[29] = 0;
   out_3160440324773884395[30] = 0;
   out_3160440324773884395[31] = 0;
   out_3160440324773884395[32] = 0;
   out_3160440324773884395[33] = 0;
   out_3160440324773884395[34] = 0;
   out_3160440324773884395[35] = 0;
   out_3160440324773884395[36] = 1;
   out_3160440324773884395[37] = 0;
   out_3160440324773884395[38] = 0;
   out_3160440324773884395[39] = 0;
   out_3160440324773884395[40] = 0;
   out_3160440324773884395[41] = 0;
   out_3160440324773884395[42] = 0;
   out_3160440324773884395[43] = 0;
   out_3160440324773884395[44] = 0;
   out_3160440324773884395[45] = 0;
   out_3160440324773884395[46] = 0;
   out_3160440324773884395[47] = 0;
   out_3160440324773884395[48] = 1;
   out_3160440324773884395[49] = 0;
   out_3160440324773884395[50] = 0;
   out_3160440324773884395[51] = 0;
   out_3160440324773884395[52] = 0;
   out_3160440324773884395[53] = 0;
   out_3160440324773884395[54] = 0;
   out_3160440324773884395[55] = 0;
   out_3160440324773884395[56] = 0;
   out_3160440324773884395[57] = 0;
   out_3160440324773884395[58] = 0;
   out_3160440324773884395[59] = 0;
   out_3160440324773884395[60] = 1;
   out_3160440324773884395[61] = 0;
   out_3160440324773884395[62] = 0;
   out_3160440324773884395[63] = 0;
   out_3160440324773884395[64] = 0;
   out_3160440324773884395[65] = 0;
   out_3160440324773884395[66] = 0;
   out_3160440324773884395[67] = 0;
   out_3160440324773884395[68] = 0;
   out_3160440324773884395[69] = 0;
   out_3160440324773884395[70] = 0;
   out_3160440324773884395[71] = 0;
   out_3160440324773884395[72] = 1;
   out_3160440324773884395[73] = dt;
   out_3160440324773884395[74] = 0;
   out_3160440324773884395[75] = 0;
   out_3160440324773884395[76] = 0;
   out_3160440324773884395[77] = 0;
   out_3160440324773884395[78] = 0;
   out_3160440324773884395[79] = 0;
   out_3160440324773884395[80] = 0;
   out_3160440324773884395[81] = 0;
   out_3160440324773884395[82] = 0;
   out_3160440324773884395[83] = 0;
   out_3160440324773884395[84] = 1;
   out_3160440324773884395[85] = dt;
   out_3160440324773884395[86] = 0;
   out_3160440324773884395[87] = 0;
   out_3160440324773884395[88] = 0;
   out_3160440324773884395[89] = 0;
   out_3160440324773884395[90] = 0;
   out_3160440324773884395[91] = 0;
   out_3160440324773884395[92] = 0;
   out_3160440324773884395[93] = 0;
   out_3160440324773884395[94] = 0;
   out_3160440324773884395[95] = 0;
   out_3160440324773884395[96] = 1;
   out_3160440324773884395[97] = 0;
   out_3160440324773884395[98] = 0;
   out_3160440324773884395[99] = 0;
   out_3160440324773884395[100] = 0;
   out_3160440324773884395[101] = 0;
   out_3160440324773884395[102] = 0;
   out_3160440324773884395[103] = 0;
   out_3160440324773884395[104] = 0;
   out_3160440324773884395[105] = 0;
   out_3160440324773884395[106] = 0;
   out_3160440324773884395[107] = 0;
   out_3160440324773884395[108] = 1;
   out_3160440324773884395[109] = 0;
   out_3160440324773884395[110] = 0;
   out_3160440324773884395[111] = 0;
   out_3160440324773884395[112] = 0;
   out_3160440324773884395[113] = 0;
   out_3160440324773884395[114] = 0;
   out_3160440324773884395[115] = 0;
   out_3160440324773884395[116] = 0;
   out_3160440324773884395[117] = 0;
   out_3160440324773884395[118] = 0;
   out_3160440324773884395[119] = 0;
   out_3160440324773884395[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_4164777334676317660) {
   out_4164777334676317660[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_8721522254593615931) {
   out_8721522254593615931[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8721522254593615931[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8721522254593615931[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8721522254593615931[3] = 0;
   out_8721522254593615931[4] = 0;
   out_8721522254593615931[5] = 0;
   out_8721522254593615931[6] = 1;
   out_8721522254593615931[7] = 0;
   out_8721522254593615931[8] = 0;
   out_8721522254593615931[9] = 0;
   out_8721522254593615931[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_1506605518158843733) {
   out_1506605518158843733[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_1146945854611411680) {
   out_1146945854611411680[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1146945854611411680[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1146945854611411680[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1146945854611411680[3] = 0;
   out_1146945854611411680[4] = 0;
   out_1146945854611411680[5] = 0;
   out_1146945854611411680[6] = 1;
   out_1146945854611411680[7] = 0;
   out_1146945854611411680[8] = 0;
   out_1146945854611411680[9] = 1;
   out_1146945854611411680[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_2838038345896688742) {
   out_2838038345896688742[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_7683900239883798223) {
   out_7683900239883798223[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[6] = 0;
   out_7683900239883798223[7] = 1;
   out_7683900239883798223[8] = 0;
   out_7683900239883798223[9] = 0;
   out_7683900239883798223[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_2838038345896688742) {
   out_2838038345896688742[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_7683900239883798223) {
   out_7683900239883798223[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7683900239883798223[6] = 0;
   out_7683900239883798223[7] = 1;
   out_7683900239883798223[8] = 0;
   out_7683900239883798223[9] = 0;
   out_7683900239883798223[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_80014774094776572) {
  err_fun(nom_x, delta_x, out_80014774094776572);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_9144507820461143592) {
  inv_err_fun(nom_x, true_x, out_9144507820461143592);
}
void gnss_H_mod_fun(double *state, double *out_3038444346073204801) {
  H_mod_fun(state, out_3038444346073204801);
}
void gnss_f_fun(double *state, double dt, double *out_5331942404729498203) {
  f_fun(state,  dt, out_5331942404729498203);
}
void gnss_F_fun(double *state, double dt, double *out_3160440324773884395) {
  F_fun(state,  dt, out_3160440324773884395);
}
void gnss_h_6(double *state, double *sat_pos, double *out_4164777334676317660) {
  h_6(state, sat_pos, out_4164777334676317660);
}
void gnss_H_6(double *state, double *sat_pos, double *out_8721522254593615931) {
  H_6(state, sat_pos, out_8721522254593615931);
}
void gnss_h_20(double *state, double *sat_pos, double *out_1506605518158843733) {
  h_20(state, sat_pos, out_1506605518158843733);
}
void gnss_H_20(double *state, double *sat_pos, double *out_1146945854611411680) {
  H_20(state, sat_pos, out_1146945854611411680);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2838038345896688742) {
  h_7(state, sat_pos_vel, out_2838038345896688742);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7683900239883798223) {
  H_7(state, sat_pos_vel, out_7683900239883798223);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2838038345896688742) {
  h_21(state, sat_pos_vel, out_2838038345896688742);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7683900239883798223) {
  H_21(state, sat_pos_vel, out_7683900239883798223);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
