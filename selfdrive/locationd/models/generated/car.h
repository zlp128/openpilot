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
void car_err_fun(double *nom_x, double *delta_x, double *out_5232708683747839446);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6273110318621425138);
void car_H_mod_fun(double *state, double *out_376479380516898605);
void car_f_fun(double *state, double dt, double *out_7586787697879010325);
void car_F_fun(double *state, double dt, double *out_472790716300753243);
void car_h_25(double *state, double *unused, double *out_6846635756302794664);
void car_H_25(double *state, double *unused, double *out_1681825998279428652);
void car_h_24(double *state, double *unused, double *out_7639061379755997248);
void car_H_24(double *state, double *unused, double *out_4893745808312089449);
void car_h_30(double *state, double *unused, double *out_2046273354615198377);
void car_H_30(double *state, double *unused, double *out_5234864343212188103);
void car_h_26(double *state, double *unused, double *out_4200177702844975091);
void car_H_26(double *state, double *unused, double *out_5423329317153484876);
void car_h_27(double *state, double *unused, double *out_6628820938264559055);
void car_H_27(double *state, double *unused, double *out_3985928257223093633);
void car_h_29(double *state, double *unused, double *out_1102763501713535942);
void car_H_29(double *state, double *unused, double *out_5699290984092644666);
void car_h_28(double *state, double *unused, double *out_6175193264364035726);
void car_H_28(double *state, double *unused, double *out_3735660712527318415);
void car_h_31(double *state, double *unused, double *out_3077779063232596577);
void car_H_31(double *state, double *unused, double *out_1651180036402468224);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}