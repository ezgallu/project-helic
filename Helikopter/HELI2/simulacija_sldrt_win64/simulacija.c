/*
 * simulacija.c
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
#include "simulacija_dt.h"

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
B_simulacija_T simulacija_B;

/* Block states (auto storage) */
DW_simulacija_T simulacija_DW;

/* Real-time model */
RT_MODEL_simulacija_T simulacija_M_;
RT_MODEL_simulacija_T *const simulacija_M = &simulacija_M_;

/* Model output function */
void simulacija_output(void)
{
  real_T currentTime;
  real_T currentTime_0;
  real_T currentTime_1;
  real_T u0;

  /* Step: '<Root>/Step' */
  currentTime = simulacija_M->Timing.t[0];

  /* Step: '<S1>/Step' */
  currentTime_0 = simulacija_M->Timing.t[0];

  /* Step: '<Root>/Step1' */
  currentTime_1 = simulacija_M->Timing.t[0];

  /* Step: '<S1>/Step' */
  if (currentTime_0 < simulacija_P.Ramp_start) {
    currentTime_0 = simulacija_P.Step_Y0_j;
  } else {
    currentTime_0 = simulacija_P.Ramp_slope;
  }

  /* Sum: '<S1>/Output' incorporates:
   *  Clock: '<S1>/Clock'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Sum'
   */
  u0 = (simulacija_M->Timing.t[0] - simulacija_P.Ramp_start) * currentTime_0 +
    simulacija_P.Ramp_X0;

  /* Step: '<Root>/Step' */
  if (currentTime < simulacija_P.Step_Time) {
    currentTime = simulacija_P.Step_Y0;
  } else {
    currentTime = simulacija_P.Step_YFinal;
  }

  /* Saturate: '<Root>/Saturation1' */
  if (u0 > simulacija_P.Saturation1_UpperSat) {
    u0 = simulacija_P.Saturation1_UpperSat;
  } else {
    if (u0 < simulacija_P.Saturation1_LowerSat) {
      u0 = simulacija_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Step: '<Root>/Step1' */
  if (currentTime_1 < simulacija_P.Step1_Time) {
    currentTime_0 = simulacija_P.Step1_Y0;
  } else {
    currentTime_0 = simulacija_P.Step1_YFinal;
  }

  /* Sum: '<Root>/Sum' */
  u0 = (currentTime + u0) + currentTime_0;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > simulacija_P.Saturation_UpperSat) {
    simulacija_B.Saturation = simulacija_P.Saturation_UpperSat;
  } else if (u0 < simulacija_P.Saturation_LowerSat) {
    simulacija_B.Saturation = simulacija_P.Saturation_LowerSat;
  } else {
    simulacija_B.Saturation = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) simulacija_P.AnalogOutput_RangeMode;
      parm.rangeidx = simulacija_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &simulacija_P.AnalogOutput_Channels,
                     &simulacija_B.Saturation, &parm);
    }
  }

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = simulacija_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &simulacija_P.EncoderInput_Channels,
                   &simulacija_B.EncoderInput, &parm);
  }
}

/* Model update function */
void simulacija_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++simulacija_M->Timing.clockTick0)) {
    ++simulacija_M->Timing.clockTickH0;
  }

  simulacija_M->Timing.t[0] = simulacija_M->Timing.clockTick0 *
    simulacija_M->Timing.stepSize0 + simulacija_M->Timing.clockTickH0 *
    simulacija_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++simulacija_M->Timing.clockTick1)) {
      ++simulacija_M->Timing.clockTickH1;
    }

    simulacija_M->Timing.t[1] = simulacija_M->Timing.clockTick1 *
      simulacija_M->Timing.stepSize1 + simulacija_M->Timing.clockTickH1 *
      simulacija_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void simulacija_initialize(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) simulacija_P.AnalogOutput_RangeMode;
      parm.rangeidx = simulacija_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &simulacija_P.AnalogOutput_Channels,
                     &simulacija_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = simulacija_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &simulacija_P.EncoderInput_Channels, NULL, &parm);
  }
}

/* Model terminate function */
void simulacija_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) simulacija_P.AnalogOutput_RangeMode;
      parm.rangeidx = simulacija_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &simulacija_P.AnalogOutput_Channels,
                     &simulacija_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  simulacija_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  simulacija_update();
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
  simulacija_initialize();
}

void MdlTerminate(void)
{
  simulacija_terminate();
}

/* Registration function */
RT_MODEL_simulacija_T *simulacija(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  simulacija_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)simulacija_M, 0,
                sizeof(RT_MODEL_simulacija_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&simulacija_M->solverInfo,
                          &simulacija_M->Timing.simTimeStep);
    rtsiSetTPtr(&simulacija_M->solverInfo, &rtmGetTPtr(simulacija_M));
    rtsiSetStepSizePtr(&simulacija_M->solverInfo,
                       &simulacija_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&simulacija_M->solverInfo, (&rtmGetErrorStatus
      (simulacija_M)));
    rtsiSetRTModelPtr(&simulacija_M->solverInfo, simulacija_M);
  }

  rtsiSetSimTimeStep(&simulacija_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&simulacija_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = simulacija_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    simulacija_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    simulacija_M->Timing.sampleTimes = (&simulacija_M->Timing.sampleTimesArray[0]);
    simulacija_M->Timing.offsetTimes = (&simulacija_M->Timing.offsetTimesArray[0]);

    /* task periods */
    simulacija_M->Timing.sampleTimes[0] = (0.0);
    simulacija_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    simulacija_M->Timing.offsetTimes[0] = (0.0);
    simulacija_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(simulacija_M, &simulacija_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = simulacija_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    simulacija_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(simulacija_M, 20.0);
  simulacija_M->Timing.stepSize0 = 0.001;
  simulacija_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  simulacija_M->Sizes.checksums[0] = (3719142164U);
  simulacija_M->Sizes.checksums[1] = (784034594U);
  simulacija_M->Sizes.checksums[2] = (1988390985U);
  simulacija_M->Sizes.checksums[3] = (3715304742U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    simulacija_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(simulacija_M->extModeInfo,
      &simulacija_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(simulacija_M->extModeInfo, simulacija_M->Sizes.checksums);
    rteiSetTPtr(simulacija_M->extModeInfo, rtmGetTPtr(simulacija_M));
  }

  simulacija_M->solverInfoPtr = (&simulacija_M->solverInfo);
  simulacija_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&simulacija_M->solverInfo, 0.001);
  rtsiSetSolverMode(&simulacija_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  simulacija_M->blockIO = ((void *) &simulacija_B);
  (void) memset(((void *) &simulacija_B), 0,
                sizeof(B_simulacija_T));

  /* parameters */
  simulacija_M->defaultParam = ((real_T *)&simulacija_P);

  /* states (dwork) */
  simulacija_M->dwork = ((void *) &simulacija_DW);
  (void) memset((void *)&simulacija_DW, 0,
                sizeof(DW_simulacija_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    simulacija_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  simulacija_M->Sizes.numContStates = (0);/* Number of continuous states */
  simulacija_M->Sizes.numY = (0);      /* Number of model outputs */
  simulacija_M->Sizes.numU = (0);      /* Number of model inputs */
  simulacija_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  simulacija_M->Sizes.numSampTimes = (2);/* Number of sample times */
  simulacija_M->Sizes.numBlocks = (16);/* Number of blocks */
  simulacija_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  simulacija_M->Sizes.numBlockPrms = (25);/* Sum of parameter "widths" */
  return simulacija_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
