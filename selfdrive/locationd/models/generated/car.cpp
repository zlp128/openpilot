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
void err_fun(double *nom_x, double *delta_x, double *out_6258559787192254109) {
   out_6258559787192254109[0] = delta_x[0] + nom_x[0];
   out_6258559787192254109[1] = delta_x[1] + nom_x[1];
   out_6258559787192254109[2] = delta_x[2] + nom_x[2];
   out_6258559787192254109[3] = delta_x[3] + nom_x[3];
   out_6258559787192254109[4] = delta_x[4] + nom_x[4];
   out_6258559787192254109[5] = delta_x[5] + nom_x[5];
   out_6258559787192254109[6] = delta_x[6] + nom_x[6];
   out_6258559787192254109[7] = delta_x[7] + nom_x[7];
   out_6258559787192254109[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8483442434741396819) {
   out_8483442434741396819[0] = -nom_x[0] + true_x[0];
   out_8483442434741396819[1] = -nom_x[1] + true_x[1];
   out_8483442434741396819[2] = -nom_x[2] + true_x[2];
   out_8483442434741396819[3] = -nom_x[3] + true_x[3];
   out_8483442434741396819[4] = -nom_x[4] + true_x[4];
   out_8483442434741396819[5] = -nom_x[5] + true_x[5];
   out_8483442434741396819[6] = -nom_x[6] + true_x[6];
   out_8483442434741396819[7] = -nom_x[7] + true_x[7];
   out_8483442434741396819[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_317258154932342734) {
   out_317258154932342734[0] = 1.0;
   out_317258154932342734[1] = 0;
   out_317258154932342734[2] = 0;
   out_317258154932342734[3] = 0;
   out_317258154932342734[4] = 0;
   out_317258154932342734[5] = 0;
   out_317258154932342734[6] = 0;
   out_317258154932342734[7] = 0;
   out_317258154932342734[8] = 0;
   out_317258154932342734[9] = 0;
   out_317258154932342734[10] = 1.0;
   out_317258154932342734[11] = 0;
   out_317258154932342734[12] = 0;
   out_317258154932342734[13] = 0;
   out_317258154932342734[14] = 0;
   out_317258154932342734[15] = 0;
   out_317258154932342734[16] = 0;
   out_317258154932342734[17] = 0;
   out_317258154932342734[18] = 0;
   out_317258154932342734[19] = 0;
   out_317258154932342734[20] = 1.0;
   out_317258154932342734[21] = 0;
   out_317258154932342734[22] = 0;
   out_317258154932342734[23] = 0;
   out_317258154932342734[24] = 0;
   out_317258154932342734[25] = 0;
   out_317258154932342734[26] = 0;
   out_317258154932342734[27] = 0;
   out_317258154932342734[28] = 0;
   out_317258154932342734[29] = 0;
   out_317258154932342734[30] = 1.0;
   out_317258154932342734[31] = 0;
   out_317258154932342734[32] = 0;
   out_317258154932342734[33] = 0;
   out_317258154932342734[34] = 0;
   out_317258154932342734[35] = 0;
   out_317258154932342734[36] = 0;
   out_317258154932342734[37] = 0;
   out_317258154932342734[38] = 0;
   out_317258154932342734[39] = 0;
   out_317258154932342734[40] = 1.0;
   out_317258154932342734[41] = 0;
   out_317258154932342734[42] = 0;
   out_317258154932342734[43] = 0;
   out_317258154932342734[44] = 0;
   out_317258154932342734[45] = 0;
   out_317258154932342734[46] = 0;
   out_317258154932342734[47] = 0;
   out_317258154932342734[48] = 0;
   out_317258154932342734[49] = 0;
   out_317258154932342734[50] = 1.0;
   out_317258154932342734[51] = 0;
   out_317258154932342734[52] = 0;
   out_317258154932342734[53] = 0;
   out_317258154932342734[54] = 0;
   out_317258154932342734[55] = 0;
   out_317258154932342734[56] = 0;
   out_317258154932342734[57] = 0;
   out_317258154932342734[58] = 0;
   out_317258154932342734[59] = 0;
   out_317258154932342734[60] = 1.0;
   out_317258154932342734[61] = 0;
   out_317258154932342734[62] = 0;
   out_317258154932342734[63] = 0;
   out_317258154932342734[64] = 0;
   out_317258154932342734[65] = 0;
   out_317258154932342734[66] = 0;
   out_317258154932342734[67] = 0;
   out_317258154932342734[68] = 0;
   out_317258154932342734[69] = 0;
   out_317258154932342734[70] = 1.0;
   out_317258154932342734[71] = 0;
   out_317258154932342734[72] = 0;
   out_317258154932342734[73] = 0;
   out_317258154932342734[74] = 0;
   out_317258154932342734[75] = 0;
   out_317258154932342734[76] = 0;
   out_317258154932342734[77] = 0;
   out_317258154932342734[78] = 0;
   out_317258154932342734[79] = 0;
   out_317258154932342734[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5753327761686972465) {
   out_5753327761686972465[0] = state[0];
   out_5753327761686972465[1] = state[1];
   out_5753327761686972465[2] = state[2];
   out_5753327761686972465[3] = state[3];
   out_5753327761686972465[4] = state[4];
   out_5753327761686972465[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5753327761686972465[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5753327761686972465[7] = state[7];
   out_5753327761686972465[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8289678864136186323) {
   out_8289678864136186323[0] = 1;
   out_8289678864136186323[1] = 0;
   out_8289678864136186323[2] = 0;
   out_8289678864136186323[3] = 0;
   out_8289678864136186323[4] = 0;
   out_8289678864136186323[5] = 0;
   out_8289678864136186323[6] = 0;
   out_8289678864136186323[7] = 0;
   out_8289678864136186323[8] = 0;
   out_8289678864136186323[9] = 0;
   out_8289678864136186323[10] = 1;
   out_8289678864136186323[11] = 0;
   out_8289678864136186323[12] = 0;
   out_8289678864136186323[13] = 0;
   out_8289678864136186323[14] = 0;
   out_8289678864136186323[15] = 0;
   out_8289678864136186323[16] = 0;
   out_8289678864136186323[17] = 0;
   out_8289678864136186323[18] = 0;
   out_8289678864136186323[19] = 0;
   out_8289678864136186323[20] = 1;
   out_8289678864136186323[21] = 0;
   out_8289678864136186323[22] = 0;
   out_8289678864136186323[23] = 0;
   out_8289678864136186323[24] = 0;
   out_8289678864136186323[25] = 0;
   out_8289678864136186323[26] = 0;
   out_8289678864136186323[27] = 0;
   out_8289678864136186323[28] = 0;
   out_8289678864136186323[29] = 0;
   out_8289678864136186323[30] = 1;
   out_8289678864136186323[31] = 0;
   out_8289678864136186323[32] = 0;
   out_8289678864136186323[33] = 0;
   out_8289678864136186323[34] = 0;
   out_8289678864136186323[35] = 0;
   out_8289678864136186323[36] = 0;
   out_8289678864136186323[37] = 0;
   out_8289678864136186323[38] = 0;
   out_8289678864136186323[39] = 0;
   out_8289678864136186323[40] = 1;
   out_8289678864136186323[41] = 0;
   out_8289678864136186323[42] = 0;
   out_8289678864136186323[43] = 0;
   out_8289678864136186323[44] = 0;
   out_8289678864136186323[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8289678864136186323[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8289678864136186323[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8289678864136186323[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8289678864136186323[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8289678864136186323[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8289678864136186323[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8289678864136186323[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8289678864136186323[53] = -9.8000000000000007*dt;
   out_8289678864136186323[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8289678864136186323[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8289678864136186323[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8289678864136186323[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8289678864136186323[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8289678864136186323[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8289678864136186323[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8289678864136186323[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8289678864136186323[62] = 0;
   out_8289678864136186323[63] = 0;
   out_8289678864136186323[64] = 0;
   out_8289678864136186323[65] = 0;
   out_8289678864136186323[66] = 0;
   out_8289678864136186323[67] = 0;
   out_8289678864136186323[68] = 0;
   out_8289678864136186323[69] = 0;
   out_8289678864136186323[70] = 1;
   out_8289678864136186323[71] = 0;
   out_8289678864136186323[72] = 0;
   out_8289678864136186323[73] = 0;
   out_8289678864136186323[74] = 0;
   out_8289678864136186323[75] = 0;
   out_8289678864136186323[76] = 0;
   out_8289678864136186323[77] = 0;
   out_8289678864136186323[78] = 0;
   out_8289678864136186323[79] = 0;
   out_8289678864136186323[80] = 1;
}
void h_25(double *state, double *unused, double *out_5741342572066533641) {
   out_5741342572066533641[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1067105512112888160) {
   out_1067105512112888160[0] = 0;
   out_1067105512112888160[1] = 0;
   out_1067105512112888160[2] = 0;
   out_1067105512112888160[3] = 0;
   out_1067105512112888160[4] = 0;
   out_1067105512112888160[5] = 0;
   out_1067105512112888160[6] = 1;
   out_1067105512112888160[7] = 0;
   out_1067105512112888160[8] = 0;
}
void h_24(double *state, double *unused, double *out_3184705636802324409) {
   out_3184705636802324409[0] = state[4];
   out_3184705636802324409[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3679403814853620874) {
   out_3679403814853620874[0] = 0;
   out_3679403814853620874[1] = 0;
   out_3679403814853620874[2] = 0;
   out_3679403814853620874[3] = 0;
   out_3679403814853620874[4] = 1;
   out_3679403814853620874[5] = 0;
   out_3679403814853620874[6] = 0;
   out_3679403814853620874[7] = 0;
   out_3679403814853620874[8] = 0;
   out_3679403814853620874[9] = 0;
   out_3679403814853620874[10] = 0;
   out_3679403814853620874[11] = 0;
   out_3679403814853620874[12] = 0;
   out_3679403814853620874[13] = 0;
   out_3679403814853620874[14] = 1;
   out_3679403814853620874[15] = 0;
   out_3679403814853620874[16] = 0;
   out_3679403814853620874[17] = 0;
}
void h_30(double *state, double *unused, double *out_5619733767201413514) {
   out_5619733767201413514[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3585438470620136787) {
   out_3585438470620136787[0] = 0;
   out_3585438470620136787[1] = 0;
   out_3585438470620136787[2] = 0;
   out_3585438470620136787[3] = 0;
   out_3585438470620136787[4] = 1;
   out_3585438470620136787[5] = 0;
   out_3585438470620136787[6] = 0;
   out_3585438470620136787[7] = 0;
   out_3585438470620136787[8] = 0;
}
void h_26(double *state, double *unused, double *out_138251146792324442) {
   out_138251146792324442[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2674397806761168064) {
   out_2674397806761168064[0] = 0;
   out_2674397806761168064[1] = 0;
   out_2674397806761168064[2] = 0;
   out_2674397806761168064[3] = 0;
   out_2674397806761168064[4] = 0;
   out_2674397806761168064[5] = 0;
   out_2674397806761168064[6] = 0;
   out_2674397806761168064[7] = 1;
   out_2674397806761168064[8] = 0;
}
void h_27(double *state, double *unused, double *out_7703728233982172330) {
   out_7703728233982172330[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5809032541804080004) {
   out_5809032541804080004[0] = 0;
   out_5809032541804080004[1] = 0;
   out_5809032541804080004[2] = 0;
   out_5809032541804080004[3] = 1;
   out_5809032541804080004[4] = 0;
   out_5809032541804080004[5] = 0;
   out_5809032541804080004[6] = 0;
   out_5809032541804080004[7] = 0;
   out_5809032541804080004[8] = 0;
}
void h_29(double *state, double *unused, double *out_3842044757553670678) {
   out_3842044757553670678[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4095669814934528971) {
   out_4095669814934528971[0] = 0;
   out_4095669814934528971[1] = 1;
   out_4095669814934528971[2] = 0;
   out_4095669814934528971[3] = 0;
   out_4095669814934528971[4] = 0;
   out_4095669814934528971[5] = 0;
   out_4095669814934528971[6] = 0;
   out_4095669814934528971[7] = 0;
   out_4095669814934528971[8] = 0;
}
void h_28(double *state, double *unused, double *out_3081542204526064016) {
   out_3081542204526064016[0] = state[0];
}
void H_28(double *state, double *unused, double *out_986729202135001603) {
   out_986729202135001603[0] = 1;
   out_986729202135001603[1] = 0;
   out_986729202135001603[2] = 0;
   out_986729202135001603[3] = 0;
   out_986729202135001603[4] = 0;
   out_986729202135001603[5] = 0;
   out_986729202135001603[6] = 0;
   out_986729202135001603[7] = 0;
   out_986729202135001603[8] = 0;
}
void h_31(double *state, double *unused, double *out_2103893043812511291) {
   out_2103893043812511291[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1097751473989848588) {
   out_1097751473989848588[0] = 0;
   out_1097751473989848588[1] = 0;
   out_1097751473989848588[2] = 0;
   out_1097751473989848588[3] = 0;
   out_1097751473989848588[4] = 0;
   out_1097751473989848588[5] = 0;
   out_1097751473989848588[6] = 0;
   out_1097751473989848588[7] = 0;
   out_1097751473989848588[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6258559787192254109) {
  err_fun(nom_x, delta_x, out_6258559787192254109);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8483442434741396819) {
  inv_err_fun(nom_x, true_x, out_8483442434741396819);
}
void car_H_mod_fun(double *state, double *out_317258154932342734) {
  H_mod_fun(state, out_317258154932342734);
}
void car_f_fun(double *state, double dt, double *out_5753327761686972465) {
  f_fun(state,  dt, out_5753327761686972465);
}
void car_F_fun(double *state, double dt, double *out_8289678864136186323) {
  F_fun(state,  dt, out_8289678864136186323);
}
void car_h_25(double *state, double *unused, double *out_5741342572066533641) {
  h_25(state, unused, out_5741342572066533641);
}
void car_H_25(double *state, double *unused, double *out_1067105512112888160) {
  H_25(state, unused, out_1067105512112888160);
}
void car_h_24(double *state, double *unused, double *out_3184705636802324409) {
  h_24(state, unused, out_3184705636802324409);
}
void car_H_24(double *state, double *unused, double *out_3679403814853620874) {
  H_24(state, unused, out_3679403814853620874);
}
void car_h_30(double *state, double *unused, double *out_5619733767201413514) {
  h_30(state, unused, out_5619733767201413514);
}
void car_H_30(double *state, double *unused, double *out_3585438470620136787) {
  H_30(state, unused, out_3585438470620136787);
}
void car_h_26(double *state, double *unused, double *out_138251146792324442) {
  h_26(state, unused, out_138251146792324442);
}
void car_H_26(double *state, double *unused, double *out_2674397806761168064) {
  H_26(state, unused, out_2674397806761168064);
}
void car_h_27(double *state, double *unused, double *out_7703728233982172330) {
  h_27(state, unused, out_7703728233982172330);
}
void car_H_27(double *state, double *unused, double *out_5809032541804080004) {
  H_27(state, unused, out_5809032541804080004);
}
void car_h_29(double *state, double *unused, double *out_3842044757553670678) {
  h_29(state, unused, out_3842044757553670678);
}
void car_H_29(double *state, double *unused, double *out_4095669814934528971) {
  H_29(state, unused, out_4095669814934528971);
}
void car_h_28(double *state, double *unused, double *out_3081542204526064016) {
  h_28(state, unused, out_3081542204526064016);
}
void car_H_28(double *state, double *unused, double *out_986729202135001603) {
  H_28(state, unused, out_986729202135001603);
}
void car_h_31(double *state, double *unused, double *out_2103893043812511291) {
  h_31(state, unused, out_2103893043812511291);
}
void car_H_31(double *state, double *unused, double *out_1097751473989848588) {
  H_31(state, unused, out_1097751473989848588);
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
