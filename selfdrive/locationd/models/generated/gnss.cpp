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
void err_fun(double *nom_x, double *delta_x, double *out_4281415265925619745) {
   out_4281415265925619745[0] = delta_x[0] + nom_x[0];
   out_4281415265925619745[1] = delta_x[1] + nom_x[1];
   out_4281415265925619745[2] = delta_x[2] + nom_x[2];
   out_4281415265925619745[3] = delta_x[3] + nom_x[3];
   out_4281415265925619745[4] = delta_x[4] + nom_x[4];
   out_4281415265925619745[5] = delta_x[5] + nom_x[5];
   out_4281415265925619745[6] = delta_x[6] + nom_x[6];
   out_4281415265925619745[7] = delta_x[7] + nom_x[7];
   out_4281415265925619745[8] = delta_x[8] + nom_x[8];
   out_4281415265925619745[9] = delta_x[9] + nom_x[9];
   out_4281415265925619745[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8058048663833159220) {
   out_8058048663833159220[0] = -nom_x[0] + true_x[0];
   out_8058048663833159220[1] = -nom_x[1] + true_x[1];
   out_8058048663833159220[2] = -nom_x[2] + true_x[2];
   out_8058048663833159220[3] = -nom_x[3] + true_x[3];
   out_8058048663833159220[4] = -nom_x[4] + true_x[4];
   out_8058048663833159220[5] = -nom_x[5] + true_x[5];
   out_8058048663833159220[6] = -nom_x[6] + true_x[6];
   out_8058048663833159220[7] = -nom_x[7] + true_x[7];
   out_8058048663833159220[8] = -nom_x[8] + true_x[8];
   out_8058048663833159220[9] = -nom_x[9] + true_x[9];
   out_8058048663833159220[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_3690945488544052836) {
   out_3690945488544052836[0] = 1.0;
   out_3690945488544052836[1] = 0;
   out_3690945488544052836[2] = 0;
   out_3690945488544052836[3] = 0;
   out_3690945488544052836[4] = 0;
   out_3690945488544052836[5] = 0;
   out_3690945488544052836[6] = 0;
   out_3690945488544052836[7] = 0;
   out_3690945488544052836[8] = 0;
   out_3690945488544052836[9] = 0;
   out_3690945488544052836[10] = 0;
   out_3690945488544052836[11] = 0;
   out_3690945488544052836[12] = 1.0;
   out_3690945488544052836[13] = 0;
   out_3690945488544052836[14] = 0;
   out_3690945488544052836[15] = 0;
   out_3690945488544052836[16] = 0;
   out_3690945488544052836[17] = 0;
   out_3690945488544052836[18] = 0;
   out_3690945488544052836[19] = 0;
   out_3690945488544052836[20] = 0;
   out_3690945488544052836[21] = 0;
   out_3690945488544052836[22] = 0;
   out_3690945488544052836[23] = 0;
   out_3690945488544052836[24] = 1.0;
   out_3690945488544052836[25] = 0;
   out_3690945488544052836[26] = 0;
   out_3690945488544052836[27] = 0;
   out_3690945488544052836[28] = 0;
   out_3690945488544052836[29] = 0;
   out_3690945488544052836[30] = 0;
   out_3690945488544052836[31] = 0;
   out_3690945488544052836[32] = 0;
   out_3690945488544052836[33] = 0;
   out_3690945488544052836[34] = 0;
   out_3690945488544052836[35] = 0;
   out_3690945488544052836[36] = 1.0;
   out_3690945488544052836[37] = 0;
   out_3690945488544052836[38] = 0;
   out_3690945488544052836[39] = 0;
   out_3690945488544052836[40] = 0;
   out_3690945488544052836[41] = 0;
   out_3690945488544052836[42] = 0;
   out_3690945488544052836[43] = 0;
   out_3690945488544052836[44] = 0;
   out_3690945488544052836[45] = 0;
   out_3690945488544052836[46] = 0;
   out_3690945488544052836[47] = 0;
   out_3690945488544052836[48] = 1.0;
   out_3690945488544052836[49] = 0;
   out_3690945488544052836[50] = 0;
   out_3690945488544052836[51] = 0;
   out_3690945488544052836[52] = 0;
   out_3690945488544052836[53] = 0;
   out_3690945488544052836[54] = 0;
   out_3690945488544052836[55] = 0;
   out_3690945488544052836[56] = 0;
   out_3690945488544052836[57] = 0;
   out_3690945488544052836[58] = 0;
   out_3690945488544052836[59] = 0;
   out_3690945488544052836[60] = 1.0;
   out_3690945488544052836[61] = 0;
   out_3690945488544052836[62] = 0;
   out_3690945488544052836[63] = 0;
   out_3690945488544052836[64] = 0;
   out_3690945488544052836[65] = 0;
   out_3690945488544052836[66] = 0;
   out_3690945488544052836[67] = 0;
   out_3690945488544052836[68] = 0;
   out_3690945488544052836[69] = 0;
   out_3690945488544052836[70] = 0;
   out_3690945488544052836[71] = 0;
   out_3690945488544052836[72] = 1.0;
   out_3690945488544052836[73] = 0;
   out_3690945488544052836[74] = 0;
   out_3690945488544052836[75] = 0;
   out_3690945488544052836[76] = 0;
   out_3690945488544052836[77] = 0;
   out_3690945488544052836[78] = 0;
   out_3690945488544052836[79] = 0;
   out_3690945488544052836[80] = 0;
   out_3690945488544052836[81] = 0;
   out_3690945488544052836[82] = 0;
   out_3690945488544052836[83] = 0;
   out_3690945488544052836[84] = 1.0;
   out_3690945488544052836[85] = 0;
   out_3690945488544052836[86] = 0;
   out_3690945488544052836[87] = 0;
   out_3690945488544052836[88] = 0;
   out_3690945488544052836[89] = 0;
   out_3690945488544052836[90] = 0;
   out_3690945488544052836[91] = 0;
   out_3690945488544052836[92] = 0;
   out_3690945488544052836[93] = 0;
   out_3690945488544052836[94] = 0;
   out_3690945488544052836[95] = 0;
   out_3690945488544052836[96] = 1.0;
   out_3690945488544052836[97] = 0;
   out_3690945488544052836[98] = 0;
   out_3690945488544052836[99] = 0;
   out_3690945488544052836[100] = 0;
   out_3690945488544052836[101] = 0;
   out_3690945488544052836[102] = 0;
   out_3690945488544052836[103] = 0;
   out_3690945488544052836[104] = 0;
   out_3690945488544052836[105] = 0;
   out_3690945488544052836[106] = 0;
   out_3690945488544052836[107] = 0;
   out_3690945488544052836[108] = 1.0;
   out_3690945488544052836[109] = 0;
   out_3690945488544052836[110] = 0;
   out_3690945488544052836[111] = 0;
   out_3690945488544052836[112] = 0;
   out_3690945488544052836[113] = 0;
   out_3690945488544052836[114] = 0;
   out_3690945488544052836[115] = 0;
   out_3690945488544052836[116] = 0;
   out_3690945488544052836[117] = 0;
   out_3690945488544052836[118] = 0;
   out_3690945488544052836[119] = 0;
   out_3690945488544052836[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_2954456239899519205) {
   out_2954456239899519205[0] = dt*state[3] + state[0];
   out_2954456239899519205[1] = dt*state[4] + state[1];
   out_2954456239899519205[2] = dt*state[5] + state[2];
   out_2954456239899519205[3] = state[3];
   out_2954456239899519205[4] = state[4];
   out_2954456239899519205[5] = state[5];
   out_2954456239899519205[6] = dt*state[7] + state[6];
   out_2954456239899519205[7] = dt*state[8] + state[7];
   out_2954456239899519205[8] = state[8];
   out_2954456239899519205[9] = state[9];
   out_2954456239899519205[10] = state[10];
}
void F_fun(double *state, double dt, double *out_709514566261682476) {
   out_709514566261682476[0] = 1;
   out_709514566261682476[1] = 0;
   out_709514566261682476[2] = 0;
   out_709514566261682476[3] = dt;
   out_709514566261682476[4] = 0;
   out_709514566261682476[5] = 0;
   out_709514566261682476[6] = 0;
   out_709514566261682476[7] = 0;
   out_709514566261682476[8] = 0;
   out_709514566261682476[9] = 0;
   out_709514566261682476[10] = 0;
   out_709514566261682476[11] = 0;
   out_709514566261682476[12] = 1;
   out_709514566261682476[13] = 0;
   out_709514566261682476[14] = 0;
   out_709514566261682476[15] = dt;
   out_709514566261682476[16] = 0;
   out_709514566261682476[17] = 0;
   out_709514566261682476[18] = 0;
   out_709514566261682476[19] = 0;
   out_709514566261682476[20] = 0;
   out_709514566261682476[21] = 0;
   out_709514566261682476[22] = 0;
   out_709514566261682476[23] = 0;
   out_709514566261682476[24] = 1;
   out_709514566261682476[25] = 0;
   out_709514566261682476[26] = 0;
   out_709514566261682476[27] = dt;
   out_709514566261682476[28] = 0;
   out_709514566261682476[29] = 0;
   out_709514566261682476[30] = 0;
   out_709514566261682476[31] = 0;
   out_709514566261682476[32] = 0;
   out_709514566261682476[33] = 0;
   out_709514566261682476[34] = 0;
   out_709514566261682476[35] = 0;
   out_709514566261682476[36] = 1;
   out_709514566261682476[37] = 0;
   out_709514566261682476[38] = 0;
   out_709514566261682476[39] = 0;
   out_709514566261682476[40] = 0;
   out_709514566261682476[41] = 0;
   out_709514566261682476[42] = 0;
   out_709514566261682476[43] = 0;
   out_709514566261682476[44] = 0;
   out_709514566261682476[45] = 0;
   out_709514566261682476[46] = 0;
   out_709514566261682476[47] = 0;
   out_709514566261682476[48] = 1;
   out_709514566261682476[49] = 0;
   out_709514566261682476[50] = 0;
   out_709514566261682476[51] = 0;
   out_709514566261682476[52] = 0;
   out_709514566261682476[53] = 0;
   out_709514566261682476[54] = 0;
   out_709514566261682476[55] = 0;
   out_709514566261682476[56] = 0;
   out_709514566261682476[57] = 0;
   out_709514566261682476[58] = 0;
   out_709514566261682476[59] = 0;
   out_709514566261682476[60] = 1;
   out_709514566261682476[61] = 0;
   out_709514566261682476[62] = 0;
   out_709514566261682476[63] = 0;
   out_709514566261682476[64] = 0;
   out_709514566261682476[65] = 0;
   out_709514566261682476[66] = 0;
   out_709514566261682476[67] = 0;
   out_709514566261682476[68] = 0;
   out_709514566261682476[69] = 0;
   out_709514566261682476[70] = 0;
   out_709514566261682476[71] = 0;
   out_709514566261682476[72] = 1;
   out_709514566261682476[73] = dt;
   out_709514566261682476[74] = 0;
   out_709514566261682476[75] = 0;
   out_709514566261682476[76] = 0;
   out_709514566261682476[77] = 0;
   out_709514566261682476[78] = 0;
   out_709514566261682476[79] = 0;
   out_709514566261682476[80] = 0;
   out_709514566261682476[81] = 0;
   out_709514566261682476[82] = 0;
   out_709514566261682476[83] = 0;
   out_709514566261682476[84] = 1;
   out_709514566261682476[85] = dt;
   out_709514566261682476[86] = 0;
   out_709514566261682476[87] = 0;
   out_709514566261682476[88] = 0;
   out_709514566261682476[89] = 0;
   out_709514566261682476[90] = 0;
   out_709514566261682476[91] = 0;
   out_709514566261682476[92] = 0;
   out_709514566261682476[93] = 0;
   out_709514566261682476[94] = 0;
   out_709514566261682476[95] = 0;
   out_709514566261682476[96] = 1;
   out_709514566261682476[97] = 0;
   out_709514566261682476[98] = 0;
   out_709514566261682476[99] = 0;
   out_709514566261682476[100] = 0;
   out_709514566261682476[101] = 0;
   out_709514566261682476[102] = 0;
   out_709514566261682476[103] = 0;
   out_709514566261682476[104] = 0;
   out_709514566261682476[105] = 0;
   out_709514566261682476[106] = 0;
   out_709514566261682476[107] = 0;
   out_709514566261682476[108] = 1;
   out_709514566261682476[109] = 0;
   out_709514566261682476[110] = 0;
   out_709514566261682476[111] = 0;
   out_709514566261682476[112] = 0;
   out_709514566261682476[113] = 0;
   out_709514566261682476[114] = 0;
   out_709514566261682476[115] = 0;
   out_709514566261682476[116] = 0;
   out_709514566261682476[117] = 0;
   out_709514566261682476[118] = 0;
   out_709514566261682476[119] = 0;
   out_709514566261682476[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_2648966289655583926) {
   out_2648966289655583926[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_1516634108393932450) {
   out_1516634108393932450[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1516634108393932450[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1516634108393932450[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1516634108393932450[3] = 0;
   out_1516634108393932450[4] = 0;
   out_1516634108393932450[5] = 0;
   out_1516634108393932450[6] = 1;
   out_1516634108393932450[7] = 0;
   out_1516634108393932450[8] = 0;
   out_1516634108393932450[9] = 0;
   out_1516634108393932450[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_1322673160422067744) {
   out_1322673160422067744[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_6746823634573947585) {
   out_6746823634573947585[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6746823634573947585[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6746823634573947585[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6746823634573947585[3] = 0;
   out_6746823634573947585[4] = 0;
   out_6746823634573947585[5] = 0;
   out_6746823634573947585[6] = 1;
   out_6746823634573947585[7] = 0;
   out_6746823634573947585[8] = 0;
   out_6746823634573947585[9] = 1;
   out_6746823634573947585[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_3768133833178917308) {
   out_3768133833178917308[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_6978532755514735815) {
   out_6978532755514735815[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[6] = 0;
   out_6978532755514735815[7] = 1;
   out_6978532755514735815[8] = 0;
   out_6978532755514735815[9] = 0;
   out_6978532755514735815[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_3768133833178917308) {
   out_3768133833178917308[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_6978532755514735815) {
   out_6978532755514735815[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6978532755514735815[6] = 0;
   out_6978532755514735815[7] = 1;
   out_6978532755514735815[8] = 0;
   out_6978532755514735815[9] = 0;
   out_6978532755514735815[10] = 0;
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
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4281415265925619745) {
  err_fun(nom_x, delta_x, out_4281415265925619745);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_8058048663833159220) {
  inv_err_fun(nom_x, true_x, out_8058048663833159220);
}
void gnss_H_mod_fun(double *state, double *out_3690945488544052836) {
  H_mod_fun(state, out_3690945488544052836);
}
void gnss_f_fun(double *state, double dt, double *out_2954456239899519205) {
  f_fun(state,  dt, out_2954456239899519205);
}
void gnss_F_fun(double *state, double dt, double *out_709514566261682476) {
  F_fun(state,  dt, out_709514566261682476);
}
void gnss_h_6(double *state, double *sat_pos, double *out_2648966289655583926) {
  h_6(state, sat_pos, out_2648966289655583926);
}
void gnss_H_6(double *state, double *sat_pos, double *out_1516634108393932450) {
  H_6(state, sat_pos, out_1516634108393932450);
}
void gnss_h_20(double *state, double *sat_pos, double *out_1322673160422067744) {
  h_20(state, sat_pos, out_1322673160422067744);
}
void gnss_H_20(double *state, double *sat_pos, double *out_6746823634573947585) {
  H_20(state, sat_pos, out_6746823634573947585);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_3768133833178917308) {
  h_7(state, sat_pos_vel, out_3768133833178917308);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_6978532755514735815) {
  H_7(state, sat_pos_vel, out_6978532755514735815);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_3768133833178917308) {
  h_21(state, sat_pos_vel, out_3768133833178917308);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_6978532755514735815) {
  H_21(state, sat_pos_vel, out_6978532755514735815);
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
