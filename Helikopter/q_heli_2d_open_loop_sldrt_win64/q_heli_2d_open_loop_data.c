/*
 * q_heli_2d_open_loop_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "q_heli_2d_open_loop".
 *
 * Model version              : 1.46
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon May 15 18:19:47 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_heli_2d_open_loop.h"
#include "q_heli_2d_open_loop_private.h"

/* Block parameters (auto storage) */
P_q_heli_2d_open_loop_T q_heli_2d_open_loop_P = {
  1.0,                                 /* Variable: K_AMP
                                        * Referenced by:
                                        *   '<S1>/Pitch amp Gain Pre-Compensation'
                                        *   '<S1>/Yaw amp Gain Pre-Compensation'
                                        */
  0.0026179938779914941,               /* Variable: K_EC_P
                                        * Referenced by: '<S1>/Encoder Resolution: Pitch '
                                        */
  0.0026179938779914941,               /* Variable: K_EC_Y
                                        * Referenced by: '<S1>/Encoder Resolution: Yaw'
                                        */
  3.2,                                 /* Variable: VMAX_AMP_P
                                        * Referenced by: '<S1>/Pitch AMP Voltage Limit'
                                        */
  3.2,                                 /* Variable: VMAX_AMP_Y
                                        * Referenced by: '<S1>/Yaw AMP Voltage Limit'
                                        */
  -0.82030474843733492,                /* Variable: theta_0
                                        * Referenced by: '<S1>/Bias'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_InitialValue
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S1>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_InputFilter
                                        * Referenced by: '<S1>/Encoder Input1'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S1>/Encoder Input'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput1_MaxMissedTicks
                                        * Referenced by: '<S1>/Encoder Input1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S1>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_YieldWhenWaiting
                                        * Referenced by: '<S1>/Encoder Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  1,                                   /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<S1>/Encoder Input'
                                        */
  1,                                   /* Mask Parameter: EncoderInput1_Channels
                                        * Referenced by: '<S1>/Encoder Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S2>/Signal Generator: Pitch (V)'
                                        */
  0.0001,                              /* Expression: 0.0001
                                        * Referenced by: '<S2>/Signal Generator: Pitch (V)'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S2>/Amplitude: Pitch (V)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant: Pitch (V)'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S2>/Signal Generator: Yaw (V)'
                                        */
  0.4,                                 /* Expression: 0.4
                                        * Referenced by: '<S2>/Signal Generator: Yaw (V)'
                                        */
  0.7,                                 /* Expression: 0.7
                                        * Referenced by: '<S2>/Amplitude: Yaw (V)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant: Yaw (V)'
                                        */

  /*  Computed Parameter: DerivativeFilterPitch_A
   * Referenced by: '<S1>/Derivative Filter: Pitch'
   */
  { -213.62830044410592, -15791.367041742973 },

  /*  Computed Parameter: DerivativeFilterPitch_C
   * Referenced by: '<S1>/Derivative Filter: Pitch'
   */
  { 15791.367041742973, 0.0 },

  /*  Computed Parameter: DerivativeFilterYaw_A
   * Referenced by: '<S1>/Derivative Filter: Yaw'
   */
  { -213.62830044410592, -15791.367041742973 },

  /*  Computed Parameter: DerivativeFilterYaw_C
   * Referenced by: '<S1>/Derivative Filter: Yaw'
   */
  { 15791.367041742973, 0.0 },

  /*  Expression: [0 0]
   * Referenced by: '<Root>/No Desired'
   */
  { 0.0, 0.0 },
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S6>/Gain'
                                        */

  /*  Expression: [0 0 0 0]
   * Referenced by: '<Root>/No Simulation'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<Root>/No Vm_sim'
                                        */
};
