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
void err_fun(double *nom_x, double *delta_x, double *out_5232708683747839446) {
   out_5232708683747839446[0] = delta_x[0] + nom_x[0];
   out_5232708683747839446[1] = delta_x[1] + nom_x[1];
   out_5232708683747839446[2] = delta_x[2] + nom_x[2];
   out_5232708683747839446[3] = delta_x[3] + nom_x[3];
   out_5232708683747839446[4] = delta_x[4] + nom_x[4];
   out_5232708683747839446[5] = delta_x[5] + nom_x[5];
   out_5232708683747839446[6] = delta_x[6] + nom_x[6];
   out_5232708683747839446[7] = delta_x[7] + nom_x[7];
   out_5232708683747839446[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6273110318621425138) {
   out_6273110318621425138[0] = -nom_x[0] + true_x[0];
   out_6273110318621425138[1] = -nom_x[1] + true_x[1];
   out_6273110318621425138[2] = -nom_x[2] + true_x[2];
   out_6273110318621425138[3] = -nom_x[3] + true_x[3];
   out_6273110318621425138[4] = -nom_x[4] + true_x[4];
   out_6273110318621425138[5] = -nom_x[5] + true_x[5];
   out_6273110318621425138[6] = -nom_x[6] + true_x[6];
   out_6273110318621425138[7] = -nom_x[7] + true_x[7];
   out_6273110318621425138[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_376479380516898605) {
   out_376479380516898605[0] = 1.0;
   out_376479380516898605[1] = 0;
   out_376479380516898605[2] = 0;
   out_376479380516898605[3] = 0;
   out_376479380516898605[4] = 0;
   out_376479380516898605[5] = 0;
   out_376479380516898605[6] = 0;
   out_376479380516898605[7] = 0;
   out_376479380516898605[8] = 0;
   out_376479380516898605[9] = 0;
   out_376479380516898605[10] = 1.0;
   out_376479380516898605[11] = 0;
   out_376479380516898605[12] = 0;
   out_376479380516898605[13] = 0;
   out_376479380516898605[14] = 0;
   out_376479380516898605[15] = 0;
   out_376479380516898605[16] = 0;
   out_376479380516898605[17] = 0;
   out_376479380516898605[18] = 0;
   out_376479380516898605[19] = 0;
   out_376479380516898605[20] = 1.0;
   out_376479380516898605[21] = 0;
   out_376479380516898605[22] = 0;
   out_376479380516898605[23] = 0;
   out_376479380516898605[24] = 0;
   out_376479380516898605[25] = 0;
   out_376479380516898605[26] = 0;
   out_376479380516898605[27] = 0;
   out_376479380516898605[28] = 0;
   out_376479380516898605[29] = 0;
   out_376479380516898605[30] = 1.0;
   out_376479380516898605[31] = 0;
   out_376479380516898605[32] = 0;
   out_376479380516898605[33] = 0;
   out_376479380516898605[34] = 0;
   out_376479380516898605[35] = 0;
   out_376479380516898605[36] = 0;
   out_376479380516898605[37] = 0;
   out_376479380516898605[38] = 0;
   out_376479380516898605[39] = 0;
   out_376479380516898605[40] = 1.0;
   out_376479380516898605[41] = 0;
   out_376479380516898605[42] = 0;
   out_376479380516898605[43] = 0;
   out_376479380516898605[44] = 0;
   out_376479380516898605[45] = 0;
   out_376479380516898605[46] = 0;
   out_376479380516898605[47] = 0;
   out_376479380516898605[48] = 0;
   out_376479380516898605[49] = 0;
   out_376479380516898605[50] = 1.0;
   out_376479380516898605[51] = 0;
   out_376479380516898605[52] = 0;
   out_376479380516898605[53] = 0;
   out_376479380516898605[54] = 0;
   out_376479380516898605[55] = 0;
   out_376479380516898605[56] = 0;
   out_376479380516898605[57] = 0;
   out_376479380516898605[58] = 0;
   out_376479380516898605[59] = 0;
   out_376479380516898605[60] = 1.0;
   out_376479380516898605[61] = 0;
   out_376479380516898605[62] = 0;
   out_376479380516898605[63] = 0;
   out_376479380516898605[64] = 0;
   out_376479380516898605[65] = 0;
   out_376479380516898605[66] = 0;
   out_376479380516898605[67] = 0;
   out_376479380516898605[68] = 0;
   out_376479380516898605[69] = 0;
   out_376479380516898605[70] = 1.0;
   out_376479380516898605[71] = 0;
   out_376479380516898605[72] = 0;
   out_376479380516898605[73] = 0;
   out_376479380516898605[74] = 0;
   out_376479380516898605[75] = 0;
   out_376479380516898605[76] = 0;
   out_376479380516898605[77] = 0;
   out_376479380516898605[78] = 0;
   out_376479380516898605[79] = 0;
   out_376479380516898605[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7586787697879010325) {
   out_7586787697879010325[0] = state[0];
   out_7586787697879010325[1] = state[1];
   out_7586787697879010325[2] = state[2];
   out_7586787697879010325[3] = state[3];
   out_7586787697879010325[4] = state[4];
   out_7586787697879010325[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7586787697879010325[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7586787697879010325[7] = state[7];
   out_7586787697879010325[8] = state[8];
}
void F_fun(double *state, double dt, double *out_472790716300753243) {
   out_472790716300753243[0] = 1;
   out_472790716300753243[1] = 0;
   out_472790716300753243[2] = 0;
   out_472790716300753243[3] = 0;
   out_472790716300753243[4] = 0;
   out_472790716300753243[5] = 0;
   out_472790716300753243[6] = 0;
   out_472790716300753243[7] = 0;
   out_472790716300753243[8] = 0;
   out_472790716300753243[9] = 0;
   out_472790716300753243[10] = 1;
   out_472790716300753243[11] = 0;
   out_472790716300753243[12] = 0;
   out_472790716300753243[13] = 0;
   out_472790716300753243[14] = 0;
   out_472790716300753243[15] = 0;
   out_472790716300753243[16] = 0;
   out_472790716300753243[17] = 0;
   out_472790716300753243[18] = 0;
   out_472790716300753243[19] = 0;
   out_472790716300753243[20] = 1;
   out_472790716300753243[21] = 0;
   out_472790716300753243[22] = 0;
   out_472790716300753243[23] = 0;
   out_472790716300753243[24] = 0;
   out_472790716300753243[25] = 0;
   out_472790716300753243[26] = 0;
   out_472790716300753243[27] = 0;
   out_472790716300753243[28] = 0;
   out_472790716300753243[29] = 0;
   out_472790716300753243[30] = 1;
   out_472790716300753243[31] = 0;
   out_472790716300753243[32] = 0;
   out_472790716300753243[33] = 0;
   out_472790716300753243[34] = 0;
   out_472790716300753243[35] = 0;
   out_472790716300753243[36] = 0;
   out_472790716300753243[37] = 0;
   out_472790716300753243[38] = 0;
   out_472790716300753243[39] = 0;
   out_472790716300753243[40] = 1;
   out_472790716300753243[41] = 0;
   out_472790716300753243[42] = 0;
   out_472790716300753243[43] = 0;
   out_472790716300753243[44] = 0;
   out_472790716300753243[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_472790716300753243[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_472790716300753243[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_472790716300753243[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_472790716300753243[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_472790716300753243[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_472790716300753243[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_472790716300753243[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_472790716300753243[53] = -9.8000000000000007*dt;
   out_472790716300753243[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_472790716300753243[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_472790716300753243[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_472790716300753243[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_472790716300753243[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_472790716300753243[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_472790716300753243[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_472790716300753243[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_472790716300753243[62] = 0;
   out_472790716300753243[63] = 0;
   out_472790716300753243[64] = 0;
   out_472790716300753243[65] = 0;
   out_472790716300753243[66] = 0;
   out_472790716300753243[67] = 0;
   out_472790716300753243[68] = 0;
   out_472790716300753243[69] = 0;
   out_472790716300753243[70] = 1;
   out_472790716300753243[71] = 0;
   out_472790716300753243[72] = 0;
   out_472790716300753243[73] = 0;
   out_472790716300753243[74] = 0;
   out_472790716300753243[75] = 0;
   out_472790716300753243[76] = 0;
   out_472790716300753243[77] = 0;
   out_472790716300753243[78] = 0;
   out_472790716300753243[79] = 0;
   out_472790716300753243[80] = 1;
}
void h_25(double *state, double *unused, double *out_6846635756302794664) {
   out_6846635756302794664[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1681825998279428652) {
   out_1681825998279428652[0] = 0;
   out_1681825998279428652[1] = 0;
   out_1681825998279428652[2] = 0;
   out_1681825998279428652[3] = 0;
   out_1681825998279428652[4] = 0;
   out_1681825998279428652[5] = 0;
   out_1681825998279428652[6] = 1;
   out_1681825998279428652[7] = 0;
   out_1681825998279428652[8] = 0;
}
void h_24(double *state, double *unused, double *out_7639061379755997248) {
   out_7639061379755997248[0] = state[4];
   out_7639061379755997248[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4893745808312089449) {
   out_4893745808312089449[0] = 0;
   out_4893745808312089449[1] = 0;
   out_4893745808312089449[2] = 0;
   out_4893745808312089449[3] = 0;
   out_4893745808312089449[4] = 1;
   out_4893745808312089449[5] = 0;
   out_4893745808312089449[6] = 0;
   out_4893745808312089449[7] = 0;
   out_4893745808312089449[8] = 0;
   out_4893745808312089449[9] = 0;
   out_4893745808312089449[10] = 0;
   out_4893745808312089449[11] = 0;
   out_4893745808312089449[12] = 0;
   out_4893745808312089449[13] = 0;
   out_4893745808312089449[14] = 1;
   out_4893745808312089449[15] = 0;
   out_4893745808312089449[16] = 0;
   out_4893745808312089449[17] = 0;
}
void h_30(double *state, double *unused, double *out_2046273354615198377) {
   out_2046273354615198377[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5234864343212188103) {
   out_5234864343212188103[0] = 0;
   out_5234864343212188103[1] = 0;
   out_5234864343212188103[2] = 0;
   out_5234864343212188103[3] = 0;
   out_5234864343212188103[4] = 1;
   out_5234864343212188103[5] = 0;
   out_5234864343212188103[6] = 0;
   out_5234864343212188103[7] = 0;
   out_5234864343212188103[8] = 0;
}
void h_26(double *state, double *unused, double *out_4200177702844975091) {
   out_4200177702844975091[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5423329317153484876) {
   out_5423329317153484876[0] = 0;
   out_5423329317153484876[1] = 0;
   out_5423329317153484876[2] = 0;
   out_5423329317153484876[3] = 0;
   out_5423329317153484876[4] = 0;
   out_5423329317153484876[5] = 0;
   out_5423329317153484876[6] = 0;
   out_5423329317153484876[7] = 1;
   out_5423329317153484876[8] = 0;
}
void h_27(double *state, double *unused, double *out_6628820938264559055) {
   out_6628820938264559055[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3985928257223093633) {
   out_3985928257223093633[0] = 0;
   out_3985928257223093633[1] = 0;
   out_3985928257223093633[2] = 0;
   out_3985928257223093633[3] = 1;
   out_3985928257223093633[4] = 0;
   out_3985928257223093633[5] = 0;
   out_3985928257223093633[6] = 0;
   out_3985928257223093633[7] = 0;
   out_3985928257223093633[8] = 0;
}
void h_29(double *state, double *unused, double *out_1102763501713535942) {
   out_1102763501713535942[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5699290984092644666) {
   out_5699290984092644666[0] = 0;
   out_5699290984092644666[1] = 1;
   out_5699290984092644666[2] = 0;
   out_5699290984092644666[3] = 0;
   out_5699290984092644666[4] = 0;
   out_5699290984092644666[5] = 0;
   out_5699290984092644666[6] = 0;
   out_5699290984092644666[7] = 0;
   out_5699290984092644666[8] = 0;
}
void h_28(double *state, double *unused, double *out_6175193264364035726) {
   out_6175193264364035726[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3735660712527318415) {
   out_3735660712527318415[0] = 1;
   out_3735660712527318415[1] = 0;
   out_3735660712527318415[2] = 0;
   out_3735660712527318415[3] = 0;
   out_3735660712527318415[4] = 0;
   out_3735660712527318415[5] = 0;
   out_3735660712527318415[6] = 0;
   out_3735660712527318415[7] = 0;
   out_3735660712527318415[8] = 0;
}
void h_31(double *state, double *unused, double *out_3077779063232596577) {
   out_3077779063232596577[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1651180036402468224) {
   out_1651180036402468224[0] = 0;
   out_1651180036402468224[1] = 0;
   out_1651180036402468224[2] = 0;
   out_1651180036402468224[3] = 0;
   out_1651180036402468224[4] = 0;
   out_1651180036402468224[5] = 0;
   out_1651180036402468224[6] = 0;
   out_1651180036402468224[7] = 0;
   out_1651180036402468224[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5232708683747839446) {
  err_fun(nom_x, delta_x, out_5232708683747839446);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6273110318621425138) {
  inv_err_fun(nom_x, true_x, out_6273110318621425138);
}
void car_H_mod_fun(double *state, double *out_376479380516898605) {
  H_mod_fun(state, out_376479380516898605);
}
void car_f_fun(double *state, double dt, double *out_7586787697879010325) {
  f_fun(state,  dt, out_7586787697879010325);
}
void car_F_fun(double *state, double dt, double *out_472790716300753243) {
  F_fun(state,  dt, out_472790716300753243);
}
void car_h_25(double *state, double *unused, double *out_6846635756302794664) {
  h_25(state, unused, out_6846635756302794664);
}
void car_H_25(double *state, double *unused, double *out_1681825998279428652) {
  H_25(state, unused, out_1681825998279428652);
}
void car_h_24(double *state, double *unused, double *out_7639061379755997248) {
  h_24(state, unused, out_7639061379755997248);
}
void car_H_24(double *state, double *unused, double *out_4893745808312089449) {
  H_24(state, unused, out_4893745808312089449);
}
void car_h_30(double *state, double *unused, double *out_2046273354615198377) {
  h_30(state, unused, out_2046273354615198377);
}
void car_H_30(double *state, double *unused, double *out_5234864343212188103) {
  H_30(state, unused, out_5234864343212188103);
}
void car_h_26(double *state, double *unused, double *out_4200177702844975091) {
  h_26(state, unused, out_4200177702844975091);
}
void car_H_26(double *state, double *unused, double *out_5423329317153484876) {
  H_26(state, unused, out_5423329317153484876);
}
void car_h_27(double *state, double *unused, double *out_6628820938264559055) {
  h_27(state, unused, out_6628820938264559055);
}
void car_H_27(double *state, double *unused, double *out_3985928257223093633) {
  H_27(state, unused, out_3985928257223093633);
}
void car_h_29(double *state, double *unused, double *out_1102763501713535942) {
  h_29(state, unused, out_1102763501713535942);
}
void car_H_29(double *state, double *unused, double *out_5699290984092644666) {
  H_29(state, unused, out_5699290984092644666);
}
void car_h_28(double *state, double *unused, double *out_6175193264364035726) {
  h_28(state, unused, out_6175193264364035726);
}
void car_H_28(double *state, double *unused, double *out_3735660712527318415) {
  H_28(state, unused, out_3735660712527318415);
}
void car_h_31(double *state, double *unused, double *out_3077779063232596577) {
  h_31(state, unused, out_3077779063232596577);
}
void car_H_31(double *state, double *unused, double *out_1651180036402468224) {
  H_31(state, unused, out_1651180036402468224);
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
