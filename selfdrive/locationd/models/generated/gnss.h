#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2097260997154060327);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_407819598143463209);
void gnss_H_mod_fun(double *state, double *out_4427837971737845911);
void gnss_f_fun(double *state, double dt, double *out_2405095626721301493);
void gnss_F_fun(double *state, double dt, double *out_1835212025890269909);
void gnss_h_6(double *state, double *sat_pos, double *out_1528125412600993628);
void gnss_H_6(double *state, double *sat_pos, double *out_104140276440086105);
void gnss_h_20(double *state, double *sat_pos, double *out_601402367496244624);
void gnss_H_20(double *state, double *sat_pos, double *out_4705666395271220693);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2964007189672083137);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_45965290841563331);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2964007189672083137);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_45965290841563331);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}