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
void car_err_fun(double *nom_x, double *delta_x, double *out_6920520309618378367);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5302696854806540781);
void car_H_mod_fun(double *state, double *out_4449921069090285960);
void car_f_fun(double *state, double dt, double *out_7814524287760230042);
void car_F_fun(double *state, double dt, double *out_411706590768419199);
void car_h_25(double *state, double *unused, double *out_624214668376866341);
void car_H_25(double *state, double *unused, double *out_4996036056466787679);
void car_h_24(double *state, double *unused, double *out_7726624714175041949);
void car_H_24(double *state, double *unused, double *out_8630386512586775674);
void car_h_30(double *state, double *unused, double *out_2951458280903618951);
void car_H_30(double *state, double *unused, double *out_5125375003610027749);
void car_h_26(double *state, double *unused, double *out_464815008745451065);
void car_H_26(double *state, double *unused, double *out_8737539375340843903);
void car_h_27(double *state, double *unused, double *out_2651633144370590248);
void car_H_27(double *state, double *unused, double *out_7300138315410452660);
void car_h_29(double *state, double *unused, double *out_2926827206655096137);
void car_H_29(double *state, double *unused, double *out_4615143659295635565);
void car_h_28(double *state, double *unused, double *out_2833450886970242207);
void car_H_28(double *state, double *unused, double *out_8749201397344385477);
void car_h_31(double *state, double *unused, double *out_899408730661372230);
void car_H_31(double *state, double *unused, double *out_4965390094589827251);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}