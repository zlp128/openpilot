#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3985733553669045281);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_668705734016375974);
void gnss_H_mod_fun(double *state, double *out_1646191520139698591);
void gnss_f_fun(double *state, double dt, double *out_8136264243716214718);
void gnss_F_fun(double *state, double dt, double *out_4236213521667949352);
void gnss_h_6(double *state, double *sat_pos, double *out_8352111296884602789);
void gnss_H_6(double *state, double *sat_pos, double *out_2202359500111385714);
void gnss_h_20(double *state, double *sat_pos, double *out_4887672178428492502);
void gnss_H_20(double *state, double *sat_pos, double *out_4961949425089895635);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_191603051630805475);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7197851591855342328);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_191603051630805475);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7197851591855342328);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}