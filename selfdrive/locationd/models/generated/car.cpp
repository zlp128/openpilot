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
void err_fun(double *nom_x, double *delta_x, double *out_7500597990915213513) {
   out_7500597990915213513[0] = delta_x[0] + nom_x[0];
   out_7500597990915213513[1] = delta_x[1] + nom_x[1];
   out_7500597990915213513[2] = delta_x[2] + nom_x[2];
   out_7500597990915213513[3] = delta_x[3] + nom_x[3];
   out_7500597990915213513[4] = delta_x[4] + nom_x[4];
   out_7500597990915213513[5] = delta_x[5] + nom_x[5];
   out_7500597990915213513[6] = delta_x[6] + nom_x[6];
   out_7500597990915213513[7] = delta_x[7] + nom_x[7];
   out_7500597990915213513[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2781571296576732525) {
   out_2781571296576732525[0] = -nom_x[0] + true_x[0];
   out_2781571296576732525[1] = -nom_x[1] + true_x[1];
   out_2781571296576732525[2] = -nom_x[2] + true_x[2];
   out_2781571296576732525[3] = -nom_x[3] + true_x[3];
   out_2781571296576732525[4] = -nom_x[4] + true_x[4];
   out_2781571296576732525[5] = -nom_x[5] + true_x[5];
   out_2781571296576732525[6] = -nom_x[6] + true_x[6];
   out_2781571296576732525[7] = -nom_x[7] + true_x[7];
   out_2781571296576732525[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3562418887379080574) {
   out_3562418887379080574[0] = 1.0;
   out_3562418887379080574[1] = 0;
   out_3562418887379080574[2] = 0;
   out_3562418887379080574[3] = 0;
   out_3562418887379080574[4] = 0;
   out_3562418887379080574[5] = 0;
   out_3562418887379080574[6] = 0;
   out_3562418887379080574[7] = 0;
   out_3562418887379080574[8] = 0;
   out_3562418887379080574[9] = 0;
   out_3562418887379080574[10] = 1.0;
   out_3562418887379080574[11] = 0;
   out_3562418887379080574[12] = 0;
   out_3562418887379080574[13] = 0;
   out_3562418887379080574[14] = 0;
   out_3562418887379080574[15] = 0;
   out_3562418887379080574[16] = 0;
   out_3562418887379080574[17] = 0;
   out_3562418887379080574[18] = 0;
   out_3562418887379080574[19] = 0;
   out_3562418887379080574[20] = 1.0;
   out_3562418887379080574[21] = 0;
   out_3562418887379080574[22] = 0;
   out_3562418887379080574[23] = 0;
   out_3562418887379080574[24] = 0;
   out_3562418887379080574[25] = 0;
   out_3562418887379080574[26] = 0;
   out_3562418887379080574[27] = 0;
   out_3562418887379080574[28] = 0;
   out_3562418887379080574[29] = 0;
   out_3562418887379080574[30] = 1.0;
   out_3562418887379080574[31] = 0;
   out_3562418887379080574[32] = 0;
   out_3562418887379080574[33] = 0;
   out_3562418887379080574[34] = 0;
   out_3562418887379080574[35] = 0;
   out_3562418887379080574[36] = 0;
   out_3562418887379080574[37] = 0;
   out_3562418887379080574[38] = 0;
   out_3562418887379080574[39] = 0;
   out_3562418887379080574[40] = 1.0;
   out_3562418887379080574[41] = 0;
   out_3562418887379080574[42] = 0;
   out_3562418887379080574[43] = 0;
   out_3562418887379080574[44] = 0;
   out_3562418887379080574[45] = 0;
   out_3562418887379080574[46] = 0;
   out_3562418887379080574[47] = 0;
   out_3562418887379080574[48] = 0;
   out_3562418887379080574[49] = 0;
   out_3562418887379080574[50] = 1.0;
   out_3562418887379080574[51] = 0;
   out_3562418887379080574[52] = 0;
   out_3562418887379080574[53] = 0;
   out_3562418887379080574[54] = 0;
   out_3562418887379080574[55] = 0;
   out_3562418887379080574[56] = 0;
   out_3562418887379080574[57] = 0;
   out_3562418887379080574[58] = 0;
   out_3562418887379080574[59] = 0;
   out_3562418887379080574[60] = 1.0;
   out_3562418887379080574[61] = 0;
   out_3562418887379080574[62] = 0;
   out_3562418887379080574[63] = 0;
   out_3562418887379080574[64] = 0;
   out_3562418887379080574[65] = 0;
   out_3562418887379080574[66] = 0;
   out_3562418887379080574[67] = 0;
   out_3562418887379080574[68] = 0;
   out_3562418887379080574[69] = 0;
   out_3562418887379080574[70] = 1.0;
   out_3562418887379080574[71] = 0;
   out_3562418887379080574[72] = 0;
   out_3562418887379080574[73] = 0;
   out_3562418887379080574[74] = 0;
   out_3562418887379080574[75] = 0;
   out_3562418887379080574[76] = 0;
   out_3562418887379080574[77] = 0;
   out_3562418887379080574[78] = 0;
   out_3562418887379080574[79] = 0;
   out_3562418887379080574[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8261543717010253727) {
   out_8261543717010253727[0] = state[0];
   out_8261543717010253727[1] = state[1];
   out_8261543717010253727[2] = state[2];
   out_8261543717010253727[3] = state[3];
   out_8261543717010253727[4] = state[4];
   out_8261543717010253727[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8261543717010253727[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8261543717010253727[7] = state[7];
   out_8261543717010253727[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3007543019148089031) {
   out_3007543019148089031[0] = 1;
   out_3007543019148089031[1] = 0;
   out_3007543019148089031[2] = 0;
   out_3007543019148089031[3] = 0;
   out_3007543019148089031[4] = 0;
   out_3007543019148089031[5] = 0;
   out_3007543019148089031[6] = 0;
   out_3007543019148089031[7] = 0;
   out_3007543019148089031[8] = 0;
   out_3007543019148089031[9] = 0;
   out_3007543019148089031[10] = 1;
   out_3007543019148089031[11] = 0;
   out_3007543019148089031[12] = 0;
   out_3007543019148089031[13] = 0;
   out_3007543019148089031[14] = 0;
   out_3007543019148089031[15] = 0;
   out_3007543019148089031[16] = 0;
   out_3007543019148089031[17] = 0;
   out_3007543019148089031[18] = 0;
   out_3007543019148089031[19] = 0;
   out_3007543019148089031[20] = 1;
   out_3007543019148089031[21] = 0;
   out_3007543019148089031[22] = 0;
   out_3007543019148089031[23] = 0;
   out_3007543019148089031[24] = 0;
   out_3007543019148089031[25] = 0;
   out_3007543019148089031[26] = 0;
   out_3007543019148089031[27] = 0;
   out_3007543019148089031[28] = 0;
   out_3007543019148089031[29] = 0;
   out_3007543019148089031[30] = 1;
   out_3007543019148089031[31] = 0;
   out_3007543019148089031[32] = 0;
   out_3007543019148089031[33] = 0;
   out_3007543019148089031[34] = 0;
   out_3007543019148089031[35] = 0;
   out_3007543019148089031[36] = 0;
   out_3007543019148089031[37] = 0;
   out_3007543019148089031[38] = 0;
   out_3007543019148089031[39] = 0;
   out_3007543019148089031[40] = 1;
   out_3007543019148089031[41] = 0;
   out_3007543019148089031[42] = 0;
   out_3007543019148089031[43] = 0;
   out_3007543019148089031[44] = 0;
   out_3007543019148089031[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3007543019148089031[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3007543019148089031[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3007543019148089031[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3007543019148089031[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3007543019148089031[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3007543019148089031[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3007543019148089031[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3007543019148089031[53] = -9.8000000000000007*dt;
   out_3007543019148089031[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3007543019148089031[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3007543019148089031[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3007543019148089031[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3007543019148089031[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3007543019148089031[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3007543019148089031[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3007543019148089031[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3007543019148089031[62] = 0;
   out_3007543019148089031[63] = 0;
   out_3007543019148089031[64] = 0;
   out_3007543019148089031[65] = 0;
   out_3007543019148089031[66] = 0;
   out_3007543019148089031[67] = 0;
   out_3007543019148089031[68] = 0;
   out_3007543019148089031[69] = 0;
   out_3007543019148089031[70] = 1;
   out_3007543019148089031[71] = 0;
   out_3007543019148089031[72] = 0;
   out_3007543019148089031[73] = 0;
   out_3007543019148089031[74] = 0;
   out_3007543019148089031[75] = 0;
   out_3007543019148089031[76] = 0;
   out_3007543019148089031[77] = 0;
   out_3007543019148089031[78] = 0;
   out_3007543019148089031[79] = 0;
   out_3007543019148089031[80] = 1;
}
void h_25(double *state, double *unused, double *out_5344993741381892957) {
   out_5344993741381892957[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3493880848013174199) {
   out_3493880848013174199[0] = 0;
   out_3493880848013174199[1] = 0;
   out_3493880848013174199[2] = 0;
   out_3493880848013174199[3] = 0;
   out_3493880848013174199[4] = 0;
   out_3493880848013174199[5] = 0;
   out_3493880848013174199[6] = 1;
   out_3493880848013174199[7] = 0;
   out_3493880848013174199[8] = 0;
}
void h_24(double *state, double *unused, double *out_7269781498191373830) {
   out_7269781498191373830[0] = state[4];
   out_7269781498191373830[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1321231249007674633) {
   out_1321231249007674633[0] = 0;
   out_1321231249007674633[1] = 0;
   out_1321231249007674633[2] = 0;
   out_1321231249007674633[3] = 0;
   out_1321231249007674633[4] = 1;
   out_1321231249007674633[5] = 0;
   out_1321231249007674633[6] = 0;
   out_1321231249007674633[7] = 0;
   out_1321231249007674633[8] = 0;
   out_1321231249007674633[9] = 0;
   out_1321231249007674633[10] = 0;
   out_1321231249007674633[11] = 0;
   out_1321231249007674633[12] = 0;
   out_1321231249007674633[13] = 0;
   out_1321231249007674633[14] = 1;
   out_1321231249007674633[15] = 0;
   out_1321231249007674633[16] = 0;
   out_1321231249007674633[17] = 0;
}
void h_30(double *state, double *unused, double *out_1707544213127870607) {
   out_1707544213127870607[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1033815482114433999) {
   out_1033815482114433999[0] = 0;
   out_1033815482114433999[1] = 0;
   out_1033815482114433999[2] = 0;
   out_1033815482114433999[3] = 0;
   out_1033815482114433999[4] = 1;
   out_1033815482114433999[5] = 0;
   out_1033815482114433999[6] = 0;
   out_1033815482114433999[7] = 0;
   out_1033815482114433999[8] = 0;
}
void h_26(double *state, double *unused, double *out_7274424958878970158) {
   out_7274424958878970158[0] = state[7];
}
void H_26(double *state, double *unused, double *out_247622470860882025) {
   out_247622470860882025[0] = 0;
   out_247622470860882025[1] = 0;
   out_247622470860882025[2] = 0;
   out_247622470860882025[3] = 0;
   out_247622470860882025[4] = 0;
   out_247622470860882025[5] = 0;
   out_247622470860882025[6] = 0;
   out_247622470860882025[7] = 1;
   out_247622470860882025[8] = 0;
}
void h_27(double *state, double *unused, double *out_343320473721047312) {
   out_343320473721047312[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3208578793914858910) {
   out_3208578793914858910[0] = 0;
   out_3208578793914858910[1] = 0;
   out_3208578793914858910[2] = 0;
   out_3208578793914858910[3] = 1;
   out_3208578793914858910[4] = 0;
   out_3208578793914858910[5] = 0;
   out_3208578793914858910[6] = 0;
   out_3208578793914858910[7] = 0;
   out_3208578793914858910[8] = 0;
}
void h_29(double *state, double *unused, double *out_3294129054532975038) {
   out_3294129054532975038[0] = state[1];
}
void H_29(double *state, double *unused, double *out_523584137800041815) {
   out_523584137800041815[0] = 0;
   out_523584137800041815[1] = 1;
   out_523584137800041815[2] = 0;
   out_523584137800041815[3] = 0;
   out_523584137800041815[4] = 0;
   out_523584137800041815[5] = 0;
   out_523584137800041815[6] = 0;
   out_523584137800041815[7] = 0;
   out_523584137800041815[8] = 0;
}
void h_28(double *state, double *unused, double *out_8374516446147645014) {
   out_8374516446147645014[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1440046133765284436) {
   out_1440046133765284436[0] = 1;
   out_1440046133765284436[1] = 0;
   out_1440046133765284436[2] = 0;
   out_1440046133765284436[3] = 0;
   out_1440046133765284436[4] = 0;
   out_1440046133765284436[5] = 0;
   out_1440046133765284436[6] = 0;
   out_1440046133765284436[7] = 0;
   out_1440046133765284436[8] = 0;
}
void h_31(double *state, double *unused, double *out_2115565022866995368) {
   out_2115565022866995368[0] = state[8];
}
void H_31(double *state, double *unused, double *out_873830573094233501) {
   out_873830573094233501[0] = 0;
   out_873830573094233501[1] = 0;
   out_873830573094233501[2] = 0;
   out_873830573094233501[3] = 0;
   out_873830573094233501[4] = 0;
   out_873830573094233501[5] = 0;
   out_873830573094233501[6] = 0;
   out_873830573094233501[7] = 0;
   out_873830573094233501[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7500597990915213513) {
  err_fun(nom_x, delta_x, out_7500597990915213513);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2781571296576732525) {
  inv_err_fun(nom_x, true_x, out_2781571296576732525);
}
void car_H_mod_fun(double *state, double *out_3562418887379080574) {
  H_mod_fun(state, out_3562418887379080574);
}
void car_f_fun(double *state, double dt, double *out_8261543717010253727) {
  f_fun(state,  dt, out_8261543717010253727);
}
void car_F_fun(double *state, double dt, double *out_3007543019148089031) {
  F_fun(state,  dt, out_3007543019148089031);
}
void car_h_25(double *state, double *unused, double *out_5344993741381892957) {
  h_25(state, unused, out_5344993741381892957);
}
void car_H_25(double *state, double *unused, double *out_3493880848013174199) {
  H_25(state, unused, out_3493880848013174199);
}
void car_h_24(double *state, double *unused, double *out_7269781498191373830) {
  h_24(state, unused, out_7269781498191373830);
}
void car_H_24(double *state, double *unused, double *out_1321231249007674633) {
  H_24(state, unused, out_1321231249007674633);
}
void car_h_30(double *state, double *unused, double *out_1707544213127870607) {
  h_30(state, unused, out_1707544213127870607);
}
void car_H_30(double *state, double *unused, double *out_1033815482114433999) {
  H_30(state, unused, out_1033815482114433999);
}
void car_h_26(double *state, double *unused, double *out_7274424958878970158) {
  h_26(state, unused, out_7274424958878970158);
}
void car_H_26(double *state, double *unused, double *out_247622470860882025) {
  H_26(state, unused, out_247622470860882025);
}
void car_h_27(double *state, double *unused, double *out_343320473721047312) {
  h_27(state, unused, out_343320473721047312);
}
void car_H_27(double *state, double *unused, double *out_3208578793914858910) {
  H_27(state, unused, out_3208578793914858910);
}
void car_h_29(double *state, double *unused, double *out_3294129054532975038) {
  h_29(state, unused, out_3294129054532975038);
}
void car_H_29(double *state, double *unused, double *out_523584137800041815) {
  H_29(state, unused, out_523584137800041815);
}
void car_h_28(double *state, double *unused, double *out_8374516446147645014) {
  h_28(state, unused, out_8374516446147645014);
}
void car_H_28(double *state, double *unused, double *out_1440046133765284436) {
  H_28(state, unused, out_1440046133765284436);
}
void car_h_31(double *state, double *unused, double *out_2115565022866995368) {
  h_31(state, unused, out_2115565022866995368);
}
void car_H_31(double *state, double *unused, double *out_873830573094233501) {
  H_31(state, unused, out_873830573094233501);
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
