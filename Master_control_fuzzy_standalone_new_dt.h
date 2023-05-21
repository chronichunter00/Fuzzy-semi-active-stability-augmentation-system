/*
 * Master_control_fuzzy_standalone_new_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Master_control_fuzzy_standalone_new".
 *
 * Model version              : 1.32
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Fri Dec  4 10:53:17 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(struct_RLwwwx5fU9j70IauvHUAxB),
  sizeof(struct_RCP1oovUDF2zF6C9vcJmtG),
  sizeof(struct_OTlcYhhT3UxB0PEhAC2ANE),
  sizeof(struct_JoRshoep8ejMwFGpwcoIXD),
  sizeof(codertarget_arduinobase_inter_T),
  sizeof(e_codertarget_arduinobase_int_T),
  sizeof(dsp_simulink_MovingRMS_Master_T),
  sizeof(e_dsp_private_ExponentialMovi_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "struct_RLwwwx5fU9j70IauvHUAxB",
  "struct_RCP1oovUDF2zF6C9vcJmtG",
  "struct_OTlcYhhT3UxB0PEhAC2ANE",
  "struct_JoRshoep8ejMwFGpwcoIXD",
  "codertarget_arduinobase_inter_T",
  "e_codertarget_arduinobase_int_T",
  "dsp_simulink_MovingRMS_Master_T",
  "e_dsp_private_ExponentialMovi_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Master_control_fuzzy_standalo_B.Diff), 0, 0, 90 },

  { (char_T *)(&Master_control_fuzzy_standalo_B.mpu6050_o1), 4, 0, 7 },

  { (char_T *)(&Master_control_fuzzy_standalo_B.MovingRMS.MovingRMS3), 0, 0, 1 },

  { (char_T *)(&Master_control_fuzzy_standalo_B.MovingRMS1.MovingRMS3), 0, 0, 1
  },

  { (char_T *)(&Master_control_fuzzy_standalo_B.MovingRMS2.MovingRMS3), 0, 0, 1
  },

  { (char_T *)(&Master_control_fuzzy_standalo_B.MovingRMS3.MovingRMS3), 0, 0, 1
  }
  ,

  { (char_T *)(&Master_control_fuzzy_standal_DW.obj), 18, 0, 12 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.gobj_0), 19, 0, 48 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.LPFl1_states), 0, 0, 106 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.ToWorkspace2_PWORK.LoggedData),
    11, 0, 34 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.Ifloop_ActiveSubsystem), 2, 0,
    11 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.objisempty), 8, 0, 12 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS.obj), 20, 0, 1 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS.gobj_0), 21, 0, 2 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS.objisempty), 8, 0, 1 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS1.obj), 20, 0, 1 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS1.gobj_0), 21, 0, 2 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS1.objisempty), 8, 0, 1
  },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS2.obj), 20, 0, 1 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS2.gobj_0), 21, 0, 2 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS2.objisempty), 8, 0, 1
  },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS3.obj), 20, 0, 1 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS3.gobj_0), 21, 0, 2 },

  { (char_T *)(&Master_control_fuzzy_standal_DW.MovingRMS3.objisempty), 8, 0, 1
  },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem_n.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem_f.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem_ej.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem_b.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standal_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  32U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Master_control_fuzzy_standalo_P.frontright_D), 0, 0, 598 },

  { (char_T *)(&Master_control_fuzzy_standalo_P.Delay1_DelayLength), 7, 0, 2 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.MovingRMS.MovingRMS3_ForgettingFactor), 0,
    0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.MovingRMS1.MovingRMS3_ForgettingFactor), 0,
    0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.MovingRMS2.MovingRMS3_ForgettingFactor), 0,
    0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.MovingRMS3.MovingRMS3_ForgettingFactor), 0,
    0, 1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.IfActionSubsystem_c.Constant_Value), 0, 0,
    1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.IfActionSubsystem_p.Constant_Value), 0, 0,
    1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.IfActionSubsystem_n.Constant_Value), 0, 0,
    1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.IfActionSubsystem_f.Constant_Value), 0, 0,
    1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.IfActionSubsystem_ej.Constant_Value), 0, 0,
    1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.IfActionSubsystem_e.Constant_Value), 0, 0,
    1 },

  { (char_T *)
    (&Master_control_fuzzy_standalo_P.IfActionSubsystem_b.Constant_Value), 0, 0,
    1 },

  { (char_T *)(&Master_control_fuzzy_standalo_P.IfActionSubsystem.Constant_Value),
    0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  14U,
  rtPTransitions
};

/* [EOF] Master_control_fuzzy_standalone_new_dt.h */
