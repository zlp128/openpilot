#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_6740791193231733360);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_5435998030533772419);
void gnss_H_mod_fun(double *state, double *out_8750904480143678209);
void gnss_f_fun(double *state, double dt, double *out_571033032076185663);
void gnss_F_fun(double *state, double dt, double *out_8071961880976414619);
void gnss_h_6(double *state, double *sat_pos, double *out_3924727623087114070);
void gnss_H_6(double *state, double *sat_pos, double *out_3168437365824362595);
void gnss_h_20(double *state, double *sat_pos, double *out_7434817830173438872);
void gnss_H_20(double *state, double *sat_pos, double *out_7560749815445785198);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_7603906676528442007);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_8038884862828261433);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_7603906676528442007);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_8038884862828261433);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}