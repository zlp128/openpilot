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
void live_H(double *in_vec, double *out_4368495907718343571);
void live_err_fun(double *nom_x, double *delta_x, double *out_4465536791498929799);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4242153094211941637);
void live_H_mod_fun(double *state, double *out_8694534732588551911);
void live_f_fun(double *state, double dt, double *out_331980123976991440);
void live_F_fun(double *state, double dt, double *out_7523521905118560137);
void live_h_4(double *state, double *unused, double *out_874158167075593511);
void live_H_4(double *state, double *unused, double *out_2890470532950944797);
void live_h_9(double *state, double *unused, double *out_7169843762143865122);
void live_H_9(double *state, double *unused, double *out_5779332085231024139);
void live_h_10(double *state, double *unused, double *out_3163124755553653720);
void live_H_10(double *state, double *unused, double *out_4896893583908803739);
void live_h_12(double *state, double *unused, double *out_6187507614461106032);
void live_H_12(double *state, double *unused, double *out_7889145227076156327);
void live_h_35(double *state, double *unused, double *out_4266066339955691863);
void live_H_35(double *state, double *unused, double *out_5143582194751142618);
void live_h_32(double *state, double *unused, double *out_9055313354289894635);
void live_H_32(double *state, double *unused, double *out_6388297375264292642);
void live_h_13(double *state, double *unused, double *out_7078564321862276630);
void live_H_13(double *state, double *unused, double *out_7646665591930494052);
void live_h_14(double *state, double *unused, double *out_7169843762143865122);
void live_H_14(double *state, double *unused, double *out_5779332085231024139);
void live_h_33(double *state, double *unused, double *out_3878198370963190653);
void live_H_33(double *state, double *unused, double *out_1993025190112285014);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}