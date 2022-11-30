#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with sympy 1.9                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7743502251243671447) {
   out_7743502251243671447[0] = delta_x[0] + nom_x[0];
   out_7743502251243671447[1] = delta_x[1] + nom_x[1];
   out_7743502251243671447[2] = delta_x[2] + nom_x[2];
   out_7743502251243671447[3] = delta_x[3] + nom_x[3];
   out_7743502251243671447[4] = delta_x[4] + nom_x[4];
   out_7743502251243671447[5] = delta_x[5] + nom_x[5];
   out_7743502251243671447[6] = delta_x[6] + nom_x[6];
   out_7743502251243671447[7] = delta_x[7] + nom_x[7];
   out_7743502251243671447[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8632432640030731669) {
   out_8632432640030731669[0] = -nom_x[0] + true_x[0];
   out_8632432640030731669[1] = -nom_x[1] + true_x[1];
   out_8632432640030731669[2] = -nom_x[2] + true_x[2];
   out_8632432640030731669[3] = -nom_x[3] + true_x[3];
   out_8632432640030731669[4] = -nom_x[4] + true_x[4];
   out_8632432640030731669[5] = -nom_x[5] + true_x[5];
   out_8632432640030731669[6] = -nom_x[6] + true_x[6];
   out_8632432640030731669[7] = -nom_x[7] + true_x[7];
   out_8632432640030731669[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6955983744751080330) {
   out_6955983744751080330[0] = 1.0;
   out_6955983744751080330[1] = 0;
   out_6955983744751080330[2] = 0;
   out_6955983744751080330[3] = 0;
   out_6955983744751080330[4] = 0;
   out_6955983744751080330[5] = 0;
   out_6955983744751080330[6] = 0;
   out_6955983744751080330[7] = 0;
   out_6955983744751080330[8] = 0;
   out_6955983744751080330[9] = 0;
   out_6955983744751080330[10] = 1.0;
   out_6955983744751080330[11] = 0;
   out_6955983744751080330[12] = 0;
   out_6955983744751080330[13] = 0;
   out_6955983744751080330[14] = 0;
   out_6955983744751080330[15] = 0;
   out_6955983744751080330[16] = 0;
   out_6955983744751080330[17] = 0;
   out_6955983744751080330[18] = 0;
   out_6955983744751080330[19] = 0;
   out_6955983744751080330[20] = 1.0;
   out_6955983744751080330[21] = 0;
   out_6955983744751080330[22] = 0;
   out_6955983744751080330[23] = 0;
   out_6955983744751080330[24] = 0;
   out_6955983744751080330[25] = 0;
   out_6955983744751080330[26] = 0;
   out_6955983744751080330[27] = 0;
   out_6955983744751080330[28] = 0;
   out_6955983744751080330[29] = 0;
   out_6955983744751080330[30] = 1.0;
   out_6955983744751080330[31] = 0;
   out_6955983744751080330[32] = 0;
   out_6955983744751080330[33] = 0;
   out_6955983744751080330[34] = 0;
   out_6955983744751080330[35] = 0;
   out_6955983744751080330[36] = 0;
   out_6955983744751080330[37] = 0;
   out_6955983744751080330[38] = 0;
   out_6955983744751080330[39] = 0;
   out_6955983744751080330[40] = 1.0;
   out_6955983744751080330[41] = 0;
   out_6955983744751080330[42] = 0;
   out_6955983744751080330[43] = 0;
   out_6955983744751080330[44] = 0;
   out_6955983744751080330[45] = 0;
   out_6955983744751080330[46] = 0;
   out_6955983744751080330[47] = 0;
   out_6955983744751080330[48] = 0;
   out_6955983744751080330[49] = 0;
   out_6955983744751080330[50] = 1.0;
   out_6955983744751080330[51] = 0;
   out_6955983744751080330[52] = 0;
   out_6955983744751080330[53] = 0;
   out_6955983744751080330[54] = 0;
   out_6955983744751080330[55] = 0;
   out_6955983744751080330[56] = 0;
   out_6955983744751080330[57] = 0;
   out_6955983744751080330[58] = 0;
   out_6955983744751080330[59] = 0;
   out_6955983744751080330[60] = 1.0;
   out_6955983744751080330[61] = 0;
   out_6955983744751080330[62] = 0;
   out_6955983744751080330[63] = 0;
   out_6955983744751080330[64] = 0;
   out_6955983744751080330[65] = 0;
   out_6955983744751080330[66] = 0;
   out_6955983744751080330[67] = 0;
   out_6955983744751080330[68] = 0;
   out_6955983744751080330[69] = 0;
   out_6955983744751080330[70] = 1.0;
   out_6955983744751080330[71] = 0;
   out_6955983744751080330[72] = 0;
   out_6955983744751080330[73] = 0;
   out_6955983744751080330[74] = 0;
   out_6955983744751080330[75] = 0;
   out_6955983744751080330[76] = 0;
   out_6955983744751080330[77] = 0;
   out_6955983744751080330[78] = 0;
   out_6955983744751080330[79] = 0;
   out_6955983744751080330[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1057256165937700131) {
   out_1057256165937700131[0] = state[0];
   out_1057256165937700131[1] = state[1];
   out_1057256165937700131[2] = state[2];
   out_1057256165937700131[3] = state[3];
   out_1057256165937700131[4] = state[4];
   out_1057256165937700131[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1057256165937700131[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1057256165937700131[7] = state[7];
   out_1057256165937700131[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2042254547319901591) {
   out_2042254547319901591[0] = 1;
   out_2042254547319901591[1] = 0;
   out_2042254547319901591[2] = 0;
   out_2042254547319901591[3] = 0;
   out_2042254547319901591[4] = 0;
   out_2042254547319901591[5] = 0;
   out_2042254547319901591[6] = 0;
   out_2042254547319901591[7] = 0;
   out_2042254547319901591[8] = 0;
   out_2042254547319901591[9] = 0;
   out_2042254547319901591[10] = 1;
   out_2042254547319901591[11] = 0;
   out_2042254547319901591[12] = 0;
   out_2042254547319901591[13] = 0;
   out_2042254547319901591[14] = 0;
   out_2042254547319901591[15] = 0;
   out_2042254547319901591[16] = 0;
   out_2042254547319901591[17] = 0;
   out_2042254547319901591[18] = 0;
   out_2042254547319901591[19] = 0;
   out_2042254547319901591[20] = 1;
   out_2042254547319901591[21] = 0;
   out_2042254547319901591[22] = 0;
   out_2042254547319901591[23] = 0;
   out_2042254547319901591[24] = 0;
   out_2042254547319901591[25] = 0;
   out_2042254547319901591[26] = 0;
   out_2042254547319901591[27] = 0;
   out_2042254547319901591[28] = 0;
   out_2042254547319901591[29] = 0;
   out_2042254547319901591[30] = 1;
   out_2042254547319901591[31] = 0;
   out_2042254547319901591[32] = 0;
   out_2042254547319901591[33] = 0;
   out_2042254547319901591[34] = 0;
   out_2042254547319901591[35] = 0;
   out_2042254547319901591[36] = 0;
   out_2042254547319901591[37] = 0;
   out_2042254547319901591[38] = 0;
   out_2042254547319901591[39] = 0;
   out_2042254547319901591[40] = 1;
   out_2042254547319901591[41] = 0;
   out_2042254547319901591[42] = 0;
   out_2042254547319901591[43] = 0;
   out_2042254547319901591[44] = 0;
   out_2042254547319901591[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2042254547319901591[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2042254547319901591[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2042254547319901591[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2042254547319901591[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2042254547319901591[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2042254547319901591[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2042254547319901591[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2042254547319901591[53] = -9.8000000000000007*dt;
   out_2042254547319901591[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2042254547319901591[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2042254547319901591[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2042254547319901591[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2042254547319901591[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2042254547319901591[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2042254547319901591[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2042254547319901591[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2042254547319901591[62] = 0;
   out_2042254547319901591[63] = 0;
   out_2042254547319901591[64] = 0;
   out_2042254547319901591[65] = 0;
   out_2042254547319901591[66] = 0;
   out_2042254547319901591[67] = 0;
   out_2042254547319901591[68] = 0;
   out_2042254547319901591[69] = 0;
   out_2042254547319901591[70] = 1;
   out_2042254547319901591[71] = 0;
   out_2042254547319901591[72] = 0;
   out_2042254547319901591[73] = 0;
   out_2042254547319901591[74] = 0;
   out_2042254547319901591[75] = 0;
   out_2042254547319901591[76] = 0;
   out_2042254547319901591[77] = 0;
   out_2042254547319901591[78] = 0;
   out_2042254547319901591[79] = 0;
   out_2042254547319901591[80] = 1;
}
void h_25(double *state, double *unused, double *out_9038137973563738704) {
   out_9038137973563738704[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6219790086191979796) {
   out_6219790086191979796[0] = 0;
   out_6219790086191979796[1] = 0;
   out_6219790086191979796[2] = 0;
   out_6219790086191979796[3] = 0;
   out_6219790086191979796[4] = 0;
   out_6219790086191979796[5] = 0;
   out_6219790086191979796[6] = 1;
   out_6219790086191979796[7] = 0;
   out_6219790086191979796[8] = 0;
}
void h_24(double *state, double *unused, double *out_8933773235415263694) {
   out_8933773235415263694[0] = state[4];
   out_8933773235415263694[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2661864487389656660) {
   out_2661864487389656660[0] = 0;
   out_2661864487389656660[1] = 0;
   out_2661864487389656660[2] = 0;
   out_2661864487389656660[3] = 0;
   out_2661864487389656660[4] = 1;
   out_2661864487389656660[5] = 0;
   out_2661864487389656660[6] = 0;
   out_2661864487389656660[7] = 0;
   out_2661864487389656660[8] = 0;
   out_2661864487389656660[9] = 0;
   out_2661864487389656660[10] = 0;
   out_2661864487389656660[11] = 0;
   out_2661864487389656660[12] = 0;
   out_2661864487389656660[13] = 0;
   out_2661864487389656660[14] = 1;
   out_2661864487389656660[15] = 0;
   out_2661864487389656660[16] = 0;
   out_2661864487389656660[17] = 0;
}
void h_30(double *state, double *unused, double *out_1353345261140371077) {
   out_1353345261140371077[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3701457127684731169) {
   out_3701457127684731169[0] = 0;
   out_3701457127684731169[1] = 0;
   out_3701457127684731169[2] = 0;
   out_3701457127684731169[3] = 0;
   out_3701457127684731169[4] = 1;
   out_3701457127684731169[5] = 0;
   out_3701457127684731169[6] = 0;
   out_3701457127684731169[7] = 0;
   out_3701457127684731169[8] = 0;
}
void h_26(double *state, double *unused, double *out_3791544801975276460) {
   out_3791544801975276460[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8485450668643515596) {
   out_8485450668643515596[0] = 0;
   out_8485450668643515596[1] = 0;
   out_8485450668643515596[2] = 0;
   out_8485450668643515596[3] = 0;
   out_8485450668643515596[4] = 0;
   out_8485450668643515596[5] = 0;
   out_8485450668643515596[6] = 0;
   out_8485450668643515596[7] = 1;
   out_8485450668643515596[8] = 0;
}
void h_27(double *state, double *unused, double *out_4406932832484967267) {
   out_4406932832484967267[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5876220439485156080) {
   out_5876220439485156080[0] = 0;
   out_5876220439485156080[1] = 0;
   out_5876220439485156080[2] = 0;
   out_5876220439485156080[3] = 1;
   out_5876220439485156080[4] = 0;
   out_5876220439485156080[5] = 0;
   out_5876220439485156080[6] = 0;
   out_5876220439485156080[7] = 0;
   out_5876220439485156080[8] = 0;
}
void h_29(double *state, double *unused, double *out_6276545984403911908) {
   out_6276545984403911908[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3191225783370338985) {
   out_3191225783370338985[0] = 0;
   out_3191225783370338985[1] = 1;
   out_3191225783370338985[2] = 0;
   out_3191225783370338985[3] = 0;
   out_3191225783370338985[4] = 0;
   out_3191225783370338985[5] = 0;
   out_3191225783370338985[6] = 0;
   out_3191225783370338985[7] = 0;
   out_3191225783370338985[8] = 0;
}
void h_28(double *state, double *unused, double *out_7011338153293664918) {
   out_7011338153293664918[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8273624800439869559) {
   out_8273624800439869559[0] = 1;
   out_8273624800439869559[1] = 0;
   out_8273624800439869559[2] = 0;
   out_8273624800439869559[3] = 0;
   out_8273624800439869559[4] = 0;
   out_8273624800439869559[5] = 0;
   out_8273624800439869559[6] = 0;
   out_8273624800439869559[7] = 0;
   out_8273624800439869559[8] = 0;
}
void h_31(double *state, double *unused, double *out_8647698245415467134) {
   out_8647698245415467134[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7859242566410164120) {
   out_7859242566410164120[0] = 0;
   out_7859242566410164120[1] = 0;
   out_7859242566410164120[2] = 0;
   out_7859242566410164120[3] = 0;
   out_7859242566410164120[4] = 0;
   out_7859242566410164120[5] = 0;
   out_7859242566410164120[6] = 0;
   out_7859242566410164120[7] = 0;
   out_7859242566410164120[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7743502251243671447) {
  err_fun(nom_x, delta_x, out_7743502251243671447);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8632432640030731669) {
  inv_err_fun(nom_x, true_x, out_8632432640030731669);
}
void car_H_mod_fun(double *state, double *out_6955983744751080330) {
  H_mod_fun(state, out_6955983744751080330);
}
void car_f_fun(double *state, double dt, double *out_1057256165937700131) {
  f_fun(state,  dt, out_1057256165937700131);
}
void car_F_fun(double *state, double dt, double *out_2042254547319901591) {
  F_fun(state,  dt, out_2042254547319901591);
}
void car_h_25(double *state, double *unused, double *out_9038137973563738704) {
  h_25(state, unused, out_9038137973563738704);
}
void car_H_25(double *state, double *unused, double *out_6219790086191979796) {
  H_25(state, unused, out_6219790086191979796);
}
void car_h_24(double *state, double *unused, double *out_8933773235415263694) {
  h_24(state, unused, out_8933773235415263694);
}
void car_H_24(double *state, double *unused, double *out_2661864487389656660) {
  H_24(state, unused, out_2661864487389656660);
}
void car_h_30(double *state, double *unused, double *out_1353345261140371077) {
  h_30(state, unused, out_1353345261140371077);
}
void car_H_30(double *state, double *unused, double *out_3701457127684731169) {
  H_30(state, unused, out_3701457127684731169);
}
void car_h_26(double *state, double *unused, double *out_3791544801975276460) {
  h_26(state, unused, out_3791544801975276460);
}
void car_H_26(double *state, double *unused, double *out_8485450668643515596) {
  H_26(state, unused, out_8485450668643515596);
}
void car_h_27(double *state, double *unused, double *out_4406932832484967267) {
  h_27(state, unused, out_4406932832484967267);
}
void car_H_27(double *state, double *unused, double *out_5876220439485156080) {
  H_27(state, unused, out_5876220439485156080);
}
void car_h_29(double *state, double *unused, double *out_6276545984403911908) {
  h_29(state, unused, out_6276545984403911908);
}
void car_H_29(double *state, double *unused, double *out_3191225783370338985) {
  H_29(state, unused, out_3191225783370338985);
}
void car_h_28(double *state, double *unused, double *out_7011338153293664918) {
  h_28(state, unused, out_7011338153293664918);
}
void car_H_28(double *state, double *unused, double *out_8273624800439869559) {
  H_28(state, unused, out_8273624800439869559);
}
void car_h_31(double *state, double *unused, double *out_8647698245415467134) {
  h_31(state, unused, out_8647698245415467134);
}
void car_H_31(double *state, double *unused, double *out_7859242566410164120) {
  H_31(state, unused, out_7859242566410164120);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
