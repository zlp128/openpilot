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
void err_fun(double *nom_x, double *delta_x, double *out_3985733553669045281) {
   out_3985733553669045281[0] = delta_x[0] + nom_x[0];
   out_3985733553669045281[1] = delta_x[1] + nom_x[1];
   out_3985733553669045281[2] = delta_x[2] + nom_x[2];
   out_3985733553669045281[3] = delta_x[3] + nom_x[3];
   out_3985733553669045281[4] = delta_x[4] + nom_x[4];
   out_3985733553669045281[5] = delta_x[5] + nom_x[5];
   out_3985733553669045281[6] = delta_x[6] + nom_x[6];
   out_3985733553669045281[7] = delta_x[7] + nom_x[7];
   out_3985733553669045281[8] = delta_x[8] + nom_x[8];
   out_3985733553669045281[9] = delta_x[9] + nom_x[9];
   out_3985733553669045281[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_668705734016375974) {
   out_668705734016375974[0] = -nom_x[0] + true_x[0];
   out_668705734016375974[1] = -nom_x[1] + true_x[1];
   out_668705734016375974[2] = -nom_x[2] + true_x[2];
   out_668705734016375974[3] = -nom_x[3] + true_x[3];
   out_668705734016375974[4] = -nom_x[4] + true_x[4];
   out_668705734016375974[5] = -nom_x[5] + true_x[5];
   out_668705734016375974[6] = -nom_x[6] + true_x[6];
   out_668705734016375974[7] = -nom_x[7] + true_x[7];
   out_668705734016375974[8] = -nom_x[8] + true_x[8];
   out_668705734016375974[9] = -nom_x[9] + true_x[9];
   out_668705734016375974[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_1646191520139698591) {
   out_1646191520139698591[0] = 1.0;
   out_1646191520139698591[1] = 0;
   out_1646191520139698591[2] = 0;
   out_1646191520139698591[3] = 0;
   out_1646191520139698591[4] = 0;
   out_1646191520139698591[5] = 0;
   out_1646191520139698591[6] = 0;
   out_1646191520139698591[7] = 0;
   out_1646191520139698591[8] = 0;
   out_1646191520139698591[9] = 0;
   out_1646191520139698591[10] = 0;
   out_1646191520139698591[11] = 0;
   out_1646191520139698591[12] = 1.0;
   out_1646191520139698591[13] = 0;
   out_1646191520139698591[14] = 0;
   out_1646191520139698591[15] = 0;
   out_1646191520139698591[16] = 0;
   out_1646191520139698591[17] = 0;
   out_1646191520139698591[18] = 0;
   out_1646191520139698591[19] = 0;
   out_1646191520139698591[20] = 0;
   out_1646191520139698591[21] = 0;
   out_1646191520139698591[22] = 0;
   out_1646191520139698591[23] = 0;
   out_1646191520139698591[24] = 1.0;
   out_1646191520139698591[25] = 0;
   out_1646191520139698591[26] = 0;
   out_1646191520139698591[27] = 0;
   out_1646191520139698591[28] = 0;
   out_1646191520139698591[29] = 0;
   out_1646191520139698591[30] = 0;
   out_1646191520139698591[31] = 0;
   out_1646191520139698591[32] = 0;
   out_1646191520139698591[33] = 0;
   out_1646191520139698591[34] = 0;
   out_1646191520139698591[35] = 0;
   out_1646191520139698591[36] = 1.0;
   out_1646191520139698591[37] = 0;
   out_1646191520139698591[38] = 0;
   out_1646191520139698591[39] = 0;
   out_1646191520139698591[40] = 0;
   out_1646191520139698591[41] = 0;
   out_1646191520139698591[42] = 0;
   out_1646191520139698591[43] = 0;
   out_1646191520139698591[44] = 0;
   out_1646191520139698591[45] = 0;
   out_1646191520139698591[46] = 0;
   out_1646191520139698591[47] = 0;
   out_1646191520139698591[48] = 1.0;
   out_1646191520139698591[49] = 0;
   out_1646191520139698591[50] = 0;
   out_1646191520139698591[51] = 0;
   out_1646191520139698591[52] = 0;
   out_1646191520139698591[53] = 0;
   out_1646191520139698591[54] = 0;
   out_1646191520139698591[55] = 0;
   out_1646191520139698591[56] = 0;
   out_1646191520139698591[57] = 0;
   out_1646191520139698591[58] = 0;
   out_1646191520139698591[59] = 0;
   out_1646191520139698591[60] = 1.0;
   out_1646191520139698591[61] = 0;
   out_1646191520139698591[62] = 0;
   out_1646191520139698591[63] = 0;
   out_1646191520139698591[64] = 0;
   out_1646191520139698591[65] = 0;
   out_1646191520139698591[66] = 0;
   out_1646191520139698591[67] = 0;
   out_1646191520139698591[68] = 0;
   out_1646191520139698591[69] = 0;
   out_1646191520139698591[70] = 0;
   out_1646191520139698591[71] = 0;
   out_1646191520139698591[72] = 1.0;
   out_1646191520139698591[73] = 0;
   out_1646191520139698591[74] = 0;
   out_1646191520139698591[75] = 0;
   out_1646191520139698591[76] = 0;
   out_1646191520139698591[77] = 0;
   out_1646191520139698591[78] = 0;
   out_1646191520139698591[79] = 0;
   out_1646191520139698591[80] = 0;
   out_1646191520139698591[81] = 0;
   out_1646191520139698591[82] = 0;
   out_1646191520139698591[83] = 0;
   out_1646191520139698591[84] = 1.0;
   out_1646191520139698591[85] = 0;
   out_1646191520139698591[86] = 0;
   out_1646191520139698591[87] = 0;
   out_1646191520139698591[88] = 0;
   out_1646191520139698591[89] = 0;
   out_1646191520139698591[90] = 0;
   out_1646191520139698591[91] = 0;
   out_1646191520139698591[92] = 0;
   out_1646191520139698591[93] = 0;
   out_1646191520139698591[94] = 0;
   out_1646191520139698591[95] = 0;
   out_1646191520139698591[96] = 1.0;
   out_1646191520139698591[97] = 0;
   out_1646191520139698591[98] = 0;
   out_1646191520139698591[99] = 0;
   out_1646191520139698591[100] = 0;
   out_1646191520139698591[101] = 0;
   out_1646191520139698591[102] = 0;
   out_1646191520139698591[103] = 0;
   out_1646191520139698591[104] = 0;
   out_1646191520139698591[105] = 0;
   out_1646191520139698591[106] = 0;
   out_1646191520139698591[107] = 0;
   out_1646191520139698591[108] = 1.0;
   out_1646191520139698591[109] = 0;
   out_1646191520139698591[110] = 0;
   out_1646191520139698591[111] = 0;
   out_1646191520139698591[112] = 0;
   out_1646191520139698591[113] = 0;
   out_1646191520139698591[114] = 0;
   out_1646191520139698591[115] = 0;
   out_1646191520139698591[116] = 0;
   out_1646191520139698591[117] = 0;
   out_1646191520139698591[118] = 0;
   out_1646191520139698591[119] = 0;
   out_1646191520139698591[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_8136264243716214718) {
   out_8136264243716214718[0] = dt*state[3] + state[0];
   out_8136264243716214718[1] = dt*state[4] + state[1];
   out_8136264243716214718[2] = dt*state[5] + state[2];
   out_8136264243716214718[3] = state[3];
   out_8136264243716214718[4] = state[4];
   out_8136264243716214718[5] = state[5];
   out_8136264243716214718[6] = dt*state[7] + state[6];
   out_8136264243716214718[7] = dt*state[8] + state[7];
   out_8136264243716214718[8] = state[8];
   out_8136264243716214718[9] = state[9];
   out_8136264243716214718[10] = state[10];
}
void F_fun(double *state, double dt, double *out_4236213521667949352) {
   out_4236213521667949352[0] = 1;
   out_4236213521667949352[1] = 0;
   out_4236213521667949352[2] = 0;
   out_4236213521667949352[3] = dt;
   out_4236213521667949352[4] = 0;
   out_4236213521667949352[5] = 0;
   out_4236213521667949352[6] = 0;
   out_4236213521667949352[7] = 0;
   out_4236213521667949352[8] = 0;
   out_4236213521667949352[9] = 0;
   out_4236213521667949352[10] = 0;
   out_4236213521667949352[11] = 0;
   out_4236213521667949352[12] = 1;
   out_4236213521667949352[13] = 0;
   out_4236213521667949352[14] = 0;
   out_4236213521667949352[15] = dt;
   out_4236213521667949352[16] = 0;
   out_4236213521667949352[17] = 0;
   out_4236213521667949352[18] = 0;
   out_4236213521667949352[19] = 0;
   out_4236213521667949352[20] = 0;
   out_4236213521667949352[21] = 0;
   out_4236213521667949352[22] = 0;
   out_4236213521667949352[23] = 0;
   out_4236213521667949352[24] = 1;
   out_4236213521667949352[25] = 0;
   out_4236213521667949352[26] = 0;
   out_4236213521667949352[27] = dt;
   out_4236213521667949352[28] = 0;
   out_4236213521667949352[29] = 0;
   out_4236213521667949352[30] = 0;
   out_4236213521667949352[31] = 0;
   out_4236213521667949352[32] = 0;
   out_4236213521667949352[33] = 0;
   out_4236213521667949352[34] = 0;
   out_4236213521667949352[35] = 0;
   out_4236213521667949352[36] = 1;
   out_4236213521667949352[37] = 0;
   out_4236213521667949352[38] = 0;
   out_4236213521667949352[39] = 0;
   out_4236213521667949352[40] = 0;
   out_4236213521667949352[41] = 0;
   out_4236213521667949352[42] = 0;
   out_4236213521667949352[43] = 0;
   out_4236213521667949352[44] = 0;
   out_4236213521667949352[45] = 0;
   out_4236213521667949352[46] = 0;
   out_4236213521667949352[47] = 0;
   out_4236213521667949352[48] = 1;
   out_4236213521667949352[49] = 0;
   out_4236213521667949352[50] = 0;
   out_4236213521667949352[51] = 0;
   out_4236213521667949352[52] = 0;
   out_4236213521667949352[53] = 0;
   out_4236213521667949352[54] = 0;
   out_4236213521667949352[55] = 0;
   out_4236213521667949352[56] = 0;
   out_4236213521667949352[57] = 0;
   out_4236213521667949352[58] = 0;
   out_4236213521667949352[59] = 0;
   out_4236213521667949352[60] = 1;
   out_4236213521667949352[61] = 0;
   out_4236213521667949352[62] = 0;
   out_4236213521667949352[63] = 0;
   out_4236213521667949352[64] = 0;
   out_4236213521667949352[65] = 0;
   out_4236213521667949352[66] = 0;
   out_4236213521667949352[67] = 0;
   out_4236213521667949352[68] = 0;
   out_4236213521667949352[69] = 0;
   out_4236213521667949352[70] = 0;
   out_4236213521667949352[71] = 0;
   out_4236213521667949352[72] = 1;
   out_4236213521667949352[73] = dt;
   out_4236213521667949352[74] = 0;
   out_4236213521667949352[75] = 0;
   out_4236213521667949352[76] = 0;
   out_4236213521667949352[77] = 0;
   out_4236213521667949352[78] = 0;
   out_4236213521667949352[79] = 0;
   out_4236213521667949352[80] = 0;
   out_4236213521667949352[81] = 0;
   out_4236213521667949352[82] = 0;
   out_4236213521667949352[83] = 0;
   out_4236213521667949352[84] = 1;
   out_4236213521667949352[85] = dt;
   out_4236213521667949352[86] = 0;
   out_4236213521667949352[87] = 0;
   out_4236213521667949352[88] = 0;
   out_4236213521667949352[89] = 0;
   out_4236213521667949352[90] = 0;
   out_4236213521667949352[91] = 0;
   out_4236213521667949352[92] = 0;
   out_4236213521667949352[93] = 0;
   out_4236213521667949352[94] = 0;
   out_4236213521667949352[95] = 0;
   out_4236213521667949352[96] = 1;
   out_4236213521667949352[97] = 0;
   out_4236213521667949352[98] = 0;
   out_4236213521667949352[99] = 0;
   out_4236213521667949352[100] = 0;
   out_4236213521667949352[101] = 0;
   out_4236213521667949352[102] = 0;
   out_4236213521667949352[103] = 0;
   out_4236213521667949352[104] = 0;
   out_4236213521667949352[105] = 0;
   out_4236213521667949352[106] = 0;
   out_4236213521667949352[107] = 0;
   out_4236213521667949352[108] = 1;
   out_4236213521667949352[109] = 0;
   out_4236213521667949352[110] = 0;
   out_4236213521667949352[111] = 0;
   out_4236213521667949352[112] = 0;
   out_4236213521667949352[113] = 0;
   out_4236213521667949352[114] = 0;
   out_4236213521667949352[115] = 0;
   out_4236213521667949352[116] = 0;
   out_4236213521667949352[117] = 0;
   out_4236213521667949352[118] = 0;
   out_4236213521667949352[119] = 0;
   out_4236213521667949352[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_8352111296884602789) {
   out_8352111296884602789[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_2202359500111385714) {
   out_2202359500111385714[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2202359500111385714[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2202359500111385714[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2202359500111385714[3] = 0;
   out_2202359500111385714[4] = 0;
   out_2202359500111385714[5] = 0;
   out_2202359500111385714[6] = 1;
   out_2202359500111385714[7] = 0;
   out_2202359500111385714[8] = 0;
   out_2202359500111385714[9] = 0;
   out_2202359500111385714[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_4887672178428492502) {
   out_4887672178428492502[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_4961949425089895635) {
   out_4961949425089895635[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4961949425089895635[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4961949425089895635[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4961949425089895635[3] = 0;
   out_4961949425089895635[4] = 0;
   out_4961949425089895635[5] = 0;
   out_4961949425089895635[6] = 1;
   out_4961949425089895635[7] = 0;
   out_4961949425089895635[8] = 0;
   out_4961949425089895635[9] = 1;
   out_4961949425089895635[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_191603051630805475) {
   out_191603051630805475[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_7197851591855342328) {
   out_7197851591855342328[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[6] = 0;
   out_7197851591855342328[7] = 1;
   out_7197851591855342328[8] = 0;
   out_7197851591855342328[9] = 0;
   out_7197851591855342328[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_191603051630805475) {
   out_191603051630805475[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_7197851591855342328) {
   out_7197851591855342328[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7197851591855342328[6] = 0;
   out_7197851591855342328[7] = 1;
   out_7197851591855342328[8] = 0;
   out_7197851591855342328[9] = 0;
   out_7197851591855342328[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3985733553669045281) {
  err_fun(nom_x, delta_x, out_3985733553669045281);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_668705734016375974) {
  inv_err_fun(nom_x, true_x, out_668705734016375974);
}
void gnss_H_mod_fun(double *state, double *out_1646191520139698591) {
  H_mod_fun(state, out_1646191520139698591);
}
void gnss_f_fun(double *state, double dt, double *out_8136264243716214718) {
  f_fun(state,  dt, out_8136264243716214718);
}
void gnss_F_fun(double *state, double dt, double *out_4236213521667949352) {
  F_fun(state,  dt, out_4236213521667949352);
}
void gnss_h_6(double *state, double *sat_pos, double *out_8352111296884602789) {
  h_6(state, sat_pos, out_8352111296884602789);
}
void gnss_H_6(double *state, double *sat_pos, double *out_2202359500111385714) {
  H_6(state, sat_pos, out_2202359500111385714);
}
void gnss_h_20(double *state, double *sat_pos, double *out_4887672178428492502) {
  h_20(state, sat_pos, out_4887672178428492502);
}
void gnss_H_20(double *state, double *sat_pos, double *out_4961949425089895635) {
  H_20(state, sat_pos, out_4961949425089895635);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_191603051630805475) {
  h_7(state, sat_pos_vel, out_191603051630805475);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7197851591855342328) {
  H_7(state, sat_pos_vel, out_7197851591855342328);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_191603051630805475) {
  h_21(state, sat_pos_vel, out_191603051630805475);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7197851591855342328) {
  H_21(state, sat_pos_vel, out_7197851591855342328);
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
