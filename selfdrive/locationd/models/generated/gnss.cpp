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
void err_fun(double *nom_x, double *delta_x, double *out_654910612427940843) {
   out_654910612427940843[0] = delta_x[0] + nom_x[0];
   out_654910612427940843[1] = delta_x[1] + nom_x[1];
   out_654910612427940843[2] = delta_x[2] + nom_x[2];
   out_654910612427940843[3] = delta_x[3] + nom_x[3];
   out_654910612427940843[4] = delta_x[4] + nom_x[4];
   out_654910612427940843[5] = delta_x[5] + nom_x[5];
   out_654910612427940843[6] = delta_x[6] + nom_x[6];
   out_654910612427940843[7] = delta_x[7] + nom_x[7];
   out_654910612427940843[8] = delta_x[8] + nom_x[8];
   out_654910612427940843[9] = delta_x[9] + nom_x[9];
   out_654910612427940843[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6637724801134549563) {
   out_6637724801134549563[0] = -nom_x[0] + true_x[0];
   out_6637724801134549563[1] = -nom_x[1] + true_x[1];
   out_6637724801134549563[2] = -nom_x[2] + true_x[2];
   out_6637724801134549563[3] = -nom_x[3] + true_x[3];
   out_6637724801134549563[4] = -nom_x[4] + true_x[4];
   out_6637724801134549563[5] = -nom_x[5] + true_x[5];
   out_6637724801134549563[6] = -nom_x[6] + true_x[6];
   out_6637724801134549563[7] = -nom_x[7] + true_x[7];
   out_6637724801134549563[8] = -nom_x[8] + true_x[8];
   out_6637724801134549563[9] = -nom_x[9] + true_x[9];
   out_6637724801134549563[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_805386010827368873) {
   out_805386010827368873[0] = 1.0;
   out_805386010827368873[1] = 0;
   out_805386010827368873[2] = 0;
   out_805386010827368873[3] = 0;
   out_805386010827368873[4] = 0;
   out_805386010827368873[5] = 0;
   out_805386010827368873[6] = 0;
   out_805386010827368873[7] = 0;
   out_805386010827368873[8] = 0;
   out_805386010827368873[9] = 0;
   out_805386010827368873[10] = 0;
   out_805386010827368873[11] = 0;
   out_805386010827368873[12] = 1.0;
   out_805386010827368873[13] = 0;
   out_805386010827368873[14] = 0;
   out_805386010827368873[15] = 0;
   out_805386010827368873[16] = 0;
   out_805386010827368873[17] = 0;
   out_805386010827368873[18] = 0;
   out_805386010827368873[19] = 0;
   out_805386010827368873[20] = 0;
   out_805386010827368873[21] = 0;
   out_805386010827368873[22] = 0;
   out_805386010827368873[23] = 0;
   out_805386010827368873[24] = 1.0;
   out_805386010827368873[25] = 0;
   out_805386010827368873[26] = 0;
   out_805386010827368873[27] = 0;
   out_805386010827368873[28] = 0;
   out_805386010827368873[29] = 0;
   out_805386010827368873[30] = 0;
   out_805386010827368873[31] = 0;
   out_805386010827368873[32] = 0;
   out_805386010827368873[33] = 0;
   out_805386010827368873[34] = 0;
   out_805386010827368873[35] = 0;
   out_805386010827368873[36] = 1.0;
   out_805386010827368873[37] = 0;
   out_805386010827368873[38] = 0;
   out_805386010827368873[39] = 0;
   out_805386010827368873[40] = 0;
   out_805386010827368873[41] = 0;
   out_805386010827368873[42] = 0;
   out_805386010827368873[43] = 0;
   out_805386010827368873[44] = 0;
   out_805386010827368873[45] = 0;
   out_805386010827368873[46] = 0;
   out_805386010827368873[47] = 0;
   out_805386010827368873[48] = 1.0;
   out_805386010827368873[49] = 0;
   out_805386010827368873[50] = 0;
   out_805386010827368873[51] = 0;
   out_805386010827368873[52] = 0;
   out_805386010827368873[53] = 0;
   out_805386010827368873[54] = 0;
   out_805386010827368873[55] = 0;
   out_805386010827368873[56] = 0;
   out_805386010827368873[57] = 0;
   out_805386010827368873[58] = 0;
   out_805386010827368873[59] = 0;
   out_805386010827368873[60] = 1.0;
   out_805386010827368873[61] = 0;
   out_805386010827368873[62] = 0;
   out_805386010827368873[63] = 0;
   out_805386010827368873[64] = 0;
   out_805386010827368873[65] = 0;
   out_805386010827368873[66] = 0;
   out_805386010827368873[67] = 0;
   out_805386010827368873[68] = 0;
   out_805386010827368873[69] = 0;
   out_805386010827368873[70] = 0;
   out_805386010827368873[71] = 0;
   out_805386010827368873[72] = 1.0;
   out_805386010827368873[73] = 0;
   out_805386010827368873[74] = 0;
   out_805386010827368873[75] = 0;
   out_805386010827368873[76] = 0;
   out_805386010827368873[77] = 0;
   out_805386010827368873[78] = 0;
   out_805386010827368873[79] = 0;
   out_805386010827368873[80] = 0;
   out_805386010827368873[81] = 0;
   out_805386010827368873[82] = 0;
   out_805386010827368873[83] = 0;
   out_805386010827368873[84] = 1.0;
   out_805386010827368873[85] = 0;
   out_805386010827368873[86] = 0;
   out_805386010827368873[87] = 0;
   out_805386010827368873[88] = 0;
   out_805386010827368873[89] = 0;
   out_805386010827368873[90] = 0;
   out_805386010827368873[91] = 0;
   out_805386010827368873[92] = 0;
   out_805386010827368873[93] = 0;
   out_805386010827368873[94] = 0;
   out_805386010827368873[95] = 0;
   out_805386010827368873[96] = 1.0;
   out_805386010827368873[97] = 0;
   out_805386010827368873[98] = 0;
   out_805386010827368873[99] = 0;
   out_805386010827368873[100] = 0;
   out_805386010827368873[101] = 0;
   out_805386010827368873[102] = 0;
   out_805386010827368873[103] = 0;
   out_805386010827368873[104] = 0;
   out_805386010827368873[105] = 0;
   out_805386010827368873[106] = 0;
   out_805386010827368873[107] = 0;
   out_805386010827368873[108] = 1.0;
   out_805386010827368873[109] = 0;
   out_805386010827368873[110] = 0;
   out_805386010827368873[111] = 0;
   out_805386010827368873[112] = 0;
   out_805386010827368873[113] = 0;
   out_805386010827368873[114] = 0;
   out_805386010827368873[115] = 0;
   out_805386010827368873[116] = 0;
   out_805386010827368873[117] = 0;
   out_805386010827368873[118] = 0;
   out_805386010827368873[119] = 0;
   out_805386010827368873[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_4766656596405504851) {
   out_4766656596405504851[0] = dt*state[3] + state[0];
   out_4766656596405504851[1] = dt*state[4] + state[1];
   out_4766656596405504851[2] = dt*state[5] + state[2];
   out_4766656596405504851[3] = state[3];
   out_4766656596405504851[4] = state[4];
   out_4766656596405504851[5] = state[5];
   out_4766656596405504851[6] = dt*state[7] + state[6];
   out_4766656596405504851[7] = dt*state[8] + state[7];
   out_4766656596405504851[8] = state[8];
   out_4766656596405504851[9] = state[9];
   out_4766656596405504851[10] = state[10];
}
void F_fun(double *state, double dt, double *out_4029299056587768608) {
   out_4029299056587768608[0] = 1;
   out_4029299056587768608[1] = 0;
   out_4029299056587768608[2] = 0;
   out_4029299056587768608[3] = dt;
   out_4029299056587768608[4] = 0;
   out_4029299056587768608[5] = 0;
   out_4029299056587768608[6] = 0;
   out_4029299056587768608[7] = 0;
   out_4029299056587768608[8] = 0;
   out_4029299056587768608[9] = 0;
   out_4029299056587768608[10] = 0;
   out_4029299056587768608[11] = 0;
   out_4029299056587768608[12] = 1;
   out_4029299056587768608[13] = 0;
   out_4029299056587768608[14] = 0;
   out_4029299056587768608[15] = dt;
   out_4029299056587768608[16] = 0;
   out_4029299056587768608[17] = 0;
   out_4029299056587768608[18] = 0;
   out_4029299056587768608[19] = 0;
   out_4029299056587768608[20] = 0;
   out_4029299056587768608[21] = 0;
   out_4029299056587768608[22] = 0;
   out_4029299056587768608[23] = 0;
   out_4029299056587768608[24] = 1;
   out_4029299056587768608[25] = 0;
   out_4029299056587768608[26] = 0;
   out_4029299056587768608[27] = dt;
   out_4029299056587768608[28] = 0;
   out_4029299056587768608[29] = 0;
   out_4029299056587768608[30] = 0;
   out_4029299056587768608[31] = 0;
   out_4029299056587768608[32] = 0;
   out_4029299056587768608[33] = 0;
   out_4029299056587768608[34] = 0;
   out_4029299056587768608[35] = 0;
   out_4029299056587768608[36] = 1;
   out_4029299056587768608[37] = 0;
   out_4029299056587768608[38] = 0;
   out_4029299056587768608[39] = 0;
   out_4029299056587768608[40] = 0;
   out_4029299056587768608[41] = 0;
   out_4029299056587768608[42] = 0;
   out_4029299056587768608[43] = 0;
   out_4029299056587768608[44] = 0;
   out_4029299056587768608[45] = 0;
   out_4029299056587768608[46] = 0;
   out_4029299056587768608[47] = 0;
   out_4029299056587768608[48] = 1;
   out_4029299056587768608[49] = 0;
   out_4029299056587768608[50] = 0;
   out_4029299056587768608[51] = 0;
   out_4029299056587768608[52] = 0;
   out_4029299056587768608[53] = 0;
   out_4029299056587768608[54] = 0;
   out_4029299056587768608[55] = 0;
   out_4029299056587768608[56] = 0;
   out_4029299056587768608[57] = 0;
   out_4029299056587768608[58] = 0;
   out_4029299056587768608[59] = 0;
   out_4029299056587768608[60] = 1;
   out_4029299056587768608[61] = 0;
   out_4029299056587768608[62] = 0;
   out_4029299056587768608[63] = 0;
   out_4029299056587768608[64] = 0;
   out_4029299056587768608[65] = 0;
   out_4029299056587768608[66] = 0;
   out_4029299056587768608[67] = 0;
   out_4029299056587768608[68] = 0;
   out_4029299056587768608[69] = 0;
   out_4029299056587768608[70] = 0;
   out_4029299056587768608[71] = 0;
   out_4029299056587768608[72] = 1;
   out_4029299056587768608[73] = dt;
   out_4029299056587768608[74] = 0;
   out_4029299056587768608[75] = 0;
   out_4029299056587768608[76] = 0;
   out_4029299056587768608[77] = 0;
   out_4029299056587768608[78] = 0;
   out_4029299056587768608[79] = 0;
   out_4029299056587768608[80] = 0;
   out_4029299056587768608[81] = 0;
   out_4029299056587768608[82] = 0;
   out_4029299056587768608[83] = 0;
   out_4029299056587768608[84] = 1;
   out_4029299056587768608[85] = dt;
   out_4029299056587768608[86] = 0;
   out_4029299056587768608[87] = 0;
   out_4029299056587768608[88] = 0;
   out_4029299056587768608[89] = 0;
   out_4029299056587768608[90] = 0;
   out_4029299056587768608[91] = 0;
   out_4029299056587768608[92] = 0;
   out_4029299056587768608[93] = 0;
   out_4029299056587768608[94] = 0;
   out_4029299056587768608[95] = 0;
   out_4029299056587768608[96] = 1;
   out_4029299056587768608[97] = 0;
   out_4029299056587768608[98] = 0;
   out_4029299056587768608[99] = 0;
   out_4029299056587768608[100] = 0;
   out_4029299056587768608[101] = 0;
   out_4029299056587768608[102] = 0;
   out_4029299056587768608[103] = 0;
   out_4029299056587768608[104] = 0;
   out_4029299056587768608[105] = 0;
   out_4029299056587768608[106] = 0;
   out_4029299056587768608[107] = 0;
   out_4029299056587768608[108] = 1;
   out_4029299056587768608[109] = 0;
   out_4029299056587768608[110] = 0;
   out_4029299056587768608[111] = 0;
   out_4029299056587768608[112] = 0;
   out_4029299056587768608[113] = 0;
   out_4029299056587768608[114] = 0;
   out_4029299056587768608[115] = 0;
   out_4029299056587768608[116] = 0;
   out_4029299056587768608[117] = 0;
   out_4029299056587768608[118] = 0;
   out_4029299056587768608[119] = 0;
   out_4029299056587768608[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_1067178731754715050) {
   out_1067178731754715050[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_7962220724729872721) {
   out_7962220724729872721[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7962220724729872721[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7962220724729872721[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7962220724729872721[3] = 0;
   out_7962220724729872721[4] = 0;
   out_7962220724729872721[5] = 0;
   out_7962220724729872721[6] = 1;
   out_7962220724729872721[7] = 0;
   out_7962220724729872721[8] = 0;
   out_7962220724729872721[9] = 0;
   out_7962220724729872721[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_7444431052127272697) {
   out_7444431052127272697[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_799492558915393744) {
   out_799492558915393744[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_799492558915393744[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_799492558915393744[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_799492558915393744[3] = 0;
   out_799492558915393744[4] = 0;
   out_799492558915393744[5] = 0;
   out_799492558915393744[6] = 1;
   out_799492558915393744[7] = 0;
   out_799492558915393744[8] = 0;
   out_799492558915393744[9] = 1;
   out_799492558915393744[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_7430002568771021643) {
   out_7430002568771021643[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_7060224876276749950) {
   out_7060224876276749950[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[6] = 0;
   out_7060224876276749950[7] = 1;
   out_7060224876276749950[8] = 0;
   out_7060224876276749950[9] = 0;
   out_7060224876276749950[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_7430002568771021643) {
   out_7430002568771021643[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_7060224876276749950) {
   out_7060224876276749950[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7060224876276749950[6] = 0;
   out_7060224876276749950[7] = 1;
   out_7060224876276749950[8] = 0;
   out_7060224876276749950[9] = 0;
   out_7060224876276749950[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_654910612427940843) {
  err_fun(nom_x, delta_x, out_654910612427940843);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6637724801134549563) {
  inv_err_fun(nom_x, true_x, out_6637724801134549563);
}
void gnss_H_mod_fun(double *state, double *out_805386010827368873) {
  H_mod_fun(state, out_805386010827368873);
}
void gnss_f_fun(double *state, double dt, double *out_4766656596405504851) {
  f_fun(state,  dt, out_4766656596405504851);
}
void gnss_F_fun(double *state, double dt, double *out_4029299056587768608) {
  F_fun(state,  dt, out_4029299056587768608);
}
void gnss_h_6(double *state, double *sat_pos, double *out_1067178731754715050) {
  h_6(state, sat_pos, out_1067178731754715050);
}
void gnss_H_6(double *state, double *sat_pos, double *out_7962220724729872721) {
  H_6(state, sat_pos, out_7962220724729872721);
}
void gnss_h_20(double *state, double *sat_pos, double *out_7444431052127272697) {
  h_20(state, sat_pos, out_7444431052127272697);
}
void gnss_H_20(double *state, double *sat_pos, double *out_799492558915393744) {
  H_20(state, sat_pos, out_799492558915393744);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7430002568771021643) {
  h_7(state, sat_pos_vel, out_7430002568771021643);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7060224876276749950) {
  H_7(state, sat_pos_vel, out_7060224876276749950);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7430002568771021643) {
  h_21(state, sat_pos_vel, out_7430002568771021643);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7060224876276749950) {
  H_21(state, sat_pos_vel, out_7060224876276749950);
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
