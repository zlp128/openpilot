#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4281415265925619745);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_8058048663833159220);
void gnss_H_mod_fun(double *state, double *out_3690945488544052836);
void gnss_f_fun(double *state, double dt, double *out_2954456239899519205);
void gnss_F_fun(double *state, double dt, double *out_709514566261682476);
void gnss_h_6(double *state, double *sat_pos, double *out_2648966289655583926);
void gnss_H_6(double *state, double *sat_pos, double *out_1516634108393932450);
void gnss_h_20(double *state, double *sat_pos, double *out_1322673160422067744);
void gnss_H_20(double *state, double *sat_pos, double *out_6746823634573947585);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_3768133833178917308);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_6978532755514735815);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_3768133833178917308);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_6978532755514735815);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}