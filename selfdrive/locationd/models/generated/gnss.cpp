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
void err_fun(double *nom_x, double *delta_x, double *out_4620912923766298580) {
   out_4620912923766298580[0] = delta_x[0] + nom_x[0];
   out_4620912923766298580[1] = delta_x[1] + nom_x[1];
   out_4620912923766298580[2] = delta_x[2] + nom_x[2];
   out_4620912923766298580[3] = delta_x[3] + nom_x[3];
   out_4620912923766298580[4] = delta_x[4] + nom_x[4];
   out_4620912923766298580[5] = delta_x[5] + nom_x[5];
   out_4620912923766298580[6] = delta_x[6] + nom_x[6];
   out_4620912923766298580[7] = delta_x[7] + nom_x[7];
   out_4620912923766298580[8] = delta_x[8] + nom_x[8];
   out_4620912923766298580[9] = delta_x[9] + nom_x[9];
   out_4620912923766298580[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9187715529705882522) {
   out_9187715529705882522[0] = -nom_x[0] + true_x[0];
   out_9187715529705882522[1] = -nom_x[1] + true_x[1];
   out_9187715529705882522[2] = -nom_x[2] + true_x[2];
   out_9187715529705882522[3] = -nom_x[3] + true_x[3];
   out_9187715529705882522[4] = -nom_x[4] + true_x[4];
   out_9187715529705882522[5] = -nom_x[5] + true_x[5];
   out_9187715529705882522[6] = -nom_x[6] + true_x[6];
   out_9187715529705882522[7] = -nom_x[7] + true_x[7];
   out_9187715529705882522[8] = -nom_x[8] + true_x[8];
   out_9187715529705882522[9] = -nom_x[9] + true_x[9];
   out_9187715529705882522[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_922973610943044438) {
   out_922973610943044438[0] = 1.0;
   out_922973610943044438[1] = 0;
   out_922973610943044438[2] = 0;
   out_922973610943044438[3] = 0;
   out_922973610943044438[4] = 0;
   out_922973610943044438[5] = 0;
   out_922973610943044438[6] = 0;
   out_922973610943044438[7] = 0;
   out_922973610943044438[8] = 0;
   out_922973610943044438[9] = 0;
   out_922973610943044438[10] = 0;
   out_922973610943044438[11] = 0;
   out_922973610943044438[12] = 1.0;
   out_922973610943044438[13] = 0;
   out_922973610943044438[14] = 0;
   out_922973610943044438[15] = 0;
   out_922973610943044438[16] = 0;
   out_922973610943044438[17] = 0;
   out_922973610943044438[18] = 0;
   out_922973610943044438[19] = 0;
   out_922973610943044438[20] = 0;
   out_922973610943044438[21] = 0;
   out_922973610943044438[22] = 0;
   out_922973610943044438[23] = 0;
   out_922973610943044438[24] = 1.0;
   out_922973610943044438[25] = 0;
   out_922973610943044438[26] = 0;
   out_922973610943044438[27] = 0;
   out_922973610943044438[28] = 0;
   out_922973610943044438[29] = 0;
   out_922973610943044438[30] = 0;
   out_922973610943044438[31] = 0;
   out_922973610943044438[32] = 0;
   out_922973610943044438[33] = 0;
   out_922973610943044438[34] = 0;
   out_922973610943044438[35] = 0;
   out_922973610943044438[36] = 1.0;
   out_922973610943044438[37] = 0;
   out_922973610943044438[38] = 0;
   out_922973610943044438[39] = 0;
   out_922973610943044438[40] = 0;
   out_922973610943044438[41] = 0;
   out_922973610943044438[42] = 0;
   out_922973610943044438[43] = 0;
   out_922973610943044438[44] = 0;
   out_922973610943044438[45] = 0;
   out_922973610943044438[46] = 0;
   out_922973610943044438[47] = 0;
   out_922973610943044438[48] = 1.0;
   out_922973610943044438[49] = 0;
   out_922973610943044438[50] = 0;
   out_922973610943044438[51] = 0;
   out_922973610943044438[52] = 0;
   out_922973610943044438[53] = 0;
   out_922973610943044438[54] = 0;
   out_922973610943044438[55] = 0;
   out_922973610943044438[56] = 0;
   out_922973610943044438[57] = 0;
   out_922973610943044438[58] = 0;
   out_922973610943044438[59] = 0;
   out_922973610943044438[60] = 1.0;
   out_922973610943044438[61] = 0;
   out_922973610943044438[62] = 0;
   out_922973610943044438[63] = 0;
   out_922973610943044438[64] = 0;
   out_922973610943044438[65] = 0;
   out_922973610943044438[66] = 0;
   out_922973610943044438[67] = 0;
   out_922973610943044438[68] = 0;
   out_922973610943044438[69] = 0;
   out_922973610943044438[70] = 0;
   out_922973610943044438[71] = 0;
   out_922973610943044438[72] = 1.0;
   out_922973610943044438[73] = 0;
   out_922973610943044438[74] = 0;
   out_922973610943044438[75] = 0;
   out_922973610943044438[76] = 0;
   out_922973610943044438[77] = 0;
   out_922973610943044438[78] = 0;
   out_922973610943044438[79] = 0;
   out_922973610943044438[80] = 0;
   out_922973610943044438[81] = 0;
   out_922973610943044438[82] = 0;
   out_922973610943044438[83] = 0;
   out_922973610943044438[84] = 1.0;
   out_922973610943044438[85] = 0;
   out_922973610943044438[86] = 0;
   out_922973610943044438[87] = 0;
   out_922973610943044438[88] = 0;
   out_922973610943044438[89] = 0;
   out_922973610943044438[90] = 0;
   out_922973610943044438[91] = 0;
   out_922973610943044438[92] = 0;
   out_922973610943044438[93] = 0;
   out_922973610943044438[94] = 0;
   out_922973610943044438[95] = 0;
   out_922973610943044438[96] = 1.0;
   out_922973610943044438[97] = 0;
   out_922973610943044438[98] = 0;
   out_922973610943044438[99] = 0;
   out_922973610943044438[100] = 0;
   out_922973610943044438[101] = 0;
   out_922973610943044438[102] = 0;
   out_922973610943044438[103] = 0;
   out_922973610943044438[104] = 0;
   out_922973610943044438[105] = 0;
   out_922973610943044438[106] = 0;
   out_922973610943044438[107] = 0;
   out_922973610943044438[108] = 1.0;
   out_922973610943044438[109] = 0;
   out_922973610943044438[110] = 0;
   out_922973610943044438[111] = 0;
   out_922973610943044438[112] = 0;
   out_922973610943044438[113] = 0;
   out_922973610943044438[114] = 0;
   out_922973610943044438[115] = 0;
   out_922973610943044438[116] = 0;
   out_922973610943044438[117] = 0;
   out_922973610943044438[118] = 0;
   out_922973610943044438[119] = 0;
   out_922973610943044438[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_1079402724574081004) {
   out_1079402724574081004[0] = dt*state[3] + state[0];
   out_1079402724574081004[1] = dt*state[4] + state[1];
   out_1079402724574081004[2] = dt*state[5] + state[2];
   out_1079402724574081004[3] = state[3];
   out_1079402724574081004[4] = state[4];
   out_1079402724574081004[5] = state[5];
   out_1079402724574081004[6] = dt*state[7] + state[6];
   out_1079402724574081004[7] = dt*state[8] + state[7];
   out_1079402724574081004[8] = state[8];
   out_1079402724574081004[9] = state[9];
   out_1079402724574081004[10] = state[10];
}
void F_fun(double *state, double dt, double *out_3039166340276301210) {
   out_3039166340276301210[0] = 1;
   out_3039166340276301210[1] = 0;
   out_3039166340276301210[2] = 0;
   out_3039166340276301210[3] = dt;
   out_3039166340276301210[4] = 0;
   out_3039166340276301210[5] = 0;
   out_3039166340276301210[6] = 0;
   out_3039166340276301210[7] = 0;
   out_3039166340276301210[8] = 0;
   out_3039166340276301210[9] = 0;
   out_3039166340276301210[10] = 0;
   out_3039166340276301210[11] = 0;
   out_3039166340276301210[12] = 1;
   out_3039166340276301210[13] = 0;
   out_3039166340276301210[14] = 0;
   out_3039166340276301210[15] = dt;
   out_3039166340276301210[16] = 0;
   out_3039166340276301210[17] = 0;
   out_3039166340276301210[18] = 0;
   out_3039166340276301210[19] = 0;
   out_3039166340276301210[20] = 0;
   out_3039166340276301210[21] = 0;
   out_3039166340276301210[22] = 0;
   out_3039166340276301210[23] = 0;
   out_3039166340276301210[24] = 1;
   out_3039166340276301210[25] = 0;
   out_3039166340276301210[26] = 0;
   out_3039166340276301210[27] = dt;
   out_3039166340276301210[28] = 0;
   out_3039166340276301210[29] = 0;
   out_3039166340276301210[30] = 0;
   out_3039166340276301210[31] = 0;
   out_3039166340276301210[32] = 0;
   out_3039166340276301210[33] = 0;
   out_3039166340276301210[34] = 0;
   out_3039166340276301210[35] = 0;
   out_3039166340276301210[36] = 1;
   out_3039166340276301210[37] = 0;
   out_3039166340276301210[38] = 0;
   out_3039166340276301210[39] = 0;
   out_3039166340276301210[40] = 0;
   out_3039166340276301210[41] = 0;
   out_3039166340276301210[42] = 0;
   out_3039166340276301210[43] = 0;
   out_3039166340276301210[44] = 0;
   out_3039166340276301210[45] = 0;
   out_3039166340276301210[46] = 0;
   out_3039166340276301210[47] = 0;
   out_3039166340276301210[48] = 1;
   out_3039166340276301210[49] = 0;
   out_3039166340276301210[50] = 0;
   out_3039166340276301210[51] = 0;
   out_3039166340276301210[52] = 0;
   out_3039166340276301210[53] = 0;
   out_3039166340276301210[54] = 0;
   out_3039166340276301210[55] = 0;
   out_3039166340276301210[56] = 0;
   out_3039166340276301210[57] = 0;
   out_3039166340276301210[58] = 0;
   out_3039166340276301210[59] = 0;
   out_3039166340276301210[60] = 1;
   out_3039166340276301210[61] = 0;
   out_3039166340276301210[62] = 0;
   out_3039166340276301210[63] = 0;
   out_3039166340276301210[64] = 0;
   out_3039166340276301210[65] = 0;
   out_3039166340276301210[66] = 0;
   out_3039166340276301210[67] = 0;
   out_3039166340276301210[68] = 0;
   out_3039166340276301210[69] = 0;
   out_3039166340276301210[70] = 0;
   out_3039166340276301210[71] = 0;
   out_3039166340276301210[72] = 1;
   out_3039166340276301210[73] = dt;
   out_3039166340276301210[74] = 0;
   out_3039166340276301210[75] = 0;
   out_3039166340276301210[76] = 0;
   out_3039166340276301210[77] = 0;
   out_3039166340276301210[78] = 0;
   out_3039166340276301210[79] = 0;
   out_3039166340276301210[80] = 0;
   out_3039166340276301210[81] = 0;
   out_3039166340276301210[82] = 0;
   out_3039166340276301210[83] = 0;
   out_3039166340276301210[84] = 1;
   out_3039166340276301210[85] = dt;
   out_3039166340276301210[86] = 0;
   out_3039166340276301210[87] = 0;
   out_3039166340276301210[88] = 0;
   out_3039166340276301210[89] = 0;
   out_3039166340276301210[90] = 0;
   out_3039166340276301210[91] = 0;
   out_3039166340276301210[92] = 0;
   out_3039166340276301210[93] = 0;
   out_3039166340276301210[94] = 0;
   out_3039166340276301210[95] = 0;
   out_3039166340276301210[96] = 1;
   out_3039166340276301210[97] = 0;
   out_3039166340276301210[98] = 0;
   out_3039166340276301210[99] = 0;
   out_3039166340276301210[100] = 0;
   out_3039166340276301210[101] = 0;
   out_3039166340276301210[102] = 0;
   out_3039166340276301210[103] = 0;
   out_3039166340276301210[104] = 0;
   out_3039166340276301210[105] = 0;
   out_3039166340276301210[106] = 0;
   out_3039166340276301210[107] = 0;
   out_3039166340276301210[108] = 1;
   out_3039166340276301210[109] = 0;
   out_3039166340276301210[110] = 0;
   out_3039166340276301210[111] = 0;
   out_3039166340276301210[112] = 0;
   out_3039166340276301210[113] = 0;
   out_3039166340276301210[114] = 0;
   out_3039166340276301210[115] = 0;
   out_3039166340276301210[116] = 0;
   out_3039166340276301210[117] = 0;
   out_3039166340276301210[118] = 0;
   out_3039166340276301210[119] = 0;
   out_3039166340276301210[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_3874365000426709074) {
   out_3874365000426709074[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_3986922819635287129) {
   out_3986922819635287129[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3986922819635287129[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3986922819635287129[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3986922819635287129[3] = 0;
   out_3986922819635287129[4] = 0;
   out_3986922819635287129[5] = 0;
   out_3986922819635287129[6] = 1;
   out_3986922819635287129[7] = 0;
   out_3986922819635287129[8] = 0;
   out_3986922819635287129[9] = 0;
   out_3986922819635287129[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_5069168270486129229) {
   out_5069168270486129229[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_678918665408427203) {
   out_678918665408427203[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_678918665408427203[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_678918665408427203[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_678918665408427203[3] = 0;
   out_678918665408427203[4] = 0;
   out_678918665408427203[5] = 0;
   out_678918665408427203[6] = 1;
   out_678918665408427203[7] = 0;
   out_678918665408427203[8] = 0;
   out_678918665408427203[9] = 1;
   out_678918665408427203[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_9105285764076347784) {
   out_9105285764076347784[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_7685540822919128148) {
   out_7685540822919128148[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[6] = 0;
   out_7685540822919128148[7] = 1;
   out_7685540822919128148[8] = 0;
   out_7685540822919128148[9] = 0;
   out_7685540822919128148[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_9105285764076347784) {
   out_9105285764076347784[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_7685540822919128148) {
   out_7685540822919128148[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7685540822919128148[6] = 0;
   out_7685540822919128148[7] = 1;
   out_7685540822919128148[8] = 0;
   out_7685540822919128148[9] = 0;
   out_7685540822919128148[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4620912923766298580) {
  err_fun(nom_x, delta_x, out_4620912923766298580);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_9187715529705882522) {
  inv_err_fun(nom_x, true_x, out_9187715529705882522);
}
void gnss_H_mod_fun(double *state, double *out_922973610943044438) {
  H_mod_fun(state, out_922973610943044438);
}
void gnss_f_fun(double *state, double dt, double *out_1079402724574081004) {
  f_fun(state,  dt, out_1079402724574081004);
}
void gnss_F_fun(double *state, double dt, double *out_3039166340276301210) {
  F_fun(state,  dt, out_3039166340276301210);
}
void gnss_h_6(double *state, double *sat_pos, double *out_3874365000426709074) {
  h_6(state, sat_pos, out_3874365000426709074);
}
void gnss_H_6(double *state, double *sat_pos, double *out_3986922819635287129) {
  H_6(state, sat_pos, out_3986922819635287129);
}
void gnss_h_20(double *state, double *sat_pos, double *out_5069168270486129229) {
  h_20(state, sat_pos, out_5069168270486129229);
}
void gnss_H_20(double *state, double *sat_pos, double *out_678918665408427203) {
  H_20(state, sat_pos, out_678918665408427203);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_9105285764076347784) {
  h_7(state, sat_pos_vel, out_9105285764076347784);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7685540822919128148) {
  H_7(state, sat_pos_vel, out_7685540822919128148);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_9105285764076347784) {
  h_21(state, sat_pos_vel, out_9105285764076347784);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7685540822919128148) {
  H_21(state, sat_pos_vel, out_7685540822919128148);
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
