#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2641878617010244620);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6377401004299455720);
void gnss_H_mod_fun(double *state, double *out_350167543532614649);
void gnss_f_fun(double *state, double dt, double *out_6672020356614883149);
void gnss_F_fun(double *state, double dt, double *out_1674482844242533979);
void gnss_h_6(double *state, double *sat_pos, double *out_5972909262720134315);
void gnss_H_6(double *state, double *sat_pos, double *out_3653461233205109228);
void gnss_h_20(double *state, double *sat_pos, double *out_4250972716649874804);
void gnss_H_20(double *state, double *sat_pos, double *out_7645549737271804400);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8613498608425957392);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_217272578096397715);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8613498608425957392);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_217272578096397715);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}