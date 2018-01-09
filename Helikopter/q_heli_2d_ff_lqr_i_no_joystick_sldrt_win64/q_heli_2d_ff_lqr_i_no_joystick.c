/*
 * q_heli_2d_ff_lqr_i_no_joystick.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "q_heli_2d_ff_lqr_i_no_joystick".
 *
 * Model version              : 1.273
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu May 18 19:04:35 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_heli_2d_ff_lqr_i_no_joystick.h"
#include "q_heli_2d_ff_lqr_i_no_joystick_private.h"
#include "q_heli_2d_ff_lqr_i_no_joystick_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Quanser/MultiQ-PCI", 4294967295U, 0, NULL },
};

/* Block signals (auto storage) */
B_q_heli_2d_ff_lqr_i_no_joystick_T q_heli_2d_ff_lqr_i_no_joystick_B;

/* Continuous states */
X_q_heli_2d_ff_lqr_i_no_joystick_T q_heli_2d_ff_lqr_i_no_joystick_X;

/* Block states (auto storage) */
DW_q_heli_2d_ff_lqr_i_no_joystick_T q_heli_2d_ff_lqr_i_no_joystick_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_q_heli_2d_ff_lqr_i_no_joystick_T q_heli_2d_ff_lqr_i_no_joystick_PrevZCX;

/* Real-time model */
RT_MODEL_q_heli_2d_ff_lqr_i_no_joystick_T q_heli_2d_ff_lqr_i_no_joystick_M_;
RT_MODEL_q_heli_2d_ff_lqr_i_no_joystick_T *const
  q_heli_2d_ff_lqr_i_no_joystick_M = &q_heli_2d_ff_lqr_i_no_joystick_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  q_heli_2d_ff_lqr_i_no_joystick_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  q_heli_2d_ff_lqr_i_no_joystick_output();
  q_heli_2d_ff_lqr_i_no_joystick_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  q_heli_2d_ff_lqr_i_no_joystick_output();
  q_heli_2d_ff_lqr_i_no_joystick_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void q_heli_2d_ff_lqr_i_no_joystick_output(void)
{
  real_T temp;
  boolean_T zcEvent;
  ZCEventType zcEvent_0;
  int32_T i;
  real_T u0;
  real_T u2;
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* set solver stop time */
    if (!(q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                            ((q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTickH0
        + 1) * q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                            ((q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTick0
        + 1) * q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize0 +
        q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTickH0 *
        q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.t[0] = rtsiGetT
      (&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S17>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       == q_heli_2d_ff_lqr_i_no_joystick_P.PitchRelay_const);

    /* Bias: '<S9>/Pitch: Add 1' */
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAdd1 = (uint8_T)((uint32_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare +
      q_heli_2d_ff_lqr_i_no_joystick_P.PitchAdd1_Bias);
  }

  /* SignalGenerator: '<S4>/Signal Generator: Pitch (V)' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorPitchV_Frequency *
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitchV =
      q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorPitchV_Amplitude;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitchV =
      -q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorPitchV_Amplitude;
  }

  /* End of SignalGenerator: '<S4>/Signal Generator: Pitch (V)' */

  /* Gain: '<S4>/Amplitude: Pitch (V)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudePitchV =
    q_heli_2d_ff_lqr_i_no_joystick_P.AmplitudePitchV_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitchV;

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/Constant: Pitch (V)'
   */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum =
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudePitchV +
    q_heli_2d_ff_lqr_i_no_joystick_P.ConstantPitchV_Value;

  /* MultiPortSwitch: '<S9>/Choose Pitch Relay' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (q_heli_2d_ff_lqr_i_no_joystick_B.PitchAdd1 == 1) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay =
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay =
      q_heli_2d_ff_lqr_i_no_joystick_B.Sum;
  }

  /* End of MultiPortSwitch: '<S9>/Choose Pitch Relay' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* RelationalOperator: '<S19>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S19>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare_m = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       >= q_heli_2d_ff_lqr_i_no_joystick_P.CompareToConstant_const);

    /* Sum: '<S15>/Add' incorporates:
     *  Constant: '<S15>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Add = (real_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare_m +
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value_i;
  }

  /* SignalGenerator: '<S3>/Signal Generator: Pitch' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorPitch_Frequency *
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitch =
      q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorPitch_Amplitude;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitch =
      -q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorPitch_Amplitude;
  }

  /* End of SignalGenerator: '<S3>/Signal Generator: Pitch' */

  /* Gain: '<S3>/Amplitude: Pitch (deg)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudePitchdeg =
    q_heli_2d_ff_lqr_i_no_joystick_P.AmplitudePitchdeg_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitch;
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* Gain: '<S40>/Slider Gain' incorporates:
     *  Constant: '<S3>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.SliderGain =
      q_heli_2d_ff_lqr_i_no_joystick_P.ConstantPitchdeg_gain *
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value_k;
  }

  /* Sum: '<S3>/Sum' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum_h =
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudePitchdeg +
    q_heli_2d_ff_lqr_i_no_joystick_B.SliderGain;

  /* Gain: '<S41>/Gain1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain1 =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain1_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum_h;
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* S-Function Block: <S6>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput_Channels,
                     &q_heli_2d_ff_lqr_i_no_joystick_B.EncoderInput, &parm);
    }

    /* S-Function Block: <S6>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput1_Channels,
                     &q_heli_2d_ff_lqr_i_no_joystick_B.EncoderInput1, &parm);
    }

    /* Gain: '<S6>/Encoder Resolution: Pitch ' */
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionPitch =
      q_heli_2d_ff_lqr_i_no_joystick_P.K_EC_P *
      q_heli_2d_ff_lqr_i_no_joystick_B.EncoderInput;

    /* Bias: '<S6>/Bias' */
    q_heli_2d_ff_lqr_i_no_joystick_B.Bias =
      q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionPitch +
      q_heli_2d_ff_lqr_i_no_joystick_P.theta_0;

    /* Gain: '<S6>/Encoder Resolution: Yaw' */
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionYaw =
      q_heli_2d_ff_lqr_i_no_joystick_P.K_EC_Y *
      q_heli_2d_ff_lqr_i_no_joystick_B.EncoderInput1;
  }

  /* TransferFcn: '<S6>/Derivative Filter: Pitch' */
  q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterPitch = 0.0;
  q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterPitch +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterPitch_C[0] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterPitch_CSTATE[0];
  q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterPitch +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterPitch_C[1] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterPitch_CSTATE[1];

  /* TransferFcn: '<S6>/Derivative Filter: Yaw' */
  q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterYaw = 0.0;
  q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterYaw +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterYaw_C[0] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterYaw_CSTATE[0];
  q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterYaw +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterYaw_C[1] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterYaw_CSTATE[1];

  /* SignalConversion: '<S7>/TmpSignal ConversionAt-XInport1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[0] =
    q_heli_2d_ff_lqr_i_no_joystick_B.Bias;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[1] =
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionYaw;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[2] =
    q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterPitch;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[3] =
    q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterYaw;

  /* Gain: '<S7>/-X' */
  for (i = 0; i < 4; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.X[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[0];
    q_heli_2d_ff_lqr_i_no_joystick_B.X[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[1];
    q_heli_2d_ff_lqr_i_no_joystick_B.X[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain[i + 8] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[2];
    q_heli_2d_ff_lqr_i_no_joystick_B.X[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain[i + 12] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[3];
  }

  /* End of Gain: '<S7>/-X' */

  /* Sum: '<S7>/Sum2' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum2 = q_heli_2d_ff_lqr_i_no_joystick_B.Gain1
    + q_heli_2d_ff_lqr_i_no_joystick_B.X[0];

  /* SignalGenerator: '<S3>/Signal Generator: Yaw' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorYaw_Frequency *
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYaw =
      q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorYaw_Amplitude;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYaw =
      -q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorYaw_Amplitude;
  }

  /* End of SignalGenerator: '<S3>/Signal Generator: Yaw' */

  /* Gain: '<S3>/Amplitude: Yaw (deg)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudeYawdeg =
    q_heli_2d_ff_lqr_i_no_joystick_P.AmplitudeYawdeg_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYaw;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S3>/Constant: Yaw (deg)'
   */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum1 =
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudeYawdeg +
    q_heli_2d_ff_lqr_i_no_joystick_P.ConstantYawdeg_Value;

  /* Gain: '<S42>/Gain1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain1_h =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain1_Gain_g *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1;

  /* Sum: '<S7>/Sum1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e =
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1_h +
    q_heli_2d_ff_lqr_i_no_joystick_B.X[1];

  /* SignalConversion: '<S7>/TmpSignal ConversionAtControl Gain: KInport1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[0] =
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[1] =
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[2] =
    q_heli_2d_ff_lqr_i_no_joystick_B.X[2];
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[3] =
    q_heli_2d_ff_lqr_i_no_joystick_B.X[3];

  /* Gain: '<S7>/Control Gain: K' */
  for (i = 0; i < 2; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1
      [0];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i + 2] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1
      [1];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1
      [2];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i + 6] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1
      [3];
  }

  /* End of Gain: '<S7>/Control Gain: K' */

  /* Gain: '<S8>/-X' */
  for (i = 0; i < 4; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_k[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[0];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_k[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[1];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_k[i + 8] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[2];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_k[i + 12] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[3];
  }

  /* End of Gain: '<S8>/-X' */

  /* Sum: '<S8>/Sum2' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_c =
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1 +
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[0];

  /* Sum: '<S8>/Sum1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_o =
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1_h +
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[1];

  /* SignalConversion: '<S8>/TmpSignal ConversionAtControl Gain: KInport1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b[0]
    = q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_c;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b[1]
    = q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_o;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b[2]
    = q_heli_2d_ff_lqr_i_no_joystick_B.X_l[2];
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b[3]
    = q_heli_2d_ff_lqr_i_no_joystick_B.X_l[3];

  /* Gain: '<S8>/Control Gain: K' */
  for (i = 0; i < 2; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [0];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain[i + 2] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [1];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [2];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain[i + 6] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [3];
  }

  /* End of Gain: '<S8>/Control Gain: K' */

  /* Integrator: '<S11>/Integrator' incorporates:
   *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
   */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    zcEvent_0 = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE,
                         (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value));
    zcEvent = (zcEvent_0 != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent) {
      q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE =
        q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC;
    }
  }

  q_heli_2d_ff_lqr_i_no_joystick_B.Integrator =
    q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE;

  /* End of Integrator: '<S11>/Integrator' */

  /* Saturate: '<S11>/Saturate' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_PITCH;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Integrator;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_PITCH;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate = u0;
  }

  /* End of Saturate: '<S11>/Saturate' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* Memory: '<S15>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory =
      q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput;
  }

  /* MultiPortSwitch: '<S15>/Switch' */
  if ((int32_T)q_heli_2d_ff_lqr_i_no_joystick_B.Add == 1) {
    /* MultiPortSwitch: '<S14>/Pitch Control  Switch' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     */
    if ((int32_T)
        q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
        == 1) {
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch_b =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[0];
    } else {
      /* Sum: '<S8>/Pitch: LQR+I' */
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchLQRI_n =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[0] +
        q_heli_2d_ff_lqr_i_no_joystick_B.Saturate;
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch_b =
        q_heli_2d_ff_lqr_i_no_joystick_B.PitchLQRI_n;
    }

    /* End of MultiPortSwitch: '<S14>/Pitch Control  Switch' */

    /* Trigonometry: '<S10>/Trigonometric Function' */
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_mn = cos
      (q_heli_2d_ff_lqr_i_no_joystick_B.Gain1);

    /* Gain: '<S10>/Feed-forward Pitch Gain' */
    temp = q_heli_2d_ff_lqr_i_no_joystick_P.l_cm *
      q_heli_2d_ff_lqr_i_no_joystick_P.m_heli *
      q_heli_2d_ff_lqr_i_no_joystick_P.g;
    u0 = q_heli_2d_ff_lqr_i_no_joystick_P.K_pp;
    temp /= u0;
    q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_h = temp *
      q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_mn;

    /* Gain: '<S1>/FF Gain Adj.' */
    q_heli_2d_ff_lqr_i_no_joystick_B.FFGainAdj =
      q_heli_2d_ff_lqr_i_no_joystick_P.K_ff *
      q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_h;

    /* Sum: '<S14>/Pitch: FF+LQR' */
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchFFLQR_b =
      q_heli_2d_ff_lqr_i_no_joystick_B.FFGainAdj +
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch_b;
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch =
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchFFLQR_b;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch =
      q_heli_2d_ff_lqr_i_no_joystick_B.Memory;
  }

  /* End of MultiPortSwitch: '<S15>/Switch' */

  /* Sum: '<S9>/Pitch: u_ol_p +LQR' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Pitchu_ol_pLQR =
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay +
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch;

  /* Gain: '<S9>/Gain' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.Pitchu_ol_pLQR;

  /* Saturate: '<S6>/Pitch AMP Voltage Limit' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_P;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Gain;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_P;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit = u0;
  }

  /* End of Saturate: '<S6>/Pitch AMP Voltage Limit' */

  /* Gain: '<S6>/Pitch amp Gain Pre-Compensation' */
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.K_AMP;
  temp = 1.0 / u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchampGainPreCompensation = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit;
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* RelationalOperator: '<S18>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S18>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare_g = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       == q_heli_2d_ff_lqr_i_no_joystick_P.YawRelay_const);

    /* Bias: '<S9>/Yaw: Add 1' */
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAdd1 = (uint8_T)((uint32_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare_g +
      q_heli_2d_ff_lqr_i_no_joystick_P.YawAdd1_Bias);
  }

  /* SignalGenerator: '<S4>/Signal Generator: Yaw (V)' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorYawV_Frequency *
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYawV =
      q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorYawV_Amplitude;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYawV =
      -q_heli_2d_ff_lqr_i_no_joystick_P.SignalGeneratorYawV_Amplitude;
  }

  /* End of SignalGenerator: '<S4>/Signal Generator: Yaw (V)' */

  /* Gain: '<S4>/Amplitude: Yaw (V)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudeYawV =
    q_heli_2d_ff_lqr_i_no_joystick_P.AmplitudeYawV_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYawV;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S4>/Constant: Yaw (V)'
   */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_p =
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudeYawV +
    q_heli_2d_ff_lqr_i_no_joystick_P.ConstantYawV_Value;

  /* MultiPortSwitch: '<S9>/Choose Yaw Relay' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (q_heli_2d_ff_lqr_i_no_joystick_B.YawAdd1 == 1) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay =
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay =
      q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_p;
  }

  /* End of MultiPortSwitch: '<S9>/Choose Yaw Relay' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* RelationalOperator: '<S20>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S20>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare_j = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       >= q_heli_2d_ff_lqr_i_no_joystick_P.CompareToConstant_const_n);

    /* Sum: '<S16>/Add' incorporates:
     *  Constant: '<S16>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Add_m = (real_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare_j +
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value_o;
  }

  /* Integrator: '<S13>/Integrator' incorporates:
   *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
   */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    zcEvent_0 = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE_e,
                         (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value));
    zcEvent = (zcEvent_0 != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent) {
      q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_i =
        q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC_i;
    }
  }

  q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_b =
    q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_i;

  /* End of Integrator: '<S13>/Integrator' */

  /* Saturate: '<S13>/Saturate' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_YAW;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_b;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_YAW;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_c = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_c = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_c = u0;
  }

  /* End of Saturate: '<S13>/Saturate' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* Memory: '<S16>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory_b =
      q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_e;
  }

  /* MultiPortSwitch: '<S16>/Switch' */
  if ((int32_T)q_heli_2d_ff_lqr_i_no_joystick_B.Add_m == 1) {
    /* MultiPortSwitch: '<S14>/Yaw Control  Switch' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     */
    if ((int32_T)
        q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
        == 1) {
      q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch_l =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[1];
    } else {
      /* Sum: '<S8>/Yaw: LQR+I' */
      q_heli_2d_ff_lqr_i_no_joystick_B.YawLQRI_l =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[1] +
        q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_c;
      q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch_l =
        q_heli_2d_ff_lqr_i_no_joystick_B.YawLQRI_l;
    }

    /* End of MultiPortSwitch: '<S14>/Yaw Control  Switch' */
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_p =
      q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch_l;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_p =
      q_heli_2d_ff_lqr_i_no_joystick_B.Memory_b;
  }

  /* End of MultiPortSwitch: '<S16>/Switch' */

  /* Sum: '<S9>/Yaw: u_ol_y +LQR' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Yawu_ol_yLQR =
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay +
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_p;

  /* Saturate: '<S6>/Yaw AMP Voltage Limit' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_Y;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Yawu_ol_yLQR;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_Y;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit = u0;
  }

  /* End of Saturate: '<S6>/Yaw AMP Voltage Limit' */

  /* Gain: '<S6>/Yaw amp Gain Pre-Compensation' */
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.K_AMP;
  temp = 1.0 / u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.YawampGainPreCompensation = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit;
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* S-Function Block: <S6>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_RangeMode;
        parm.rangeidx = q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_Channels,
                       &q_heli_2d_ff_lqr_i_no_joystick_B.PitchampGainPreCompensation,
                       &parm);
      }
    }

    /* S-Function Block: <S6>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_RangeMode;
        parm.rangeidx = q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_Channels,
                       &q_heli_2d_ff_lqr_i_no_joystick_B.YawampGainPreCompensation,
                       &parm);
      }
    }
  }

  /* Gain: '<S11>/Pitch Integral Control Gain: K(1,5)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchIntegralControlGainK15 =
    q_heli_2d_ff_lqr_i_no_joystick_P.PitchIntegralControlGainK15_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_c;

  /* Gain: '<S11>/Yaw Cross-Integral Control Gain: K(1,6)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.YawCrossIntegralControlGainK16 =
    q_heli_2d_ff_lqr_i_no_joystick_P.YawCrossIntegralControlGainK16_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_o;

  /* Sum: '<S11>/Integral Input  (V//s)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs =
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchIntegralControlGainK15 +
    q_heli_2d_ff_lqr_i_no_joystick_B.YawCrossIntegralControlGainK16;

  /* Sum: '<S11>/u-v' */
  q_heli_2d_ff_lqr_i_no_joystick_B.uv =
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate -
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator;

  /* Gain: '<S11>/Pitch Reset Time' */
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.Tr_p;
  temp = 1.0 / u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchResetTime = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.uv;

  /* Sum: '<S11>/Sum' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum_d =
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs +
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchResetTime;

  /* Trigonometry: '<S12>/Trigonometric Function' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction = cos
    (q_heli_2d_ff_lqr_i_no_joystick_B.Gain1);

  /* Gain: '<S12>/Feed-forward Pitch Gain' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.l_cm *
    q_heli_2d_ff_lqr_i_no_joystick_P.m_heli * q_heli_2d_ff_lqr_i_no_joystick_P.g;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.K_pp;
  temp /= u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction;

  /* Gain: '<S13>/Yaw Integral Control Gain: K(2,6)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.YawIntegralControlGainK26 =
    q_heli_2d_ff_lqr_i_no_joystick_P.YawIntegralControlGainK26_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_o;

  /* Gain: '<S13>/Pitch Cross-Integral Control Gain: K(2,5)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchCrossIntegralControlGainK25 =
    q_heli_2d_ff_lqr_i_no_joystick_P.PitchCrossIntegralControlGainK25_Gain *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_c;

  /* Sum: '<S13>/Integral Input  (V//s)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_m =
    q_heli_2d_ff_lqr_i_no_joystick_B.YawIntegralControlGainK26 +
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchCrossIntegralControlGainK25;

  /* Sum: '<S13>/u-v' */
  q_heli_2d_ff_lqr_i_no_joystick_B.uv_i =
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_c -
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_b;

  /* Gain: '<S13>/Yaw Reset Time' */
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.Tr_y;
  temp = 1.0 / u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.YawResetTime = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.uv_i;

  /* Sum: '<S13>/Sum' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum_c =
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_m +
    q_heli_2d_ff_lqr_i_no_joystick_B.YawResetTime;

  /* Gain: '<S44>/Gain' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_l[0] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_a *
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1;
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_l[1] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_a *
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1_h;

  /* Gain: '<S45>/Gain' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[0] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_d *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[0];
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[1] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_d *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[1];
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[2] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_d *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[2];
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[3] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_d *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[3];

  /* Integrator: '<S23>/theta' */
  /* Limited  Integrator  */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.theta_0;
  if (q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE >= temp) {
    q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE =
      -q_heli_2d_ff_lqr_i_no_joystick_P.theta_0;
  } else {
    if (q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE <=
        q_heli_2d_ff_lqr_i_no_joystick_P.theta_0) {
      q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE =
        q_heli_2d_ff_lqr_i_no_joystick_P.theta_0;
    }
  }

  q_heli_2d_ff_lqr_i_no_joystick_B.theta =
    q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE;

  /* End of Integrator: '<S23>/theta' */

  /* Integrator: '<S23>/psi' */
  q_heli_2d_ff_lqr_i_no_joystick_B.psi =
    q_heli_2d_ff_lqr_i_no_joystick_X.psi_CSTATE;

  /* Integrator: '<S23>/theta_dot' */
  q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot =
    q_heli_2d_ff_lqr_i_no_joystick_X.theta_dot_CSTATE;

  /* Integrator: '<S23>/psi_dot' */
  q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot =
    q_heli_2d_ff_lqr_i_no_joystick_X.psi_dot_CSTATE;

  /* SignalConversion: '<S21>/TmpSignal ConversionAt-XInport1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[0] =
    q_heli_2d_ff_lqr_i_no_joystick_B.theta;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[1] =
    q_heli_2d_ff_lqr_i_no_joystick_B.psi;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[2] =
    q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[3] =
    q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot;

  /* Gain: '<S43>/Gain' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[0] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_l *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[0];
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[1] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_l *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[1];
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[2] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_l *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[2];
  q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[3] =
    q_heli_2d_ff_lqr_i_no_joystick_P.Gain_Gain_l *
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[3];
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* RelationalOperator: '<S36>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S36>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare_n = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       == q_heli_2d_ff_lqr_i_no_joystick_P.PitchRelay_const_p);

    /* Bias: '<S24>/Pitch: Add 1' */
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAdd1_c = (uint8_T)((uint32_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare_n +
      q_heli_2d_ff_lqr_i_no_joystick_P.PitchAdd1_Bias_b);

    /* RelationalOperator: '<S38>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S38>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare_mw = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       >= q_heli_2d_ff_lqr_i_no_joystick_P.CompareToConstant_const_d);

    /* Sum: '<S34>/Add' incorporates:
     *  Constant: '<S34>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Add_i = (real_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare_mw +
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value_p;
  }

  /* MultiPortSwitch: '<S24>/Choose Pitch Relay' incorporates:
   *  Constant: '<S24>/Constant'
   */
  if (q_heli_2d_ff_lqr_i_no_joystick_B.PitchAdd1_c == 1) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay_d =
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value_a;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay_d =
      q_heli_2d_ff_lqr_i_no_joystick_B.Sum;
  }

  /* End of MultiPortSwitch: '<S24>/Choose Pitch Relay' */

  /* Gain: '<S21>/-X' */
  for (i = 0; i < 4; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_j[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[0];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_j[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[1];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_j[i + 8] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[2];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_j[i + 12] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[3];
  }

  /* End of Gain: '<S21>/-X' */

  /* Sum: '<S21>/Sum2' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_a =
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1 +
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[0];

  /* Sum: '<S21>/Sum1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_g =
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1_h +
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[1];

  /* SignalConversion: '<S21>/TmpSignal ConversionAtControl Gain: KInport1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[0]
    = q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_a;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[1]
    = q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_g;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[2]
    = q_heli_2d_ff_lqr_i_no_joystick_B.X_c[2];
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[3]
    = q_heli_2d_ff_lqr_i_no_joystick_B.X_c[3];

  /* Gain: '<S21>/Control Gain: K' */
  for (i = 0; i < 2; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be
      [0];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i + 2] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be
      [1];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be
      [2];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.K[i + 6] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be
      [3];
  }

  /* End of Gain: '<S21>/Control Gain: K' */

  /* Gain: '<S22>/-X' */
  for (i = 0; i < 4; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_d[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[0];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_d[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[1];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_d[i + 8] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[2];
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.X_Gain_d[i + 12] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[3];
  }

  /* End of Gain: '<S22>/-X' */

  /* Sum: '<S22>/Sum2' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_o =
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1 +
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[0];

  /* Sum: '<S22>/Sum1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e4 =
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1_h +
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[1];

  /* SignalConversion: '<S22>/TmpSignal ConversionAtControl Gain: KInport1' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
    [0] = q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_o;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
    [1] = q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e4;
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
    [2] = q_heli_2d_ff_lqr_i_no_joystick_B.X_n[2];
  q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
    [3] = q_heli_2d_ff_lqr_i_no_joystick_B.X_n[3];

  /* Gain: '<S22>/Control Gain: K' */
  for (i = 0; i < 2; i++) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[i] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain_h[i] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [0];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain_h[i + 2] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [1];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain_h[i + 4] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [2];
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[i] +=
      q_heli_2d_ff_lqr_i_no_joystick_P.ControlGainK_Gain_h[i + 6] *
      q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [3];
  }

  /* End of Gain: '<S22>/Control Gain: K' */

  /* Integrator: '<S26>/Integrator' incorporates:
   *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
   */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    zcEvent_0 = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE_i,
                         (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value));
    zcEvent = (zcEvent_0 != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent) {
      q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_m =
        q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC_p;
    }
  }

  q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_k =
    q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_m;

  /* End of Integrator: '<S26>/Integrator' */

  /* Saturate: '<S26>/Saturate' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_PITCH;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_k;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_PITCH;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_e = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_e = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_e = u0;
  }

  /* End of Saturate: '<S26>/Saturate' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* Memory: '<S34>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory_g =
      q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_h;
  }

  /* MultiPortSwitch: '<S34>/Switch' */
  if ((int32_T)q_heli_2d_ff_lqr_i_no_joystick_B.Add_i == 1) {
    /* MultiPortSwitch: '<S33>/Pitch Control  Switch' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     */
    if ((int32_T)
        q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
        == 1) {
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[0];
    } else {
      /* Sum: '<S22>/Pitch: LQR+I' */
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchLQRI =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[0] +
        q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_e;
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch =
        q_heli_2d_ff_lqr_i_no_joystick_B.PitchLQRI;
    }

    /* End of MultiPortSwitch: '<S33>/Pitch Control  Switch' */

    /* Trigonometry: '<S25>/Trigonometric Function' */
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_m = cos
      (q_heli_2d_ff_lqr_i_no_joystick_B.Gain1);

    /* Gain: '<S25>/Feed-forward Pitch Gain' */
    temp = q_heli_2d_ff_lqr_i_no_joystick_P.l_cm *
      q_heli_2d_ff_lqr_i_no_joystick_P.m_heli *
      q_heli_2d_ff_lqr_i_no_joystick_P.g;
    u0 = q_heli_2d_ff_lqr_i_no_joystick_P.K_pp;
    temp /= u0;
    q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_n = temp *
      q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_m;

    /* Sum: '<S33>/Pitch: FF+LQR' */
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchFFLQR =
      q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_n +
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch;
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_m =
      q_heli_2d_ff_lqr_i_no_joystick_B.PitchFFLQR;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_m =
      q_heli_2d_ff_lqr_i_no_joystick_B.Memory_g;
  }

  /* End of MultiPortSwitch: '<S34>/Switch' */

  /* Sum: '<S24>/Pitch: u_ol_p +LQR' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Pitchu_ol_pLQR_n =
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay_d +
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_m;

  /* Saturate: '<S23>/Pitch AMP Voltage Limit' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_P;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Pitchu_ol_pLQR_n;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_P;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit_i = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit_i = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit_i = u0;
  }

  /* End of Saturate: '<S23>/Pitch AMP Voltage Limit' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* RelationalOperator: '<S37>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S37>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare_mq = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       == q_heli_2d_ff_lqr_i_no_joystick_P.YawRelay_const_i);

    /* Bias: '<S24>/Yaw: Add 1' */
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAdd1_b = (uint8_T)((uint32_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare_mq +
      q_heli_2d_ff_lqr_i_no_joystick_P.YawAdd1_Bias_j);

    /* RelationalOperator: '<S39>/Compare' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     *  Constant: '<S39>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Compare_l = (uint8_T)
      (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
       >= q_heli_2d_ff_lqr_i_no_joystick_P.CompareToConstant_const_e);

    /* Sum: '<S35>/Add' incorporates:
     *  Constant: '<S35>/Constant'
     */
    q_heli_2d_ff_lqr_i_no_joystick_B.Add_l = (real_T)
      q_heli_2d_ff_lqr_i_no_joystick_B.Compare_l +
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value_d;
  }

  /* MultiPortSwitch: '<S24>/Choose Yaw Relay' incorporates:
   *  Constant: '<S24>/Constant'
   */
  if (q_heli_2d_ff_lqr_i_no_joystick_B.YawAdd1_b == 1) {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay_m =
      q_heli_2d_ff_lqr_i_no_joystick_P.Constant_Value_a;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay_m =
      q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_p;
  }

  /* End of MultiPortSwitch: '<S24>/Choose Yaw Relay' */

  /* Integrator: '<S28>/Integrator' incorporates:
   *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
   */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    zcEvent_0 = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE_b,
                         (q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value));
    zcEvent = (zcEvent_0 != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent) {
      q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_e =
        q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC_b;
    }
  }

  q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_h =
    q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_e;

  /* End of Integrator: '<S28>/Integrator' */

  /* Saturate: '<S28>/Saturate' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_YAW;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_h;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.SAT_INT_ERR_YAW;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_g = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_g = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_g = u0;
  }

  /* End of Saturate: '<S28>/Saturate' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* Memory: '<S35>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory_k =
      q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_o;
  }

  /* MultiPortSwitch: '<S35>/Switch' */
  if ((int32_T)q_heli_2d_ff_lqr_i_no_joystick_B.Add_l == 1) {
    /* MultiPortSwitch: '<S33>/Yaw Control  Switch' incorporates:
     *  Constant: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
     */
    if ((int32_T)
        q_heli_2d_ff_lqr_i_no_joystick_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
        == 1) {
      q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[1];
    } else {
      /* Sum: '<S22>/Yaw: LQR+I' */
      q_heli_2d_ff_lqr_i_no_joystick_B.YawLQRI =
        q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[1] +
        q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_g;
      q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch =
        q_heli_2d_ff_lqr_i_no_joystick_B.YawLQRI;
    }

    /* End of MultiPortSwitch: '<S33>/Yaw Control  Switch' */
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_g =
      q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_g =
      q_heli_2d_ff_lqr_i_no_joystick_B.Memory_k;
  }

  /* End of MultiPortSwitch: '<S35>/Switch' */

  /* Sum: '<S24>/Yaw: u_ol_y +LQR' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Yawu_ol_yLQR_e =
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay_m +
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_g;

  /* Saturate: '<S23>/Yaw AMP Voltage Limit' */
  temp = -q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_Y;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_B.Yawu_ol_yLQR_e;
  u2 = q_heli_2d_ff_lqr_i_no_joystick_P.VMAX_AMP_Y;
  if (u0 > u2) {
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit_h = u2;
  } else if (u0 < temp) {
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit_h = temp;
  } else {
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit_h = u0;
  }

  /* End of Saturate: '<S23>/Yaw AMP Voltage Limit' */
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
  }

  /* Gain: '<S26>/Pitch Integral Control Gain: K(1,5)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchIntegralControlGainK15_c =
    q_heli_2d_ff_lqr_i_no_joystick_P.PitchIntegralControlGainK15_Gain_a *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_o;

  /* Gain: '<S26>/Yaw Cross-Integral Control Gain: K(1,6)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.YawCrossIntegralControlGainK16_k =
    q_heli_2d_ff_lqr_i_no_joystick_P.YawCrossIntegralControlGainK16_Gain_j *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e4;

  /* Sum: '<S26>/Integral Input  (V//s)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_p =
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchIntegralControlGainK15_c +
    q_heli_2d_ff_lqr_i_no_joystick_B.YawCrossIntegralControlGainK16_k;

  /* Sum: '<S26>/u-v' */
  q_heli_2d_ff_lqr_i_no_joystick_B.uv_l =
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_e -
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_k;

  /* Gain: '<S26>/Pitch Reset Time' */
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.Tr_p;
  temp = 1.0 / u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchResetTime_b = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.uv_l;

  /* Sum: '<S26>/Sum' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum_a =
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_p +
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchResetTime_b;

  /* Trigonometry: '<S27>/Trigonometric Function' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_f = cos
    (q_heli_2d_ff_lqr_i_no_joystick_B.Gain1);

  /* Gain: '<S27>/Feed-forward Pitch Gain' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.l_cm *
    q_heli_2d_ff_lqr_i_no_joystick_P.m_heli * q_heli_2d_ff_lqr_i_no_joystick_P.g;
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.K_pp;
  temp /= u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_f = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_f;

  /* Gain: '<S28>/Yaw Integral Control Gain: K(2,6)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.YawIntegralControlGainK26_i =
    q_heli_2d_ff_lqr_i_no_joystick_P.YawIntegralControlGainK26_Gain_h *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e4;

  /* Gain: '<S28>/Pitch Cross-Integral Control Gain: K(2,5)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchCrossIntegralControlGainK25_p =
    q_heli_2d_ff_lqr_i_no_joystick_P.PitchCrossIntegralControlGainK25_Gain_a *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_o;

  /* Sum: '<S28>/Integral Input  (V//s)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_i =
    q_heli_2d_ff_lqr_i_no_joystick_B.YawIntegralControlGainK26_i +
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchCrossIntegralControlGainK25_p;

  /* Sum: '<S28>/u-v' */
  q_heli_2d_ff_lqr_i_no_joystick_B.uv_b =
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_g -
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_h;

  /* Gain: '<S28>/Yaw Reset Time' */
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.Tr_y;
  temp = 1.0 / u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.YawResetTime_a = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.uv_b;

  /* Sum: '<S28>/Sum' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum_k =
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_i +
    q_heli_2d_ff_lqr_i_no_joystick_B.YawResetTime_a;

  /* Gain: '<S23>/Cross-torque acting on Pitch  from Yaw Motor' */
  q_heli_2d_ff_lqr_i_no_joystick_B.CrosstorqueactingonPitchfromYawMotor =
    q_heli_2d_ff_lqr_i_no_joystick_P.K_py *
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit_h;

  /* Gain: '<S23>/Cross-torque acting on Yaw  from Pitch Motor' */
  q_heli_2d_ff_lqr_i_no_joystick_B.CrosstorqueactingonYawfromPitchMotor =
    q_heli_2d_ff_lqr_i_no_joystick_P.K_yp *
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit_i;

  /* Gain: '<S23>/Thrust torque from  Yaw Motor' */
  q_heli_2d_ff_lqr_i_no_joystick_B.ThrusttorquefromYawMotor =
    q_heli_2d_ff_lqr_i_no_joystick_P.K_yy *
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit_h;

  /* Trigonometry: '<S32>/cos(theta)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.costheta = cos
    (q_heli_2d_ff_lqr_i_no_joystick_B.theta);

  /* Trigonometry: '<S32>/sin(psi)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.sinpsi = sin
    (q_heli_2d_ff_lqr_i_no_joystick_B.psi);

  /* Product: '<S32>/Product' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Product =
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta *
    q_heli_2d_ff_lqr_i_no_joystick_B.sinpsi *
    q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot *
    q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot;

  /* Gain: '<S32>/2*m*lcm^2' */
  temp = 2.0 * q_heli_2d_ff_lqr_i_no_joystick_P.m_heli * 0.0001;
  q_heli_2d_ff_lqr_i_no_joystick_B.umlcm2 = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.Product;

  /* Gain: '<S23>/Yaw Viscous Damping' */
  q_heli_2d_ff_lqr_i_no_joystick_B.YawViscousDamping =
    q_heli_2d_ff_lqr_i_no_joystick_P.B_y *
    q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot;

  /* Sum: '<S23>/Sum4' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum4 =
    ((q_heli_2d_ff_lqr_i_no_joystick_B.ThrusttorquefromYawMotor +
      q_heli_2d_ff_lqr_i_no_joystick_B.CrosstorqueactingonYawfromPitchMotor) +
     q_heli_2d_ff_lqr_i_no_joystick_B.umlcm2) -
    q_heli_2d_ff_lqr_i_no_joystick_B.YawViscousDamping;

  /* Trigonometry: '<S31>/cos(theta)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.costheta_h = cos
    (q_heli_2d_ff_lqr_i_no_joystick_B.theta);

  /* Product: '<S31>/cos(theta)^2' */
  q_heli_2d_ff_lqr_i_no_joystick_B.costheta2 =
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta_h *
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta_h;

  /* Gain: '<S31>/m_heli*l_cm^2' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.m_heli * 0.0001;
  q_heli_2d_ff_lqr_i_no_joystick_B.m_helil_cm2 = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta2;

  /* Sum: '<S31>/Sum3' incorporates:
   *  Constant: '<S31>/Yaw Inertia'
   */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum3 =
    q_heli_2d_ff_lqr_i_no_joystick_P.J_eq_y +
    q_heli_2d_ff_lqr_i_no_joystick_B.m_helil_cm2;

  /* Product: '<S23>/Divide by Inertia' */
  q_heli_2d_ff_lqr_i_no_joystick_B.DividebyInertia =
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum4 /
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum3;

  /* Trigonometry: '<S29>/Trigonometric Function' */
  q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_k = cos
    (q_heli_2d_ff_lqr_i_no_joystick_B.theta);

  /* Gain: '<S29>/m*g*lcm' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.m_heli *
    q_heli_2d_ff_lqr_i_no_joystick_P.g * q_heli_2d_ff_lqr_i_no_joystick_P.l_cm;
  q_heli_2d_ff_lqr_i_no_joystick_B.mglcm = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_k;

  /* Gain: '<S23>/Thrust torque from  Pitch Motor' */
  q_heli_2d_ff_lqr_i_no_joystick_B.ThrusttorquefromPitchMotor =
    q_heli_2d_ff_lqr_i_no_joystick_P.K_pp *
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit_i;

  /* Trigonometry: '<S30>/sin(theta)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.sintheta = sin
    (q_heli_2d_ff_lqr_i_no_joystick_B.theta);

  /* Trigonometry: '<S30>/cos(theta)' */
  q_heli_2d_ff_lqr_i_no_joystick_B.costheta_f = cos
    (q_heli_2d_ff_lqr_i_no_joystick_B.theta);

  /* Product: '<S30>/Product' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Product_p =
    q_heli_2d_ff_lqr_i_no_joystick_B.sintheta *
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta_f *
    q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot *
    q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot;

  /* Gain: '<S30>/m*lcm^2' */
  temp = q_heli_2d_ff_lqr_i_no_joystick_P.m_heli * 0.0001;
  q_heli_2d_ff_lqr_i_no_joystick_B.mlcm2 = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.Product_p;

  /* Gain: '<S23>/Pitch Viscous Damping' */
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchViscousDamping =
    q_heli_2d_ff_lqr_i_no_joystick_P.B_p *
    q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot;

  /* Sum: '<S23>/Sum2' */
  q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_g =
    (((q_heli_2d_ff_lqr_i_no_joystick_B.ThrusttorquefromPitchMotor +
       q_heli_2d_ff_lqr_i_no_joystick_B.CrosstorqueactingonPitchfromYawMotor) -
      q_heli_2d_ff_lqr_i_no_joystick_B.mlcm2) -
     q_heli_2d_ff_lqr_i_no_joystick_B.mglcm) -
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchViscousDamping;

  /* Gain: '<S23>/Pitch Inertia' */
  u0 = q_heli_2d_ff_lqr_i_no_joystick_P.m_heli * 0.0001 +
    q_heli_2d_ff_lqr_i_no_joystick_P.J_eq_p;
  temp = 1.0 / u0;
  q_heli_2d_ff_lqr_i_no_joystick_B.PitchInertia = temp *
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_g;
}

/* Model update function */
void q_heli_2d_ff_lqr_i_no_joystick_update(void)
{
  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    /* Update for Memory: '<S15>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput =
      q_heli_2d_ff_lqr_i_no_joystick_B.Switch;

    /* Update for Memory: '<S16>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_e =
      q_heli_2d_ff_lqr_i_no_joystick_B.Switch_p;

    /* Update for Memory: '<S34>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_h =
      q_heli_2d_ff_lqr_i_no_joystick_B.Switch_m;

    /* Update for Memory: '<S35>/Memory' */
    q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_o =
      q_heli_2d_ff_lqr_i_no_joystick_B.Switch_g;
  }

  if (rtmIsMajorTimeStep(q_heli_2d_ff_lqr_i_no_joystick_M)) {
    rt_ertODEUpdateContinuousStates
      (&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTick0)) {
    ++q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTickH0;
  }

  q_heli_2d_ff_lqr_i_no_joystick_M->Timing.t[0] = rtsiGetSolverStopTime
    (&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTick1)) {
      ++q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTickH1;
    }

    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.t[1] =
      q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTick1 *
      q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize1 +
      q_heli_2d_ff_lqr_i_no_joystick_M->Timing.clockTickH1 *
      q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void q_heli_2d_ff_lqr_i_no_joystick_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  real_T y;
  XDot_q_heli_2d_ff_lqr_i_no_joystick_T *_rtXdot;
  _rtXdot = ((XDot_q_heli_2d_ff_lqr_i_no_joystick_T *)
             q_heli_2d_ff_lqr_i_no_joystick_M->derivs);

  /* Derivatives for TransferFcn: '<S6>/Derivative Filter: Pitch' */
  _rtXdot->DerivativeFilterPitch_CSTATE[0] = 0.0;
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterPitch_A[0] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterPitch_CSTATE[0];
  _rtXdot->DerivativeFilterPitch_CSTATE[1] = 0.0;
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterPitch_A[1] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterPitch_CSTATE[1];
  _rtXdot->DerivativeFilterPitch_CSTATE[1] +=
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterPitch_CSTATE[0];
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionPitch;

  /* Derivatives for TransferFcn: '<S6>/Derivative Filter: Yaw' */
  _rtXdot->DerivativeFilterYaw_CSTATE[0] = 0.0;
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterYaw_A[0] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterYaw_CSTATE[0];
  _rtXdot->DerivativeFilterYaw_CSTATE[1] = 0.0;
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    q_heli_2d_ff_lqr_i_no_joystick_P.DerivativeFilterYaw_A[1] *
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterYaw_CSTATE[1];
  _rtXdot->DerivativeFilterYaw_CSTATE[1] +=
    q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterYaw_CSTATE[0];
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionYaw;

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE = q_heli_2d_ff_lqr_i_no_joystick_B.Sum_d;

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = q_heli_2d_ff_lqr_i_no_joystick_B.Sum_c;

  /* Derivatives for Integrator: '<S23>/theta' */
  lsat = (q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE <=
          q_heli_2d_ff_lqr_i_no_joystick_P.theta_0);
  y = -q_heli_2d_ff_lqr_i_no_joystick_P.theta_0;
  usat = (q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE >= y);
  if (((!lsat) && (!usat)) || (lsat &&
       (q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot > 0.0)) || (usat &&
       (q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot < 0.0))) {
    _rtXdot->theta_CSTATE = q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot;
  } else {
    /* in saturation */
    _rtXdot->theta_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S23>/theta' */

  /* Derivatives for Integrator: '<S23>/psi' */
  _rtXdot->psi_CSTATE = q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot;

  /* Derivatives for Integrator: '<S23>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = q_heli_2d_ff_lqr_i_no_joystick_B.PitchInertia;

  /* Derivatives for Integrator: '<S23>/psi_dot' */
  _rtXdot->psi_dot_CSTATE = q_heli_2d_ff_lqr_i_no_joystick_B.DividebyInertia;

  /* Derivatives for Integrator: '<S26>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = q_heli_2d_ff_lqr_i_no_joystick_B.Sum_a;

  /* Derivatives for Integrator: '<S28>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = q_heli_2d_ff_lqr_i_no_joystick_B.Sum_k;
}

/* Model initialize function */
void q_heli_2d_ff_lqr_i_no_joystick_initialize(void)
{
  /* S-Function Block: <S6>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_RangeMode;
      parm.rangeidx = q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_Channels,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* S-Function Block: <S6>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_RangeMode;
      parm.rangeidx = q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_Channels,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_InitialValue,
                     &parm);
    }
  }

  q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE_e =
    UNINITIALIZED_ZCSIG;
  q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE_i =
    UNINITIALIZED_ZCSIG;
  q_heli_2d_ff_lqr_i_no_joystick_PrevZCX.Integrator_Reset_ZCE_b =
    UNINITIALIZED_ZCSIG;

  /* S-Function Block: <S6>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput_Channels, NULL,
                   &parm);
  }

  /* S-Function Block: <S6>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput1_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S6>/Derivative Filter: Pitch' */
  q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterPitch_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Derivative Filter: Yaw' */
  q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterYaw_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Derivative Filter: Pitch' */
  q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterPitch_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Derivative Filter: Yaw' */
  q_heli_2d_ff_lqr_i_no_joystick_X.DerivativeFilterYaw_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S11>/Integrator' */
  q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE =
    q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC;

  /* InitializeConditions for Memory: '<S15>/Memory' */
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput =
    q_heli_2d_ff_lqr_i_no_joystick_P.Memory_X0;

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_i =
    q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC_i;

  /* InitializeConditions for Memory: '<S16>/Memory' */
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_e =
    q_heli_2d_ff_lqr_i_no_joystick_P.Memory_X0_m;

  /* InitializeConditions for Integrator: '<S23>/theta' */
  q_heli_2d_ff_lqr_i_no_joystick_X.theta_CSTATE =
    q_heli_2d_ff_lqr_i_no_joystick_P.theta_0;

  /* InitializeConditions for Integrator: '<S23>/psi' */
  q_heli_2d_ff_lqr_i_no_joystick_X.psi_CSTATE =
    q_heli_2d_ff_lqr_i_no_joystick_P.psi_IC;

  /* InitializeConditions for Integrator: '<S23>/theta_dot' */
  q_heli_2d_ff_lqr_i_no_joystick_X.theta_dot_CSTATE =
    q_heli_2d_ff_lqr_i_no_joystick_P.theta_dot_IC;

  /* InitializeConditions for Integrator: '<S23>/psi_dot' */
  q_heli_2d_ff_lqr_i_no_joystick_X.psi_dot_CSTATE =
    q_heli_2d_ff_lqr_i_no_joystick_P.psi_dot_IC;

  /* InitializeConditions for Integrator: '<S26>/Integrator' */
  q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_m =
    q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC_p;

  /* InitializeConditions for Memory: '<S34>/Memory' */
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_h =
    q_heli_2d_ff_lqr_i_no_joystick_P.Memory_X0_c;

  /* InitializeConditions for Integrator: '<S28>/Integrator' */
  q_heli_2d_ff_lqr_i_no_joystick_X.Integrator_CSTATE_e =
    q_heli_2d_ff_lqr_i_no_joystick_P.Integrator_IC_b;

  /* InitializeConditions for Memory: '<S35>/Memory' */
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_o =
    q_heli_2d_ff_lqr_i_no_joystick_P.Memory_X0_a;
}

/* Model terminate function */
void q_heli_2d_ff_lqr_i_no_joystick_terminate(void)
{
  /* S-Function Block: <S6>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_RangeMode;
      parm.rangeidx = q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_Channels,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput_FinalValue,
                     &parm);
    }
  }

  /* S-Function Block: <S6>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_RangeMode;
      parm.rangeidx = q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_Channels,
                     &q_heli_2d_ff_lqr_i_no_joystick_P.AnalogOutput1_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  q_heli_2d_ff_lqr_i_no_joystick_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_heli_2d_ff_lqr_i_no_joystick_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  q_heli_2d_ff_lqr_i_no_joystick_initialize();
}

void MdlTerminate(void)
{
  q_heli_2d_ff_lqr_i_no_joystick_terminate();
}

/* Registration function */
RT_MODEL_q_heli_2d_ff_lqr_i_no_joystick_T *q_heli_2d_ff_lqr_i_no_joystick(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput_InputFilter = rtInf;
  q_heli_2d_ff_lqr_i_no_joystick_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)q_heli_2d_ff_lqr_i_no_joystick_M, 0,
                sizeof(RT_MODEL_q_heli_2d_ff_lqr_i_no_joystick_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                          &q_heli_2d_ff_lqr_i_no_joystick_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo, &rtmGetTPtr
                (q_heli_2d_ff_lqr_i_no_joystick_M));
    rtsiSetStepSizePtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                       &q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                 &q_heli_2d_ff_lqr_i_no_joystick_M->derivs);
    rtsiSetContStatesPtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo, (real_T **)
                         &q_heli_2d_ff_lqr_i_no_joystick_M->contStates);
    rtsiSetNumContStatesPtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
      &q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
       &q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
       &q_heli_2d_ff_lqr_i_no_joystick_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
       &q_heli_2d_ff_lqr_i_no_joystick_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                          (&rtmGetErrorStatus(q_heli_2d_ff_lqr_i_no_joystick_M)));
    rtsiSetRTModelPtr(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                      q_heli_2d_ff_lqr_i_no_joystick_M);
  }

  rtsiSetSimTimeStep(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                     MAJOR_TIME_STEP);
  q_heli_2d_ff_lqr_i_no_joystick_M->intgData.y =
    q_heli_2d_ff_lqr_i_no_joystick_M->odeY;
  q_heli_2d_ff_lqr_i_no_joystick_M->intgData.f[0] =
    q_heli_2d_ff_lqr_i_no_joystick_M->odeF[0];
  q_heli_2d_ff_lqr_i_no_joystick_M->intgData.f[1] =
    q_heli_2d_ff_lqr_i_no_joystick_M->odeF[1];
  q_heli_2d_ff_lqr_i_no_joystick_M->intgData.f[2] =
    q_heli_2d_ff_lqr_i_no_joystick_M->odeF[2];
  q_heli_2d_ff_lqr_i_no_joystick_M->contStates = ((real_T *)
    &q_heli_2d_ff_lqr_i_no_joystick_X);
  rtsiSetSolverData(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo, (void *)
                    &q_heli_2d_ff_lqr_i_no_joystick_M->intgData);
  rtsiSetSolverName(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleTimes =
      (&q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleTimesArray[0]);
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.offsetTimes =
      (&q_heli_2d_ff_lqr_i_no_joystick_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleTimes[0] = (0.0);
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.offsetTimes[0] = (0.0);
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_heli_2d_ff_lqr_i_no_joystick_M,
             &q_heli_2d_ff_lqr_i_no_joystick_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_heli_2d_ff_lqr_i_no_joystick_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_heli_2d_ff_lqr_i_no_joystick_M, -1);
  q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize0 = 0.001;
  q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.checksums[0] = (4277653875U);
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.checksums[1] = (3038224113U);
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.checksums[2] = (3017464481U);
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.checksums[3] = (1404449647U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    q_heli_2d_ff_lqr_i_no_joystick_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_heli_2d_ff_lqr_i_no_joystick_M->extModeInfo,
      &q_heli_2d_ff_lqr_i_no_joystick_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_heli_2d_ff_lqr_i_no_joystick_M->extModeInfo,
                        q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.checksums);
    rteiSetTPtr(q_heli_2d_ff_lqr_i_no_joystick_M->extModeInfo, rtmGetTPtr
                (q_heli_2d_ff_lqr_i_no_joystick_M));
  }

  q_heli_2d_ff_lqr_i_no_joystick_M->solverInfoPtr =
    (&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo);
  q_heli_2d_ff_lqr_i_no_joystick_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo, 0.001);
  rtsiSetSolverMode(&q_heli_2d_ff_lqr_i_no_joystick_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_heli_2d_ff_lqr_i_no_joystick_M->blockIO = ((void *)
    &q_heli_2d_ff_lqr_i_no_joystick_B);
  (void) memset(((void *) &q_heli_2d_ff_lqr_i_no_joystick_B), 0,
                sizeof(B_q_heli_2d_ff_lqr_i_no_joystick_T));

  {
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitchV = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudePitchV = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Add = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorPitch = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudePitchdeg = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.SliderGain = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum_h = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderInput = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderInput1 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionPitch = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Bias = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.EncoderResolutionYaw = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterPitch = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.DerivativeFilterYaw = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYaw = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudeYawdeg = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain1_h = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[0]
      = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[1]
      = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[2]
      = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1[3]
      = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_l[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_c = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_o = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_b
      [3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_l[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Pitchu_ol_pLQR = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchampGainPreCompensation = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.SignalGeneratorYawV = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.AmplitudeYawV = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_p = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Add_m = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_b = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_c = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory_b = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_p = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Yawu_ol_yLQR = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawampGainPreCompensation = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchIntegralControlGainK15 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawCrossIntegralControlGainK16 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.uv = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchResetTime = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum_d = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawIntegralControlGainK26 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchCrossIntegralControlGainK25 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_m = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.uv_i = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawResetTime = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum_c = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_l[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_l[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_lx[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.theta = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.psi = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.theta_dot = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.psi_dot = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtXInport1_i[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Gain_b[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ChoosePitchRelay_d = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Add_i = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_c[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_a = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_g = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[
      0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[
      1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[
      2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be[
      3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_j[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.X_n[3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_o = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum1_e4 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [2] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TmpSignalConversionAtControlGainKInport1_be1
      [3] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[0] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ControlGainK_b[1] = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_k = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_e = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory_g = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_m = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Pitchu_ol_pLQR_n = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchAMPVoltageLimit_i = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ChooseYawRelay_m = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Add_l = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Integrator_h = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Saturate_g = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Memory_k = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Switch_g = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Yawu_ol_yLQR_e = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawAMPVoltageLimit_h = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchIntegralControlGainK15_c = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawCrossIntegralControlGainK16_k = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_p = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.uv_l = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchResetTime_b = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum_a = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_f = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_f = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawIntegralControlGainK26_i = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchCrossIntegralControlGainK25_p = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.IntegralInputVs_i = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.uv_b = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawResetTime_a = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum_k = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.CrosstorqueactingonPitchfromYawMotor = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.CrosstorqueactingonYawfromPitchMotor = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ThrusttorquefromYawMotor = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.sinpsi = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Product = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.umlcm2 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawViscousDamping = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum4 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta_h = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta2 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.m_helil_cm2 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum3 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.DividebyInertia = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_k = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.mglcm = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.ThrusttorquefromPitchMotor = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.sintheta = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.costheta_f = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Product_p = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.mlcm2 = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchViscousDamping = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.Sum2_g = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchInertia = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawLQRI = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_m = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_n = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchFFLQR = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchLQRI = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawControlSwitch_l = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.YawLQRI_l = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchControlSwitch_b = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.TrigonometricFunction_mn = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.FeedforwardPitchGain_h = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.FFGainAdj = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchFFLQR_b = 0.0;
    q_heli_2d_ff_lqr_i_no_joystick_B.PitchLQRI_n = 0.0;
  }

  /* parameters */
  q_heli_2d_ff_lqr_i_no_joystick_M->defaultParam = ((real_T *)
    &q_heli_2d_ff_lqr_i_no_joystick_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &q_heli_2d_ff_lqr_i_no_joystick_X;
    q_heli_2d_ff_lqr_i_no_joystick_M->contStates = (x);
    (void) memset((void *)&q_heli_2d_ff_lqr_i_no_joystick_X, 0,
                  sizeof(X_q_heli_2d_ff_lqr_i_no_joystick_T));
  }

  /* states (dwork) */
  q_heli_2d_ff_lqr_i_no_joystick_M->dwork = ((void *)
    &q_heli_2d_ff_lqr_i_no_joystick_DW);
  (void) memset((void *)&q_heli_2d_ff_lqr_i_no_joystick_DW, 0,
                sizeof(DW_q_heli_2d_ff_lqr_i_no_joystick_T));
  q_heli_2d_ff_lqr_i_no_joystick_DW.Add_DWORK1 = 0.0;
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput = 0.0;
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_e = 0.0;
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_h = 0.0;
  q_heli_2d_ff_lqr_i_no_joystick_DW.Memory_PreviousInput_o = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_heli_2d_ff_lqr_i_no_joystick_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numContStates = (12);/* Number of continuous states */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numY = (0);/* Number of model outputs */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numU = (0);/* Number of model inputs */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numSampTimes = (2);/* Number of sample times */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numBlocks = (201);/* Number of blocks */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numBlockIO = (165);/* Number of block outputs */
  q_heli_2d_ff_lqr_i_no_joystick_M->Sizes.numBlockPrms = (201);/* Sum of parameter "widths" */
  return q_heli_2d_ff_lqr_i_no_joystick_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
