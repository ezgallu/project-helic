/*
 * ukupni_model.h
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

#ifndef RTW_HEADER_ukupni_model_h_
#define RTW_HEADER_ukupni_model_h_
#include <math.h>
#include <string.h>
#ifndef ukupni_model_COMMON_INCLUDES_
# define ukupni_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* ukupni_model_COMMON_INCLUDES_ */

#include "ukupni_model_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ukupni_model_rtModel           RT_MODEL_ukupni_model_T

/* Block signals (auto storage) */
typedef struct {
  real_T SliderGain;                   /* '<S10>/Slider Gain' */
  real_T EncoderResolutionPitch;       /* '<S5>/Encoder Resolution: Pitch ' */
  real_T Bias;                         /* '<S5>/Bias' */
  real_T EncoderResolutionYaw;         /* '<S5>/Encoder Resolution: Yaw' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T Gain1;                        /* '<S5>/Gain1' */
  real_T Sum;                          /* '<S7>/Sum' */
  real_T Sum_f;                        /* '<S9>/Sum' */
  real_T Gain_a[2];                    /* '<S14>/Gain' */
  real_T Gain_d[4];                    /* '<S15>/Gain' */
  real_T theta_dot;                    /* '<S17>/theta_dot' */
  real_T psi_dot;                      /* '<S17>/psi_dot' */
  real_T Gain_k[4];                    /* '<S13>/Gain' */
  real_T PitchAMPVoltageLimit;         /* '<S17>/Pitch AMP Voltage Limit' */
  real_T YawAMPVoltageLimit;           /* '<S17>/Yaw AMP Voltage Limit' */
  real_T Sum_o;                        /* '<S19>/Sum' */
  real_T Sum_j;                        /* '<S20>/Sum' */
  real_T DividebyInertia;              /* '<S17>/Divide by Inertia' */
  real_T PitchInertia;                 /* '<S17>/Pitch Inertia' */
} B_ukupni_model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  void *EncoderInput_PWORK;            /* '<S5>/Encoder Input' */
  void *EncoderInput1_PWORK;           /* '<S5>/Encoder Input1' */
  void *AnalogOutput_PWORK;            /* '<S5>/Analog Output' */
  void *AnalogOutput1_PWORK;           /* '<S5>/Analog Output1' */
  struct {
    void *LoggedData;
  } psideg_PWORK;                      /* '<S3>/psi (deg)' */

  struct {
    void *LoggedData;
  } psi_dotdegs_PWORK;                 /* '<S3>/psi_dot (deg//s)' */

  struct {
    void *LoggedData;
  } thetadeg_PWORK;                    /* '<S3>/theta (deg)' */

  struct {
    void *LoggedData;
  } theta_dotdegs_PWORK;               /* '<S3>/theta_dot (deg//s)' */

  struct {
    void *LoggedData;
  } Vm_actualV_PWORK;                  /* '<S3>/Vm_actual (V)' */

  struct {
    void *LoggedData;
  } Vm_simV_PWORK;                     /* '<S3>/Vm_sim (V)' */
} DW_ukupni_model_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T DerivativeFilterPitch_CSTATE[2];/* '<S5>/Derivative Filter: Pitch' */
  real_T DerivativeFilterYaw_CSTATE[2];/* '<S5>/Derivative Filter: Yaw' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S9>/Integrator' */
  real_T theta_CSTATE;                 /* '<S17>/theta' */
  real_T psi_CSTATE;                   /* '<S17>/psi' */
  real_T theta_dot_CSTATE;             /* '<S17>/theta_dot' */
  real_T psi_dot_CSTATE;               /* '<S17>/psi_dot' */
  real_T Integrator_CSTATE_j;          /* '<S19>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S20>/Integrator' */
} X_ukupni_model_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T DerivativeFilterPitch_CSTATE[2];/* '<S5>/Derivative Filter: Pitch' */
  real_T DerivativeFilterYaw_CSTATE[2];/* '<S5>/Derivative Filter: Yaw' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S9>/Integrator' */
  real_T theta_CSTATE;                 /* '<S17>/theta' */
  real_T psi_CSTATE;                   /* '<S17>/psi' */
  real_T theta_dot_CSTATE;             /* '<S17>/theta_dot' */
  real_T psi_dot_CSTATE;               /* '<S17>/psi_dot' */
  real_T Integrator_CSTATE_j;          /* '<S19>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S20>/Integrator' */
} XDot_ukupni_model_T;

/* State disabled  */
typedef struct {
  boolean_T DerivativeFilterPitch_CSTATE[2];/* '<S5>/Derivative Filter: Pitch' */
  boolean_T DerivativeFilterYaw_CSTATE[2];/* '<S5>/Derivative Filter: Yaw' */
  boolean_T Integrator_CSTATE;         /* '<S7>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S9>/Integrator' */
  boolean_T theta_CSTATE;              /* '<S17>/theta' */
  boolean_T psi_CSTATE;                /* '<S17>/psi' */
  boolean_T theta_dot_CSTATE;          /* '<S17>/theta_dot' */
  boolean_T psi_dot_CSTATE;            /* '<S17>/psi_dot' */
  boolean_T Integrator_CSTATE_j;       /* '<S19>/Integrator' */
  boolean_T Integrator_CSTATE_o;       /* '<S20>/Integrator' */
} XDis_ukupni_model_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ukupni_model_B
#define BlockIO                        B_ukupni_model_T
#define rtX                            ukupni_model_X
#define ContinuousStates               X_ukupni_model_T
#define rtXdot                         ukupni_model_XDot
#define StateDerivatives               XDot_ukupni_model_T
#define tXdis                          ukupni_model_XDis
#define StateDisabled                  XDis_ukupni_model_T
#define rtP                            ukupni_model_P
#define Parameters                     P_ukupni_model_T
#define rtDWork                        ukupni_model_DW
#define D_Work                         DW_ukupni_model_T

/* Parameters (auto storage) */
struct P_ukupni_model_T_ {
  real_T B_p;                          /* Variable: B_p
                                        * Referenced by: '<S17>/Pitch Viscous Damping'
                                        */
  real_T B_y;                          /* Variable: B_y
                                        * Referenced by: '<S17>/Yaw Viscous Damping'
                                        */
  real_T J_eq_y;                       /* Variable: J_eq_y
                                        * Referenced by: '<S23>/Yaw Inertia'
                                        */
  real_T J_p;                          /* Variable: J_p
                                        * Referenced by: '<S17>/Pitch Inertia'
                                        */
  real_T K_EC_P;                       /* Variable: K_EC_P
                                        * Referenced by: '<S5>/Encoder Resolution: Pitch '
                                        */
  real_T K_EC_Y;                       /* Variable: K_EC_Y
                                        * Referenced by: '<S5>/Encoder Resolution: Yaw'
                                        */
  real_T K_pp;                         /* Variable: K_pp
                                        * Referenced by:
                                        *   '<S17>/Thrust torque from  Pitch Motor'
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        */
  real_T K_py;                         /* Variable: K_py
                                        * Referenced by: '<S17>/Cross-torque acting on Pitch  from Yaw Motor'
                                        */
  real_T K_yp;                         /* Variable: K_yp
                                        * Referenced by: '<S17>/Cross-torque acting on Yaw  from Pitch Motor'
                                        */
  real_T K_yy;                         /* Variable: K_yy
                                        * Referenced by: '<S17>/Thrust torque from  Yaw Motor'
                                        */
  real_T Tr_p;                         /* Variable: Tr_p
                                        * Referenced by:
                                        *   '<S7>/Pitch Reset Time'
                                        *   '<S19>/Pitch Reset Time'
                                        */
  real_T Tr_y;                         /* Variable: Tr_y
                                        * Referenced by:
                                        *   '<S9>/Yaw Reset Time'
                                        *   '<S20>/Yaw Reset Time'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        *   '<S21>/m*g*lcm'
                                        */
  real_T l_cm;                         /* Variable: l_cm
                                        * Referenced by:
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        *   '<S21>/m*g*lcm'
                                        */
  real_T m_heli;                       /* Variable: m_heli
                                        * Referenced by:
                                        *   '<S8>/Feed-forward Pitch Gain'
                                        *   '<S18>/Feed-forward Pitch Gain'
                                        *   '<S21>/m*g*lcm'
                                        *   '<S22>/m*lcm^2'
                                        *   '<S23>/m_heli*l_cm^2'
                                        *   '<S24>/2*m*lcm^2'
                                        */
  real_T max_u;                        /* Variable: max_u
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
  real_T theta_0;                      /* Variable: theta_0
                                        * Referenced by:
                                        *   '<S5>/Bias'
                                        *   '<S17>/theta'
                                        */
  real_T AnalogOutput_FinalValue;      /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  real_T AnalogOutput1_FinalValue;     /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  real_T AnalogOutput_InitialValue;    /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  real_T AnalogOutput1_InitialValue;   /* Mask Parameter: AnalogOutput1_InitialValue
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  real_T EncoderInput_InputFilter;     /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  real_T EncoderInput1_InputFilter;    /* Mask Parameter: EncoderInput1_InputFilter
                                        * Referenced by: '<S5>/Encoder Input1'
                                        */
  real_T EncoderInput_MaxMissedTicks;  /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  real_T EncoderInput1_MaxMissedTicks; /* Mask Parameter: EncoderInput1_MaxMissedTicks
                                        * Referenced by: '<S5>/Encoder Input1'
                                        */
  real_T AnalogOutput_MaxMissedTicks;  /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  real_T AnalogOutput1_MaxMissedTicks; /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  real_T EncoderInput_YieldWhenWaiting;/* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  real_T EncoderInput1_YieldWhenWaiting;/* Mask Parameter: EncoderInput1_YieldWhenWaiting
                                         * Referenced by: '<S5>/Encoder Input1'
                                         */
  real_T AnalogOutput_YieldWhenWaiting;/* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  real_T AnalogOutput1_YieldWhenWaiting;/* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                         * Referenced by: '<S5>/Analog Output1'
                                         */
  real_T ConstantPitchdeg_gain;        /* Mask Parameter: ConstantPitchdeg_gain
                                        * Referenced by: '<S10>/Slider Gain'
                                        */
  int32_T EncoderInput_Channels;       /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<S5>/Encoder Input'
                                        */
  int32_T EncoderInput1_Channels;      /* Mask Parameter: EncoderInput1_Channels
                                        * Referenced by: '<S5>/Encoder Input1'
                                        */
  int32_T AnalogOutput_Channels;       /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  int32_T AnalogOutput1_Channels;      /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  int32_T AnalogOutput_RangeMode;      /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  int32_T AnalogOutput1_RangeMode;     /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  int32_T AnalogOutput_VoltRange;      /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S5>/Analog Output'
                                        */
  int32_T AnalogOutput1_VoltRange;     /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S5>/Analog Output1'
                                        */
  real_T SignalGeneratorPitch_Amplitude;/* Expression: 15
                                         * Referenced by: '<S2>/Signal Generator: Pitch'
                                         */
  real_T SignalGeneratorPitch_Frequency;/* Expression: 0.05
                                         * Referenced by: '<S2>/Signal Generator: Pitch'
                                         */
  real_T AmplitudePitchdeg_Gain;       /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Pitch (deg)'
                                        */
  real_T Constant_Value;               /* Expression: 20
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T DerivativeFilterPitch_A[2];   /* Computed Parameter: DerivativeFilterPitch_A
                                        * Referenced by: '<S5>/Derivative Filter: Pitch'
                                        */
  real_T DerivativeFilterPitch_C[2];   /* Computed Parameter: DerivativeFilterPitch_C
                                        * Referenced by: '<S5>/Derivative Filter: Pitch'
                                        */
  real_T DerivativeFilterYaw_A[2];     /* Computed Parameter: DerivativeFilterYaw_A
                                        * Referenced by: '<S5>/Derivative Filter: Yaw'
                                        */
  real_T DerivativeFilterYaw_C[2];     /* Computed Parameter: DerivativeFilterYaw_C
                                        * Referenced by: '<S5>/Derivative Filter: Yaw'
                                        */
  real_T X_Gain[16];                   /* Expression: -eye(4,4)
                                        * Referenced by: '<S6>/-X'
                                        */
  real_T SignalGeneratorYaw_Amplitude; /* Expression: 30
                                        * Referenced by: '<S2>/Signal Generator: Yaw'
                                        */
  real_T SignalGeneratorYaw_Frequency; /* Expression: 0.05
                                        * Referenced by: '<S2>/Signal Generator: Yaw'
                                        */
  real_T AmplitudeYawdeg_Gain;         /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Yaw (deg)'
                                        */
  real_T ConstantYawdeg_Value;         /* Expression: -10
                                        * Referenced by: '<S2>/Constant: Yaw (deg)'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T ControlGainK_Gain[8];         /* Expression: K_i(:,1:4)
                                        * Referenced by: '<S6>/Control Gain: K'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T PitchIntegralControlGainK15_Gain;/* Expression: K_i(1,5)
                                           * Referenced by: '<S7>/Pitch Integral Control Gain: K(1,5)'
                                           */
  real_T YawCrossIntegralControlGainK16_Gain;/* Expression: K_i(1,6)
                                              * Referenced by: '<S7>/Yaw Cross-Integral Control Gain: K(1,6)'
                                              */
  real_T YawIntegralControlGainK26_Gain;/* Expression: K_i(2,6)
                                         * Referenced by: '<S9>/Yaw Integral Control Gain: K(2,6)'
                                         */
  real_T PitchCrossIntegralControlGainK25_Gain;/* Expression: K_i(2,5)
                                                * Referenced by: '<S9>/Pitch Cross-Integral Control Gain: K(2,5)'
                                                */
  real_T Gain_Gain_i;                  /* Expression: 180/pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T theta_UpperSat;               /* Expression: 60*pi/180
                                        * Referenced by: '<S17>/theta'
                                        */
  real_T theta_LowerSat;               /* Expression: -60*pi/180
                                        * Referenced by: '<S17>/theta'
                                        */
  real_T psi_IC;                       /* Expression: 0
                                        * Referenced by: '<S17>/psi'
                                        */
  real_T theta_dot_IC;                 /* Expression: 0
                                        * Referenced by: '<S17>/theta_dot'
                                        */
  real_T psi_dot_IC;                   /* Expression: 0
                                        * Referenced by: '<S17>/psi_dot'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T X_Gain_o[16];                 /* Expression: -eye(4,4)
                                        * Referenced by: '<S16>/-X'
                                        */
  real_T ControlGainK_Gain_k[8];       /* Expression: K_i(:,1:4)
                                        * Referenced by: '<S16>/Control Gain: K'
                                        */
  real_T Integrator_IC_o;              /* Expression: 0
                                        * Referenced by: '<S19>/Integrator'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T PitchIntegralControlGainK15_Gain_b;/* Expression: K_i(1,5)
                                             * Referenced by: '<S19>/Pitch Integral Control Gain: K(1,5)'
                                             */
  real_T YawCrossIntegralControlGainK16_Gain_o;/* Expression: K_i(1,6)
                                                * Referenced by: '<S19>/Yaw Cross-Integral Control Gain: K(1,6)'
                                                */
  real_T YawIntegralControlGainK26_Gain_g;/* Expression: K_i(2,6)
                                           * Referenced by: '<S20>/Yaw Integral Control Gain: K(2,6)'
                                           */
  real_T PitchCrossIntegralControlGainK25_Gain_p;/* Expression: K_i(2,5)
                                                  * Referenced by: '<S20>/Pitch Cross-Integral Control Gain: K(2,5)'
                                                  */
};

/* Real-time Model Data Structure */
struct tag_RTM_ukupni_model_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ukupni_model_T ukupni_model_P;

/* Block signals (auto storage) */
extern B_ukupni_model_T ukupni_model_B;

/* Continuous states (auto storage) */
extern X_ukupni_model_T ukupni_model_X;

/* Block states (auto storage) */
extern DW_ukupni_model_T ukupni_model_DW;

/* Model entry point functions */
extern void ukupni_model_initialize(void);
extern void ukupni_model_output(void);
extern void ukupni_model_update(void);
extern void ukupni_model_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ukupni_model_rtModel *ukupni_model(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ukupni_model_T *const ukupni_model_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ukupni_model'
 * '<S1>'   : 'ukupni_model/2 DOF Helicopter - Closed-loop Actual System'
 * '<S2>'   : 'ukupni_model/Referentni kut'
 * '<S3>'   : 'ukupni_model/Scopes'
 * '<S4>'   : 'ukupni_model/simulacija'
 * '<S5>'   : 'ukupni_model/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI'
 * '<S6>'   : 'ukupni_model/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller'
 * '<S7>'   : 'ukupni_model/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller/Pitch Integral Antiwidup'
 * '<S8>'   : 'ukupni_model/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller/Pitch feed-forward controller'
 * '<S9>'   : 'ukupni_model/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller/Yaw Integral Antiwidup'
 * '<S10>'  : 'ukupni_model/Referentni kut/Constant: Pitch (deg)'
 * '<S11>'  : 'ukupni_model/Referentni kut/Pitch: deg to rad'
 * '<S12>'  : 'ukupni_model/Referentni kut/Yaw: deg to rad'
 * '<S13>'  : 'ukupni_model/Scopes/Radians to Degree - Sim States'
 * '<S14>'  : 'ukupni_model/Scopes/Radians to Degrees - Des. States'
 * '<S15>'  : 'ukupni_model/Scopes/Radians to Degrees - Meas. States'
 * '<S16>'  : 'ukupni_model/simulacija/kontroler'
 * '<S17>'  : 'ukupni_model/simulacija/model'
 * '<S18>'  : 'ukupni_model/simulacija/kontroler/Pitch feed-forward controller'
 * '<S19>'  : 'ukupni_model/simulacija/kontroler/p_antiwindup'
 * '<S20>'  : 'ukupni_model/simulacija/kontroler/y_antiwindup'
 * '<S21>'  : 'ukupni_model/simulacija/model/Gravitational Torque'
 * '<S22>'  : 'ukupni_model/simulacija/model/Pitch Position Dependent Torque'
 * '<S23>'  : 'ukupni_model/simulacija/model/Yaw Inertia'
 * '<S24>'  : 'ukupni_model/simulacija/model/Yaw Position Dependent Torque'
 */
#endif                                 /* RTW_HEADER_ukupni_model_h_ */
