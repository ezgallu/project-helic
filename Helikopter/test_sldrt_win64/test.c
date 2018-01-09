/*
 * test.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "test".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Thu May 11 16:55:10 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"
#include "test_dt.h"

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
B_test_T test_B;

/* Block states (auto storage) */
DW_test_T test_DW;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;

/* Model output function */
void test_output(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) test_P.AnalogOutput_RangeMode;
      parm.rangeidx = test_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &test_P.AnalogOutput_Channels,
                     &test_P.Constant_Value, &parm);
    }
  }

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = test_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &test_P.EncoderInput_Channels,
                   &test_B.EncoderInput, &parm);
  }

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = test_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &test_P.EncoderInput1_Channels,
                   &test_B.EncoderInput1, &parm);
  }
}

/* Model update function */
void test_update(void)
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
  if (!(++test_M->Timing.clockTick0)) {
    ++test_M->Timing.clockTickH0;
  }

  test_M->Timing.t[0] = test_M->Timing.clockTick0 * test_M->Timing.stepSize0 +
    test_M->Timing.clockTickH0 * test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void test_initialize(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) test_P.AnalogOutput_RangeMode;
      parm.rangeidx = test_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &test_P.AnalogOutput_Channels,
                     &test_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = test_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &test_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = test_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &test_P.EncoderInput1_Channels,
                   NULL, &parm);
  }
}

/* Model terminate function */
void test_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) test_P.AnalogOutput_RangeMode;
      parm.rangeidx = test_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &test_P.AnalogOutput_Channels,
                     &test_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  test_update();
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
  test_initialize();
}

void MdlTerminate(void)
{
  test_terminate();
}

/* Registration function */
RT_MODEL_test_T *test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  test_P.EncoderInput_InputFilter = rtInf;
  test_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    test_M->Timing.sampleTimes = (&test_M->Timing.sampleTimesArray[0]);
    test_M->Timing.offsetTimes = (&test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    test_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    test_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(test_M, &test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(test_M, 12.0);
  test_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  test_M->Sizes.checksums[0] = (3916604072U);
  test_M->Sizes.checksums[1] = (583887965U);
  test_M->Sizes.checksums[2] = (333564596U);
  test_M->Sizes.checksums[3] = (2865115736U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_M->extModeInfo,
      &test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_M->extModeInfo, test_M->Sizes.checksums);
    rteiSetTPtr(test_M->extModeInfo, rtmGetTPtr(test_M));
  }

  test_M->solverInfoPtr = (&test_M->solverInfo);
  test_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&test_M->solverInfo, 0.001);
  rtsiSetSolverMode(&test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  test_M->blockIO = ((void *) &test_B);
  (void) memset(((void *) &test_B), 0,
                sizeof(B_test_T));

  /* parameters */
  test_M->defaultParam = ((real_T *)&test_P);

  /* states (dwork) */
  test_M->dwork = ((void *) &test_DW);
  (void) memset((void *)&test_DW, 0,
                sizeof(DW_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  test_M->Sizes.numContStates = (0);   /* Number of continuous states */
  test_M->Sizes.numY = (0);            /* Number of model outputs */
  test_M->Sizes.numU = (0);            /* Number of model inputs */
  test_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  test_M->Sizes.numSampTimes = (1);    /* Number of sample times */
  test_M->Sizes.numBlocks = (6);       /* Number of blocks */
  test_M->Sizes.numBlockIO = (2);      /* Number of block outputs */
  test_M->Sizes.numBlockPrms = (16);   /* Sum of parameter "widths" */
  return test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
