/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Master_control_fuzzy_standalone_new_private.h
 *
 * Code generated for Simulink model 'Master_control_fuzzy_standalone_new'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Dec  4 10:53:17 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Master_control_fuzzy_standalone_new_private_h_
#define RTW_HEADER_Master_control_fuzzy_standalone_new_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Master_control_fuzzy_standalone_new.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void imu_mpu_6050_Start_wrapper(real_T *xD);
  extern void imu_mpu_6050_Outputs_wrapper(int16_T *ax,
    int16_T *ay,
    int16_T *az,
    int16_T *temp,
    int16_T *gx,
    int16_T *gy,
    int16_T *gz,
    const real_T *xD);
  extern void imu_mpu_6050_Update_wrapper(int16_T *ax,
    int16_T *ay,
    int16_T *az,
    int16_T *temp,
    int16_T *gx,
    int16_T *gy,
    int16_T *gz,
    real_T *xD);
  extern void imu_mpu_6050_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void pin_5_PWM_Start_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_5_PWM_Outputs_wrapper(const real_T *inp,
    const real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_5_PWM_Update_wrapper(const real_T *inp,
    real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_5_PWM_Terminate_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void pin_4_PWM_Start_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_4_PWM_Outputs_wrapper(const real_T *inp,
    const real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_4_PWM_Update_wrapper(const real_T *inp,
    real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_4_PWM_Terminate_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void pin_3_PWM_Start_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_3_PWM_Outputs_wrapper(const real_T *inp,
    const real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_3_PWM_Update_wrapper(const real_T *inp,
    real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_3_PWM_Terminate_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void pin_6_PWM_Start_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_6_PWM_Outputs_wrapper(const real_T *inp,
    const real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_6_PWM_Update_wrapper(const real_T *inp,
    real_T *xD,
    const real_T *pin, const int_T p_width0);
  extern void pin_6_PWM_Terminate_wrapper(real_T *xD,
    const real_T *pin, const int_T p_width0);

#ifdef __cplusplus

}
#endif

extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void Master_contro_IfActionSubsystem(real_T *rty_dfn,
  P_IfActionSubsystem_Master_co_T *localP);
extern void Master_control_f_MATLABFunction(real_T rtu_x1, real_T rtu_x2, real_T
  *rty_U, B_MATLABFunction_Master_contr_T *localB);
extern void Master_control__MovingRMS3_Init(DW_MovingRMS3_Master_control__T
  *localDW);
extern void Master_control_MovingRMS3_Start(DW_MovingRMS3_Master_control__T
  *localDW, P_MovingRMS3_Master_control_f_T *localP);
extern void Master_control_fuzzy_MovingRMS3(real_T rtu_0,
  B_MovingRMS3_Master_control_f_T *localB, DW_MovingRMS3_Master_control__T
  *localDW, P_MovingRMS3_Master_control_f_T *localP);
extern void Master_control__MovingRMS3_Term(DW_MovingRMS3_Master_control__T
  *localDW);

#endif           /* RTW_HEADER_Master_control_fuzzy_standalone_new_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
