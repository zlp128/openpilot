#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4640013062227700412);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_4915148707996812550);
void gnss_H_mod_fun(double *state, double *out_8574237875034322764);
void gnss_f_fun(double *state, double dt, double *out_5636831905979297775);
void gnss_F_fun(double *state, double dt, double *out_2727942986966876467);
void gnss_h_6(double *state, double *sat_pos, double *out_4554215930920042575);
void gnss_H_6(double *state, double *sat_pos, double *out_895428558576169950);
void gnss_h_20(double *state, double *sat_pos, double *out_6704926246356191984);
void gnss_H_20(double *state, double *sat_pos, double *out_3575717658219428128);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_6430340606903371855);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_4789129994195662485);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_6430340606903371855);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_4789129994195662485);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}