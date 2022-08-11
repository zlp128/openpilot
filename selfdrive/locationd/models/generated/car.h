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
void car_err_fun(double *nom_x, double *delta_x, double *out_7500597990915213513);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2781571296576732525);
void car_H_mod_fun(double *state, double *out_3562418887379080574);
void car_f_fun(double *state, double dt, double *out_8261543717010253727);
void car_F_fun(double *state, double dt, double *out_3007543019148089031);
void car_h_25(double *state, double *unused, double *out_5344993741381892957);
void car_H_25(double *state, double *unused, double *out_3493880848013174199);
void car_h_24(double *state, double *unused, double *out_7269781498191373830);
void car_H_24(double *state, double *unused, double *out_1321231249007674633);
void car_h_30(double *state, double *unused, double *out_1707544213127870607);
void car_H_30(double *state, double *unused, double *out_1033815482114433999);
void car_h_26(double *state, double *unused, double *out_7274424958878970158);
void car_H_26(double *state, double *unused, double *out_247622470860882025);
void car_h_27(double *state, double *unused, double *out_343320473721047312);
void car_H_27(double *state, double *unused, double *out_3208578793914858910);
void car_h_29(double *state, double *unused, double *out_3294129054532975038);
void car_H_29(double *state, double *unused, double *out_523584137800041815);
void car_h_28(double *state, double *unused, double *out_8374516446147645014);
void car_H_28(double *state, double *unused, double *out_1440046133765284436);
void car_h_31(double *state, double *unused, double *out_2115565022866995368);
void car_H_31(double *state, double *unused, double *out_873830573094233501);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}