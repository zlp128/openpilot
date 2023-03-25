#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_559111814741085424);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8525802223358923727);
void car_H_mod_fun(double *state, double *out_6521334698987505192);
void car_f_fun(double *state, double dt, double *out_5157815911269073647);
void car_F_fun(double *state, double dt, double *out_4341564588224271600);
void car_h_25(double *state, double *unused, double *out_8809968363646297090);
void car_H_25(double *state, double *unused, double *out_1959634654218019643);
void car_h_24(double *state, double *unused, double *out_8028835485487409495);
void car_H_24(double *state, double *unused, double *out_2786874672748489391);
void car_h_30(double *state, double *unused, double *out_8967155031997426235);
void car_H_30(double *state, double *unused, double *out_4477967612725268270);
void car_h_26(double *state, double *unused, double *out_4004775034316133003);
void car_H_26(double *state, double *unused, double *out_5264160623978820244);
void car_h_27(double *state, double *unused, double *out_6824223606793401143);
void car_H_27(double *state, double *unused, double *out_2303204300924843359);
void car_h_29(double *state, double *unused, double *out_53388380443050207);
void car_H_29(double *state, double *unused, double *out_4988198957039660454);
void car_h_28(double *state, double *unused, double *out_6620847199255304828);
void car_H_28(double *state, double *unused, double *out_94200060029870120);
void car_h_31(double *state, double *unused, double *out_9085162425930802979);
void car_H_31(double *state, double *unused, double *out_4637952521745468768);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}