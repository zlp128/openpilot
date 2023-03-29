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
void err_fun(double *nom_x, double *delta_x, double *out_5634330020296848070) {
   out_5634330020296848070[0] = delta_x[0] + nom_x[0];
   out_5634330020296848070[1] = delta_x[1] + nom_x[1];
   out_5634330020296848070[2] = delta_x[2] + nom_x[2];
   out_5634330020296848070[3] = delta_x[3] + nom_x[3];
   out_5634330020296848070[4] = delta_x[4] + nom_x[4];
   out_5634330020296848070[5] = delta_x[5] + nom_x[5];
   out_5634330020296848070[6] = delta_x[6] + nom_x[6];
   out_5634330020296848070[7] = delta_x[7] + nom_x[7];
   out_5634330020296848070[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1061559027503315281) {
   out_1061559027503315281[0] = -nom_x[0] + true_x[0];
   out_1061559027503315281[1] = -nom_x[1] + true_x[1];
   out_1061559027503315281[2] = -nom_x[2] + true_x[2];
   out_1061559027503315281[3] = -nom_x[3] + true_x[3];
   out_1061559027503315281[4] = -nom_x[4] + true_x[4];
   out_1061559027503315281[5] = -nom_x[5] + true_x[5];
   out_1061559027503315281[6] = -nom_x[6] + true_x[6];
   out_1061559027503315281[7] = -nom_x[7] + true_x[7];
   out_1061559027503315281[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1567569310651922730) {
   out_1567569310651922730[0] = 1.0;
   out_1567569310651922730[1] = 0;
   out_1567569310651922730[2] = 0;
   out_1567569310651922730[3] = 0;
   out_1567569310651922730[4] = 0;
   out_1567569310651922730[5] = 0;
   out_1567569310651922730[6] = 0;
   out_1567569310651922730[7] = 0;
   out_1567569310651922730[8] = 0;
   out_1567569310651922730[9] = 0;
   out_1567569310651922730[10] = 1.0;
   out_1567569310651922730[11] = 0;
   out_1567569310651922730[12] = 0;
   out_1567569310651922730[13] = 0;
   out_1567569310651922730[14] = 0;
   out_1567569310651922730[15] = 0;
   out_1567569310651922730[16] = 0;
   out_1567569310651922730[17] = 0;
   out_1567569310651922730[18] = 0;
   out_1567569310651922730[19] = 0;
   out_1567569310651922730[20] = 1.0;
   out_1567569310651922730[21] = 0;
   out_1567569310651922730[22] = 0;
   out_1567569310651922730[23] = 0;
   out_1567569310651922730[24] = 0;
   out_1567569310651922730[25] = 0;
   out_1567569310651922730[26] = 0;
   out_1567569310651922730[27] = 0;
   out_1567569310651922730[28] = 0;
   out_1567569310651922730[29] = 0;
   out_1567569310651922730[30] = 1.0;
   out_1567569310651922730[31] = 0;
   out_1567569310651922730[32] = 0;
   out_1567569310651922730[33] = 0;
   out_1567569310651922730[34] = 0;
   out_1567569310651922730[35] = 0;
   out_1567569310651922730[36] = 0;
   out_1567569310651922730[37] = 0;
   out_1567569310651922730[38] = 0;
   out_1567569310651922730[39] = 0;
   out_1567569310651922730[40] = 1.0;
   out_1567569310651922730[41] = 0;
   out_1567569310651922730[42] = 0;
   out_1567569310651922730[43] = 0;
   out_1567569310651922730[44] = 0;
   out_1567569310651922730[45] = 0;
   out_1567569310651922730[46] = 0;
   out_1567569310651922730[47] = 0;
   out_1567569310651922730[48] = 0;
   out_1567569310651922730[49] = 0;
   out_1567569310651922730[50] = 1.0;
   out_1567569310651922730[51] = 0;
   out_1567569310651922730[52] = 0;
   out_1567569310651922730[53] = 0;
   out_1567569310651922730[54] = 0;
   out_1567569310651922730[55] = 0;
   out_1567569310651922730[56] = 0;
   out_1567569310651922730[57] = 0;
   out_1567569310651922730[58] = 0;
   out_1567569310651922730[59] = 0;
   out_1567569310651922730[60] = 1.0;
   out_1567569310651922730[61] = 0;
   out_1567569310651922730[62] = 0;
   out_1567569310651922730[63] = 0;
   out_1567569310651922730[64] = 0;
   out_1567569310651922730[65] = 0;
   out_1567569310651922730[66] = 0;
   out_1567569310651922730[67] = 0;
   out_1567569310651922730[68] = 0;
   out_1567569310651922730[69] = 0;
   out_1567569310651922730[70] = 1.0;
   out_1567569310651922730[71] = 0;
   out_1567569310651922730[72] = 0;
   out_1567569310651922730[73] = 0;
   out_1567569310651922730[74] = 0;
   out_1567569310651922730[75] = 0;
   out_1567569310651922730[76] = 0;
   out_1567569310651922730[77] = 0;
   out_1567569310651922730[78] = 0;
   out_1567569310651922730[79] = 0;
   out_1567569310651922730[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1208381054458531187) {
   out_1208381054458531187[0] = state[0];
   out_1208381054458531187[1] = state[1];
   out_1208381054458531187[2] = state[2];
   out_1208381054458531187[3] = state[3];
   out_1208381054458531187[4] = state[4];
   out_1208381054458531187[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1208381054458531187[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1208381054458531187[7] = state[7];
   out_1208381054458531187[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8824004521572161416) {
   out_8824004521572161416[0] = 1;
   out_8824004521572161416[1] = 0;
   out_8824004521572161416[2] = 0;
   out_8824004521572161416[3] = 0;
   out_8824004521572161416[4] = 0;
   out_8824004521572161416[5] = 0;
   out_8824004521572161416[6] = 0;
   out_8824004521572161416[7] = 0;
   out_8824004521572161416[8] = 0;
   out_8824004521572161416[9] = 0;
   out_8824004521572161416[10] = 1;
   out_8824004521572161416[11] = 0;
   out_8824004521572161416[12] = 0;
   out_8824004521572161416[13] = 0;
   out_8824004521572161416[14] = 0;
   out_8824004521572161416[15] = 0;
   out_8824004521572161416[16] = 0;
   out_8824004521572161416[17] = 0;
   out_8824004521572161416[18] = 0;
   out_8824004521572161416[19] = 0;
   out_8824004521572161416[20] = 1;
   out_8824004521572161416[21] = 0;
   out_8824004521572161416[22] = 0;
   out_8824004521572161416[23] = 0;
   out_8824004521572161416[24] = 0;
   out_8824004521572161416[25] = 0;
   out_8824004521572161416[26] = 0;
   out_8824004521572161416[27] = 0;
   out_8824004521572161416[28] = 0;
   out_8824004521572161416[29] = 0;
   out_8824004521572161416[30] = 1;
   out_8824004521572161416[31] = 0;
   out_8824004521572161416[32] = 0;
   out_8824004521572161416[33] = 0;
   out_8824004521572161416[34] = 0;
   out_8824004521572161416[35] = 0;
   out_8824004521572161416[36] = 0;
   out_8824004521572161416[37] = 0;
   out_8824004521572161416[38] = 0;
   out_8824004521572161416[39] = 0;
   out_8824004521572161416[40] = 1;
   out_8824004521572161416[41] = 0;
   out_8824004521572161416[42] = 0;
   out_8824004521572161416[43] = 0;
   out_8824004521572161416[44] = 0;
   out_8824004521572161416[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8824004521572161416[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8824004521572161416[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8824004521572161416[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8824004521572161416[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8824004521572161416[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8824004521572161416[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8824004521572161416[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8824004521572161416[53] = -9.8000000000000007*dt;
   out_8824004521572161416[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8824004521572161416[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8824004521572161416[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8824004521572161416[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8824004521572161416[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8824004521572161416[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8824004521572161416[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8824004521572161416[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8824004521572161416[62] = 0;
   out_8824004521572161416[63] = 0;
   out_8824004521572161416[64] = 0;
   out_8824004521572161416[65] = 0;
   out_8824004521572161416[66] = 0;
   out_8824004521572161416[67] = 0;
   out_8824004521572161416[68] = 0;
   out_8824004521572161416[69] = 0;
   out_8824004521572161416[70] = 1;
   out_8824004521572161416[71] = 0;
   out_8824004521572161416[72] = 0;
   out_8824004521572161416[73] = 0;
   out_8824004521572161416[74] = 0;
   out_8824004521572161416[75] = 0;
   out_8824004521572161416[76] = 0;
   out_8824004521572161416[77] = 0;
   out_8824004521572161416[78] = 0;
   out_8824004521572161416[79] = 0;
   out_8824004521572161416[80] = 1;
}
void h_25(double *state, double *unused, double *out_1789446864250922111) {
   out_1789446864250922111[0] = state[6];
}
void H_25(double *state, double *unused, double *out_9129886545195087354) {
   out_9129886545195087354[0] = 0;
   out_9129886545195087354[1] = 0;
   out_9129886545195087354[2] = 0;
   out_9129886545195087354[3] = 0;
   out_9129886545195087354[4] = 0;
   out_9129886545195087354[5] = 0;
   out_9129886545195087354[6] = 1;
   out_9129886545195087354[7] = 0;
   out_9129886545195087354[8] = 0;
}
void h_24(double *state, double *unused, double *out_3299160385053087312) {
   out_3299160385053087312[0] = state[4];
   out_3299160385053087312[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7144207929508964696) {
   out_7144207929508964696[0] = 0;
   out_7144207929508964696[1] = 0;
   out_7144207929508964696[2] = 0;
   out_7144207929508964696[3] = 0;
   out_7144207929508964696[4] = 1;
   out_7144207929508964696[5] = 0;
   out_7144207929508964696[6] = 0;
   out_7144207929508964696[7] = 0;
   out_7144207929508964696[8] = 0;
   out_7144207929508964696[9] = 0;
   out_7144207929508964696[10] = 0;
   out_7144207929508964696[11] = 0;
   out_7144207929508964696[12] = 0;
   out_7144207929508964696[13] = 0;
   out_7144207929508964696[14] = 1;
   out_7144207929508964696[15] = 0;
   out_7144207929508964696[16] = 0;
   out_7144207929508964696[17] = 0;
}
void h_30(double *state, double *unused, double *out_7348270420432929071) {
   out_7348270420432929071[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6611553586687838727) {
   out_6611553586687838727[0] = 0;
   out_6611553586687838727[1] = 0;
   out_6611553586687838727[2] = 0;
   out_6611553586687838727[3] = 0;
   out_6611553586687838727[4] = 1;
   out_6611553586687838727[5] = 0;
   out_6611553586687838727[6] = 0;
   out_6611553586687838727[7] = 0;
   out_6611553586687838727[8] = 0;
}
void h_26(double *state, double *unused, double *out_6096800385615776900) {
   out_6096800385615776900[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5575354209640408038) {
   out_5575354209640408038[0] = 0;
   out_5575354209640408038[1] = 0;
   out_5575354209640408038[2] = 0;
   out_5575354209640408038[3] = 0;
   out_5575354209640408038[4] = 0;
   out_5575354209640408038[5] = 0;
   out_5575354209640408038[6] = 0;
   out_5575354209640408038[7] = 1;
   out_5575354209640408038[8] = 0;
}
void h_27(double *state, double *unused, double *out_1247339187193410574) {
   out_1247339187193410574[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2614397886586431153) {
   out_2614397886586431153[0] = 0;
   out_2614397886586431153[1] = 0;
   out_2614397886586431153[2] = 0;
   out_2614397886586431153[3] = 1;
   out_2614397886586431153[4] = 0;
   out_2614397886586431153[5] = 0;
   out_2614397886586431153[6] = 0;
   out_2614397886586431153[7] = 0;
   out_2614397886586431153[8] = 0;
}
void h_29(double *state, double *unused, double *out_1705540549351972236) {
   out_1705540549351972236[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5299392542701248248) {
   out_5299392542701248248[0] = 0;
   out_5299392542701248248[1] = 1;
   out_5299392542701248248[2] = 0;
   out_5299392542701248248[3] = 0;
   out_5299392542701248248[4] = 0;
   out_5299392542701248248[5] = 0;
   out_5299392542701248248[6] = 0;
   out_5299392542701248248[7] = 0;
   out_5299392542701248248[8] = 0;
}
void h_28(double *state, double *unused, double *out_4170451758575142464) {
   out_4170451758575142464[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7263022814266574499) {
   out_7263022814266574499[0] = 1;
   out_7263022814266574499[1] = 0;
   out_7263022814266574499[2] = 0;
   out_7263022814266574499[3] = 0;
   out_7263022814266574499[4] = 0;
   out_7263022814266574499[5] = 0;
   out_7263022814266574499[6] = 0;
   out_7263022814266574499[7] = 0;
   out_7263022814266574499[8] = 0;
}
void h_31(double *state, double *unused, double *out_1514252801966416222) {
   out_1514252801966416222[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4949146107407056562) {
   out_4949146107407056562[0] = 0;
   out_4949146107407056562[1] = 0;
   out_4949146107407056562[2] = 0;
   out_4949146107407056562[3] = 0;
   out_4949146107407056562[4] = 0;
   out_4949146107407056562[5] = 0;
   out_4949146107407056562[6] = 0;
   out_4949146107407056562[7] = 0;
   out_4949146107407056562[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5634330020296848070) {
  err_fun(nom_x, delta_x, out_5634330020296848070);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1061559027503315281) {
  inv_err_fun(nom_x, true_x, out_1061559027503315281);
}
void car_H_mod_fun(double *state, double *out_1567569310651922730) {
  H_mod_fun(state, out_1567569310651922730);
}
void car_f_fun(double *state, double dt, double *out_1208381054458531187) {
  f_fun(state,  dt, out_1208381054458531187);
}
void car_F_fun(double *state, double dt, double *out_8824004521572161416) {
  F_fun(state,  dt, out_8824004521572161416);
}
void car_h_25(double *state, double *unused, double *out_1789446864250922111) {
  h_25(state, unused, out_1789446864250922111);
}
void car_H_25(double *state, double *unused, double *out_9129886545195087354) {
  H_25(state, unused, out_9129886545195087354);
}
void car_h_24(double *state, double *unused, double *out_3299160385053087312) {
  h_24(state, unused, out_3299160385053087312);
}
void car_H_24(double *state, double *unused, double *out_7144207929508964696) {
  H_24(state, unused, out_7144207929508964696);
}
void car_h_30(double *state, double *unused, double *out_7348270420432929071) {
  h_30(state, unused, out_7348270420432929071);
}
void car_H_30(double *state, double *unused, double *out_6611553586687838727) {
  H_30(state, unused, out_6611553586687838727);
}
void car_h_26(double *state, double *unused, double *out_6096800385615776900) {
  h_26(state, unused, out_6096800385615776900);
}
void car_H_26(double *state, double *unused, double *out_5575354209640408038) {
  H_26(state, unused, out_5575354209640408038);
}
void car_h_27(double *state, double *unused, double *out_1247339187193410574) {
  h_27(state, unused, out_1247339187193410574);
}
void car_H_27(double *state, double *unused, double *out_2614397886586431153) {
  H_27(state, unused, out_2614397886586431153);
}
void car_h_29(double *state, double *unused, double *out_1705540549351972236) {
  h_29(state, unused, out_1705540549351972236);
}
void car_H_29(double *state, double *unused, double *out_5299392542701248248) {
  H_29(state, unused, out_5299392542701248248);
}
void car_h_28(double *state, double *unused, double *out_4170451758575142464) {
  h_28(state, unused, out_4170451758575142464);
}
void car_H_28(double *state, double *unused, double *out_7263022814266574499) {
  H_28(state, unused, out_7263022814266574499);
}
void car_h_31(double *state, double *unused, double *out_1514252801966416222) {
  h_31(state, unused, out_1514252801966416222);
}
void car_H_31(double *state, double *unused, double *out_4949146107407056562) {
  H_31(state, unused, out_4949146107407056562);
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
