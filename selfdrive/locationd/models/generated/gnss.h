#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8218999594846759964);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6004490369099356165);
void gnss_H_mod_fun(double *state, double *out_5465143194872640210);
void gnss_f_fun(double *state, double dt, double *out_6477589900664112980);
void gnss_F_fun(double *state, double dt, double *out_159332577828599777);
void gnss_h_6(double *state, double *sat_pos, double *out_822185378282268145);
void gnss_H_6(double *state, double *sat_pos, double *out_2954217689973778176);
void gnss_h_20(double *state, double *sat_pos, double *out_3775340380998125465);
void gnss_H_20(double *state, double *sat_pos, double *out_4124080333257632986);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_750344228235882460);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1618262330099536806);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_750344228235882460);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1618262330099536806);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}