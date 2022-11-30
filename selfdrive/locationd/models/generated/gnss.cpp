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
void err_fun(double *nom_x, double *delta_x, double *out_1734633203049768488) {
   out_1734633203049768488[0] = delta_x[0] + nom_x[0];
   out_1734633203049768488[1] = delta_x[1] + nom_x[1];
   out_1734633203049768488[2] = delta_x[2] + nom_x[2];
   out_1734633203049768488[3] = delta_x[3] + nom_x[3];
   out_1734633203049768488[4] = delta_x[4] + nom_x[4];
   out_1734633203049768488[5] = delta_x[5] + nom_x[5];
   out_1734633203049768488[6] = delta_x[6] + nom_x[6];
   out_1734633203049768488[7] = delta_x[7] + nom_x[7];
   out_1734633203049768488[8] = delta_x[8] + nom_x[8];
   out_1734633203049768488[9] = delta_x[9] + nom_x[9];
   out_1734633203049768488[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7226800202829737504) {
   out_7226800202829737504[0] = -nom_x[0] + true_x[0];
   out_7226800202829737504[1] = -nom_x[1] + true_x[1];
   out_7226800202829737504[2] = -nom_x[2] + true_x[2];
   out_7226800202829737504[3] = -nom_x[3] + true_x[3];
   out_7226800202829737504[4] = -nom_x[4] + true_x[4];
   out_7226800202829737504[5] = -nom_x[5] + true_x[5];
   out_7226800202829737504[6] = -nom_x[6] + true_x[6];
   out_7226800202829737504[7] = -nom_x[7] + true_x[7];
   out_7226800202829737504[8] = -nom_x[8] + true_x[8];
   out_7226800202829737504[9] = -nom_x[9] + true_x[9];
   out_7226800202829737504[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_7212715412967761026) {
   out_7212715412967761026[0] = 1.0;
   out_7212715412967761026[1] = 0;
   out_7212715412967761026[2] = 0;
   out_7212715412967761026[3] = 0;
   out_7212715412967761026[4] = 0;
   out_7212715412967761026[5] = 0;
   out_7212715412967761026[6] = 0;
   out_7212715412967761026[7] = 0;
   out_7212715412967761026[8] = 0;
   out_7212715412967761026[9] = 0;
   out_7212715412967761026[10] = 0;
   out_7212715412967761026[11] = 0;
   out_7212715412967761026[12] = 1.0;
   out_7212715412967761026[13] = 0;
   out_7212715412967761026[14] = 0;
   out_7212715412967761026[15] = 0;
   out_7212715412967761026[16] = 0;
   out_7212715412967761026[17] = 0;
   out_7212715412967761026[18] = 0;
   out_7212715412967761026[19] = 0;
   out_7212715412967761026[20] = 0;
   out_7212715412967761026[21] = 0;
   out_7212715412967761026[22] = 0;
   out_7212715412967761026[23] = 0;
   out_7212715412967761026[24] = 1.0;
   out_7212715412967761026[25] = 0;
   out_7212715412967761026[26] = 0;
   out_7212715412967761026[27] = 0;
   out_7212715412967761026[28] = 0;
   out_7212715412967761026[29] = 0;
   out_7212715412967761026[30] = 0;
   out_7212715412967761026[31] = 0;
   out_7212715412967761026[32] = 0;
   out_7212715412967761026[33] = 0;
   out_7212715412967761026[34] = 0;
   out_7212715412967761026[35] = 0;
   out_7212715412967761026[36] = 1.0;
   out_7212715412967761026[37] = 0;
   out_7212715412967761026[38] = 0;
   out_7212715412967761026[39] = 0;
   out_7212715412967761026[40] = 0;
   out_7212715412967761026[41] = 0;
   out_7212715412967761026[42] = 0;
   out_7212715412967761026[43] = 0;
   out_7212715412967761026[44] = 0;
   out_7212715412967761026[45] = 0;
   out_7212715412967761026[46] = 0;
   out_7212715412967761026[47] = 0;
   out_7212715412967761026[48] = 1.0;
   out_7212715412967761026[49] = 0;
   out_7212715412967761026[50] = 0;
   out_7212715412967761026[51] = 0;
   out_7212715412967761026[52] = 0;
   out_7212715412967761026[53] = 0;
   out_7212715412967761026[54] = 0;
   out_7212715412967761026[55] = 0;
   out_7212715412967761026[56] = 0;
   out_7212715412967761026[57] = 0;
   out_7212715412967761026[58] = 0;
   out_7212715412967761026[59] = 0;
   out_7212715412967761026[60] = 1.0;
   out_7212715412967761026[61] = 0;
   out_7212715412967761026[62] = 0;
   out_7212715412967761026[63] = 0;
   out_7212715412967761026[64] = 0;
   out_7212715412967761026[65] = 0;
   out_7212715412967761026[66] = 0;
   out_7212715412967761026[67] = 0;
   out_7212715412967761026[68] = 0;
   out_7212715412967761026[69] = 0;
   out_7212715412967761026[70] = 0;
   out_7212715412967761026[71] = 0;
   out_7212715412967761026[72] = 1.0;
   out_7212715412967761026[73] = 0;
   out_7212715412967761026[74] = 0;
   out_7212715412967761026[75] = 0;
   out_7212715412967761026[76] = 0;
   out_7212715412967761026[77] = 0;
   out_7212715412967761026[78] = 0;
   out_7212715412967761026[79] = 0;
   out_7212715412967761026[80] = 0;
   out_7212715412967761026[81] = 0;
   out_7212715412967761026[82] = 0;
   out_7212715412967761026[83] = 0;
   out_7212715412967761026[84] = 1.0;
   out_7212715412967761026[85] = 0;
   out_7212715412967761026[86] = 0;
   out_7212715412967761026[87] = 0;
   out_7212715412967761026[88] = 0;
   out_7212715412967761026[89] = 0;
   out_7212715412967761026[90] = 0;
   out_7212715412967761026[91] = 0;
   out_7212715412967761026[92] = 0;
   out_7212715412967761026[93] = 0;
   out_7212715412967761026[94] = 0;
   out_7212715412967761026[95] = 0;
   out_7212715412967761026[96] = 1.0;
   out_7212715412967761026[97] = 0;
   out_7212715412967761026[98] = 0;
   out_7212715412967761026[99] = 0;
   out_7212715412967761026[100] = 0;
   out_7212715412967761026[101] = 0;
   out_7212715412967761026[102] = 0;
   out_7212715412967761026[103] = 0;
   out_7212715412967761026[104] = 0;
   out_7212715412967761026[105] = 0;
   out_7212715412967761026[106] = 0;
   out_7212715412967761026[107] = 0;
   out_7212715412967761026[108] = 1.0;
   out_7212715412967761026[109] = 0;
   out_7212715412967761026[110] = 0;
   out_7212715412967761026[111] = 0;
   out_7212715412967761026[112] = 0;
   out_7212715412967761026[113] = 0;
   out_7212715412967761026[114] = 0;
   out_7212715412967761026[115] = 0;
   out_7212715412967761026[116] = 0;
   out_7212715412967761026[117] = 0;
   out_7212715412967761026[118] = 0;
   out_7212715412967761026[119] = 0;
   out_7212715412967761026[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_4622219999608348212) {
   out_4622219999608348212[0] = dt*state[3] + state[0];
   out_4622219999608348212[1] = dt*state[4] + state[1];
   out_4622219999608348212[2] = dt*state[5] + state[2];
   out_4622219999608348212[3] = state[3];
   out_4622219999608348212[4] = state[4];
   out_4622219999608348212[5] = state[5];
   out_4622219999608348212[6] = dt*state[7] + state[6];
   out_4622219999608348212[7] = dt*state[8] + state[7];
   out_4622219999608348212[8] = state[8];
   out_4622219999608348212[9] = state[9];
   out_4622219999608348212[10] = state[10];
}
void F_fun(double *state, double dt, double *out_1489675256084431222) {
   out_1489675256084431222[0] = 1;
   out_1489675256084431222[1] = 0;
   out_1489675256084431222[2] = 0;
   out_1489675256084431222[3] = dt;
   out_1489675256084431222[4] = 0;
   out_1489675256084431222[5] = 0;
   out_1489675256084431222[6] = 0;
   out_1489675256084431222[7] = 0;
   out_1489675256084431222[8] = 0;
   out_1489675256084431222[9] = 0;
   out_1489675256084431222[10] = 0;
   out_1489675256084431222[11] = 0;
   out_1489675256084431222[12] = 1;
   out_1489675256084431222[13] = 0;
   out_1489675256084431222[14] = 0;
   out_1489675256084431222[15] = dt;
   out_1489675256084431222[16] = 0;
   out_1489675256084431222[17] = 0;
   out_1489675256084431222[18] = 0;
   out_1489675256084431222[19] = 0;
   out_1489675256084431222[20] = 0;
   out_1489675256084431222[21] = 0;
   out_1489675256084431222[22] = 0;
   out_1489675256084431222[23] = 0;
   out_1489675256084431222[24] = 1;
   out_1489675256084431222[25] = 0;
   out_1489675256084431222[26] = 0;
   out_1489675256084431222[27] = dt;
   out_1489675256084431222[28] = 0;
   out_1489675256084431222[29] = 0;
   out_1489675256084431222[30] = 0;
   out_1489675256084431222[31] = 0;
   out_1489675256084431222[32] = 0;
   out_1489675256084431222[33] = 0;
   out_1489675256084431222[34] = 0;
   out_1489675256084431222[35] = 0;
   out_1489675256084431222[36] = 1;
   out_1489675256084431222[37] = 0;
   out_1489675256084431222[38] = 0;
   out_1489675256084431222[39] = 0;
   out_1489675256084431222[40] = 0;
   out_1489675256084431222[41] = 0;
   out_1489675256084431222[42] = 0;
   out_1489675256084431222[43] = 0;
   out_1489675256084431222[44] = 0;
   out_1489675256084431222[45] = 0;
   out_1489675256084431222[46] = 0;
   out_1489675256084431222[47] = 0;
   out_1489675256084431222[48] = 1;
   out_1489675256084431222[49] = 0;
   out_1489675256084431222[50] = 0;
   out_1489675256084431222[51] = 0;
   out_1489675256084431222[52] = 0;
   out_1489675256084431222[53] = 0;
   out_1489675256084431222[54] = 0;
   out_1489675256084431222[55] = 0;
   out_1489675256084431222[56] = 0;
   out_1489675256084431222[57] = 0;
   out_1489675256084431222[58] = 0;
   out_1489675256084431222[59] = 0;
   out_1489675256084431222[60] = 1;
   out_1489675256084431222[61] = 0;
   out_1489675256084431222[62] = 0;
   out_1489675256084431222[63] = 0;
   out_1489675256084431222[64] = 0;
   out_1489675256084431222[65] = 0;
   out_1489675256084431222[66] = 0;
   out_1489675256084431222[67] = 0;
   out_1489675256084431222[68] = 0;
   out_1489675256084431222[69] = 0;
   out_1489675256084431222[70] = 0;
   out_1489675256084431222[71] = 0;
   out_1489675256084431222[72] = 1;
   out_1489675256084431222[73] = dt;
   out_1489675256084431222[74] = 0;
   out_1489675256084431222[75] = 0;
   out_1489675256084431222[76] = 0;
   out_1489675256084431222[77] = 0;
   out_1489675256084431222[78] = 0;
   out_1489675256084431222[79] = 0;
   out_1489675256084431222[80] = 0;
   out_1489675256084431222[81] = 0;
   out_1489675256084431222[82] = 0;
   out_1489675256084431222[83] = 0;
   out_1489675256084431222[84] = 1;
   out_1489675256084431222[85] = dt;
   out_1489675256084431222[86] = 0;
   out_1489675256084431222[87] = 0;
   out_1489675256084431222[88] = 0;
   out_1489675256084431222[89] = 0;
   out_1489675256084431222[90] = 0;
   out_1489675256084431222[91] = 0;
   out_1489675256084431222[92] = 0;
   out_1489675256084431222[93] = 0;
   out_1489675256084431222[94] = 0;
   out_1489675256084431222[95] = 0;
   out_1489675256084431222[96] = 1;
   out_1489675256084431222[97] = 0;
   out_1489675256084431222[98] = 0;
   out_1489675256084431222[99] = 0;
   out_1489675256084431222[100] = 0;
   out_1489675256084431222[101] = 0;
   out_1489675256084431222[102] = 0;
   out_1489675256084431222[103] = 0;
   out_1489675256084431222[104] = 0;
   out_1489675256084431222[105] = 0;
   out_1489675256084431222[106] = 0;
   out_1489675256084431222[107] = 0;
   out_1489675256084431222[108] = 1;
   out_1489675256084431222[109] = 0;
   out_1489675256084431222[110] = 0;
   out_1489675256084431222[111] = 0;
   out_1489675256084431222[112] = 0;
   out_1489675256084431222[113] = 0;
   out_1489675256084431222[114] = 0;
   out_1489675256084431222[115] = 0;
   out_1489675256084431222[116] = 0;
   out_1489675256084431222[117] = 0;
   out_1489675256084431222[118] = 0;
   out_1489675256084431222[119] = 0;
   out_1489675256084431222[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_7567908033892933921) {
   out_7567908033892933921[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_7455993273502557413) {
   out_7455993273502557413[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7455993273502557413[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7455993273502557413[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7455993273502557413[3] = 0;
   out_7455993273502557413[4] = 0;
   out_7455993273502557413[5] = 0;
   out_7455993273502557413[6] = 1;
   out_7455993273502557413[7] = 0;
   out_7455993273502557413[8] = 0;
   out_7455993273502557413[9] = 0;
   out_7455993273502557413[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_3841468768416351937) {
   out_3841468768416351937[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_5623941665124898301) {
   out_5623941665124898301[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5623941665124898301[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5623941665124898301[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5623941665124898301[3] = 0;
   out_5623941665124898301[4] = 0;
   out_5623941665124898301[5] = 0;
   out_5623941665124898301[6] = 1;
   out_5623941665124898301[7] = 0;
   out_5623941665124898301[8] = 0;
   out_5623941665124898301[9] = 1;
   out_5623941665124898301[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_1211039377275791210) {
   out_1211039377275791210[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_2159917500592958723) {
   out_2159917500592958723[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[6] = 0;
   out_2159917500592958723[7] = 1;
   out_2159917500592958723[8] = 0;
   out_2159917500592958723[9] = 0;
   out_2159917500592958723[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_1211039377275791210) {
   out_1211039377275791210[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_2159917500592958723) {
   out_2159917500592958723[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_2159917500592958723[6] = 0;
   out_2159917500592958723[7] = 1;
   out_2159917500592958723[8] = 0;
   out_2159917500592958723[9] = 0;
   out_2159917500592958723[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_1734633203049768488) {
  err_fun(nom_x, delta_x, out_1734633203049768488);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_7226800202829737504) {
  inv_err_fun(nom_x, true_x, out_7226800202829737504);
}
void gnss_H_mod_fun(double *state, double *out_7212715412967761026) {
  H_mod_fun(state, out_7212715412967761026);
}
void gnss_f_fun(double *state, double dt, double *out_4622219999608348212) {
  f_fun(state,  dt, out_4622219999608348212);
}
void gnss_F_fun(double *state, double dt, double *out_1489675256084431222) {
  F_fun(state,  dt, out_1489675256084431222);
}
void gnss_h_6(double *state, double *sat_pos, double *out_7567908033892933921) {
  h_6(state, sat_pos, out_7567908033892933921);
}
void gnss_H_6(double *state, double *sat_pos, double *out_7455993273502557413) {
  H_6(state, sat_pos, out_7455993273502557413);
}
void gnss_h_20(double *state, double *sat_pos, double *out_3841468768416351937) {
  h_20(state, sat_pos, out_3841468768416351937);
}
void gnss_H_20(double *state, double *sat_pos, double *out_5623941665124898301) {
  H_20(state, sat_pos, out_5623941665124898301);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1211039377275791210) {
  h_7(state, sat_pos_vel, out_1211039377275791210);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2159917500592958723) {
  H_7(state, sat_pos_vel, out_2159917500592958723);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1211039377275791210) {
  h_21(state, sat_pos_vel, out_1211039377275791210);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2159917500592958723) {
  H_21(state, sat_pos_vel, out_2159917500592958723);
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
