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
void live_H(double *in_vec, double *out_919321204285207253);
void live_err_fun(double *nom_x, double *delta_x, double *out_1239592434612673434);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_8424707651892025503);
void live_H_mod_fun(double *state, double *out_3398846321270000840);
void live_f_fun(double *state, double dt, double *out_5945410084485745517);
void live_F_fun(double *state, double dt, double *out_1406202444158773973);
void live_h_4(double *state, double *unused, double *out_855318047403330363);
void live_H_4(double *state, double *unused, double *out_7229846732012737030);
void live_h_9(double *state, double *unused, double *out_2075713419116157705);
void live_H_9(double *state, double *unused, double *out_4340985179732657688);
void live_h_10(double *state, double *unused, double *out_4871234396170298071);
void live_H_10(double *state, double *unused, double *out_6664980085443225062);
void live_h_12(double *state, double *unused, double *out_59445924731046944);
void live_H_12(double *state, double *unused, double *out_437281581669713462);
void live_h_35(double *state, double *unused, double *out_5470579135920011702);
void live_H_35(double *state, double *unused, double *out_3863184674640129654);
void live_h_32(double *state, double *unused, double *out_61541883826926771);
void live_H_32(double *state, double *unused, double *out_4156829226020876432);
void live_h_13(double *state, double *unused, double *out_4436606334341082472);
void live_H_13(double *state, double *unused, double *out_7475084592984867636);
void live_h_14(double *state, double *unused, double *out_2075713419116157705);
void live_H_14(double *state, double *unused, double *out_4340985179732657688);
void live_h_33(double *state, double *unused, double *out_7363698010792310478);
void live_H_33(double *state, double *unused, double *out_712627670001272050);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}