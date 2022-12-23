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
void car_err_fun(double *nom_x, double *delta_x, double *out_8581923876106076715);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4891521151268278961);
void car_H_mod_fun(double *state, double *out_6523549794488946483);
void car_f_fun(double *state, double dt, double *out_3111820312432597939);
void car_F_fun(double *state, double dt, double *out_5596968740727191559);
void car_h_25(double *state, double *unused, double *out_8255502319032992897);
void car_H_25(double *state, double *unused, double *out_8118118653173567889);
void car_h_24(double *state, double *unused, double *out_5005612245441996689);
void car_H_24(double *state, double *unused, double *out_5892410869194699327);
void car_h_30(double *state, double *unused, double *out_3420406528326207783);
void car_H_30(double *state, double *unused, double *out_1201428311681951134);
void car_h_26(double *state, double *unused, double *out_1805500687509117164);
void car_H_26(double *state, double *unused, double *out_6587122101661927503);
void car_h_27(double *state, double *unused, double *out_9023497953600416982);
void car_H_27(double *state, double *unused, double *out_3376191623482376045);
void car_h_29(double *state, double *unused, double *out_9148052057824628745);
void car_H_29(double *state, double *unused, double *out_691196967367558950);
void car_h_28(double *state, double *unused, double *out_402702707668658192);
void car_H_28(double *state, double *unused, double *out_5773595984437089524);
void car_h_31(double *state, double *unused, double *out_6661654130949307838);
void car_H_31(double *state, double *unused, double *out_8087472691296607461);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}