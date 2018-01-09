/*
 * PIDbrzina_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "PIDbrzina".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed May 24 17:17:48 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PIDbrzina.h"
#include "PIDbrzina_private.h"

/* Block parameters (auto storage) */
P_PIDbrzina_T PIDbrzina_P = {
  0.0001388888889,                     /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S3>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<S3>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S3>/Encoder Input'
                                        */
  10.0,                                /* Mask Parameter: AnalogInput_MaxMissedTicks
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S3>/Encoder Input'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S3>/Analog Output'
                                        */
  300.0,                               /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  2.3666666666667,                     /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  0.0,                                 /* Mask Parameter: AnalogInput_YieldWhenWaiting
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S3>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S3>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogInput_Channels
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  0,                                   /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<S3>/Encoder Input'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S3>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogInput_RangeMode
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S3>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogInput_VoltRange
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S3>/Analog Output'
                                        */
  -33.333333333333336,                 /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  33.333333333333336,                  /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  -0.06,                               /* Expression: -0.06
                                        * Referenced by: '<S2>/Gain'
                                        */
  666.66666666666663,                  /* Expression: (1000/1.5)
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.014285714285714285,                /* Expression: 1/70
                                        * Referenced by: '<S3>/Gain3'
                                        */
  0.10471975511965977,                 /* Expression: pi/30
                                        * Referenced by: '<S3>/Gain4'
                                        */
  -0.0015339807878856412,              /* Expression: -2*pi/4096
                                        * Referenced by: '<S3>/Gain2'
                                        */
  -10.0,                               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  -100.0,                              /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  10.0,                                /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -6.0,                                /* Expression: -6
                                        * Referenced by: '<S3>/Saturation'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S2>/Constant'
                                        */
  12.5,                                /* Expression: 12.5
                                        * Referenced by: '<S2>/Signal Generator'
                                        */
  0.15915494309189535,                 /* Computed Parameter: SignalGenerator_Frequency
                                        * Referenced by: '<S2>/Signal Generator'
                                        */
  0U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S3>/Manual Switch'
                                        */
};
