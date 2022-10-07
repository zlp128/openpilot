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
void err_fun(double *nom_x, double *delta_x, double *out_5662953649758416364) {
   out_5662953649758416364[0] = delta_x[0] + nom_x[0];
   out_5662953649758416364[1] = delta_x[1] + nom_x[1];
   out_5662953649758416364[2] = delta_x[2] + nom_x[2];
   out_5662953649758416364[3] = delta_x[3] + nom_x[3];
   out_5662953649758416364[4] = delta_x[4] + nom_x[4];
   out_5662953649758416364[5] = delta_x[5] + nom_x[5];
   out_5662953649758416364[6] = delta_x[6] + nom_x[6];
   out_5662953649758416364[7] = delta_x[7] + nom_x[7];
   out_5662953649758416364[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2896900801310648034) {
   out_2896900801310648034[0] = -nom_x[0] + true_x[0];
   out_2896900801310648034[1] = -nom_x[1] + true_x[1];
   out_2896900801310648034[2] = -nom_x[2] + true_x[2];
   out_2896900801310648034[3] = -nom_x[3] + true_x[3];
   out_2896900801310648034[4] = -nom_x[4] + true_x[4];
   out_2896900801310648034[5] = -nom_x[5] + true_x[5];
   out_2896900801310648034[6] = -nom_x[6] + true_x[6];
   out_2896900801310648034[7] = -nom_x[7] + true_x[7];
   out_2896900801310648034[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6763768597135270784) {
   out_6763768597135270784[0] = 1.0;
   out_6763768597135270784[1] = 0;
   out_6763768597135270784[2] = 0;
   out_6763768597135270784[3] = 0;
   out_6763768597135270784[4] = 0;
   out_6763768597135270784[5] = 0;
   out_6763768597135270784[6] = 0;
   out_6763768597135270784[7] = 0;
   out_6763768597135270784[8] = 0;
   out_6763768597135270784[9] = 0;
   out_6763768597135270784[10] = 1.0;
   out_6763768597135270784[11] = 0;
   out_6763768597135270784[12] = 0;
   out_6763768597135270784[13] = 0;
   out_6763768597135270784[14] = 0;
   out_6763768597135270784[15] = 0;
   out_6763768597135270784[16] = 0;
   out_6763768597135270784[17] = 0;
   out_6763768597135270784[18] = 0;
   out_6763768597135270784[19] = 0;
   out_6763768597135270784[20] = 1.0;
   out_6763768597135270784[21] = 0;
   out_6763768597135270784[22] = 0;
   out_6763768597135270784[23] = 0;
   out_6763768597135270784[24] = 0;
   out_6763768597135270784[25] = 0;
   out_6763768597135270784[26] = 0;
   out_6763768597135270784[27] = 0;
   out_6763768597135270784[28] = 0;
   out_6763768597135270784[29] = 0;
   out_6763768597135270784[30] = 1.0;
   out_6763768597135270784[31] = 0;
   out_6763768597135270784[32] = 0;
   out_6763768597135270784[33] = 0;
   out_6763768597135270784[34] = 0;
   out_6763768597135270784[35] = 0;
   out_6763768597135270784[36] = 0;
   out_6763768597135270784[37] = 0;
   out_6763768597135270784[38] = 0;
   out_6763768597135270784[39] = 0;
   out_6763768597135270784[40] = 1.0;
   out_6763768597135270784[41] = 0;
   out_6763768597135270784[42] = 0;
   out_6763768597135270784[43] = 0;
   out_6763768597135270784[44] = 0;
   out_6763768597135270784[45] = 0;
   out_6763768597135270784[46] = 0;
   out_6763768597135270784[47] = 0;
   out_6763768597135270784[48] = 0;
   out_6763768597135270784[49] = 0;
   out_6763768597135270784[50] = 1.0;
   out_6763768597135270784[51] = 0;
   out_6763768597135270784[52] = 0;
   out_6763768597135270784[53] = 0;
   out_6763768597135270784[54] = 0;
   out_6763768597135270784[55] = 0;
   out_6763768597135270784[56] = 0;
   out_6763768597135270784[57] = 0;
   out_6763768597135270784[58] = 0;
   out_6763768597135270784[59] = 0;
   out_6763768597135270784[60] = 1.0;
   out_6763768597135270784[61] = 0;
   out_6763768597135270784[62] = 0;
   out_6763768597135270784[63] = 0;
   out_6763768597135270784[64] = 0;
   out_6763768597135270784[65] = 0;
   out_6763768597135270784[66] = 0;
   out_6763768597135270784[67] = 0;
   out_6763768597135270784[68] = 0;
   out_6763768597135270784[69] = 0;
   out_6763768597135270784[70] = 1.0;
   out_6763768597135270784[71] = 0;
   out_6763768597135270784[72] = 0;
   out_6763768597135270784[73] = 0;
   out_6763768597135270784[74] = 0;
   out_6763768597135270784[75] = 0;
   out_6763768597135270784[76] = 0;
   out_6763768597135270784[77] = 0;
   out_6763768597135270784[78] = 0;
   out_6763768597135270784[79] = 0;
   out_6763768597135270784[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7014559889233024887) {
   out_7014559889233024887[0] = state[0];
   out_7014559889233024887[1] = state[1];
   out_7014559889233024887[2] = state[2];
   out_7014559889233024887[3] = state[3];
   out_7014559889233024887[4] = state[4];
   out_7014559889233024887[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7014559889233024887[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7014559889233024887[7] = state[7];
   out_7014559889233024887[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2749676980229268459) {
   out_2749676980229268459[0] = 1;
   out_2749676980229268459[1] = 0;
   out_2749676980229268459[2] = 0;
   out_2749676980229268459[3] = 0;
   out_2749676980229268459[4] = 0;
   out_2749676980229268459[5] = 0;
   out_2749676980229268459[6] = 0;
   out_2749676980229268459[7] = 0;
   out_2749676980229268459[8] = 0;
   out_2749676980229268459[9] = 0;
   out_2749676980229268459[10] = 1;
   out_2749676980229268459[11] = 0;
   out_2749676980229268459[12] = 0;
   out_2749676980229268459[13] = 0;
   out_2749676980229268459[14] = 0;
   out_2749676980229268459[15] = 0;
   out_2749676980229268459[16] = 0;
   out_2749676980229268459[17] = 0;
   out_2749676980229268459[18] = 0;
   out_2749676980229268459[19] = 0;
   out_2749676980229268459[20] = 1;
   out_2749676980229268459[21] = 0;
   out_2749676980229268459[22] = 0;
   out_2749676980229268459[23] = 0;
   out_2749676980229268459[24] = 0;
   out_2749676980229268459[25] = 0;
   out_2749676980229268459[26] = 0;
   out_2749676980229268459[27] = 0;
   out_2749676980229268459[28] = 0;
   out_2749676980229268459[29] = 0;
   out_2749676980229268459[30] = 1;
   out_2749676980229268459[31] = 0;
   out_2749676980229268459[32] = 0;
   out_2749676980229268459[33] = 0;
   out_2749676980229268459[34] = 0;
   out_2749676980229268459[35] = 0;
   out_2749676980229268459[36] = 0;
   out_2749676980229268459[37] = 0;
   out_2749676980229268459[38] = 0;
   out_2749676980229268459[39] = 0;
   out_2749676980229268459[40] = 1;
   out_2749676980229268459[41] = 0;
   out_2749676980229268459[42] = 0;
   out_2749676980229268459[43] = 0;
   out_2749676980229268459[44] = 0;
   out_2749676980229268459[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2749676980229268459[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2749676980229268459[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2749676980229268459[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2749676980229268459[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2749676980229268459[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2749676980229268459[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2749676980229268459[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2749676980229268459[53] = -9.8000000000000007*dt;
   out_2749676980229268459[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2749676980229268459[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2749676980229268459[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2749676980229268459[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2749676980229268459[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2749676980229268459[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2749676980229268459[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2749676980229268459[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2749676980229268459[62] = 0;
   out_2749676980229268459[63] = 0;
   out_2749676980229268459[64] = 0;
   out_2749676980229268459[65] = 0;
   out_2749676980229268459[66] = 0;
   out_2749676980229268459[67] = 0;
   out_2749676980229268459[68] = 0;
   out_2749676980229268459[69] = 0;
   out_2749676980229268459[70] = 1;
   out_2749676980229268459[71] = 0;
   out_2749676980229268459[72] = 0;
   out_2749676980229268459[73] = 0;
   out_2749676980229268459[74] = 0;
   out_2749676980229268459[75] = 0;
   out_2749676980229268459[76] = 0;
   out_2749676980229268459[77] = 0;
   out_2749676980229268459[78] = 0;
   out_2749676980229268459[79] = 0;
   out_2749676980229268459[80] = 1;
}
void h_25(double *state, double *unused, double *out_722690739429382572) {
   out_722690739429382572[0] = state[6];
}
void H_25(double *state, double *unused, double *out_209301010503276110) {
   out_209301010503276110[0] = 0;
   out_209301010503276110[1] = 0;
   out_209301010503276110[2] = 0;
   out_209301010503276110[3] = 0;
   out_209301010503276110[4] = 0;
   out_209301010503276110[5] = 0;
   out_209301010503276110[6] = 1;
   out_209301010503276110[7] = 0;
   out_209301010503276110[8] = 0;
}
void h_24(double *state, double *unused, double *out_1099225576319256647) {
   out_1099225576319256647[0] = state[4];
   out_1099225576319256647[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1967913413103873863) {
   out_1967913413103873863[0] = 0;
   out_1967913413103873863[1] = 0;
   out_1967913413103873863[2] = 0;
   out_1967913413103873863[3] = 0;
   out_1967913413103873863[4] = 1;
   out_1967913413103873863[5] = 0;
   out_1967913413103873863[6] = 0;
   out_1967913413103873863[7] = 0;
   out_1967913413103873863[8] = 0;
   out_1967913413103873863[9] = 0;
   out_1967913413103873863[10] = 0;
   out_1967913413103873863[11] = 0;
   out_1967913413103873863[12] = 0;
   out_1967913413103873863[13] = 0;
   out_1967913413103873863[14] = 1;
   out_1967913413103873863[15] = 0;
   out_1967913413103873863[16] = 0;
   out_1967913413103873863[17] = 0;
}
void h_30(double *state, double *unused, double *out_6048144486920968364) {
   out_6048144486920968364[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2309031948003972517) {
   out_2309031948003972517[0] = 0;
   out_2309031948003972517[1] = 0;
   out_2309031948003972517[2] = 0;
   out_2309031948003972517[3] = 0;
   out_2309031948003972517[4] = 1;
   out_2309031948003972517[5] = 0;
   out_2309031948003972517[6] = 0;
   out_2309031948003972517[7] = 0;
   out_2309031948003972517[8] = 0;
}
void h_26(double *state, double *unused, double *out_7396926319127737607) {
   out_7396926319127737607[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3950804329377332334) {
   out_3950804329377332334[0] = 0;
   out_3950804329377332334[1] = 0;
   out_3950804329377332334[2] = 0;
   out_3950804329377332334[3] = 0;
   out_3950804329377332334[4] = 0;
   out_3950804329377332334[5] = 0;
   out_3950804329377332334[6] = 0;
   out_3950804329377332334[7] = 1;
   out_3950804329377332334[8] = 0;
}
void h_27(double *state, double *unused, double *out_5724364007090228217) {
   out_5724364007090228217[0] = state[3];
}
void H_27(double *state, double *unused, double *out_134268636203547606) {
   out_134268636203547606[0] = 0;
   out_134268636203547606[1] = 0;
   out_134268636203547606[2] = 0;
   out_134268636203547606[3] = 1;
   out_134268636203547606[4] = 0;
   out_134268636203547606[5] = 0;
   out_134268636203547606[6] = 0;
   out_134268636203547606[7] = 0;
   out_134268636203547606[8] = 0;
}
void h_29(double *state, double *unused, double *out_4273732614461345050) {
   out_4273732614461345050[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2819263292318364701) {
   out_2819263292318364701[0] = 0;
   out_2819263292318364701[1] = 1;
   out_2819263292318364701[2] = 0;
   out_2819263292318364701[3] = 0;
   out_2819263292318364701[4] = 0;
   out_2819263292318364701[5] = 0;
   out_2819263292318364701[6] = 0;
   out_2819263292318364701[7] = 0;
   out_2819263292318364701[8] = 0;
}
void h_28(double *state, double *unused, double *out_4780854154188565782) {
   out_4780854154188565782[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2263135724751165873) {
   out_2263135724751165873[0] = 1;
   out_2263135724751165873[1] = 0;
   out_2263135724751165873[2] = 0;
   out_2263135724751165873[3] = 0;
   out_2263135724751165873[4] = 0;
   out_2263135724751165873[5] = 0;
   out_2263135724751165873[6] = 0;
   out_2263135724751165873[7] = 0;
   out_2263135724751165873[8] = 0;
}
void h_31(double *state, double *unused, double *out_8485955996250055013) {
   out_8485955996250055013[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4577012431610683810) {
   out_4577012431610683810[0] = 0;
   out_4577012431610683810[1] = 0;
   out_4577012431610683810[2] = 0;
   out_4577012431610683810[3] = 0;
   out_4577012431610683810[4] = 0;
   out_4577012431610683810[5] = 0;
   out_4577012431610683810[6] = 0;
   out_4577012431610683810[7] = 0;
   out_4577012431610683810[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5662953649758416364) {
  err_fun(nom_x, delta_x, out_5662953649758416364);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2896900801310648034) {
  inv_err_fun(nom_x, true_x, out_2896900801310648034);
}
void car_H_mod_fun(double *state, double *out_6763768597135270784) {
  H_mod_fun(state, out_6763768597135270784);
}
void car_f_fun(double *state, double dt, double *out_7014559889233024887) {
  f_fun(state,  dt, out_7014559889233024887);
}
void car_F_fun(double *state, double dt, double *out_2749676980229268459) {
  F_fun(state,  dt, out_2749676980229268459);
}
void car_h_25(double *state, double *unused, double *out_722690739429382572) {
  h_25(state, unused, out_722690739429382572);
}
void car_H_25(double *state, double *unused, double *out_209301010503276110) {
  H_25(state, unused, out_209301010503276110);
}
void car_h_24(double *state, double *unused, double *out_1099225576319256647) {
  h_24(state, unused, out_1099225576319256647);
}
void car_H_24(double *state, double *unused, double *out_1967913413103873863) {
  H_24(state, unused, out_1967913413103873863);
}
void car_h_30(double *state, double *unused, double *out_6048144486920968364) {
  h_30(state, unused, out_6048144486920968364);
}
void car_H_30(double *state, double *unused, double *out_2309031948003972517) {
  H_30(state, unused, out_2309031948003972517);
}
void car_h_26(double *state, double *unused, double *out_7396926319127737607) {
  h_26(state, unused, out_7396926319127737607);
}
void car_H_26(double *state, double *unused, double *out_3950804329377332334) {
  H_26(state, unused, out_3950804329377332334);
}
void car_h_27(double *state, double *unused, double *out_5724364007090228217) {
  h_27(state, unused, out_5724364007090228217);
}
void car_H_27(double *state, double *unused, double *out_134268636203547606) {
  H_27(state, unused, out_134268636203547606);
}
void car_h_29(double *state, double *unused, double *out_4273732614461345050) {
  h_29(state, unused, out_4273732614461345050);
}
void car_H_29(double *state, double *unused, double *out_2819263292318364701) {
  H_29(state, unused, out_2819263292318364701);
}
void car_h_28(double *state, double *unused, double *out_4780854154188565782) {
  h_28(state, unused, out_4780854154188565782);
}
void car_H_28(double *state, double *unused, double *out_2263135724751165873) {
  H_28(state, unused, out_2263135724751165873);
}
void car_h_31(double *state, double *unused, double *out_8485955996250055013) {
  h_31(state, unused, out_8485955996250055013);
}
void car_H_31(double *state, double *unused, double *out_4577012431610683810) {
  H_31(state, unused, out_4577012431610683810);
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
