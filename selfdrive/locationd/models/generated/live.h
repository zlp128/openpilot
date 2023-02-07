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
void live_H(double *in_vec, double *out_907497564161450989);
void live_err_fun(double *nom_x, double *delta_x, double *out_403017012035771763);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2932713747370631150);
void live_H_mod_fun(double *state, double *out_6036032580712144890);
void live_f_fun(double *state, double dt, double *out_653667760006229873);
void live_F_fun(double *state, double dt, double *out_8944506884882647575);
void live_h_4(double *state, double *unused, double *out_6967130088459663654);
void live_H_4(double *state, double *unused, double *out_2805776108884249108);
void live_h_9(double *state, double *unused, double *out_5944074116138401933);
void live_H_9(double *state, double *unused, double *out_2564586462254658463);
void live_h_10(double *state, double *unused, double *out_3024176660760462318);
void live_H_10(double *state, double *unused, double *out_3594957374532062379);
void live_h_12(double *state, double *unused, double *out_1781567485764299655);
void live_H_12(double *state, double *unused, double *out_2213680299147712687);
void live_h_35(double *state, double *unused, double *out_3392135172365373817);
void live_H_35(double *state, double *unused, double *out_4959243331472726396);
void live_h_32(double *state, double *unused, double *out_5713026107165599538);
void live_H_32(double *state, double *unused, double *out_8507087671459885125);
void live_h_13(double *state, double *unused, double *out_8591731605088062953);
void live_H_13(double *state, double *unused, double *out_1226506526531533769);
void live_h_14(double *state, double *unused, double *out_5944074116138401933);
void live_H_14(double *state, double *unused, double *out_2564586462254658463);
void live_h_33(double *state, double *unused, double *out_3376577180674409820);
void live_H_33(double *state, double *unused, double *out_3711442953127215872);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}