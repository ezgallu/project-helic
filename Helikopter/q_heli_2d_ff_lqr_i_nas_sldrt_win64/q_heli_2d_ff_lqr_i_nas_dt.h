/*
 * q_heli_2d_ff_lqr_i_nas_dt.h
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "q_heli_2d_ff_lqr_i_nas".
 *
 * Model version              : 1.275
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Fri May 19 15:08:53 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&q_heli_2d_ff_lqr_i_nas_B.SignalGeneratorPitchV), 0, 0, 194 },

  { (char_T *)(&q_heli_2d_ff_lqr_i_nas_B.Compare), 3, 0, 12 }
  ,

  { (char_T *)(&q_heli_2d_ff_lqr_i_nas_DW.Add_DWORK1), 0, 0, 5 },

  { (char_T *)(&q_heli_2d_ff_lqr_i_nas_DW.EncoderInput_PWORK), 11, 0, 10 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&q_heli_2d_ff_lqr_i_nas_P.B_p), 0, 0, 53 },

  { (char_T *)(&q_heli_2d_ff_lqr_i_nas_P.EncoderInput_Channels), 6, 0, 8 },

  { (char_T *)
    (&q_heli_2d_ff_lqr_i_nas_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value), 0, 0,
    136 },

  { (char_T *)(&q_heli_2d_ff_lqr_i_nas_P.PitchAdd1_Bias), 3, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] q_heli_2d_ff_lqr_i_nas_dt.h */
