#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_1734633203049768488);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_7226800202829737504);
void gnss_H_mod_fun(double *state, double *out_7212715412967761026);
void gnss_f_fun(double *state, double dt, double *out_4622219999608348212);
void gnss_F_fun(double *state, double dt, double *out_1489675256084431222);
void gnss_h_6(double *state, double *sat_pos, double *out_7567908033892933921);
void gnss_H_6(double *state, double *sat_pos, double *out_7455993273502557413);
void gnss_h_20(double *state, double *sat_pos, double *out_3841468768416351937);
void gnss_H_20(double *state, double *sat_pos, double *out_5623941665124898301);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_1211039377275791210);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_2159917500592958723);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_1211039377275791210);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_2159917500592958723);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}