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
void live_H(double *in_vec, double *out_4500389823279432985);
void live_err_fun(double *nom_x, double *delta_x, double *out_1913535744177293566);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2851117358798162907);
void live_H_mod_fun(double *state, double *out_2697157995522224710);
void live_f_fun(double *state, double dt, double *out_258969813900144001);
void live_F_fun(double *state, double dt, double *out_3982048512447115253);
void live_h_4(double *state, double *unused, double *out_3062002944620705961);
void live_H_4(double *state, double *unused, double *out_3011098296458653357);
void live_h_9(double *state, double *unused, double *out_5633073678966500073);
void live_H_9(double *state, double *unused, double *out_3252287943088244002);
void live_h_10(double *state, double *unused, double *out_4956664653644560279);
void live_H_10(double *state, double *unused, double *out_4513091182693755627);
void live_h_12(double *state, double *unused, double *out_5780595779529914179);
void live_H_12(double *state, double *unused, double *out_3632197321506247024);
void live_h_35(double *state, double *unused, double *out_190113666816480701);
void live_H_35(double *state, double *unused, double *out_6377760353831260733);
void live_h_32(double *state, double *unused, double *out_1962437249848893520);
void live_H_32(double *state, double *unused, double *out_6267679347670678325);
void live_h_13(double *state, double *unused, double *out_1422098576590259012);
void live_H_13(double *state, double *unused, double *out_979728642438066826);
void live_h_14(double *state, double *unused, double *out_5633073678966500073);
void live_H_14(double *state, double *unused, double *out_3252287943088244002);
void live_h_33(double *state, double *unused, double *out_4297372334290366217);
void live_H_33(double *state, double *unused, double *out_8918426715239433279);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}