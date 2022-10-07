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
void car_err_fun(double *nom_x, double *delta_x, double *out_5662953649758416364);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2896900801310648034);
void car_H_mod_fun(double *state, double *out_6763768597135270784);
void car_f_fun(double *state, double dt, double *out_7014559889233024887);
void car_F_fun(double *state, double dt, double *out_2749676980229268459);
void car_h_25(double *state, double *unused, double *out_722690739429382572);
void car_H_25(double *state, double *unused, double *out_209301010503276110);
void car_h_24(double *state, double *unused, double *out_1099225576319256647);
void car_H_24(double *state, double *unused, double *out_1967913413103873863);
void car_h_30(double *state, double *unused, double *out_6048144486920968364);
void car_H_30(double *state, double *unused, double *out_2309031948003972517);
void car_h_26(double *state, double *unused, double *out_7396926319127737607);
void car_H_26(double *state, double *unused, double *out_3950804329377332334);
void car_h_27(double *state, double *unused, double *out_5724364007090228217);
void car_H_27(double *state, double *unused, double *out_134268636203547606);
void car_h_29(double *state, double *unused, double *out_4273732614461345050);
void car_H_29(double *state, double *unused, double *out_2819263292318364701);
void car_h_28(double *state, double *unused, double *out_4780854154188565782);
void car_H_28(double *state, double *unused, double *out_2263135724751165873);
void car_h_31(double *state, double *unused, double *out_8485955996250055013);
void car_H_31(double *state, double *unused, double *out_4577012431610683810);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}