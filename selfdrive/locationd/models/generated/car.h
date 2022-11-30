#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7743502251243671447);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8632432640030731669);
void car_H_mod_fun(double *state, double *out_6955983744751080330);
void car_f_fun(double *state, double dt, double *out_1057256165937700131);
void car_F_fun(double *state, double dt, double *out_2042254547319901591);
void car_h_25(double *state, double *unused, double *out_9038137973563738704);
void car_H_25(double *state, double *unused, double *out_6219790086191979796);
void car_h_24(double *state, double *unused, double *out_8933773235415263694);
void car_H_24(double *state, double *unused, double *out_2661864487389656660);
void car_h_30(double *state, double *unused, double *out_1353345261140371077);
void car_H_30(double *state, double *unused, double *out_3701457127684731169);
void car_h_26(double *state, double *unused, double *out_3791544801975276460);
void car_H_26(double *state, double *unused, double *out_8485450668643515596);
void car_h_27(double *state, double *unused, double *out_4406932832484967267);
void car_H_27(double *state, double *unused, double *out_5876220439485156080);
void car_h_29(double *state, double *unused, double *out_6276545984403911908);
void car_H_29(double *state, double *unused, double *out_3191225783370338985);
void car_h_28(double *state, double *unused, double *out_7011338153293664918);
void car_H_28(double *state, double *unused, double *out_8273624800439869559);
void car_h_31(double *state, double *unused, double *out_8647698245415467134);
void car_H_31(double *state, double *unused, double *out_7859242566410164120);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}