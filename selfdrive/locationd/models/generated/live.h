#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_3693999405139314794);
void live_err_fun(double *nom_x, double *delta_x, double *out_3414598820419176679);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5364111469669926070);
void live_H_mod_fun(double *state, double *out_8664355600254952032);
void live_f_fun(double *state, double dt, double *out_5944879704050977948);
void live_F_fun(double *state, double dt, double *out_1511312995606333672);
void live_h_4(double *state, double *unused, double *out_6748587584352144008);
void live_H_4(double *state, double *unused, double *out_6619224273712010162);
void live_h_9(double *state, double *unused, double *out_8367559596262948470);
void live_H_9(double *state, double *unused, double *out_6860413920341600807);
void live_h_10(double *state, double *unused, double *out_9168195956800795275);
void live_H_10(double *state, double *unused, double *out_1822418700523668742);
void live_h_12(double *state, double *unused, double *out_2333080179053030376);
void live_H_12(double *state, double *unused, double *out_6808063391965579659);
void live_h_35(double *state, double *unused, double *out_4784374292918501119);
void live_H_35(double *state, double *unused, double *out_8460857742624934078);
void live_h_32(double *state, double *unused, double *out_2752828006802561656);
void live_H_32(double *state, double *unused, double *out_8329692957684193609);
void live_h_13(double *state, double *unused, double *out_392591640858112584);
void live_H_13(double *state, double *unused, double *out_4626093262240260019);
void live_h_14(double *state, double *unused, double *out_8367559596262948470);
void live_H_14(double *state, double *unused, double *out_6860413920341600807);
void live_h_33(double *state, double *unused, double *out_9004392775721978689);
void live_H_33(double *state, double *unused, double *out_5310300737986076474);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}