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
void live_H(double *in_vec, double *out_7275051445048872074);
void live_err_fun(double *nom_x, double *delta_x, double *out_900214999320880639);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6228497090895348531);
void live_H_mod_fun(double *state, double *out_6900568612264374751);
void live_f_fun(double *state, double dt, double *out_444317293709373841);
void live_F_fun(double *state, double dt, double *out_833440091851189730);
void live_h_4(double *state, double *unused, double *out_5875214861579885541);
void live_H_4(double *state, double *unused, double *out_276857831883521901);
void live_h_9(double *state, double *unused, double *out_7431485379286447551);
void live_H_9(double *state, double *unused, double *out_7564076767147969371);
void live_h_10(double *state, double *unused, double *out_8274293454775594883);
void live_H_10(double *state, double *unused, double *out_3646697484698039257);
void live_h_12(double *state, double *unused, double *out_7462563038781612366);
void live_H_12(double *state, double *unused, double *out_6104400545159211095);
void live_h_35(double *state, double *unused, double *out_3219025280718560296);
void live_H_35(double *state, double *unused, double *out_3358837512834197386);
void live_h_32(double *state, double *unused, double *out_5537109185631613612);
void live_H_32(double *state, double *unused, double *out_3774684674196869746);
void live_h_13(double *state, double *unused, double *out_1615263710325240669);
void live_H_13(double *state, double *unused, double *out_1846820156559909960);
void live_h_14(double *state, double *unused, double *out_7431485379286447551);
void live_H_14(double *state, double *unused, double *out_7564076767147969371);
void live_h_33(double *state, double *unused, double *out_4659271231748144567);
void live_H_33(double *state, double *unused, double *out_4606637891179707910);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}