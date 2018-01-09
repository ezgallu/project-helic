/*
 * ukupni_model_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "ukupni_model".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu Jun 08 09:23:03 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ukupni_model.h"
#include "ukupni_model_private.h"

/* Block parameters (auto storage) */
P_ukupni_model_T ukupni_model_P = {
  0.08,                                /* Variable: B_p
                                        * Referenced by: '<S17>/Pitch Viscous Damping'
                                        */
  0.14,                                /* Variable: B_y
                                        * Referenced by: '<S17>/Yaw Viscous Damping'
                                        */
  0.016488525,                         /* Variable: J_eq_y
                                        * Referenced by: '<S23>/Yaw Inertia'
                                        */
  0.0147,                              /* Variable: J_p
                                        * Referenced by: '<S17>/Pitch Inertia'
                                        */
  0.0026179938779914941,               /* Variable: K_EC_P
                                        * Referenced by: '<S5>/Encoder Resolution: Pitch '
                                        */
  0.0026179938779914941,               /* Variable: K_EC_Y
                                        * Referenced by: '<S5>/Encoder Resolution: Yaw'
                                        */
  0.04875,                             /* Variable: K_pp
                                        * Referenced by:
                                        *   '<S17>/Thrust torque from  Pitch Motor'
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        */
  0.01,                                /* Variable: K_py
                                        * Referenced by: '<S17>/Cross-torque acting on Pitch  from Yaw Motor'
                                        */
  0.01,                                /* Variable: K_yp
                                        * Referenced by: '<S17>/Cross-torque acting on Yaw  from Pitch Motor'
                                        */
  0.04625,                             /* Variable: K_yy
                                        * Referenced by: '<S17>/Thrust torque from  Yaw Motor'
                                        */
  1.0,                                 /* Variable: Tr_p
                                        * Referenced by:
                                        *   '<S7>/Pitch Reset Time'
                                        *   '<S19>/Pitch Reset Time'
                                        */
  1.0,                                 /* Variable: Tr_y
                                        * Referenced by:
                                        *   '<S9>/Yaw Reset Time'
                                        *   '<S20>/Yaw Reset Time'
                                        */
  9.81,                                /* Variable: g
                                        * Referenced by:
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        *   '<S21>/m*g*lcm'
                                        */
  0.005,                               /* Variable: l_cm
                                        * Referenced by:
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        *   '<S21>/m*g*lcm'
                                        */
  0.459,                               /* Variable: m_heli
                                        * Referenced by:
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        *   '<S21>/m*g*lcm'
                                        *   '<S22>/m*lcm^2'
                                        *   '<S23>/m_heli*l_cm^2'
                                        *   '<S24>/2*m*lcm^2'
                                        */
  3.5,                                 /* Variable: max_u
                                        * Referenced by:
                                        *   '<S5>/Pitch AMP Voltage Limit'
                                        *   '<S5>/Yaw AMP Voltage Limit'
                                        *   '<S17>/Pitch AMP Voltage Limit'
                                        *   '<S17>/Yaw AMP Voltage Limit'
                                        *   '<S7>/Saturate'
                                        *   '<S9>/Saturate'
                                        *   '<S19>/Saturate'
                                        *   '<S20>/Saturate'
                                        */
  -1.0471975511965976,                 /* Variable: theta_0
                                        * Referenced by:
                                        *   '<S5>/Bias'
                                        *   '<S17>/theta'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_InitialValue
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_InputFilter
                                        * Referenced by: '<S5>/Encoder Input1'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput1_MaxMissedTicks
                                        * Referenced by: '<S5>/Encoder Input1'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_YieldWhenWaiting
                                        * Referenced by: '<S5>/Encoder Input1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  1.0,                                 /* Mask Parameter: ConstantPitchdeg_gain
                                        * Referenced by: '<S10>/Slider Gain'
                                        */
  0,                                   /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  1,                                   /* Mask Parameter: EncoderInput1_Channels
                                        * Referenced by: '<S5>/Encoder Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  1,                                   /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  15.0,                                /* Expression: 15
                                        * Referenced by: '<S2>/Signal Generator: Pitch'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S2>/Signal Generator: Pitch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Pitch (deg)'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S2>/Constant'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S11>/Gain1'
                                        */

  /*  Computed Parameter: DerivativeFilterPitch_A
   * Referenced by: '<S5>/Derivative Filter: Pitch'
   */
  { -213.62830044410592, -15791.367041742973 },

  /*  Computed Parameter: DerivativeFilterPitch_C
   * Referenced by: '<S5>/Derivative Filter: Pitch'
   */
  { 15791.367041742973, 0.0 },

  /*  Computed Parameter: DerivativeFilterYaw_A
   * Referenced by: '<S5>/Derivative Filter: Yaw'
   */
  { -213.62830044410592, -15791.367041742973 },

  /*  Computed Parameter: DerivativeFilterYaw_C
   * Referenced by: '<S5>/Derivative Filter: Yaw'
   */
  { 15791.367041742973, 0.0 },

  /*  Expression: -eye(4,4)
   * Referenced by: '<S6>/-X'
   */
  { -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -1.0 },
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S2>/Signal Generator: Yaw'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S2>/Signal Generator: Yaw'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Yaw (deg)'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S2>/Constant: Yaw (deg)'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S12>/Gain1'
                                        */

  /*  Expression: K_i(:,1:4)
   * Referenced by: '<S6>/Control Gain: K'
   */
  { 16.66843166042479, 0.71175748418616414, -0.89938212771513426,
    15.728637375460345, 8.93299808728088, 0.65749140190796618,
    -0.040591886191590966, 6.2413444174633836 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S5>/Gain1'
                                        */
  7.7365443182512905,                  /* Expression: K_i(1,5)
                                        * Referenced by: '<S7>/Pitch Integral Control Gain: K(1,5)'
                                        */
  -0.42225612673350693,                /* Expression: K_i(1,6)
                                        * Referenced by: '<S7>/Yaw Cross-Integral Control Gain: K(1,6)'
                                        */
  8.5530715591984432,                  /* Expression: K_i(2,6)
                                        * Referenced by: '<S9>/Yaw Integral Control Gain: K(2,6)'
                                        */
  0.38194503758287385,                 /* Expression: K_i(2,5)
                                        * Referenced by: '<S9>/Pitch Cross-Integral Control Gain: K(2,5)'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  1.0471975511965976,                  /* Expression: 60*pi/180
                                        * Referenced by: '<S17>/theta'
                                        */
  -1.0471975511965976,                 /* Expression: -60*pi/180
                                        * Referenced by: '<S17>/theta'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/psi'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/theta_dot'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/psi_dot'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */

  /*  Expression: -eye(4,4)
   * Referenced by: '<S16>/-X'
   */
  { -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -1.0 },

  /*  Expression: K_i(:,1:4)
   * Referenced by: '<S16>/Control Gain: K'
   */
  { 16.66843166042479, 0.71175748418616414, -0.89938212771513426,
    15.728637375460345, 8.93299808728088, 0.65749140190796618,
    -0.040591886191590966, 6.2413444174633836 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Integrator'
                                        */
  7.7365443182512905,                  /* Expression: K_i(1,5)
                                        * Referenced by: '<S19>/Pitch Integral Control Gain: K(1,5)'
                                        */
  -0.42225612673350693,                /* Expression: K_i(1,6)
                                        * Referenced by: '<S19>/Yaw Cross-Integral Control Gain: K(1,6)'
                                        */
  8.5530715591984432,                  /* Expression: K_i(2,6)
                                        * Referenced by: '<S20>/Yaw Integral Control Gain: K(2,6)'
                                        */
  0.38194503758287385                  /* Expression: K_i(2,5)
                                        * Referenced by: '<S20>/Pitch Cross-Integral Control Gain: K(2,5)'
                                        */
};
