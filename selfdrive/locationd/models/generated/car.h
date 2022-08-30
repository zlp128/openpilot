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
void car_err_fun(double *nom_x, double *delta_x, double *out_6258559787192254109);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8483442434741396819);
void car_H_mod_fun(double *state, double *out_317258154932342734);
void car_f_fun(double *state, double dt, double *out_5753327761686972465);
void car_F_fun(double *state, double dt, double *out_8289678864136186323);
void car_h_25(double *state, double *unused, double *out_5741342572066533641);
void car_H_25(double *state, double *unused, double *out_1067105512112888160);
void car_h_24(double *state, double *unused, double *out_3184705636802324409);
void car_H_24(double *state, double *unused, double *out_3679403814853620874);
void car_h_30(double *state, double *unused, double *out_5619733767201413514);
void car_H_30(double *state, double *unused, double *out_3585438470620136787);
void car_h_26(double *state, double *unused, double *out_138251146792324442);
void car_H_26(double *state, double *unused, double *out_2674397806761168064);
void car_h_27(double *state, double *unused, double *out_7703728233982172330);
void car_H_27(double *state, double *unused, double *out_5809032541804080004);
void car_h_29(double *state, double *unused, double *out_3842044757553670678);
void car_H_29(double *state, double *unused, double *out_4095669814934528971);
void car_h_28(double *state, double *unused, double *out_3081542204526064016);
void car_H_28(double *state, double *unused, double *out_986729202135001603);
void car_h_31(double *state, double *unused, double *out_2103893043812511291);
void car_H_31(double *state, double *unused, double *out_1097751473989848588);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}