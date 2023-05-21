/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Master_control_fuzzy_standalone_new_types.h
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

#ifndef RTW_HEADER_Master_control_fuzzy_standalone_new_types_h_
#define RTW_HEADER_Master_control_fuzzy_standalone_new_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_RLwwwx5fU9j70IauvHUAxB_
#define DEFINED_TYPEDEF_FOR_struct_RLwwwx5fU9j70IauvHUAxB_

typedef struct {
  uint8_T SimulinkDiagnostic;
  uint8_T Model[76];
  uint8_T Block[100];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
} struct_RLwwwx5fU9j70IauvHUAxB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
#define DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_

typedef struct {
  uint8_T type[5];
  int32_T origTypeLength;
  real_T params[3];
  int32_T origParamLength;
} struct_RCP1oovUDF2zF6C9vcJmtG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_OTlcYhhT3UxB0PEhAC2ANE_
#define DEFINED_TYPEDEF_FOR_struct_OTlcYhhT3UxB0PEhAC2ANE_

typedef struct {
  struct_RCP1oovUDF2zF6C9vcJmtG mf[3];
  int32_T origNumMF;
} struct_OTlcYhhT3UxB0PEhAC2ANE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JoRshoep8ejMwFGpwcoIXD_
#define DEFINED_TYPEDEF_FOR_struct_JoRshoep8ejMwFGpwcoIXD_

typedef struct {
  uint8_T type[7];
  uint8_T andMethod[3];
  uint8_T orMethod[3];
  uint8_T defuzzMethod[8];
  uint8_T impMethod[3];
  uint8_T aggMethod[3];
  real_T inputRange[6];
  real_T outputRange[6];
  struct_OTlcYhhT3UxB0PEhAC2ANE inputMF[3];
  struct_OTlcYhhT3UxB0PEhAC2ANE outputMF[3];
  real_T antecedent[27];
  real_T consequent[27];
  real_T connection[9];
  real_T weight[9];
  int32_T numSamples;
  int32_T numInputs;
  int32_T numOutputs;
  int32_T numRules;
  int32_T numInputMFs[3];
  int32_T numCumInputMFs[3];
  int32_T numOutputMFs[3];
  int32_T numCumOutputMFs[3];
  real_T outputSamplePoints[150];
  int32_T orrSize[2];
  int32_T aggSize[2];
} struct_JoRshoep8ejMwFGpwcoIXD;

#endif

#ifndef typedef_e_dsp_private_ExponentialMovi_T
#define typedef_e_dsp_private_ExponentialMovi_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T ForgettingFactor;
  real_T pwN;
  real_T pmN;
  real_T plambda;
} e_dsp_private_ExponentialMovi_T;

#endif                               /*typedef_e_dsp_private_ExponentialMovi_T*/

#ifndef typedef_c_cell_wrap_Master_control_fu_T
#define typedef_c_cell_wrap_Master_control_fu_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_Master_control_fu_T;

#endif                               /*typedef_c_cell_wrap_Master_control_fu_T*/

#ifndef typedef_dsp_simulink_MovingRMS_Master_T
#define typedef_dsp_simulink_MovingRMS_Master_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  c_cell_wrap_Master_control_fu_T inputVarSize;
  real_T ForgettingFactor;
  e_dsp_private_ExponentialMovi_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingRMS_Master_T;

#endif                               /*typedef_dsp_simulink_MovingRMS_Master_T*/

/* Custom Type definition for MATLABSystem: '<S23>/Analog Input3' */
#include "MW_SVD.h"
#ifndef typedef_c_cell_Master_control_fuzzy_s_T
#define typedef_c_cell_Master_control_fuzzy_s_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} c_cell_Master_control_fuzzy_s_T;

#endif                               /*typedef_c_cell_Master_control_fuzzy_s_T*/

#ifndef typedef_e_codertarget_arduinobase_int_T
#define typedef_e_codertarget_arduinobase_int_T

typedef struct {
  c_cell_Master_control_fuzzy_s_T AvailablePwmPinNames;
} e_codertarget_arduinobase_int_T;

#endif                               /*typedef_e_codertarget_arduinobase_int_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_codertarget_arduinobase_int_T *Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Custom Type definition for MATLAB Function: '<S56>/Evaluate Rule Consequents' */
#ifndef struct_tag_sDfM9XCdU9DLkphJPFDd11C
#define struct_tag_sDfM9XCdU9DLkphJPFDd11C

struct tag_sDfM9XCdU9DLkphJPFDd11C
{
  uint8_T type[5];
  int32_T origTypeLength;
  real_T params[3];
  int32_T origParamLength;
};

#endif                                 /*struct_tag_sDfM9XCdU9DLkphJPFDd11C*/

#ifndef typedef_sDfM9XCdU9DLkphJPFDd11C_Maste_T
#define typedef_sDfM9XCdU9DLkphJPFDd11C_Maste_T

typedef struct tag_sDfM9XCdU9DLkphJPFDd11C sDfM9XCdU9DLkphJPFDd11C_Maste_T;

#endif                               /*typedef_sDfM9XCdU9DLkphJPFDd11C_Maste_T*/

#ifndef struct_tag_shO0IWYgEilomEPNnioDLBD
#define struct_tag_shO0IWYgEilomEPNnioDLBD

struct tag_shO0IWYgEilomEPNnioDLBD
{
  sDfM9XCdU9DLkphJPFDd11C_Maste_T mf[3];
  int32_T origNumMF;
};

#endif                                 /*struct_tag_shO0IWYgEilomEPNnioDLBD*/

#ifndef typedef_shO0IWYgEilomEPNnioDLBD_Maste_T
#define typedef_shO0IWYgEilomEPNnioDLBD_Maste_T

typedef struct tag_shO0IWYgEilomEPNnioDLBD shO0IWYgEilomEPNnioDLBD_Maste_T;

#endif                               /*typedef_shO0IWYgEilomEPNnioDLBD_Maste_T*/

#ifndef struct_tag_sW8BrHokMTcOVE5nCDB3gAF
#define struct_tag_sW8BrHokMTcOVE5nCDB3gAF

struct tag_sW8BrHokMTcOVE5nCDB3gAF
{
  uint8_T type[7];
  uint8_T andMethod[3];
  uint8_T orMethod[3];
  uint8_T defuzzMethod[8];
  uint8_T impMethod[3];
  uint8_T aggMethod[3];
  real_T inputRange[6];
  real_T outputRange[6];
  shO0IWYgEilomEPNnioDLBD_Maste_T inputMF[3];
  shO0IWYgEilomEPNnioDLBD_Maste_T outputMF[3];
  real_T antecedent[27];
  real_T consequent[27];
  real_T connection[9];
  real_T weight[9];
  int32_T numSamples;
  int32_T numInputs;
  int32_T numOutputs;
  int32_T numRules;
  int32_T numInputMFs[3];
  int32_T numCumInputMFs[3];
  int32_T numOutputMFs[3];
  int32_T numCumOutputMFs[3];
  real_T outputSamplePoints[150];
  int32_T orrSize[2];
  int32_T aggSize[2];
};

#endif                                 /*struct_tag_sW8BrHokMTcOVE5nCDB3gAF*/

#ifndef typedef_sW8BrHokMTcOVE5nCDB3gAF_Maste_T
#define typedef_sW8BrHokMTcOVE5nCDB3gAF_Maste_T

typedef struct tag_sW8BrHokMTcOVE5nCDB3gAF sW8BrHokMTcOVE5nCDB3gAF_Maste_T;

#endif                               /*typedef_sW8BrHokMTcOVE5nCDB3gAF_Maste_T*/

/* Custom Type definition for MATLAB Function: '<S56>/Evaluate Rule Antecedents' */
#ifndef struct_tag_sIej7iYt24umMixZOIaErPH
#define struct_tag_sIej7iYt24umMixZOIaErPH

struct tag_sIej7iYt24umMixZOIaErPH
{
  uint8_T SimulinkDiagnostic;
  uint8_T Model[76];
  uint8_T Block[100];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
};

#endif                                 /*struct_tag_sIej7iYt24umMixZOIaErPH*/

#ifndef typedef_sIej7iYt24umMixZOIaErPH_Maste_T
#define typedef_sIej7iYt24umMixZOIaErPH_Maste_T

typedef struct tag_sIej7iYt24umMixZOIaErPH sIej7iYt24umMixZOIaErPH_Maste_T;

#endif                               /*typedef_sIej7iYt24umMixZOIaErPH_Maste_T*/

/* Custom Type definition for MATLAB Function: '<S56>/Evaluate Rule Consequents' */
#ifndef struct_tag_sXsSeVB4E0ntMvFGNG3D1eC
#define struct_tag_sXsSeVB4E0ntMvFGNG3D1eC

struct tag_sXsSeVB4E0ntMvFGNG3D1eC
{
  uint8_T type[5];
  real_T params[3];
};

#endif                                 /*struct_tag_sXsSeVB4E0ntMvFGNG3D1eC*/

#ifndef typedef_sXsSeVB4E0ntMvFGNG3D1eC_Maste_T
#define typedef_sXsSeVB4E0ntMvFGNG3D1eC_Maste_T

typedef struct tag_sXsSeVB4E0ntMvFGNG3D1eC sXsSeVB4E0ntMvFGNG3D1eC_Maste_T;

#endif                               /*typedef_sXsSeVB4E0ntMvFGNG3D1eC_Maste_T*/

/* Parameters for system: '<S1>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_Master_co_T_ P_IfActionSubsystem_Master_co_T;

/* Parameters for system: '<S51>/Moving RMS3' */
typedef struct P_MovingRMS3_Master_control_f_T_ P_MovingRMS3_Master_control_f_T;

/* Parameters (default storage) */
typedef struct P_Master_control_fuzzy_standa_T_ P_Master_control_fuzzy_standa_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Master_control_fuzzy__T RT_MODEL_Master_control_fuzzy_T;

#endif             /* RTW_HEADER_Master_control_fuzzy_standalone_new_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
