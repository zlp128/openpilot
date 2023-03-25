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
void live_H(double *in_vec, double *out_2989134609448912360);
void live_err_fun(double *nom_x, double *delta_x, double *out_4134642150611912562);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_102578031842580524);
void live_H_mod_fun(double *state, double *out_1333467034631963441);
void live_f_fun(double *state, double dt, double *out_1638653065682139689);
void live_F_fun(double *state, double dt, double *out_3627592268953963269);
void live_h_4(double *state, double *unused, double *out_8187072558274677226);
void live_H_4(double *state, double *unused, double *out_5073553165915915446);
void live_h_9(double *state, double *unused, double *out_7751183598308146162);
void live_H_9(double *state, double *unused, double *out_6085971972529188700);
void live_h_10(double *state, double *unused, double *out_7475415363803884616);
void live_H_10(double *state, double *unused, double *out_7599748917935120017);
void live_h_12(double *state, double *unused, double *out_4560316742219209161);
void live_H_12(double *state, double *unused, double *out_8353734499761674375);
void live_h_35(double *state, double *unused, double *out_395256144382285655);
void live_H_35(double *state, double *unused, double *out_5608171467436660666);
void live_h_32(double *state, double *unused, double *out_2629447041285500641);
void live_H_32(double *state, double *unused, double *out_5477006682495920197);
void live_h_13(double *state, double *unused, double *out_4411752618062649722);
void live_H_13(double *state, double *unused, double *out_6527861414729128748);
void live_h_14(double *state, double *unused, double *out_7751183598308146162);
void live_H_14(double *state, double *unused, double *out_6085971972529188700);
void live_h_33(double *state, double *unused, double *out_6706316243285295529);
void live_H_33(double *state, double *unused, double *out_2457614462797803062);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}