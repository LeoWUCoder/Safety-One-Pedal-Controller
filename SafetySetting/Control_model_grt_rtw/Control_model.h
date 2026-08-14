/*
 * Control_model.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Control_model".
 *
 * Model version              : 1.9
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Aug 14 19:09:05 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Control_model_h_
#define Control_model_h_
#ifndef Control_model_COMMON_INCLUDES_
#define Control_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Control_model_COMMON_INCLUDES_ */

#include "Control_model_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Switch2;                    /* '<S1>/Switch2' */
  real32_T out;                        /* '<Root>/PedalVoter' */
  TransmissionState Switch1;           /* '<S1>/Switch1' */
  boolean_T Switch;                    /* '<S1>/Switch' */
} B_Control_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Tolerance;                  /* '<Root>/PedalVoter' */
  real32_T sumError;                   /* '<Root>/Chart' */
  uint8_T is_active_c2_Control_model;  /* '<Root>/PedalVoter' */
  uint8_T is_c2_Control_model;         /* '<Root>/PedalVoter' */
  uint8_T is_active_c3_Control_model;  /* '<Root>/Chart' */
  uint8_T is_c3_Control_model;         /* '<Root>/Chart' */
  uint8_T is_LimpMode;                 /* '<Root>/Chart' */
  uint8_T is_Drive;                    /* '<Root>/Chart' */
  uint8_T is_Reverse;                  /* '<Root>/Chart' */
  uint8_T is_NoFailureDetected;        /* '<Root>/Chart' */
  uint8_T is_Brake;                    /* '<Root>/Chart' */
  uint8_T is_BrakeNormal;              /* '<Root>/Chart' */
  uint8_T is_Drive_f;                  /* '<Root>/Chart' */
  uint8_T is_Reverse_f;                /* '<Root>/Chart' */
} DW_Control_model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  TransmissionState AutomaticTransmissionSelectorSt;
                               /* '<Root>/AutomaticTransmissionSelectorState' */
  real32_T VehicleSpeed_km_h;          /* '<Root>/VehicleSpeed_km_h' */
  boolean_T CANBUSavailableSignals[3]; /* '<Root>/CAN BUS available Signals' */
  boolean_T ThrottlePedalSensorReset;  /* '<Root>/ThrottlePedalSensorReset' */
  real32_T PedalPositionSensor[3];     /* '<Root>/PedalPositionSensor' */
  boolean_T BrakePedalPressed;         /* '<Root>/BrakePedalPressed' */
} ExtU_Control_model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T TorqueRequest_Nm;           /* '<Root>/TorqueRequest_Nm' */
  TransmissionState AutomaticTransmissionState;/* '<Root>/AutomaticTransmissionState' */
  int8_T SensorFailMode;               /* '<Root>/Sensor Fail Mode' */
  int8_T CANBUSFailMode;               /* '<Root>/CAN BUS Fail Mode' */
} ExtY_Control_model_T;

/* Parameters (default storage) */
struct P_Control_model_T_ {
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  TransmissionState Constant1_Value;   /* Expression: TransmissionState.Neutral
                                        * Referenced by: '<S1>/Constant1'
                                        */
  boolean_T Constant_Value;            /* Expression: logical(1)
                                        * Referenced by: '<S1>/Constant'
                                        */
  int8_T Constant3_Value;              /* Expression: int8(1)
                                        * Referenced by: '<S1>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Expression: int8(2)
                                        * Referenced by: '<S1>/Constant4'
                                        */
  int8_T Constant5_Value;              /* Expression: int8(4)
                                        * Referenced by: '<S1>/Constant5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Control_model_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Control_model_T Control_model_P;

/* Block signals (default storage) */
extern B_Control_model_T Control_model_B;

/* Block states (default storage) */
extern DW_Control_model_T Control_model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Control_model_T Control_model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Control_model_T Control_model_Y;

/* Model entry point functions */
extern void Control_model_initialize(void);
extern void Control_model_step(void);
extern void Control_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Control_model_T *const Control_model_M;

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
 * '<Root>' : 'Control_model'
 * '<S1>'   : 'Control_model/CAN Signal Checker'
 * '<S2>'   : 'Control_model/Chart'
 * '<S3>'   : 'Control_model/PedalVoter'
 */
#endif                                 /* Control_model_h_ */
