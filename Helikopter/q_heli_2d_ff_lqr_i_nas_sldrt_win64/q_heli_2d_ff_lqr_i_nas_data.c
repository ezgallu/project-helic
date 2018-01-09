/*
 * q_heli_2d_ff_lqr_i_nas_data.c
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

#include "q_heli_2d_ff_lqr_i_nas.h"
#include "q_heli_2d_ff_lqr_i_nas_private.h"

/* Block parameters (auto storage) */
P_q_heli_2d_ff_lqr_i_nas_T q_heli_2d_ff_lqr_i_nas_P = {
  0.3,                                 /* Variable: B_p
                                        * Referenced by: '<S23>/Pitch Viscous Damping'
                                        */
  0.45,                                /* Variable: B_y
                                        * Referenced by: '<S23>/Yaw Viscous Damping'
                                        */
  0.014688525,                         /* Variable: J_eq_p
                                        * Referenced by: '<S23>/Pitch Inertia'
                                        */
  0.016488525,                         /* Variable: J_eq_y
                                        * Referenced by: '<S31>/Yaw Inertia'
                                        */

  /*  Variable: K
   * Referenced by:
   *   '<S7>/Control Gain: K'
   *   '<S21>/Control Gain: K'
   */
  { 7.7196865466788154, 0.637526172816733, -0.52053794035679668,
    6.3030976711969968, 2.1103095628373452, 0.44026918237106588,
    0.10669129325471509, 0.878742431471067 },
  1.0,                                 /* Variable: K_AMP
                                        * Referenced by:
                                        *   '<S6>/Pitch amp Gain Pre-Compensation'
                                        *   '<S6>/Yaw amp Gain Pre-Compensation'
                                        */
  0.0026179938779914941,               /* Variable: K_EC_P
                                        * Referenced by: '<S6>/Encoder Resolution: Pitch '
                                        */
  0.0026179938779914941,               /* Variable: K_EC_Y
                                        * Referenced by: '<S6>/Encoder Resolution: Yaw'
                                        */
  1.0,                                 /* Variable: K_ff
                                        * Referenced by: '<S1>/FF Gain Adj.'
                                        */
  0.068249999999999991,                /* Variable: K_pp
                                        * Referenced by:
                                        *   '<S23>/Thrust torque from  Pitch Motor'
                                        *   '<S10>/Feed-forward Pitch Gain'
                                        *   '<S12>/Feed-forward Pitch Gain'
                                        *   '<S25>/Feed-forward Pitch Gain'
                                        *   '<S27>/Feed-forward Pitch Gain'
                                        */
  0.018,                               /* Variable: K_py
                                        * Referenced by: '<S23>/Cross-torque acting on Pitch  from Yaw Motor'
                                        */
  0.018,                               /* Variable: K_yp
                                        * Referenced by: '<S23>/Cross-torque acting on Yaw  from Pitch Motor'
                                        */
  0.06475,                             /* Variable: K_yy
                                        * Referenced by: '<S23>/Thrust torque from  Yaw Motor'
                                        */
  3.2,                                 /* Variable: SAT_INT_ERR_PITCH
                                        * Referenced by:
                                        *   '<S11>/Saturate'
                                        *   '<S26>/Saturate'
                                        */
  3.2,                                 /* Variable: SAT_INT_ERR_YAW
                                        * Referenced by:
                                        *   '<S13>/Saturate'
                                        *   '<S28>/Saturate'
                                        */
  1.0,                                 /* Variable: Tr_p
                                        * Referenced by:
                                        *   '<S11>/Pitch Reset Time'
                                        *   '<S26>/Pitch Reset Time'
                                        */
  1.0,                                 /* Variable: Tr_y
                                        * Referenced by:
                                        *   '<S13>/Yaw Reset Time'
                                        *   '<S28>/Yaw Reset Time'
                                        */
  3.2,                                 /* Variable: VMAX_AMP_P
                                        * Referenced by:
                                        *   '<S6>/Pitch AMP Voltage Limit'
                                        *   '<S23>/Pitch AMP Voltage Limit'
                                        */
  3.2,                                 /* Variable: VMAX_AMP_Y
                                        * Referenced by:
                                        *   '<S6>/Yaw AMP Voltage Limit'
                                        *   '<S23>/Yaw AMP Voltage Limit'
                                        */
  9.81,                                /* Variable: g
                                        * Referenced by:
                                        *   '<S10>/Feed-forward Pitch Gain'
                                        *   '<S12>/Feed-forward Pitch Gain'
                                        *   '<S25>/Feed-forward Pitch Gain'
                                        *   '<S27>/Feed-forward Pitch Gain'
                                        *   '<S29>/m*g*lcm'
                                        */
  0.005,                               /* Variable: l_cm
                                        * Referenced by:
                                        *   '<S10>/Feed-forward Pitch Gain'
                                        *   '<S12>/Feed-forward Pitch Gain'
                                        *   '<S25>/Feed-forward Pitch Gain'
                                        *   '<S27>/Feed-forward Pitch Gain'
                                        *   '<S29>/m*g*lcm'
                                        */
  0.459,                               /* Variable: m_heli
                                        * Referenced by:
                                        *   '<S23>/Pitch Inertia'
                                        *   '<S10>/Feed-forward Pitch Gain'
                                        *   '<S12>/Feed-forward Pitch Gain'
                                        *   '<S25>/Feed-forward Pitch Gain'
                                        *   '<S27>/Feed-forward Pitch Gain'
                                        *   '<S29>/m*g*lcm'
                                        *   '<S30>/m*lcm^2'
                                        *   '<S31>/m_heli*l_cm^2'
                                        *   '<S32>/2*m*lcm^2'
                                        */
  -0.82030474843733492,                /* Variable: theta_0
                                        * Referenced by:
                                        *   '<S6>/Bias'
                                        *   '<S23>/theta'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_InitialValue
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_InputFilter
                                        * Referenced by: '<S6>/Encoder Input1'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  10.0,                                /* Mask Parameter: EncoderInput1_MaxMissedTicks
                                        * Referenced by: '<S6>/Encoder Input1'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_YieldWhenWaiting
                                        * Referenced by: '<S6>/Encoder Input1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  3.0,                                 /* Mask Parameter: PitchRelay_const
                                        * Referenced by: '<S17>/Constant'
                                        */
  3.0,                                 /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S19>/Constant'
                                        */
  4.0,                                 /* Mask Parameter: YawRelay_const
                                        * Referenced by: '<S18>/Constant'
                                        */
  3.0,                                 /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S20>/Constant'
                                        */
  3.0,                                 /* Mask Parameter: PitchRelay_const_p
                                        * Referenced by: '<S36>/Constant'
                                        */
  3.0,                                 /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S38>/Constant'
                                        */
  4.0,                                 /* Mask Parameter: YawRelay_const_i
                                        * Referenced by: '<S37>/Constant'
                                        */
  3.0,                                 /* Mask Parameter: CompareToConstant_const_e
                                        * Referenced by: '<S39>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: ConstantPitchdeg_gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  0,                                   /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  1,                                   /* Mask Parameter: EncoderInput1_Channels
                                        * Referenced by: '<S6>/Encoder Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  1,                                   /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Signal Generator: Pitch (V)'
                                        */
  0.4,                                 /* Expression: 0.4
                                        * Referenced by: '<S4>/Signal Generator: Pitch (V)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Amplitude: Pitch (V)'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S4>/Constant: Pitch (V)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S3>/Signal Generator: Pitch'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S3>/Signal Generator: Pitch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Amplitude: Pitch (deg)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S41>/Gain1'
                                        */

  /*  Computed Parameter: DerivativeFilterPitch_A
   * Referenced by: '<S6>/Derivative Filter: Pitch'
   */
  { -213.62830044410592, -15791.367041742973 },

  /*  Computed Parameter: DerivativeFilterPitch_C
   * Referenced by: '<S6>/Derivative Filter: Pitch'
   */
  { 15791.367041742973, 0.0 },

  /*  Computed Parameter: DerivativeFilterYaw_A
   * Referenced by: '<S6>/Derivative Filter: Yaw'
   */
  { -213.62830044410592, -15791.367041742973 },

  /*  Computed Parameter: DerivativeFilterYaw_C
   * Referenced by: '<S6>/Derivative Filter: Yaw'
   */
  { 15791.367041742973, 0.0 },

  /*  Expression: -eye(4,4)
   * Referenced by: '<S7>/-X'
   */
  { -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -1.0 },
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S3>/Signal Generator: Yaw'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S3>/Signal Generator: Yaw'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Amplitude: Yaw (deg)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant: Yaw (deg)'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S42>/Gain1'
                                        */

  /*  Expression: -eye(4,4)
   * Referenced by: '<S8>/-X'
   */
  { -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -1.0 },

  /*  Expression: Ki(:,1:4)
   * Referenced by: '<S8>/Control Gain: K'
   */
  { 40.8206379832705, -1.8436449759392204, 5.7930453404271276,
    142.94028405657511, 27.428823485682567, -0.2311807851950943,
    3.5292669178383904, 44.4669067310925 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Signal Generator: Yaw (V)'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S4>/Signal Generator: Yaw (V)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Amplitude: Yaw (V)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant: Yaw (V)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory'
                                        */
  20.106037719786713,                  /* Expression: Ki(1,5)
                                        * Referenced by: '<S11>/Pitch Integral Control Gain: K(1,5)'
                                        */
  3.4387434443487805,                  /* Expression: Ki(1,6)
                                        * Referenced by: '<S11>/Yaw Cross-Integral Control Gain: K(1,6)'
                                        */
  79.982342073260511,                  /* Expression: Ki(2,6)
                                        * Referenced by: '<S13>/Yaw Integral Control Gain: K(2,6)'
                                        */
  -0.86443461904883989,                /* Expression: Ki(2,5)
                                        * Referenced by: '<S13>/Pitch Cross-Integral Control Gain: K(2,5)'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S44>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S45>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/psi'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/theta_dot'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/psi_dot'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S43>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */

  /*  Expression: -eye(4,4)
   * Referenced by: '<S21>/-X'
   */
  { -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -1.0 },

  /*  Expression: -eye(4,4)
   * Referenced by: '<S22>/-X'
   */
  { -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0,
    -0.0, -0.0, -1.0 },

  /*  Expression: Ki(:,1:4)
   * Referenced by: '<S22>/Control Gain: K'
   */
  { 40.8206379832705, -1.8436449759392204, 5.7930453404271276,
    142.94028405657511, 27.428823485682567, -0.2311807851950943,
    3.5292669178383904, 44.4669067310925 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S34>/Memory'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Memory'
                                        */
  20.106037719786713,                  /* Expression: Ki(1,5)
                                        * Referenced by: '<S26>/Pitch Integral Control Gain: K(1,5)'
                                        */
  3.4387434443487805,                  /* Expression: Ki(1,6)
                                        * Referenced by: '<S26>/Yaw Cross-Integral Control Gain: K(1,6)'
                                        */
  79.982342073260511,                  /* Expression: Ki(2,6)
                                        * Referenced by: '<S28>/Yaw Integral Control Gain: K(2,6)'
                                        */
  -0.86443461904883989,                /* Expression: Ki(2,5)
                                        * Referenced by: '<S28>/Pitch Cross-Integral Control Gain: K(2,5)'
                                        */
  1U,                                  /* Computed Parameter: PitchAdd1_Bias
                                        * Referenced by: '<S9>/Pitch: Add 1'
                                        */
  1U,                                  /* Computed Parameter: YawAdd1_Bias
                                        * Referenced by: '<S9>/Yaw: Add 1'
                                        */
  1U,                                  /* Computed Parameter: PitchAdd1_Bias_b
                                        * Referenced by: '<S24>/Pitch: Add 1'
                                        */
  1U                                   /* Computed Parameter: YawAdd1_Bias_j
                                        * Referenced by: '<S24>/Yaw: Add 1'
                                        */
};
