#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_654910612427940843);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6637724801134549563);
void gnss_H_mod_fun(double *state, double *out_805386010827368873);
void gnss_f_fun(double *state, double dt, double *out_4766656596405504851);
void gnss_F_fun(double *state, double dt, double *out_4029299056587768608);
void gnss_h_6(double *state, double *sat_pos, double *out_1067178731754715050);
void gnss_H_6(double *state, double *sat_pos, double *out_7962220724729872721);
void gnss_h_20(double *state, double *sat_pos, double *out_7444431052127272697);
void gnss_H_20(double *state, double *sat_pos, double *out_799492558915393744);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7430002568771021643);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7060224876276749950);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7430002568771021643);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7060224876276749950);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}