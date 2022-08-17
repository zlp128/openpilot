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
void car_err_fun(double *nom_x, double *delta_x, double *out_6814212569071197423);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7666174205888484741);
void car_H_mod_fun(double *state, double *out_8014857022495098622);
void car_f_fun(double *state, double dt, double *out_6791547762604559707);
void car_F_fun(double *state, double dt, double *out_3683219731909566018);
void car_h_25(double *state, double *unused, double *out_2172051214329875381);
void car_H_25(double *state, double *unused, double *out_3364051928398716628);
void car_h_24(double *state, double *unused, double *out_7587553502939940622);
void car_H_24(double *state, double *unused, double *out_2519055319615021229);
void car_h_30(double *state, double *unused, double *out_6112207235155681847);
void car_H_30(double *state, double *unused, double *out_3552638413092900127);
void car_h_26(double *state, double *unused, double *out_967317172040034310);
void car_H_26(double *state, double *unused, double *out_7105555247272772852);
void car_h_27(double *state, double *unused, double *out_351929141530343503);
void car_H_27(double *state, double *unused, double *out_1377875101292475216);
void car_h_29(double *state, double *unused, double *out_627123203814849392);
void car_H_29(double *state, double *unused, double *out_335487625577075817);
void car_h_28(double *state, double *unused, double *out_2252476179278354148);
void car_H_28(double *state, double *unused, double *out_5417886642646606391);
void car_h_31(double *state, double *unused, double *out_8511427602559003794);
void car_H_31(double *state, double *unused, double *out_3333405966521756200);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}