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
void err_fun(double *nom_x, double *delta_x, double *out_2641878617010244620) {
   out_2641878617010244620[0] = delta_x[0] + nom_x[0];
   out_2641878617010244620[1] = delta_x[1] + nom_x[1];
   out_2641878617010244620[2] = delta_x[2] + nom_x[2];
   out_2641878617010244620[3] = delta_x[3] + nom_x[3];
   out_2641878617010244620[4] = delta_x[4] + nom_x[4];
   out_2641878617010244620[5] = delta_x[5] + nom_x[5];
   out_2641878617010244620[6] = delta_x[6] + nom_x[6];
   out_2641878617010244620[7] = delta_x[7] + nom_x[7];
   out_2641878617010244620[8] = delta_x[8] + nom_x[8];
   out_2641878617010244620[9] = delta_x[9] + nom_x[9];
   out_2641878617010244620[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6377401004299455720) {
   out_6377401004299455720[0] = -nom_x[0] + true_x[0];
   out_6377401004299455720[1] = -nom_x[1] + true_x[1];
   out_6377401004299455720[2] = -nom_x[2] + true_x[2];
   out_6377401004299455720[3] = -nom_x[3] + true_x[3];
   out_6377401004299455720[4] = -nom_x[4] + true_x[4];
   out_6377401004299455720[5] = -nom_x[5] + true_x[5];
   out_6377401004299455720[6] = -nom_x[6] + true_x[6];
   out_6377401004299455720[7] = -nom_x[7] + true_x[7];
   out_6377401004299455720[8] = -nom_x[8] + true_x[8];
   out_6377401004299455720[9] = -nom_x[9] + true_x[9];
   out_6377401004299455720[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_350167543532614649) {
   out_350167543532614649[0] = 1.0;
   out_350167543532614649[1] = 0;
   out_350167543532614649[2] = 0;
   out_350167543532614649[3] = 0;
   out_350167543532614649[4] = 0;
   out_350167543532614649[5] = 0;
   out_350167543532614649[6] = 0;
   out_350167543532614649[7] = 0;
   out_350167543532614649[8] = 0;
   out_350167543532614649[9] = 0;
   out_350167543532614649[10] = 0;
   out_350167543532614649[11] = 0;
   out_350167543532614649[12] = 1.0;
   out_350167543532614649[13] = 0;
   out_350167543532614649[14] = 0;
   out_350167543532614649[15] = 0;
   out_350167543532614649[16] = 0;
   out_350167543532614649[17] = 0;
   out_350167543532614649[18] = 0;
   out_350167543532614649[19] = 0;
   out_350167543532614649[20] = 0;
   out_350167543532614649[21] = 0;
   out_350167543532614649[22] = 0;
   out_350167543532614649[23] = 0;
   out_350167543532614649[24] = 1.0;
   out_350167543532614649[25] = 0;
   out_350167543532614649[26] = 0;
   out_350167543532614649[27] = 0;
   out_350167543532614649[28] = 0;
   out_350167543532614649[29] = 0;
   out_350167543532614649[30] = 0;
   out_350167543532614649[31] = 0;
   out_350167543532614649[32] = 0;
   out_350167543532614649[33] = 0;
   out_350167543532614649[34] = 0;
   out_350167543532614649[35] = 0;
   out_350167543532614649[36] = 1.0;
   out_350167543532614649[37] = 0;
   out_350167543532614649[38] = 0;
   out_350167543532614649[39] = 0;
   out_350167543532614649[40] = 0;
   out_350167543532614649[41] = 0;
   out_350167543532614649[42] = 0;
   out_350167543532614649[43] = 0;
   out_350167543532614649[44] = 0;
   out_350167543532614649[45] = 0;
   out_350167543532614649[46] = 0;
   out_350167543532614649[47] = 0;
   out_350167543532614649[48] = 1.0;
   out_350167543532614649[49] = 0;
   out_350167543532614649[50] = 0;
   out_350167543532614649[51] = 0;
   out_350167543532614649[52] = 0;
   out_350167543532614649[53] = 0;
   out_350167543532614649[54] = 0;
   out_350167543532614649[55] = 0;
   out_350167543532614649[56] = 0;
   out_350167543532614649[57] = 0;
   out_350167543532614649[58] = 0;
   out_350167543532614649[59] = 0;
   out_350167543532614649[60] = 1.0;
   out_350167543532614649[61] = 0;
   out_350167543532614649[62] = 0;
   out_350167543532614649[63] = 0;
   out_350167543532614649[64] = 0;
   out_350167543532614649[65] = 0;
   out_350167543532614649[66] = 0;
   out_350167543532614649[67] = 0;
   out_350167543532614649[68] = 0;
   out_350167543532614649[69] = 0;
   out_350167543532614649[70] = 0;
   out_350167543532614649[71] = 0;
   out_350167543532614649[72] = 1.0;
   out_350167543532614649[73] = 0;
   out_350167543532614649[74] = 0;
   out_350167543532614649[75] = 0;
   out_350167543532614649[76] = 0;
   out_350167543532614649[77] = 0;
   out_350167543532614649[78] = 0;
   out_350167543532614649[79] = 0;
   out_350167543532614649[80] = 0;
   out_350167543532614649[81] = 0;
   out_350167543532614649[82] = 0;
   out_350167543532614649[83] = 0;
   out_350167543532614649[84] = 1.0;
   out_350167543532614649[85] = 0;
   out_350167543532614649[86] = 0;
   out_350167543532614649[87] = 0;
   out_350167543532614649[88] = 0;
   out_350167543532614649[89] = 0;
   out_350167543532614649[90] = 0;
   out_350167543532614649[91] = 0;
   out_350167543532614649[92] = 0;
   out_350167543532614649[93] = 0;
   out_350167543532614649[94] = 0;
   out_350167543532614649[95] = 0;
   out_350167543532614649[96] = 1.0;
   out_350167543532614649[97] = 0;
   out_350167543532614649[98] = 0;
   out_350167543532614649[99] = 0;
   out_350167543532614649[100] = 0;
   out_350167543532614649[101] = 0;
   out_350167543532614649[102] = 0;
   out_350167543532614649[103] = 0;
   out_350167543532614649[104] = 0;
   out_350167543532614649[105] = 0;
   out_350167543532614649[106] = 0;
   out_350167543532614649[107] = 0;
   out_350167543532614649[108] = 1.0;
   out_350167543532614649[109] = 0;
   out_350167543532614649[110] = 0;
   out_350167543532614649[111] = 0;
   out_350167543532614649[112] = 0;
   out_350167543532614649[113] = 0;
   out_350167543532614649[114] = 0;
   out_350167543532614649[115] = 0;
   out_350167543532614649[116] = 0;
   out_350167543532614649[117] = 0;
   out_350167543532614649[118] = 0;
   out_350167543532614649[119] = 0;
   out_350167543532614649[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_6672020356614883149) {
   out_6672020356614883149[0] = dt*state[3] + state[0];
   out_6672020356614883149[1] = dt*state[4] + state[1];
   out_6672020356614883149[2] = dt*state[5] + state[2];
   out_6672020356614883149[3] = state[3];
   out_6672020356614883149[4] = state[4];
   out_6672020356614883149[5] = state[5];
   out_6672020356614883149[6] = dt*state[7] + state[6];
   out_6672020356614883149[7] = dt*state[8] + state[7];
   out_6672020356614883149[8] = state[8];
   out_6672020356614883149[9] = state[9];
   out_6672020356614883149[10] = state[10];
}
void F_fun(double *state, double dt, double *out_1674482844242533979) {
   out_1674482844242533979[0] = 1;
   out_1674482844242533979[1] = 0;
   out_1674482844242533979[2] = 0;
   out_1674482844242533979[3] = dt;
   out_1674482844242533979[4] = 0;
   out_1674482844242533979[5] = 0;
   out_1674482844242533979[6] = 0;
   out_1674482844242533979[7] = 0;
   out_1674482844242533979[8] = 0;
   out_1674482844242533979[9] = 0;
   out_1674482844242533979[10] = 0;
   out_1674482844242533979[11] = 0;
   out_1674482844242533979[12] = 1;
   out_1674482844242533979[13] = 0;
   out_1674482844242533979[14] = 0;
   out_1674482844242533979[15] = dt;
   out_1674482844242533979[16] = 0;
   out_1674482844242533979[17] = 0;
   out_1674482844242533979[18] = 0;
   out_1674482844242533979[19] = 0;
   out_1674482844242533979[20] = 0;
   out_1674482844242533979[21] = 0;
   out_1674482844242533979[22] = 0;
   out_1674482844242533979[23] = 0;
   out_1674482844242533979[24] = 1;
   out_1674482844242533979[25] = 0;
   out_1674482844242533979[26] = 0;
   out_1674482844242533979[27] = dt;
   out_1674482844242533979[28] = 0;
   out_1674482844242533979[29] = 0;
   out_1674482844242533979[30] = 0;
   out_1674482844242533979[31] = 0;
   out_1674482844242533979[32] = 0;
   out_1674482844242533979[33] = 0;
   out_1674482844242533979[34] = 0;
   out_1674482844242533979[35] = 0;
   out_1674482844242533979[36] = 1;
   out_1674482844242533979[37] = 0;
   out_1674482844242533979[38] = 0;
   out_1674482844242533979[39] = 0;
   out_1674482844242533979[40] = 0;
   out_1674482844242533979[41] = 0;
   out_1674482844242533979[42] = 0;
   out_1674482844242533979[43] = 0;
   out_1674482844242533979[44] = 0;
   out_1674482844242533979[45] = 0;
   out_1674482844242533979[46] = 0;
   out_1674482844242533979[47] = 0;
   out_1674482844242533979[48] = 1;
   out_1674482844242533979[49] = 0;
   out_1674482844242533979[50] = 0;
   out_1674482844242533979[51] = 0;
   out_1674482844242533979[52] = 0;
   out_1674482844242533979[53] = 0;
   out_1674482844242533979[54] = 0;
   out_1674482844242533979[55] = 0;
   out_1674482844242533979[56] = 0;
   out_1674482844242533979[57] = 0;
   out_1674482844242533979[58] = 0;
   out_1674482844242533979[59] = 0;
   out_1674482844242533979[60] = 1;
   out_1674482844242533979[61] = 0;
   out_1674482844242533979[62] = 0;
   out_1674482844242533979[63] = 0;
   out_1674482844242533979[64] = 0;
   out_1674482844242533979[65] = 0;
   out_1674482844242533979[66] = 0;
   out_1674482844242533979[67] = 0;
   out_1674482844242533979[68] = 0;
   out_1674482844242533979[69] = 0;
   out_1674482844242533979[70] = 0;
   out_1674482844242533979[71] = 0;
   out_1674482844242533979[72] = 1;
   out_1674482844242533979[73] = dt;
   out_1674482844242533979[74] = 0;
   out_1674482844242533979[75] = 0;
   out_1674482844242533979[76] = 0;
   out_1674482844242533979[77] = 0;
   out_1674482844242533979[78] = 0;
   out_1674482844242533979[79] = 0;
   out_1674482844242533979[80] = 0;
   out_1674482844242533979[81] = 0;
   out_1674482844242533979[82] = 0;
   out_1674482844242533979[83] = 0;
   out_1674482844242533979[84] = 1;
   out_1674482844242533979[85] = dt;
   out_1674482844242533979[86] = 0;
   out_1674482844242533979[87] = 0;
   out_1674482844242533979[88] = 0;
   out_1674482844242533979[89] = 0;
   out_1674482844242533979[90] = 0;
   out_1674482844242533979[91] = 0;
   out_1674482844242533979[92] = 0;
   out_1674482844242533979[93] = 0;
   out_1674482844242533979[94] = 0;
   out_1674482844242533979[95] = 0;
   out_1674482844242533979[96] = 1;
   out_1674482844242533979[97] = 0;
   out_1674482844242533979[98] = 0;
   out_1674482844242533979[99] = 0;
   out_1674482844242533979[100] = 0;
   out_1674482844242533979[101] = 0;
   out_1674482844242533979[102] = 0;
   out_1674482844242533979[103] = 0;
   out_1674482844242533979[104] = 0;
   out_1674482844242533979[105] = 0;
   out_1674482844242533979[106] = 0;
   out_1674482844242533979[107] = 0;
   out_1674482844242533979[108] = 1;
   out_1674482844242533979[109] = 0;
   out_1674482844242533979[110] = 0;
   out_1674482844242533979[111] = 0;
   out_1674482844242533979[112] = 0;
   out_1674482844242533979[113] = 0;
   out_1674482844242533979[114] = 0;
   out_1674482844242533979[115] = 0;
   out_1674482844242533979[116] = 0;
   out_1674482844242533979[117] = 0;
   out_1674482844242533979[118] = 0;
   out_1674482844242533979[119] = 0;
   out_1674482844242533979[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_5972909262720134315) {
   out_5972909262720134315[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_3653461233205109228) {
   out_3653461233205109228[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3653461233205109228[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3653461233205109228[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3653461233205109228[3] = 0;
   out_3653461233205109228[4] = 0;
   out_3653461233205109228[5] = 0;
   out_3653461233205109228[6] = 1;
   out_3653461233205109228[7] = 0;
   out_3653461233205109228[8] = 0;
   out_3653461233205109228[9] = 0;
   out_3653461233205109228[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_4250972716649874804) {
   out_4250972716649874804[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_7645549737271804400) {
   out_7645549737271804400[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7645549737271804400[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7645549737271804400[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7645549737271804400[3] = 0;
   out_7645549737271804400[4] = 0;
   out_7645549737271804400[5] = 0;
   out_7645549737271804400[6] = 1;
   out_7645549737271804400[7] = 0;
   out_7645549737271804400[8] = 0;
   out_7645549737271804400[9] = 1;
   out_7645549737271804400[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_8613498608425957392) {
   out_8613498608425957392[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_217272578096397715) {
   out_217272578096397715[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[6] = 0;
   out_217272578096397715[7] = 1;
   out_217272578096397715[8] = 0;
   out_217272578096397715[9] = 0;
   out_217272578096397715[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_8613498608425957392) {
   out_8613498608425957392[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_217272578096397715) {
   out_217272578096397715[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_217272578096397715[6] = 0;
   out_217272578096397715[7] = 1;
   out_217272578096397715[8] = 0;
   out_217272578096397715[9] = 0;
   out_217272578096397715[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2641878617010244620) {
  err_fun(nom_x, delta_x, out_2641878617010244620);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6377401004299455720) {
  inv_err_fun(nom_x, true_x, out_6377401004299455720);
}
void gnss_H_mod_fun(double *state, double *out_350167543532614649) {
  H_mod_fun(state, out_350167543532614649);
}
void gnss_f_fun(double *state, double dt, double *out_6672020356614883149) {
  f_fun(state,  dt, out_6672020356614883149);
}
void gnss_F_fun(double *state, double dt, double *out_1674482844242533979) {
  F_fun(state,  dt, out_1674482844242533979);
}
void gnss_h_6(double *state, double *sat_pos, double *out_5972909262720134315) {
  h_6(state, sat_pos, out_5972909262720134315);
}
void gnss_H_6(double *state, double *sat_pos, double *out_3653461233205109228) {
  H_6(state, sat_pos, out_3653461233205109228);
}
void gnss_h_20(double *state, double *sat_pos, double *out_4250972716649874804) {
  h_20(state, sat_pos, out_4250972716649874804);
}
void gnss_H_20(double *state, double *sat_pos, double *out_7645549737271804400) {
  H_20(state, sat_pos, out_7645549737271804400);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8613498608425957392) {
  h_7(state, sat_pos_vel, out_8613498608425957392);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_217272578096397715) {
  H_7(state, sat_pos_vel, out_217272578096397715);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8613498608425957392) {
  h_21(state, sat_pos_vel, out_8613498608425957392);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_217272578096397715) {
  H_21(state, sat_pos_vel, out_217272578096397715);
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
