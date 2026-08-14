/*
 * Control_model.c
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

#include "Control_model.h"
#include "rtwtypes.h"
#include "Control_model_types.h"
#include <math.h>
#include <string.h>
#include "Control_model_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Control_mo_IN_NoFailureDetected ((uint8_T)2U)
#define Control_mode_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Control_model_IN_Brake         ((uint8_T)1U)
#define Control_model_IN_BrakeNormal   ((uint8_T)1U)
#define Control_model_IN_Drive         ((uint8_T)1U)
#define Control_model_IN_Drive_h       ((uint8_T)2U)
#define Control_model_IN_LimpMode      ((uint8_T)1U)
#define Control_model_IN_Neutral       ((uint8_T)2U)
#define Control_model_IN_Neutral_b     ((uint8_T)3U)
#define Control_model_IN_Park          ((uint8_T)3U)
#define Control_model_IN_Park_l        ((uint8_T)4U)
#define Control_model_IN_Reverse       ((uint8_T)4U)
#define Control_model_IN_Reverse_f     ((uint8_T)5U)
#define Control_model_IN_barkDecele    ((uint8_T)1U)
#define Control_model_IN_barkStop      ((uint8_T)2U)
#define Control_model_IN_brak0Velocity ((uint8_T)2U)
#define Control_model_IN_brakeAccle    ((uint8_T)3U)
#define Control_model_IN_driveStop     ((uint8_T)1U)
#define Control_model_IN_normalDrive   ((uint8_T)2U)
#define Control_model_IN_normalReverse ((uint8_T)1U)
#define Control_model_IN_reverseStop   ((uint8_T)2U)

/* Named constants for Chart: '<Root>/PedalVoter' */
#define Control_model_IN_A_Failure     ((uint8_T)1U)
#define Control_model_IN_B_Failure     ((uint8_T)2U)
#define Control_model_IN_C_Failure     ((uint8_T)3U)
#define Control_model_IN_NO_Trust      ((uint8_T)4U)
#define Control_model_IN_Normal        ((uint8_T)5U)

/* Block signals (default storage) */
B_Control_model_T Control_model_B;

/* Block states (default storage) */
DW_Control_model_T Control_model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Control_model_T Control_model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Control_model_T Control_model_Y;

/* Real-time model */
static RT_MODEL_Control_model_T Control_model_M_;
RT_MODEL_Control_model_T *const Control_model_M = &Control_model_M_;

/* Forward declaration for local functions */
static void Control_model_NoFailureDetected(void);

/* Function for Chart: '<Root>/Chart' */
static void Control_model_NoFailureDetected(void)
{
  boolean_T tmp;
  switch (Control_model_DW.is_NoFailureDetected) {
   case Control_model_IN_Brake:
    if (Control_model_B.Switch1 == Drive) {
      if (Control_model_DW.is_Brake == Control_model_IN_BrakeNormal) {
        if (Control_model_DW.is_BrakeNormal == Control_model_IN_brak0Velocity) {
          Control_model_DW.sumError = 0.0F;
          Control_model_DW.is_BrakeNormal = Control_mode_IN_NO_ACTIVE_CHILD;
        } else {
          Control_model_DW.is_BrakeNormal = Control_mode_IN_NO_ACTIVE_CHILD;
        }

        Control_model_DW.is_Brake = Control_mode_IN_NO_ACTIVE_CHILD;
      } else {
        Control_model_DW.is_Brake = Control_mode_IN_NO_ACTIVE_CHILD;
      }

      Control_model_DW.is_NoFailureDetected = Control_model_IN_Drive_h;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Drive;
      Control_model_DW.is_Drive_f = Control_model_IN_driveStop;
    } else if (Control_model_B.Switch1 == Neutral) {
      if (Control_model_DW.is_Brake == Control_model_IN_BrakeNormal) {
        if (Control_model_DW.is_BrakeNormal == Control_model_IN_brak0Velocity) {
          Control_model_DW.sumError = 0.0F;
          Control_model_DW.is_BrakeNormal = Control_mode_IN_NO_ACTIVE_CHILD;
        } else {
          Control_model_DW.is_BrakeNormal = Control_mode_IN_NO_ACTIVE_CHILD;
        }

        Control_model_DW.is_Brake = Control_mode_IN_NO_ACTIVE_CHILD;
      } else {
        Control_model_DW.is_Brake = Control_mode_IN_NO_ACTIVE_CHILD;
      }

      Control_model_DW.is_NoFailureDetected = Control_model_IN_Neutral_b;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Neutral;
    } else if (Control_model_DW.is_Brake == Control_model_IN_BrakeNormal) {
      if (Control_model_B.Switch) {
        if (Control_model_DW.is_BrakeNormal == Control_model_IN_brak0Velocity) {
          Control_model_DW.sumError = 0.0F;
          Control_model_DW.is_BrakeNormal = Control_mode_IN_NO_ACTIVE_CHILD;
        } else {
          Control_model_DW.is_BrakeNormal = Control_mode_IN_NO_ACTIVE_CHILD;
        }

        Control_model_DW.is_Brake = Control_model_IN_barkStop;

        /* Outport: '<Root>/TorqueRequest_Nm' */
        Control_model_Y.TorqueRequest_Nm = 0.0F;
      } else {
        switch (Control_model_DW.is_BrakeNormal) {
         case Control_model_IN_barkDecele:
          if (Control_model_B.out > 0.33333333333333331) {
            Control_model_DW.is_BrakeNormal = Control_model_IN_brakeAccle;
          } else if (Control_model_B.Switch2 <= 0.2) {
            Control_model_DW.is_BrakeNormal = Control_model_IN_brak0Velocity;
          } else {
            /* Outport: '<Root>/TorqueRequest_Nm' */
            Control_model_Y.TorqueRequest_Nm = (0.333333343F -
              Control_model_B.out) * -3.0F * 960.0F / 12.0F;
          }
          break;

         case Control_model_IN_brak0Velocity:
          if (Control_model_B.out > 0.33333333333333331) {
            Control_model_DW.sumError = 0.0F;
            Control_model_DW.is_BrakeNormal = Control_model_IN_brakeAccle;
          } else {
            Control_model_DW.sumError += 0.0F - Control_model_B.Switch2;

            /* Outport: '<Root>/TorqueRequest_Nm' */
            Control_model_Y.TorqueRequest_Nm = (0.0F - Control_model_B.Switch2) *
              30.0F + Control_model_DW.sumError * 2.0F;
          }
          break;

         default:
          /* case IN_brakeAccle: */
          if (Control_model_B.out <= 0.33333333333333331) {
            Control_model_DW.is_BrakeNormal = Control_model_IN_barkDecele;
          } else {
            /* Outport: '<Root>/TorqueRequest_Nm' */
            Control_model_Y.TorqueRequest_Nm = (Control_model_B.out -
              0.333333343F) * 1.5F * 960.0F / 12.0F;
          }
          break;
        }
      }

      /* case IN_barkStop: */
    } else if (!Control_model_B.Switch) {
      Control_model_DW.is_Brake = Control_model_IN_BrakeNormal;
      Control_model_DW.is_BrakeNormal = Control_model_IN_brakeAccle;
    }
    break;

   case Control_model_IN_Drive_h:
    if (Control_model_B.Switch1 == Neutral) {
      Control_model_DW.is_Drive_f = Control_mode_IN_NO_ACTIVE_CHILD;
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Neutral_b;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Neutral;
    } else if ((Control_model_B.out > 0.33333333333333331) &&
               (Control_model_B.Switch1 == Brake)) {
      Control_model_DW.is_Drive_f = Control_mode_IN_NO_ACTIVE_CHILD;
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Brake;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Brake;
      Control_model_DW.is_Brake = Control_model_IN_barkStop;

      /* Outport: '<Root>/TorqueRequest_Nm' */
      Control_model_Y.TorqueRequest_Nm = 0.0F;
    } else if (Control_model_DW.is_Drive_f == Control_model_IN_driveStop) {
      if (!Control_model_B.Switch) {
        Control_model_DW.is_Drive_f = Control_model_IN_normalDrive;
      } else {
        /* Outport: '<Root>/TorqueRequest_Nm' */
        Control_model_Y.TorqueRequest_Nm = 0.0F;
      }

      /* case IN_normalDrive: */
    } else if (Control_model_B.Switch) {
      Control_model_DW.is_Drive_f = Control_model_IN_driveStop;
    } else {
      /* Outport: '<Root>/TorqueRequest_Nm' */
      Control_model_Y.TorqueRequest_Nm = Control_model_B.out * 960.0F / 12.0F;
    }
    break;

   case Control_model_IN_Neutral_b:
    tmp = ((Control_model_B.Switch2 < 5.0F) && (Control_model_B.Switch2 > -5.0F)
           && Control_model_B.Switch);
    if (tmp && (Control_model_B.Switch1 == Park)) {
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Park_l;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Park;
    } else if (tmp && (Control_model_B.Switch1 == Reverse)) {
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Reverse_f;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Reverse;
      Control_model_DW.is_Reverse_f = Control_model_IN_reverseStop;
    } else if (tmp && (Control_model_B.Switch1 == Drive)) {
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Drive_h;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Drive;
      Control_model_DW.is_Drive_f = Control_model_IN_driveStop;
    } else if (tmp && (Control_model_B.Switch1 == Brake)) {
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Brake;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Brake;
      Control_model_DW.is_Brake = Control_model_IN_barkStop;

      /* Outport: '<Root>/TorqueRequest_Nm' */
      Control_model_Y.TorqueRequest_Nm = 0.0F;
    } else {
      /* Outport: '<Root>/TorqueRequest_Nm' */
      Control_model_Y.TorqueRequest_Nm = 0.0F;
    }
    break;

   case Control_model_IN_Park_l:
    if (Control_model_B.Switch && (Control_model_B.Switch1 != Park)) {
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Neutral_b;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Neutral;
    } else {
      /* Outport: '<Root>/TorqueRequest_Nm' */
      Control_model_Y.TorqueRequest_Nm = 0.0F;
    }
    break;

   default:
    /* case IN_Reverse: */
    if (Control_model_B.Switch1 != Reverse) {
      Control_model_DW.is_Reverse_f = Control_mode_IN_NO_ACTIVE_CHILD;
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Neutral_b;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Neutral;
    } else if (Control_model_DW.is_Reverse_f == Control_model_IN_normalReverse)
    {
      if (Control_model_B.Switch) {
        Control_model_DW.is_Reverse_f = Control_model_IN_reverseStop;
      } else {
        /* Outport: '<Root>/TorqueRequest_Nm' */
        Control_model_Y.TorqueRequest_Nm = -8.0F * Control_model_B.out * 60.0F /
          12.0F;
      }

      /* case IN_reverseStop: */
    } else if (!Control_model_B.Switch) {
      Control_model_DW.is_Reverse_f = Control_model_IN_normalReverse;
    } else {
      /* Outport: '<Root>/TorqueRequest_Nm' */
      Control_model_Y.TorqueRequest_Nm = 0.0F;
    }
    break;
  }
}

/* Model step function */
void Control_model_step(void)
{
  real32_T abDiff;
  real32_T acDiff;
  int8_T rtb_Add;
  boolean_T tmp;

  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/CAN BUS available Signals'
   */
  if (Control_model_U.CANBUSavailableSignals[0]) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Inport: '<Root>/BrakePedalPressed'
     */
    Control_model_B.Switch = Control_model_U.BrakePedalPressed;
  } else {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     */
    Control_model_B.Switch = Control_model_P.Constant_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Chart: '<Root>/PedalVoter' incorporates:
   *  Inport: '<Root>/PedalPositionSensor'
   *  Outport: '<Root>/Sensor Fail Mode'
   */
  if (Control_model_DW.is_active_c2_Control_model == 0) {
    Control_model_DW.is_active_c2_Control_model = 1U;
    Control_model_DW.is_c2_Control_model = Control_model_IN_Normal;
  } else {
    switch (Control_model_DW.is_c2_Control_model) {
     case Control_model_IN_A_Failure:
      if (Control_model_Y.SensorFailMode == 4) {
        Control_model_DW.is_c2_Control_model = Control_model_IN_NO_Trust;
        Control_model_B.out = 0.0F;
      } else if ((fabsf(Control_model_U.PedalPositionSensor[1] -
                        Control_model_U.PedalPositionSensor[2]) >
                  Control_model_DW.Tolerance) ||
                 ((Control_model_U.PedalPositionSensor[1] > 1.0F) ||
                  (Control_model_U.PedalPositionSensor[1] < 0.0F) ||
                  (Control_model_U.PedalPositionSensor[2] > 1.0F) ||
                  (Control_model_U.PedalPositionSensor[2] < 0.0F))) {
        /* Outport: '<Root>/Sensor Fail Mode' */
        Control_model_Y.SensorFailMode = 4;
        Control_model_B.out = 0.0F;
      } else {
        Control_model_B.out = (Control_model_U.PedalPositionSensor[1] +
          Control_model_U.PedalPositionSensor[2]) / 2.0F;
      }
      break;

     case Control_model_IN_B_Failure:
      if (Control_model_Y.SensorFailMode == 4) {
        Control_model_DW.is_c2_Control_model = Control_model_IN_NO_Trust;
        Control_model_B.out = 0.0F;
      } else if ((fabsf(Control_model_U.PedalPositionSensor[0] -
                        Control_model_U.PedalPositionSensor[2]) >
                  Control_model_DW.Tolerance) ||
                 ((Control_model_U.PedalPositionSensor[0] > 1.0F) ||
                  (Control_model_U.PedalPositionSensor[0] < 0.0F) ||
                  (Control_model_U.PedalPositionSensor[2] > 1.0F) ||
                  (Control_model_U.PedalPositionSensor[2] < 0.0F))) {
        /* Outport: '<Root>/Sensor Fail Mode' */
        Control_model_Y.SensorFailMode = 4;
        Control_model_B.out = 0.0F;
      } else {
        Control_model_B.out = (Control_model_U.PedalPositionSensor[0] +
          Control_model_U.PedalPositionSensor[2]) / 2.0F;
      }
      break;

     case Control_model_IN_C_Failure:
      if (Control_model_Y.SensorFailMode == 4) {
        Control_model_DW.is_c2_Control_model = Control_model_IN_NO_Trust;
        Control_model_B.out = 0.0F;
      } else if ((fabsf(Control_model_U.PedalPositionSensor[0] -
                        Control_model_U.PedalPositionSensor[1]) >
                  Control_model_DW.Tolerance) ||
                 ((Control_model_U.PedalPositionSensor[1] > 1.0F) ||
                  (Control_model_U.PedalPositionSensor[1] < 0.0F) ||
                  (Control_model_U.PedalPositionSensor[0] > 1.0F) ||
                  (Control_model_U.PedalPositionSensor[0] < 0.0F))) {
        /* Outport: '<Root>/Sensor Fail Mode' */
        Control_model_Y.SensorFailMode = 4;
        Control_model_B.out = 0.0F;
      } else {
        Control_model_B.out = (Control_model_U.PedalPositionSensor[0] +
          Control_model_U.PedalPositionSensor[1]) / 2.0F;
      }
      break;

     case Control_model_IN_NO_Trust:
      Control_model_DW.is_c2_Control_model = Control_model_IN_NO_Trust;
      Control_model_B.out = 0.0F;
      break;

     default:
      /* case IN_Normal: */
      if (Control_model_Y.SensorFailMode == 1) {
        Control_model_DW.is_c2_Control_model = Control_model_IN_A_Failure;
        Control_model_B.out = (Control_model_U.PedalPositionSensor[1] +
          Control_model_U.PedalPositionSensor[2]) / 2.0F;
      } else if (Control_model_Y.SensorFailMode == 3) {
        Control_model_DW.is_c2_Control_model = Control_model_IN_C_Failure;
        Control_model_B.out = (Control_model_U.PedalPositionSensor[0] +
          Control_model_U.PedalPositionSensor[1]) / 2.0F;
      } else if (Control_model_Y.SensorFailMode == 2) {
        Control_model_DW.is_c2_Control_model = Control_model_IN_B_Failure;
        Control_model_B.out = (Control_model_U.PedalPositionSensor[0] +
          Control_model_U.PedalPositionSensor[2]) / 2.0F;
      } else {
        abDiff = fabsf(Control_model_U.PedalPositionSensor[0] -
                       Control_model_U.PedalPositionSensor[1]);
        acDiff = fabsf(Control_model_U.PedalPositionSensor[0] -
                       Control_model_U.PedalPositionSensor[2]);
        if ((Control_model_U.PedalPositionSensor[0] < 0.0F) ||
            (Control_model_U.PedalPositionSensor[0] > 1.0F) || ((abDiff >
              Control_model_DW.Tolerance) && (acDiff >
              Control_model_DW.Tolerance))) {
          Control_model_B.out = (Control_model_U.PedalPositionSensor[1] +
            Control_model_U.PedalPositionSensor[2]) / 2.0F;
          Control_model_Y.SensorFailMode = 1;
        } else if ((Control_model_U.PedalPositionSensor[1] > 1.0F) ||
                   (Control_model_U.PedalPositionSensor[1] < 0.0F) || (abDiff >
                    Control_model_DW.Tolerance)) {
          Control_model_B.out = (Control_model_U.PedalPositionSensor[0] +
            Control_model_U.PedalPositionSensor[2]) / 2.0F;
          Control_model_Y.SensorFailMode = 2;
        } else if ((Control_model_U.PedalPositionSensor[2] > 1.0F) ||
                   (Control_model_U.PedalPositionSensor[2] < 0.0F) || (acDiff >
                    Control_model_DW.Tolerance)) {
          Control_model_B.out = (Control_model_U.PedalPositionSensor[0] +
            Control_model_U.PedalPositionSensor[1]) / 2.0F;
          Control_model_Y.SensorFailMode = 3;
        } else {
          Control_model_B.out = ((Control_model_U.PedalPositionSensor[0] +
            Control_model_U.PedalPositionSensor[1]) +
            Control_model_U.PedalPositionSensor[2]) / 3.0F;
          Control_model_Y.SensorFailMode = 0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/PedalVoter' */

  /* Switch: '<S1>/Switch1' incorporates:
   *  Inport: '<Root>/CAN BUS available Signals'
   *  Logic: '<S1>/OR'
   */
  if (Control_model_U.CANBUSavailableSignals[1] &&
      Control_model_U.CANBUSavailableSignals[2]) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Inport: '<Root>/AutomaticTransmissionSelectorState'
     */
    Control_model_B.Switch1 = Control_model_U.AutomaticTransmissionSelectorSt;
  } else {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    Control_model_B.Switch1 = Control_model_P.Constant1_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Switch: '<S1>/Switch2' incorporates:
   *  Inport: '<Root>/CAN BUS available Signals'
   */
  if (Control_model_U.CANBUSavailableSignals[2]) {
    /* Switch: '<S1>/Switch2' incorporates:
     *  Inport: '<Root>/VehicleSpeed_km_h'
     */
    Control_model_B.Switch2 = Control_model_U.VehicleSpeed_km_h;
  } else {
    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant2'
     *  DataTypeConversion: '<S1>/Cast To Boolean'
     */
    Control_model_B.Switch2 = (real32_T)Control_model_P.Constant2_Value;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Inport: '<Root>/CAN BUS available Signals'
   *  Logic: '<S1>/NOT'
   *  Logic: '<S1>/NOT1'
   *  Logic: '<S1>/NOT2'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Product: '<S1>/Product2'
   */
  rtb_Add = (int8_T)((int8_T)(!Control_model_U.CANBUSavailableSignals[0] *
    Control_model_P.Constant3_Value + !Control_model_U.CANBUSavailableSignals[1]
    * Control_model_P.Constant4_Value) +
                     !Control_model_U.CANBUSavailableSignals[2] *
                     Control_model_P.Constant5_Value);

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/ThrottlePedalSensorReset'
   *  Logic: '<Root>/OR'
   *  Outport: '<Root>/Sensor Fail Mode'
   */
  if (Control_model_DW.is_active_c3_Control_model == 0) {
    Control_model_DW.is_active_c3_Control_model = 1U;
    Control_model_DW.is_c3_Control_model = Control_mo_IN_NoFailureDetected;
    Control_model_DW.is_NoFailureDetected = Control_model_IN_Park_l;

    /* Outport: '<Root>/AutomaticTransmissionState' */
    Control_model_Y.AutomaticTransmissionState = Park;
  } else if (Control_model_DW.is_c3_Control_model == Control_model_IN_LimpMode)
  {
    if (Control_model_U.ThrottlePedalSensorReset &&
        ((Control_model_Y.SensorFailMode == 0) && (rtb_Add == 0))) {
      Control_model_DW.is_Drive = Control_mode_IN_NO_ACTIVE_CHILD;
      Control_model_DW.is_Reverse = Control_mode_IN_NO_ACTIVE_CHILD;
      Control_model_DW.is_LimpMode = Control_mode_IN_NO_ACTIVE_CHILD;
      Control_model_DW.is_c3_Control_model = Control_mo_IN_NoFailureDetected;
      Control_model_DW.is_NoFailureDetected = Control_model_IN_Park_l;

      /* Outport: '<Root>/AutomaticTransmissionState' */
      Control_model_Y.AutomaticTransmissionState = Park;
    } else {
      switch (Control_model_DW.is_LimpMode) {
       case Control_model_IN_Drive:
        if (Control_model_B.Switch1 == Neutral) {
          Control_model_DW.is_Drive = Control_mode_IN_NO_ACTIVE_CHILD;
          Control_model_DW.is_LimpMode = Control_model_IN_Neutral;

          /* Outport: '<Root>/AutomaticTransmissionState' */
          Control_model_Y.AutomaticTransmissionState = Neutral;
        } else if (Control_model_DW.is_Drive == Control_model_IN_driveStop) {
          if (!Control_model_B.Switch) {
            Control_model_DW.is_Drive = Control_model_IN_normalDrive;
          } else {
            /* Outport: '<Root>/TorqueRequest_Nm' */
            Control_model_Y.TorqueRequest_Nm = 0.0F;
          }

          /* case IN_normalDrive: */
        } else if (Control_model_B.Switch) {
          Control_model_DW.is_Drive = Control_model_IN_driveStop;
        } else if (Control_model_B.Switch2 < 20.0F) {
          /* Outport: '<Root>/TorqueRequest_Nm' */
          Control_model_Y.TorqueRequest_Nm = Control_model_B.out * 80.0F / 10.0F;
        } else {
          /* Outport: '<Root>/TorqueRequest_Nm' */
          Control_model_Y.TorqueRequest_Nm = 0.0F;
        }
        break;

       case Control_model_IN_Neutral:
        tmp = ((Control_model_B.Switch2 < 5.0F) && (Control_model_B.Switch2 >
                -5.0F) && Control_model_B.Switch);
        if (tmp && (Control_model_B.Switch1 == Park)) {
          Control_model_DW.is_LimpMode = Control_model_IN_Park;

          /* Outport: '<Root>/AutomaticTransmissionState' */
          Control_model_Y.AutomaticTransmissionState = Park;
        } else if (tmp && (Control_model_B.Switch1 == Reverse)) {
          Control_model_DW.is_LimpMode = Control_model_IN_Reverse;

          /* Outport: '<Root>/AutomaticTransmissionState' */
          Control_model_Y.AutomaticTransmissionState = Reverse;
          Control_model_DW.is_Reverse = Control_model_IN_reverseStop;
        } else if ((Control_model_B.Switch2 > -5.0F) && Control_model_B.Switch &&
                   ((Control_model_B.Switch1 == Drive) ||
                    (Control_model_B.Switch1 == Brake))) {
          Control_model_DW.is_LimpMode = Control_model_IN_Drive;

          /* Outport: '<Root>/AutomaticTransmissionState' */
          Control_model_Y.AutomaticTransmissionState = Drive;
          Control_model_DW.is_Drive = Control_model_IN_driveStop;
        } else {
          /* Outport: '<Root>/TorqueRequest_Nm' */
          Control_model_Y.TorqueRequest_Nm = 0.0F;
        }
        break;

       case Control_model_IN_Park:
        if (Control_model_B.Switch && (Control_model_B.Switch1 != Park)) {
          Control_model_DW.is_LimpMode = Control_model_IN_Neutral;

          /* Outport: '<Root>/AutomaticTransmissionState' */
          Control_model_Y.AutomaticTransmissionState = Neutral;
        } else {
          /* Outport: '<Root>/TorqueRequest_Nm' */
          Control_model_Y.TorqueRequest_Nm = 0.0F;
        }
        break;

       default:
        /* case IN_Reverse: */
        if (Control_model_B.Switch1 != Reverse) {
          Control_model_DW.is_Reverse = Control_mode_IN_NO_ACTIVE_CHILD;
          Control_model_DW.is_LimpMode = Control_model_IN_Neutral;

          /* Outport: '<Root>/AutomaticTransmissionState' */
          Control_model_Y.AutomaticTransmissionState = Neutral;
        } else if (Control_model_DW.is_Reverse == Control_model_IN_normalReverse)
        {
          if (Control_model_B.Switch) {
            Control_model_DW.is_Reverse = Control_model_IN_reverseStop;
          } else {
            /* Outport: '<Root>/TorqueRequest_Nm' */
            Control_model_Y.TorqueRequest_Nm = -8.0F * Control_model_B.out *
              60.0F / 12.0F / 10.0F;
          }

          /* case IN_reverseStop: */
        } else if (!Control_model_B.Switch) {
          Control_model_DW.is_Reverse = Control_model_IN_normalReverse;
        } else {
          /* Outport: '<Root>/TorqueRequest_Nm' */
          Control_model_Y.TorqueRequest_Nm = 0.0F;
        }
        break;
      }
    }
  } else {
    /* case IN_NoFailureDetected: */
    Control_model_NoFailureDetected();
  }

  /* End of Chart: '<Root>/Chart' */

  /* Outport: '<Root>/CAN BUS Fail Mode' */
  Control_model_Y.CANBUSFailMode = rtb_Add;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Control_model_M->rtwLogInfo,
                      (&Control_model_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Control_model_M)!=-1) &&
        !((rtmGetTFinal(Control_model_M)-Control_model_M->Timing.taskTime0) >
          Control_model_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Control_model_M, "Simulation finished");
    }
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
  if (!(++Control_model_M->Timing.clockTick0)) {
    ++Control_model_M->Timing.clockTickH0;
  }

  Control_model_M->Timing.taskTime0 = Control_model_M->Timing.clockTick0 *
    Control_model_M->Timing.stepSize0 + Control_model_M->Timing.clockTickH0 *
    Control_model_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Control_model_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Control_model_M, 0,
                sizeof(RT_MODEL_Control_model_T));
  rtmSetTFinal(Control_model_M, 10.0);
  Control_model_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Control_model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Control_model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Control_model_M->rtwLogInfo, (NULL));
    rtliSetLogT(Control_model_M->rtwLogInfo, "tout");
    rtliSetLogX(Control_model_M->rtwLogInfo, "");
    rtliSetLogXFinal(Control_model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Control_model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Control_model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Control_model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Control_model_M->rtwLogInfo, 1);
    rtliSetLogY(Control_model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Control_model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Control_model_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Control_model_B), 0,
                sizeof(B_Control_model_T));

  {
    Control_model_B.Switch1 = Park;
  }

  /* states (dwork) */
  (void) memset((void *)&Control_model_DW, 0,
                sizeof(DW_Control_model_T));

  /* external inputs */
  (void)memset(&Control_model_U, 0, sizeof(ExtU_Control_model_T));

  /* external outputs */
  (void)memset(&Control_model_Y, 0, sizeof(ExtY_Control_model_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Control_model_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Control_model_M), Control_model_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Control_model_M)));

  /* SystemInitialize for Chart: '<Root>/PedalVoter' */
  Control_model_B.out = 0.0F;

  /* SystemInitialize for Outport: '<Root>/Sensor Fail Mode' incorporates:
   *  Chart: '<Root>/PedalVoter'
   */
  Control_model_Y.SensorFailMode = 0;

  /* SystemInitialize for Chart: '<Root>/PedalVoter' */
  Control_model_DW.Tolerance = 0.001F;
  Control_model_DW.is_active_c2_Control_model = 0U;
  Control_model_DW.is_c2_Control_model = Control_mode_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Outport: '<Root>/AutomaticTransmissionState' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Control_model_Y.AutomaticTransmissionState = Park;

  /* SystemInitialize for Outport: '<Root>/TorqueRequest_Nm' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Control_model_Y.TorqueRequest_Nm = 0.0F;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  Control_model_DW.sumError = 0.0F;
  Control_model_DW.is_active_c3_Control_model = 0U;
  Control_model_DW.is_c3_Control_model = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_LimpMode = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_Drive = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_Reverse = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_NoFailureDetected = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_Brake = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_BrakeNormal = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_Drive_f = Control_mode_IN_NO_ACTIVE_CHILD;
  Control_model_DW.is_Reverse_f = Control_mode_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void Control_model_terminate(void)
{
  /* (no terminate code required) */
}
