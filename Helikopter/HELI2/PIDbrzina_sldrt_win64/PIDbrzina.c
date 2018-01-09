/*
 * PIDbrzina.c
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
#include "PIDbrzina_dt.h"

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
B_PIDbrzina_T PIDbrzina_B;

/* Continuous states */
X_PIDbrzina_T PIDbrzina_X;

/* Block states (auto storage) */
DW_PIDbrzina_T PIDbrzina_DW;

/* Real-time model */
RT_MODEL_PIDbrzina_T PIDbrzina_M_;
RT_MODEL_PIDbrzina_T *const PIDbrzina_M = &PIDbrzina_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PIDbrzina_M->Timing.TaskCounters.TID[2])++;
  if ((PIDbrzina_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    PIDbrzina_M->Timing.TaskCounters.TID[2] = 0;
  }

  PIDbrzina_M->Timing.sampleHits[2] = (PIDbrzina_M->Timing.TaskCounters.TID[2] ==
    0);
}

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
  PIDbrzina_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PIDbrzina_output();
  PIDbrzina_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PIDbrzina_output();
  PIDbrzina_derivatives();

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
void PIDbrzina_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput;
  real_T rtb_EncoderInput;
  real_T rtb_Sum1;
  real_T u0;
  if (rtmIsMajorTimeStep(PIDbrzina_M)) {
    /* set solver stop time */
    if (!(PIDbrzina_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PIDbrzina_M->solverInfo,
                            ((PIDbrzina_M->Timing.clockTickH0 + 1) *
        PIDbrzina_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PIDbrzina_M->solverInfo,
                            ((PIDbrzina_M->Timing.clockTick0 + 1) *
        PIDbrzina_M->Timing.stepSize0 + PIDbrzina_M->Timing.clockTickH0 *
        PIDbrzina_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PIDbrzina_M)) {
    PIDbrzina_M->Timing.t[0] = rtsiGetT(&PIDbrzina_M->solverInfo);
  }

  /* Gain: '<S2>/Gain' incorporates:
   *  TransferFcn: '<S2>/Transfer Fcn'
   */
  PIDbrzina_B.Gain = PIDbrzina_P.TransferFcn_C * PIDbrzina_X.TransferFcn_CSTATE *
    PIDbrzina_P.Gain_Gain;
  if (rtmIsMajorTimeStep(PIDbrzina_M) &&
      PIDbrzina_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function Block: <S3>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PIDbrzina_P.AnalogInput_RangeMode;
      parm.rangeidx = PIDbrzina_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &PIDbrzina_P.AnalogInput_Channels, &rtb_AnalogInput, &parm);
    }

    /* S-Function Block: <S3>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = PIDbrzina_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &PIDbrzina_P.EncoderInput_Channels, &rtb_EncoderInput,
                     &parm);
    }

    /* Gain: '<S3>/Gain4' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain3'
     */
    PIDbrzina_B.Gain4 = PIDbrzina_P.Gain1_Gain * rtb_AnalogInput *
      PIDbrzina_P.Gain3_Gain * PIDbrzina_P.Gain4_Gain;

    /* Gain: '<S3>/Gain2' */
    PIDbrzina_B.Gain2 = PIDbrzina_P.Gain2_Gain * rtb_EncoderInput;
  }

  /* TransferFcn: '<S3>/Transfer Fcn1' */
  PIDbrzina_B.TransferFcn1 = 0.0;
  PIDbrzina_B.TransferFcn1 += PIDbrzina_P.TransferFcn1_C *
    PIDbrzina_X.TransferFcn1_CSTATE;
  PIDbrzina_B.TransferFcn1 += PIDbrzina_P.TransferFcn1_D * PIDbrzina_B.Gain2;

  /* ManualSwitch: '<S3>/Manual Switch' */
  if (PIDbrzina_P.ManualSwitch_CurrentSetting == 1) {
    PIDbrzina_B.ManualSwitch = PIDbrzina_B.Gain4;
  } else {
    PIDbrzina_B.ManualSwitch = PIDbrzina_B.TransferFcn1;
  }

  /* End of ManualSwitch: '<S3>/Manual Switch' */

  /* Sum: '<Root>/Sum1' */
  rtb_Sum1 = PIDbrzina_B.Gain - PIDbrzina_B.ManualSwitch;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  PIDbrzina_B.FilterCoefficient = (PIDbrzina_P.PIDController_D * rtb_Sum1 -
    PIDbrzina_X.Filter_CSTATE) * PIDbrzina_P.PIDController_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Proportional Gain'
   *  Integrator: '<S1>/Integrator'
   */
  u0 = (PIDbrzina_P.PIDController_P * rtb_Sum1 + PIDbrzina_X.Integrator_CSTATE)
    + PIDbrzina_B.FilterCoefficient;

  /* Saturate: '<S3>/Saturation' */
  if (u0 > PIDbrzina_P.Saturation_UpperSat) {
    PIDbrzina_B.Saturation = PIDbrzina_P.Saturation_UpperSat;
  } else if (u0 < PIDbrzina_P.Saturation_LowerSat) {
    PIDbrzina_B.Saturation = PIDbrzina_P.Saturation_LowerSat;
  } else {
    PIDbrzina_B.Saturation = u0;
  }

  /* End of Saturate: '<S3>/Saturation' */
  if (rtmIsMajorTimeStep(PIDbrzina_M) &&
      PIDbrzina_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function Block: <S3>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) PIDbrzina_P.AnalogOutput_RangeMode;
        parm.rangeidx = PIDbrzina_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &PIDbrzina_P.AnalogOutput_Channels,
                       &PIDbrzina_B.Saturation, &parm);
      }
    }
  }

  if (rtmIsMajorTimeStep(PIDbrzina_M) &&
      PIDbrzina_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S1>/Integral Gain' */
  PIDbrzina_B.IntegralGain = PIDbrzina_P.PIDController_I * rtb_Sum1;

  /* SignalGenerator: '<S2>/Signal Generator' */
  rtb_Sum1 = PIDbrzina_P.SignalGenerator_Frequency * PIDbrzina_M->Timing.t[0];
  if (rtb_Sum1 - floor(rtb_Sum1) >= 0.5) {
    rtb_Sum1 = PIDbrzina_P.SignalGenerator_Amplitude;
  } else {
    rtb_Sum1 = -PIDbrzina_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<S2>/Signal Generator' */

  /* Sum: '<S2>/Sum2' incorporates:
   *  Constant: '<S2>/Constant'
   */
  PIDbrzina_B.Sum2 = rtb_Sum1 - PIDbrzina_P.Constant_Value;
}

/* Model update function */
void PIDbrzina_update(void)
{
  if (rtmIsMajorTimeStep(PIDbrzina_M)) {
    rt_ertODEUpdateContinuousStates(&PIDbrzina_M->solverInfo);
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
  if (!(++PIDbrzina_M->Timing.clockTick0)) {
    ++PIDbrzina_M->Timing.clockTickH0;
  }

  PIDbrzina_M->Timing.t[0] = rtsiGetSolverStopTime(&PIDbrzina_M->solverInfo);

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
    if (!(++PIDbrzina_M->Timing.clockTick1)) {
      ++PIDbrzina_M->Timing.clockTickH1;
    }

    PIDbrzina_M->Timing.t[1] = PIDbrzina_M->Timing.clockTick1 *
      PIDbrzina_M->Timing.stepSize1 + PIDbrzina_M->Timing.clockTickH1 *
      PIDbrzina_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(PIDbrzina_M) &&
      PIDbrzina_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PIDbrzina_M->Timing.clockTick2)) {
      ++PIDbrzina_M->Timing.clockTickH2;
    }

    PIDbrzina_M->Timing.t[2] = PIDbrzina_M->Timing.clockTick2 *
      PIDbrzina_M->Timing.stepSize2 + PIDbrzina_M->Timing.clockTickH2 *
      PIDbrzina_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void PIDbrzina_derivatives(void)
{
  XDot_PIDbrzina_T *_rtXdot;
  _rtXdot = ((XDot_PIDbrzina_T *) PIDbrzina_M->derivs);

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += PIDbrzina_P.TransferFcn_A *
    PIDbrzina_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += PIDbrzina_B.Sum2;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += PIDbrzina_P.TransferFcn1_A *
    PIDbrzina_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += PIDbrzina_B.Gain2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = PIDbrzina_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = PIDbrzina_B.FilterCoefficient;
}

/* Model initialize function */
void PIDbrzina_initialize(void)
{
  /* S-Function Block: <S3>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PIDbrzina_P.AnalogOutput_RangeMode;
      parm.rangeidx = PIDbrzina_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PIDbrzina_P.AnalogOutput_Channels,
                     &PIDbrzina_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn' */
  PIDbrzina_X.TransferFcn_CSTATE = 0.0;

  /* S-Function Block: <S3>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = PIDbrzina_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &PIDbrzina_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn1' */
  PIDbrzina_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  PIDbrzina_X.Integrator_CSTATE = PIDbrzina_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  PIDbrzina_X.Filter_CSTATE = PIDbrzina_P.Filter_IC;
}

/* Model terminate function */
void PIDbrzina_terminate(void)
{
  /* S-Function Block: <S3>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PIDbrzina_P.AnalogOutput_RangeMode;
      parm.rangeidx = PIDbrzina_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PIDbrzina_P.AnalogOutput_Channels,
                     &PIDbrzina_P.AnalogOutput_FinalValue, &parm);
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
  PIDbrzina_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PIDbrzina_update();
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
  PIDbrzina_initialize();
}

void MdlTerminate(void)
{
  PIDbrzina_terminate();
}

/* Registration function */
RT_MODEL_PIDbrzina_T *PIDbrzina(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  PIDbrzina_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)PIDbrzina_M, 0,
                sizeof(RT_MODEL_PIDbrzina_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PIDbrzina_M->solverInfo,
                          &PIDbrzina_M->Timing.simTimeStep);
    rtsiSetTPtr(&PIDbrzina_M->solverInfo, &rtmGetTPtr(PIDbrzina_M));
    rtsiSetStepSizePtr(&PIDbrzina_M->solverInfo, &PIDbrzina_M->Timing.stepSize0);
    rtsiSetdXPtr(&PIDbrzina_M->solverInfo, &PIDbrzina_M->derivs);
    rtsiSetContStatesPtr(&PIDbrzina_M->solverInfo, (real_T **)
                         &PIDbrzina_M->contStates);
    rtsiSetNumContStatesPtr(&PIDbrzina_M->solverInfo,
      &PIDbrzina_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PIDbrzina_M->solverInfo,
      &PIDbrzina_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PIDbrzina_M->solverInfo,
      &PIDbrzina_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PIDbrzina_M->solverInfo,
      &PIDbrzina_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PIDbrzina_M->solverInfo, (&rtmGetErrorStatus
      (PIDbrzina_M)));
    rtsiSetRTModelPtr(&PIDbrzina_M->solverInfo, PIDbrzina_M);
  }

  rtsiSetSimTimeStep(&PIDbrzina_M->solverInfo, MAJOR_TIME_STEP);
  PIDbrzina_M->intgData.y = PIDbrzina_M->odeY;
  PIDbrzina_M->intgData.f[0] = PIDbrzina_M->odeF[0];
  PIDbrzina_M->intgData.f[1] = PIDbrzina_M->odeF[1];
  PIDbrzina_M->intgData.f[2] = PIDbrzina_M->odeF[2];
  PIDbrzina_M->contStates = ((real_T *) &PIDbrzina_X);
  rtsiSetSolverData(&PIDbrzina_M->solverInfo, (void *)&PIDbrzina_M->intgData);
  rtsiSetSolverName(&PIDbrzina_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PIDbrzina_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    PIDbrzina_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PIDbrzina_M->Timing.sampleTimes = (&PIDbrzina_M->Timing.sampleTimesArray[0]);
    PIDbrzina_M->Timing.offsetTimes = (&PIDbrzina_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PIDbrzina_M->Timing.sampleTimes[0] = (0.0);
    PIDbrzina_M->Timing.sampleTimes[1] = (0.001);
    PIDbrzina_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    PIDbrzina_M->Timing.offsetTimes[0] = (0.0);
    PIDbrzina_M->Timing.offsetTimes[1] = (0.0);
    PIDbrzina_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(PIDbrzina_M, &PIDbrzina_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PIDbrzina_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    PIDbrzina_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PIDbrzina_M, 999.0);
  PIDbrzina_M->Timing.stepSize0 = 0.001;
  PIDbrzina_M->Timing.stepSize1 = 0.001;
  PIDbrzina_M->Timing.stepSize2 = 0.1;

  /* External mode info */
  PIDbrzina_M->Sizes.checksums[0] = (1145580649U);
  PIDbrzina_M->Sizes.checksums[1] = (1401541176U);
  PIDbrzina_M->Sizes.checksums[2] = (2077037059U);
  PIDbrzina_M->Sizes.checksums[3] = (985943983U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    PIDbrzina_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PIDbrzina_M->extModeInfo,
      &PIDbrzina_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PIDbrzina_M->extModeInfo, PIDbrzina_M->Sizes.checksums);
    rteiSetTPtr(PIDbrzina_M->extModeInfo, rtmGetTPtr(PIDbrzina_M));
  }

  PIDbrzina_M->solverInfoPtr = (&PIDbrzina_M->solverInfo);
  PIDbrzina_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PIDbrzina_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PIDbrzina_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PIDbrzina_M->blockIO = ((void *) &PIDbrzina_B);
  (void) memset(((void *) &PIDbrzina_B), 0,
                sizeof(B_PIDbrzina_T));

  /* parameters */
  PIDbrzina_M->defaultParam = ((real_T *)&PIDbrzina_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PIDbrzina_X;
    PIDbrzina_M->contStates = (x);
    (void) memset((void *)&PIDbrzina_X, 0,
                  sizeof(X_PIDbrzina_T));
  }

  /* states (dwork) */
  PIDbrzina_M->dwork = ((void *) &PIDbrzina_DW);
  (void) memset((void *)&PIDbrzina_DW, 0,
                sizeof(DW_PIDbrzina_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PIDbrzina_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PIDbrzina_M->Sizes.numContStates = (4);/* Number of continuous states */
  PIDbrzina_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  PIDbrzina_M->Sizes.numY = (0);       /* Number of model outputs */
  PIDbrzina_M->Sizes.numU = (0);       /* Number of model inputs */
  PIDbrzina_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PIDbrzina_M->Sizes.numSampTimes = (3);/* Number of sample times */
  PIDbrzina_M->Sizes.numBlocks = (27); /* Number of blocks */
  PIDbrzina_M->Sizes.numBlockIO = (9); /* Number of block outputs */
  PIDbrzina_M->Sizes.numBlockPrms = (38);/* Sum of parameter "widths" */
  return PIDbrzina_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
