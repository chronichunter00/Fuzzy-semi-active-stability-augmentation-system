/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Master_control_fuzzy_standalone_new.h
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

#ifndef RTW_HEADER_Master_control_fuzzy_standalone_new_h_
#define RTW_HEADER_Master_control_fuzzy_standalone_new_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Master_control_fuzzy_standalone_new_COMMON_INCLUDES_
# define Master_control_fuzzy_standalone_new_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_AnalogIn.h"
#endif                /* Master_control_fuzzy_standalone_new_COMMON_INCLUDES_ */

#include "Master_control_fuzzy_standalone_new_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
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

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#define Master_control_fuzzy_standalone_new_M (Master_control_fuzzy_standal_M)

/* Block states (default storage) for system '<S1>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S1>/If Action Subsystem' */
} DW_IfActionSubsystem_Master_c_T;

/* Block signals for system '<S5>/MATLAB Function' */
typedef struct {
  real_T fl[9];
  real_T fu[9];
  real_T lmfZ;
  real_T umfZ;
  real_T lmfP;
  real_T umfP;
  real_T uluL_num;
} B_MATLABFunction_Master_contr_T;

/* Block signals for system '<S51>/Moving RMS3' */
typedef struct {
  real_T MovingRMS3;                   /* '<S51>/Moving RMS3' */
} B_MovingRMS3_Master_control_f_T;

/* Block states (default storage) for system '<S51>/Moving RMS3' */
typedef struct {
  dsp_simulink_MovingRMS_Master_T obj; /* '<S51>/Moving RMS3' */
  e_dsp_private_ExponentialMovi_T gobj_0;/* '<S51>/Moving RMS3' */
  e_dsp_private_ExponentialMovi_T gobj_1;/* '<S51>/Moving RMS3' */
  boolean_T objisempty;                /* '<S51>/Moving RMS3' */
} DW_MovingRMS3_Master_control__T;

/* Block signals (default storage) */
typedef struct {
  real_T outputMFCache[450];
  real_T aggregatedOutputs[150];       /* '<S56>/Evaluate Rule Consequents' */
  real_T outputSamplePoints[50];
  real_T dv0[50];
  real_T inputMFCache[9];
  real_T antecedentOutputs[9];         /* '<S56>/Evaluate Rule Antecedents' */
  real_T TmpSignalConversionAtSFunct[3];/* '<S56>/Evaluate Rule Consequents' */
  real_T outputMFCache_m[2];
  real_T rtb_aggregatedOutputs_c[2];
  real_T Diff;                         /* '<S239>/Diff' */
  real_T sd1;                          /* '<S5>/s.d1' */
  real_T VACC_FL;                      /* '<S9>/Product1' */
  real_T VACCFR;                       /* '<S9>/Product2' */
  real_T VACCRL_;                      /* '<S9>/Product3' */
  real_T VACC_RR;                      /* '<S9>/Product4' */
  real_T Gain3;                        /* '<S9>/Gain3' */
  real_T HEAVE_VEL1;                   /* '<S9>/HEAVE_VEL1' */
  real_T Add1;                         /* '<S9>/Add1' */
  real_T sd;                           /* '<S5>/s.d' */
  real_T Add1_h;                       /* '<S5>/Add1' */
  real_T Diff_e;                       /* '<S237>/Diff' */
  real_T sd1_i;                        /* '<S8>/s.d1' */
  real_T Gain4;                        /* '<S9>/Gain4' */
  real_T HEAVE_VEL2;                   /* '<S9>/HEAVE_VEL2' */
  real_T sd_k;                         /* '<S8>/s.d' */
  real_T Add1_ha;                      /* '<S8>/Add1' */
  real_T Diff_l;                       /* '<S240>/Diff' */
  real_T sd1_p;                        /* '<S7>/s.d1' */
  real_T Gain5;                        /* '<S9>/Gain5' */
  real_T HEAVE_VEL3;                   /* '<S9>/HEAVE_VEL3' */
  real_T sd_a;                         /* '<S7>/s.d' */
  real_T Add1_m;                       /* '<S7>/Add1' */
  real_T Diff_p;                       /* '<S238>/Diff' */
  real_T sd1_n;                        /* '<S6>/s.d1' */
  real_T Gain6;                        /* '<S9>/Gain6' */
  real_T HEAVE_VEL4;                   /* '<S9>/HEAVE_VEL4' */
  real_T sd_j;                         /* '<S6>/s.d' */
  real_T Add1_k;                       /* '<S6>/Add1' */
  real_T TmpSignalConversionAtToWorkspac[8];
  real_T Gain;                         /* '<Root>/Gain' */
  real_T HEAVE_VEL;                    /* '<S9>/HEAVE_VEL' */
  real_T HEAVE_disp;                   /* '<S9>/HEAVE_disp' */
  real_T Divide3;                      /* '<S17>/Divide3' */
  real_T gx;                           /* '<S17>/gx' */
  real_T Divide;                       /* '<S17>/Divide' */
  real_T roll;                         /* '<S148>/roll' */
  real_T Add4;                         /* '<S17>/Add4' */
  real_T Add9;                         /* '<S17>/Add9' */
  real_T roll_i;                       /* '<Root>/Saturation1' */
  real_T Diff_c;                       /* '<S49>/Diff' */
  real_T Divide4;                      /* '<S17>/Divide4' */
  real_T gy;                           /* '<S17>/gy' */
  real_T pitch;                        /* '<S148>/pitch' */
  real_T Add2;                         /* '<S17>/Add2' */
  real_T Add8;                         /* '<S17>/Add8' */
  real_T Pitch;                        /* '<Root>/Saturation' */
  real_T Diff_d;                       /* '<S48>/Diff' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T TmpSignalConversionAtToWorksp_o[7];
  real_T TmpSignalConversionAtToWorksp_g[4];
  real_T Dfl2;                         /* '<Root>/Df l2' */
  real_T Saturation;                   /* '<S6>/Saturation' */
  real_T L1;                           /* '<S10>/L1' */
  real_T Saturation_c;                 /* '<S5>/Saturation' */
  real_T DFl1;                         /* '<Root>/DF l1' */
  real_T Divide6;                      /* '<S17>/Divide6' */
  real_T uDLookupTable4;               /* '<Root>/1-D Lookup Table4' */
  real_T Saturation_m;                 /* '<S140>/Saturation' */
  real_T uDLookupTable2;               /* '<Root>/1-D Lookup Table2' */
  real_T Saturation_cm;                /* '<S185>/Saturation' */
  real_T uDLookupTable5;               /* '<Root>/1-D Lookup Table5' */
  real_T Saturation_c1;                /* '<S229>/Saturation' */
  real_T Merge;                        /* '<S1>/Merge' */
  real_T uDLookupTable;                /* '<Root>/1-D Lookup Table' */
  real_T Saturation_e;                 /* '<S96>/Saturation' */
  real_T uDLookupTable2_o;             /* '<S14>/1-D Lookup Table2' */
  real_T uDLookupTable2_ov;            /* '<S13>/1-D Lookup Table2' */
  real_T uDLookupTable2_p;             /* '<S12>/1-D Lookup Table2' */
  real_T uDLookupTable2_c;             /* '<S11>/1-D Lookup Table2' */
  real_T Add2_b;                       /* '<S52>/Add2' */
  real_T Add1_n;                       /* '<S52>/Add1' */
  real_T Add3;                         /* '<S52>/Add3' */
  real_T Add4_n;                       /* '<S52>/Add4' */
  real_T Product2;                     /* '<S11>/Product2' */
  real_T Integrator_i;                 /* '<S178>/Integrator' */
  real_T SignPreSat_i;                 /* '<S215>/SignPreSat' */
  real_T SignPreSat_m;                 /* '<S126>/SignPreSat' */
  real_T Filter_ny;                    /* '<S128>/Filter' */
  real_T d0;
  real_T Switch_k;                     /* '<S126>/Switch' */
  real_T Switch_g;                     /* '<S171>/Switch' */
  real_T Switch_e;                     /* '<S215>/Switch' */
  real_T SignPreIntegrator;            /* '<S126>/SignPreIntegrator' */
  real_T LPF6;                         /* '<S9>/LPF6' */
  real_T Switch;                       /* '<S82>/Switch' */
  real_T IntegralGain_e;               /* '<S219>/Integral Gain' */
  real_T IntegralGain_a;               /* '<S175>/Integral Gain' */
  real_T IntegralGain_d;               /* '<S130>/Integral Gain' */
  real_T TSamp_k;                      /* '<S55>/TSamp' */
  real_T TSamp_ga;                     /* '<S54>/TSamp' */
  real_T TSamp_j;                      /* '<S53>/TSamp' */
  real_T TSamp;                        /* '<S239>/TSamp' */
  real_T LPF2;                         /* '<S5>/LPF2' */
  real_T LPF2_d;                       /* '<S9>/LPF2' */
  real_T LPF1;                         /* '<S5>/LPF1' */
  real_T TSamp_o;                      /* '<S237>/TSamp' */
  real_T LPF2_b;                       /* '<S8>/LPF2' */
  real_T LPF3;                         /* '<S9>/LPF3' */
  real_T LPF1_g;                       /* '<S8>/LPF1' */
  real_T TSamp_g;                      /* '<S240>/TSamp' */
  real_T LPF2_i;                       /* '<S7>/LPF2' */
  real_T LPF4;                         /* '<S9>/LPF4' */
  real_T LPF1_k;                       /* '<S7>/LPF1' */
  real_T TSamp_e;                      /* '<S238>/TSamp' */
  real_T LPF2_a;                       /* '<S6>/LPF2' */
  real_T LPF5;                         /* '<S9>/LPF5' */
  real_T LPF1_ki;                      /* '<S6>/LPF1' */
  real_T LPF1_j;                       /* '<S9>/LPF1' */
  real_T TSamp_l;                      /* '<S49>/TSamp' */
  real_T TSamp_m;                      /* '<S48>/TSamp' */
  real_T Add2_k;                       /* '<S9>/Add2' */
  real_T Integrator_e;                 /* '<S133>/Integrator' */
  real_T Add3_c;                       /* '<S9>/Add3' */
  real_T roll_b;                       /* '<S6>/Saturation1' */
  real_T roll_b_p;                     /* '<S6>/Saturation2' */
  real_T FilterCoefficient;            /* '<S136>/Filter Coefficient' */
  real_T FilterCoefficient_b;          /* '<S181>/Filter Coefficient' */
  real_T FilterCoefficient_l;          /* '<S225>/Filter Coefficient' */
  real_T FilterCoefficient_br;         /* '<S92>/Filter Coefficient' */
  real_T a;
  real_T b;
  real_T c;
  int32_T ruleID;
  int32_T outputID;
  int32_T sampleID;
  int32_T q0;
  int32_T q1;
  int32_T rtb_aggregatedOutputs_tmp;
  int32_T i0;
  int32_T i;
  int32_T u0;
  int32_T u1;
  int16_T mpu6050_o1;                  /* '<S17>/mpu6050' */
  int16_T mpu6050_o2;                  /* '<S17>/mpu6050' */
  int16_T mpu6050_o3;                  /* '<S17>/mpu6050' */
  int16_T mpu6050_o4;                  /* '<S17>/mpu6050' */
  int16_T mpu6050_o5;                  /* '<S17>/mpu6050' */
  int16_T mpu6050_o6;                  /* '<S17>/mpu6050' */
  int16_T mpu6050_o7;                  /* '<S17>/mpu6050' */
  B_MovingRMS3_Master_control_f_T MovingRMS;/* '<S51>/Moving RMS3' */
  B_MovingRMS3_Master_control_f_T MovingRMS1;/* '<S51>/Moving RMS3' */
  B_MovingRMS3_Master_control_f_T MovingRMS2;/* '<S51>/Moving RMS3' */
  B_MovingRMS3_Master_control_f_T MovingRMS3;/* '<S51>/Moving RMS3' */
  B_MATLABFunction_Master_contr_T sf_MATLABFunction_nb;/* '<S8>/MATLAB Function' */
  B_MATLABFunction_Master_contr_T sf_MATLABFunction_d;/* '<S7>/MATLAB Function' */
  B_MATLABFunction_Master_contr_T sf_MATLABFunction_n;/* '<S6>/MATLAB Function' */
  B_MATLABFunction_Master_contr_T sf_MATLABFunction;/* '<S5>/MATLAB Function' */
} B_Master_control_fuzzy_standa_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S23>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_k;/* '<S22>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_e;/* '<S21>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_p;/* '<S20>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_a;/* '<S14>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_n;/* '<S13>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_ku;/* '<S12>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_i;/* '<S11>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_ku2;/* '<S9>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_er;/* '<S9>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_kt;/* '<S9>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_io;/* '<S9>/Analog Input4' */
  e_codertarget_arduinobase_int_T gobj_0;/* '<S23>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_1;/* '<S23>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_2;/* '<S23>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_3;/* '<S23>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_0_h;/* '<S22>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_1_h;/* '<S22>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_2_i;/* '<S22>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_3_j;/* '<S22>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_0_n;/* '<S21>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_1_b;/* '<S21>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_2_o;/* '<S21>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_3_n;/* '<S21>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_0_c;/* '<S20>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_1_n;/* '<S20>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_2_m;/* '<S20>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_3_i;/* '<S20>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_0_o;/* '<S14>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_1_nn;/* '<S14>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_2_in;/* '<S14>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_3_p;/* '<S14>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_0_h2;/* '<S13>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_1_f;/* '<S13>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_2_e;/* '<S13>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_3_h;/* '<S13>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_0_j;/* '<S12>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_1_o;/* '<S12>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_2_d;/* '<S12>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_3_no;/* '<S12>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_0_oz;/* '<S11>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_1_e;/* '<S11>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_2_mo;/* '<S11>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_3_jg;/* '<S11>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_0_k;/* '<S9>/Analog Input2' */
  e_codertarget_arduinobase_int_T gobj_1_oe;/* '<S9>/Analog Input2' */
  e_codertarget_arduinobase_int_T gobj_2_g;/* '<S9>/Analog Input2' */
  e_codertarget_arduinobase_int_T gobj_3_jo;/* '<S9>/Analog Input2' */
  e_codertarget_arduinobase_int_T gobj_0_m;/* '<S9>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_1_c;/* '<S9>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_2_f;/* '<S9>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_3_iv;/* '<S9>/Analog Input1' */
  e_codertarget_arduinobase_int_T gobj_0_ng;/* '<S9>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_1_g;/* '<S9>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_2_a;/* '<S9>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_3_n2;/* '<S9>/Analog Input3' */
  e_codertarget_arduinobase_int_T gobj_0_i;/* '<S9>/Analog Input4' */
  e_codertarget_arduinobase_int_T gobj_1_l;/* '<S9>/Analog Input4' */
  e_codertarget_arduinobase_int_T gobj_2_du;/* '<S9>/Analog Input4' */
  e_codertarget_arduinobase_int_T gobj_3_hl;/* '<S9>/Analog Input4' */
  real_T LPFl1_states;                 /* '<S22>/LPFl1' */
  real_T UD_DSTATE;                    /* '<S239>/UD' */
  real_T HF2_states;                   /* '<S5>/H.F2' */
  real_T LPF2_states;                  /* '<S5>/LPF2' */
  real_T sd1_DSTATE;                   /* '<S5>/s.d1' */
  real_T HF2_states_a;                 /* '<S9>/H.F2' */
  real_T LPF2_states_e;                /* '<S9>/LPF2' */
  real_T HEAVE_VEL1_DSTATE;            /* '<S9>/HEAVE_VEL1' */
  real_T HF1_states;                   /* '<S5>/H.F1' */
  real_T LPF1_states;                  /* '<S5>/LPF1' */
  real_T sd_DSTATE;                    /* '<S5>/s.d' */
  real_T LPFr1_states;                 /* '<S20>/LPFr1' */
  real_T UD_DSTATE_h;                  /* '<S237>/UD' */
  real_T HF2_states_m;                 /* '<S8>/H.F2' */
  real_T LPF2_states_j;                /* '<S8>/LPF2' */
  real_T sd1_DSTATE_c;                 /* '<S8>/s.d1' */
  real_T HF3_states;                   /* '<S9>/H.F3' */
  real_T LPF3_states;                  /* '<S9>/LPF3' */
  real_T HEAVE_VEL2_DSTATE;            /* '<S9>/HEAVE_VEL2' */
  real_T HF1_states_e;                 /* '<S8>/H.F1' */
  real_T LPF1_states_f;                /* '<S8>/LPF1' */
  real_T sd_DSTATE_f;                  /* '<S8>/s.d' */
  real_T l2_states;                    /* '<S23>/l2' */
  real_T UD_DSTATE_o;                  /* '<S240>/UD' */
  real_T HF2_states_b;                 /* '<S7>/H.F2' */
  real_T LPF2_states_m;                /* '<S7>/LPF2' */
  real_T sd1_DSTATE_k;                 /* '<S7>/s.d1' */
  real_T HF4_states;                   /* '<S9>/H.F4' */
  real_T LPF4_states;                  /* '<S9>/LPF4' */
  real_T HEAVE_VEL3_DSTATE;            /* '<S9>/HEAVE_VEL3' */
  real_T HF1_states_i;                 /* '<S7>/H.F1' */
  real_T LPF1_states_a;                /* '<S7>/LPF1' */
  real_T sd_DSTATE_h;                  /* '<S7>/s.d' */
  real_T r2_states;                    /* '<S21>/r2' */
  real_T UD_DSTATE_f;                  /* '<S238>/UD' */
  real_T HF2_states_j;                 /* '<S6>/H.F2' */
  real_T LPF2_states_b;                /* '<S6>/LPF2' */
  real_T sd1_DSTATE_i;                 /* '<S6>/s.d1' */
  real_T HF5_states;                   /* '<S9>/H.F5' */
  real_T LPF5_states;                  /* '<S9>/LPF5' */
  real_T HEAVE_VEL4_DSTATE;            /* '<S9>/HEAVE_VEL4' */
  real_T HF1_states_g;                 /* '<S6>/H.F1' */
  real_T LPF1_states_g;                /* '<S6>/LPF1' */
  real_T sd_DSTATE_m;                  /* '<S6>/s.d' */
  real_T mpu6050_DSTATE;               /* '<S17>/mpu6050' */
  real_T HF_states;                    /* '<S9>/H.F' */
  real_T LPF6_states;                  /* '<S9>/LPF6' */
  real_T HEAVE_VEL_DSTATE;             /* '<S9>/HEAVE_VEL' */
  real_T HF1_states_k;                 /* '<S9>/H.F1' */
  real_T LPF1_states_h;                /* '<S9>/LPF1' */
  real_T HEAVE_disp_DSTATE;            /* '<S9>/HEAVE_disp' */
  real_T Delay1_DSTATE;                /* '<S17>/Delay1' */
  real_T UD_DSTATE_g;                  /* '<S49>/UD' */
  real_T Delay_DSTATE;                 /* '<S17>/Delay' */
  real_T UD_DSTATE_c;                  /* '<S48>/UD' */
  real_T UD_DSTATE_cy;                 /* '<S53>/UD' */
  real_T UD_DSTATE_e;                  /* '<S54>/UD' */
  real_T UD_DSTATE_e2;                 /* '<S55>/UD' */
  real_T Integrator_DSTATE;            /* '<S133>/Integrator' */
  real_T Filter_DSTATE;                /* '<S128>/Filter' */
  real_T PWM_F_R_DSTATE;               /* '<Root>/PWM_F_R' */
  real_T Integrator_DSTATE_e;          /* '<S178>/Integrator' */
  real_T Filter_DSTATE_o;              /* '<S173>/Filter' */
  real_T PWM_R_L_DSTATE;               /* '<Root>/PWM_R_L' */
  real_T Integrator_DSTATE_b;          /* '<S222>/Integrator' */
  real_T Filter_DSTATE_i;              /* '<S217>/Filter' */
  real_T PWM_R_R_DSTATE;               /* '<Root>/PWM_R_R' */
  real_T Integrator_DSTATE_g;          /* '<S89>/Integrator' */
  real_T Filter_DSTATE_n;              /* '<S84>/Filter' */
  real_T pwm_fL_DSTATE;                /* '<Root>/pwm_fL' */
  real_T LPF_states;                   /* '<S14>/LPF' */
  real_T LPF_states_f;                 /* '<S13>/LPF' */
  real_T LPF_states_g;                 /* '<S12>/LPF' */
  real_T LPF_states_o;                 /* '<S11>/LPF' */
  real_T LPFl1_tmp;                    /* '<S22>/LPFl1' */
  real_T HF2_tmp;                      /* '<S5>/H.F2' */
  real_T LPF2_tmp;                     /* '<S5>/LPF2' */
  real_T HF2_tmp_k;                    /* '<S9>/H.F2' */
  real_T LPF2_tmp_i;                   /* '<S9>/LPF2' */
  real_T HF1_tmp;                      /* '<S5>/H.F1' */
  real_T LPF1_tmp;                     /* '<S5>/LPF1' */
  real_T LPFr1_tmp;                    /* '<S20>/LPFr1' */
  real_T HF2_tmp_e;                    /* '<S8>/H.F2' */
  real_T LPF2_tmp_h;                   /* '<S8>/LPF2' */
  real_T HF3_tmp;                      /* '<S9>/H.F3' */
  real_T LPF3_tmp;                     /* '<S9>/LPF3' */
  real_T HF1_tmp_o;                    /* '<S8>/H.F1' */
  real_T LPF1_tmp_n;                   /* '<S8>/LPF1' */
  real_T l2_tmp;                       /* '<S23>/l2' */
  real_T HF2_tmp_o;                    /* '<S7>/H.F2' */
  real_T LPF2_tmp_il;                  /* '<S7>/LPF2' */
  real_T HF4_tmp;                      /* '<S9>/H.F4' */
  real_T LPF4_tmp;                     /* '<S9>/LPF4' */
  real_T HF1_tmp_k;                    /* '<S7>/H.F1' */
  real_T LPF1_tmp_o;                   /* '<S7>/LPF1' */
  real_T r2_tmp;                       /* '<S21>/r2' */
  real_T HF2_tmp_g;                    /* '<S6>/H.F2' */
  real_T LPF2_tmp_hp;                  /* '<S6>/LPF2' */
  real_T HF5_tmp;                      /* '<S9>/H.F5' */
  real_T LPF5_tmp;                     /* '<S9>/LPF5' */
  real_T HF1_tmp_h;                    /* '<S6>/H.F1' */
  real_T LPF1_tmp_h;                   /* '<S6>/LPF1' */
  real_T HF_tmp;                       /* '<S9>/H.F' */
  real_T LPF6_tmp;                     /* '<S9>/LPF6' */
  real_T HF1_tmp_a;                    /* '<S9>/H.F1' */
  real_T LPF1_tmp_i;                   /* '<S9>/LPF1' */
  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope18_PWORK;                     /* '<Root>/Scope18' */

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     /* '<Root>/Scope13' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope14_PWORK;                     /* '<Root>/Scope14' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_g;                    /* '<S17>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope7_PWORK;                      /* '<S17>/Scope7' */

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     /* '<S148>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S17>/Scope' */

  struct {
    void *LoggedData;
  } Scope16_PWORK;                     /* '<Root>/Scope16' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_c;                    /* '<S17>/Scope3' */

  struct {
    void *LoggedData[3];
  } Scope2_PWORK;                      /* '<S17>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_p;                    /* '<S148>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_f;                    /* '<S9>/Scope2' */

  struct {
    void *LoggedData;
  } Scope15_PWORK;                     /* '<Root>/Scope15' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope7_PWORK_j;                    /* '<Root>/Scope7' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<Root>/Scope10' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<Root>/Scope8' */

  struct {
    void *LoggedData;
  } TimeScope1_PWORK;                  /* '<Root>/Time Scope1' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<Root>/Scope9' */

  struct {
    void *LoggedData;
  } Scope17_PWORK;                     /* '<Root>/Scope17' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S9>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S9>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_c;                    /* '<Root>/Scope2' */

  int8_T Ifloop_ActiveSubsystem;       /* '<S50>/If loop ' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S50>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S50>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S45>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_c;/* '<S41>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S37>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_n;/* '<S33>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_f;/* '<S4>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_j;/* '<S3>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_b;/* '<S2>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRan_fz;/* '<S1>/If Action Subsystem1' */
  boolean_T objisempty;                /* '<S23>/Analog Input3' */
  boolean_T objisempty_l;              /* '<S22>/Analog Input3' */
  boolean_T objisempty_o;              /* '<S21>/Analog Input3' */
  boolean_T objisempty_f;              /* '<S20>/Analog Input3' */
  boolean_T objisempty_c;              /* '<S14>/Analog Input1' */
  boolean_T objisempty_b;              /* '<S13>/Analog Input1' */
  boolean_T objisempty_bk;             /* '<S12>/Analog Input1' */
  boolean_T objisempty_i;              /* '<S11>/Analog Input1' */
  boolean_T objisempty_m;              /* '<S9>/Analog Input2' */
  boolean_T objisempty_g;              /* '<S9>/Analog Input1' */
  boolean_T objisempty_h;              /* '<S9>/Analog Input3' */
  boolean_T objisempty_a;              /* '<S9>/Analog Input4' */
  DW_MovingRMS3_Master_control__T MovingRMS;/* '<S51>/Moving RMS3' */
  DW_MovingRMS3_Master_control__T MovingRMS1;/* '<S51>/Moving RMS3' */
  DW_MovingRMS3_Master_control__T MovingRMS2;/* '<S51>/Moving RMS3' */
  DW_MovingRMS3_Master_control__T MovingRMS3;/* '<S51>/Moving RMS3' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem_c;/* '<S45>/If Action Subsystem' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem_p;/* '<S41>/If Action Subsystem' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem_n;/* '<S37>/If Action Subsystem' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem_f;/* '<S33>/If Action Subsystem' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem_ej;/* '<S4>/If Action Subsystem' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem_e;/* '<S3>/If Action Subsystem' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem_b;/* '<S2>/If Action Subsystem' */
  DW_IfActionSubsystem_Master_c_T IfActionSubsystem;/* '<S1>/If Action Subsystem' */
} DW_Master_control_fuzzy_stand_T;

/* Parameters for system: '<S1>/If Action Subsystem' */
struct P_IfActionSubsystem_Master_co_T_ {
  real_T Constant_Value;               /* Expression: 50
                                        * Referenced by: '<S24>/Constant'
                                        */
};

/* Parameters for system: '<S51>/Moving RMS3' */
struct P_MovingRMS3_Master_control_f_T_ {
  real_T MovingRMS3_ForgettingFactor;  /* Expression: 0.9
                                        * Referenced by: '<S51>/Moving RMS3'
                                        */
};

/* Parameters (default storage) */
struct P_Master_control_fuzzy_standa_T_ {
  real_T frontright_D;                 /* Mask Parameter: frontright_D
                                        * Referenced by: '<S127>/Derivative Gain'
                                        */
  real_T rearleft_D;                   /* Mask Parameter: rearleft_D
                                        * Referenced by: '<S172>/Derivative Gain'
                                        */
  real_T rearright_D;                  /* Mask Parameter: rearright_D
                                        * Referenced by: '<S216>/Derivative Gain'
                                        */
  real_T frontleft_D;                  /* Mask Parameter: frontleft_D
                                        * Referenced by: '<S83>/Derivative Gain'
                                        */
  real_T frontleft_I;                  /* Mask Parameter: frontleft_I
                                        * Referenced by: '<S86>/Integral Gain'
                                        */
  real_T rearright_I;                  /* Mask Parameter: rearright_I
                                        * Referenced by: '<S219>/Integral Gain'
                                        */
  real_T rearleft_I;                   /* Mask Parameter: rearleft_I
                                        * Referenced by: '<S175>/Integral Gain'
                                        */
  real_T frontright_I;                 /* Mask Parameter: frontright_I
                                        * Referenced by: '<S130>/Integral Gain'
                                        */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S239>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevSca_m;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevSca_m
                               * Referenced by: '<S237>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevSca_g;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevSca_g
                               * Referenced by: '<S240>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevSca_j;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevSca_j
                               * Referenced by: '<S238>/UD'
                               */
  real_T DiscreteDerivative5_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative5_ICPrevScale
                               * Referenced by: '<S49>/UD'
                               */
  real_T DiscreteDerivative4_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative4_ICPrevScale
                               * Referenced by: '<S48>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S53>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevSc_mb;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevSc_mb
                               * Referenced by: '<S54>/UD'
                               */
  real_T DiscreteDerivative2_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevScale
                               * Referenced by: '<S55>/UD'
                               */
  real_T frontright_InitialConditionForF;
                              /* Mask Parameter: frontright_InitialConditionForF
                               * Referenced by: '<S128>/Filter'
                               */
  real_T rearleft_InitialConditionForFil;
                              /* Mask Parameter: rearleft_InitialConditionForFil
                               * Referenced by: '<S173>/Filter'
                               */
  real_T rearright_InitialConditionForFi;
                              /* Mask Parameter: rearright_InitialConditionForFi
                               * Referenced by: '<S217>/Filter'
                               */
  real_T frontleft_InitialConditionForFi;
                              /* Mask Parameter: frontleft_InitialConditionForFi
                               * Referenced by: '<S84>/Filter'
                               */
  real_T frontright_InitialConditionForI;
                              /* Mask Parameter: frontright_InitialConditionForI
                               * Referenced by: '<S133>/Integrator'
                               */
  real_T rearleft_InitialConditionForInt;
                              /* Mask Parameter: rearleft_InitialConditionForInt
                               * Referenced by: '<S178>/Integrator'
                               */
  real_T rearright_InitialConditionForIn;
                              /* Mask Parameter: rearright_InitialConditionForIn
                               * Referenced by: '<S222>/Integrator'
                               */
  real_T frontleft_InitialConditionForIn;
                              /* Mask Parameter: frontleft_InitialConditionForIn
                               * Referenced by: '<S89>/Integrator'
                               */
  real_T frontright_LowerSaturationLimit;
                              /* Mask Parameter: frontright_LowerSaturationLimit
                               * Referenced by:
                               *   '<S126>/DeadZone'
                               *   '<S140>/Saturation'
                               */
  real_T rearleft_LowerSaturationLimit;
                                /* Mask Parameter: rearleft_LowerSaturationLimit
                                 * Referenced by:
                                 *   '<S171>/DeadZone'
                                 *   '<S185>/Saturation'
                                 */
  real_T rearright_LowerSaturationLimit;
                               /* Mask Parameter: rearright_LowerSaturationLimit
                                * Referenced by:
                                *   '<S215>/DeadZone'
                                *   '<S229>/Saturation'
                                */
  real_T frontleft_LowerSaturationLimit;
                               /* Mask Parameter: frontleft_LowerSaturationLimit
                                * Referenced by:
                                *   '<S82>/DeadZone'
                                *   '<S96>/Saturation'
                                */
  real_T frontright_N;                 /* Mask Parameter: frontright_N
                                        * Referenced by: '<S136>/Filter Coefficient'
                                        */
  real_T rearleft_N;                   /* Mask Parameter: rearleft_N
                                        * Referenced by: '<S181>/Filter Coefficient'
                                        */
  real_T rearright_N;                  /* Mask Parameter: rearright_N
                                        * Referenced by: '<S225>/Filter Coefficient'
                                        */
  real_T frontleft_N;                  /* Mask Parameter: frontleft_N
                                        * Referenced by: '<S92>/Filter Coefficient'
                                        */
  real_T frontright_P;                 /* Mask Parameter: frontright_P
                                        * Referenced by: '<S138>/Proportional Gain'
                                        */
  real_T rearleft_P;                   /* Mask Parameter: rearleft_P
                                        * Referenced by: '<S183>/Proportional Gain'
                                        */
  real_T rearright_P;                  /* Mask Parameter: rearright_P
                                        * Referenced by: '<S227>/Proportional Gain'
                                        */
  real_T frontleft_P;                  /* Mask Parameter: frontleft_P
                                        * Referenced by: '<S94>/Proportional Gain'
                                        */
  real_T frontright_UpperSaturationLimit;
                              /* Mask Parameter: frontright_UpperSaturationLimit
                               * Referenced by:
                               *   '<S126>/DeadZone'
                               *   '<S140>/Saturation'
                               */
  real_T rearleft_UpperSaturationLimit;
                                /* Mask Parameter: rearleft_UpperSaturationLimit
                                 * Referenced by:
                                 *   '<S171>/DeadZone'
                                 *   '<S185>/Saturation'
                                 */
  real_T rearright_UpperSaturationLimit;
                               /* Mask Parameter: rearright_UpperSaturationLimit
                                * Referenced by:
                                *   '<S215>/DeadZone'
                                *   '<S229>/Saturation'
                                */
  real_T frontleft_UpperSaturationLimit;
                               /* Mask Parameter: frontleft_UpperSaturationLimit
                                * Referenced by:
                                *   '<S82>/DeadZone'
                                *   '<S96>/Saturation'
                                */
  real_T AnalogInput4_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S9>/Analog Input4'
                                        */
  real_T AnalogInput3_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S9>/Analog Input3'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S9>/Analog Input1'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S9>/Analog Input2'
                                        */
  real_T acc_s_rmsFL_Y0;               /* Computed Parameter: acc_s_rmsFL_Y0
                                        * Referenced by: '<S51>/acc_s_rms FL'
                                        */
  real_T acc_s_rmsFR_Y0;               /* Computed Parameter: acc_s_rmsFR_Y0
                                        * Referenced by: '<S51>/acc_s_rmsFR'
                                        */
  real_T acc_s_rmsRL_Y0;               /* Computed Parameter: acc_s_rmsRL_Y0
                                        * Referenced by: '<S51>/acc_s_rms RL'
                                        */
  real_T acc_s_rmsRR_Y0;               /* Computed Parameter: acc_s_rmsRR_Y0
                                        * Referenced by: '<S51>/acc_s_rms RR'
                                        */
  real_T Calib_acc_FL_Y0;              /* Computed Parameter: Calib_acc_FL_Y0
                                        * Referenced by: '<S52>/Calib_acc_FL'
                                        */
  real_T Calib_acc_FR_Y0;              /* Computed Parameter: Calib_acc_FR_Y0
                                        * Referenced by: '<S52>/Calib_acc_FR'
                                        */
  real_T Calib_acc_RL_Y0;              /* Computed Parameter: Calib_acc_RL_Y0
                                        * Referenced by: '<S52>/Calib_acc_RL'
                                        */
  real_T Calib_acc_RR_Y0;              /* Computed Parameter: Calib_acc_RR_Y0
                                        * Referenced by: '<S52>/Calib_acc_RR'
                                        */
  real_T OutputSamplePoints_Value[150];/* Expression: fis.outputSamplePoints
                                        * Referenced by: '<S56>/Output Sample Points'
                                        */
  real_T AnalogInput1_SampleTime_k;    /* Expression: 0.01
                                        * Referenced by: '<S11>/Analog Input1'
                                        */
  real_T LPF_NumCoef;                  /* Expression: [0.1462 ]
                                        * Referenced by: '<S11>/LPF'
                                        */
  real_T LPF_DenCoef[2];               /* Expression: [1 -0.8538]
                                        * Referenced by: '<S11>/LPF'
                                        */
  real_T LPF_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S11>/LPF'
                                        */
  real_T uDLookupTable2_tableData[2];  /* Expression: [1284,2200]
                                        * Referenced by: '<S11>/1-D Lookup Table2'
                                        */
  real_T uDLookupTable2_bp01Data[2];   /* Expression: [0.845,3.3]
                                        * Referenced by: '<S11>/1-D Lookup Table2'
                                        */
  real_T Constant1_Value;              /* Expression: 3.3/4095
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T AnalogInput1_SampleTime_n;    /* Expression: 0.01
                                        * Referenced by: '<S12>/Analog Input1'
                                        */
  real_T LPF_NumCoef_d;                /* Expression: [0.1462 ]
                                        * Referenced by: '<S12>/LPF'
                                        */
  real_T LPF_DenCoef_m[2];             /* Expression: [1 -0.8538]
                                        * Referenced by: '<S12>/LPF'
                                        */
  real_T LPF_InitialStates_g;          /* Expression: 0
                                        * Referenced by: '<S12>/LPF'
                                        */
  real_T uDLookupTable2_tableData_b[2];/* Expression: [1284,2200]
                                        * Referenced by: '<S12>/1-D Lookup Table2'
                                        */
  real_T uDLookupTable2_bp01Data_c[2]; /* Expression: [0.845,3.3]
                                        * Referenced by: '<S12>/1-D Lookup Table2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 3.3/4095
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T AnalogInput1_SampleTime_h;    /* Expression: 0.01
                                        * Referenced by: '<S13>/Analog Input1'
                                        */
  real_T LPF_NumCoef_p;                /* Expression: [0.1462 ]
                                        * Referenced by: '<S13>/LPF'
                                        */
  real_T LPF_DenCoef_b[2];             /* Expression: [1 -0.8538]
                                        * Referenced by: '<S13>/LPF'
                                        */
  real_T LPF_InitialStates_c;          /* Expression: 0
                                        * Referenced by: '<S13>/LPF'
                                        */
  real_T uDLookupTable2_tableData_g[2];/* Expression: [1284,2200]
                                        * Referenced by: '<S13>/1-D Lookup Table2'
                                        */
  real_T uDLookupTable2_bp01Data_p[2]; /* Expression: [0.845,3.3]
                                        * Referenced by: '<S13>/1-D Lookup Table2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 3.3/4095
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T AnalogInput1_SampleTime_i;    /* Expression: 0.01
                                        * Referenced by: '<S14>/Analog Input1'
                                        */
  real_T LPF_NumCoef_j;                /* Expression: [0.1462 ]
                                        * Referenced by: '<S14>/LPF'
                                        */
  real_T LPF_DenCoef_k[2];             /* Expression: [1 -0.8538]
                                        * Referenced by: '<S14>/LPF'
                                        */
  real_T LPF_InitialStates_h;          /* Expression: 0
                                        * Referenced by: '<S14>/LPF'
                                        */
  real_T uDLookupTable2_tableData_k[2];/* Expression: [1284,2200]
                                        * Referenced by: '<S14>/1-D Lookup Table2'
                                        */
  real_T uDLookupTable2_bp01Data_l[2]; /* Expression: [0.845,3.3]
                                        * Referenced by: '<S14>/1-D Lookup Table2'
                                        */
  real_T Constant1_Value_o;            /* Expression: 3.3/4095
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T AnalogInput3_SampleTime_c;    /* Expression: 0.01
                                        * Referenced by: '<S20>/Analog Input3'
                                        */
  real_T AnalogInput3_SampleTime_m;    /* Expression: 0.01
                                        * Referenced by: '<S21>/Analog Input3'
                                        */
  real_T AnalogInput3_SampleTime_mh;   /* Expression: 0.01
                                        * Referenced by: '<S22>/Analog Input3'
                                        */
  real_T AnalogInput3_SampleTime_d;    /* Expression: 0.01
                                        * Referenced by: '<S23>/Analog Input3'
                                        */
  real_T Conversion_volt_Value;        /* Expression: 3.3/4095
                                        * Referenced by: '<S22>/Conversion_volt'
                                        */
  real_T LPFl1_NumCoef[2];             /* Expression: [0.1701 0.1701 ]
                                        * Referenced by: '<S22>/LPFl1'
                                        */
  real_T LPFl1_DenCoef[2];             /* Expression: [1 -0.6598]
                                        * Referenced by: '<S22>/LPFl1'
                                        */
  real_T LPFl1_InitialStates;          /* Expression: 0
                                        * Referenced by: '<S22>/LPFl1'
                                        */
  real_T frontleft_tableData[3];       /* Expression: [0.072, 0,-0.072]
                                        * Referenced by: '<S22>/front left'
                                        */
  real_T frontleft_bp01Data[3];        /* Expression: [0.733,1.606,2.49]
                                        * Referenced by: '<S22>/front left'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S239>/TSamp'
                                        */
  real_T HF2_NumCoef[2];               /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S5>/H.F2'
                                        */
  real_T HF2_DenCoef[2];               /* Expression: [1 -0.9512]
                                        * Referenced by: '<S5>/H.F2'
                                        */
  real_T HF2_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S5>/H.F2'
                                        */
  real_T LPF2_NumCoef[2];              /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S5>/LPF2'
                                        */
  real_T LPF2_DenCoef[2];              /* Expression: [1 -0.2308]
                                        * Referenced by: '<S5>/LPF2'
                                        */
  real_T LPF2_InitialStates;           /* Expression: 0
                                        * Referenced by: '<S5>/LPF2'
                                        */
  real_T sd1_gainval;                  /* Computed Parameter: sd1_gainval
                                        * Referenced by: '<S5>/s.d1'
                                        */
  real_T sd1_IC;                       /* Expression: 0
                                        * Referenced by: '<S5>/s.d1'
                                        */
  real_T Conversion_Value;             /* Expression: 3.3/4095
                                        * Referenced by: '<S9>/Conversion'
                                        */
  real_T Conversion1_Value;            /* Expression: 3.3/4095
                                        * Referenced by: '<S9>/Conversion1'
                                        */
  real_T Conversion2_Value;            /* Expression: 3.3/4095
                                        * Referenced by: '<S9>/Conversion2'
                                        */
  real_T Conversion3_Value;            /* Expression: 3.3/4095
                                        * Referenced by: '<S9>/Conversion3'
                                        */
  real_T Constant9_Value;              /* Expression: 1.25
                                        * Referenced by: '<S9>/Constant9'
                                        */
  real_T Gain3_Gain;                   /* Expression: 9.80665
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T HF2_NumCoef_i[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S9>/H.F2'
                                        */
  real_T HF2_DenCoef_f[2];             /* Expression: [1 -0.9512]
                                        * Referenced by: '<S9>/H.F2'
                                        */
  real_T HF2_InitialStates_c;          /* Expression: 0
                                        * Referenced by: '<S9>/H.F2'
                                        */
  real_T LPF2_NumCoef_o[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S9>/LPF2'
                                        */
  real_T LPF2_DenCoef_g[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S9>/LPF2'
                                        */
  real_T LPF2_InitialStates_b;         /* Expression: 0
                                        * Referenced by: '<S9>/LPF2'
                                        */
  real_T HEAVE_VEL1_gainval;           /* Computed Parameter: HEAVE_VEL1_gainval
                                        * Referenced by: '<S9>/HEAVE_VEL1'
                                        */
  real_T HEAVE_VEL1_IC;                /* Expression: 0
                                        * Referenced by: '<S9>/HEAVE_VEL1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0.02
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T HF1_NumCoef[2];               /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S5>/H.F1'
                                        */
  real_T HF1_DenCoef[2];               /* Expression: [1 -0.9512]
                                        * Referenced by: '<S5>/H.F1'
                                        */
  real_T HF1_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S5>/H.F1'
                                        */
  real_T LPF1_NumCoef[2];              /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S5>/LPF1'
                                        */
  real_T LPF1_DenCoef[2];              /* Expression: [1 -0.2308]
                                        * Referenced by: '<S5>/LPF1'
                                        */
  real_T LPF1_InitialStates;           /* Expression: 0
                                        * Referenced by: '<S5>/LPF1'
                                        */
  real_T sd_gainval;                   /* Computed Parameter: sd_gainval
                                        * Referenced by: '<S5>/s.d'
                                        */
  real_T sd_IC;                        /* Expression: 0
                                        * Referenced by: '<S5>/s.d'
                                        */
  real_T Conversion_volt_Value_l;      /* Expression: 3.3/4095
                                        * Referenced by: '<S20>/Conversion_volt'
                                        */
  real_T LPFr1_NumCoef[2];             /* Expression: [0.1701 0.1701 ]
                                        * Referenced by: '<S20>/LPFr1'
                                        */
  real_T LPFr1_DenCoef[2];             /* Expression: [1 -0.6598]
                                        * Referenced by: '<S20>/LPFr1'
                                        */
  real_T LPFr1_InitialStates;          /* Expression: 0
                                        * Referenced by: '<S20>/LPFr1'
                                        */
  real_T frontright_tableData[3];      /* Expression: [0.072, 0,-0.072]
                                        * Referenced by: '<S20>/front right'
                                        */
  real_T frontright_bp01Data[3];       /* Expression: [0.7615,1.585,2.42]
                                        * Referenced by: '<S20>/front right'
                                        */
  real_T TSamp_WtEt_o;                 /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S237>/TSamp'
                                        */
  real_T HF2_NumCoef_f[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S8>/H.F2'
                                        */
  real_T HF2_DenCoef_g[2];             /* Expression: [1 -0.9512]
                                        * Referenced by: '<S8>/H.F2'
                                        */
  real_T HF2_InitialStates_p;          /* Expression: 0
                                        * Referenced by: '<S8>/H.F2'
                                        */
  real_T LPF2_NumCoef_c[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S8>/LPF2'
                                        */
  real_T LPF2_DenCoef_j[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S8>/LPF2'
                                        */
  real_T LPF2_InitialStates_k;         /* Expression: 0
                                        * Referenced by: '<S8>/LPF2'
                                        */
  real_T sd1_gainval_m;                /* Computed Parameter: sd1_gainval_m
                                        * Referenced by: '<S8>/s.d1'
                                        */
  real_T sd1_IC_f;                     /* Expression: 0
                                        * Referenced by: '<S8>/s.d1'
                                        */
  real_T Constant2_Value;              /* Expression: 1.25
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 9.80665
                                        * Referenced by: '<S9>/Gain4'
                                        */
  real_T HF3_NumCoef[2];               /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S9>/H.F3'
                                        */
  real_T HF3_DenCoef[2];               /* Expression: [1 -0.9512]
                                        * Referenced by: '<S9>/H.F3'
                                        */
  real_T HF3_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S9>/H.F3'
                                        */
  real_T LPF3_NumCoef[2];              /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S9>/LPF3'
                                        */
  real_T LPF3_DenCoef[2];              /* Expression: [1 -0.2308]
                                        * Referenced by: '<S9>/LPF3'
                                        */
  real_T LPF3_InitialStates;           /* Expression: 0
                                        * Referenced by: '<S9>/LPF3'
                                        */
  real_T HEAVE_VEL2_gainval;           /* Computed Parameter: HEAVE_VEL2_gainval
                                        * Referenced by: '<S9>/HEAVE_VEL2'
                                        */
  real_T HEAVE_VEL2_IC;                /* Expression: 0
                                        * Referenced by: '<S9>/HEAVE_VEL2'
                                        */
  real_T Constant3_Value;              /* Expression: 0.02
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T HF1_NumCoef_c[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S8>/H.F1'
                                        */
  real_T HF1_DenCoef_c[2];             /* Expression: [1 -0.9512]
                                        * Referenced by: '<S8>/H.F1'
                                        */
  real_T HF1_InitialStates_j;          /* Expression: 0
                                        * Referenced by: '<S8>/H.F1'
                                        */
  real_T LPF1_NumCoef_k[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S8>/LPF1'
                                        */
  real_T LPF1_DenCoef_i[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S8>/LPF1'
                                        */
  real_T LPF1_InitialStates_e;         /* Expression: 0
                                        * Referenced by: '<S8>/LPF1'
                                        */
  real_T sd_gainval_h;                 /* Computed Parameter: sd_gainval_h
                                        * Referenced by: '<S8>/s.d'
                                        */
  real_T sd_IC_b;                      /* Expression: 0
                                        * Referenced by: '<S8>/s.d'
                                        */
  real_T Conversion_volt_Value_p;      /* Expression: 3.3/4095
                                        * Referenced by: '<S23>/Conversion_volt'
                                        */
  real_T l2_NumCoef[2];                /* Expression: [0.1489 0.1489]
                                        * Referenced by: '<S23>/l2'
                                        */
  real_T l2_DenCoef[2];                /* Expression: [1   -0.7021]
                                        * Referenced by: '<S23>/l2'
                                        */
  real_T l2_InitialStates;             /* Expression: 0
                                        * Referenced by: '<S23>/l2'
                                        */
  real_T Rleft_tableData[3];           /* Expression: [-0.1, 0,0.1]
                                        * Referenced by: '<S23>/Rleft'
                                        */
  real_T Rleft_bp01Data[3];            /* Expression: [0.81,1.86,2.67]
                                        * Referenced by: '<S23>/Rleft'
                                        */
  real_T TSamp_WtEt_oi;                /* Computed Parameter: TSamp_WtEt_oi
                                        * Referenced by: '<S240>/TSamp'
                                        */
  real_T HF2_NumCoef_d[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S7>/H.F2'
                                        */
  real_T HF2_DenCoef_l[2];             /* Expression: [1 -0.9512]
                                        * Referenced by: '<S7>/H.F2'
                                        */
  real_T HF2_InitialStates_b;          /* Expression: 0
                                        * Referenced by: '<S7>/H.F2'
                                        */
  real_T LPF2_NumCoef_p[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S7>/LPF2'
                                        */
  real_T LPF2_DenCoef_d[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S7>/LPF2'
                                        */
  real_T LPF2_InitialStates_ks;        /* Expression: 0
                                        * Referenced by: '<S7>/LPF2'
                                        */
  real_T sd1_gainval_n;                /* Computed Parameter: sd1_gainval_n
                                        * Referenced by: '<S7>/s.d1'
                                        */
  real_T sd1_IC_e;                     /* Expression: 0
                                        * Referenced by: '<S7>/s.d1'
                                        */
  real_T Constant4_Value;              /* Expression: 1.25
                                        * Referenced by: '<S9>/Constant4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 9.80665
                                        * Referenced by: '<S9>/Gain5'
                                        */
  real_T HF4_NumCoef[2];               /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S9>/H.F4'
                                        */
  real_T HF4_DenCoef[2];               /* Expression: [1 -0.9512]
                                        * Referenced by: '<S9>/H.F4'
                                        */
  real_T HF4_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S9>/H.F4'
                                        */
  real_T LPF4_NumCoef[2];              /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S9>/LPF4'
                                        */
  real_T LPF4_DenCoef[2];              /* Expression: [1 -0.2308]
                                        * Referenced by: '<S9>/LPF4'
                                        */
  real_T LPF4_InitialStates;           /* Expression: 0
                                        * Referenced by: '<S9>/LPF4'
                                        */
  real_T HEAVE_VEL3_gainval;           /* Computed Parameter: HEAVE_VEL3_gainval
                                        * Referenced by: '<S9>/HEAVE_VEL3'
                                        */
  real_T HEAVE_VEL3_IC;                /* Expression: 0
                                        * Referenced by: '<S9>/HEAVE_VEL3'
                                        */
  real_T Constant5_Value;              /* Expression: 0.02
                                        * Referenced by: '<S9>/Constant5'
                                        */
  real_T HF1_NumCoef_m[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S7>/H.F1'
                                        */
  real_T HF1_DenCoef_j[2];             /* Expression: [1 -0.9512]
                                        * Referenced by: '<S7>/H.F1'
                                        */
  real_T HF1_InitialStates_j0;         /* Expression: 0
                                        * Referenced by: '<S7>/H.F1'
                                        */
  real_T LPF1_NumCoef_o[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S7>/LPF1'
                                        */
  real_T LPF1_DenCoef_f[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S7>/LPF1'
                                        */
  real_T LPF1_InitialStates_a;         /* Expression: 0
                                        * Referenced by: '<S7>/LPF1'
                                        */
  real_T sd_gainval_i;                 /* Computed Parameter: sd_gainval_i
                                        * Referenced by: '<S7>/s.d'
                                        */
  real_T sd_IC_f;                      /* Expression: 0
                                        * Referenced by: '<S7>/s.d'
                                        */
  real_T Conversion_volt_Value_j;      /* Expression: 3.3/4095
                                        * Referenced by: '<S21>/Conversion_volt'
                                        */
  real_T r2_NumCoef[2];                /* Expression: [0.1489 0.1489]
                                        * Referenced by: '<S21>/r2'
                                        */
  real_T r2_DenCoef[2];                /* Expression: [1   -0.7021]
                                        * Referenced by: '<S21>/r2'
                                        */
  real_T r2_InitialStates;             /* Expression: 0
                                        * Referenced by: '<S21>/r2'
                                        */
  real_T uDLookupTable1_tableData[3];  /* Expression: [0.095, 0,-0.095]
                                        * Referenced by: '<S21>/1-D Lookup Table1'
                                        */
  real_T uDLookupTable1_bp01Data[3];   /* Expression: [0.6,1.45,2.7]
                                        * Referenced by: '<S21>/1-D Lookup Table1'
                                        */
  real_T TSamp_WtEt_ox;                /* Computed Parameter: TSamp_WtEt_ox
                                        * Referenced by: '<S238>/TSamp'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 2.8
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -2.8
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T HF2_NumCoef_e[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S6>/H.F2'
                                        */
  real_T HF2_DenCoef_i[2];             /* Expression: [1 -0.9512]
                                        * Referenced by: '<S6>/H.F2'
                                        */
  real_T HF2_InitialStates_m;          /* Expression: 0
                                        * Referenced by: '<S6>/H.F2'
                                        */
  real_T LPF2_NumCoef_l[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S6>/LPF2'
                                        */
  real_T LPF2_DenCoef_i[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S6>/LPF2'
                                        */
  real_T LPF2_InitialStates_f;         /* Expression: 0
                                        * Referenced by: '<S6>/LPF2'
                                        */
  real_T sd1_gainval_l;                /* Computed Parameter: sd1_gainval_l
                                        * Referenced by: '<S6>/s.d1'
                                        */
  real_T sd1_IC_l;                     /* Expression: 0
                                        * Referenced by: '<S6>/s.d1'
                                        */
  real_T Constant6_Value;              /* Expression: 1.25
                                        * Referenced by: '<S9>/Constant6'
                                        */
  real_T Gain6_Gain;                   /* Expression: 9.80665
                                        * Referenced by: '<S9>/Gain6'
                                        */
  real_T HF5_NumCoef[2];               /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S9>/H.F5'
                                        */
  real_T HF5_DenCoef[2];               /* Expression: [1 -0.9512]
                                        * Referenced by: '<S9>/H.F5'
                                        */
  real_T HF5_InitialStates;            /* Expression: 0
                                        * Referenced by: '<S9>/H.F5'
                                        */
  real_T LPF5_NumCoef[2];              /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S9>/LPF5'
                                        */
  real_T LPF5_DenCoef[2];              /* Expression: [1 -0.2308]
                                        * Referenced by: '<S9>/LPF5'
                                        */
  real_T LPF5_InitialStates;           /* Expression: 0
                                        * Referenced by: '<S9>/LPF5'
                                        */
  real_T HEAVE_VEL4_gainval;           /* Computed Parameter: HEAVE_VEL4_gainval
                                        * Referenced by: '<S9>/HEAVE_VEL4'
                                        */
  real_T HEAVE_VEL4_IC;                /* Expression: 0
                                        * Referenced by: '<S9>/HEAVE_VEL4'
                                        */
  real_T Constant7_Value;              /* Expression: 0.02
                                        * Referenced by: '<S9>/Constant7'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 2.8
                                        * Referenced by: '<S6>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -2.8
                                        * Referenced by: '<S6>/Saturation2'
                                        */
  real_T HF1_NumCoef_k[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S6>/H.F1'
                                        */
  real_T HF1_DenCoef_a[2];             /* Expression: [1 -0.9512]
                                        * Referenced by: '<S6>/H.F1'
                                        */
  real_T HF1_InitialStates_l;          /* Expression: 0
                                        * Referenced by: '<S6>/H.F1'
                                        */
  real_T LPF1_NumCoef_b[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S6>/LPF1'
                                        */
  real_T LPF1_DenCoef_h[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S6>/LPF1'
                                        */
  real_T LPF1_InitialStates_c;         /* Expression: 0
                                        * Referenced by: '<S6>/LPF1'
                                        */
  real_T sd_gainval_b;                 /* Computed Parameter: sd_gainval_b
                                        * Referenced by: '<S6>/s.d'
                                        */
  real_T sd_IC_o;                      /* Expression: 0
                                        * Referenced by: '<S6>/s.d'
                                        */
  real_T Constant_Value;               /* Expression: 16384
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant3_Value_n;            /* Expression: 0.089
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T Constant_Value_o;             /* Expression: 1.01
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 9.8
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T HF_NumCoef[2];                /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S9>/H.F'
                                        */
  real_T HF_DenCoef[2];                /* Expression: [1 -0.9512]
                                        * Referenced by: '<S9>/H.F'
                                        */
  real_T HF_InitialStates;             /* Expression: 0
                                        * Referenced by: '<S9>/H.F'
                                        */
  real_T LPF6_NumCoef[2];              /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S9>/LPF6'
                                        */
  real_T LPF6_DenCoef[2];              /* Expression: [1 -0.2308]
                                        * Referenced by: '<S9>/LPF6'
                                        */
  real_T LPF6_InitialStates;           /* Expression: 0
                                        * Referenced by: '<S9>/LPF6'
                                        */
  real_T HEAVE_VEL_gainval;            /* Computed Parameter: HEAVE_VEL_gainval
                                        * Referenced by: '<S9>/HEAVE_VEL'
                                        */
  real_T HEAVE_VEL_IC;                 /* Expression: 0
                                        * Referenced by: '<S9>/HEAVE_VEL'
                                        */
  real_T HF1_NumCoef_f[2];             /* Expression: [0.9756 -0.9756]
                                        * Referenced by: '<S9>/H.F1'
                                        */
  real_T HF1_DenCoef_jq[2];            /* Expression: [1 -0.9512]
                                        * Referenced by: '<S9>/H.F1'
                                        */
  real_T HF1_InitialStates_n;          /* Expression: 0
                                        * Referenced by: '<S9>/H.F1'
                                        */
  real_T LPF1_NumCoef_h[2];            /* Expression: [0.386 0.3846 ]
                                        * Referenced by: '<S9>/LPF1'
                                        */
  real_T LPF1_DenCoef_e[2];            /* Expression: [1 -0.2308]
                                        * Referenced by: '<S9>/LPF1'
                                        */
  real_T LPF1_InitialStates_p;         /* Expression: 0
                                        * Referenced by: '<S9>/LPF1'
                                        */
  real_T HEAVE_disp_gainval;           /* Computed Parameter: HEAVE_disp_gainval
                                        * Referenced by: '<S9>/HEAVE_disp'
                                        */
  real_T HEAVE_disp_IC;                /* Expression: 0
                                        * Referenced by: '<S9>/HEAVE_disp'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S17>/Delay1'
                                        */
  real_T Constant1_Value_k;            /* Expression: 131
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Constant4_Value_i;            /* Expression: 2.74
                                        * Referenced by: '<S17>/Constant4'
                                        */
  real_T gx_Gain;                      /* Expression: 0.01
                                        * Referenced by: '<S17>/gx'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.98
                                        * Referenced by: '<S17>/Gain2'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S148>/Constant'
                                        */
  real_T roll_Gain;                    /* Expression: 57.295
                                        * Referenced by: '<S148>/roll'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: 0.02
                                        * Referenced by: '<S17>/Gain3'
                                        */
  real_T Constant7_Value_f;            /* Expression: 2.395
                                        * Referenced by: '<S17>/Constant7'
                                        */
  real_T Saturation1_UpperSat_b;       /* Expression: 30
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_p;       /* Expression: -30
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T TSamp_WtEt_oy;                /* Computed Parameter: TSamp_WtEt_oy
                                        * Referenced by: '<S49>/TSamp'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S17>/Delay'
                                        */
  real_T Constant5_Value_o;            /* Expression: 0.1
                                        * Referenced by: '<S17>/Constant5'
                                        */
  real_T gy_Gain;                      /* Expression: 0.01
                                        * Referenced by: '<S17>/gy'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 0.98
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T pitch1_Gain;                  /* Expression: -1
                                        * Referenced by: '<S148>/pitch1'
                                        */
  real_T pitch_Gain;                   /* Expression: 57.295
                                        * Referenced by: '<S148>/pitch'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.02
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Constant6_Value_m;            /* Expression: 4.82
                                        * Referenced by: '<S17>/Constant6'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 30
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -30
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T TSamp_WtEt_d;                 /* Computed Parameter: TSamp_WtEt_d
                                        * Referenced by: '<S48>/TSamp'
                                        */
  real_T Saturation2_UpperSat_a;       /* Expression: 2
                                        * Referenced by: '<S10>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_f;       /* Expression: 0
                                        * Referenced by: '<S10>/Saturation2'
                                        */
  real_T Saturation1_UpperSat_m;       /* Expression: 80
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_i;       /* Expression: 0
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 80
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S10>/gain'
                                        */
  real_T TSamp_WtEt_n;                 /* Computed Parameter: TSamp_WtEt_n
                                        * Referenced by: '<S53>/TSamp'
                                        */
  real_T gain1_Gain;                   /* Expression: 15
                                        * Referenced by: '<S10>/gain1'
                                        */
  real_T Gain6_Gain_a;                 /* Expression: 0.2655
                                        * Referenced by: '<S10>/Gain6'
                                        */
  real_T g2_Gain;                      /* Expression: 1
                                        * Referenced by: '<S10>/g2'
                                        */
  real_T gain3_Gain;                   /* Expression: 25
                                        * Referenced by: '<S10>/gain3'
                                        */
  real_T TSamp_WtEt_a;                 /* Computed Parameter: TSamp_WtEt_a
                                        * Referenced by: '<S54>/TSamp'
                                        */
  real_T Gain9_Gain;                   /* Expression: 0.1493
                                        * Referenced by: '<S10>/Gain9'
                                        */
  real_T g3_Gain;                      /* Expression: 1
                                        * Referenced by: '<S10>/g3'
                                        */
  real_T gain5_Gain;                   /* Expression: 60
                                        * Referenced by: '<S10>/gain5'
                                        */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S55>/TSamp'
                                        */
  real_T Gain7_Gain;                   /* Expression: 0.3135
                                        * Referenced by: '<S10>/Gain7'
                                        */
  real_T Constant1_Value_i;            /* Expression: 16000
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 16000
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -16000
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 16000
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -16000
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 0.3077
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 0.2345
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 0.1493
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T Constant1_Value_h;            /* Expression: 16000
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 16000
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -16000
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_UpperSat_mr;       /* Expression: 16000
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: -16000
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Gain11_Gain;                  /* Expression: 0.3077
                                        * Referenced by: '<S10>/Gain11'
                                        */
  real_T Gain10_Gain;                  /* Expression: 0.2345
                                        * Referenced by: '<S10>/Gain10'
                                        */
  real_T Gain12_Gain;                  /* Expression: 0.1493
                                        * Referenced by: '<S10>/Gain12'
                                        */
  real_T Constant1_Value_be;           /* Expression: 16000
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 16000
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -16000
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_UpperSat_la;       /* Expression: 16000
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_hm;       /* Expression: -16000
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain5_Gain_g;                 /* Expression: 0.3135
                                        * Referenced by: '<S10>/Gain5'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: 0.2655
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T Gain8_Gain;                   /* Expression: 0.1493
                                        * Referenced by: '<S10>/Gain8'
                                        */
  real_T Constant1_Value_hw;           /* Expression: 16000
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 16000
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat_p3;       /* Expression: -16000
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 16000
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -16000
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Constant2_Value_l;            /* Expression: 340
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T uDLookupTable4_tableData[2];  /* Expression: [2200,1284]
                                        * Referenced by: '<Root>/1-D Lookup Table4'
                                        */
  real_T uDLookupTable4_bp01Data[2];   /* Expression: [0,11000]
                                        * Referenced by: '<Root>/1-D Lookup Table4'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S133>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S128>/Filter'
                                        */
  real_T PWM_F_R_P1;                   /* Expression: 5
                                        * Referenced by: '<Root>/PWM_F_R'
                                        */
  real_T uDLookupTable2_tableData_o[2];/* Expression: [2200,1284]
                                        * Referenced by: '<Root>/1-D Lookup Table2'
                                        */
  real_T uDLookupTable2_bp01Data_lb[2];/* Expression: [0,11000]
                                        * Referenced by: '<Root>/1-D Lookup Table2'
                                        */
  real_T Integrator_gainval_d;       /* Computed Parameter: Integrator_gainval_d
                                      * Referenced by: '<S178>/Integrator'
                                      */
  real_T Filter_gainval_l;             /* Computed Parameter: Filter_gainval_l
                                        * Referenced by: '<S173>/Filter'
                                        */
  real_T PWM_R_L_P1;                   /* Expression: 4
                                        * Referenced by: '<Root>/PWM_R_L'
                                        */
  real_T uDLookupTable5_tableData[2];  /* Expression: [2200,1284]
                                        * Referenced by: '<Root>/1-D Lookup Table5'
                                        */
  real_T uDLookupTable5_bp01Data[2];   /* Expression: [0,11000]
                                        * Referenced by: '<Root>/1-D Lookup Table5'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S222>/Integrator'
                                      */
  real_T Filter_gainval_la;            /* Computed Parameter: Filter_gainval_la
                                        * Referenced by: '<S217>/Filter'
                                        */
  real_T PWM_R_R_P1;                   /* Expression: 3
                                        * Referenced by: '<Root>/PWM_R_R'
                                        */
  real_T uDLookupTable_tableData[2];   /* Expression: [2200,1284]
                                        * Referenced by: '<Root>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[2];    /* Expression: [0,11000]
                                        * Referenced by: '<Root>/1-D Lookup Table'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S89>/Integrator'
                                      */
  real_T Filter_gainval_f;             /* Computed Parameter: Filter_gainval_f
                                        * Referenced by: '<S84>/Filter'
                                        */
  real_T pwm_fL_P1;                    /* Expression: 6
                                        * Referenced by: '<Root>/pwm_fL'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S82>/ZeroGain'
                                        */
  real_T Constant1_Value_ig;           /* Expression: 0
                                        * Referenced by: '<S82>/Constant1'
                                        */
  real_T ZeroGain_Gain_l;              /* Expression: 0
                                        * Referenced by: '<S215>/ZeroGain'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S215>/Constant1'
                                        */
  real_T ZeroGain_Gain_f;              /* Expression: 0
                                        * Referenced by: '<S171>/ZeroGain'
                                        */
  real_T Constant1_Value_hh;           /* Expression: 0
                                        * Referenced by: '<S171>/Constant1'
                                        */
  real_T ZeroGain_Gain_j;              /* Expression: 0
                                        * Referenced by: '<S126>/ZeroGain'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S126>/Constant1'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S17>/Delay1'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S17>/Delay'
                                        */
  P_MovingRMS3_Master_control_f_T MovingRMS;/* '<S51>/Moving RMS3' */
  P_MovingRMS3_Master_control_f_T MovingRMS1;/* '<S51>/Moving RMS3' */
  P_MovingRMS3_Master_control_f_T MovingRMS2;/* '<S51>/Moving RMS3' */
  P_MovingRMS3_Master_control_f_T MovingRMS3;/* '<S51>/Moving RMS3' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem_c;/* '<S45>/If Action Subsystem' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem_p;/* '<S41>/If Action Subsystem' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem_n;/* '<S37>/If Action Subsystem' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem_f;/* '<S33>/If Action Subsystem' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem_ej;/* '<S4>/If Action Subsystem' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem_e;/* '<S3>/If Action Subsystem' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem_b;/* '<S2>/If Action Subsystem' */
  P_IfActionSubsystem_Master_co_T IfActionSubsystem;/* '<S1>/If Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Master_control_fuzzy__T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Master_control_fuzzy_standa_T Master_control_fuzzy_standalo_P;

/* Block signals (default storage) */
extern B_Master_control_fuzzy_standa_T Master_control_fuzzy_standalo_B;

/* Block states (default storage) */
extern DW_Master_control_fuzzy_stand_T Master_control_fuzzy_standal_DW;

/* Model entry point functions */
extern void Master_control_fuzzy_standalone_new_initialize(void);
extern void Master_control_fuzzy_standalone_new_step(void);
extern void Master_control_fuzzy_standalone_new_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Master_control_fuzzy_T *const Master_control_fuzzy_standal_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Gain1' : Unused code path elimination
 * Block '<S9>/Gain2' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Conversion6' : Unused code path elimination
 * Block '<S17>/Divide5' : Unused code path elimination
 * Block '<S148>/Sign' : Unused code path elimination
 * Block '<S237>/Data Type Duplicate' : Unused code path elimination
 * Block '<S238>/Data Type Duplicate' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/InputConversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'Master_control_fuzzy_standalone_new'
 * '<S1>'   : 'Master_control_fuzzy_standalone_new/DF_logic'
 * '<S2>'   : 'Master_control_fuzzy_standalone_new/DF_logic1'
 * '<S3>'   : 'Master_control_fuzzy_standalone_new/DF_logic2'
 * '<S4>'   : 'Master_control_fuzzy_standalone_new/DF_logic3'
 * '<S5>'   : 'Master_control_fuzzy_standalone_new/Fuzzy Front left'
 * '<S6>'   : 'Master_control_fuzzy_standalone_new/Fuzzy Rear Right'
 * '<S7>'   : 'Master_control_fuzzy_standalone_new/Fuzzy rear Right'
 * '<S8>'   : 'Master_control_fuzzy_standalone_new/FuzzyFront Right'
 * '<S9>'   : 'Master_control_fuzzy_standalone_new/Subsystem1'
 * '<S10>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop'
 * '<S11>'  : 'Master_control_fuzzy_standalone_new/feedback'
 * '<S12>'  : 'Master_control_fuzzy_standalone_new/feedback1'
 * '<S13>'  : 'Master_control_fuzzy_standalone_new/feedback2'
 * '<S14>'  : 'Master_control_fuzzy_standalone_new/feedback3'
 * '<S15>'  : 'Master_control_fuzzy_standalone_new/front left'
 * '<S16>'  : 'Master_control_fuzzy_standalone_new/front right'
 * '<S17>'  : 'Master_control_fuzzy_standalone_new/mpu6050'
 * '<S18>'  : 'Master_control_fuzzy_standalone_new/rear left'
 * '<S19>'  : 'Master_control_fuzzy_standalone_new/rear right'
 * '<S20>'  : 'Master_control_fuzzy_standalone_new/rv_Right_FRONT'
 * '<S21>'  : 'Master_control_fuzzy_standalone_new/rv_Right_REAR'
 * '<S22>'  : 'Master_control_fuzzy_standalone_new/rv_left_FRONT'
 * '<S23>'  : 'Master_control_fuzzy_standalone_new/rv_left_REAR'
 * '<S24>'  : 'Master_control_fuzzy_standalone_new/DF_logic/If Action Subsystem'
 * '<S25>'  : 'Master_control_fuzzy_standalone_new/DF_logic/If Action Subsystem1'
 * '<S26>'  : 'Master_control_fuzzy_standalone_new/DF_logic1/If Action Subsystem'
 * '<S27>'  : 'Master_control_fuzzy_standalone_new/DF_logic1/If Action Subsystem1'
 * '<S28>'  : 'Master_control_fuzzy_standalone_new/DF_logic2/If Action Subsystem'
 * '<S29>'  : 'Master_control_fuzzy_standalone_new/DF_logic2/If Action Subsystem1'
 * '<S30>'  : 'Master_control_fuzzy_standalone_new/DF_logic3/If Action Subsystem'
 * '<S31>'  : 'Master_control_fuzzy_standalone_new/DF_logic3/If Action Subsystem1'
 * '<S32>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Front left/MATLAB Function'
 * '<S33>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Front left/divi_by Zero_bypass'
 * '<S34>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Front left/divi_by Zero_bypass/If Action Subsystem'
 * '<S35>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Front left/divi_by Zero_bypass/If Action Subsystem1'
 * '<S36>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Rear Right/MATLAB Function'
 * '<S37>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Rear Right/divi_by Zero_bypass'
 * '<S38>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Rear Right/divi_by Zero_bypass/If Action Subsystem'
 * '<S39>'  : 'Master_control_fuzzy_standalone_new/Fuzzy Rear Right/divi_by Zero_bypass/If Action Subsystem1'
 * '<S40>'  : 'Master_control_fuzzy_standalone_new/Fuzzy rear Right/MATLAB Function'
 * '<S41>'  : 'Master_control_fuzzy_standalone_new/Fuzzy rear Right/divi_by Zero_bypass'
 * '<S42>'  : 'Master_control_fuzzy_standalone_new/Fuzzy rear Right/divi_by Zero_bypass/If Action Subsystem'
 * '<S43>'  : 'Master_control_fuzzy_standalone_new/Fuzzy rear Right/divi_by Zero_bypass/If Action Subsystem1'
 * '<S44>'  : 'Master_control_fuzzy_standalone_new/FuzzyFront Right/MATLAB Function'
 * '<S45>'  : 'Master_control_fuzzy_standalone_new/FuzzyFront Right/divi_by Zero_bypass'
 * '<S46>'  : 'Master_control_fuzzy_standalone_new/FuzzyFront Right/divi_by Zero_bypass/If Action Subsystem'
 * '<S47>'  : 'Master_control_fuzzy_standalone_new/FuzzyFront Right/divi_by Zero_bypass/If Action Subsystem1'
 * '<S48>'  : 'Master_control_fuzzy_standalone_new/Subsystem1/Discrete Derivative4'
 * '<S49>'  : 'Master_control_fuzzy_standalone_new/Subsystem1/Discrete Derivative5'
 * '<S50>'  : 'Master_control_fuzzy_standalone_new/Subsystem1/sensor caliberation logic'
 * '<S51>'  : 'Master_control_fuzzy_standalone_new/Subsystem1/sensor caliberation logic/If Action Subsystem'
 * '<S52>'  : 'Master_control_fuzzy_standalone_new/Subsystem1/sensor caliberation logic/If Action Subsystem1'
 * '<S53>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop/Discrete Derivative'
 * '<S54>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop/Discrete Derivative1'
 * '<S55>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop/Discrete Derivative2'
 * '<S56>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop/Fuzzy Logic  Controller'
 * '<S57>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop/Fuzzy Logic  Controller/Defuzzify Outputs'
 * '<S58>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop/Fuzzy Logic  Controller/Evaluate Rule Antecedents'
 * '<S59>'  : 'Master_control_fuzzy_standalone_new/decoupling transformation and outer loop/Fuzzy Logic  Controller/Evaluate Rule Consequents'
 * '<S60>'  : 'Master_control_fuzzy_standalone_new/front left/Anti-windup'
 * '<S61>'  : 'Master_control_fuzzy_standalone_new/front left/D Gain'
 * '<S62>'  : 'Master_control_fuzzy_standalone_new/front left/Filter'
 * '<S63>'  : 'Master_control_fuzzy_standalone_new/front left/Filter ICs'
 * '<S64>'  : 'Master_control_fuzzy_standalone_new/front left/I Gain'
 * '<S65>'  : 'Master_control_fuzzy_standalone_new/front left/Ideal P Gain'
 * '<S66>'  : 'Master_control_fuzzy_standalone_new/front left/Ideal P Gain Fdbk'
 * '<S67>'  : 'Master_control_fuzzy_standalone_new/front left/Integrator'
 * '<S68>'  : 'Master_control_fuzzy_standalone_new/front left/Integrator ICs'
 * '<S69>'  : 'Master_control_fuzzy_standalone_new/front left/N Copy'
 * '<S70>'  : 'Master_control_fuzzy_standalone_new/front left/N Gain'
 * '<S71>'  : 'Master_control_fuzzy_standalone_new/front left/P Copy'
 * '<S72>'  : 'Master_control_fuzzy_standalone_new/front left/Parallel P Gain'
 * '<S73>'  : 'Master_control_fuzzy_standalone_new/front left/Reset Signal'
 * '<S74>'  : 'Master_control_fuzzy_standalone_new/front left/Saturation'
 * '<S75>'  : 'Master_control_fuzzy_standalone_new/front left/Saturation Fdbk'
 * '<S76>'  : 'Master_control_fuzzy_standalone_new/front left/Sum'
 * '<S77>'  : 'Master_control_fuzzy_standalone_new/front left/Sum Fdbk'
 * '<S78>'  : 'Master_control_fuzzy_standalone_new/front left/Tracking Mode'
 * '<S79>'  : 'Master_control_fuzzy_standalone_new/front left/Tracking Mode Sum'
 * '<S80>'  : 'Master_control_fuzzy_standalone_new/front left/postSat Signal'
 * '<S81>'  : 'Master_control_fuzzy_standalone_new/front left/preSat Signal'
 * '<S82>'  : 'Master_control_fuzzy_standalone_new/front left/Anti-windup/Disc. Clamping Parallel'
 * '<S83>'  : 'Master_control_fuzzy_standalone_new/front left/D Gain/Internal Parameters'
 * '<S84>'  : 'Master_control_fuzzy_standalone_new/front left/Filter/Disc. Forward Euler Filter'
 * '<S85>'  : 'Master_control_fuzzy_standalone_new/front left/Filter ICs/Internal IC - Filter'
 * '<S86>'  : 'Master_control_fuzzy_standalone_new/front left/I Gain/Internal Parameters'
 * '<S87>'  : 'Master_control_fuzzy_standalone_new/front left/Ideal P Gain/Passthrough'
 * '<S88>'  : 'Master_control_fuzzy_standalone_new/front left/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'Master_control_fuzzy_standalone_new/front left/Integrator/Discrete'
 * '<S90>'  : 'Master_control_fuzzy_standalone_new/front left/Integrator ICs/Internal IC'
 * '<S91>'  : 'Master_control_fuzzy_standalone_new/front left/N Copy/Disabled'
 * '<S92>'  : 'Master_control_fuzzy_standalone_new/front left/N Gain/Internal Parameters'
 * '<S93>'  : 'Master_control_fuzzy_standalone_new/front left/P Copy/Disabled'
 * '<S94>'  : 'Master_control_fuzzy_standalone_new/front left/Parallel P Gain/Internal Parameters'
 * '<S95>'  : 'Master_control_fuzzy_standalone_new/front left/Reset Signal/Disabled'
 * '<S96>'  : 'Master_control_fuzzy_standalone_new/front left/Saturation/Enabled'
 * '<S97>'  : 'Master_control_fuzzy_standalone_new/front left/Saturation Fdbk/Disabled'
 * '<S98>'  : 'Master_control_fuzzy_standalone_new/front left/Sum/Sum_PID'
 * '<S99>'  : 'Master_control_fuzzy_standalone_new/front left/Sum Fdbk/Disabled'
 * '<S100>' : 'Master_control_fuzzy_standalone_new/front left/Tracking Mode/Disabled'
 * '<S101>' : 'Master_control_fuzzy_standalone_new/front left/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'Master_control_fuzzy_standalone_new/front left/postSat Signal/Forward_Path'
 * '<S103>' : 'Master_control_fuzzy_standalone_new/front left/preSat Signal/Forward_Path'
 * '<S104>' : 'Master_control_fuzzy_standalone_new/front right/Anti-windup'
 * '<S105>' : 'Master_control_fuzzy_standalone_new/front right/D Gain'
 * '<S106>' : 'Master_control_fuzzy_standalone_new/front right/Filter'
 * '<S107>' : 'Master_control_fuzzy_standalone_new/front right/Filter ICs'
 * '<S108>' : 'Master_control_fuzzy_standalone_new/front right/I Gain'
 * '<S109>' : 'Master_control_fuzzy_standalone_new/front right/Ideal P Gain'
 * '<S110>' : 'Master_control_fuzzy_standalone_new/front right/Ideal P Gain Fdbk'
 * '<S111>' : 'Master_control_fuzzy_standalone_new/front right/Integrator'
 * '<S112>' : 'Master_control_fuzzy_standalone_new/front right/Integrator ICs'
 * '<S113>' : 'Master_control_fuzzy_standalone_new/front right/N Copy'
 * '<S114>' : 'Master_control_fuzzy_standalone_new/front right/N Gain'
 * '<S115>' : 'Master_control_fuzzy_standalone_new/front right/P Copy'
 * '<S116>' : 'Master_control_fuzzy_standalone_new/front right/Parallel P Gain'
 * '<S117>' : 'Master_control_fuzzy_standalone_new/front right/Reset Signal'
 * '<S118>' : 'Master_control_fuzzy_standalone_new/front right/Saturation'
 * '<S119>' : 'Master_control_fuzzy_standalone_new/front right/Saturation Fdbk'
 * '<S120>' : 'Master_control_fuzzy_standalone_new/front right/Sum'
 * '<S121>' : 'Master_control_fuzzy_standalone_new/front right/Sum Fdbk'
 * '<S122>' : 'Master_control_fuzzy_standalone_new/front right/Tracking Mode'
 * '<S123>' : 'Master_control_fuzzy_standalone_new/front right/Tracking Mode Sum'
 * '<S124>' : 'Master_control_fuzzy_standalone_new/front right/postSat Signal'
 * '<S125>' : 'Master_control_fuzzy_standalone_new/front right/preSat Signal'
 * '<S126>' : 'Master_control_fuzzy_standalone_new/front right/Anti-windup/Disc. Clamping Parallel'
 * '<S127>' : 'Master_control_fuzzy_standalone_new/front right/D Gain/Internal Parameters'
 * '<S128>' : 'Master_control_fuzzy_standalone_new/front right/Filter/Disc. Forward Euler Filter'
 * '<S129>' : 'Master_control_fuzzy_standalone_new/front right/Filter ICs/Internal IC - Filter'
 * '<S130>' : 'Master_control_fuzzy_standalone_new/front right/I Gain/Internal Parameters'
 * '<S131>' : 'Master_control_fuzzy_standalone_new/front right/Ideal P Gain/Passthrough'
 * '<S132>' : 'Master_control_fuzzy_standalone_new/front right/Ideal P Gain Fdbk/Disabled'
 * '<S133>' : 'Master_control_fuzzy_standalone_new/front right/Integrator/Discrete'
 * '<S134>' : 'Master_control_fuzzy_standalone_new/front right/Integrator ICs/Internal IC'
 * '<S135>' : 'Master_control_fuzzy_standalone_new/front right/N Copy/Disabled'
 * '<S136>' : 'Master_control_fuzzy_standalone_new/front right/N Gain/Internal Parameters'
 * '<S137>' : 'Master_control_fuzzy_standalone_new/front right/P Copy/Disabled'
 * '<S138>' : 'Master_control_fuzzy_standalone_new/front right/Parallel P Gain/Internal Parameters'
 * '<S139>' : 'Master_control_fuzzy_standalone_new/front right/Reset Signal/Disabled'
 * '<S140>' : 'Master_control_fuzzy_standalone_new/front right/Saturation/Enabled'
 * '<S141>' : 'Master_control_fuzzy_standalone_new/front right/Saturation Fdbk/Disabled'
 * '<S142>' : 'Master_control_fuzzy_standalone_new/front right/Sum/Sum_PID'
 * '<S143>' : 'Master_control_fuzzy_standalone_new/front right/Sum Fdbk/Disabled'
 * '<S144>' : 'Master_control_fuzzy_standalone_new/front right/Tracking Mode/Disabled'
 * '<S145>' : 'Master_control_fuzzy_standalone_new/front right/Tracking Mode Sum/Passthrough'
 * '<S146>' : 'Master_control_fuzzy_standalone_new/front right/postSat Signal/Forward_Path'
 * '<S147>' : 'Master_control_fuzzy_standalone_new/front right/preSat Signal/Forward_Path'
 * '<S148>' : 'Master_control_fuzzy_standalone_new/mpu6050/Subsystem'
 * '<S149>' : 'Master_control_fuzzy_standalone_new/rear left/Anti-windup'
 * '<S150>' : 'Master_control_fuzzy_standalone_new/rear left/D Gain'
 * '<S151>' : 'Master_control_fuzzy_standalone_new/rear left/Filter'
 * '<S152>' : 'Master_control_fuzzy_standalone_new/rear left/Filter ICs'
 * '<S153>' : 'Master_control_fuzzy_standalone_new/rear left/I Gain'
 * '<S154>' : 'Master_control_fuzzy_standalone_new/rear left/Ideal P Gain'
 * '<S155>' : 'Master_control_fuzzy_standalone_new/rear left/Ideal P Gain Fdbk'
 * '<S156>' : 'Master_control_fuzzy_standalone_new/rear left/Integrator'
 * '<S157>' : 'Master_control_fuzzy_standalone_new/rear left/Integrator ICs'
 * '<S158>' : 'Master_control_fuzzy_standalone_new/rear left/N Copy'
 * '<S159>' : 'Master_control_fuzzy_standalone_new/rear left/N Gain'
 * '<S160>' : 'Master_control_fuzzy_standalone_new/rear left/P Copy'
 * '<S161>' : 'Master_control_fuzzy_standalone_new/rear left/Parallel P Gain'
 * '<S162>' : 'Master_control_fuzzy_standalone_new/rear left/Reset Signal'
 * '<S163>' : 'Master_control_fuzzy_standalone_new/rear left/Saturation'
 * '<S164>' : 'Master_control_fuzzy_standalone_new/rear left/Saturation Fdbk'
 * '<S165>' : 'Master_control_fuzzy_standalone_new/rear left/Sum'
 * '<S166>' : 'Master_control_fuzzy_standalone_new/rear left/Sum Fdbk'
 * '<S167>' : 'Master_control_fuzzy_standalone_new/rear left/Tracking Mode'
 * '<S168>' : 'Master_control_fuzzy_standalone_new/rear left/Tracking Mode Sum'
 * '<S169>' : 'Master_control_fuzzy_standalone_new/rear left/postSat Signal'
 * '<S170>' : 'Master_control_fuzzy_standalone_new/rear left/preSat Signal'
 * '<S171>' : 'Master_control_fuzzy_standalone_new/rear left/Anti-windup/Disc. Clamping Parallel'
 * '<S172>' : 'Master_control_fuzzy_standalone_new/rear left/D Gain/Internal Parameters'
 * '<S173>' : 'Master_control_fuzzy_standalone_new/rear left/Filter/Disc. Forward Euler Filter'
 * '<S174>' : 'Master_control_fuzzy_standalone_new/rear left/Filter ICs/Internal IC - Filter'
 * '<S175>' : 'Master_control_fuzzy_standalone_new/rear left/I Gain/Internal Parameters'
 * '<S176>' : 'Master_control_fuzzy_standalone_new/rear left/Ideal P Gain/Passthrough'
 * '<S177>' : 'Master_control_fuzzy_standalone_new/rear left/Ideal P Gain Fdbk/Disabled'
 * '<S178>' : 'Master_control_fuzzy_standalone_new/rear left/Integrator/Discrete'
 * '<S179>' : 'Master_control_fuzzy_standalone_new/rear left/Integrator ICs/Internal IC'
 * '<S180>' : 'Master_control_fuzzy_standalone_new/rear left/N Copy/Disabled'
 * '<S181>' : 'Master_control_fuzzy_standalone_new/rear left/N Gain/Internal Parameters'
 * '<S182>' : 'Master_control_fuzzy_standalone_new/rear left/P Copy/Disabled'
 * '<S183>' : 'Master_control_fuzzy_standalone_new/rear left/Parallel P Gain/Internal Parameters'
 * '<S184>' : 'Master_control_fuzzy_standalone_new/rear left/Reset Signal/Disabled'
 * '<S185>' : 'Master_control_fuzzy_standalone_new/rear left/Saturation/Enabled'
 * '<S186>' : 'Master_control_fuzzy_standalone_new/rear left/Saturation Fdbk/Disabled'
 * '<S187>' : 'Master_control_fuzzy_standalone_new/rear left/Sum/Sum_PID'
 * '<S188>' : 'Master_control_fuzzy_standalone_new/rear left/Sum Fdbk/Disabled'
 * '<S189>' : 'Master_control_fuzzy_standalone_new/rear left/Tracking Mode/Disabled'
 * '<S190>' : 'Master_control_fuzzy_standalone_new/rear left/Tracking Mode Sum/Passthrough'
 * '<S191>' : 'Master_control_fuzzy_standalone_new/rear left/postSat Signal/Forward_Path'
 * '<S192>' : 'Master_control_fuzzy_standalone_new/rear left/preSat Signal/Forward_Path'
 * '<S193>' : 'Master_control_fuzzy_standalone_new/rear right/Anti-windup'
 * '<S194>' : 'Master_control_fuzzy_standalone_new/rear right/D Gain'
 * '<S195>' : 'Master_control_fuzzy_standalone_new/rear right/Filter'
 * '<S196>' : 'Master_control_fuzzy_standalone_new/rear right/Filter ICs'
 * '<S197>' : 'Master_control_fuzzy_standalone_new/rear right/I Gain'
 * '<S198>' : 'Master_control_fuzzy_standalone_new/rear right/Ideal P Gain'
 * '<S199>' : 'Master_control_fuzzy_standalone_new/rear right/Ideal P Gain Fdbk'
 * '<S200>' : 'Master_control_fuzzy_standalone_new/rear right/Integrator'
 * '<S201>' : 'Master_control_fuzzy_standalone_new/rear right/Integrator ICs'
 * '<S202>' : 'Master_control_fuzzy_standalone_new/rear right/N Copy'
 * '<S203>' : 'Master_control_fuzzy_standalone_new/rear right/N Gain'
 * '<S204>' : 'Master_control_fuzzy_standalone_new/rear right/P Copy'
 * '<S205>' : 'Master_control_fuzzy_standalone_new/rear right/Parallel P Gain'
 * '<S206>' : 'Master_control_fuzzy_standalone_new/rear right/Reset Signal'
 * '<S207>' : 'Master_control_fuzzy_standalone_new/rear right/Saturation'
 * '<S208>' : 'Master_control_fuzzy_standalone_new/rear right/Saturation Fdbk'
 * '<S209>' : 'Master_control_fuzzy_standalone_new/rear right/Sum'
 * '<S210>' : 'Master_control_fuzzy_standalone_new/rear right/Sum Fdbk'
 * '<S211>' : 'Master_control_fuzzy_standalone_new/rear right/Tracking Mode'
 * '<S212>' : 'Master_control_fuzzy_standalone_new/rear right/Tracking Mode Sum'
 * '<S213>' : 'Master_control_fuzzy_standalone_new/rear right/postSat Signal'
 * '<S214>' : 'Master_control_fuzzy_standalone_new/rear right/preSat Signal'
 * '<S215>' : 'Master_control_fuzzy_standalone_new/rear right/Anti-windup/Disc. Clamping Parallel'
 * '<S216>' : 'Master_control_fuzzy_standalone_new/rear right/D Gain/Internal Parameters'
 * '<S217>' : 'Master_control_fuzzy_standalone_new/rear right/Filter/Disc. Forward Euler Filter'
 * '<S218>' : 'Master_control_fuzzy_standalone_new/rear right/Filter ICs/Internal IC - Filter'
 * '<S219>' : 'Master_control_fuzzy_standalone_new/rear right/I Gain/Internal Parameters'
 * '<S220>' : 'Master_control_fuzzy_standalone_new/rear right/Ideal P Gain/Passthrough'
 * '<S221>' : 'Master_control_fuzzy_standalone_new/rear right/Ideal P Gain Fdbk/Disabled'
 * '<S222>' : 'Master_control_fuzzy_standalone_new/rear right/Integrator/Discrete'
 * '<S223>' : 'Master_control_fuzzy_standalone_new/rear right/Integrator ICs/Internal IC'
 * '<S224>' : 'Master_control_fuzzy_standalone_new/rear right/N Copy/Disabled'
 * '<S225>' : 'Master_control_fuzzy_standalone_new/rear right/N Gain/Internal Parameters'
 * '<S226>' : 'Master_control_fuzzy_standalone_new/rear right/P Copy/Disabled'
 * '<S227>' : 'Master_control_fuzzy_standalone_new/rear right/Parallel P Gain/Internal Parameters'
 * '<S228>' : 'Master_control_fuzzy_standalone_new/rear right/Reset Signal/Disabled'
 * '<S229>' : 'Master_control_fuzzy_standalone_new/rear right/Saturation/Enabled'
 * '<S230>' : 'Master_control_fuzzy_standalone_new/rear right/Saturation Fdbk/Disabled'
 * '<S231>' : 'Master_control_fuzzy_standalone_new/rear right/Sum/Sum_PID'
 * '<S232>' : 'Master_control_fuzzy_standalone_new/rear right/Sum Fdbk/Disabled'
 * '<S233>' : 'Master_control_fuzzy_standalone_new/rear right/Tracking Mode/Disabled'
 * '<S234>' : 'Master_control_fuzzy_standalone_new/rear right/Tracking Mode Sum/Passthrough'
 * '<S235>' : 'Master_control_fuzzy_standalone_new/rear right/postSat Signal/Forward_Path'
 * '<S236>' : 'Master_control_fuzzy_standalone_new/rear right/preSat Signal/Forward_Path'
 * '<S237>' : 'Master_control_fuzzy_standalone_new/rv_Right_FRONT/Discrete Derivative1'
 * '<S238>' : 'Master_control_fuzzy_standalone_new/rv_Right_REAR/Discrete Derivative1'
 * '<S239>' : 'Master_control_fuzzy_standalone_new/rv_left_FRONT/Discrete Derivative1'
 * '<S240>' : 'Master_control_fuzzy_standalone_new/rv_left_REAR/Discrete Derivative1'
 */
#endif                   /* RTW_HEADER_Master_control_fuzzy_standalone_new_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
