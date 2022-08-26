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
void err_fun(double *nom_x, double *delta_x, double *out_729362937437787457) {
   out_729362937437787457[0] = delta_x[0] + nom_x[0];
   out_729362937437787457[1] = delta_x[1] + nom_x[1];
   out_729362937437787457[2] = delta_x[2] + nom_x[2];
   out_729362937437787457[3] = delta_x[3] + nom_x[3];
   out_729362937437787457[4] = delta_x[4] + nom_x[4];
   out_729362937437787457[5] = delta_x[5] + nom_x[5];
   out_729362937437787457[6] = delta_x[6] + nom_x[6];
   out_729362937437787457[7] = delta_x[7] + nom_x[7];
   out_729362937437787457[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4929143687762803407) {
   out_4929143687762803407[0] = -nom_x[0] + true_x[0];
   out_4929143687762803407[1] = -nom_x[1] + true_x[1];
   out_4929143687762803407[2] = -nom_x[2] + true_x[2];
   out_4929143687762803407[3] = -nom_x[3] + true_x[3];
   out_4929143687762803407[4] = -nom_x[4] + true_x[4];
   out_4929143687762803407[5] = -nom_x[5] + true_x[5];
   out_4929143687762803407[6] = -nom_x[6] + true_x[6];
   out_4929143687762803407[7] = -nom_x[7] + true_x[7];
   out_4929143687762803407[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8315888887196402654) {
   out_8315888887196402654[0] = 1.0;
   out_8315888887196402654[1] = 0;
   out_8315888887196402654[2] = 0;
   out_8315888887196402654[3] = 0;
   out_8315888887196402654[4] = 0;
   out_8315888887196402654[5] = 0;
   out_8315888887196402654[6] = 0;
   out_8315888887196402654[7] = 0;
   out_8315888887196402654[8] = 0;
   out_8315888887196402654[9] = 0;
   out_8315888887196402654[10] = 1.0;
   out_8315888887196402654[11] = 0;
   out_8315888887196402654[12] = 0;
   out_8315888887196402654[13] = 0;
   out_8315888887196402654[14] = 0;
   out_8315888887196402654[15] = 0;
   out_8315888887196402654[16] = 0;
   out_8315888887196402654[17] = 0;
   out_8315888887196402654[18] = 0;
   out_8315888887196402654[19] = 0;
   out_8315888887196402654[20] = 1.0;
   out_8315888887196402654[21] = 0;
   out_8315888887196402654[22] = 0;
   out_8315888887196402654[23] = 0;
   out_8315888887196402654[24] = 0;
   out_8315888887196402654[25] = 0;
   out_8315888887196402654[26] = 0;
   out_8315888887196402654[27] = 0;
   out_8315888887196402654[28] = 0;
   out_8315888887196402654[29] = 0;
   out_8315888887196402654[30] = 1.0;
   out_8315888887196402654[31] = 0;
   out_8315888887196402654[32] = 0;
   out_8315888887196402654[33] = 0;
   out_8315888887196402654[34] = 0;
   out_8315888887196402654[35] = 0;
   out_8315888887196402654[36] = 0;
   out_8315888887196402654[37] = 0;
   out_8315888887196402654[38] = 0;
   out_8315888887196402654[39] = 0;
   out_8315888887196402654[40] = 1.0;
   out_8315888887196402654[41] = 0;
   out_8315888887196402654[42] = 0;
   out_8315888887196402654[43] = 0;
   out_8315888887196402654[44] = 0;
   out_8315888887196402654[45] = 0;
   out_8315888887196402654[46] = 0;
   out_8315888887196402654[47] = 0;
   out_8315888887196402654[48] = 0;
   out_8315888887196402654[49] = 0;
   out_8315888887196402654[50] = 1.0;
   out_8315888887196402654[51] = 0;
   out_8315888887196402654[52] = 0;
   out_8315888887196402654[53] = 0;
   out_8315888887196402654[54] = 0;
   out_8315888887196402654[55] = 0;
   out_8315888887196402654[56] = 0;
   out_8315888887196402654[57] = 0;
   out_8315888887196402654[58] = 0;
   out_8315888887196402654[59] = 0;
   out_8315888887196402654[60] = 1.0;
   out_8315888887196402654[61] = 0;
   out_8315888887196402654[62] = 0;
   out_8315888887196402654[63] = 0;
   out_8315888887196402654[64] = 0;
   out_8315888887196402654[65] = 0;
   out_8315888887196402654[66] = 0;
   out_8315888887196402654[67] = 0;
   out_8315888887196402654[68] = 0;
   out_8315888887196402654[69] = 0;
   out_8315888887196402654[70] = 1.0;
   out_8315888887196402654[71] = 0;
   out_8315888887196402654[72] = 0;
   out_8315888887196402654[73] = 0;
   out_8315888887196402654[74] = 0;
   out_8315888887196402654[75] = 0;
   out_8315888887196402654[76] = 0;
   out_8315888887196402654[77] = 0;
   out_8315888887196402654[78] = 0;
   out_8315888887196402654[79] = 0;
   out_8315888887196402654[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7554938137534762046) {
   out_7554938137534762046[0] = state[0];
   out_7554938137534762046[1] = state[1];
   out_7554938137534762046[2] = state[2];
   out_7554938137534762046[3] = state[3];
   out_7554938137534762046[4] = state[4];
   out_7554938137534762046[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7554938137534762046[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7554938137534762046[7] = state[7];
   out_7554938137534762046[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6130812160595680525) {
   out_6130812160595680525[0] = 1;
   out_6130812160595680525[1] = 0;
   out_6130812160595680525[2] = 0;
   out_6130812160595680525[3] = 0;
   out_6130812160595680525[4] = 0;
   out_6130812160595680525[5] = 0;
   out_6130812160595680525[6] = 0;
   out_6130812160595680525[7] = 0;
   out_6130812160595680525[8] = 0;
   out_6130812160595680525[9] = 0;
   out_6130812160595680525[10] = 1;
   out_6130812160595680525[11] = 0;
   out_6130812160595680525[12] = 0;
   out_6130812160595680525[13] = 0;
   out_6130812160595680525[14] = 0;
   out_6130812160595680525[15] = 0;
   out_6130812160595680525[16] = 0;
   out_6130812160595680525[17] = 0;
   out_6130812160595680525[18] = 0;
   out_6130812160595680525[19] = 0;
   out_6130812160595680525[20] = 1;
   out_6130812160595680525[21] = 0;
   out_6130812160595680525[22] = 0;
   out_6130812160595680525[23] = 0;
   out_6130812160595680525[24] = 0;
   out_6130812160595680525[25] = 0;
   out_6130812160595680525[26] = 0;
   out_6130812160595680525[27] = 0;
   out_6130812160595680525[28] = 0;
   out_6130812160595680525[29] = 0;
   out_6130812160595680525[30] = 1;
   out_6130812160595680525[31] = 0;
   out_6130812160595680525[32] = 0;
   out_6130812160595680525[33] = 0;
   out_6130812160595680525[34] = 0;
   out_6130812160595680525[35] = 0;
   out_6130812160595680525[36] = 0;
   out_6130812160595680525[37] = 0;
   out_6130812160595680525[38] = 0;
   out_6130812160595680525[39] = 0;
   out_6130812160595680525[40] = 1;
   out_6130812160595680525[41] = 0;
   out_6130812160595680525[42] = 0;
   out_6130812160595680525[43] = 0;
   out_6130812160595680525[44] = 0;
   out_6130812160595680525[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6130812160595680525[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6130812160595680525[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6130812160595680525[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6130812160595680525[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6130812160595680525[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6130812160595680525[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6130812160595680525[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6130812160595680525[53] = -9.8000000000000007*dt;
   out_6130812160595680525[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6130812160595680525[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6130812160595680525[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6130812160595680525[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6130812160595680525[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6130812160595680525[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6130812160595680525[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6130812160595680525[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6130812160595680525[62] = 0;
   out_6130812160595680525[63] = 0;
   out_6130812160595680525[64] = 0;
   out_6130812160595680525[65] = 0;
   out_6130812160595680525[66] = 0;
   out_6130812160595680525[67] = 0;
   out_6130812160595680525[68] = 0;
   out_6130812160595680525[69] = 0;
   out_6130812160595680525[70] = 1;
   out_6130812160595680525[71] = 0;
   out_6130812160595680525[72] = 0;
   out_6130812160595680525[73] = 0;
   out_6130812160595680525[74] = 0;
   out_6130812160595680525[75] = 0;
   out_6130812160595680525[76] = 0;
   out_6130812160595680525[77] = 0;
   out_6130812160595680525[78] = 0;
   out_6130812160595680525[79] = 0;
   out_6130812160595680525[80] = 1;
}
void h_25(double *state, double *unused, double *out_8951477070372806105) {
   out_8951477070372806105[0] = state[6];
}
void H_25(double *state, double *unused, double *out_9087508506817314964) {
   out_9087508506817314964[0] = 0;
   out_9087508506817314964[1] = 0;
   out_9087508506817314964[2] = 0;
   out_9087508506817314964[3] = 0;
   out_9087508506817314964[4] = 0;
   out_9087508506817314964[5] = 0;
   out_9087508506817314964[6] = 1;
   out_9087508506817314964[7] = 0;
   out_9087508506817314964[8] = 0;
}
void h_24(double *state, double *unused, double *out_4067561432286125622) {
   out_4067561432286125622[0] = state[4];
   out_4067561432286125622[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1669116873140388071) {
   out_1669116873140388071[0] = 0;
   out_1669116873140388071[1] = 0;
   out_1669116873140388071[2] = 0;
   out_1669116873140388071[3] = 0;
   out_1669116873140388071[4] = 1;
   out_1669116873140388071[5] = 0;
   out_1669116873140388071[6] = 0;
   out_1669116873140388071[7] = 0;
   out_1669116873140388071[8] = 0;
   out_1669116873140388071[9] = 0;
   out_1669116873140388071[10] = 0;
   out_1669116873140388071[11] = 0;
   out_1669116873140388071[12] = 0;
   out_1669116873140388071[13] = 0;
   out_1669116873140388071[14] = 1;
   out_1669116873140388071[15] = 0;
   out_1669116873140388071[16] = 0;
   out_1669116873140388071[17] = 0;
}
void h_30(double *state, double *unused, double *out_7500845677743922938) {
   out_7500845677743922938[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4831539236764628454) {
   out_4831539236764628454[0] = 0;
   out_4831539236764628454[1] = 0;
   out_4831539236764628454[2] = 0;
   out_4831539236764628454[3] = 0;
   out_4831539236764628454[4] = 1;
   out_4831539236764628454[5] = 0;
   out_4831539236764628454[6] = 0;
   out_4831539236764628454[7] = 0;
   out_4831539236764628454[8] = 0;
}
void h_26(double *state, double *unused, double *out_8341493075156931027) {
   out_8341493075156931027[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5617732248018180428) {
   out_5617732248018180428[0] = 0;
   out_5617732248018180428[1] = 0;
   out_5617732248018180428[2] = 0;
   out_5617732248018180428[3] = 0;
   out_5617732248018180428[4] = 0;
   out_5617732248018180428[5] = 0;
   out_5617732248018180428[6] = 0;
   out_5617732248018180428[7] = 1;
   out_5617732248018180428[8] = 0;
}
void h_27(double *state, double *unused, double *out_5342806970691419479) {
   out_5342806970691419479[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2656775924964203543) {
   out_2656775924964203543[0] = 0;
   out_2656775924964203543[1] = 0;
   out_2656775924964203543[2] = 0;
   out_2656775924964203543[3] = 1;
   out_2656775924964203543[4] = 0;
   out_2656775924964203543[5] = 0;
   out_2656775924964203543[6] = 0;
   out_2656775924964203543[7] = 0;
   out_2656775924964203543[8] = 0;
}
void h_29(double *state, double *unused, double *out_2538465680062629706) {
   out_2538465680062629706[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5341770581079020638) {
   out_5341770581079020638[0] = 0;
   out_5341770581079020638[1] = 1;
   out_5341770581079020638[2] = 0;
   out_5341770581079020638[3] = 0;
   out_5341770581079020638[4] = 0;
   out_5341770581079020638[5] = 0;
   out_5341770581079020638[6] = 0;
   out_5341770581079020638[7] = 0;
   out_5341770581079020638[8] = 0;
}
void h_28(double *state, double *unused, double *out_572823783042442857) {
   out_572823783042442857[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7305400852644346889) {
   out_7305400852644346889[0] = 1;
   out_7305400852644346889[1] = 0;
   out_7305400852644346889[2] = 0;
   out_7305400852644346889[3] = 0;
   out_7305400852644346889[4] = 0;
   out_7305400852644346889[5] = 0;
   out_7305400852644346889[6] = 0;
   out_7305400852644346889[7] = 0;
   out_7305400852644346889[8] = 0;
}
void h_31(double *state, double *unused, double *out_8893848845723381957) {
   out_8893848845723381957[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4991524145784828952) {
   out_4991524145784828952[0] = 0;
   out_4991524145784828952[1] = 0;
   out_4991524145784828952[2] = 0;
   out_4991524145784828952[3] = 0;
   out_4991524145784828952[4] = 0;
   out_4991524145784828952[5] = 0;
   out_4991524145784828952[6] = 0;
   out_4991524145784828952[7] = 0;
   out_4991524145784828952[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_729362937437787457) {
  err_fun(nom_x, delta_x, out_729362937437787457);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4929143687762803407) {
  inv_err_fun(nom_x, true_x, out_4929143687762803407);
}
void car_H_mod_fun(double *state, double *out_8315888887196402654) {
  H_mod_fun(state, out_8315888887196402654);
}
void car_f_fun(double *state, double dt, double *out_7554938137534762046) {
  f_fun(state,  dt, out_7554938137534762046);
}
void car_F_fun(double *state, double dt, double *out_6130812160595680525) {
  F_fun(state,  dt, out_6130812160595680525);
}
void car_h_25(double *state, double *unused, double *out_8951477070372806105) {
  h_25(state, unused, out_8951477070372806105);
}
void car_H_25(double *state, double *unused, double *out_9087508506817314964) {
  H_25(state, unused, out_9087508506817314964);
}
void car_h_24(double *state, double *unused, double *out_4067561432286125622) {
  h_24(state, unused, out_4067561432286125622);
}
void car_H_24(double *state, double *unused, double *out_1669116873140388071) {
  H_24(state, unused, out_1669116873140388071);
}
void car_h_30(double *state, double *unused, double *out_7500845677743922938) {
  h_30(state, unused, out_7500845677743922938);
}
void car_H_30(double *state, double *unused, double *out_4831539236764628454) {
  H_30(state, unused, out_4831539236764628454);
}
void car_h_26(double *state, double *unused, double *out_8341493075156931027) {
  h_26(state, unused, out_8341493075156931027);
}
void car_H_26(double *state, double *unused, double *out_5617732248018180428) {
  H_26(state, unused, out_5617732248018180428);
}
void car_h_27(double *state, double *unused, double *out_5342806970691419479) {
  h_27(state, unused, out_5342806970691419479);
}
void car_H_27(double *state, double *unused, double *out_2656775924964203543) {
  H_27(state, unused, out_2656775924964203543);
}
void car_h_29(double *state, double *unused, double *out_2538465680062629706) {
  h_29(state, unused, out_2538465680062629706);
}
void car_H_29(double *state, double *unused, double *out_5341770581079020638) {
  H_29(state, unused, out_5341770581079020638);
}
void car_h_28(double *state, double *unused, double *out_572823783042442857) {
  h_28(state, unused, out_572823783042442857);
}
void car_H_28(double *state, double *unused, double *out_7305400852644346889) {
  H_28(state, unused, out_7305400852644346889);
}
void car_h_31(double *state, double *unused, double *out_8893848845723381957) {
  h_31(state, unused, out_8893848845723381957);
}
void car_H_31(double *state, double *unused, double *out_4991524145784828952) {
  H_31(state, unused, out_4991524145784828952);
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
