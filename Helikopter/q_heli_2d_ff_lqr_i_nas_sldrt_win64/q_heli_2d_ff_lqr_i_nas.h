/*
 * q_heli_2d_ff_lqr_i_nas.h
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

#ifndef RTW_HEADER_q_heli_2d_ff_lqr_i_nas_h_
#define RTW_HEADER_q_heli_2d_ff_lqr_i_nas_h_
#include <math.h>
#include <string.h>
#ifndef q_heli_2d_ff_lqr_i_nas_COMMON_INCLUDES_
# define q_heli_2d_ff_lqr_i_nas_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* q_heli_2d_ff_lqr_i_nas_COMMON_INCLUDES_ */

#include "q_heli_2d_ff_lqr_i_nas_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
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
#define q_heli_2d_ff_lqr_i_nas_rtModel RT_MODEL_q_heli_2d_ff_lqr_i_nas_T

/* Block signals (auto storage) */
typedef struct {
  real_T SignalGeneratorPitchV;        /* '<S4>/Signal Generator: Pitch (V)' */
  real_T AmplitudePitchV;              /* '<S4>/Amplitude: Pitch (V)' */
  real_T Sum;                          /* '<S4>/Sum' */
  real_T ChoosePitchRelay;             /* '<S9>/Choose Pitch Relay' */
  real_T Add;                          /* '<S15>/Add' */
  real_T SignalGeneratorPitch;         /* '<S3>/Signal Generator: Pitch' */
  real_T AmplitudePitchdeg;            /* '<S3>/Amplitude: Pitch (deg)' */
  real_T SliderGain;                   /* '<S40>/Slider Gain' */
  real_T Sum_h;                        /* '<S3>/Sum' */
  real_T Gain1;                        /* '<S41>/Gain1' */
  real_T EncoderInput;                 /* '<S6>/Encoder Input' */
  real_T EncoderInput1;                /* '<S6>/Encoder Input1' */
  real_T EncoderResolutionPitch;       /* '<S6>/Encoder Resolution: Pitch ' */
  real_T Bias;                         /* '<S6>/Bias' */
  real_T EncoderResolutionYaw;         /* '<S6>/Encoder Resolution: Yaw' */
  real_T DerivativeFilterPitch;        /* '<S6>/Derivative Filter: Pitch' */
  real_T DerivativeFilterYaw;          /* '<S6>/Derivative Filter: Yaw' */
  real_T TmpSignalConversionAtXInport1[4];
  real_T X[4];                         /* '<S7>/-X' */
  real_T Sum2;                         /* '<S7>/Sum2' */
  real_T SignalGeneratorYaw;           /* '<S3>/Signal Generator: Yaw' */
  real_T AmplitudeYawdeg;              /* '<S3>/Amplitude: Yaw (deg)' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T Gain1_h;                      /* '<S42>/Gain1' */
  real_T Sum1_e;                       /* '<S7>/Sum1' */
  real_T TmpSignalConversionAtControlGainKInport1[4];
  real_T ControlGainK[2];              /* '<S7>/Control Gain: K' */
  real_T X_l[4];                       /* '<S8>/-X' */
  real_T Sum2_c;                       /* '<S8>/Sum2' */
  real_T Sum1_o;                       /* '<S8>/Sum1' */
  real_T TmpSignalConversionAtControlGainKInport1_b[4];
  real_T ControlGainK_l[2];            /* '<S8>/Control Gain: K' */
  real_T Integrator;                   /* '<S11>/Integrator' */
  real_T Saturate;                     /* '<S11>/Saturate' */
  real_T Memory;                       /* '<S15>/Memory' */
  real_T Switch;                       /* '<S15>/Switch' */
  real_T Pitchu_ol_pLQR;               /* '<S9>/Pitch: u_ol_p +LQR' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T PitchAMPVoltageLimit;         /* '<S6>/Pitch AMP Voltage Limit' */
  real_T PitchampGainPreCompensation;  /* '<S6>/Pitch amp Gain Pre-Compensation' */
  real_T SignalGeneratorYawV;          /* '<S4>/Signal Generator: Yaw (V)' */
  real_T AmplitudeYawV;                /* '<S4>/Amplitude: Yaw (V)' */
  real_T Sum1_p;                       /* '<S4>/Sum1' */
  real_T ChooseYawRelay;               /* '<S9>/Choose Yaw Relay' */
  real_T Add_m;                        /* '<S16>/Add' */
  real_T Integrator_b;                 /* '<S13>/Integrator' */
  real_T Saturate_c;                   /* '<S13>/Saturate' */
  real_T Memory_b;                     /* '<S16>/Memory' */
  real_T Switch_p;                     /* '<S16>/Switch' */
  real_T Yawu_ol_yLQR;                 /* '<S9>/Yaw: u_ol_y +LQR' */
  real_T YawAMPVoltageLimit;           /* '<S6>/Yaw AMP Voltage Limit' */
  real_T YawampGainPreCompensation;    /* '<S6>/Yaw amp Gain Pre-Compensation' */
  real_T PitchIntegralControlGainK15;  /* '<S11>/Pitch Integral Control Gain: K(1,5)' */
  real_T YawCrossIntegralControlGainK16;/* '<S11>/Yaw Cross-Integral Control Gain: K(1,6)' */
  real_T IntegralInputVs;              /* '<S11>/Integral Input  (V//s)' */
  real_T uv;                           /* '<S11>/u-v' */
  real_T PitchResetTime;               /* '<S11>/Pitch Reset Time' */
  real_T Sum_d;                        /* '<S11>/Sum' */
  real_T TrigonometricFunction;        /* '<S12>/Trigonometric Function' */
  real_T FeedforwardPitchGain;         /* '<S12>/Feed-forward Pitch Gain' */
  real_T YawIntegralControlGainK26;    /* '<S13>/Yaw Integral Control Gain: K(2,6)' */
  real_T PitchCrossIntegralControlGainK25;/* '<S13>/Pitch Cross-Integral Control Gain: K(2,5)' */
  real_T IntegralInputVs_m;            /* '<S13>/Integral Input  (V//s)' */
  real_T uv_i;                         /* '<S13>/u-v' */
  real_T YawResetTime;                 /* '<S13>/Yaw Reset Time' */
  real_T Sum_c;                        /* '<S13>/Sum' */
  real_T Gain_l[2];                    /* '<S44>/Gain' */
  real_T Gain_lx[4];                   /* '<S45>/Gain' */
  real_T theta;                        /* '<S23>/theta' */
  real_T psi;                          /* '<S23>/psi' */
  real_T theta_dot;                    /* '<S23>/theta_dot' */
  real_T psi_dot;                      /* '<S23>/psi_dot' */
  real_T TmpSignalConversionAtXInport1_i[4];
  real_T Gain_b[4];                    /* '<S43>/Gain' */
  real_T ChoosePitchRelay_d;           /* '<S24>/Choose Pitch Relay' */
  real_T Add_i;                        /* '<S34>/Add' */
  real_T X_c[4];                       /* '<S21>/-X' */
  real_T Sum2_a;                       /* '<S21>/Sum2' */
  real_T Sum1_g;                       /* '<S21>/Sum1' */
  real_T TmpSignalConversionAtControlGainKInport1_be[4];
  real_T ControlGainK_j[2];            /* '<S21>/Control Gain: K' */
  real_T X_n[4];                       /* '<S22>/-X' */
  real_T Sum2_o;                       /* '<S22>/Sum2' */
  real_T Sum1_e4;                      /* '<S22>/Sum1' */
  real_T TmpSignalConversionAtControlGainKInport1_be1[4];
  real_T ControlGainK_b[2];            /* '<S22>/Control Gain: K' */
  real_T Integrator_k;                 /* '<S26>/Integrator' */
  real_T Saturate_e;                   /* '<S26>/Saturate' */
  real_T Memory_g;                     /* '<S34>/Memory' */
  real_T Switch_m;                     /* '<S34>/Switch' */
  real_T Pitchu_ol_pLQR_n;             /* '<S24>/Pitch: u_ol_p +LQR' */
  real_T PitchAMPVoltageLimit_i;       /* '<S23>/Pitch AMP Voltage Limit' */
  real_T ChooseYawRelay_m;             /* '<S24>/Choose Yaw Relay' */
  real_T Add_l;                        /* '<S35>/Add' */
  real_T Integrator_h;                 /* '<S28>/Integrator' */
  real_T Saturate_g;                   /* '<S28>/Saturate' */
  real_T Memory_k;                     /* '<S35>/Memory' */
  real_T Switch_g;                     /* '<S35>/Switch' */
  real_T Yawu_ol_yLQR_e;               /* '<S24>/Yaw: u_ol_y +LQR' */
  real_T YawAMPVoltageLimit_h;         /* '<S23>/Yaw AMP Voltage Limit' */
  real_T PitchIntegralControlGainK15_c;/* '<S26>/Pitch Integral Control Gain: K(1,5)' */
  real_T YawCrossIntegralControlGainK16_k;/* '<S26>/Yaw Cross-Integral Control Gain: K(1,6)' */
  real_T IntegralInputVs_p;            /* '<S26>/Integral Input  (V//s)' */
  real_T uv_l;                         /* '<S26>/u-v' */
  real_T PitchResetTime_b;             /* '<S26>/Pitch Reset Time' */
  real_T Sum_a;                        /* '<S26>/Sum' */
  real_T TrigonometricFunction_f;      /* '<S27>/Trigonometric Function' */
  real_T FeedforwardPitchGain_f;       /* '<S27>/Feed-forward Pitch Gain' */
  real_T YawIntegralControlGainK26_i;  /* '<S28>/Yaw Integral Control Gain: K(2,6)' */
  real_T PitchCrossIntegralControlGainK25_p;/* '<S28>/Pitch Cross-Integral Control Gain: K(2,5)' */
  real_T IntegralInputVs_i;            /* '<S28>/Integral Input  (V//s)' */
  real_T uv_b;                         /* '<S28>/u-v' */
  real_T YawResetTime_a;               /* '<S28>/Yaw Reset Time' */
  real_T Sum_k;                        /* '<S28>/Sum' */
  real_T CrosstorqueactingonPitchfromYawMotor;/* '<S23>/Cross-torque acting on Pitch  from Yaw Motor' */
  real_T CrosstorqueactingonYawfromPitchMotor;/* '<S23>/Cross-torque acting on Yaw  from Pitch Motor' */
  real_T ThrusttorquefromYawMotor;     /* '<S23>/Thrust torque from  Yaw Motor' */
  real_T costheta;                     /* '<S32>/cos(theta)' */
  real_T sinpsi;                       /* '<S32>/sin(psi)' */
  real_T Product;                      /* '<S32>/Product' */
  real_T umlcm2;                       /* '<S32>/2*m*lcm^2' */
  real_T YawViscousDamping;            /* '<S23>/Yaw Viscous Damping' */
  real_T Sum4;                         /* '<S23>/Sum4' */
  real_T costheta_h;                   /* '<S31>/cos(theta)' */
  real_T costheta2;                    /* '<S31>/cos(theta)^2' */
  real_T m_helil_cm2;                  /* '<S31>/m_heli*l_cm^2' */
  real_T Sum3;                         /* '<S31>/Sum3' */
  real_T DividebyInertia;              /* '<S23>/Divide by Inertia' */
  real_T TrigonometricFunction_k;      /* '<S29>/Trigonometric Function' */
  real_T mglcm;                        /* '<S29>/m*g*lcm' */
  real_T ThrusttorquefromPitchMotor;   /* '<S23>/Thrust torque from  Pitch Motor' */
  real_T sintheta;                     /* '<S30>/sin(theta)' */
  real_T costheta_f;                   /* '<S30>/cos(theta)' */
  real_T Product_p;                    /* '<S30>/Product' */
  real_T mlcm2;                        /* '<S30>/m*lcm^2' */
  real_T PitchViscousDamping;          /* '<S23>/Pitch Viscous Damping' */
  real_T Sum2_g;                       /* '<S23>/Sum2' */
  real_T PitchInertia;                 /* '<S23>/Pitch Inertia' */
  real_T YawControlSwitch;             /* '<S33>/Yaw Control  Switch' */
  real_T YawLQRI;                      /* '<S22>/Yaw: LQR+I' */
  real_T PitchControlSwitch;           /* '<S33>/Pitch Control  Switch' */
  real_T TrigonometricFunction_m;      /* '<S25>/Trigonometric Function' */
  real_T FeedforwardPitchGain_n;       /* '<S25>/Feed-forward Pitch Gain' */
  real_T PitchFFLQR;                   /* '<S33>/Pitch: FF+LQR' */
  real_T PitchLQRI;                    /* '<S22>/Pitch: LQR+I' */
  real_T YawControlSwitch_l;           /* '<S14>/Yaw Control  Switch' */
  real_T YawLQRI_l;                    /* '<S8>/Yaw: LQR+I' */
  real_T PitchControlSwitch_b;         /* '<S14>/Pitch Control  Switch' */
  real_T TrigonometricFunction_mn;     /* '<S10>/Trigonometric Function' */
  real_T FeedforwardPitchGain_h;       /* '<S10>/Feed-forward Pitch Gain' */
  real_T FFGainAdj;                    /* '<S1>/FF Gain Adj.' */
  real_T PitchFFLQR_b;                 /* '<S14>/Pitch: FF+LQR' */
  real_T PitchLQRI_n;                  /* '<S8>/Pitch: LQR+I' */
  uint8_T Compare;                     /* '<S17>/Compare' */
  uint8_T PitchAdd1;                   /* '<S9>/Pitch: Add 1' */
  uint8_T Compare_m;                   /* '<S19>/Compare' */
  uint8_T Compare_g;                   /* '<S18>/Compare' */
  uint8_T YawAdd1;                     /* '<S9>/Yaw: Add 1' */
  uint8_T Compare_j;                   /* '<S20>/Compare' */
  uint8_T Compare_n;                   /* '<S36>/Compare' */
  uint8_T PitchAdd1_c;                 /* '<S24>/Pitch: Add 1' */
  uint8_T Compare_mw;                  /* '<S38>/Compare' */
  uint8_T Compare_mq;                  /* '<S37>/Compare' */
  uint8_T YawAdd1_b;                   /* '<S24>/Yaw: Add 1' */
  uint8_T Compare_l;                   /* '<S39>/Compare' */
} B_q_heli_2d_ff_lqr_i_nas_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Add_DWORK1;                   /* '<S15>/Add' */
  real_T Memory_PreviousInput;         /* '<S15>/Memory' */
  real_T Memory_PreviousInput_e;       /* '<S16>/Memory' */
  real_T Memory_PreviousInput_h;       /* '<S34>/Memory' */
  real_T Memory_PreviousInput_o;       /* '<S35>/Memory' */
  void *EncoderInput_PWORK;            /* '<S6>/Encoder Input' */
  void *EncoderInput1_PWORK;           /* '<S6>/Encoder Input1' */
  void *AnalogOutput_PWORK;            /* '<S6>/Analog Output' */
  void *AnalogOutput1_PWORK;           /* '<S6>/Analog Output1' */
  struct {
    void *LoggedData;
  } psideg_PWORK;                      /* '<S5>/psi (deg)' */

  struct {
    void *LoggedData;
  } psi_dotdegs_PWORK;                 /* '<S5>/psi_dot (deg//s)' */

  struct {
    void *LoggedData;
  } thetadeg_PWORK;                    /* '<S5>/theta (deg)' */

  struct {
    void *LoggedData;
  } theta_dotdegs_PWORK;               /* '<S5>/theta_dot (deg//s)' */

  struct {
    void *LoggedData;
  } Vm_actualV_PWORK;                  /* '<S5>/Vm_actual (V)' */

  struct {
    void *LoggedData;
  } Vm_simV_PWORK;                     /* '<S5>/Vm_sim (V)' */
} DW_q_heli_2d_ff_lqr_i_nas_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T DerivativeFilterPitch_CSTATE[2];/* '<S6>/Derivative Filter: Pitch' */
  real_T DerivativeFilterYaw_CSTATE[2];/* '<S6>/Derivative Filter: Yaw' */
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S13>/Integrator' */
  real_T theta_CSTATE;                 /* '<S23>/theta' */
  real_T psi_CSTATE;                   /* '<S23>/psi' */
  real_T theta_dot_CSTATE;             /* '<S23>/theta_dot' */
  real_T psi_dot_CSTATE;               /* '<S23>/psi_dot' */
  real_T Integrator_CSTATE_m;          /* '<S26>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S28>/Integrator' */
} X_q_heli_2d_ff_lqr_i_nas_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T DerivativeFilterPitch_CSTATE[2];/* '<S6>/Derivative Filter: Pitch' */
  real_T DerivativeFilterYaw_CSTATE[2];/* '<S6>/Derivative Filter: Yaw' */
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S13>/Integrator' */
  real_T theta_CSTATE;                 /* '<S23>/theta' */
  real_T psi_CSTATE;                   /* '<S23>/psi' */
  real_T theta_dot_CSTATE;             /* '<S23>/theta_dot' */
  real_T psi_dot_CSTATE;               /* '<S23>/psi_dot' */
  real_T Integrator_CSTATE_m;          /* '<S26>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S28>/Integrator' */
} XDot_q_heli_2d_ff_lqr_i_nas_T;

/* State disabled  */
typedef struct {
  boolean_T DerivativeFilterPitch_CSTATE[2];/* '<S6>/Derivative Filter: Pitch' */
  boolean_T DerivativeFilterYaw_CSTATE[2];/* '<S6>/Derivative Filter: Yaw' */
  boolean_T Integrator_CSTATE;         /* '<S11>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S13>/Integrator' */
  boolean_T theta_CSTATE;              /* '<S23>/theta' */
  boolean_T psi_CSTATE;                /* '<S23>/psi' */
  boolean_T theta_dot_CSTATE;          /* '<S23>/theta_dot' */
  boolean_T psi_dot_CSTATE;            /* '<S23>/psi_dot' */
  boolean_T Integrator_CSTATE_m;       /* '<S26>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S28>/Integrator' */
} XDis_q_heli_2d_ff_lqr_i_nas_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S11>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_e;   /* '<S13>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S26>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_b;   /* '<S28>/Integrator' */
} PrevZCX_q_heli_2d_ff_lqr_i_nas_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            q_heli_2d_ff_lqr_i_nas_B
#define BlockIO                        B_q_heli_2d_ff_lqr_i_nas_T
#define rtX                            q_heli_2d_ff_lqr_i_nas_X
#define ContinuousStates               X_q_heli_2d_ff_lqr_i_nas_T
#define rtXdot                         q_heli_2d_ff_lqr_i_nas_XDot
#define StateDerivatives               XDot_q_heli_2d_ff_lqr_i_nas_T
#define tXdis                          q_heli_2d_ff_lqr_i_nas_XDis
#define StateDisabled                  XDis_q_heli_2d_ff_lqr_i_nas_T
#define rtP                            q_heli_2d_ff_lqr_i_nas_P
#define Parameters                     P_q_heli_2d_ff_lqr_i_nas_T
#define rtDWork                        q_heli_2d_ff_lqr_i_nas_DW
#define D_Work                         DW_q_heli_2d_ff_lqr_i_nas_T
#define rtPrevZCSigState               q_heli_2d_ff_lqr_i_nas_PrevZCX
#define PrevZCSigStates                PrevZCX_q_heli_2d_ff_lqr_i_nas_T

/* Parameters (auto storage) */
struct P_q_heli_2d_ff_lqr_i_nas_T_ {
  real_T B_p;                          /* Variable: B_p
                                        * Referenced by: '<S23>/Pitch Viscous Damping'
                                        */
  real_T B_y;                          /* Variable: B_y
                                        * Referenced by: '<S23>/Yaw Viscous Damping'
                                        */
  real_T J_eq_p;                       /* Variable: J_eq_p
                                        * Referenced by: '<S23>/Pitch Inertia'
                                        */
  real_T J_eq_y;                       /* Variable: J_eq_y
                                        * Referenced by: '<S31>/Yaw Inertia'
                                        */
  real_T K[8];                         /* Variable: K
                                        * Referenced by:
                                        *   '<S7>/Control Gain: K'
                                        *   '<S21>/Control Gain: K'
                                        */
  real_T K_AMP;                        /* Variable: K_AMP
                                        * Referenced by:
                                        *   '<S6>/Pitch amp Gain Pre-Compensation'
                                        *   '<S6>/Yaw amp Gain Pre-Compensation'
                                        */
  real_T K_EC_P;                       /* Variable: K_EC_P
                                        * Referenced by: '<S6>/Encoder Resolution: Pitch '
                                        */
  real_T K_EC_Y;                       /* Variable: K_EC_Y
                                        * Referenced by: '<S6>/Encoder Resolution: Yaw'
                                        */
  real_T K_ff;                         /* Variable: K_ff
                                        * Referenced by: '<S1>/FF Gain Adj.'
                                        */
  real_T K_pp;                         /* Variable: K_pp
                                        * Referenced by:
                                        *   '<S23>/Thrust torque from  Pitch Motor'
                                        *   '<S10>/Feed-forward Pitch Gain'
                                        *   '<S12>/Feed-forward Pitch Gain'
                                        *   '<S25>/Feed-forward Pitch Gain'
                                        *   '<S27>/Feed-forward Pitch Gain'
                                        */
  real_T K_py;                         /* Variable: K_py
                                        * Referenced by: '<S23>/Cross-torque acting on Pitch  from Yaw Motor'
                                        */
  real_T K_yp;                         /* Variable: K_yp
                                        * Referenced by: '<S23>/Cross-torque acting on Yaw  from Pitch Motor'
                                        */
  real_T K_yy;                         /* Variable: K_yy
                                        * Referenced by: '<S23>/Thrust torque from  Yaw Motor'
                                        */
  real_T SAT_INT_ERR_PITCH;            /* Variable: SAT_INT_ERR_PITCH
                                        * Referenced by:
                                        *   '<S11>/Saturate'
                                        *   '<S26>/Saturate'
                                        */
  real_T SAT_INT_ERR_YAW;              /* Variable: SAT_INT_ERR_YAW
                                        * Referenced by:
                                        *   '<S13>/Saturate'
                                        *   '<S28>/Saturate'
                                        */
  real_T Tr_p;                         /* Variable: Tr_p
                                        * Referenced by:
                                        *   '<S11>/Pitch Reset Time'
                                        *   '<S26>/Pitch Reset Time'
                                        */
  real_T Tr_y;                         /* Variable: Tr_y
                                        * Referenced by:
                                        *   '<S13>/Yaw Reset Time'
                                        *   '<S28>/Yaw Reset Time'
                                        */
  real_T VMAX_AMP_P;                   /* Variable: VMAX_AMP_P
                                        * Referenced by:
                                        *   '<S6>/Pitch AMP Voltage Limit'
                                        *   '<S23>/Pitch AMP Voltage Limit'
                                        */
  real_T VMAX_AMP_Y;                   /* Variable: VMAX_AMP_Y
                                        * Referenced by:
                                        *   '<S6>/Yaw AMP Voltage Limit'
                                        *   '<S23>/Yaw AMP Voltage Limit'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S10>/Feed-forward Pitch Gain'
                                        *   '<S12>/Feed-forward Pitch Gain'
                                        *   '<S25>/Feed-forward Pitch Gain'
                                        *   '<S27>/Feed-forward Pitch Gain'
                                        *   '<S29>/m*g*lcm'
                                        */
  real_T l_cm;                         /* Variable: l_cm
                                        * Referenced by:
                                        *   '<S10>/Feed-forward Pitch Gain'
                                        *   '<S12>/Feed-forward Pitch Gain'
                                        *   '<S25>/Feed-forward Pitch Gain'
                                        *   '<S27>/Feed-forward Pitch Gain'
                                        *   '<S29>/m*g*lcm'
                                        */
  real_T m_heli;                       /* Variable: m_heli
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
  real_T theta_0;                      /* Variable: theta_0
                                        * Referenced by:
                                        *   '<S6>/Bias'
                                        *   '<S23>/theta'
                                        */
  real_T AnalogOutput_FinalValue;      /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  real_T AnalogOutput1_FinalValue;     /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  real_T AnalogOutput_InitialValue;    /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  real_T AnalogOutput1_InitialValue;   /* Mask Parameter: AnalogOutput1_InitialValue
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  real_T EncoderInput_InputFilter;     /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  real_T EncoderInput1_InputFilter;    /* Mask Parameter: EncoderInput1_InputFilter
                                        * Referenced by: '<S6>/Encoder Input1'
                                        */
  real_T EncoderInput_MaxMissedTicks;  /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  real_T EncoderInput1_MaxMissedTicks; /* Mask Parameter: EncoderInput1_MaxMissedTicks
                                        * Referenced by: '<S6>/Encoder Input1'
                                        */
  real_T AnalogOutput_MaxMissedTicks;  /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  real_T AnalogOutput1_MaxMissedTicks; /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  real_T EncoderInput_YieldWhenWaiting;/* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  real_T EncoderInput1_YieldWhenWaiting;/* Mask Parameter: EncoderInput1_YieldWhenWaiting
                                         * Referenced by: '<S6>/Encoder Input1'
                                         */
  real_T AnalogOutput_YieldWhenWaiting;/* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  real_T AnalogOutput1_YieldWhenWaiting;/* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                         * Referenced by: '<S6>/Analog Output1'
                                         */
  real_T PitchRelay_const;             /* Mask Parameter: PitchRelay_const
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T YawRelay_const;               /* Mask Parameter: YawRelay_const
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T CompareToConstant_const_n;    /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T PitchRelay_const_p;           /* Mask Parameter: PitchRelay_const_p
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T CompareToConstant_const_d;    /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T YawRelay_const_i;             /* Mask Parameter: YawRelay_const_i
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T CompareToConstant_const_e;    /* Mask Parameter: CompareToConstant_const_e
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T ConstantPitchdeg_gain;        /* Mask Parameter: ConstantPitchdeg_gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  int32_T EncoderInput_Channels;       /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  int32_T EncoderInput1_Channels;      /* Mask Parameter: EncoderInput1_Channels
                                        * Referenced by: '<S6>/Encoder Input1'
                                        */
  int32_T AnalogOutput_Channels;       /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  int32_T AnalogOutput1_Channels;      /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  int32_T AnalogOutput_RangeMode;      /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  int32_T AnalogOutput1_RangeMode;     /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  int32_T AnalogOutput_VoltRange;      /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S6>/Analog Output'
                                        */
  int32_T AnalogOutput1_VoltRange;     /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S6>/Analog Output1'
                                        */
  real_T LQR1LQRI2Pitchopenloop3Yawopenloop4_Value;/* Expression: 2
                                                    * Referenced by: '<Root>/LQR = 1 LQR+I = 2 Pitch open-loop  = 3 Yaw open-loop = 4'
                                                    */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T SignalGeneratorPitchV_Amplitude;/* Expression: 1
                                          * Referenced by: '<S4>/Signal Generator: Pitch (V)'
                                          */
  real_T SignalGeneratorPitchV_Frequency;/* Expression: 0.4
                                          * Referenced by: '<S4>/Signal Generator: Pitch (V)'
                                          */
  real_T AmplitudePitchV_Gain;         /* Expression: 0
                                        * Referenced by: '<S4>/Amplitude: Pitch (V)'
                                        */
  real_T ConstantPitchV_Value;         /* Expression: 3
                                        * Referenced by: '<S4>/Constant: Pitch (V)'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T SignalGeneratorPitch_Amplitude;/* Expression: 10
                                         * Referenced by: '<S3>/Signal Generator: Pitch'
                                         */
  real_T SignalGeneratorPitch_Frequency;/* Expression: 0.05
                                         * Referenced by: '<S3>/Signal Generator: Pitch'
                                         */
  real_T AmplitudePitchdeg_Gain;       /* Expression: 1
                                        * Referenced by: '<S3>/Amplitude: Pitch (deg)'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S41>/Gain1'
                                        */
  real_T DerivativeFilterPitch_A[2];   /* Computed Parameter: DerivativeFilterPitch_A
                                        * Referenced by: '<S6>/Derivative Filter: Pitch'
                                        */
  real_T DerivativeFilterPitch_C[2];   /* Computed Parameter: DerivativeFilterPitch_C
                                        * Referenced by: '<S6>/Derivative Filter: Pitch'
                                        */
  real_T DerivativeFilterYaw_A[2];     /* Computed Parameter: DerivativeFilterYaw_A
                                        * Referenced by: '<S6>/Derivative Filter: Yaw'
                                        */
  real_T DerivativeFilterYaw_C[2];     /* Computed Parameter: DerivativeFilterYaw_C
                                        * Referenced by: '<S6>/Derivative Filter: Yaw'
                                        */
  real_T X_Gain[16];                   /* Expression: -eye(4,4)
                                        * Referenced by: '<S7>/-X'
                                        */
  real_T SignalGeneratorYaw_Amplitude; /* Expression: 25
                                        * Referenced by: '<S3>/Signal Generator: Yaw'
                                        */
  real_T SignalGeneratorYaw_Frequency; /* Expression: 0.05
                                        * Referenced by: '<S3>/Signal Generator: Yaw'
                                        */
  real_T AmplitudeYawdeg_Gain;         /* Expression: 1
                                        * Referenced by: '<S3>/Amplitude: Yaw (deg)'
                                        */
  real_T ConstantYawdeg_Value;         /* Expression: 0
                                        * Referenced by: '<S3>/Constant: Yaw (deg)'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: pi/180
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T X_Gain_k[16];                 /* Expression: -eye(4,4)
                                        * Referenced by: '<S8>/-X'
                                        */
  real_T ControlGainK_Gain[8];         /* Expression: Ki(:,1:4)
                                        * Referenced by: '<S8>/Control Gain: K'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S15>/Memory'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T SignalGeneratorYawV_Amplitude;/* Expression: 1
                                        * Referenced by: '<S4>/Signal Generator: Yaw (V)'
                                        */
  real_T SignalGeneratorYawV_Frequency;/* Expression: 0.01
                                        * Referenced by: '<S4>/Signal Generator: Yaw (V)'
                                        */
  real_T AmplitudeYawV_Gain;           /* Expression: 0
                                        * Referenced by: '<S4>/Amplitude: Yaw (V)'
                                        */
  real_T ConstantYawV_Value;           /* Expression: 0
                                        * Referenced by: '<S4>/Constant: Yaw (V)'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Integrator_IC_i;              /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Memory_X0_m;                  /* Expression: 0
                                        * Referenced by: '<S16>/Memory'
                                        */
  real_T PitchIntegralControlGainK15_Gain;/* Expression: Ki(1,5)
                                           * Referenced by: '<S11>/Pitch Integral Control Gain: K(1,5)'
                                           */
  real_T YawCrossIntegralControlGainK16_Gain;/* Expression: Ki(1,6)
                                              * Referenced by: '<S11>/Yaw Cross-Integral Control Gain: K(1,6)'
                                              */
  real_T YawIntegralControlGainK26_Gain;/* Expression: Ki(2,6)
                                         * Referenced by: '<S13>/Yaw Integral Control Gain: K(2,6)'
                                         */
  real_T PitchCrossIntegralControlGainK25_Gain;/* Expression: Ki(2,5)
                                                * Referenced by: '<S13>/Pitch Cross-Integral Control Gain: K(2,5)'
                                                */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S44>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T psi_IC;                       /* Expression: 0
                                        * Referenced by: '<S23>/psi'
                                        */
  real_T theta_dot_IC;                 /* Expression: 0
                                        * Referenced by: '<S23>/theta_dot'
                                        */
  real_T psi_dot_IC;                   /* Expression: 0
                                        * Referenced by: '<S23>/psi_dot'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 180/pi
                                        * Referenced by: '<S43>/Gain'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T X_Gain_j[16];                 /* Expression: -eye(4,4)
                                        * Referenced by: '<S21>/-X'
                                        */
  real_T X_Gain_d[16];                 /* Expression: -eye(4,4)
                                        * Referenced by: '<S22>/-X'
                                        */
  real_T ControlGainK_Gain_h[8];       /* Expression: Ki(:,1:4)
                                        * Referenced by: '<S22>/Control Gain: K'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S26>/Integrator'
                                        */
  real_T Memory_X0_c;                  /* Expression: 0
                                        * Referenced by: '<S34>/Memory'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Integrator_IC_b;              /* Expression: 0
                                        * Referenced by: '<S28>/Integrator'
                                        */
  real_T Memory_X0_a;                  /* Expression: 0
                                        * Referenced by: '<S35>/Memory'
                                        */
  real_T PitchIntegralControlGainK15_Gain_a;/* Expression: Ki(1,5)
                                             * Referenced by: '<S26>/Pitch Integral Control Gain: K(1,5)'
                                             */
  real_T YawCrossIntegralControlGainK16_Gain_j;/* Expression: Ki(1,6)
                                                * Referenced by: '<S26>/Yaw Cross-Integral Control Gain: K(1,6)'
                                                */
  real_T YawIntegralControlGainK26_Gain_h;/* Expression: Ki(2,6)
                                           * Referenced by: '<S28>/Yaw Integral Control Gain: K(2,6)'
                                           */
  real_T PitchCrossIntegralControlGainK25_Gain_a;/* Expression: Ki(2,5)
                                                  * Referenced by: '<S28>/Pitch Cross-Integral Control Gain: K(2,5)'
                                                  */
  uint8_T PitchAdd1_Bias;              /* Computed Parameter: PitchAdd1_Bias
                                        * Referenced by: '<S9>/Pitch: Add 1'
                                        */
  uint8_T YawAdd1_Bias;                /* Computed Parameter: YawAdd1_Bias
                                        * Referenced by: '<S9>/Yaw: Add 1'
                                        */
  uint8_T PitchAdd1_Bias_b;            /* Computed Parameter: PitchAdd1_Bias_b
                                        * Referenced by: '<S24>/Pitch: Add 1'
                                        */
  uint8_T YawAdd1_Bias_j;              /* Computed Parameter: YawAdd1_Bias_j
                                        * Referenced by: '<S24>/Yaw: Add 1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_q_heli_2d_ff_lqr_i_nas_T {
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
extern P_q_heli_2d_ff_lqr_i_nas_T q_heli_2d_ff_lqr_i_nas_P;

/* Block signals (auto storage) */
extern B_q_heli_2d_ff_lqr_i_nas_T q_heli_2d_ff_lqr_i_nas_B;

/* Continuous states (auto storage) */
extern X_q_heli_2d_ff_lqr_i_nas_T q_heli_2d_ff_lqr_i_nas_X;

/* Block states (auto storage) */
extern DW_q_heli_2d_ff_lqr_i_nas_T q_heli_2d_ff_lqr_i_nas_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_q_heli_2d_ff_lqr_i_nas_T q_heli_2d_ff_lqr_i_nas_PrevZCX;

/* Model entry point functions */
extern void q_heli_2d_ff_lqr_i_nas_initialize(void);
extern void q_heli_2d_ff_lqr_i_nas_output(void);
extern void q_heli_2d_ff_lqr_i_nas_update(void);
extern void q_heli_2d_ff_lqr_i_nas_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern q_heli_2d_ff_lqr_i_nas_rtModel *q_heli_2d_ff_lqr_i_nas(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_q_heli_2d_ff_lqr_i_nas_T *const q_heli_2d_ff_lqr_i_nas_M;

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
 * '<Root>' : 'q_heli_2d_ff_lqr_i_nas'
 * '<S1>'   : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System'
 * '<S2>'   : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation'
 * '<S3>'   : 'q_heli_2d_ff_lqr_i_nas/Desired Angle from Program'
 * '<S4>'   : 'q_heli_2d_ff_lqr_i_nas/Desired Voltage'
 * '<S5>'   : 'q_heli_2d_ff_lqr_i_nas/Scopes'
 * '<S6>'   : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI'
 * '<S7>'   : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR Controller'
 * '<S8>'   : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller'
 * '<S9>'   : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch'
 * '<S10>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR Controller/Pitch feed-forward controller'
 * '<S11>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller/Pitch Integral Antiwidup'
 * '<S12>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller/Pitch feed-forward controller'
 * '<S13>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/2DOF HELI: FF+LQR+I Controller/Yaw Integral Antiwidup'
 * '<S14>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch/FF+LQR//FF+LQR+I Switch'
 * '<S15>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch/Latch: Pitch Voltage'
 * '<S16>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch/Latch: Yaw Voltage'
 * '<S17>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch/Pitch Relay'
 * '<S18>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch/Yaw Relay'
 * '<S19>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch/Latch: Pitch Voltage/Compare To Constant'
 * '<S20>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop Actual System/Controller Switch/Latch: Yaw Voltage/Compare To Constant'
 * '<S21>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: FF+LQR Controller'
 * '<S22>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: FF+LQR+I Controller'
 * '<S23>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: Nonlinear Model'
 * '<S24>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch'
 * '<S25>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: FF+LQR Controller/Pitch feed-forward controller'
 * '<S26>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: FF+LQR+I Controller/Pitch Integral Antiwidup'
 * '<S27>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: FF+LQR+I Controller/Pitch feed-forward controller'
 * '<S28>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: FF+LQR+I Controller/Yaw Integral Antiwidup'
 * '<S29>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: Nonlinear Model/Gravitational Torque'
 * '<S30>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: Nonlinear Model/Pitch Position Dependent Torque'
 * '<S31>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: Nonlinear Model/Yaw Inertia'
 * '<S32>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/2DOF HELI: Nonlinear Model/Yaw Position Dependent Torque'
 * '<S33>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch/FF+LQR//FF+LQR+I Switch'
 * '<S34>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch/Latch: Pitch Voltage'
 * '<S35>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch/Latch: Yaw Voltage'
 * '<S36>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch/Pitch Relay'
 * '<S37>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch/Yaw Relay'
 * '<S38>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch/Latch: Pitch Voltage/Compare To Constant'
 * '<S39>'  : 'q_heli_2d_ff_lqr_i_nas/2 DOF Helicopter - Closed-loop System Simulation/Controller Switch/Latch: Yaw Voltage/Compare To Constant'
 * '<S40>'  : 'q_heli_2d_ff_lqr_i_nas/Desired Angle from Program/Constant: Pitch (deg)'
 * '<S41>'  : 'q_heli_2d_ff_lqr_i_nas/Desired Angle from Program/Pitch: deg to rad'
 * '<S42>'  : 'q_heli_2d_ff_lqr_i_nas/Desired Angle from Program/Yaw: deg to rad'
 * '<S43>'  : 'q_heli_2d_ff_lqr_i_nas/Scopes/Radians to Degree - Sim States'
 * '<S44>'  : 'q_heli_2d_ff_lqr_i_nas/Scopes/Radians to Degrees - Des. States'
 * '<S45>'  : 'q_heli_2d_ff_lqr_i_nas/Scopes/Radians to Degrees - Meas. States'
 */
#endif                                 /* RTW_HEADER_q_heli_2d_ff_lqr_i_nas_h_ */
