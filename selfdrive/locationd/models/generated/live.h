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
void live_H(double *in_vec, double *out_6690968010248080223);
void live_err_fun(double *nom_x, double *delta_x, double *out_5128644486154966433);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7600355658971333284);
void live_H_mod_fun(double *state, double *out_1685726956674156760);
void live_f_fun(double *state, double dt, double *out_774966178326963321);
void live_F_fun(double *state, double dt, double *out_7282145086155387076);
void live_h_4(double *state, double *unused, double *out_3936704980047894152);
void live_H_4(double *state, double *unused, double *out_9052514604414786102);
void live_h_9(double *state, double *unused, double *out_4670376777294811307);
void live_H_9(double *state, double *unused, double *out_9153039822665174869);
void live_h_10(double *state, double *unused, double *out_5114531167885874097);
void live_H_10(double *state, double *unused, double *out_8901083693322163334);
void live_h_12(double *state, double *unused, double *out_6249225679190641860);
void live_H_12(double *state, double *unused, double *out_4374773061262803719);
void live_h_35(double *state, double *unused, double *out_5751710703471722702);
void live_H_35(double *state, double *unused, double *out_1629210028937790010);
void live_h_32(double *state, double *unused, double *out_7960850640984836266);
void live_H_32(double *state, double *unused, double *out_8200477424115484408);
void live_h_13(double *state, double *unused, double *out_2913105661532148231);
void live_H_13(double *state, double *unused, double *out_6442117529364745675);
void live_h_14(double *state, double *unused, double *out_4670376777294811307);
void live_H_14(double *state, double *unused, double *out_9153039822665174869);
void live_h_33(double *state, double *unused, double *out_3733937587285700568);
void live_H_33(double *state, double *unused, double *out_1521346975701067594);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}