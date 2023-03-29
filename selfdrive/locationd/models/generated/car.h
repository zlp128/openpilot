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
void car_err_fun(double *nom_x, double *delta_x, double *out_5634330020296848070);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1061559027503315281);
void car_H_mod_fun(double *state, double *out_1567569310651922730);
void car_f_fun(double *state, double dt, double *out_1208381054458531187);
void car_F_fun(double *state, double dt, double *out_8824004521572161416);
void car_h_25(double *state, double *unused, double *out_1789446864250922111);
void car_H_25(double *state, double *unused, double *out_9129886545195087354);
void car_h_24(double *state, double *unused, double *out_3299160385053087312);
void car_H_24(double *state, double *unused, double *out_7144207929508964696);
void car_h_30(double *state, double *unused, double *out_7348270420432929071);
void car_H_30(double *state, double *unused, double *out_6611553586687838727);
void car_h_26(double *state, double *unused, double *out_6096800385615776900);
void car_H_26(double *state, double *unused, double *out_5575354209640408038);
void car_h_27(double *state, double *unused, double *out_1247339187193410574);
void car_H_27(double *state, double *unused, double *out_2614397886586431153);
void car_h_29(double *state, double *unused, double *out_1705540549351972236);
void car_H_29(double *state, double *unused, double *out_5299392542701248248);
void car_h_28(double *state, double *unused, double *out_4170451758575142464);
void car_H_28(double *state, double *unused, double *out_7263022814266574499);
void car_h_31(double *state, double *unused, double *out_1514252801966416222);
void car_H_31(double *state, double *unused, double *out_4949146107407056562);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}