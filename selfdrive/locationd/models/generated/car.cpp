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
void err_fun(double *nom_x, double *delta_x, double *out_1694732445564659799) {
   out_1694732445564659799[0] = delta_x[0] + nom_x[0];
   out_1694732445564659799[1] = delta_x[1] + nom_x[1];
   out_1694732445564659799[2] = delta_x[2] + nom_x[2];
   out_1694732445564659799[3] = delta_x[3] + nom_x[3];
   out_1694732445564659799[4] = delta_x[4] + nom_x[4];
   out_1694732445564659799[5] = delta_x[5] + nom_x[5];
   out_1694732445564659799[6] = delta_x[6] + nom_x[6];
   out_1694732445564659799[7] = delta_x[7] + nom_x[7];
   out_1694732445564659799[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_425293828362209991) {
   out_425293828362209991[0] = -nom_x[0] + true_x[0];
   out_425293828362209991[1] = -nom_x[1] + true_x[1];
   out_425293828362209991[2] = -nom_x[2] + true_x[2];
   out_425293828362209991[3] = -nom_x[3] + true_x[3];
   out_425293828362209991[4] = -nom_x[4] + true_x[4];
   out_425293828362209991[5] = -nom_x[5] + true_x[5];
   out_425293828362209991[6] = -nom_x[6] + true_x[6];
   out_425293828362209991[7] = -nom_x[7] + true_x[7];
   out_425293828362209991[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7930286674743613659) {
   out_7930286674743613659[0] = 1.0;
   out_7930286674743613659[1] = 0;
   out_7930286674743613659[2] = 0;
   out_7930286674743613659[3] = 0;
   out_7930286674743613659[4] = 0;
   out_7930286674743613659[5] = 0;
   out_7930286674743613659[6] = 0;
   out_7930286674743613659[7] = 0;
   out_7930286674743613659[8] = 0;
   out_7930286674743613659[9] = 0;
   out_7930286674743613659[10] = 1.0;
   out_7930286674743613659[11] = 0;
   out_7930286674743613659[12] = 0;
   out_7930286674743613659[13] = 0;
   out_7930286674743613659[14] = 0;
   out_7930286674743613659[15] = 0;
   out_7930286674743613659[16] = 0;
   out_7930286674743613659[17] = 0;
   out_7930286674743613659[18] = 0;
   out_7930286674743613659[19] = 0;
   out_7930286674743613659[20] = 1.0;
   out_7930286674743613659[21] = 0;
   out_7930286674743613659[22] = 0;
   out_7930286674743613659[23] = 0;
   out_7930286674743613659[24] = 0;
   out_7930286674743613659[25] = 0;
   out_7930286674743613659[26] = 0;
   out_7930286674743613659[27] = 0;
   out_7930286674743613659[28] = 0;
   out_7930286674743613659[29] = 0;
   out_7930286674743613659[30] = 1.0;
   out_7930286674743613659[31] = 0;
   out_7930286674743613659[32] = 0;
   out_7930286674743613659[33] = 0;
   out_7930286674743613659[34] = 0;
   out_7930286674743613659[35] = 0;
   out_7930286674743613659[36] = 0;
   out_7930286674743613659[37] = 0;
   out_7930286674743613659[38] = 0;
   out_7930286674743613659[39] = 0;
   out_7930286674743613659[40] = 1.0;
   out_7930286674743613659[41] = 0;
   out_7930286674743613659[42] = 0;
   out_7930286674743613659[43] = 0;
   out_7930286674743613659[44] = 0;
   out_7930286674743613659[45] = 0;
   out_7930286674743613659[46] = 0;
   out_7930286674743613659[47] = 0;
   out_7930286674743613659[48] = 0;
   out_7930286674743613659[49] = 0;
   out_7930286674743613659[50] = 1.0;
   out_7930286674743613659[51] = 0;
   out_7930286674743613659[52] = 0;
   out_7930286674743613659[53] = 0;
   out_7930286674743613659[54] = 0;
   out_7930286674743613659[55] = 0;
   out_7930286674743613659[56] = 0;
   out_7930286674743613659[57] = 0;
   out_7930286674743613659[58] = 0;
   out_7930286674743613659[59] = 0;
   out_7930286674743613659[60] = 1.0;
   out_7930286674743613659[61] = 0;
   out_7930286674743613659[62] = 0;
   out_7930286674743613659[63] = 0;
   out_7930286674743613659[64] = 0;
   out_7930286674743613659[65] = 0;
   out_7930286674743613659[66] = 0;
   out_7930286674743613659[67] = 0;
   out_7930286674743613659[68] = 0;
   out_7930286674743613659[69] = 0;
   out_7930286674743613659[70] = 1.0;
   out_7930286674743613659[71] = 0;
   out_7930286674743613659[72] = 0;
   out_7930286674743613659[73] = 0;
   out_7930286674743613659[74] = 0;
   out_7930286674743613659[75] = 0;
   out_7930286674743613659[76] = 0;
   out_7930286674743613659[77] = 0;
   out_7930286674743613659[78] = 0;
   out_7930286674743613659[79] = 0;
   out_7930286674743613659[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4344037338675685761) {
   out_4344037338675685761[0] = state[0];
   out_4344037338675685761[1] = state[1];
   out_4344037338675685761[2] = state[2];
   out_4344037338675685761[3] = state[3];
   out_4344037338675685761[4] = state[4];
   out_4344037338675685761[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4344037338675685761[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4344037338675685761[7] = state[7];
   out_4344037338675685761[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5293371990253890476) {
   out_5293371990253890476[0] = 1;
   out_5293371990253890476[1] = 0;
   out_5293371990253890476[2] = 0;
   out_5293371990253890476[3] = 0;
   out_5293371990253890476[4] = 0;
   out_5293371990253890476[5] = 0;
   out_5293371990253890476[6] = 0;
   out_5293371990253890476[7] = 0;
   out_5293371990253890476[8] = 0;
   out_5293371990253890476[9] = 0;
   out_5293371990253890476[10] = 1;
   out_5293371990253890476[11] = 0;
   out_5293371990253890476[12] = 0;
   out_5293371990253890476[13] = 0;
   out_5293371990253890476[14] = 0;
   out_5293371990253890476[15] = 0;
   out_5293371990253890476[16] = 0;
   out_5293371990253890476[17] = 0;
   out_5293371990253890476[18] = 0;
   out_5293371990253890476[19] = 0;
   out_5293371990253890476[20] = 1;
   out_5293371990253890476[21] = 0;
   out_5293371990253890476[22] = 0;
   out_5293371990253890476[23] = 0;
   out_5293371990253890476[24] = 0;
   out_5293371990253890476[25] = 0;
   out_5293371990253890476[26] = 0;
   out_5293371990253890476[27] = 0;
   out_5293371990253890476[28] = 0;
   out_5293371990253890476[29] = 0;
   out_5293371990253890476[30] = 1;
   out_5293371990253890476[31] = 0;
   out_5293371990253890476[32] = 0;
   out_5293371990253890476[33] = 0;
   out_5293371990253890476[34] = 0;
   out_5293371990253890476[35] = 0;
   out_5293371990253890476[36] = 0;
   out_5293371990253890476[37] = 0;
   out_5293371990253890476[38] = 0;
   out_5293371990253890476[39] = 0;
   out_5293371990253890476[40] = 1;
   out_5293371990253890476[41] = 0;
   out_5293371990253890476[42] = 0;
   out_5293371990253890476[43] = 0;
   out_5293371990253890476[44] = 0;
   out_5293371990253890476[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5293371990253890476[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5293371990253890476[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5293371990253890476[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5293371990253890476[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5293371990253890476[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5293371990253890476[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5293371990253890476[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5293371990253890476[53] = -9.8000000000000007*dt;
   out_5293371990253890476[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5293371990253890476[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5293371990253890476[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5293371990253890476[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5293371990253890476[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5293371990253890476[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5293371990253890476[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5293371990253890476[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5293371990253890476[62] = 0;
   out_5293371990253890476[63] = 0;
   out_5293371990253890476[64] = 0;
   out_5293371990253890476[65] = 0;
   out_5293371990253890476[66] = 0;
   out_5293371990253890476[67] = 0;
   out_5293371990253890476[68] = 0;
   out_5293371990253890476[69] = 0;
   out_5293371990253890476[70] = 1;
   out_5293371990253890476[71] = 0;
   out_5293371990253890476[72] = 0;
   out_5293371990253890476[73] = 0;
   out_5293371990253890476[74] = 0;
   out_5293371990253890476[75] = 0;
   out_5293371990253890476[76] = 0;
   out_5293371990253890476[77] = 0;
   out_5293371990253890476[78] = 0;
   out_5293371990253890476[79] = 0;
   out_5293371990253890476[80] = 1;
}
void h_25(double *state, double *unused, double *out_6157449178476545177) {
   out_6157449178476545177[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2441201791329547719) {
   out_2441201791329547719[0] = 0;
   out_2441201791329547719[1] = 0;
   out_2441201791329547719[2] = 0;
   out_2441201791329547719[3] = 0;
   out_2441201791329547719[4] = 0;
   out_2441201791329547719[5] = 0;
   out_2441201791329547719[6] = 1;
   out_2441201791329547719[7] = 0;
   out_2441201791329547719[8] = 0;
}
void h_24(double *state, double *unused, double *out_7099854435825100532) {
   out_7099854435825100532[0] = state[4];
   out_7099854435825100532[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8562867689391287577) {
   out_8562867689391287577[0] = 0;
   out_8562867689391287577[1] = 0;
   out_8562867689391287577[2] = 0;
   out_8562867689391287577[3] = 0;
   out_8562867689391287577[4] = 1;
   out_8562867689391287577[5] = 0;
   out_8562867689391287577[6] = 0;
   out_8562867689391287577[7] = 0;
   out_8562867689391287577[8] = 0;
   out_8562867689391287577[9] = 0;
   out_8562867689391287577[10] = 0;
   out_8562867689391287577[11] = 0;
   out_8562867689391287577[12] = 0;
   out_8562867689391287577[13] = 0;
   out_8562867689391287577[14] = 1;
   out_8562867689391287577[15] = 0;
   out_8562867689391287577[16] = 0;
   out_8562867689391287577[17] = 0;
}
void h_30(double *state, double *unused, double *out_8651845366978984089) {
   out_8651845366978984089[0] = state[4];
}
void H_30(double *state, double *unused, double *out_77131167177700908) {
   out_77131167177700908[0] = 0;
   out_77131167177700908[1] = 0;
   out_77131167177700908[2] = 0;
   out_77131167177700908[3] = 0;
   out_77131167177700908[4] = 1;
   out_77131167177700908[5] = 0;
   out_77131167177700908[6] = 0;
   out_77131167177700908[7] = 0;
   out_77131167177700908[8] = 0;
}
void h_26(double *state, double *unused, double *out_7484101565902842352) {
   out_7484101565902842352[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6182705110203603943) {
   out_6182705110203603943[0] = 0;
   out_6182705110203603943[1] = 0;
   out_6182705110203603943[2] = 0;
   out_6182705110203603943[3] = 0;
   out_6182705110203603943[4] = 0;
   out_6182705110203603943[5] = 0;
   out_6182705110203603943[6] = 0;
   out_6182705110203603943[7] = 1;
   out_6182705110203603943[8] = 0;
}
void h_27(double *state, double *unused, double *out_3701132213428165031) {
   out_3701132213428165031[0] = state[3];
}
void H_27(double *state, double *unused, double *out_9143661433257580828) {
   out_9143661433257580828[0] = 0;
   out_9143661433257580828[1] = 0;
   out_9143661433257580828[2] = 0;
   out_9143661433257580828[3] = 1;
   out_9143661433257580828[4] = 0;
   out_9143661433257580828[5] = 0;
   out_9143661433257580828[6] = 0;
   out_9143661433257580828[7] = 0;
   out_9143661433257580828[8] = 0;
}
void h_29(double *state, double *unused, double *out_3425938151143659142) {
   out_3425938151143659142[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6458666777142763733) {
   out_6458666777142763733[0] = 0;
   out_6458666777142763733[1] = 1;
   out_6458666777142763733[2] = 0;
   out_6458666777142763733[3] = 0;
   out_6458666777142763733[4] = 0;
   out_6458666777142763733[5] = 0;
   out_6458666777142763733[6] = 0;
   out_6458666777142763733[7] = 0;
   out_6458666777142763733[8] = 0;
}
void h_28(double *state, double *unused, double *out_6305537534236862682) {
   out_6305537534236862682[0] = state[0];
}
void H_28(double *state, double *unused, double *out_4495036505577437482) {
   out_4495036505577437482[0] = 1;
   out_4495036505577437482[1] = 0;
   out_4495036505577437482[2] = 0;
   out_4495036505577437482[3] = 0;
   out_4495036505577437482[4] = 0;
   out_4495036505577437482[5] = 0;
   out_4495036505577437482[6] = 0;
   out_4495036505577437482[7] = 0;
   out_4495036505577437482[8] = 0;
}
void h_31(double *state, double *unused, double *out_206144799825270684) {
   out_206144799825270684[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6808913212436955419) {
   out_6808913212436955419[0] = 0;
   out_6808913212436955419[1] = 0;
   out_6808913212436955419[2] = 0;
   out_6808913212436955419[3] = 0;
   out_6808913212436955419[4] = 0;
   out_6808913212436955419[5] = 0;
   out_6808913212436955419[6] = 0;
   out_6808913212436955419[7] = 0;
   out_6808913212436955419[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_1694732445564659799) {
  err_fun(nom_x, delta_x, out_1694732445564659799);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_425293828362209991) {
  inv_err_fun(nom_x, true_x, out_425293828362209991);
}
void car_H_mod_fun(double *state, double *out_7930286674743613659) {
  H_mod_fun(state, out_7930286674743613659);
}
void car_f_fun(double *state, double dt, double *out_4344037338675685761) {
  f_fun(state,  dt, out_4344037338675685761);
}
void car_F_fun(double *state, double dt, double *out_5293371990253890476) {
  F_fun(state,  dt, out_5293371990253890476);
}
void car_h_25(double *state, double *unused, double *out_6157449178476545177) {
  h_25(state, unused, out_6157449178476545177);
}
void car_H_25(double *state, double *unused, double *out_2441201791329547719) {
  H_25(state, unused, out_2441201791329547719);
}
void car_h_24(double *state, double *unused, double *out_7099854435825100532) {
  h_24(state, unused, out_7099854435825100532);
}
void car_H_24(double *state, double *unused, double *out_8562867689391287577) {
  H_24(state, unused, out_8562867689391287577);
}
void car_h_30(double *state, double *unused, double *out_8651845366978984089) {
  h_30(state, unused, out_8651845366978984089);
}
void car_H_30(double *state, double *unused, double *out_77131167177700908) {
  H_30(state, unused, out_77131167177700908);
}
void car_h_26(double *state, double *unused, double *out_7484101565902842352) {
  h_26(state, unused, out_7484101565902842352);
}
void car_H_26(double *state, double *unused, double *out_6182705110203603943) {
  H_26(state, unused, out_6182705110203603943);
}
void car_h_27(double *state, double *unused, double *out_3701132213428165031) {
  h_27(state, unused, out_3701132213428165031);
}
void car_H_27(double *state, double *unused, double *out_9143661433257580828) {
  H_27(state, unused, out_9143661433257580828);
}
void car_h_29(double *state, double *unused, double *out_3425938151143659142) {
  h_29(state, unused, out_3425938151143659142);
}
void car_H_29(double *state, double *unused, double *out_6458666777142763733) {
  H_29(state, unused, out_6458666777142763733);
}
void car_h_28(double *state, double *unused, double *out_6305537534236862682) {
  h_28(state, unused, out_6305537534236862682);
}
void car_H_28(double *state, double *unused, double *out_4495036505577437482) {
  H_28(state, unused, out_4495036505577437482);
}
void car_h_31(double *state, double *unused, double *out_206144799825270684) {
  h_31(state, unused, out_206144799825270684);
}
void car_H_31(double *state, double *unused, double *out_6808913212436955419) {
  H_31(state, unused, out_6808913212436955419);
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
