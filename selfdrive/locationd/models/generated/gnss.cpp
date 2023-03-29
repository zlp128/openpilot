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
void err_fun(double *nom_x, double *delta_x, double *out_8218999594846759964) {
   out_8218999594846759964[0] = delta_x[0] + nom_x[0];
   out_8218999594846759964[1] = delta_x[1] + nom_x[1];
   out_8218999594846759964[2] = delta_x[2] + nom_x[2];
   out_8218999594846759964[3] = delta_x[3] + nom_x[3];
   out_8218999594846759964[4] = delta_x[4] + nom_x[4];
   out_8218999594846759964[5] = delta_x[5] + nom_x[5];
   out_8218999594846759964[6] = delta_x[6] + nom_x[6];
   out_8218999594846759964[7] = delta_x[7] + nom_x[7];
   out_8218999594846759964[8] = delta_x[8] + nom_x[8];
   out_8218999594846759964[9] = delta_x[9] + nom_x[9];
   out_8218999594846759964[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6004490369099356165) {
   out_6004490369099356165[0] = -nom_x[0] + true_x[0];
   out_6004490369099356165[1] = -nom_x[1] + true_x[1];
   out_6004490369099356165[2] = -nom_x[2] + true_x[2];
   out_6004490369099356165[3] = -nom_x[3] + true_x[3];
   out_6004490369099356165[4] = -nom_x[4] + true_x[4];
   out_6004490369099356165[5] = -nom_x[5] + true_x[5];
   out_6004490369099356165[6] = -nom_x[6] + true_x[6];
   out_6004490369099356165[7] = -nom_x[7] + true_x[7];
   out_6004490369099356165[8] = -nom_x[8] + true_x[8];
   out_6004490369099356165[9] = -nom_x[9] + true_x[9];
   out_6004490369099356165[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_5465143194872640210) {
   out_5465143194872640210[0] = 1.0;
   out_5465143194872640210[1] = 0;
   out_5465143194872640210[2] = 0;
   out_5465143194872640210[3] = 0;
   out_5465143194872640210[4] = 0;
   out_5465143194872640210[5] = 0;
   out_5465143194872640210[6] = 0;
   out_5465143194872640210[7] = 0;
   out_5465143194872640210[8] = 0;
   out_5465143194872640210[9] = 0;
   out_5465143194872640210[10] = 0;
   out_5465143194872640210[11] = 0;
   out_5465143194872640210[12] = 1.0;
   out_5465143194872640210[13] = 0;
   out_5465143194872640210[14] = 0;
   out_5465143194872640210[15] = 0;
   out_5465143194872640210[16] = 0;
   out_5465143194872640210[17] = 0;
   out_5465143194872640210[18] = 0;
   out_5465143194872640210[19] = 0;
   out_5465143194872640210[20] = 0;
   out_5465143194872640210[21] = 0;
   out_5465143194872640210[22] = 0;
   out_5465143194872640210[23] = 0;
   out_5465143194872640210[24] = 1.0;
   out_5465143194872640210[25] = 0;
   out_5465143194872640210[26] = 0;
   out_5465143194872640210[27] = 0;
   out_5465143194872640210[28] = 0;
   out_5465143194872640210[29] = 0;
   out_5465143194872640210[30] = 0;
   out_5465143194872640210[31] = 0;
   out_5465143194872640210[32] = 0;
   out_5465143194872640210[33] = 0;
   out_5465143194872640210[34] = 0;
   out_5465143194872640210[35] = 0;
   out_5465143194872640210[36] = 1.0;
   out_5465143194872640210[37] = 0;
   out_5465143194872640210[38] = 0;
   out_5465143194872640210[39] = 0;
   out_5465143194872640210[40] = 0;
   out_5465143194872640210[41] = 0;
   out_5465143194872640210[42] = 0;
   out_5465143194872640210[43] = 0;
   out_5465143194872640210[44] = 0;
   out_5465143194872640210[45] = 0;
   out_5465143194872640210[46] = 0;
   out_5465143194872640210[47] = 0;
   out_5465143194872640210[48] = 1.0;
   out_5465143194872640210[49] = 0;
   out_5465143194872640210[50] = 0;
   out_5465143194872640210[51] = 0;
   out_5465143194872640210[52] = 0;
   out_5465143194872640210[53] = 0;
   out_5465143194872640210[54] = 0;
   out_5465143194872640210[55] = 0;
   out_5465143194872640210[56] = 0;
   out_5465143194872640210[57] = 0;
   out_5465143194872640210[58] = 0;
   out_5465143194872640210[59] = 0;
   out_5465143194872640210[60] = 1.0;
   out_5465143194872640210[61] = 0;
   out_5465143194872640210[62] = 0;
   out_5465143194872640210[63] = 0;
   out_5465143194872640210[64] = 0;
   out_5465143194872640210[65] = 0;
   out_5465143194872640210[66] = 0;
   out_5465143194872640210[67] = 0;
   out_5465143194872640210[68] = 0;
   out_5465143194872640210[69] = 0;
   out_5465143194872640210[70] = 0;
   out_5465143194872640210[71] = 0;
   out_5465143194872640210[72] = 1.0;
   out_5465143194872640210[73] = 0;
   out_5465143194872640210[74] = 0;
   out_5465143194872640210[75] = 0;
   out_5465143194872640210[76] = 0;
   out_5465143194872640210[77] = 0;
   out_5465143194872640210[78] = 0;
   out_5465143194872640210[79] = 0;
   out_5465143194872640210[80] = 0;
   out_5465143194872640210[81] = 0;
   out_5465143194872640210[82] = 0;
   out_5465143194872640210[83] = 0;
   out_5465143194872640210[84] = 1.0;
   out_5465143194872640210[85] = 0;
   out_5465143194872640210[86] = 0;
   out_5465143194872640210[87] = 0;
   out_5465143194872640210[88] = 0;
   out_5465143194872640210[89] = 0;
   out_5465143194872640210[90] = 0;
   out_5465143194872640210[91] = 0;
   out_5465143194872640210[92] = 0;
   out_5465143194872640210[93] = 0;
   out_5465143194872640210[94] = 0;
   out_5465143194872640210[95] = 0;
   out_5465143194872640210[96] = 1.0;
   out_5465143194872640210[97] = 0;
   out_5465143194872640210[98] = 0;
   out_5465143194872640210[99] = 0;
   out_5465143194872640210[100] = 0;
   out_5465143194872640210[101] = 0;
   out_5465143194872640210[102] = 0;
   out_5465143194872640210[103] = 0;
   out_5465143194872640210[104] = 0;
   out_5465143194872640210[105] = 0;
   out_5465143194872640210[106] = 0;
   out_5465143194872640210[107] = 0;
   out_5465143194872640210[108] = 1.0;
   out_5465143194872640210[109] = 0;
   out_5465143194872640210[110] = 0;
   out_5465143194872640210[111] = 0;
   out_5465143194872640210[112] = 0;
   out_5465143194872640210[113] = 0;
   out_5465143194872640210[114] = 0;
   out_5465143194872640210[115] = 0;
   out_5465143194872640210[116] = 0;
   out_5465143194872640210[117] = 0;
   out_5465143194872640210[118] = 0;
   out_5465143194872640210[119] = 0;
   out_5465143194872640210[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_6477589900664112980) {
   out_6477589900664112980[0] = dt*state[3] + state[0];
   out_6477589900664112980[1] = dt*state[4] + state[1];
   out_6477589900664112980[2] = dt*state[5] + state[2];
   out_6477589900664112980[3] = state[3];
   out_6477589900664112980[4] = state[4];
   out_6477589900664112980[5] = state[5];
   out_6477589900664112980[6] = dt*state[7] + state[6];
   out_6477589900664112980[7] = dt*state[8] + state[7];
   out_6477589900664112980[8] = state[8];
   out_6477589900664112980[9] = state[9];
   out_6477589900664112980[10] = state[10];
}
void F_fun(double *state, double dt, double *out_159332577828599777) {
   out_159332577828599777[0] = 1;
   out_159332577828599777[1] = 0;
   out_159332577828599777[2] = 0;
   out_159332577828599777[3] = dt;
   out_159332577828599777[4] = 0;
   out_159332577828599777[5] = 0;
   out_159332577828599777[6] = 0;
   out_159332577828599777[7] = 0;
   out_159332577828599777[8] = 0;
   out_159332577828599777[9] = 0;
   out_159332577828599777[10] = 0;
   out_159332577828599777[11] = 0;
   out_159332577828599777[12] = 1;
   out_159332577828599777[13] = 0;
   out_159332577828599777[14] = 0;
   out_159332577828599777[15] = dt;
   out_159332577828599777[16] = 0;
   out_159332577828599777[17] = 0;
   out_159332577828599777[18] = 0;
   out_159332577828599777[19] = 0;
   out_159332577828599777[20] = 0;
   out_159332577828599777[21] = 0;
   out_159332577828599777[22] = 0;
   out_159332577828599777[23] = 0;
   out_159332577828599777[24] = 1;
   out_159332577828599777[25] = 0;
   out_159332577828599777[26] = 0;
   out_159332577828599777[27] = dt;
   out_159332577828599777[28] = 0;
   out_159332577828599777[29] = 0;
   out_159332577828599777[30] = 0;
   out_159332577828599777[31] = 0;
   out_159332577828599777[32] = 0;
   out_159332577828599777[33] = 0;
   out_159332577828599777[34] = 0;
   out_159332577828599777[35] = 0;
   out_159332577828599777[36] = 1;
   out_159332577828599777[37] = 0;
   out_159332577828599777[38] = 0;
   out_159332577828599777[39] = 0;
   out_159332577828599777[40] = 0;
   out_159332577828599777[41] = 0;
   out_159332577828599777[42] = 0;
   out_159332577828599777[43] = 0;
   out_159332577828599777[44] = 0;
   out_159332577828599777[45] = 0;
   out_159332577828599777[46] = 0;
   out_159332577828599777[47] = 0;
   out_159332577828599777[48] = 1;
   out_159332577828599777[49] = 0;
   out_159332577828599777[50] = 0;
   out_159332577828599777[51] = 0;
   out_159332577828599777[52] = 0;
   out_159332577828599777[53] = 0;
   out_159332577828599777[54] = 0;
   out_159332577828599777[55] = 0;
   out_159332577828599777[56] = 0;
   out_159332577828599777[57] = 0;
   out_159332577828599777[58] = 0;
   out_159332577828599777[59] = 0;
   out_159332577828599777[60] = 1;
   out_159332577828599777[61] = 0;
   out_159332577828599777[62] = 0;
   out_159332577828599777[63] = 0;
   out_159332577828599777[64] = 0;
   out_159332577828599777[65] = 0;
   out_159332577828599777[66] = 0;
   out_159332577828599777[67] = 0;
   out_159332577828599777[68] = 0;
   out_159332577828599777[69] = 0;
   out_159332577828599777[70] = 0;
   out_159332577828599777[71] = 0;
   out_159332577828599777[72] = 1;
   out_159332577828599777[73] = dt;
   out_159332577828599777[74] = 0;
   out_159332577828599777[75] = 0;
   out_159332577828599777[76] = 0;
   out_159332577828599777[77] = 0;
   out_159332577828599777[78] = 0;
   out_159332577828599777[79] = 0;
   out_159332577828599777[80] = 0;
   out_159332577828599777[81] = 0;
   out_159332577828599777[82] = 0;
   out_159332577828599777[83] = 0;
   out_159332577828599777[84] = 1;
   out_159332577828599777[85] = dt;
   out_159332577828599777[86] = 0;
   out_159332577828599777[87] = 0;
   out_159332577828599777[88] = 0;
   out_159332577828599777[89] = 0;
   out_159332577828599777[90] = 0;
   out_159332577828599777[91] = 0;
   out_159332577828599777[92] = 0;
   out_159332577828599777[93] = 0;
   out_159332577828599777[94] = 0;
   out_159332577828599777[95] = 0;
   out_159332577828599777[96] = 1;
   out_159332577828599777[97] = 0;
   out_159332577828599777[98] = 0;
   out_159332577828599777[99] = 0;
   out_159332577828599777[100] = 0;
   out_159332577828599777[101] = 0;
   out_159332577828599777[102] = 0;
   out_159332577828599777[103] = 0;
   out_159332577828599777[104] = 0;
   out_159332577828599777[105] = 0;
   out_159332577828599777[106] = 0;
   out_159332577828599777[107] = 0;
   out_159332577828599777[108] = 1;
   out_159332577828599777[109] = 0;
   out_159332577828599777[110] = 0;
   out_159332577828599777[111] = 0;
   out_159332577828599777[112] = 0;
   out_159332577828599777[113] = 0;
   out_159332577828599777[114] = 0;
   out_159332577828599777[115] = 0;
   out_159332577828599777[116] = 0;
   out_159332577828599777[117] = 0;
   out_159332577828599777[118] = 0;
   out_159332577828599777[119] = 0;
   out_159332577828599777[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_822185378282268145) {
   out_822185378282268145[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_2954217689973778176) {
   out_2954217689973778176[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2954217689973778176[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2954217689973778176[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_2954217689973778176[3] = 0;
   out_2954217689973778176[4] = 0;
   out_2954217689973778176[5] = 0;
   out_2954217689973778176[6] = 1;
   out_2954217689973778176[7] = 0;
   out_2954217689973778176[8] = 0;
   out_2954217689973778176[9] = 0;
   out_2954217689973778176[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_3775340380998125465) {
   out_3775340380998125465[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_4124080333257632986) {
   out_4124080333257632986[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4124080333257632986[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4124080333257632986[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4124080333257632986[3] = 0;
   out_4124080333257632986[4] = 0;
   out_4124080333257632986[5] = 0;
   out_4124080333257632986[6] = 1;
   out_4124080333257632986[7] = 0;
   out_4124080333257632986[8] = 0;
   out_4124080333257632986[9] = 1;
   out_4124080333257632986[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_750344228235882460) {
   out_750344228235882460[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_1618262330099536806) {
   out_1618262330099536806[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[6] = 0;
   out_1618262330099536806[7] = 1;
   out_1618262330099536806[8] = 0;
   out_1618262330099536806[9] = 0;
   out_1618262330099536806[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_750344228235882460) {
   out_750344228235882460[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_1618262330099536806) {
   out_1618262330099536806[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1618262330099536806[6] = 0;
   out_1618262330099536806[7] = 1;
   out_1618262330099536806[8] = 0;
   out_1618262330099536806[9] = 0;
   out_1618262330099536806[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8218999594846759964) {
  err_fun(nom_x, delta_x, out_8218999594846759964);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6004490369099356165) {
  inv_err_fun(nom_x, true_x, out_6004490369099356165);
}
void gnss_H_mod_fun(double *state, double *out_5465143194872640210) {
  H_mod_fun(state, out_5465143194872640210);
}
void gnss_f_fun(double *state, double dt, double *out_6477589900664112980) {
  f_fun(state,  dt, out_6477589900664112980);
}
void gnss_F_fun(double *state, double dt, double *out_159332577828599777) {
  F_fun(state,  dt, out_159332577828599777);
}
void gnss_h_6(double *state, double *sat_pos, double *out_822185378282268145) {
  h_6(state, sat_pos, out_822185378282268145);
}
void gnss_H_6(double *state, double *sat_pos, double *out_2954217689973778176) {
  H_6(state, sat_pos, out_2954217689973778176);
}
void gnss_h_20(double *state, double *sat_pos, double *out_3775340380998125465) {
  h_20(state, sat_pos, out_3775340380998125465);
}
void gnss_H_20(double *state, double *sat_pos, double *out_4124080333257632986) {
  H_20(state, sat_pos, out_4124080333257632986);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_750344228235882460) {
  h_7(state, sat_pos_vel, out_750344228235882460);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1618262330099536806) {
  H_7(state, sat_pos_vel, out_1618262330099536806);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_750344228235882460) {
  h_21(state, sat_pos_vel, out_750344228235882460);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1618262330099536806) {
  H_21(state, sat_pos_vel, out_1618262330099536806);
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
