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
void err_fun(double *nom_x, double *delta_x, double *out_6740791193231733360) {
   out_6740791193231733360[0] = delta_x[0] + nom_x[0];
   out_6740791193231733360[1] = delta_x[1] + nom_x[1];
   out_6740791193231733360[2] = delta_x[2] + nom_x[2];
   out_6740791193231733360[3] = delta_x[3] + nom_x[3];
   out_6740791193231733360[4] = delta_x[4] + nom_x[4];
   out_6740791193231733360[5] = delta_x[5] + nom_x[5];
   out_6740791193231733360[6] = delta_x[6] + nom_x[6];
   out_6740791193231733360[7] = delta_x[7] + nom_x[7];
   out_6740791193231733360[8] = delta_x[8] + nom_x[8];
   out_6740791193231733360[9] = delta_x[9] + nom_x[9];
   out_6740791193231733360[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5435998030533772419) {
   out_5435998030533772419[0] = -nom_x[0] + true_x[0];
   out_5435998030533772419[1] = -nom_x[1] + true_x[1];
   out_5435998030533772419[2] = -nom_x[2] + true_x[2];
   out_5435998030533772419[3] = -nom_x[3] + true_x[3];
   out_5435998030533772419[4] = -nom_x[4] + true_x[4];
   out_5435998030533772419[5] = -nom_x[5] + true_x[5];
   out_5435998030533772419[6] = -nom_x[6] + true_x[6];
   out_5435998030533772419[7] = -nom_x[7] + true_x[7];
   out_5435998030533772419[8] = -nom_x[8] + true_x[8];
   out_5435998030533772419[9] = -nom_x[9] + true_x[9];
   out_5435998030533772419[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_8750904480143678209) {
   out_8750904480143678209[0] = 1.0;
   out_8750904480143678209[1] = 0;
   out_8750904480143678209[2] = 0;
   out_8750904480143678209[3] = 0;
   out_8750904480143678209[4] = 0;
   out_8750904480143678209[5] = 0;
   out_8750904480143678209[6] = 0;
   out_8750904480143678209[7] = 0;
   out_8750904480143678209[8] = 0;
   out_8750904480143678209[9] = 0;
   out_8750904480143678209[10] = 0;
   out_8750904480143678209[11] = 0;
   out_8750904480143678209[12] = 1.0;
   out_8750904480143678209[13] = 0;
   out_8750904480143678209[14] = 0;
   out_8750904480143678209[15] = 0;
   out_8750904480143678209[16] = 0;
   out_8750904480143678209[17] = 0;
   out_8750904480143678209[18] = 0;
   out_8750904480143678209[19] = 0;
   out_8750904480143678209[20] = 0;
   out_8750904480143678209[21] = 0;
   out_8750904480143678209[22] = 0;
   out_8750904480143678209[23] = 0;
   out_8750904480143678209[24] = 1.0;
   out_8750904480143678209[25] = 0;
   out_8750904480143678209[26] = 0;
   out_8750904480143678209[27] = 0;
   out_8750904480143678209[28] = 0;
   out_8750904480143678209[29] = 0;
   out_8750904480143678209[30] = 0;
   out_8750904480143678209[31] = 0;
   out_8750904480143678209[32] = 0;
   out_8750904480143678209[33] = 0;
   out_8750904480143678209[34] = 0;
   out_8750904480143678209[35] = 0;
   out_8750904480143678209[36] = 1.0;
   out_8750904480143678209[37] = 0;
   out_8750904480143678209[38] = 0;
   out_8750904480143678209[39] = 0;
   out_8750904480143678209[40] = 0;
   out_8750904480143678209[41] = 0;
   out_8750904480143678209[42] = 0;
   out_8750904480143678209[43] = 0;
   out_8750904480143678209[44] = 0;
   out_8750904480143678209[45] = 0;
   out_8750904480143678209[46] = 0;
   out_8750904480143678209[47] = 0;
   out_8750904480143678209[48] = 1.0;
   out_8750904480143678209[49] = 0;
   out_8750904480143678209[50] = 0;
   out_8750904480143678209[51] = 0;
   out_8750904480143678209[52] = 0;
   out_8750904480143678209[53] = 0;
   out_8750904480143678209[54] = 0;
   out_8750904480143678209[55] = 0;
   out_8750904480143678209[56] = 0;
   out_8750904480143678209[57] = 0;
   out_8750904480143678209[58] = 0;
   out_8750904480143678209[59] = 0;
   out_8750904480143678209[60] = 1.0;
   out_8750904480143678209[61] = 0;
   out_8750904480143678209[62] = 0;
   out_8750904480143678209[63] = 0;
   out_8750904480143678209[64] = 0;
   out_8750904480143678209[65] = 0;
   out_8750904480143678209[66] = 0;
   out_8750904480143678209[67] = 0;
   out_8750904480143678209[68] = 0;
   out_8750904480143678209[69] = 0;
   out_8750904480143678209[70] = 0;
   out_8750904480143678209[71] = 0;
   out_8750904480143678209[72] = 1.0;
   out_8750904480143678209[73] = 0;
   out_8750904480143678209[74] = 0;
   out_8750904480143678209[75] = 0;
   out_8750904480143678209[76] = 0;
   out_8750904480143678209[77] = 0;
   out_8750904480143678209[78] = 0;
   out_8750904480143678209[79] = 0;
   out_8750904480143678209[80] = 0;
   out_8750904480143678209[81] = 0;
   out_8750904480143678209[82] = 0;
   out_8750904480143678209[83] = 0;
   out_8750904480143678209[84] = 1.0;
   out_8750904480143678209[85] = 0;
   out_8750904480143678209[86] = 0;
   out_8750904480143678209[87] = 0;
   out_8750904480143678209[88] = 0;
   out_8750904480143678209[89] = 0;
   out_8750904480143678209[90] = 0;
   out_8750904480143678209[91] = 0;
   out_8750904480143678209[92] = 0;
   out_8750904480143678209[93] = 0;
   out_8750904480143678209[94] = 0;
   out_8750904480143678209[95] = 0;
   out_8750904480143678209[96] = 1.0;
   out_8750904480143678209[97] = 0;
   out_8750904480143678209[98] = 0;
   out_8750904480143678209[99] = 0;
   out_8750904480143678209[100] = 0;
   out_8750904480143678209[101] = 0;
   out_8750904480143678209[102] = 0;
   out_8750904480143678209[103] = 0;
   out_8750904480143678209[104] = 0;
   out_8750904480143678209[105] = 0;
   out_8750904480143678209[106] = 0;
   out_8750904480143678209[107] = 0;
   out_8750904480143678209[108] = 1.0;
   out_8750904480143678209[109] = 0;
   out_8750904480143678209[110] = 0;
   out_8750904480143678209[111] = 0;
   out_8750904480143678209[112] = 0;
   out_8750904480143678209[113] = 0;
   out_8750904480143678209[114] = 0;
   out_8750904480143678209[115] = 0;
   out_8750904480143678209[116] = 0;
   out_8750904480143678209[117] = 0;
   out_8750904480143678209[118] = 0;
   out_8750904480143678209[119] = 0;
   out_8750904480143678209[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_571033032076185663) {
   out_571033032076185663[0] = dt*state[3] + state[0];
   out_571033032076185663[1] = dt*state[4] + state[1];
   out_571033032076185663[2] = dt*state[5] + state[2];
   out_571033032076185663[3] = state[3];
   out_571033032076185663[4] = state[4];
   out_571033032076185663[5] = state[5];
   out_571033032076185663[6] = dt*state[7] + state[6];
   out_571033032076185663[7] = dt*state[8] + state[7];
   out_571033032076185663[8] = state[8];
   out_571033032076185663[9] = state[9];
   out_571033032076185663[10] = state[10];
}
void F_fun(double *state, double dt, double *out_8071961880976414619) {
   out_8071961880976414619[0] = 1;
   out_8071961880976414619[1] = 0;
   out_8071961880976414619[2] = 0;
   out_8071961880976414619[3] = dt;
   out_8071961880976414619[4] = 0;
   out_8071961880976414619[5] = 0;
   out_8071961880976414619[6] = 0;
   out_8071961880976414619[7] = 0;
   out_8071961880976414619[8] = 0;
   out_8071961880976414619[9] = 0;
   out_8071961880976414619[10] = 0;
   out_8071961880976414619[11] = 0;
   out_8071961880976414619[12] = 1;
   out_8071961880976414619[13] = 0;
   out_8071961880976414619[14] = 0;
   out_8071961880976414619[15] = dt;
   out_8071961880976414619[16] = 0;
   out_8071961880976414619[17] = 0;
   out_8071961880976414619[18] = 0;
   out_8071961880976414619[19] = 0;
   out_8071961880976414619[20] = 0;
   out_8071961880976414619[21] = 0;
   out_8071961880976414619[22] = 0;
   out_8071961880976414619[23] = 0;
   out_8071961880976414619[24] = 1;
   out_8071961880976414619[25] = 0;
   out_8071961880976414619[26] = 0;
   out_8071961880976414619[27] = dt;
   out_8071961880976414619[28] = 0;
   out_8071961880976414619[29] = 0;
   out_8071961880976414619[30] = 0;
   out_8071961880976414619[31] = 0;
   out_8071961880976414619[32] = 0;
   out_8071961880976414619[33] = 0;
   out_8071961880976414619[34] = 0;
   out_8071961880976414619[35] = 0;
   out_8071961880976414619[36] = 1;
   out_8071961880976414619[37] = 0;
   out_8071961880976414619[38] = 0;
   out_8071961880976414619[39] = 0;
   out_8071961880976414619[40] = 0;
   out_8071961880976414619[41] = 0;
   out_8071961880976414619[42] = 0;
   out_8071961880976414619[43] = 0;
   out_8071961880976414619[44] = 0;
   out_8071961880976414619[45] = 0;
   out_8071961880976414619[46] = 0;
   out_8071961880976414619[47] = 0;
   out_8071961880976414619[48] = 1;
   out_8071961880976414619[49] = 0;
   out_8071961880976414619[50] = 0;
   out_8071961880976414619[51] = 0;
   out_8071961880976414619[52] = 0;
   out_8071961880976414619[53] = 0;
   out_8071961880976414619[54] = 0;
   out_8071961880976414619[55] = 0;
   out_8071961880976414619[56] = 0;
   out_8071961880976414619[57] = 0;
   out_8071961880976414619[58] = 0;
   out_8071961880976414619[59] = 0;
   out_8071961880976414619[60] = 1;
   out_8071961880976414619[61] = 0;
   out_8071961880976414619[62] = 0;
   out_8071961880976414619[63] = 0;
   out_8071961880976414619[64] = 0;
   out_8071961880976414619[65] = 0;
   out_8071961880976414619[66] = 0;
   out_8071961880976414619[67] = 0;
   out_8071961880976414619[68] = 0;
   out_8071961880976414619[69] = 0;
   out_8071961880976414619[70] = 0;
   out_8071961880976414619[71] = 0;
   out_8071961880976414619[72] = 1;
   out_8071961880976414619[73] = dt;
   out_8071961880976414619[74] = 0;
   out_8071961880976414619[75] = 0;
   out_8071961880976414619[76] = 0;
   out_8071961880976414619[77] = 0;
   out_8071961880976414619[78] = 0;
   out_8071961880976414619[79] = 0;
   out_8071961880976414619[80] = 0;
   out_8071961880976414619[81] = 0;
   out_8071961880976414619[82] = 0;
   out_8071961880976414619[83] = 0;
   out_8071961880976414619[84] = 1;
   out_8071961880976414619[85] = dt;
   out_8071961880976414619[86] = 0;
   out_8071961880976414619[87] = 0;
   out_8071961880976414619[88] = 0;
   out_8071961880976414619[89] = 0;
   out_8071961880976414619[90] = 0;
   out_8071961880976414619[91] = 0;
   out_8071961880976414619[92] = 0;
   out_8071961880976414619[93] = 0;
   out_8071961880976414619[94] = 0;
   out_8071961880976414619[95] = 0;
   out_8071961880976414619[96] = 1;
   out_8071961880976414619[97] = 0;
   out_8071961880976414619[98] = 0;
   out_8071961880976414619[99] = 0;
   out_8071961880976414619[100] = 0;
   out_8071961880976414619[101] = 0;
   out_8071961880976414619[102] = 0;
   out_8071961880976414619[103] = 0;
   out_8071961880976414619[104] = 0;
   out_8071961880976414619[105] = 0;
   out_8071961880976414619[106] = 0;
   out_8071961880976414619[107] = 0;
   out_8071961880976414619[108] = 1;
   out_8071961880976414619[109] = 0;
   out_8071961880976414619[110] = 0;
   out_8071961880976414619[111] = 0;
   out_8071961880976414619[112] = 0;
   out_8071961880976414619[113] = 0;
   out_8071961880976414619[114] = 0;
   out_8071961880976414619[115] = 0;
   out_8071961880976414619[116] = 0;
   out_8071961880976414619[117] = 0;
   out_8071961880976414619[118] = 0;
   out_8071961880976414619[119] = 0;
   out_8071961880976414619[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_3924727623087114070) {
   out_3924727623087114070[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_3168437365824362595) {
   out_3168437365824362595[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3168437365824362595[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3168437365824362595[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3168437365824362595[3] = 0;
   out_3168437365824362595[4] = 0;
   out_3168437365824362595[5] = 0;
   out_3168437365824362595[6] = 1;
   out_3168437365824362595[7] = 0;
   out_3168437365824362595[8] = 0;
   out_3168437365824362595[9] = 0;
   out_3168437365824362595[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_7434817830173438872) {
   out_7434817830173438872[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_7560749815445785198) {
   out_7560749815445785198[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7560749815445785198[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7560749815445785198[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7560749815445785198[3] = 0;
   out_7560749815445785198[4] = 0;
   out_7560749815445785198[5] = 0;
   out_7560749815445785198[6] = 1;
   out_7560749815445785198[7] = 0;
   out_7560749815445785198[8] = 0;
   out_7560749815445785198[9] = 1;
   out_7560749815445785198[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_7603906676528442007) {
   out_7603906676528442007[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_8038884862828261433) {
   out_8038884862828261433[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[6] = 0;
   out_8038884862828261433[7] = 1;
   out_8038884862828261433[8] = 0;
   out_8038884862828261433[9] = 0;
   out_8038884862828261433[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_7603906676528442007) {
   out_7603906676528442007[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_8038884862828261433) {
   out_8038884862828261433[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_8038884862828261433[6] = 0;
   out_8038884862828261433[7] = 1;
   out_8038884862828261433[8] = 0;
   out_8038884862828261433[9] = 0;
   out_8038884862828261433[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_6740791193231733360) {
  err_fun(nom_x, delta_x, out_6740791193231733360);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_5435998030533772419) {
  inv_err_fun(nom_x, true_x, out_5435998030533772419);
}
void gnss_H_mod_fun(double *state, double *out_8750904480143678209) {
  H_mod_fun(state, out_8750904480143678209);
}
void gnss_f_fun(double *state, double dt, double *out_571033032076185663) {
  f_fun(state,  dt, out_571033032076185663);
}
void gnss_F_fun(double *state, double dt, double *out_8071961880976414619) {
  F_fun(state,  dt, out_8071961880976414619);
}
void gnss_h_6(double *state, double *sat_pos, double *out_3924727623087114070) {
  h_6(state, sat_pos, out_3924727623087114070);
}
void gnss_H_6(double *state, double *sat_pos, double *out_3168437365824362595) {
  H_6(state, sat_pos, out_3168437365824362595);
}
void gnss_h_20(double *state, double *sat_pos, double *out_7434817830173438872) {
  h_20(state, sat_pos, out_7434817830173438872);
}
void gnss_H_20(double *state, double *sat_pos, double *out_7560749815445785198) {
  H_20(state, sat_pos, out_7560749815445785198);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7603906676528442007) {
  h_7(state, sat_pos_vel, out_7603906676528442007);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_8038884862828261433) {
  H_7(state, sat_pos_vel, out_8038884862828261433);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7603906676528442007) {
  h_21(state, sat_pos_vel, out_7603906676528442007);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_8038884862828261433) {
  H_21(state, sat_pos_vel, out_8038884862828261433);
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
