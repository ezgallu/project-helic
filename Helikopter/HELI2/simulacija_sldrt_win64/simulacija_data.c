/*
 * simulacija_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "simulacija".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed May 31 15:47:03 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simulacija.h"
#include "simulacija_private.h"

/* Block parameters (auto storage) */
P_simulacija_T simulacija_P = {
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<Root>/Encoder Input'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<Root>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<Root>/Encoder Input'
                                        */
  2.0,                                 /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S1>/Step'
                                        */
  5.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S1>/Step'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<Root>/Encoder Input'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<Root>/Step'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  14.0,                                /* Expression: 14
                                        * Referenced by: '<Root>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<Root>/Step1'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -4.0                                 /* Expression: -4
                                        * Referenced by: '<Root>/Saturation'
                                        */
};
