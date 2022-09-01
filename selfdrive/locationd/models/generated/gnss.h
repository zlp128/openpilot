#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_7861368562585023949);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6509090499931839816);
void gnss_H_mod_fun(double *state, double *out_475664012759985504);
void gnss_f_fun(double *state, double dt, double *out_4292385048460003663);
void gnss_F_fun(double *state, double dt, double *out_7071174528671579157);
void gnss_h_6(double *state, double *sat_pos, double *out_2481230479465319936);
void gnss_H_6(double *state, double *sat_pos, double *out_7645196925630164082);
void gnss_h_20(double *state, double *sat_pos, double *out_7507301208942135576);
void gnss_H_20(double *state, double *sat_pos, double *out_1693366137112332184);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2861812996390348550);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1823365369839474784);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2861812996390348550);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1823365369839474784);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}