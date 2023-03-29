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
void live_H(double *in_vec, double *out_7959907782308194627);
void live_err_fun(double *nom_x, double *delta_x, double *out_6929774310989775988);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6193789776824585571);
void live_H_mod_fun(double *state, double *out_8547509152961498922);
void live_f_fun(double *state, double dt, double *out_8100393315288221642);
void live_F_fun(double *state, double dt, double *out_7769089323050102648);
void live_h_4(double *state, double *unused, double *out_6579737165675804813);
void live_H_4(double *state, double *unused, double *out_8985066658053328462);
void live_h_9(double *state, double *unused, double *out_6592276556226636800);
void live_H_9(double *state, double *unused, double *out_6096205105773249120);
void live_h_10(double *state, double *unused, double *out_3043512482999151809);
void live_H_10(double *state, double *unused, double *out_7192958685017806166);
void live_h_12(double *state, double *unused, double *out_6151089362108428494);
void live_H_12(double *state, double *unused, double *out_1317938344370877970);
void live_h_35(double *state, double *unused, double *out_1134950865722680502);
void live_H_35(double *state, double *unused, double *out_1427624687954135739);
void live_h_32(double *state, double *unused, double *out_4721207292266360875);
void live_H_32(double *state, double *unused, double *out_2913380087778971149);
void live_h_13(double *state, double *unused, double *out_364134050257467252);
void live_H_13(double *state, double *unused, double *out_5486592313647626777);
void live_h_14(double *state, double *unused, double *out_6592276556226636800);
void live_H_14(double *state, double *unused, double *out_6096205105773249120);
void live_h_33(double *state, double *unused, double *out_3737322617129334857);
void live_H_33(double *state, double *unused, double *out_4578181692592993343);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}