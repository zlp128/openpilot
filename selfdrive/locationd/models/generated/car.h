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
void car_err_fun(double *nom_x, double *delta_x, double *out_729362937437787457);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4929143687762803407);
void car_H_mod_fun(double *state, double *out_8315888887196402654);
void car_f_fun(double *state, double dt, double *out_7554938137534762046);
void car_F_fun(double *state, double dt, double *out_6130812160595680525);
void car_h_25(double *state, double *unused, double *out_8951477070372806105);
void car_H_25(double *state, double *unused, double *out_9087508506817314964);
void car_h_24(double *state, double *unused, double *out_4067561432286125622);
void car_H_24(double *state, double *unused, double *out_1669116873140388071);
void car_h_30(double *state, double *unused, double *out_7500845677743922938);
void car_H_30(double *state, double *unused, double *out_4831539236764628454);
void car_h_26(double *state, double *unused, double *out_8341493075156931027);
void car_H_26(double *state, double *unused, double *out_5617732248018180428);
void car_h_27(double *state, double *unused, double *out_5342806970691419479);
void car_H_27(double *state, double *unused, double *out_2656775924964203543);
void car_h_29(double *state, double *unused, double *out_2538465680062629706);
void car_H_29(double *state, double *unused, double *out_5341770581079020638);
void car_h_28(double *state, double *unused, double *out_572823783042442857);
void car_H_28(double *state, double *unused, double *out_7305400852644346889);
void car_h_31(double *state, double *unused, double *out_8893848845723381957);
void car_H_31(double *state, double *unused, double *out_4991524145784828952);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}