/*
 * q_heli_2d_open_loop.c
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
#include "q_heli_2d_open_loop_dt.h"

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
B_q_heli_2d_open_loop_T q_heli_2d_open_loop_B;

/* Continuous states */
X_q_heli_2d_open_loop_T q_heli_2d_open_loop_X;

/* Block states (auto storage) */
DW_q_heli_2d_open_loop_T q_heli_2d_open_loop_DW;

/* Real-time model */
RT_MODEL_q_heli_2d_open_loop_T q_heli_2d_open_loop_M_;
RT_MODEL_q_heli_2d_open_loop_T *const q_heli_2d_open_loop_M =
  &q_heli_2d_open_loop_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  q_heli_2d_open_loop_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  q_heli_2d_open_loop_output();
  q_heli_2d_open_loop_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  q_heli_2d_open_loop_output();
  q_heli_2d_open_loop_derivatives();

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
void q_heli_2d_open_loop_output(void)
{
  real_T temp;
  real_T u0;
  real_T u2;
  if (rtmIsMajorTimeStep(q_heli_2d_open_loop_M)) {
    /* set solver stop time */
    if (!(q_heli_2d_open_loop_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_heli_2d_open_loop_M->solverInfo,
                            ((q_heli_2d_open_loop_M->Timing.clockTickH0 + 1) *
        q_heli_2d_open_loop_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_heli_2d_open_loop_M->solverInfo,
                            ((q_heli_2d_open_loop_M->Timing.clockTick0 + 1) *
        q_heli_2d_open_loop_M->Timing.stepSize0 +
        q_heli_2d_open_loop_M->Timing.clockTickH0 *
        q_heli_2d_open_loop_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_heli_2d_open_loop_M)) {
    q_heli_2d_open_loop_M->Timing.t[0] = rtsiGetT
      (&q_heli_2d_open_loop_M->solverInfo);
  }

  /* SignalGenerator: '<S2>/Signal Generator: Pitch (V)' */
  temp = q_heli_2d_open_loop_P.SignalGeneratorPitchV_Frequency *
    q_heli_2d_open_loop_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    q_heli_2d_open_loop_B.SignalGeneratorPitchV =
      q_heli_2d_open_loop_P.SignalGeneratorPitchV_Amplitude;
  } else {
    q_heli_2d_open_loop_B.SignalGeneratorPitchV =
      -q_heli_2d_open_loop_P.SignalGeneratorPitchV_Amplitude;
  }

  /* End of SignalGenerator: '<S2>/Signal Generator: Pitch (V)' */

  /* Gain: '<S2>/Amplitude: Pitch (V)' */
  q_heli_2d_open_loop_B.AmplitudePitchV =
    q_heli_2d_open_loop_P.AmplitudePitchV_Gain *
    q_heli_2d_open_loop_B.SignalGeneratorPitchV;

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Constant: Pitch (V)'
   */
  q_heli_2d_open_loop_B.Sum = q_heli_2d_open_loop_B.AmplitudePitchV +
    q_heli_2d_open_loop_P.ConstantPitchV_Value;

  /* Saturate: '<S1>/Pitch AMP Voltage Limit' */
  temp = -q_heli_2d_open_loop_P.VMAX_AMP_P;
  u0 = q_heli_2d_open_loop_B.Sum;
  u2 = q_heli_2d_open_loop_P.VMAX_AMP_P;
  if (u0 > u2) {
    q_heli_2d_open_loop_B.PitchAMPVoltageLimit = u2;
  } else if (u0 < temp) {
    q_heli_2d_open_loop_B.PitchAMPVoltageLimit = temp;
  } else {
    q_heli_2d_open_loop_B.PitchAMPVoltageLimit = u0;
  }

  /* End of Saturate: '<S1>/Pitch AMP Voltage Limit' */

  /* Gain: '<S1>/Pitch amp Gain Pre-Compensation' */
  temp = q_heli_2d_open_loop_P.K_AMP;
  temp = 1.0 / temp;
  q_heli_2d_open_loop_B.PitchampGainPreCompensation = temp *
    q_heli_2d_open_loop_B.PitchAMPVoltageLimit;

  /* SignalGenerator: '<S2>/Signal Generator: Yaw (V)' */
  temp = q_heli_2d_open_loop_P.SignalGeneratorYawV_Frequency *
    q_heli_2d_open_loop_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    q_heli_2d_open_loop_B.SignalGeneratorYawV =
      q_heli_2d_open_loop_P.SignalGeneratorYawV_Amplitude;
  } else {
    q_heli_2d_open_loop_B.SignalGeneratorYawV =
      -q_heli_2d_open_loop_P.SignalGeneratorYawV_Amplitude;
  }

  /* End of SignalGenerator: '<S2>/Signal Generator: Yaw (V)' */

  /* Gain: '<S2>/Amplitude: Yaw (V)' */
  q_heli_2d_open_loop_B.AmplitudeYawV = q_heli_2d_open_loop_P.AmplitudeYawV_Gain
    * q_heli_2d_open_loop_B.SignalGeneratorYawV;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/Constant: Yaw (V)'
   */
  q_heli_2d_open_loop_B.Sum1 = q_heli_2d_open_loop_B.AmplitudeYawV +
    q_heli_2d_open_loop_P.ConstantYawV_Value;

  /* Saturate: '<S1>/Yaw AMP Voltage Limit' */
  temp = -q_heli_2d_open_loop_P.VMAX_AMP_Y;
  u0 = q_heli_2d_open_loop_B.Sum1;
  u2 = q_heli_2d_open_loop_P.VMAX_AMP_Y;
  if (u0 > u2) {
    q_heli_2d_open_loop_B.YawAMPVoltageLimit = u2;
  } else if (u0 < temp) {
    q_heli_2d_open_loop_B.YawAMPVoltageLimit = temp;
  } else {
    q_heli_2d_open_loop_B.YawAMPVoltageLimit = u0;
  }

  /* End of Saturate: '<S1>/Yaw AMP Voltage Limit' */

  /* Gain: '<S1>/Yaw amp Gain Pre-Compensation' */
  temp = q_heli_2d_open_loop_P.K_AMP;
  temp = 1.0 / temp;
  q_heli_2d_open_loop_B.YawampGainPreCompensation = temp *
    q_heli_2d_open_loop_B.YawAMPVoltageLimit;
  if (rtmIsMajorTimeStep(q_heli_2d_open_loop_M)) {
    /* S-Function Block: <S1>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) q_heli_2d_open_loop_P.AnalogOutput_RangeMode;
        parm.rangeidx = q_heli_2d_open_loop_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &q_heli_2d_open_loop_P.AnalogOutput_Channels,
                       &q_heli_2d_open_loop_B.PitchampGainPreCompensation, &parm);
      }
    }

    /* S-Function Block: <S1>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) q_heli_2d_open_loop_P.AnalogOutput1_RangeMode;
        parm.rangeidx = q_heli_2d_open_loop_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &q_heli_2d_open_loop_P.AnalogOutput1_Channels,
                       &q_heli_2d_open_loop_B.YawampGainPreCompensation, &parm);
      }
    }

    /* S-Function Block: <S1>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = q_heli_2d_open_loop_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &q_heli_2d_open_loop_P.EncoderInput_Channels,
                     &q_heli_2d_open_loop_B.EncoderInput, &parm);
    }

    /* S-Function Block: <S1>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = q_heli_2d_open_loop_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &q_heli_2d_open_loop_P.EncoderInput1_Channels,
                     &q_heli_2d_open_loop_B.EncoderInput1, &parm);
    }

    /* Gain: '<S1>/Encoder Resolution: Pitch ' */
    q_heli_2d_open_loop_B.EncoderResolutionPitch = q_heli_2d_open_loop_P.K_EC_P *
      q_heli_2d_open_loop_B.EncoderInput;

    /* Bias: '<S1>/Bias' */
    q_heli_2d_open_loop_B.Bias = q_heli_2d_open_loop_B.EncoderResolutionPitch +
      q_heli_2d_open_loop_P.theta_0;

    /* Gain: '<S1>/Encoder Resolution: Yaw' */
    q_heli_2d_open_loop_B.EncoderResolutionYaw = q_heli_2d_open_loop_P.K_EC_Y *
      q_heli_2d_open_loop_B.EncoderInput1;

    /* Gain: '<S5>/Gain' incorporates:
     *  Constant: '<Root>/No Desired'
     */
    q_heli_2d_open_loop_B.Gain[0] = q_heli_2d_open_loop_P.Gain_Gain *
      q_heli_2d_open_loop_P.NoDesired_Value[0];
    q_heli_2d_open_loop_B.Gain[1] = q_heli_2d_open_loop_P.Gain_Gain *
      q_heli_2d_open_loop_P.NoDesired_Value[1];
  }

  /* TransferFcn: '<S1>/Derivative Filter: Pitch' */
  q_heli_2d_open_loop_B.DerivativeFilterPitch = 0.0;
  q_heli_2d_open_loop_B.DerivativeFilterPitch +=
    q_heli_2d_open_loop_P.DerivativeFilterPitch_C[0] *
    q_heli_2d_open_loop_X.DerivativeFilterPitch_CSTATE[0];
  q_heli_2d_open_loop_B.DerivativeFilterPitch +=
    q_heli_2d_open_loop_P.DerivativeFilterPitch_C[1] *
    q_heli_2d_open_loop_X.DerivativeFilterPitch_CSTATE[1];

  /* TransferFcn: '<S1>/Derivative Filter: Yaw' */
  q_heli_2d_open_loop_B.DerivativeFilterYaw = 0.0;
  q_heli_2d_open_loop_B.DerivativeFilterYaw +=
    q_heli_2d_open_loop_P.DerivativeFilterYaw_C[0] *
    q_heli_2d_open_loop_X.DerivativeFilterYaw_CSTATE[0];
  q_heli_2d_open_loop_B.DerivativeFilterYaw +=
    q_heli_2d_open_loop_P.DerivativeFilterYaw_C[1] *
    q_heli_2d_open_loop_X.DerivativeFilterYaw_CSTATE[1];

  /* Gain: '<S6>/Gain' */
  q_heli_2d_open_loop_B.Gain_m[0] = q_heli_2d_open_loop_P.Gain_Gain_h *
    q_heli_2d_open_loop_B.Bias;
  q_heli_2d_open_loop_B.Gain_m[1] = q_heli_2d_open_loop_P.Gain_Gain_h *
    q_heli_2d_open_loop_B.EncoderResolutionYaw;
  q_heli_2d_open_loop_B.Gain_m[2] = q_heli_2d_open_loop_P.Gain_Gain_h *
    q_heli_2d_open_loop_B.DerivativeFilterPitch;
  q_heli_2d_open_loop_B.Gain_m[3] = q_heli_2d_open_loop_P.Gain_Gain_h *
    q_heli_2d_open_loop_B.DerivativeFilterYaw;
  if (rtmIsMajorTimeStep(q_heli_2d_open_loop_M)) {
    /* Gain: '<S4>/Gain' incorporates:
     *  Constant: '<Root>/No Simulation'
     */
    q_heli_2d_open_loop_B.Gain_l[0] = q_heli_2d_open_loop_P.Gain_Gain_k *
      q_heli_2d_open_loop_P.NoSimulation_Value[0];
    q_heli_2d_open_loop_B.Gain_l[1] = q_heli_2d_open_loop_P.Gain_Gain_k *
      q_heli_2d_open_loop_P.NoSimulation_Value[1];
    q_heli_2d_open_loop_B.Gain_l[2] = q_heli_2d_open_loop_P.Gain_Gain_k *
      q_heli_2d_open_loop_P.NoSimulation_Value[2];
    q_heli_2d_open_loop_B.Gain_l[3] = q_heli_2d_open_loop_P.Gain_Gain_k *
      q_heli_2d_open_loop_P.NoSimulation_Value[3];

    /* Constant: '<Root>/No Vm_sim' */
    q_heli_2d_open_loop_B.NoVm_sim = q_heli_2d_open_loop_P.NoVm_sim_Value;
  }
}

/* Model update function */
void q_heli_2d_open_loop_update(void)
{
  if (rtmIsMajorTimeStep(q_heli_2d_open_loop_M)) {
    rt_ertODEUpdateContinuousStates(&q_heli_2d_open_loop_M->solverInfo);
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
  if (!(++q_heli_2d_open_loop_M->Timing.clockTick0)) {
    ++q_heli_2d_open_loop_M->Timing.clockTickH0;
  }

  q_heli_2d_open_loop_M->Timing.t[0] = rtsiGetSolverStopTime
    (&q_heli_2d_open_loop_M->solverInfo);

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
    if (!(++q_heli_2d_open_loop_M->Timing.clockTick1)) {
      ++q_heli_2d_open_loop_M->Timing.clockTickH1;
    }

    q_heli_2d_open_loop_M->Timing.t[1] =
      q_heli_2d_open_loop_M->Timing.clockTick1 *
      q_heli_2d_open_loop_M->Timing.stepSize1 +
      q_heli_2d_open_loop_M->Timing.clockTickH1 *
      q_heli_2d_open_loop_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void q_heli_2d_open_loop_derivatives(void)
{
  XDot_q_heli_2d_open_loop_T *_rtXdot;
  _rtXdot = ((XDot_q_heli_2d_open_loop_T *) q_heli_2d_open_loop_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Derivative Filter: Pitch' */
  _rtXdot->DerivativeFilterPitch_CSTATE[0] = 0.0;
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    q_heli_2d_open_loop_P.DerivativeFilterPitch_A[0] *
    q_heli_2d_open_loop_X.DerivativeFilterPitch_CSTATE[0];
  _rtXdot->DerivativeFilterPitch_CSTATE[1] = 0.0;
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    q_heli_2d_open_loop_P.DerivativeFilterPitch_A[1] *
    q_heli_2d_open_loop_X.DerivativeFilterPitch_CSTATE[1];
  _rtXdot->DerivativeFilterPitch_CSTATE[1] +=
    q_heli_2d_open_loop_X.DerivativeFilterPitch_CSTATE[0];
  _rtXdot->DerivativeFilterPitch_CSTATE[0] +=
    q_heli_2d_open_loop_B.EncoderResolutionPitch;

  /* Derivatives for TransferFcn: '<S1>/Derivative Filter: Yaw' */
  _rtXdot->DerivativeFilterYaw_CSTATE[0] = 0.0;
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    q_heli_2d_open_loop_P.DerivativeFilterYaw_A[0] *
    q_heli_2d_open_loop_X.DerivativeFilterYaw_CSTATE[0];
  _rtXdot->DerivativeFilterYaw_CSTATE[1] = 0.0;
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    q_heli_2d_open_loop_P.DerivativeFilterYaw_A[1] *
    q_heli_2d_open_loop_X.DerivativeFilterYaw_CSTATE[1];
  _rtXdot->DerivativeFilterYaw_CSTATE[1] +=
    q_heli_2d_open_loop_X.DerivativeFilterYaw_CSTATE[0];
  _rtXdot->DerivativeFilterYaw_CSTATE[0] +=
    q_heli_2d_open_loop_B.EncoderResolutionYaw;
}

/* Model initialize function */
void q_heli_2d_open_loop_initialize(void)
{
  /* S-Function Block: <S1>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) q_heli_2d_open_loop_P.AnalogOutput_RangeMode;
      parm.rangeidx = q_heli_2d_open_loop_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_open_loop_P.AnalogOutput_Channels,
                     &q_heli_2d_open_loop_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* S-Function Block: <S1>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) q_heli_2d_open_loop_P.AnalogOutput1_RangeMode;
      parm.rangeidx = q_heli_2d_open_loop_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_open_loop_P.AnalogOutput1_Channels,
                     &q_heli_2d_open_loop_P.AnalogOutput1_InitialValue, &parm);
    }
  }

  /* S-Function Block: <S1>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = q_heli_2d_open_loop_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &q_heli_2d_open_loop_P.EncoderInput_Channels, NULL, &parm);
  }

  /* S-Function Block: <S1>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = q_heli_2d_open_loop_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &q_heli_2d_open_loop_P.EncoderInput1_Channels, NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S1>/Derivative Filter: Pitch' */
  q_heli_2d_open_loop_X.DerivativeFilterPitch_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Derivative Filter: Yaw' */
  q_heli_2d_open_loop_X.DerivativeFilterYaw_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Derivative Filter: Pitch' */
  q_heli_2d_open_loop_X.DerivativeFilterPitch_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Derivative Filter: Yaw' */
  q_heli_2d_open_loop_X.DerivativeFilterYaw_CSTATE[1] = 0.0;
}

/* Model terminate function */
void q_heli_2d_open_loop_terminate(void)
{
  /* S-Function Block: <S1>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) q_heli_2d_open_loop_P.AnalogOutput_RangeMode;
      parm.rangeidx = q_heli_2d_open_loop_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_open_loop_P.AnalogOutput_Channels,
                     &q_heli_2d_open_loop_P.AnalogOutput_FinalValue, &parm);
    }
  }

  /* S-Function Block: <S1>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) q_heli_2d_open_loop_P.AnalogOutput1_RangeMode;
      parm.rangeidx = q_heli_2d_open_loop_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &q_heli_2d_open_loop_P.AnalogOutput1_Channels,
                     &q_heli_2d_open_loop_P.AnalogOutput1_FinalValue, &parm);
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
  q_heli_2d_open_loop_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_heli_2d_open_loop_update();
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
  q_heli_2d_open_loop_initialize();
}

void MdlTerminate(void)
{
  q_heli_2d_open_loop_terminate();
}

/* Registration function */
RT_MODEL_q_heli_2d_open_loop_T *q_heli_2d_open_loop(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  q_heli_2d_open_loop_P.EncoderInput_InputFilter = rtInf;
  q_heli_2d_open_loop_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)q_heli_2d_open_loop_M, 0,
                sizeof(RT_MODEL_q_heli_2d_open_loop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_heli_2d_open_loop_M->solverInfo,
                          &q_heli_2d_open_loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_heli_2d_open_loop_M->solverInfo, &rtmGetTPtr
                (q_heli_2d_open_loop_M));
    rtsiSetStepSizePtr(&q_heli_2d_open_loop_M->solverInfo,
                       &q_heli_2d_open_loop_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_heli_2d_open_loop_M->solverInfo,
                 &q_heli_2d_open_loop_M->derivs);
    rtsiSetContStatesPtr(&q_heli_2d_open_loop_M->solverInfo, (real_T **)
                         &q_heli_2d_open_loop_M->contStates);
    rtsiSetNumContStatesPtr(&q_heli_2d_open_loop_M->solverInfo,
      &q_heli_2d_open_loop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&q_heli_2d_open_loop_M->solverInfo,
      &q_heli_2d_open_loop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&q_heli_2d_open_loop_M->solverInfo,
      &q_heli_2d_open_loop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&q_heli_2d_open_loop_M->solverInfo,
      &q_heli_2d_open_loop_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&q_heli_2d_open_loop_M->solverInfo,
                          (&rtmGetErrorStatus(q_heli_2d_open_loop_M)));
    rtsiSetRTModelPtr(&q_heli_2d_open_loop_M->solverInfo, q_heli_2d_open_loop_M);
  }

  rtsiSetSimTimeStep(&q_heli_2d_open_loop_M->solverInfo, MAJOR_TIME_STEP);
  q_heli_2d_open_loop_M->intgData.y = q_heli_2d_open_loop_M->odeY;
  q_heli_2d_open_loop_M->intgData.f[0] = q_heli_2d_open_loop_M->odeF[0];
  q_heli_2d_open_loop_M->intgData.f[1] = q_heli_2d_open_loop_M->odeF[1];
  q_heli_2d_open_loop_M->intgData.f[2] = q_heli_2d_open_loop_M->odeF[2];
  q_heli_2d_open_loop_M->contStates = ((real_T *) &q_heli_2d_open_loop_X);
  rtsiSetSolverData(&q_heli_2d_open_loop_M->solverInfo, (void *)
                    &q_heli_2d_open_loop_M->intgData);
  rtsiSetSolverName(&q_heli_2d_open_loop_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_heli_2d_open_loop_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    q_heli_2d_open_loop_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_heli_2d_open_loop_M->Timing.sampleTimes =
      (&q_heli_2d_open_loop_M->Timing.sampleTimesArray[0]);
    q_heli_2d_open_loop_M->Timing.offsetTimes =
      (&q_heli_2d_open_loop_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_heli_2d_open_loop_M->Timing.sampleTimes[0] = (0.0);
    q_heli_2d_open_loop_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    q_heli_2d_open_loop_M->Timing.offsetTimes[0] = (0.0);
    q_heli_2d_open_loop_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_heli_2d_open_loop_M, &q_heli_2d_open_loop_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_heli_2d_open_loop_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_heli_2d_open_loop_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_heli_2d_open_loop_M, 10.0);
  q_heli_2d_open_loop_M->Timing.stepSize0 = 0.001;
  q_heli_2d_open_loop_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  q_heli_2d_open_loop_M->Sizes.checksums[0] = (4209688749U);
  q_heli_2d_open_loop_M->Sizes.checksums[1] = (775728109U);
  q_heli_2d_open_loop_M->Sizes.checksums[2] = (1059099552U);
  q_heli_2d_open_loop_M->Sizes.checksums[3] = (2884881347U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    q_heli_2d_open_loop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_heli_2d_open_loop_M->extModeInfo,
      &q_heli_2d_open_loop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_heli_2d_open_loop_M->extModeInfo,
                        q_heli_2d_open_loop_M->Sizes.checksums);
    rteiSetTPtr(q_heli_2d_open_loop_M->extModeInfo, rtmGetTPtr
                (q_heli_2d_open_loop_M));
  }

  q_heli_2d_open_loop_M->solverInfoPtr = (&q_heli_2d_open_loop_M->solverInfo);
  q_heli_2d_open_loop_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&q_heli_2d_open_loop_M->solverInfo, 0.001);
  rtsiSetSolverMode(&q_heli_2d_open_loop_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_heli_2d_open_loop_M->blockIO = ((void *) &q_heli_2d_open_loop_B);

  {
    q_heli_2d_open_loop_B.SignalGeneratorPitchV = 0.0;
    q_heli_2d_open_loop_B.AmplitudePitchV = 0.0;
    q_heli_2d_open_loop_B.Sum = 0.0;
    q_heli_2d_open_loop_B.PitchAMPVoltageLimit = 0.0;
    q_heli_2d_open_loop_B.PitchampGainPreCompensation = 0.0;
    q_heli_2d_open_loop_B.SignalGeneratorYawV = 0.0;
    q_heli_2d_open_loop_B.AmplitudeYawV = 0.0;
    q_heli_2d_open_loop_B.Sum1 = 0.0;
    q_heli_2d_open_loop_B.YawAMPVoltageLimit = 0.0;
    q_heli_2d_open_loop_B.YawampGainPreCompensation = 0.0;
    q_heli_2d_open_loop_B.EncoderInput = 0.0;
    q_heli_2d_open_loop_B.EncoderInput1 = 0.0;
    q_heli_2d_open_loop_B.EncoderResolutionPitch = 0.0;
    q_heli_2d_open_loop_B.Bias = 0.0;
    q_heli_2d_open_loop_B.DerivativeFilterPitch = 0.0;
    q_heli_2d_open_loop_B.DerivativeFilterYaw = 0.0;
    q_heli_2d_open_loop_B.EncoderResolutionYaw = 0.0;
    q_heli_2d_open_loop_B.Gain[0] = 0.0;
    q_heli_2d_open_loop_B.Gain[1] = 0.0;
    q_heli_2d_open_loop_B.Gain_m[0] = 0.0;
    q_heli_2d_open_loop_B.Gain_m[1] = 0.0;
    q_heli_2d_open_loop_B.Gain_m[2] = 0.0;
    q_heli_2d_open_loop_B.Gain_m[3] = 0.0;
    q_heli_2d_open_loop_B.Gain_l[0] = 0.0;
    q_heli_2d_open_loop_B.Gain_l[1] = 0.0;
    q_heli_2d_open_loop_B.Gain_l[2] = 0.0;
    q_heli_2d_open_loop_B.Gain_l[3] = 0.0;
    q_heli_2d_open_loop_B.NoVm_sim = 0.0;
  }

  /* parameters */
  q_heli_2d_open_loop_M->defaultParam = ((real_T *)&q_heli_2d_open_loop_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &q_heli_2d_open_loop_X;
    q_heli_2d_open_loop_M->contStates = (x);
    (void) memset((void *)&q_heli_2d_open_loop_X, 0,
                  sizeof(X_q_heli_2d_open_loop_T));
  }

  /* states (dwork) */
  q_heli_2d_open_loop_M->dwork = ((void *) &q_heli_2d_open_loop_DW);
  (void) memset((void *)&q_heli_2d_open_loop_DW, 0,
                sizeof(DW_q_heli_2d_open_loop_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_heli_2d_open_loop_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_heli_2d_open_loop_M->Sizes.numContStates = (4);/* Number of continuous states */
  q_heli_2d_open_loop_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  q_heli_2d_open_loop_M->Sizes.numY = (0);/* Number of model outputs */
  q_heli_2d_open_loop_M->Sizes.numU = (0);/* Number of model inputs */
  q_heli_2d_open_loop_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_heli_2d_open_loop_M->Sizes.numSampTimes = (2);/* Number of sample times */
  q_heli_2d_open_loop_M->Sizes.numBlocks = (33);/* Number of blocks */
  q_heli_2d_open_loop_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  q_heli_2d_open_loop_M->Sizes.numBlockPrms = (54);/* Sum of parameter "widths" */
  return q_heli_2d_open_loop_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
