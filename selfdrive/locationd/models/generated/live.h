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
void live_H(double *in_vec, double *out_6240008686817713408);
void live_err_fun(double *nom_x, double *delta_x, double *out_3690665086918622964);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_8615868703535681088);
void live_H_mod_fun(double *state, double *out_1988291488770769521);
void live_f_fun(double *state, double dt, double *out_3263988285527381505);
void live_F_fun(double *state, double dt, double *out_4332092747232242913);
void live_h_4(double *state, double *unused, double *out_6582152946104087701);
void live_H_4(double *state, double *unused, double *out_8426954437225368770);
void live_h_9(double *state, double *unused, double *out_7444569565063482614);
void live_H_9(double *state, double *unused, double *out_7130928084204103504);
void live_h_10(double *state, double *unused, double *out_1939752611965379146);
void live_H_10(double *state, double *unused, double *out_6385265893824183484);
void live_h_12(double *state, double *unused, double *out_7296993372404775801);
void live_H_12(double *state, double *unused, double *out_2352661322801732354);
void live_h_35(double *state, double *unused, double *out_947171662528612088);
void live_H_35(double *state, double *unused, double *out_392901709523281355);
void live_h_32(double *state, double *unused, double *out_2929900686975731664);
void live_H_32(double *state, double *unused, double *out_8907135071749521650);
void live_h_13(double *state, double *unused, double *out_4581312559012542837);
void live_H_13(double *state, double *unused, double *out_569470278268388809);
void live_h_14(double *state, double *unused, double *out_7444569565063482614);
void live_H_14(double *state, double *unused, double *out_7130928084204103504);
void live_h_33(double *state, double *unused, double *out_7317084925230058116);
void live_H_33(double *state, double *unused, double *out_3543458714162138959);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}