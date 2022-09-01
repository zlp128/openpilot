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
void live_H(double *in_vec, double *out_734965431798586088);
void live_err_fun(double *nom_x, double *delta_x, double *out_7867135572176938343);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4469849344899012791);
void live_H_mod_fun(double *state, double *out_482044005104989923);
void live_f_fun(double *state, double dt, double *out_5277401503139322236);
void live_F_fun(double *state, double dt, double *out_6716422747633413136);
void live_h_4(double *state, double *unused, double *out_7766204740505938751);
void live_H_4(double *state, double *unused, double *out_5987995952750113477);
void live_h_9(double *state, double *unused, double *out_2388230207696517986);
void live_H_9(double *state, double *unused, double *out_6229185599379704122);
void live_h_10(double *state, double *unused, double *out_9053893872496357561);
void live_H_10(double *state, double *unused, double *out_140518164600154776);
void live_h_12(double *state, double *unused, double *out_835136029362175519);
void live_H_12(double *state, double *unused, double *out_6609094977797707144);
void live_h_35(double *state, double *unused, double *out_93555897102822674);
void live_H_35(double *state, double *unused, double *out_9092086063586830763);
void live_h_32(double *state, double *unused, double *out_6290965057558394135);
void live_H_32(double *state, double *unused, double *out_2439793506428604497);
void live_h_13(double *state, double *unused, double *out_8490099498842921417);
void live_H_13(double *state, double *unused, double *out_8653375813311677152);
void live_h_14(double *state, double *unused, double *out_2388230207696517986);
void live_H_14(double *state, double *unused, double *out_6229185599379704122);
void live_h_33(double *state, double *unused, double *out_3386383232379514061);
void live_H_33(double *state, double *unused, double *out_5941529058947973159);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}