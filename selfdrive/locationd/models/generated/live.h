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
void live_H(double *in_vec, double *out_4820339293882119518);
void live_err_fun(double *nom_x, double *delta_x, double *out_3392766111887124100);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2216925330683638231);
void live_H_mod_fun(double *state, double *out_679232602159257814);
void live_f_fun(double *state, double dt, double *out_6123814017633530199);
void live_F_fun(double *state, double dt, double *out_9115853419523662321);
void live_h_4(double *state, double *unused, double *out_6071256838368436397);
void live_H_4(double *state, double *unused, double *out_1119314742193140760);
void live_h_9(double *state, double *unused, double *out_7859104742158472266);
void live_H_9(double *state, double *unused, double *out_8406533677457588230);
void live_h_10(double *state, double *unused, double *out_4473856785133789330);
void live_H_10(double *state, double *unused, double *out_5999678041645387439);
void live_h_12(double *state, double *unused, double *out_7662391294081069133);
void live_H_12(double *state, double *unused, double *out_5261943634849592236);
void live_h_35(double *state, double *unused, double *out_7101706285091203473);
void live_H_35(double *state, double *unused, double *out_8884334182550116264);
void live_h_32(double *state, double *unused, double *out_6785252874119741308);
void live_H_32(double *state, double *unused, double *out_4617141584506488605);
void live_h_13(double *state, double *unused, double *out_8336853920327438524);
void live_H_13(double *state, double *unused, double *out_6724928250734846974);
void live_h_14(double *state, double *unused, double *out_7859104742158472266);
void live_H_14(double *state, double *unused, double *out_8406533677457588230);
void live_h_33(double *state, double *unused, double *out_3304821984098832254);
void live_H_33(double *state, double *unused, double *out_634176402114279077);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}