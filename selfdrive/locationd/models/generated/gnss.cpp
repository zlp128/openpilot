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
void err_fun(double *nom_x, double *delta_x, double *out_4640013062227700412) {
   out_4640013062227700412[0] = delta_x[0] + nom_x[0];
   out_4640013062227700412[1] = delta_x[1] + nom_x[1];
   out_4640013062227700412[2] = delta_x[2] + nom_x[2];
   out_4640013062227700412[3] = delta_x[3] + nom_x[3];
   out_4640013062227700412[4] = delta_x[4] + nom_x[4];
   out_4640013062227700412[5] = delta_x[5] + nom_x[5];
   out_4640013062227700412[6] = delta_x[6] + nom_x[6];
   out_4640013062227700412[7] = delta_x[7] + nom_x[7];
   out_4640013062227700412[8] = delta_x[8] + nom_x[8];
   out_4640013062227700412[9] = delta_x[9] + nom_x[9];
   out_4640013062227700412[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4915148707996812550) {
   out_4915148707996812550[0] = -nom_x[0] + true_x[0];
   out_4915148707996812550[1] = -nom_x[1] + true_x[1];
   out_4915148707996812550[2] = -nom_x[2] + true_x[2];
   out_4915148707996812550[3] = -nom_x[3] + true_x[3];
   out_4915148707996812550[4] = -nom_x[4] + true_x[4];
   out_4915148707996812550[5] = -nom_x[5] + true_x[5];
   out_4915148707996812550[6] = -nom_x[6] + true_x[6];
   out_4915148707996812550[7] = -nom_x[7] + true_x[7];
   out_4915148707996812550[8] = -nom_x[8] + true_x[8];
   out_4915148707996812550[9] = -nom_x[9] + true_x[9];
   out_4915148707996812550[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_8574237875034322764) {
   out_8574237875034322764[0] = 1.0;
   out_8574237875034322764[1] = 0;
   out_8574237875034322764[2] = 0;
   out_8574237875034322764[3] = 0;
   out_8574237875034322764[4] = 0;
   out_8574237875034322764[5] = 0;
   out_8574237875034322764[6] = 0;
   out_8574237875034322764[7] = 0;
   out_8574237875034322764[8] = 0;
   out_8574237875034322764[9] = 0;
   out_8574237875034322764[10] = 0;
   out_8574237875034322764[11] = 0;
   out_8574237875034322764[12] = 1.0;
   out_8574237875034322764[13] = 0;
   out_8574237875034322764[14] = 0;
   out_8574237875034322764[15] = 0;
   out_8574237875034322764[16] = 0;
   out_8574237875034322764[17] = 0;
   out_8574237875034322764[18] = 0;
   out_8574237875034322764[19] = 0;
   out_8574237875034322764[20] = 0;
   out_8574237875034322764[21] = 0;
   out_8574237875034322764[22] = 0;
   out_8574237875034322764[23] = 0;
   out_8574237875034322764[24] = 1.0;
   out_8574237875034322764[25] = 0;
   out_8574237875034322764[26] = 0;
   out_8574237875034322764[27] = 0;
   out_8574237875034322764[28] = 0;
   out_8574237875034322764[29] = 0;
   out_8574237875034322764[30] = 0;
   out_8574237875034322764[31] = 0;
   out_8574237875034322764[32] = 0;
   out_8574237875034322764[33] = 0;
   out_8574237875034322764[34] = 0;
   out_8574237875034322764[35] = 0;
   out_8574237875034322764[36] = 1.0;
   out_8574237875034322764[37] = 0;
   out_8574237875034322764[38] = 0;
   out_8574237875034322764[39] = 0;
   out_8574237875034322764[40] = 0;
   out_8574237875034322764[41] = 0;
   out_8574237875034322764[42] = 0;
   out_8574237875034322764[43] = 0;
   out_8574237875034322764[44] = 0;
   out_8574237875034322764[45] = 0;
   out_8574237875034322764[46] = 0;
   out_8574237875034322764[47] = 0;
   out_8574237875034322764[48] = 1.0;
   out_8574237875034322764[49] = 0;
   out_8574237875034322764[50] = 0;
   out_8574237875034322764[51] = 0;
   out_8574237875034322764[52] = 0;
   out_8574237875034322764[53] = 0;
   out_8574237875034322764[54] = 0;
   out_8574237875034322764[55] = 0;
   out_8574237875034322764[56] = 0;
   out_8574237875034322764[57] = 0;
   out_8574237875034322764[58] = 0;
   out_8574237875034322764[59] = 0;
   out_8574237875034322764[60] = 1.0;
   out_8574237875034322764[61] = 0;
   out_8574237875034322764[62] = 0;
   out_8574237875034322764[63] = 0;
   out_8574237875034322764[64] = 0;
   out_8574237875034322764[65] = 0;
   out_8574237875034322764[66] = 0;
   out_8574237875034322764[67] = 0;
   out_8574237875034322764[68] = 0;
   out_8574237875034322764[69] = 0;
   out_8574237875034322764[70] = 0;
   out_8574237875034322764[71] = 0;
   out_8574237875034322764[72] = 1.0;
   out_8574237875034322764[73] = 0;
   out_8574237875034322764[74] = 0;
   out_8574237875034322764[75] = 0;
   out_8574237875034322764[76] = 0;
   out_8574237875034322764[77] = 0;
   out_8574237875034322764[78] = 0;
   out_8574237875034322764[79] = 0;
   out_8574237875034322764[80] = 0;
   out_8574237875034322764[81] = 0;
   out_8574237875034322764[82] = 0;
   out_8574237875034322764[83] = 0;
   out_8574237875034322764[84] = 1.0;
   out_8574237875034322764[85] = 0;
   out_8574237875034322764[86] = 0;
   out_8574237875034322764[87] = 0;
   out_8574237875034322764[88] = 0;
   out_8574237875034322764[89] = 0;
   out_8574237875034322764[90] = 0;
   out_8574237875034322764[91] = 0;
   out_8574237875034322764[92] = 0;
   out_8574237875034322764[93] = 0;
   out_8574237875034322764[94] = 0;
   out_8574237875034322764[95] = 0;
   out_8574237875034322764[96] = 1.0;
   out_8574237875034322764[97] = 0;
   out_8574237875034322764[98] = 0;
   out_8574237875034322764[99] = 0;
   out_8574237875034322764[100] = 0;
   out_8574237875034322764[101] = 0;
   out_8574237875034322764[102] = 0;
   out_8574237875034322764[103] = 0;
   out_8574237875034322764[104] = 0;
   out_8574237875034322764[105] = 0;
   out_8574237875034322764[106] = 0;
   out_8574237875034322764[107] = 0;
   out_8574237875034322764[108] = 1.0;
   out_8574237875034322764[109] = 0;
   out_8574237875034322764[110] = 0;
   out_8574237875034322764[111] = 0;
   out_8574237875034322764[112] = 0;
   out_8574237875034322764[113] = 0;
   out_8574237875034322764[114] = 0;
   out_8574237875034322764[115] = 0;
   out_8574237875034322764[116] = 0;
   out_8574237875034322764[117] = 0;
   out_8574237875034322764[118] = 0;
   out_8574237875034322764[119] = 0;
   out_8574237875034322764[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_5636831905979297775) {
   out_5636831905979297775[0] = dt*state[3] + state[0];
   out_5636831905979297775[1] = dt*state[4] + state[1];
   out_5636831905979297775[2] = dt*state[5] + state[2];
   out_5636831905979297775[3] = state[3];
   out_5636831905979297775[4] = state[4];
   out_5636831905979297775[5] = state[5];
   out_5636831905979297775[6] = dt*state[7] + state[6];
   out_5636831905979297775[7] = dt*state[8] + state[7];
   out_5636831905979297775[8] = state[8];
   out_5636831905979297775[9] = state[9];
   out_5636831905979297775[10] = state[10];
}
void F_fun(double *state, double dt, double *out_2727942986966876467) {
   out_2727942986966876467[0] = 1;
   out_2727942986966876467[1] = 0;
   out_2727942986966876467[2] = 0;
   out_2727942986966876467[3] = dt;
   out_2727942986966876467[4] = 0;
   out_2727942986966876467[5] = 0;
   out_2727942986966876467[6] = 0;
   out_2727942986966876467[7] = 0;
   out_2727942986966876467[8] = 0;
   out_2727942986966876467[9] = 0;
   out_2727942986966876467[10] = 0;
   out_2727942986966876467[11] = 0;
   out_2727942986966876467[12] = 1;
   out_2727942986966876467[13] = 0;
   out_2727942986966876467[14] = 0;
   out_2727942986966876467[15] = dt;
   out_2727942986966876467[16] = 0;
   out_2727942986966876467[17] = 0;
   out_2727942986966876467[18] = 0;
   out_2727942986966876467[19] = 0;
   out_2727942986966876467[20] = 0;
   out_2727942986966876467[21] = 0;
   out_2727942986966876467[22] = 0;
   out_2727942986966876467[23] = 0;
   out_2727942986966876467[24] = 1;
   out_2727942986966876467[25] = 0;
   out_2727942986966876467[26] = 0;
   out_2727942986966876467[27] = dt;
   out_2727942986966876467[28] = 0;
   out_2727942986966876467[29] = 0;
   out_2727942986966876467[30] = 0;
   out_2727942986966876467[31] = 0;
   out_2727942986966876467[32] = 0;
   out_2727942986966876467[33] = 0;
   out_2727942986966876467[34] = 0;
   out_2727942986966876467[35] = 0;
   out_2727942986966876467[36] = 1;
   out_2727942986966876467[37] = 0;
   out_2727942986966876467[38] = 0;
   out_2727942986966876467[39] = 0;
   out_2727942986966876467[40] = 0;
   out_2727942986966876467[41] = 0;
   out_2727942986966876467[42] = 0;
   out_2727942986966876467[43] = 0;
   out_2727942986966876467[44] = 0;
   out_2727942986966876467[45] = 0;
   out_2727942986966876467[46] = 0;
   out_2727942986966876467[47] = 0;
   out_2727942986966876467[48] = 1;
   out_2727942986966876467[49] = 0;
   out_2727942986966876467[50] = 0;
   out_2727942986966876467[51] = 0;
   out_2727942986966876467[52] = 0;
   out_2727942986966876467[53] = 0;
   out_2727942986966876467[54] = 0;
   out_2727942986966876467[55] = 0;
   out_2727942986966876467[56] = 0;
   out_2727942986966876467[57] = 0;
   out_2727942986966876467[58] = 0;
   out_2727942986966876467[59] = 0;
   out_2727942986966876467[60] = 1;
   out_2727942986966876467[61] = 0;
   out_2727942986966876467[62] = 0;
   out_2727942986966876467[63] = 0;
   out_2727942986966876467[64] = 0;
   out_2727942986966876467[65] = 0;
   out_2727942986966876467[66] = 0;
   out_2727942986966876467[67] = 0;
   out_2727942986966876467[68] = 0;
   out_2727942986966876467[69] = 0;
   out_2727942986966876467[70] = 0;
   out_2727942986966876467[71] = 0;
   out_2727942986966876467[72] = 1;
   out_2727942986966876467[73] = dt;
   out_2727942986966876467[74] = 0;
   out_2727942986966876467[75] = 0;
   out_2727942986966876467[76] = 0;
   out_2727942986966876467[77] = 0;
   out_2727942986966876467[78] = 0;
   out_2727942986966876467[79] = 0;
   out_2727942986966876467[80] = 0;
   out_2727942986966876467[81] = 0;
   out_2727942986966876467[82] = 0;
   out_2727942986966876467[83] = 0;
   out_2727942986966876467[84] = 1;
   out_2727942986966876467[85] = dt;
   out_2727942986966876467[86] = 0;
   out_2727942986966876467[87] = 0;
   out_2727942986966876467[88] = 0;
   out_2727942986966876467[89] = 0;
   out_2727942986966876467[90] = 0;
   out_2727942986966876467[91] = 0;
   out_2727942986966876467[92] = 0;
   out_2727942986966876467[93] = 0;
   out_2727942986966876467[94] = 0;
   out_2727942986966876467[95] = 0;
   out_2727942986966876467[96] = 1;
   out_2727942986966876467[97] = 0;
   out_2727942986966876467[98] = 0;
   out_2727942986966876467[99] = 0;
   out_2727942986966876467[100] = 0;
   out_2727942986966876467[101] = 0;
   out_2727942986966876467[102] = 0;
   out_2727942986966876467[103] = 0;
   out_2727942986966876467[104] = 0;
   out_2727942986966876467[105] = 0;
   out_2727942986966876467[106] = 0;
   out_2727942986966876467[107] = 0;
   out_2727942986966876467[108] = 1;
   out_2727942986966876467[109] = 0;
   out_2727942986966876467[110] = 0;
   out_2727942986966876467[111] = 0;
   out_2727942986966876467[112] = 0;
   out_2727942986966876467[113] = 0;
   out_2727942986966876467[114] = 0;
   out_2727942986966876467[115] = 0;
   out_2727942986966876467[116] = 0;
   out_2727942986966876467[117] = 0;
   out_2727942986966876467[118] = 0;
   out_2727942986966876467[119] = 0;
   out_2727942986966876467[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_4554215930920042575) {
   out_4554215930920042575[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_895428558576169950) {
   out_895428558576169950[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_895428558576169950[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_895428558576169950[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_895428558576169950[3] = 0;
   out_895428558576169950[4] = 0;
   out_895428558576169950[5] = 0;
   out_895428558576169950[6] = 1;
   out_895428558576169950[7] = 0;
   out_895428558576169950[8] = 0;
   out_895428558576169950[9] = 0;
   out_895428558576169950[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_6704926246356191984) {
   out_6704926246356191984[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_3575717658219428128) {
   out_3575717658219428128[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3575717658219428128[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3575717658219428128[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3575717658219428128[3] = 0;
   out_3575717658219428128[4] = 0;
   out_3575717658219428128[5] = 0;
   out_3575717658219428128[6] = 1;
   out_3575717658219428128[7] = 0;
   out_3575717658219428128[8] = 0;
   out_3575717658219428128[9] = 1;
   out_3575717658219428128[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_6430340606903371855) {
   out_6430340606903371855[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_4789129994195662485) {
   out_4789129994195662485[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[6] = 0;
   out_4789129994195662485[7] = 1;
   out_4789129994195662485[8] = 0;
   out_4789129994195662485[9] = 0;
   out_4789129994195662485[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_6430340606903371855) {
   out_6430340606903371855[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_4789129994195662485) {
   out_4789129994195662485[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4789129994195662485[6] = 0;
   out_4789129994195662485[7] = 1;
   out_4789129994195662485[8] = 0;
   out_4789129994195662485[9] = 0;
   out_4789129994195662485[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4640013062227700412) {
  err_fun(nom_x, delta_x, out_4640013062227700412);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_4915148707996812550) {
  inv_err_fun(nom_x, true_x, out_4915148707996812550);
}
void gnss_H_mod_fun(double *state, double *out_8574237875034322764) {
  H_mod_fun(state, out_8574237875034322764);
}
void gnss_f_fun(double *state, double dt, double *out_5636831905979297775) {
  f_fun(state,  dt, out_5636831905979297775);
}
void gnss_F_fun(double *state, double dt, double *out_2727942986966876467) {
  F_fun(state,  dt, out_2727942986966876467);
}
void gnss_h_6(double *state, double *sat_pos, double *out_4554215930920042575) {
  h_6(state, sat_pos, out_4554215930920042575);
}
void gnss_H_6(double *state, double *sat_pos, double *out_895428558576169950) {
  H_6(state, sat_pos, out_895428558576169950);
}
void gnss_h_20(double *state, double *sat_pos, double *out_6704926246356191984) {
  h_20(state, sat_pos, out_6704926246356191984);
}
void gnss_H_20(double *state, double *sat_pos, double *out_3575717658219428128) {
  H_20(state, sat_pos, out_3575717658219428128);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6430340606903371855) {
  h_7(state, sat_pos_vel, out_6430340606903371855);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_4789129994195662485) {
  H_7(state, sat_pos_vel, out_4789129994195662485);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6430340606903371855) {
  h_21(state, sat_pos_vel, out_6430340606903371855);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_4789129994195662485) {
  H_21(state, sat_pos_vel, out_4789129994195662485);
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
