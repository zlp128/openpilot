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
void err_fun(double *nom_x, double *delta_x, double *out_2097260997154060327) {
   out_2097260997154060327[0] = delta_x[0] + nom_x[0];
   out_2097260997154060327[1] = delta_x[1] + nom_x[1];
   out_2097260997154060327[2] = delta_x[2] + nom_x[2];
   out_2097260997154060327[3] = delta_x[3] + nom_x[3];
   out_2097260997154060327[4] = delta_x[4] + nom_x[4];
   out_2097260997154060327[5] = delta_x[5] + nom_x[5];
   out_2097260997154060327[6] = delta_x[6] + nom_x[6];
   out_2097260997154060327[7] = delta_x[7] + nom_x[7];
   out_2097260997154060327[8] = delta_x[8] + nom_x[8];
   out_2097260997154060327[9] = delta_x[9] + nom_x[9];
   out_2097260997154060327[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_407819598143463209) {
   out_407819598143463209[0] = -nom_x[0] + true_x[0];
   out_407819598143463209[1] = -nom_x[1] + true_x[1];
   out_407819598143463209[2] = -nom_x[2] + true_x[2];
   out_407819598143463209[3] = -nom_x[3] + true_x[3];
   out_407819598143463209[4] = -nom_x[4] + true_x[4];
   out_407819598143463209[5] = -nom_x[5] + true_x[5];
   out_407819598143463209[6] = -nom_x[6] + true_x[6];
   out_407819598143463209[7] = -nom_x[7] + true_x[7];
   out_407819598143463209[8] = -nom_x[8] + true_x[8];
   out_407819598143463209[9] = -nom_x[9] + true_x[9];
   out_407819598143463209[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_4427837971737845911) {
   out_4427837971737845911[0] = 1.0;
   out_4427837971737845911[1] = 0;
   out_4427837971737845911[2] = 0;
   out_4427837971737845911[3] = 0;
   out_4427837971737845911[4] = 0;
   out_4427837971737845911[5] = 0;
   out_4427837971737845911[6] = 0;
   out_4427837971737845911[7] = 0;
   out_4427837971737845911[8] = 0;
   out_4427837971737845911[9] = 0;
   out_4427837971737845911[10] = 0;
   out_4427837971737845911[11] = 0;
   out_4427837971737845911[12] = 1.0;
   out_4427837971737845911[13] = 0;
   out_4427837971737845911[14] = 0;
   out_4427837971737845911[15] = 0;
   out_4427837971737845911[16] = 0;
   out_4427837971737845911[17] = 0;
   out_4427837971737845911[18] = 0;
   out_4427837971737845911[19] = 0;
   out_4427837971737845911[20] = 0;
   out_4427837971737845911[21] = 0;
   out_4427837971737845911[22] = 0;
   out_4427837971737845911[23] = 0;
   out_4427837971737845911[24] = 1.0;
   out_4427837971737845911[25] = 0;
   out_4427837971737845911[26] = 0;
   out_4427837971737845911[27] = 0;
   out_4427837971737845911[28] = 0;
   out_4427837971737845911[29] = 0;
   out_4427837971737845911[30] = 0;
   out_4427837971737845911[31] = 0;
   out_4427837971737845911[32] = 0;
   out_4427837971737845911[33] = 0;
   out_4427837971737845911[34] = 0;
   out_4427837971737845911[35] = 0;
   out_4427837971737845911[36] = 1.0;
   out_4427837971737845911[37] = 0;
   out_4427837971737845911[38] = 0;
   out_4427837971737845911[39] = 0;
   out_4427837971737845911[40] = 0;
   out_4427837971737845911[41] = 0;
   out_4427837971737845911[42] = 0;
   out_4427837971737845911[43] = 0;
   out_4427837971737845911[44] = 0;
   out_4427837971737845911[45] = 0;
   out_4427837971737845911[46] = 0;
   out_4427837971737845911[47] = 0;
   out_4427837971737845911[48] = 1.0;
   out_4427837971737845911[49] = 0;
   out_4427837971737845911[50] = 0;
   out_4427837971737845911[51] = 0;
   out_4427837971737845911[52] = 0;
   out_4427837971737845911[53] = 0;
   out_4427837971737845911[54] = 0;
   out_4427837971737845911[55] = 0;
   out_4427837971737845911[56] = 0;
   out_4427837971737845911[57] = 0;
   out_4427837971737845911[58] = 0;
   out_4427837971737845911[59] = 0;
   out_4427837971737845911[60] = 1.0;
   out_4427837971737845911[61] = 0;
   out_4427837971737845911[62] = 0;
   out_4427837971737845911[63] = 0;
   out_4427837971737845911[64] = 0;
   out_4427837971737845911[65] = 0;
   out_4427837971737845911[66] = 0;
   out_4427837971737845911[67] = 0;
   out_4427837971737845911[68] = 0;
   out_4427837971737845911[69] = 0;
   out_4427837971737845911[70] = 0;
   out_4427837971737845911[71] = 0;
   out_4427837971737845911[72] = 1.0;
   out_4427837971737845911[73] = 0;
   out_4427837971737845911[74] = 0;
   out_4427837971737845911[75] = 0;
   out_4427837971737845911[76] = 0;
   out_4427837971737845911[77] = 0;
   out_4427837971737845911[78] = 0;
   out_4427837971737845911[79] = 0;
   out_4427837971737845911[80] = 0;
   out_4427837971737845911[81] = 0;
   out_4427837971737845911[82] = 0;
   out_4427837971737845911[83] = 0;
   out_4427837971737845911[84] = 1.0;
   out_4427837971737845911[85] = 0;
   out_4427837971737845911[86] = 0;
   out_4427837971737845911[87] = 0;
   out_4427837971737845911[88] = 0;
   out_4427837971737845911[89] = 0;
   out_4427837971737845911[90] = 0;
   out_4427837971737845911[91] = 0;
   out_4427837971737845911[92] = 0;
   out_4427837971737845911[93] = 0;
   out_4427837971737845911[94] = 0;
   out_4427837971737845911[95] = 0;
   out_4427837971737845911[96] = 1.0;
   out_4427837971737845911[97] = 0;
   out_4427837971737845911[98] = 0;
   out_4427837971737845911[99] = 0;
   out_4427837971737845911[100] = 0;
   out_4427837971737845911[101] = 0;
   out_4427837971737845911[102] = 0;
   out_4427837971737845911[103] = 0;
   out_4427837971737845911[104] = 0;
   out_4427837971737845911[105] = 0;
   out_4427837971737845911[106] = 0;
   out_4427837971737845911[107] = 0;
   out_4427837971737845911[108] = 1.0;
   out_4427837971737845911[109] = 0;
   out_4427837971737845911[110] = 0;
   out_4427837971737845911[111] = 0;
   out_4427837971737845911[112] = 0;
   out_4427837971737845911[113] = 0;
   out_4427837971737845911[114] = 0;
   out_4427837971737845911[115] = 0;
   out_4427837971737845911[116] = 0;
   out_4427837971737845911[117] = 0;
   out_4427837971737845911[118] = 0;
   out_4427837971737845911[119] = 0;
   out_4427837971737845911[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_2405095626721301493) {
   out_2405095626721301493[0] = dt*state[3] + state[0];
   out_2405095626721301493[1] = dt*state[4] + state[1];
   out_2405095626721301493[2] = dt*state[5] + state[2];
   out_2405095626721301493[3] = state[3];
   out_2405095626721301493[4] = state[4];
   out_2405095626721301493[5] = state[5];
   out_2405095626721301493[6] = dt*state[7] + state[6];
   out_2405095626721301493[7] = dt*state[8] + state[7];
   out_2405095626721301493[8] = state[8];
   out_2405095626721301493[9] = state[9];
   out_2405095626721301493[10] = state[10];
}
void F_fun(double *state, double dt, double *out_1835212025890269909) {
   out_1835212025890269909[0] = 1;
   out_1835212025890269909[1] = 0;
   out_1835212025890269909[2] = 0;
   out_1835212025890269909[3] = dt;
   out_1835212025890269909[4] = 0;
   out_1835212025890269909[5] = 0;
   out_1835212025890269909[6] = 0;
   out_1835212025890269909[7] = 0;
   out_1835212025890269909[8] = 0;
   out_1835212025890269909[9] = 0;
   out_1835212025890269909[10] = 0;
   out_1835212025890269909[11] = 0;
   out_1835212025890269909[12] = 1;
   out_1835212025890269909[13] = 0;
   out_1835212025890269909[14] = 0;
   out_1835212025890269909[15] = dt;
   out_1835212025890269909[16] = 0;
   out_1835212025890269909[17] = 0;
   out_1835212025890269909[18] = 0;
   out_1835212025890269909[19] = 0;
   out_1835212025890269909[20] = 0;
   out_1835212025890269909[21] = 0;
   out_1835212025890269909[22] = 0;
   out_1835212025890269909[23] = 0;
   out_1835212025890269909[24] = 1;
   out_1835212025890269909[25] = 0;
   out_1835212025890269909[26] = 0;
   out_1835212025890269909[27] = dt;
   out_1835212025890269909[28] = 0;
   out_1835212025890269909[29] = 0;
   out_1835212025890269909[30] = 0;
   out_1835212025890269909[31] = 0;
   out_1835212025890269909[32] = 0;
   out_1835212025890269909[33] = 0;
   out_1835212025890269909[34] = 0;
   out_1835212025890269909[35] = 0;
   out_1835212025890269909[36] = 1;
   out_1835212025890269909[37] = 0;
   out_1835212025890269909[38] = 0;
   out_1835212025890269909[39] = 0;
   out_1835212025890269909[40] = 0;
   out_1835212025890269909[41] = 0;
   out_1835212025890269909[42] = 0;
   out_1835212025890269909[43] = 0;
   out_1835212025890269909[44] = 0;
   out_1835212025890269909[45] = 0;
   out_1835212025890269909[46] = 0;
   out_1835212025890269909[47] = 0;
   out_1835212025890269909[48] = 1;
   out_1835212025890269909[49] = 0;
   out_1835212025890269909[50] = 0;
   out_1835212025890269909[51] = 0;
   out_1835212025890269909[52] = 0;
   out_1835212025890269909[53] = 0;
   out_1835212025890269909[54] = 0;
   out_1835212025890269909[55] = 0;
   out_1835212025890269909[56] = 0;
   out_1835212025890269909[57] = 0;
   out_1835212025890269909[58] = 0;
   out_1835212025890269909[59] = 0;
   out_1835212025890269909[60] = 1;
   out_1835212025890269909[61] = 0;
   out_1835212025890269909[62] = 0;
   out_1835212025890269909[63] = 0;
   out_1835212025890269909[64] = 0;
   out_1835212025890269909[65] = 0;
   out_1835212025890269909[66] = 0;
   out_1835212025890269909[67] = 0;
   out_1835212025890269909[68] = 0;
   out_1835212025890269909[69] = 0;
   out_1835212025890269909[70] = 0;
   out_1835212025890269909[71] = 0;
   out_1835212025890269909[72] = 1;
   out_1835212025890269909[73] = dt;
   out_1835212025890269909[74] = 0;
   out_1835212025890269909[75] = 0;
   out_1835212025890269909[76] = 0;
   out_1835212025890269909[77] = 0;
   out_1835212025890269909[78] = 0;
   out_1835212025890269909[79] = 0;
   out_1835212025890269909[80] = 0;
   out_1835212025890269909[81] = 0;
   out_1835212025890269909[82] = 0;
   out_1835212025890269909[83] = 0;
   out_1835212025890269909[84] = 1;
   out_1835212025890269909[85] = dt;
   out_1835212025890269909[86] = 0;
   out_1835212025890269909[87] = 0;
   out_1835212025890269909[88] = 0;
   out_1835212025890269909[89] = 0;
   out_1835212025890269909[90] = 0;
   out_1835212025890269909[91] = 0;
   out_1835212025890269909[92] = 0;
   out_1835212025890269909[93] = 0;
   out_1835212025890269909[94] = 0;
   out_1835212025890269909[95] = 0;
   out_1835212025890269909[96] = 1;
   out_1835212025890269909[97] = 0;
   out_1835212025890269909[98] = 0;
   out_1835212025890269909[99] = 0;
   out_1835212025890269909[100] = 0;
   out_1835212025890269909[101] = 0;
   out_1835212025890269909[102] = 0;
   out_1835212025890269909[103] = 0;
   out_1835212025890269909[104] = 0;
   out_1835212025890269909[105] = 0;
   out_1835212025890269909[106] = 0;
   out_1835212025890269909[107] = 0;
   out_1835212025890269909[108] = 1;
   out_1835212025890269909[109] = 0;
   out_1835212025890269909[110] = 0;
   out_1835212025890269909[111] = 0;
   out_1835212025890269909[112] = 0;
   out_1835212025890269909[113] = 0;
   out_1835212025890269909[114] = 0;
   out_1835212025890269909[115] = 0;
   out_1835212025890269909[116] = 0;
   out_1835212025890269909[117] = 0;
   out_1835212025890269909[118] = 0;
   out_1835212025890269909[119] = 0;
   out_1835212025890269909[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_1528125412600993628) {
   out_1528125412600993628[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_104140276440086105) {
   out_104140276440086105[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_104140276440086105[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_104140276440086105[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_104140276440086105[3] = 0;
   out_104140276440086105[4] = 0;
   out_104140276440086105[5] = 0;
   out_104140276440086105[6] = 1;
   out_104140276440086105[7] = 0;
   out_104140276440086105[8] = 0;
   out_104140276440086105[9] = 0;
   out_104140276440086105[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_601402367496244624) {
   out_601402367496244624[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_4705666395271220693) {
   out_4705666395271220693[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4705666395271220693[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4705666395271220693[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_4705666395271220693[3] = 0;
   out_4705666395271220693[4] = 0;
   out_4705666395271220693[5] = 0;
   out_4705666395271220693[6] = 1;
   out_4705666395271220693[7] = 0;
   out_4705666395271220693[8] = 0;
   out_4705666395271220693[9] = 1;
   out_4705666395271220693[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_2964007189672083137) {
   out_2964007189672083137[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_45965290841563331) {
   out_45965290841563331[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[6] = 0;
   out_45965290841563331[7] = 1;
   out_45965290841563331[8] = 0;
   out_45965290841563331[9] = 0;
   out_45965290841563331[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_2964007189672083137) {
   out_2964007189672083137[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_45965290841563331) {
   out_45965290841563331[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_45965290841563331[6] = 0;
   out_45965290841563331[7] = 1;
   out_45965290841563331[8] = 0;
   out_45965290841563331[9] = 0;
   out_45965290841563331[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2097260997154060327) {
  err_fun(nom_x, delta_x, out_2097260997154060327);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_407819598143463209) {
  inv_err_fun(nom_x, true_x, out_407819598143463209);
}
void gnss_H_mod_fun(double *state, double *out_4427837971737845911) {
  H_mod_fun(state, out_4427837971737845911);
}
void gnss_f_fun(double *state, double dt, double *out_2405095626721301493) {
  f_fun(state,  dt, out_2405095626721301493);
}
void gnss_F_fun(double *state, double dt, double *out_1835212025890269909) {
  F_fun(state,  dt, out_1835212025890269909);
}
void gnss_h_6(double *state, double *sat_pos, double *out_1528125412600993628) {
  h_6(state, sat_pos, out_1528125412600993628);
}
void gnss_H_6(double *state, double *sat_pos, double *out_104140276440086105) {
  H_6(state, sat_pos, out_104140276440086105);
}
void gnss_h_20(double *state, double *sat_pos, double *out_601402367496244624) {
  h_20(state, sat_pos, out_601402367496244624);
}
void gnss_H_20(double *state, double *sat_pos, double *out_4705666395271220693) {
  H_20(state, sat_pos, out_4705666395271220693);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2964007189672083137) {
  h_7(state, sat_pos_vel, out_2964007189672083137);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_45965290841563331) {
  H_7(state, sat_pos_vel, out_45965290841563331);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2964007189672083137) {
  h_21(state, sat_pos_vel, out_2964007189672083137);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_45965290841563331) {
  H_21(state, sat_pos_vel, out_45965290841563331);
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
