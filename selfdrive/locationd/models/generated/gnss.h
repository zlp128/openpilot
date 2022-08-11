#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4620912923766298580);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_9187715529705882522);
void gnss_H_mod_fun(double *state, double *out_922973610943044438);
void gnss_f_fun(double *state, double dt, double *out_1079402724574081004);
void gnss_F_fun(double *state, double dt, double *out_3039166340276301210);
void gnss_h_6(double *state, double *sat_pos, double *out_3874365000426709074);
void gnss_H_6(double *state, double *sat_pos, double *out_3986922819635287129);
void gnss_h_20(double *state, double *sat_pos, double *out_5069168270486129229);
void gnss_H_20(double *state, double *sat_pos, double *out_678918665408427203);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_9105285764076347784);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7685540822919128148);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_9105285764076347784);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7685540822919128148);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}