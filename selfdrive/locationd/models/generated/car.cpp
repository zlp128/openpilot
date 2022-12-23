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
void err_fun(double *nom_x, double *delta_x, double *out_8581923876106076715) {
   out_8581923876106076715[0] = delta_x[0] + nom_x[0];
   out_8581923876106076715[1] = delta_x[1] + nom_x[1];
   out_8581923876106076715[2] = delta_x[2] + nom_x[2];
   out_8581923876106076715[3] = delta_x[3] + nom_x[3];
   out_8581923876106076715[4] = delta_x[4] + nom_x[4];
   out_8581923876106076715[5] = delta_x[5] + nom_x[5];
   out_8581923876106076715[6] = delta_x[6] + nom_x[6];
   out_8581923876106076715[7] = delta_x[7] + nom_x[7];
   out_8581923876106076715[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4891521151268278961) {
   out_4891521151268278961[0] = -nom_x[0] + true_x[0];
   out_4891521151268278961[1] = -nom_x[1] + true_x[1];
   out_4891521151268278961[2] = -nom_x[2] + true_x[2];
   out_4891521151268278961[3] = -nom_x[3] + true_x[3];
   out_4891521151268278961[4] = -nom_x[4] + true_x[4];
   out_4891521151268278961[5] = -nom_x[5] + true_x[5];
   out_4891521151268278961[6] = -nom_x[6] + true_x[6];
   out_4891521151268278961[7] = -nom_x[7] + true_x[7];
   out_4891521151268278961[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6523549794488946483) {
   out_6523549794488946483[0] = 1.0;
   out_6523549794488946483[1] = 0;
   out_6523549794488946483[2] = 0;
   out_6523549794488946483[3] = 0;
   out_6523549794488946483[4] = 0;
   out_6523549794488946483[5] = 0;
   out_6523549794488946483[6] = 0;
   out_6523549794488946483[7] = 0;
   out_6523549794488946483[8] = 0;
   out_6523549794488946483[9] = 0;
   out_6523549794488946483[10] = 1.0;
   out_6523549794488946483[11] = 0;
   out_6523549794488946483[12] = 0;
   out_6523549794488946483[13] = 0;
   out_6523549794488946483[14] = 0;
   out_6523549794488946483[15] = 0;
   out_6523549794488946483[16] = 0;
   out_6523549794488946483[17] = 0;
   out_6523549794488946483[18] = 0;
   out_6523549794488946483[19] = 0;
   out_6523549794488946483[20] = 1.0;
   out_6523549794488946483[21] = 0;
   out_6523549794488946483[22] = 0;
   out_6523549794488946483[23] = 0;
   out_6523549794488946483[24] = 0;
   out_6523549794488946483[25] = 0;
   out_6523549794488946483[26] = 0;
   out_6523549794488946483[27] = 0;
   out_6523549794488946483[28] = 0;
   out_6523549794488946483[29] = 0;
   out_6523549794488946483[30] = 1.0;
   out_6523549794488946483[31] = 0;
   out_6523549794488946483[32] = 0;
   out_6523549794488946483[33] = 0;
   out_6523549794488946483[34] = 0;
   out_6523549794488946483[35] = 0;
   out_6523549794488946483[36] = 0;
   out_6523549794488946483[37] = 0;
   out_6523549794488946483[38] = 0;
   out_6523549794488946483[39] = 0;
   out_6523549794488946483[40] = 1.0;
   out_6523549794488946483[41] = 0;
   out_6523549794488946483[42] = 0;
   out_6523549794488946483[43] = 0;
   out_6523549794488946483[44] = 0;
   out_6523549794488946483[45] = 0;
   out_6523549794488946483[46] = 0;
   out_6523549794488946483[47] = 0;
   out_6523549794488946483[48] = 0;
   out_6523549794488946483[49] = 0;
   out_6523549794488946483[50] = 1.0;
   out_6523549794488946483[51] = 0;
   out_6523549794488946483[52] = 0;
   out_6523549794488946483[53] = 0;
   out_6523549794488946483[54] = 0;
   out_6523549794488946483[55] = 0;
   out_6523549794488946483[56] = 0;
   out_6523549794488946483[57] = 0;
   out_6523549794488946483[58] = 0;
   out_6523549794488946483[59] = 0;
   out_6523549794488946483[60] = 1.0;
   out_6523549794488946483[61] = 0;
   out_6523549794488946483[62] = 0;
   out_6523549794488946483[63] = 0;
   out_6523549794488946483[64] = 0;
   out_6523549794488946483[65] = 0;
   out_6523549794488946483[66] = 0;
   out_6523549794488946483[67] = 0;
   out_6523549794488946483[68] = 0;
   out_6523549794488946483[69] = 0;
   out_6523549794488946483[70] = 1.0;
   out_6523549794488946483[71] = 0;
   out_6523549794488946483[72] = 0;
   out_6523549794488946483[73] = 0;
   out_6523549794488946483[74] = 0;
   out_6523549794488946483[75] = 0;
   out_6523549794488946483[76] = 0;
   out_6523549794488946483[77] = 0;
   out_6523549794488946483[78] = 0;
   out_6523549794488946483[79] = 0;
   out_6523549794488946483[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3111820312432597939) {
   out_3111820312432597939[0] = state[0];
   out_3111820312432597939[1] = state[1];
   out_3111820312432597939[2] = state[2];
   out_3111820312432597939[3] = state[3];
   out_3111820312432597939[4] = state[4];
   out_3111820312432597939[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3111820312432597939[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3111820312432597939[7] = state[7];
   out_3111820312432597939[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5596968740727191559) {
   out_5596968740727191559[0] = 1;
   out_5596968740727191559[1] = 0;
   out_5596968740727191559[2] = 0;
   out_5596968740727191559[3] = 0;
   out_5596968740727191559[4] = 0;
   out_5596968740727191559[5] = 0;
   out_5596968740727191559[6] = 0;
   out_5596968740727191559[7] = 0;
   out_5596968740727191559[8] = 0;
   out_5596968740727191559[9] = 0;
   out_5596968740727191559[10] = 1;
   out_5596968740727191559[11] = 0;
   out_5596968740727191559[12] = 0;
   out_5596968740727191559[13] = 0;
   out_5596968740727191559[14] = 0;
   out_5596968740727191559[15] = 0;
   out_5596968740727191559[16] = 0;
   out_5596968740727191559[17] = 0;
   out_5596968740727191559[18] = 0;
   out_5596968740727191559[19] = 0;
   out_5596968740727191559[20] = 1;
   out_5596968740727191559[21] = 0;
   out_5596968740727191559[22] = 0;
   out_5596968740727191559[23] = 0;
   out_5596968740727191559[24] = 0;
   out_5596968740727191559[25] = 0;
   out_5596968740727191559[26] = 0;
   out_5596968740727191559[27] = 0;
   out_5596968740727191559[28] = 0;
   out_5596968740727191559[29] = 0;
   out_5596968740727191559[30] = 1;
   out_5596968740727191559[31] = 0;
   out_5596968740727191559[32] = 0;
   out_5596968740727191559[33] = 0;
   out_5596968740727191559[34] = 0;
   out_5596968740727191559[35] = 0;
   out_5596968740727191559[36] = 0;
   out_5596968740727191559[37] = 0;
   out_5596968740727191559[38] = 0;
   out_5596968740727191559[39] = 0;
   out_5596968740727191559[40] = 1;
   out_5596968740727191559[41] = 0;
   out_5596968740727191559[42] = 0;
   out_5596968740727191559[43] = 0;
   out_5596968740727191559[44] = 0;
   out_5596968740727191559[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5596968740727191559[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5596968740727191559[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5596968740727191559[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5596968740727191559[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5596968740727191559[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5596968740727191559[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5596968740727191559[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5596968740727191559[53] = -9.8000000000000007*dt;
   out_5596968740727191559[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5596968740727191559[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5596968740727191559[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5596968740727191559[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5596968740727191559[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5596968740727191559[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5596968740727191559[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5596968740727191559[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5596968740727191559[62] = 0;
   out_5596968740727191559[63] = 0;
   out_5596968740727191559[64] = 0;
   out_5596968740727191559[65] = 0;
   out_5596968740727191559[66] = 0;
   out_5596968740727191559[67] = 0;
   out_5596968740727191559[68] = 0;
   out_5596968740727191559[69] = 0;
   out_5596968740727191559[70] = 1;
   out_5596968740727191559[71] = 0;
   out_5596968740727191559[72] = 0;
   out_5596968740727191559[73] = 0;
   out_5596968740727191559[74] = 0;
   out_5596968740727191559[75] = 0;
   out_5596968740727191559[76] = 0;
   out_5596968740727191559[77] = 0;
   out_5596968740727191559[78] = 0;
   out_5596968740727191559[79] = 0;
   out_5596968740727191559[80] = 1;
}
void h_25(double *state, double *unused, double *out_8255502319032992897) {
   out_8255502319032992897[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8118118653173567889) {
   out_8118118653173567889[0] = 0;
   out_8118118653173567889[1] = 0;
   out_8118118653173567889[2] = 0;
   out_8118118653173567889[3] = 0;
   out_8118118653173567889[4] = 0;
   out_8118118653173567889[5] = 0;
   out_8118118653173567889[6] = 1;
   out_8118118653173567889[7] = 0;
   out_8118118653173567889[8] = 0;
}
void h_24(double *state, double *unused, double *out_5005612245441996689) {
   out_5005612245441996689[0] = state[4];
   out_5005612245441996689[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5892410869194699327) {
   out_5892410869194699327[0] = 0;
   out_5892410869194699327[1] = 0;
   out_5892410869194699327[2] = 0;
   out_5892410869194699327[3] = 0;
   out_5892410869194699327[4] = 1;
   out_5892410869194699327[5] = 0;
   out_5892410869194699327[6] = 0;
   out_5892410869194699327[7] = 0;
   out_5892410869194699327[8] = 0;
   out_5892410869194699327[9] = 0;
   out_5892410869194699327[10] = 0;
   out_5892410869194699327[11] = 0;
   out_5892410869194699327[12] = 0;
   out_5892410869194699327[13] = 0;
   out_5892410869194699327[14] = 1;
   out_5892410869194699327[15] = 0;
   out_5892410869194699327[16] = 0;
   out_5892410869194699327[17] = 0;
}
void h_30(double *state, double *unused, double *out_3420406528326207783) {
   out_3420406528326207783[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1201428311681951134) {
   out_1201428311681951134[0] = 0;
   out_1201428311681951134[1] = 0;
   out_1201428311681951134[2] = 0;
   out_1201428311681951134[3] = 0;
   out_1201428311681951134[4] = 1;
   out_1201428311681951134[5] = 0;
   out_1201428311681951134[6] = 0;
   out_1201428311681951134[7] = 0;
   out_1201428311681951134[8] = 0;
}
void h_26(double *state, double *unused, double *out_1805500687509117164) {
   out_1805500687509117164[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6587122101661927503) {
   out_6587122101661927503[0] = 0;
   out_6587122101661927503[1] = 0;
   out_6587122101661927503[2] = 0;
   out_6587122101661927503[3] = 0;
   out_6587122101661927503[4] = 0;
   out_6587122101661927503[5] = 0;
   out_6587122101661927503[6] = 0;
   out_6587122101661927503[7] = 1;
   out_6587122101661927503[8] = 0;
}
void h_27(double *state, double *unused, double *out_9023497953600416982) {
   out_9023497953600416982[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3376191623482376045) {
   out_3376191623482376045[0] = 0;
   out_3376191623482376045[1] = 0;
   out_3376191623482376045[2] = 0;
   out_3376191623482376045[3] = 1;
   out_3376191623482376045[4] = 0;
   out_3376191623482376045[5] = 0;
   out_3376191623482376045[6] = 0;
   out_3376191623482376045[7] = 0;
   out_3376191623482376045[8] = 0;
}
void h_29(double *state, double *unused, double *out_9148052057824628745) {
   out_9148052057824628745[0] = state[1];
}
void H_29(double *state, double *unused, double *out_691196967367558950) {
   out_691196967367558950[0] = 0;
   out_691196967367558950[1] = 1;
   out_691196967367558950[2] = 0;
   out_691196967367558950[3] = 0;
   out_691196967367558950[4] = 0;
   out_691196967367558950[5] = 0;
   out_691196967367558950[6] = 0;
   out_691196967367558950[7] = 0;
   out_691196967367558950[8] = 0;
}
void h_28(double *state, double *unused, double *out_402702707668658192) {
   out_402702707668658192[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5773595984437089524) {
   out_5773595984437089524[0] = 1;
   out_5773595984437089524[1] = 0;
   out_5773595984437089524[2] = 0;
   out_5773595984437089524[3] = 0;
   out_5773595984437089524[4] = 0;
   out_5773595984437089524[5] = 0;
   out_5773595984437089524[6] = 0;
   out_5773595984437089524[7] = 0;
   out_5773595984437089524[8] = 0;
}
void h_31(double *state, double *unused, double *out_6661654130949307838) {
   out_6661654130949307838[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8087472691296607461) {
   out_8087472691296607461[0] = 0;
   out_8087472691296607461[1] = 0;
   out_8087472691296607461[2] = 0;
   out_8087472691296607461[3] = 0;
   out_8087472691296607461[4] = 0;
   out_8087472691296607461[5] = 0;
   out_8087472691296607461[6] = 0;
   out_8087472691296607461[7] = 0;
   out_8087472691296607461[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8581923876106076715) {
  err_fun(nom_x, delta_x, out_8581923876106076715);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4891521151268278961) {
  inv_err_fun(nom_x, true_x, out_4891521151268278961);
}
void car_H_mod_fun(double *state, double *out_6523549794488946483) {
  H_mod_fun(state, out_6523549794488946483);
}
void car_f_fun(double *state, double dt, double *out_3111820312432597939) {
  f_fun(state,  dt, out_3111820312432597939);
}
void car_F_fun(double *state, double dt, double *out_5596968740727191559) {
  F_fun(state,  dt, out_5596968740727191559);
}
void car_h_25(double *state, double *unused, double *out_8255502319032992897) {
  h_25(state, unused, out_8255502319032992897);
}
void car_H_25(double *state, double *unused, double *out_8118118653173567889) {
  H_25(state, unused, out_8118118653173567889);
}
void car_h_24(double *state, double *unused, double *out_5005612245441996689) {
  h_24(state, unused, out_5005612245441996689);
}
void car_H_24(double *state, double *unused, double *out_5892410869194699327) {
  H_24(state, unused, out_5892410869194699327);
}
void car_h_30(double *state, double *unused, double *out_3420406528326207783) {
  h_30(state, unused, out_3420406528326207783);
}
void car_H_30(double *state, double *unused, double *out_1201428311681951134) {
  H_30(state, unused, out_1201428311681951134);
}
void car_h_26(double *state, double *unused, double *out_1805500687509117164) {
  h_26(state, unused, out_1805500687509117164);
}
void car_H_26(double *state, double *unused, double *out_6587122101661927503) {
  H_26(state, unused, out_6587122101661927503);
}
void car_h_27(double *state, double *unused, double *out_9023497953600416982) {
  h_27(state, unused, out_9023497953600416982);
}
void car_H_27(double *state, double *unused, double *out_3376191623482376045) {
  H_27(state, unused, out_3376191623482376045);
}
void car_h_29(double *state, double *unused, double *out_9148052057824628745) {
  h_29(state, unused, out_9148052057824628745);
}
void car_H_29(double *state, double *unused, double *out_691196967367558950) {
  H_29(state, unused, out_691196967367558950);
}
void car_h_28(double *state, double *unused, double *out_402702707668658192) {
  h_28(state, unused, out_402702707668658192);
}
void car_H_28(double *state, double *unused, double *out_5773595984437089524) {
  H_28(state, unused, out_5773595984437089524);
}
void car_h_31(double *state, double *unused, double *out_6661654130949307838) {
  h_31(state, unused, out_6661654130949307838);
}
void car_H_31(double *state, double *unused, double *out_8087472691296607461) {
  H_31(state, unused, out_8087472691296607461);
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
