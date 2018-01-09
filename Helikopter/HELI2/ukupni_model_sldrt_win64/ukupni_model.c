/*
 * ukupni_model.c
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
#include "ukupni_model_dt.h"

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
B_ukupni_model_T ukupni_model_B;

/* Continuous states */
X_ukupni_model_T ukupni_model_X;

/* Block states (auto storage) */
DW_ukupni_model_T ukupni_model_DW;

/* Real-time model */
RT_MODEL_ukupni_model_T ukupni_model_M_;
RT_MODEL_ukupni_model_T *const ukupni_model_M = &ukupni_model_M_;

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
  ukupni_model_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ukupni_model_output();
  ukupni_model_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ukupni_model_output();
  ukupni_model_derivatives();

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
void ukupni_model_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput;
  real_T rtb_EncoderInput1;
  real_T rtb_Sum2_n;
  real_T rtb_TmpSignalConversionAtControlGainKInport1[4];
  real_T rtb_TmpSignalConversionAtXInport1[4];
  real_T rtb_Sum1_i;
  real_T rtb_ControlGainK[2];
  real_T rtb_Saturate_m;
  real_T rtb_costheta_p;
  real_T rtb_YawLQRI;
  real_T rtb_Saturate;
  int32_T i;
  real_T u0;
  if (rtmIsMajorTimeStep(ukupni_model_M)) {
    /* set solver stop time */
    if (!(ukupni_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ukupni_model_M->solverInfo,
                            ((ukupni_model_M->Timing.clockTickH0 + 1) *
        ukupni_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ukupni_model_M->solverInfo,
                            ((ukupni_model_M->Timing.clockTick0 + 1) *
        ukupni_model_M->Timing.stepSize0 + ukupni_model_M->Timing.clockTickH0 *
        ukupni_model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ukupni_model_M)) {
    ukupni_model_M->Timing.t[0] = rtsiGetT(&ukupni_model_M->solverInfo);
  }

  /* SignalGenerator: '<S2>/Signal Generator: Pitch' */
  rtb_Saturate_m = ukupni_model_P.SignalGeneratorPitch_Frequency *
    ukupni_model_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ukupni_model_M)) {
    /* Gain: '<S10>/Slider Gain' incorporates:
     *  Constant: '<S2>/Constant'
     */
    ukupni_model_B.SliderGain = ukupni_model_P.ConstantPitchdeg_gain *
      ukupni_model_P.Constant_Value;
  }

  /* SignalGenerator: '<S2>/Signal Generator: Pitch' */
  if (rtb_Saturate_m - floor(rtb_Saturate_m) >= 0.5) {
    rtb_Saturate_m = ukupni_model_P.SignalGeneratorPitch_Amplitude;
  } else {
    rtb_Saturate_m = -ukupni_model_P.SignalGeneratorPitch_Amplitude;
  }

  /* Gain: '<S11>/Gain1' incorporates:
   *  Gain: '<S2>/Amplitude: Pitch (deg)'
   *  Sum: '<S2>/Sum'
   */
  rtb_Sum2_n = (ukupni_model_P.AmplitudePitchdeg_Gain * rtb_Saturate_m +
                ukupni_model_B.SliderGain) * ukupni_model_P.Gain1_Gain;
  if (rtmIsMajorTimeStep(ukupni_model_M)) {
    /* S-Function Block: <S5>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = ukupni_model_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &ukupni_model_P.EncoderInput_Channels, &rtb_EncoderInput,
                     &parm);
    }

    /* S-Function Block: <S5>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = ukupni_model_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &ukupni_model_P.EncoderInput1_Channels, &rtb_EncoderInput1,
                     &parm);
    }

    /* Gain: '<S5>/Encoder Resolution: Pitch ' */
    ukupni_model_B.EncoderResolutionPitch = ukupni_model_P.K_EC_P *
      rtb_EncoderInput;

    /* Bias: '<S5>/Bias' */
    ukupni_model_B.Bias = ukupni_model_B.EncoderResolutionPitch +
      ukupni_model_P.theta_0;

    /* Gain: '<S5>/Encoder Resolution: Yaw' */
    ukupni_model_B.EncoderResolutionYaw = ukupni_model_P.K_EC_Y *
      rtb_EncoderInput1;
  }

  /* TransferFcn: '<S5>/Derivative Filter: Pitch' */
  rtb_Sum1_i = ukupni_model_P.DerivativeFilterPitch_C[0] *
    ukupni_model_X.DerivativeFilterPitch_CSTATE[0] +
    ukupni_model_P.DerivativeFilterPitch_C[1] *
    ukupni_model_X.DerivativeFilterPitch_CSTATE[1];

  /* TransferFcn: '<S5>/Derivative Filter: Yaw' */
  rtb_YawLQRI = ukupni_model_P.DerivativeFilterYaw_C[0] *
    ukupni_model_X.DerivativeFilterYaw_CSTATE[0] +
    ukupni_model_P.DerivativeFilterYaw_C[1] *
    ukupni_model_X.DerivativeFilterYaw_CSTATE[1];

  /* SignalConversion: '<S6>/TmpSignal ConversionAt-XInport1' */
  rtb_TmpSignalConversionAtControlGainKInport1[2] = rtb_Sum1_i;
  rtb_TmpSignalConversionAtControlGainKInport1[3] = rtb_YawLQRI;

  /* Gain: '<S6>/-X' incorporates:
   *  SignalConversion: '<S6>/TmpSignal ConversionAt-XInport1'
   */
  for (i = 0; i < 4; i++) {
    rtb_Saturate = ukupni_model_P.X_Gain[i + 12] * rtb_YawLQRI +
      (ukupni_model_P.X_Gain[i + 8] * rtb_Sum1_i + (ukupni_model_P.X_Gain[i + 4]
        * ukupni_model_B.EncoderResolutionYaw + ukupni_model_P.X_Gain[i] *
        ukupni_model_B.Bias));
    rtb_TmpSignalConversionAtXInport1[i] = rtb_Saturate;
  }

  /* End of Gain: '<S6>/-X' */

  /* Sum: '<S6>/Sum2' */
  rtb_YawLQRI = rtb_Sum2_n + rtb_TmpSignalConversionAtXInport1[0];

  /* SignalGenerator: '<S2>/Signal Generator: Yaw' */
  rtb_Saturate_m = ukupni_model_P.SignalGeneratorYaw_Frequency *
    ukupni_model_M->Timing.t[0];
  if (rtb_Saturate_m - floor(rtb_Saturate_m) >= 0.5) {
    rtb_Saturate_m = ukupni_model_P.SignalGeneratorYaw_Amplitude;
  } else {
    rtb_Saturate_m = -ukupni_model_P.SignalGeneratorYaw_Amplitude;
  }

  /* End of SignalGenerator: '<S2>/Signal Generator: Yaw' */

  /* Gain: '<S12>/Gain1' incorporates:
   *  Constant: '<S2>/Constant: Yaw (deg)'
   *  Gain: '<S2>/Amplitude: Yaw (deg)'
   *  Sum: '<S2>/Sum1'
   */
  rtb_Sum1_i = (ukupni_model_P.AmplitudeYawdeg_Gain * rtb_Saturate_m +
                ukupni_model_P.ConstantYawdeg_Value) *
    ukupni_model_P.Gain1_Gain_c;

  /* Sum: '<S6>/Sum1' */
  rtb_Saturate = rtb_Sum1_i + rtb_TmpSignalConversionAtXInport1[1];

  /* Gain: '<S6>/Control Gain: K' incorporates:
   *  SignalConversion: '<S6>/TmpSignal ConversionAtControl Gain: KInport1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Saturate_m = ukupni_model_P.ControlGainK_Gain[i + 6] *
      rtb_TmpSignalConversionAtXInport1[3] + (ukupni_model_P.ControlGainK_Gain[i
      + 4] * rtb_TmpSignalConversionAtXInport1[2] +
      (ukupni_model_P.ControlGainK_Gain[i + 2] * rtb_Saturate +
       ukupni_model_P.ControlGainK_Gain[i] * rtb_YawLQRI));
    rtb_ControlGainK[i] = rtb_Saturate_m;
  }

  /* End of Gain: '<S6>/Control Gain: K' */

  /* Saturate: '<S7>/Saturate' incorporates:
   *  Integrator: '<S7>/Integrator'
   */
  if (ukupni_model_X.Integrator_CSTATE > ukupni_model_P.max_u) {
    rtb_Saturate_m = ukupni_model_P.max_u;
  } else if (ukupni_model_X.Integrator_CSTATE < -ukupni_model_P.max_u) {
    rtb_Saturate_m = -ukupni_model_P.max_u;
  } else {
    rtb_Saturate_m = ukupni_model_X.Integrator_CSTATE;
  }

  /* End of Saturate: '<S7>/Saturate' */

  /* Sum: '<S6>/Pitch: LQR+I' incorporates:
   *  Gain: '<S8>/Feed-forward Pitch Gain'
   *  Trigonometry: '<S8>/Trigonometric Function'
   */
  u0 = (ukupni_model_P.l_cm * ukupni_model_P.m_heli * ukupni_model_P.g /
        ukupni_model_P.K_pp * cos(rtb_Sum2_n) + rtb_ControlGainK[0]) +
    rtb_Saturate_m;

  /* Saturate: '<S5>/Pitch AMP Voltage Limit' */
  if (u0 > ukupni_model_P.max_u) {
    u0 = ukupni_model_P.max_u;
  } else {
    if (u0 < -ukupni_model_P.max_u) {
      u0 = -ukupni_model_P.max_u;
    }
  }

  /* End of Saturate: '<S5>/Pitch AMP Voltage Limit' */

  /* Gain: '<S5>/Gain' */
  ukupni_model_B.Gain = ukupni_model_P.Gain_Gain * u0;

  /* Saturate: '<S9>/Saturate' incorporates:
   *  Integrator: '<S9>/Integrator'
   */
  if (ukupni_model_X.Integrator_CSTATE_i > ukupni_model_P.max_u) {
    rtb_costheta_p = ukupni_model_P.max_u;
  } else if (ukupni_model_X.Integrator_CSTATE_i < -ukupni_model_P.max_u) {
    rtb_costheta_p = -ukupni_model_P.max_u;
  } else {
    rtb_costheta_p = ukupni_model_X.Integrator_CSTATE_i;
  }

  /* End of Saturate: '<S9>/Saturate' */

  /* Sum: '<S6>/Yaw: LQR+I' */
  u0 = rtb_ControlGainK[1] + rtb_costheta_p;

  /* Saturate: '<S5>/Yaw AMP Voltage Limit' */
  if (u0 > ukupni_model_P.max_u) {
    u0 = ukupni_model_P.max_u;
  } else {
    if (u0 < -ukupni_model_P.max_u) {
      u0 = -ukupni_model_P.max_u;
    }
  }

  /* End of Saturate: '<S5>/Yaw AMP Voltage Limit' */

  /* Gain: '<S5>/Gain1' */
  ukupni_model_B.Gain1 = ukupni_model_P.Gain1_Gain_d * u0;
  if (rtmIsMajorTimeStep(ukupni_model_M)) {
    /* S-Function Block: <S5>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) ukupni_model_P.AnalogOutput_RangeMode;
        parm.rangeidx = ukupni_model_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &ukupni_model_P.AnalogOutput_Channels,
                       &ukupni_model_B.Gain, &parm);
      }
    }

    /* S-Function Block: <S5>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) ukupni_model_P.AnalogOutput1_RangeMode;
        parm.rangeidx = ukupni_model_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &ukupni_model_P.AnalogOutput1_Channels,
                       &ukupni_model_B.Gain1, &parm);
      }
    }
  }

  /* Sum: '<S7>/Sum' incorporates:
   *  Gain: '<S7>/Pitch Integral Control Gain: K(1,5)'
   *  Gain: '<S7>/Pitch Reset Time'
   *  Gain: '<S7>/Yaw Cross-Integral Control Gain: K(1,6)'
   *  Integrator: '<S7>/Integrator'
   *  Sum: '<S7>/Integral Input  (V//s)'
   *  Sum: '<S7>/u-v'
   */
  ukupni_model_B.Sum = (ukupni_model_P.PitchIntegralControlGainK15_Gain *
                        rtb_YawLQRI +
                        ukupni_model_P.YawCrossIntegralControlGainK16_Gain *
                        rtb_Saturate) + 1.0 / ukupni_model_P.Tr_p *
    (rtb_Saturate_m - ukupni_model_X.Integrator_CSTATE);

  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Pitch Cross-Integral Control Gain: K(2,5)'
   *  Gain: '<S9>/Yaw Integral Control Gain: K(2,6)'
   *  Gain: '<S9>/Yaw Reset Time'
   *  Integrator: '<S9>/Integrator'
   *  Sum: '<S9>/Integral Input  (V//s)'
   *  Sum: '<S9>/u-v'
   */
  ukupni_model_B.Sum_f = (ukupni_model_P.YawIntegralControlGainK26_Gain *
    rtb_Saturate + ukupni_model_P.PitchCrossIntegralControlGainK25_Gain *
    rtb_YawLQRI) + 1.0 / ukupni_model_P.Tr_y * (rtb_costheta_p -
    ukupni_model_X.Integrator_CSTATE_i);

  /* Gain: '<S14>/Gain' */
  ukupni_model_B.Gain_a[0] = ukupni_model_P.Gain_Gain_i * rtb_Sum2_n;
  ukupni_model_B.Gain_a[1] = ukupni_model_P.Gain_Gain_i * rtb_Sum1_i;

  /* Gain: '<S15>/Gain' incorporates:
   *  SignalConversion: '<S6>/TmpSignal ConversionAt-XInport1'
   */
  ukupni_model_B.Gain_d[0] = ukupni_model_P.Gain_Gain_l * ukupni_model_B.Bias;
  ukupni_model_B.Gain_d[1] = ukupni_model_P.Gain_Gain_l *
    ukupni_model_B.EncoderResolutionYaw;
  ukupni_model_B.Gain_d[2] = ukupni_model_P.Gain_Gain_l *
    rtb_TmpSignalConversionAtControlGainKInport1[2];
  ukupni_model_B.Gain_d[3] = ukupni_model_P.Gain_Gain_l *
    rtb_TmpSignalConversionAtControlGainKInport1[3];

  /* Integrator: '<S17>/theta' */
  /* Limited  Integrator  */
  if (ukupni_model_X.theta_CSTATE >= ukupni_model_P.theta_UpperSat) {
    ukupni_model_X.theta_CSTATE = ukupni_model_P.theta_UpperSat;
  } else {
    if (ukupni_model_X.theta_CSTATE <= ukupni_model_P.theta_LowerSat) {
      ukupni_model_X.theta_CSTATE = ukupni_model_P.theta_LowerSat;
    }
  }

  /* Integrator: '<S17>/theta_dot' */
  ukupni_model_B.theta_dot = ukupni_model_X.theta_dot_CSTATE;

  /* Integrator: '<S17>/psi_dot' */
  ukupni_model_B.psi_dot = ukupni_model_X.psi_dot_CSTATE;

  /* Gain: '<S13>/Gain' incorporates:
   *  Integrator: '<S17>/psi'
   *  Integrator: '<S17>/theta'
   *  SignalConversion: '<S16>/TmpSignal ConversionAt-XInport1'
   */
  ukupni_model_B.Gain_k[0] = ukupni_model_P.Gain_Gain_b *
    ukupni_model_X.theta_CSTATE;
  ukupni_model_B.Gain_k[1] = ukupni_model_P.Gain_Gain_b *
    ukupni_model_X.psi_CSTATE;
  ukupni_model_B.Gain_k[2] = ukupni_model_P.Gain_Gain_b *
    ukupni_model_B.theta_dot;
  ukupni_model_B.Gain_k[3] = ukupni_model_P.Gain_Gain_b * ukupni_model_B.psi_dot;
  if (rtmIsMajorTimeStep(ukupni_model_M)) {
  }

  /* Gain: '<S18>/Feed-forward Pitch Gain' incorporates:
   *  Trigonometry: '<S18>/Trigonometric Function'
   */
  rtb_YawLQRI = ukupni_model_P.l_cm * ukupni_model_P.m_heli * ukupni_model_P.g /
    ukupni_model_P.K_pp * cos(rtb_Sum2_n);

  /* Gain: '<S16>/-X' incorporates:
   *  Integrator: '<S17>/psi'
   *  Integrator: '<S17>/theta'
   *  SignalConversion: '<S16>/TmpSignal ConversionAt-XInport1'
   */
  for (i = 0; i < 4; i++) {
    rtb_Saturate = ukupni_model_P.X_Gain_o[i + 12] * ukupni_model_B.psi_dot +
      (ukupni_model_P.X_Gain_o[i + 8] * ukupni_model_B.theta_dot +
       (ukupni_model_P.X_Gain_o[i + 4] * ukupni_model_X.psi_CSTATE +
        ukupni_model_P.X_Gain_o[i] * ukupni_model_X.theta_CSTATE));
    rtb_TmpSignalConversionAtControlGainKInport1[i] = rtb_Saturate;
  }

  /* End of Gain: '<S16>/-X' */

  /* Sum: '<S16>/Sum2' */
  rtb_Sum2_n += rtb_TmpSignalConversionAtControlGainKInport1[0];

  /* Sum: '<S16>/Sum1' */
  rtb_Sum1_i += rtb_TmpSignalConversionAtControlGainKInport1[1];

  /* Gain: '<S16>/Control Gain: K' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtControl Gain: KInport1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Saturate_m = ukupni_model_P.ControlGainK_Gain_k[i + 6] *
      rtb_TmpSignalConversionAtControlGainKInport1[3] +
      (ukupni_model_P.ControlGainK_Gain_k[i + 4] *
       rtb_TmpSignalConversionAtControlGainKInport1[2] +
       (ukupni_model_P.ControlGainK_Gain_k[i + 2] * rtb_Sum1_i +
        ukupni_model_P.ControlGainK_Gain_k[i] * rtb_Sum2_n));
    rtb_ControlGainK[i] = rtb_Saturate_m;
  }

  /* End of Gain: '<S16>/Control Gain: K' */

  /* Saturate: '<S19>/Saturate' incorporates:
   *  Integrator: '<S19>/Integrator'
   */
  if (ukupni_model_X.Integrator_CSTATE_j > ukupni_model_P.max_u) {
    rtb_Saturate_m = ukupni_model_P.max_u;
  } else if (ukupni_model_X.Integrator_CSTATE_j < -ukupni_model_P.max_u) {
    rtb_Saturate_m = -ukupni_model_P.max_u;
  } else {
    rtb_Saturate_m = ukupni_model_X.Integrator_CSTATE_j;
  }

  /* End of Saturate: '<S19>/Saturate' */

  /* Sum: '<S16>/Pitch: LQR+I' */
  u0 = (rtb_YawLQRI + rtb_ControlGainK[0]) + rtb_Saturate_m;

  /* Saturate: '<S17>/Pitch AMP Voltage Limit' */
  if (u0 > ukupni_model_P.max_u) {
    ukupni_model_B.PitchAMPVoltageLimit = ukupni_model_P.max_u;
  } else if (u0 < -ukupni_model_P.max_u) {
    ukupni_model_B.PitchAMPVoltageLimit = -ukupni_model_P.max_u;
  } else {
    ukupni_model_B.PitchAMPVoltageLimit = u0;
  }

  /* End of Saturate: '<S17>/Pitch AMP Voltage Limit' */

  /* Saturate: '<S20>/Saturate' incorporates:
   *  Integrator: '<S20>/Integrator'
   */
  if (ukupni_model_X.Integrator_CSTATE_o > ukupni_model_P.max_u) {
    rtb_Saturate = ukupni_model_P.max_u;
  } else if (ukupni_model_X.Integrator_CSTATE_o < -ukupni_model_P.max_u) {
    rtb_Saturate = -ukupni_model_P.max_u;
  } else {
    rtb_Saturate = ukupni_model_X.Integrator_CSTATE_o;
  }

  /* End of Saturate: '<S20>/Saturate' */

  /* Sum: '<S16>/Yaw: LQR+I' */
  u0 = rtb_ControlGainK[1] + rtb_Saturate;

  /* Saturate: '<S17>/Yaw AMP Voltage Limit' */
  if (u0 > ukupni_model_P.max_u) {
    ukupni_model_B.YawAMPVoltageLimit = ukupni_model_P.max_u;
  } else if (u0 < -ukupni_model_P.max_u) {
    ukupni_model_B.YawAMPVoltageLimit = -ukupni_model_P.max_u;
  } else {
    ukupni_model_B.YawAMPVoltageLimit = u0;
  }

  /* End of Saturate: '<S17>/Yaw AMP Voltage Limit' */
  if (rtmIsMajorTimeStep(ukupni_model_M)) {
  }

  /* Sum: '<S19>/Sum' incorporates:
   *  Gain: '<S19>/Pitch Integral Control Gain: K(1,5)'
   *  Gain: '<S19>/Pitch Reset Time'
   *  Gain: '<S19>/Yaw Cross-Integral Control Gain: K(1,6)'
   *  Integrator: '<S19>/Integrator'
   *  Sum: '<S19>/Integral Input  (V//s)'
   *  Sum: '<S19>/u-v'
   */
  ukupni_model_B.Sum_o = (ukupni_model_P.PitchIntegralControlGainK15_Gain_b *
    rtb_Sum2_n + ukupni_model_P.YawCrossIntegralControlGainK16_Gain_o *
    rtb_Sum1_i) + 1.0 / ukupni_model_P.Tr_p * (rtb_Saturate_m -
    ukupni_model_X.Integrator_CSTATE_j);

  /* Sum: '<S20>/Sum' incorporates:
   *  Gain: '<S20>/Pitch Cross-Integral Control Gain: K(2,5)'
   *  Gain: '<S20>/Yaw Integral Control Gain: K(2,6)'
   *  Gain: '<S20>/Yaw Reset Time'
   *  Integrator: '<S20>/Integrator'
   *  Sum: '<S20>/Integral Input  (V//s)'
   *  Sum: '<S20>/u-v'
   */
  ukupni_model_B.Sum_j = (ukupni_model_P.YawIntegralControlGainK26_Gain_g *
    rtb_Sum1_i + ukupni_model_P.PitchCrossIntegralControlGainK25_Gain_p *
    rtb_Sum2_n) + 1.0 / ukupni_model_P.Tr_y * (rtb_Saturate -
    ukupni_model_X.Integrator_CSTATE_o);

  /* Trigonometry: '<S23>/cos(theta)' incorporates:
   *  Integrator: '<S17>/theta'
   */
  rtb_costheta_p = cos(ukupni_model_X.theta_CSTATE);

  /* Product: '<S17>/Divide by Inertia' incorporates:
   *  Constant: '<S23>/Yaw Inertia'
   *  Gain: '<S17>/Cross-torque acting on Yaw  from Pitch Motor'
   *  Gain: '<S17>/Thrust torque from  Yaw Motor'
   *  Gain: '<S17>/Yaw Viscous Damping'
   *  Gain: '<S23>/m_heli*l_cm^2'
   *  Gain: '<S24>/2*m*lcm^2'
   *  Integrator: '<S17>/psi'
   *  Integrator: '<S17>/theta'
   *  Product: '<S23>/cos(theta)^2'
   *  Product: '<S24>/Product'
   *  Sum: '<S17>/Sum4'
   *  Sum: '<S23>/Sum3'
   *  Trigonometry: '<S24>/cos(theta)'
   *  Trigonometry: '<S24>/sin(psi)'
   */
  ukupni_model_B.DividebyInertia = ((cos(ukupni_model_X.theta_CSTATE) * sin
    (ukupni_model_X.psi_CSTATE) * ukupni_model_B.theta_dot *
    ukupni_model_B.psi_dot * (2.0 * ukupni_model_P.m_heli * 2.5E-5) +
    (ukupni_model_P.K_yy * ukupni_model_B.YawAMPVoltageLimit +
     ukupni_model_P.K_yp * ukupni_model_B.PitchAMPVoltageLimit)) -
    ukupni_model_P.B_y * ukupni_model_B.psi_dot) / (ukupni_model_P.m_heli *
    2.5E-5 * (rtb_costheta_p * rtb_costheta_p) + ukupni_model_P.J_eq_y);

  /* Gain: '<S17>/Pitch Inertia' incorporates:
   *  Gain: '<S17>/Cross-torque acting on Pitch  from Yaw Motor'
   *  Gain: '<S17>/Pitch Viscous Damping'
   *  Gain: '<S17>/Thrust torque from  Pitch Motor'
   *  Gain: '<S21>/m*g*lcm'
   *  Gain: '<S22>/m*lcm^2'
   *  Integrator: '<S17>/theta'
   *  Product: '<S22>/Product'
   *  Sum: '<S17>/Sum2'
   *  Trigonometry: '<S21>/Trigonometric Function'
   *  Trigonometry: '<S22>/cos(theta)'
   *  Trigonometry: '<S22>/sin(theta)'
   */
  ukupni_model_B.PitchInertia = ((((ukupni_model_P.K_pp *
    ukupni_model_B.PitchAMPVoltageLimit + ukupni_model_P.K_py *
    ukupni_model_B.YawAMPVoltageLimit) - sin(ukupni_model_X.theta_CSTATE) * cos
    (ukupni_model_X.theta_CSTATE) * ukupni_model_B.psi_dot *
    ukupni_model_B.psi_dot * (ukupni_model_P.m_heli * 2.5E-5)) -
    ukupni_model_P.m_heli * ukupni_model_P.g * ukupni_model_P.l_cm * cos
    (ukupni_model_X.theta_CSTATE)) - ukupni_model_P.B_p *
    ukupni_model_B.theta_dot) * (1.0 / ukupni_model_P.J_p);
}

/* Model update function */
void ukupni_model_update(void)
{
  if (rtmIsMajorTimeStep(ukupni_model_M)) {
    rt_ertODEUpdateContinuousStates(&ukupni_model_M->solverInfo);
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
  if (!(++ukupni_model_M->Timing.clockTick0)) {
    ++ukupni_model_M->Timing.clockTickH0;
  }

  ukupni_model_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ukupni_model_M->solverInfo);

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
    if (!(++ukupni_model_M->Timing.clockTick1)) {
      ++ukupni_model_M->Timing.clockTickH1;
    }

    ukupni_model_M->Timing.t[1] = ukupni_model_M->Timing.clockTick1 *
      ukupni_model_M->Timing.stepSize1 + ukupni_model_M->Timing.clockTickH1 *
      ukupni_model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ukupni_model_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_ukupni_model_T *_rtXdot;
  _rtXdot = ((XDot_ukupni_model_T *) ukupni_model_M->derivs);

  /* Derivatives for TransferFcn: '<S5>/Derivative Filter: Pitch' */
  _rtXdot->DerivativeFilterPitch_CSTATE[0] = 0.0;
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    ukupni_model_P.DerivativeFilterPitch_A[0] *
    ukupni_model_X.DerivativeFilterPitch_CSTATE[0];
  _rtXdot->DerivativeFilterPitch_CSTATE[1] = 0.0;
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    ukupni_model_P.DerivativeFilterPitch_A[1] *
    ukupni_model_X.DerivativeFilterPitch_CSTATE[1];
  _rtXdot->DerivativeFilterPitch_CSTATE[1] +=
    ukupni_model_X.DerivativeFilterPitch_CSTATE[0];
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    ukupni_model_B.EncoderResolutionPitch;

  /* Derivatives for TransferFcn: '<S5>/Derivative Filter: Yaw' */
  _rtXdot->DerivativeFilterYaw_CSTATE[0] = 0.0;
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    ukupni_model_P.DerivativeFilterYaw_A[0] *
    ukupni_model_X.DerivativeFilterYaw_CSTATE[0];
  _rtXdot->DerivativeFilterYaw_CSTATE[1] = 0.0;
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    ukupni_model_P.DerivativeFilterYaw_A[1] *
    ukupni_model_X.DerivativeFilterYaw_CSTATE[1];
  _rtXdot->DerivativeFilterYaw_CSTATE[1] +=
    ukupni_model_X.DerivativeFilterYaw_CSTATE[0];
  _rtXdot->DerivativeFilterYaw_CSTATE[0] += ukupni_model_B.EncoderResolutionYaw;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = ukupni_model_B.Sum;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = ukupni_model_B.Sum_f;

  /* Derivatives for Integrator: '<S17>/theta' */
  lsat = (ukupni_model_X.theta_CSTATE <= ukupni_model_P.theta_LowerSat);
  usat = (ukupni_model_X.theta_CSTATE >= ukupni_model_P.theta_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (ukupni_model_B.theta_dot > 0.0)) ||
      (usat && (ukupni_model_B.theta_dot < 0.0))) {
    _rtXdot->theta_CSTATE = ukupni_model_B.theta_dot;
  } else {
    /* in saturation */
    _rtXdot->theta_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S17>/theta' */

  /* Derivatives for Integrator: '<S17>/psi' */
  _rtXdot->psi_CSTATE = ukupni_model_B.psi_dot;

  /* Derivatives for Integrator: '<S17>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = ukupni_model_B.PitchInertia;

  /* Derivatives for Integrator: '<S17>/psi_dot' */
  _rtXdot->psi_dot_CSTATE = ukupni_model_B.DividebyInertia;

  /* Derivatives for Integrator: '<S19>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = ukupni_model_B.Sum_o;

  /* Derivatives for Integrator: '<S20>/Integrator' */
  _rtXdot->Integrator_CSTATE_o = ukupni_model_B.Sum_j;
}

/* Model initialize function */
void ukupni_model_initialize(void)
{
  /* S-Function Block: <S5>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) ukupni_model_P.AnalogOutput_RangeMode;
      parm.rangeidx = ukupni_model_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &ukupni_model_P.AnalogOutput_Channels,
                     &ukupni_model_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* S-Function Block: <S5>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) ukupni_model_P.AnalogOutput1_RangeMode;
      parm.rangeidx = ukupni_model_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &ukupni_model_P.AnalogOutput1_Channels,
                     &ukupni_model_P.AnalogOutput1_InitialValue, &parm);
    }
  }

  /* S-Function Block: <S5>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = ukupni_model_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &ukupni_model_P.EncoderInput_Channels, NULL, &parm);
  }

  /* S-Function Block: <S5>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = ukupni_model_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &ukupni_model_P.EncoderInput1_Channels, NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S5>/Derivative Filter: Pitch' */
  ukupni_model_X.DerivativeFilterPitch_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Derivative Filter: Yaw' */
  ukupni_model_X.DerivativeFilterYaw_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Derivative Filter: Pitch' */
  ukupni_model_X.DerivativeFilterPitch_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Derivative Filter: Yaw' */
  ukupni_model_X.DerivativeFilterYaw_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  ukupni_model_X.Integrator_CSTATE = ukupni_model_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  ukupni_model_X.Integrator_CSTATE_i = ukupni_model_P.Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S17>/theta' */
  ukupni_model_X.theta_CSTATE = ukupni_model_P.theta_0;

  /* InitializeConditions for Integrator: '<S17>/psi' */
  ukupni_model_X.psi_CSTATE = ukupni_model_P.psi_IC;

  /* InitializeConditions for Integrator: '<S17>/theta_dot' */
  ukupni_model_X.theta_dot_CSTATE = ukupni_model_P.theta_dot_IC;

  /* InitializeConditions for Integrator: '<S17>/psi_dot' */
  ukupni_model_X.psi_dot_CSTATE = ukupni_model_P.psi_dot_IC;

  /* InitializeConditions for Integrator: '<S19>/Integrator' */
  ukupni_model_X.Integrator_CSTATE_j = ukupni_model_P.Integrator_IC_o;

  /* InitializeConditions for Integrator: '<S20>/Integrator' */
  ukupni_model_X.Integrator_CSTATE_o = ukupni_model_P.Integrator_IC_j;
}

/* Model terminate function */
void ukupni_model_terminate(void)
{
  /* S-Function Block: <S5>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) ukupni_model_P.AnalogOutput_RangeMode;
      parm.rangeidx = ukupni_model_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &ukupni_model_P.AnalogOutput_Channels,
                     &ukupni_model_P.AnalogOutput_FinalValue, &parm);
    }
  }

  /* S-Function Block: <S5>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) ukupni_model_P.AnalogOutput1_RangeMode;
      parm.rangeidx = ukupni_model_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &ukupni_model_P.AnalogOutput1_Channels,
                     &ukupni_model_P.AnalogOutput1_FinalValue, &parm);
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
  ukupni_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ukupni_model_update();
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
  ukupni_model_initialize();
}

void MdlTerminate(void)
{
  ukupni_model_terminate();
}

/* Registration function */
RT_MODEL_ukupni_model_T *ukupni_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ukupni_model_P.EncoderInput_InputFilter = rtInf;
  ukupni_model_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)ukupni_model_M, 0,
                sizeof(RT_MODEL_ukupni_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ukupni_model_M->solverInfo,
                          &ukupni_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&ukupni_model_M->solverInfo, &rtmGetTPtr(ukupni_model_M));
    rtsiSetStepSizePtr(&ukupni_model_M->solverInfo,
                       &ukupni_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&ukupni_model_M->solverInfo, &ukupni_model_M->derivs);
    rtsiSetContStatesPtr(&ukupni_model_M->solverInfo, (real_T **)
                         &ukupni_model_M->contStates);
    rtsiSetNumContStatesPtr(&ukupni_model_M->solverInfo,
      &ukupni_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ukupni_model_M->solverInfo,
      &ukupni_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ukupni_model_M->solverInfo,
      &ukupni_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ukupni_model_M->solverInfo,
      &ukupni_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ukupni_model_M->solverInfo, (&rtmGetErrorStatus
      (ukupni_model_M)));
    rtsiSetRTModelPtr(&ukupni_model_M->solverInfo, ukupni_model_M);
  }

  rtsiSetSimTimeStep(&ukupni_model_M->solverInfo, MAJOR_TIME_STEP);
  ukupni_model_M->intgData.y = ukupni_model_M->odeY;
  ukupni_model_M->intgData.f[0] = ukupni_model_M->odeF[0];
  ukupni_model_M->intgData.f[1] = ukupni_model_M->odeF[1];
  ukupni_model_M->intgData.f[2] = ukupni_model_M->odeF[2];
  ukupni_model_M->contStates = ((real_T *) &ukupni_model_X);
  rtsiSetSolverData(&ukupni_model_M->solverInfo, (void *)
                    &ukupni_model_M->intgData);
  rtsiSetSolverName(&ukupni_model_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ukupni_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ukupni_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ukupni_model_M->Timing.sampleTimes =
      (&ukupni_model_M->Timing.sampleTimesArray[0]);
    ukupni_model_M->Timing.offsetTimes =
      (&ukupni_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ukupni_model_M->Timing.sampleTimes[0] = (0.0);
    ukupni_model_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    ukupni_model_M->Timing.offsetTimes[0] = (0.0);
    ukupni_model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ukupni_model_M, &ukupni_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ukupni_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ukupni_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ukupni_model_M, -1);
  ukupni_model_M->Timing.stepSize0 = 0.001;
  ukupni_model_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  ukupni_model_M->Sizes.checksums[0] = (907498927U);
  ukupni_model_M->Sizes.checksums[1] = (2531890356U);
  ukupni_model_M->Sizes.checksums[2] = (1391664844U);
  ukupni_model_M->Sizes.checksums[3] = (826193499U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ukupni_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ukupni_model_M->extModeInfo,
      &ukupni_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ukupni_model_M->extModeInfo,
                        ukupni_model_M->Sizes.checksums);
    rteiSetTPtr(ukupni_model_M->extModeInfo, rtmGetTPtr(ukupni_model_M));
  }

  ukupni_model_M->solverInfoPtr = (&ukupni_model_M->solverInfo);
  ukupni_model_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&ukupni_model_M->solverInfo, 0.001);
  rtsiSetSolverMode(&ukupni_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ukupni_model_M->blockIO = ((void *) &ukupni_model_B);
  (void) memset(((void *) &ukupni_model_B), 0,
                sizeof(B_ukupni_model_T));

  /* parameters */
  ukupni_model_M->defaultParam = ((real_T *)&ukupni_model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ukupni_model_X;
    ukupni_model_M->contStates = (x);
    (void) memset((void *)&ukupni_model_X, 0,
                  sizeof(X_ukupni_model_T));
  }

  /* states (dwork) */
  ukupni_model_M->dwork = ((void *) &ukupni_model_DW);
  (void) memset((void *)&ukupni_model_DW, 0,
                sizeof(DW_ukupni_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ukupni_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ukupni_model_M->Sizes.numContStates = (12);/* Number of continuous states */
  ukupni_model_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ukupni_model_M->Sizes.numY = (0);    /* Number of model outputs */
  ukupni_model_M->Sizes.numU = (0);    /* Number of model inputs */
  ukupni_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ukupni_model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ukupni_model_M->Sizes.numBlocks = (116);/* Number of blocks */
  ukupni_model_M->Sizes.numBlockIO = (19);/* Number of block outputs */
  ukupni_model_M->Sizes.numBlockPrms = (128);/* Sum of parameter "widths" */
  return ukupni_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
