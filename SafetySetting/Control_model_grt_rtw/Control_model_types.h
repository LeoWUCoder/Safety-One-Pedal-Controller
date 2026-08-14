/*
 * Control_model_types.h
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

#ifndef Control_model_types_h_
#define Control_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_TransmissionState_
#define DEFINED_TYPEDEF_FOR_TransmissionState_

typedef enum {
  Park = 0,                            /* Default value */
  Reverse,
  Neutral,
  Drive,
  Brake
} TransmissionState;

#endif

/* Parameters (default storage) */
typedef struct P_Control_model_T_ P_Control_model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Control_model_T RT_MODEL_Control_model_T;

#endif                                 /* Control_model_types_h_ */
