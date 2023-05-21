/*
  Fuzzy semi-active stability augmentation system  code 
*/
/*
 * File: Master_control_fuzzy_standalone_new.c
 * Code generated for Simulink model 'Master_control_fuzzy_standalone_new'.
 * Embedded hardware selection: ARM Compatible->ARM Cortex */


#include "Master_control_fuzzy_standalone_new.h"
#include "Master_control_fuzzy_standalone_new_private.h"
#include "Master_control_fuzzy_standalone_new_dt.h"

/* Block signals (default storage) */
B_Master_control_fuzzy_standa_T Master_control_fuzzy_standalo_B;

/* Block states (default storage) */
DW_Master_control_fuzzy_stand_T Master_control_fuzzy_standal_DW;

/* Real-time model */
RT_MODEL_Master_control_fuzzy_T Master_control_fuzzy_standal_M_;
RT_MODEL_Master_control_fuzzy_T *const Master_control_fuzzy_standal_M =
  &Master_control_fuzzy_standal_M_;

/* Forward declaration for local functions */
static void Master_control_fuzzy_sta_input1(real_T x1, real_T *lmfNS, real_T
  *umfNS, real_T *lmfZS, real_T *umfZS, real_T *lmfPS, real_T *umfPS);

/* Forward declaration for local functions */
static void Master_contr_SystemCore_release(dsp_simulink_MovingRMS_Master_T *obj);
static void Master_contro_SystemCore_delete(dsp_simulink_MovingRMS_Master_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingRMS_Master_T *obj);

/* Forward declaration for local functions */
static real_T Master_control_fu_rt_atan2d_snf(real_T u0, real_T u1);
static real_T Master_control_fuzzy_stan_trimf(real_T x, const real_T params[3]);
static void Master_control_fuzzy_st_trimf_a(const real_T x[50], const real_T
  params[3], real_T y[50]);
static void Mast_createMamdaniOutputMFCache(const real_T outputSamplePoints[150],
  real_T outputMFCache[450]);
static int32_T Master_control_fuzzy_standa_abs(int32_T x);
static real_T Master_contro_evaluateAndMethod(const real_T x[2]);
static real_T Master_control_evaluateOrMethod(const real_T x[2]);
static void matlabCodegenHandle_matlabCod_j(codertarget_arduinobase_inter_T *obj);
static void arduino_AnalogInput_set_pinNumb(codertarget_arduinobase_inter_T *obj,
  e_codertarget_arduinobase_int_T *iobj_0);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem'
 *    '<S2>/If Action Subsystem'
 *    '<S3>/If Action Subsystem'
 *    '<S4>/If Action Subsystem'
 *    '<S33>/If Action Subsystem'
 *    '<S37>/If Action Subsystem'
 *    '<S41>/If Action Subsystem'
 *    '<S45>/If Action Subsystem'
 */
void Master_contro_IfActionSubsystem(real_T *rty_dfn,
  P_IfActionSubsystem_Master_co_T *localP)
{
  /* SignalConversion: '<S24>/OutportBufferFordfn' incorporates:
   *  Constant: '<S24>/Constant'
   */
  *rty_dfn = localP->Constant_Value;
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void Master_control_fuzzy_sta_input1(real_T x1, real_T *lmfNS, real_T
  *umfNS, real_T *lmfZS, real_T *umfZS, real_T *lmfPS, real_T *umfPS)
{
  if (x1 <= -3.5) {
    *umfNS = 0.0;
  } else if ((x1 > -3.5) && (x1 <= -0.8)) {
    *umfNS = (x1 - -3.5) / 2.7;
  } else if ((x1 > -0.8) && (x1 <= -0.15)) {
    *umfNS = 1.0;
  } else if ((x1 > -0.15) && (x1 <= 0.05)) {
    *umfNS = (0.05 - x1) / 0.2;
  } else {
    *umfNS = 0.0;
  }

  if (x1 <= -3.2) {
    *lmfNS = 0.0;
  } else if ((x1 > -3.2) && (x1 <= -0.6)) {
    *lmfNS = (x1 - -3.2) / 2.6 * 0.9;
  } else if ((x1 > -0.6) && (x1 <= -0.1)) {
    *lmfNS = (-0.1 - x1) / 0.5 * 0.9;
  } else {
    *lmfNS = 0.0;
  }

  if (x1 <= -0.3) {
    *umfZS = 0.0;
  } else if ((x1 > -0.3) && (x1 <= -0.02)) {
    *umfZS = (x1 - -0.3) / 0.27999999999999997;
  } else if ((x1 > -0.02) && (x1 <= 0.02)) {
    *umfZS = 1.0;
  } else if ((x1 > 0.02) && (x1 <= 0.25)) {
    *umfZS = (0.25 - x1) / 0.23;
  } else {
    *umfZS = 0.0;
  }

  if (x1 <= -0.15) {
    *lmfZS = 0.0;
  } else if ((x1 > -0.15) && (x1 <= 0.0)) {
    *lmfZS = (x1 - -0.15) / 0.15 * 0.9;
  } else if ((x1 > 0.0) && (x1 <= 0.15)) {
    *lmfZS = (0.15 - x1) / 0.15 * 0.9;
  } else {
    *lmfZS = 0.0;
  }

  if (x1 <= 0.001) {
    *umfPS = 0.0;
  } else if ((x1 > 0.001) && (x1 <= 0.1501)) {
    *umfPS = (x1 - 0.001) / 0.1491;
  } else if ((x1 > 0.1501) && (x1 <= 0.8)) {
    *umfPS = 1.0;
  } else if ((x1 > 0.8) && (x1 <= 3.5)) {
    *umfPS = (3.5 - x1) / 2.7;
  } else {
    *umfPS = 0.0;
  }

  if (x1 <= 0.1) {
    *lmfPS = 0.0;
  } else if ((x1 > 0.1) && (x1 <= 0.5)) {
    *lmfPS = (x1 - 0.1) / 0.4 * 0.9;
  } else if ((x1 > 0.5) && (x1 <= 3.2)) {
    *lmfPS = (3.2 - x1) / 2.7 * 0.9;
  } else {
    *lmfPS = 0.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function'
 *    '<S6>/MATLAB Function'
 *    '<S7>/MATLAB Function'
 *    '<S8>/MATLAB Function'
 */
void Master_control_f_MATLABFunction(real_T rtu_x1, real_T rtu_x2, real_T *rty_U,
  B_MATLABFunction_Master_contr_T *localB)
{
  real_T uluL_denum;
  real_T umuL_num;
  real_T umuL_denum;
  real_T uluR_num;
  real_T uluR_denum;
  real_T umuR_num;
  real_T umuR_denum;
  int32_T s;
  static const int16_T b[9] = { 1077, 1077, 3448, 3448, 3448, 3448, 3448, 15686,
    15686 };

  static const int16_T c[9] = { 1730, 1730, 3548, 3548, 3548, 3548, 3548, 16700,
    16700 };

  Master_control_fuzzy_sta_input1(rtu_x1, &umuL_num, &umuL_denum,
    &localB->uluL_num, &uluL_denum, &uluR_num, &umuR_num);
  if (rtu_x2 <= -3.5) {
    umuR_denum = 0.0;
  } else if ((rtu_x2 > -3.5) && (rtu_x2 <= -1.5)) {
    umuR_denum = (rtu_x2 - -3.5) / 2.0;
  } else if ((rtu_x2 > -1.5) && (rtu_x2 <= -0.5)) {
    umuR_denum = 1.0;
  } else {
    umuR_denum = 0.0;
  }

  if (rtu_x2 <= -3.25) {
    uluR_denum = 0.0;
  } else if ((rtu_x2 > -3.25) && (rtu_x2 <= -1.0)) {
    uluR_denum = (rtu_x2 - -3.25) / 2.25 * 0.9;
  } else if ((rtu_x2 > -1.0) && (rtu_x2 <= -0.249)) {
    uluR_denum = (-0.249 - rtu_x2) / 0.751 * 0.9;
  } else {
    uluR_denum = 0.0;
  }

  if (rtu_x2 <= -0.49) {
    localB->umfZ = 0.0;
  } else if ((rtu_x2 > -0.49) && (rtu_x2 <= -0.125)) {
    localB->umfZ = (rtu_x2 - -0.49) / 0.365;
  } else if ((rtu_x2 > -0.125) && (rtu_x2 <= 0.125)) {
    localB->umfZ = 1.0;
  } else if ((rtu_x2 > 0.125) && (rtu_x2 <= 0.5)) {
    localB->umfZ = (0.5 - rtu_x2) / 0.375;
  } else {
    localB->umfZ = 0.0;
  }

  if (rtu_x2 <= -0.249) {
    localB->lmfZ = 0.0;
  } else if ((rtu_x2 > -0.249) && (rtu_x2 <= 0.0)) {
    localB->lmfZ = (rtu_x2 - -0.249) / 0.249 * 0.9;
  } else if ((rtu_x2 > 0.0) && (rtu_x2 <= 0.251)) {
    localB->lmfZ = (0.251 - rtu_x2) / 0.251 * 0.9;
  } else {
    localB->lmfZ = 0.0;
  }

  if (rtu_x2 <= 0.001) {
    localB->umfP = 0.0;
  } else if ((rtu_x2 > 0.001) && (rtu_x2 <= 0.375)) {
    localB->umfP = (rtu_x2 - 0.001) / 0.374;
  } else if ((rtu_x2 > 0.375) && (rtu_x2 <= 1.5)) {
    localB->umfP = 1.0;
  } else if ((rtu_x2 > 1.5) && (rtu_x2 <= 3.5)) {
    localB->umfP = (3.5 - rtu_x2) / 2.0;
  } else {
    localB->umfP = 0.0;
  }

  if (rtu_x2 <= 0.25) {
    localB->lmfP = 0.0;
  } else if ((rtu_x2 > 0.25) && (rtu_x2 <= 1.0)) {
    localB->lmfP = (rtu_x2 - 0.25) / 0.75 * 0.9;
  } else if ((rtu_x2 > 1.0) && (rtu_x2 <= 3.25)) {
    localB->lmfP = (3.25 - rtu_x2) / 2.25 * 0.9;
  } else {
    localB->lmfP = 0.0;
  }

  if (umuL_num < localB->lmfP) {
    localB->fl[0] = umuL_num;
  } else {
    localB->fl[0] = localB->lmfP;
  }

  if (uluR_num < uluR_denum) {
    localB->fl[1] = uluR_num;
  } else {
    localB->fl[1] = uluR_denum;
  }

  if (umuL_num < localB->lmfZ) {
    localB->fl[2] = umuL_num;
  } else {
    localB->fl[2] = localB->lmfZ;
  }

  if (localB->uluL_num < uluR_denum) {
    localB->fl[3] = localB->uluL_num;
  } else {
    localB->fl[3] = uluR_denum;
  }

  if (localB->uluL_num < localB->lmfZ) {
    localB->fl[4] = localB->uluL_num;
  } else {
    localB->fl[4] = localB->lmfZ;
  }

  if (localB->uluL_num < localB->lmfP) {
    localB->fl[5] = localB->uluL_num;
  } else {
    localB->fl[5] = localB->lmfP;
  }

  if (uluR_num < localB->lmfZ) {
    localB->fl[6] = uluR_num;
  } else {
    localB->fl[6] = localB->lmfZ;
  }

  if (umuL_num < uluR_denum) {
    localB->fl[7] = umuL_num;
  } else {
    localB->fl[7] = uluR_denum;
  }

  if (uluR_num < localB->lmfP) {
    localB->fl[8] = uluR_num;
  } else {
    localB->fl[8] = localB->lmfP;
  }

  if (umuL_denum < localB->umfP) {
    localB->fu[0] = umuL_denum;
  } else {
    localB->fu[0] = localB->umfP;
  }

  if (umuR_num < umuR_denum) {
    localB->fu[1] = umuR_num;
  } else {
    localB->fu[1] = umuR_denum;
  }

  if (umuL_denum < localB->umfZ) {
    localB->fu[2] = umuL_denum;
  } else {
    localB->fu[2] = localB->umfZ;
  }

  if (uluL_denum < umuR_denum) {
    localB->fu[3] = uluL_denum;
  } else {
    localB->fu[3] = umuR_denum;
  }

  if (uluL_denum < localB->umfZ) {
    localB->fu[4] = uluL_denum;
  } else {
    localB->fu[4] = localB->umfZ;
  }

  if (uluL_denum < localB->umfP) {
    localB->fu[5] = uluL_denum;
  } else {
    localB->fu[5] = localB->umfP;
  }

  if (umuR_num < localB->umfZ) {
    localB->fu[6] = umuR_num;
  } else {
    localB->fu[6] = localB->umfZ;
  }

  if (umuL_denum < umuR_denum) {
    localB->fu[7] = umuL_denum;
  } else {
    localB->fu[7] = umuR_denum;
  }

  if (umuR_num < localB->umfP) {
    localB->fu[8] = umuR_num;
  } else {
    localB->fu[8] = localB->umfP;
  }

  localB->uluL_num = 0.0;
  uluL_denum = 0.0;
  umuL_num = 0.0;
  umuL_denum = 0.0;
  for (s = 0; s < 9; s++) {
    localB->uluL_num += localB->fl[s] * (real_T)b[s];
    uluL_denum += localB->fl[s];
    umuL_num += localB->fu[s] * (real_T)b[s];
    umuL_denum += localB->fu[s];
  }

  uluR_num = localB->uluL_num / uluL_denum;
  umuL_num /= umuL_denum;
  if ((uluR_num < umuL_num) || rtIsNaN(umuL_num)) {
    umuL_num = uluR_num;
  }

  umuL_denum = 0.0;
  localB->uluL_num = 0.0;
  uluL_denum = 0.0;
  for (s = 0; s < 9; s++) {
    umuL_denum += localB->fu[s] - localB->fl[s];
    localB->uluL_num += localB->fu[s];
    uluL_denum += localB->fl[s];
  }

  umuL_denum /= localB->uluL_num * uluL_denum;
  localB->uluL_num = 0.0;
  uluL_denum = 0.0;
  uluR_num = 0.0;
  uluR_denum = 0.0;
  umuR_num = 0.0;
  umuR_denum = 0.0;
  for (s = 0; s < 9; s++) {
    localB->uluL_num += ((real_T)b[s] - 1077.0) * localB->fl[s];
    uluL_denum += (15686.0 - (real_T)b[s]) * localB->fu[s];
    uluR_num += localB->fl[s] * (real_T)c[s];
    uluR_denum += localB->fl[s];
    umuR_num += localB->fu[s] * (real_T)c[s];
    umuR_denum += localB->fu[s];
  }

  uluR_num /= uluR_denum;
  umuR_num /= umuR_denum;
  if ((uluR_num > umuR_num) || rtIsNaN(umuR_num)) {
    umuR_num = uluR_num;
  }

  uluR_num = 0.0;
  umuR_denum = 0.0;
  for (s = 0; s < 9; s++) {
    uluR_num += ((real_T)c[s] - 1730.0) * localB->fu[s];
    umuR_denum += (16700.0 - (real_T)c[s]) * localB->fl[s];
  }

  *rty_U = (((umuL_num - localB->uluL_num * uluL_denum / (localB->uluL_num +
    uluL_denum) * umuL_denum) + umuL_num) / 2.0 + ((uluR_num * umuR_denum /
              (uluR_num + umuR_denum) * umuL_denum + umuR_num) + umuR_num) / 2.0)
    / 2.0;
}

static void Master_contr_SystemCore_release(dsp_simulink_MovingRMS_Master_T *obj)
{
  e_dsp_private_ExponentialMovi_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Master_contro_SystemCore_delete(dsp_simulink_MovingRMS_Master_T *obj)
{
  Master_contr_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingRMS_Master_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Master_contro_SystemCore_delete(obj);
  }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void Master_control__MovingRMS3_Init(DW_MovingRMS3_Master_control__T *localDW)
{
  /* InitializeConditions for MATLABSystem: '<S51>/Moving RMS3' */
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pwN = 1.0;
    localDW->obj.pStatistic->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S51>/Moving RMS3' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void Master_control_MovingRMS3_Start(DW_MovingRMS3_Master_control__T *localDW,
  P_MovingRMS3_Master_control_f_T *localP)
{
  boolean_T flag;

  /* Start for MATLABSystem: '<S51>/Moving RMS3' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  if (localDW->obj.isInitialized == 1) {
    localDW->obj.TunablePropsChanged = true;
  }

  localDW->obj.ForgettingFactor = localP->MovingRMS3_ForgettingFactor;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_0.isInitialized = 0;
  flag = (localDW->gobj_0.isInitialized == 1);
  if (flag) {
    localDW->gobj_0.TunablePropsChanged = true;
  }

  if (localDW->obj.ForgettingFactor != 0.0) {
    localDW->gobj_0.ForgettingFactor = localDW->obj.ForgettingFactor;
  } else {
    localDW->gobj_0.ForgettingFactor = 2.2204460492503131E-16;
  }

  localDW->obj.pStatistic = &localDW->gobj_0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<S51>/Moving RMS3' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void Master_control_fuzzy_MovingRMS3(real_T rtu_0,
  B_MovingRMS3_Master_control_f_T *localB, DW_MovingRMS3_Master_control__T
  *localDW, P_MovingRMS3_Master_control_f_T *localP)
{
  boolean_T flag;
  real_T y;
  real_T pwLocal;
  real_T pmLocal;
  real_T lambda;

  /* MATLABSystem: '<S51>/Moving RMS3' */
  if (localDW->obj.ForgettingFactor != localP->MovingRMS3_ForgettingFactor) {
    if (localDW->obj.isInitialized == 1) {
      localDW->obj.TunablePropsChanged = true;
    }

    localDW->obj.ForgettingFactor = localP->MovingRMS3_ForgettingFactor;
  }

  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
    flag = (localDW->obj.pStatistic->isInitialized == 1);
    if (flag) {
      localDW->obj.pStatistic->TunablePropsChanged = true;
    }

    localDW->obj.pStatistic->ForgettingFactor = localDW->obj.ForgettingFactor;
  }

  y = fabs(rtu_0);
  if (localDW->obj.pStatistic->isInitialized != 1) {
    localDW->obj.pStatistic->isSetupComplete = false;
    localDW->obj.pStatistic->isInitialized = 1;
    localDW->obj.pStatistic->pwN = 1.0;
    localDW->obj.pStatistic->pmN = 0.0;
    localDW->obj.pStatistic->plambda = localDW->obj.pStatistic->ForgettingFactor;
    localDW->obj.pStatistic->isSetupComplete = true;
    localDW->obj.pStatistic->TunablePropsChanged = false;
    localDW->obj.pStatistic->pwN = 1.0;
    localDW->obj.pStatistic->pmN = 0.0;
  }

  if (localDW->obj.pStatistic->TunablePropsChanged) {
    localDW->obj.pStatistic->TunablePropsChanged = false;
    localDW->obj.pStatistic->plambda = localDW->obj.pStatistic->ForgettingFactor;
  }

  pwLocal = localDW->obj.pStatistic->pwN;
  pmLocal = localDW->obj.pStatistic->pmN;
  lambda = localDW->obj.pStatistic->plambda;
  y = (1.0 - 1.0 / pwLocal) * pmLocal + 1.0 / pwLocal * (y * y);
  localDW->obj.pStatistic->pwN = lambda * pwLocal + 1.0;
  localDW->obj.pStatistic->pmN = y;
  localB->MovingRMS3 = sqrt(y);

  /* End of MATLABSystem: '<S51>/Moving RMS3' */
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void Master_control__MovingRMS3_Term(DW_MovingRMS3_Master_control__T *localDW)
{
  /* Terminate for MATLABSystem: '<S51>/Moving RMS3' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static real_T Master_control_fu_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      Master_control_fuzzy_standalo_B.u0 = 1;
    } else {
      Master_control_fuzzy_standalo_B.u0 = -1;
    }

    if (u1 > 0.0) {
      Master_control_fuzzy_standalo_B.u1 = 1;
    } else {
      Master_control_fuzzy_standalo_B.u1 = -1;
    }

    y = atan2(Master_control_fuzzy_standalo_B.u0,
              Master_control_fuzzy_standalo_B.u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S56>/Evaluate Rule Antecedents' */
static real_T Master_control_fuzzy_stan_trimf(real_T x, const real_T params[3])
{
  real_T y;
  y = 0.0;
  if ((params[0] != params[1]) && (params[0] < x) && (x < params[1])) {
    y = 1.0 / (params[1] - params[0]) * (x - params[0]);
  }

  if ((params[1] != params[2]) && (params[1] < x) && (x < params[2])) {
    y = 1.0 / (params[2] - params[1]) * (params[2] - x);
  }

  if (x == params[1]) {
    y = 1.0;
  }

  return y;
}

/* Function for MATLAB Function: '<S56>/Evaluate Rule Consequents' */
static void Master_control_fuzzy_st_trimf_a(const real_T x[50], const real_T
  params[3], real_T y[50])
{
  Master_control_fuzzy_standalo_B.a = params[0];
  Master_control_fuzzy_standalo_B.b = params[1];
  Master_control_fuzzy_standalo_B.c = params[2];
  for (Master_control_fuzzy_standalo_B.i = 0; Master_control_fuzzy_standalo_B.i <
       50; Master_control_fuzzy_standalo_B.i++) {
    y[Master_control_fuzzy_standalo_B.i] = 0.0;
    if ((Master_control_fuzzy_standalo_B.a != Master_control_fuzzy_standalo_B.b)
        && (Master_control_fuzzy_standalo_B.a <
            x[Master_control_fuzzy_standalo_B.i]) &&
        (x[Master_control_fuzzy_standalo_B.i] <
         Master_control_fuzzy_standalo_B.b)) {
      y[Master_control_fuzzy_standalo_B.i] = 1.0 /
        (Master_control_fuzzy_standalo_B.b - Master_control_fuzzy_standalo_B.a) *
        (x[Master_control_fuzzy_standalo_B.i] -
         Master_control_fuzzy_standalo_B.a);
    }

    if ((Master_control_fuzzy_standalo_B.b != Master_control_fuzzy_standalo_B.c)
        && (Master_control_fuzzy_standalo_B.b <
            x[Master_control_fuzzy_standalo_B.i]) &&
        (x[Master_control_fuzzy_standalo_B.i] <
         Master_control_fuzzy_standalo_B.c)) {
      y[Master_control_fuzzy_standalo_B.i] = 1.0 /
        (Master_control_fuzzy_standalo_B.c - Master_control_fuzzy_standalo_B.b) *
        (Master_control_fuzzy_standalo_B.c - x[Master_control_fuzzy_standalo_B.i]);
    }

    if (x[Master_control_fuzzy_standalo_B.i] ==
        Master_control_fuzzy_standalo_B.b) {
      y[Master_control_fuzzy_standalo_B.i] = 1.0;
    }
  }
}

/* Function for MATLAB Function: '<S56>/Evaluate Rule Consequents' */
static void Mast_createMamdaniOutputMFCache(const real_T outputSamplePoints[150],
  real_T outputMFCache[450])
{
  static const real_T b[3] = { 0.5012, 12.96, 40.37 };

  static const real_T c[3] = { 13.41, 50.34, 100.2 };

  static const real_T d[3] = { 87.86, 150.0, 212.2 };

  static const real_T e[3] = { -0.278, 71.35, 143.0 };

  static const real_T f[3] = { 96.723044397463, 187.0, 293.0 };

  static const real_T g[3] = { 250.0, 333.3, 555.6 };

  static const real_T h[3] = { -0.1875, 9.375, 26.25 };

  static const real_T i[3] = { 15.0, 112.5, 225.0 };

  static const real_T j[3] = { 188.0, 252.748414376321, 338.0 };

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, b,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, c,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[1 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, d,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[2 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0 + 1];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, e,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[3 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0 + 1];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, f,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[4 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0 + 1];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, g,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[5 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0 + 2];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, h,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[6 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0 + 2];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, i,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[7 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }

  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    Master_control_fuzzy_standalo_B.outputSamplePoints[Master_control_fuzzy_standalo_B.i0]
      = outputSamplePoints[3 * Master_control_fuzzy_standalo_B.i0 + 2];
  }

  Master_control_fuzzy_st_trimf_a
    (Master_control_fuzzy_standalo_B.outputSamplePoints, j,
     Master_control_fuzzy_standalo_B.dv0);
  for (Master_control_fuzzy_standalo_B.i0 = 0;
       Master_control_fuzzy_standalo_B.i0 < 50;
       Master_control_fuzzy_standalo_B.i0++) {
    outputMFCache[8 + 9 * Master_control_fuzzy_standalo_B.i0] =
      Master_control_fuzzy_standalo_B.dv0[Master_control_fuzzy_standalo_B.i0];
  }
}

/* Function for MATLAB Function: '<S56>/Evaluate Rule Consequents' */
static int32_T Master_control_fuzzy_standa_abs(int32_T x)
{
  int32_T y;
  if (x < 0) {
    if (x <= MIN_int32_T) {
      y = MAX_int32_T;
    } else {
      y = -x;
    }
  } else {
    y = x;
  }

  return y;
}

/* Function for MATLAB Function: '<S56>/Evaluate Rule Consequents' */
static real_T Master_contro_evaluateAndMethod(const real_T x[2])
{
  real_T y;
  if (x[0] > x[1]) {
    y = x[1];
  } else if (rtIsNaN(x[0])) {
    if (!rtIsNaN(x[1])) {
      y = x[1];
    } else {
      y = x[0];
    }
  } else {
    y = x[0];
  }

  return y;
}

/* Function for MATLAB Function: '<S56>/Evaluate Rule Consequents' */
static real_T Master_control_evaluateOrMethod(const real_T x[2])
{
  real_T y;
  if (x[0] < x[1]) {
    y = x[1];
  } else if (rtIsNaN(x[0])) {
    if (!rtIsNaN(x[1])) {
      y = x[1];
    } else {
      y = x[0];
    }
  } else {
    y = x[0];
  }

  return y;
}

static void matlabCodegenHandle_matlabCod_j(codertarget_arduinobase_inter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void arduino_AnalogInput_set_pinNumb(codertarget_arduinobase_inter_T *obj,
  e_codertarget_arduinobase_int_T *iobj_0)
{
  iobj_0->AvailablePwmPinNames.f1 = '2';
  iobj_0->AvailablePwmPinNames.f2 = '3';
  iobj_0->AvailablePwmPinNames.f3 = '4';
  iobj_0->AvailablePwmPinNames.f4 = '5';
  iobj_0->AvailablePwmPinNames.f5 = '6';
  iobj_0->AvailablePwmPinNames.f6 = '7';
  iobj_0->AvailablePwmPinNames.f7 = '8';
  iobj_0->AvailablePwmPinNames.f8 = '9';
  iobj_0->AvailablePwmPinNames.f9[0] = '1';
  iobj_0->AvailablePwmPinNames.f9[1] = '0';
  iobj_0->AvailablePwmPinNames.f10[0] = '1';
  iobj_0->AvailablePwmPinNames.f10[1] = '1';
  iobj_0->AvailablePwmPinNames.f11[0] = '1';
  iobj_0->AvailablePwmPinNames.f11[1] = '2';
  iobj_0->AvailablePwmPinNames.f12[0] = '1';
  iobj_0->AvailablePwmPinNames.f12[1] = '3';
  obj->Hw = iobj_0;
}

/* Model step function */
void Master_control_fuzzy_standalone_new_step(void)
{
  uint16_T rtb_AnalogInput3_d_0;
  static const int8_T b[27] = { 3, 2, 2, 1, 1, 1, 3, 2, 2, 3, 3, 2, 1, 2, 3, 1,
    1, 3, 3, 3, 2, 1, 2, 3, 1, 3, 1 };

  static const real_T c[3] = { 28.8, 48.0, 80.0 };

  static const real_T d[3] = { 4.8, 19.2, 32.0 };

  static const real_T e[3] = { -1.6, 4.8, 9.6 };

  static const real_T f[3] = { 24.0, 46.67, 93.33 };

  static const real_T g[3] = { 4.0, 13.33, 26.67 };

  static const real_T h[3] = { -1.333, 4.0, 8.0 };

  static const real_T i[3] = { 1.5, 4.0, 12.0 };

  static const real_T j[3] = { 0.09, 1.0, 2.0 };

  static const real_T k[3] = { 0.0, 0.05, 1.0 };

  static const int8_T b_0[27] = { 3, 2, 1, 1, 1, 1, 2, 1, 1, 3, 3, 2, 1, 2, 3, 2,
    1, 3, 3, 3, 2, 1, 2, 3, 2, 3, 1 };

  static const int16_T b_1[6] = { 1, 0, 0, 150, 500, 300 };

  boolean_T rtb_NotEqual;
  int8_T rtAction;

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (Master_control_fuzzy_standal_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRan_fz);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_b);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_n);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_e);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanBC);

  /* MATLABSystem: '<S22>/Analog Input3' */
  if (Master_control_fuzzy_standal_DW.obj_k.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_mh) {
    Master_control_fuzzy_standal_DW.obj_k.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_mh;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_k.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_k.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* DiscreteTransferFcn: '<S22>/LPFl1' incorporates:
   *  Constant: '<S22>/Conversion_volt'
   *  MATLABSystem: '<S22>/Analog Input3'
   *  Product: '<S22>/Product8'
   */
  Master_control_fuzzy_standal_DW.LPFl1_tmp = ((real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion_volt_Value -
    Master_control_fuzzy_standalo_P.LPFl1_DenCoef[1] *
    Master_control_fuzzy_standal_DW.LPFl1_states) /
    Master_control_fuzzy_standalo_P.LPFl1_DenCoef[0];

  /* SampleTimeMath: '<S239>/TSamp' incorporates:
   *  DiscreteTransferFcn: '<S22>/LPFl1'
   *  Lookup_n-D: '<S22>/front left'
   *
   * About '<S239>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp = look1_binlxpw
    (Master_control_fuzzy_standalo_P.LPFl1_NumCoef[0] *
     Master_control_fuzzy_standal_DW.LPFl1_tmp +
     Master_control_fuzzy_standalo_P.LPFl1_NumCoef[1] *
     Master_control_fuzzy_standal_DW.LPFl1_states,
     Master_control_fuzzy_standalo_P.frontleft_bp01Data,
     Master_control_fuzzy_standalo_P.frontleft_tableData, 2U) *
    Master_control_fuzzy_standalo_P.TSamp_WtEt;

  /* Sum: '<S239>/Diff' incorporates:
   *  UnitDelay: '<S239>/UD'
   *
   * Block description for '<S239>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S239>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Diff = Master_control_fuzzy_standalo_B.TSamp -
    Master_control_fuzzy_standal_DW.UD_DSTATE;

  /* DiscreteTransferFcn: '<S5>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_tmp =
    (Master_control_fuzzy_standalo_B.Diff -
     Master_control_fuzzy_standalo_P.HF2_DenCoef[1] *
     Master_control_fuzzy_standal_DW.HF2_states) /
    Master_control_fuzzy_standalo_P.HF2_DenCoef[0];

  /* DiscreteTransferFcn: '<S5>/LPF2' incorporates:
   *  DiscreteTransferFcn: '<S5>/H.F2'
   */
  Master_control_fuzzy_standal_DW.LPF2_tmp =
    ((Master_control_fuzzy_standalo_P.HF2_NumCoef[0] *
      Master_control_fuzzy_standal_DW.HF2_tmp +
      Master_control_fuzzy_standalo_P.HF2_NumCoef[1] *
      Master_control_fuzzy_standal_DW.HF2_states) -
     Master_control_fuzzy_standalo_P.LPF2_DenCoef[1] *
     Master_control_fuzzy_standal_DW.LPF2_states) /
    Master_control_fuzzy_standalo_P.LPF2_DenCoef[0];
  Master_control_fuzzy_standalo_B.LPF2 =
    Master_control_fuzzy_standalo_P.LPF2_NumCoef[0] *
    Master_control_fuzzy_standal_DW.LPF2_tmp +
    Master_control_fuzzy_standalo_P.LPF2_NumCoef[1] *
    Master_control_fuzzy_standal_DW.LPF2_states;

  /* DiscreteIntegrator: '<S5>/s.d1' */
  Master_control_fuzzy_standalo_B.sd1 =
    Master_control_fuzzy_standalo_P.sd1_gainval *
    Master_control_fuzzy_standalo_B.LPF2 +
    Master_control_fuzzy_standal_DW.sd1_DSTATE;

  /* MATLABSystem: '<S9>/Analog Input2' */
  if (Master_control_fuzzy_standal_DW.obj_ku2.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput2_SampleTime) {
    Master_control_fuzzy_standal_DW.obj_ku2.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput2_SampleTime;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_ku2.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_ku2.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<S9>/Conversion'
   *  MATLABSystem: '<S9>/Analog Input2'
   */
  Master_control_fuzzy_standalo_B.VACC_FL = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion_Value;

  /* MATLABSystem: '<S9>/Analog Input1' */
  if (Master_control_fuzzy_standal_DW.obj_er.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime) {
    Master_control_fuzzy_standal_DW.obj_er.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_er.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_er.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S9>/Product2' incorporates:
   *  Constant: '<S9>/Conversion1'
   *  MATLABSystem: '<S9>/Analog Input1'
   */
  Master_control_fuzzy_standalo_B.VACCFR = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion1_Value;

  /* MATLABSystem: '<S9>/Analog Input3' */
  if (Master_control_fuzzy_standal_DW.obj_kt.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime) {
    Master_control_fuzzy_standal_DW.obj_kt.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_kt.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_kt.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S9>/Product3' incorporates:
   *  Constant: '<S9>/Conversion2'
   *  MATLABSystem: '<S9>/Analog Input3'
   */
  Master_control_fuzzy_standalo_B.VACCRL_ = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion2_Value;

  /* MATLABSystem: '<S9>/Analog Input4' */
  if (Master_control_fuzzy_standal_DW.obj_io.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput4_SampleTime) {
    Master_control_fuzzy_standal_DW.obj_io.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput4_SampleTime;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_io.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_io.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S9>/Product4' incorporates:
   *  Constant: '<S9>/Conversion3'
   *  MATLABSystem: '<S9>/Analog Input4'
   */
  Master_control_fuzzy_standalo_B.VACC_RR = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion3_Value;

  /* Clock: '<S50>/Clock' incorporates:
   *  Clock: '<Root>/Clock'
   */
  Master_control_fuzzy_standalo_B.Filter_ny =
    Master_control_fuzzy_standal_M->Timing.t[0];

  /* If: '<S50>/If loop ' incorporates:
   *  Clock: '<S50>/Clock'
   */
  if (Master_control_fuzzy_standalo_B.Filter_ny <= 3.0) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* MATLABSystem: '<S51>/Moving RMS' */
    Master_control_fuzzy_MovingRMS3(Master_control_fuzzy_standalo_B.VACC_FL,
      &Master_control_fuzzy_standalo_B.MovingRMS,
      &Master_control_fuzzy_standal_DW.MovingRMS,
      &Master_control_fuzzy_standalo_P.MovingRMS);

    /* MATLABSystem: '<S51>/Moving RMS1' */
    Master_control_fuzzy_MovingRMS3(Master_control_fuzzy_standalo_B.VACCFR,
      &Master_control_fuzzy_standalo_B.MovingRMS1,
      &Master_control_fuzzy_standal_DW.MovingRMS1,
      &Master_control_fuzzy_standalo_P.MovingRMS1);

    /* MATLABSystem: '<S51>/Moving RMS2' */
    Master_control_fuzzy_MovingRMS3(Master_control_fuzzy_standalo_B.VACCRL_,
      &Master_control_fuzzy_standalo_B.MovingRMS2,
      &Master_control_fuzzy_standal_DW.MovingRMS2,
      &Master_control_fuzzy_standalo_P.MovingRMS2);

    /* MATLABSystem: '<S51>/Moving RMS3' */
    Master_control_fuzzy_MovingRMS3(Master_control_fuzzy_standalo_B.VACC_RR,
      &Master_control_fuzzy_standalo_B.MovingRMS3,
      &Master_control_fuzzy_standal_DW.MovingRMS3,
      &Master_control_fuzzy_standalo_P.MovingRMS3);
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Outputs for SubSystem: '<S50>/If Action Subsystem' */
  } else {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* Sum: '<S52>/Add2' */
    Master_control_fuzzy_standalo_B.Add2_b =
      Master_control_fuzzy_standalo_B.VACC_FL -
      Master_control_fuzzy_standalo_B.MovingRMS.MovingRMS3;

    /* Sum: '<S52>/Add1' */
    Master_control_fuzzy_standalo_B.Add1_n =
      Master_control_fuzzy_standalo_B.VACCFR -
      Master_control_fuzzy_standalo_B.MovingRMS1.MovingRMS3;

    /* Sum: '<S52>/Add3' */
    Master_control_fuzzy_standalo_B.Add3 =
      Master_control_fuzzy_standalo_B.VACCRL_ -
      Master_control_fuzzy_standalo_B.MovingRMS2.MovingRMS3;

    /* Sum: '<S52>/Add4' */
    Master_control_fuzzy_standalo_B.Add4_n =
      Master_control_fuzzy_standalo_B.VACC_RR -
      Master_control_fuzzy_standalo_B.MovingRMS3.MovingRMS3;
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Outputs for SubSystem: '<S50>/If Action Subsystem1' */
  }

  Master_control_fuzzy_standal_DW.Ifloop_ActiveSubsystem = rtAction;

  /* End of If: '<S50>/If loop ' */

  /* Gain: '<S9>/Gain3' incorporates:
   *  Constant: '<S9>/Constant9'
   *  Product: '<S9>/Product5'
   */
  Master_control_fuzzy_standalo_B.Gain3 = Master_control_fuzzy_standalo_B.Add2_b
    * Master_control_fuzzy_standalo_P.Constant9_Value *
    Master_control_fuzzy_standalo_P.Gain3_Gain;

  /* DiscreteTransferFcn: '<S9>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_tmp_k =
    (Master_control_fuzzy_standalo_B.Gain3 -
     Master_control_fuzzy_standalo_P.HF2_DenCoef_f[1] *
     Master_control_fuzzy_standal_DW.HF2_states_a) /
    Master_control_fuzzy_standalo_P.HF2_DenCoef_f[0];

  /* DiscreteTransferFcn: '<S9>/LPF2' incorporates:
   *  DiscreteTransferFcn: '<S9>/H.F2'
   */
  Master_control_fuzzy_standal_DW.LPF2_tmp_i =
    ((Master_control_fuzzy_standalo_P.HF2_NumCoef_i[0] *
      Master_control_fuzzy_standal_DW.HF2_tmp_k +
      Master_control_fuzzy_standalo_P.HF2_NumCoef_i[1] *
      Master_control_fuzzy_standal_DW.HF2_states_a) -
     Master_control_fuzzy_standalo_P.LPF2_DenCoef_g[1] *
     Master_control_fuzzy_standal_DW.LPF2_states_e) /
    Master_control_fuzzy_standalo_P.LPF2_DenCoef_g[0];
  Master_control_fuzzy_standalo_B.LPF2_d =
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_o[0] *
    Master_control_fuzzy_standal_DW.LPF2_tmp_i +
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_o[1] *
    Master_control_fuzzy_standal_DW.LPF2_states_e;

  /* DiscreteIntegrator: '<S9>/HEAVE_VEL1' */
  Master_control_fuzzy_standalo_B.HEAVE_VEL1 =
    Master_control_fuzzy_standalo_P.HEAVE_VEL1_gainval *
    Master_control_fuzzy_standalo_B.LPF2_d +
    Master_control_fuzzy_standal_DW.HEAVE_VEL1_DSTATE;

  /* Sum: '<S9>/Add1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  Master_control_fuzzy_standalo_B.Add1 =
    Master_control_fuzzy_standalo_B.HEAVE_VEL1 +
    Master_control_fuzzy_standalo_P.Constant1_Value_f;

  /* DiscreteTransferFcn: '<S5>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_tmp =
    (Master_control_fuzzy_standalo_B.Add1 -
     Master_control_fuzzy_standalo_P.HF1_DenCoef[1] *
     Master_control_fuzzy_standal_DW.HF1_states) /
    Master_control_fuzzy_standalo_P.HF1_DenCoef[0];

  /* DiscreteTransferFcn: '<S5>/LPF1' incorporates:
   *  DiscreteTransferFcn: '<S5>/H.F1'
   */
  Master_control_fuzzy_standal_DW.LPF1_tmp =
    ((Master_control_fuzzy_standalo_P.HF1_NumCoef[0] *
      Master_control_fuzzy_standal_DW.HF1_tmp +
      Master_control_fuzzy_standalo_P.HF1_NumCoef[1] *
      Master_control_fuzzy_standal_DW.HF1_states) -
     Master_control_fuzzy_standalo_P.LPF1_DenCoef[1] *
     Master_control_fuzzy_standal_DW.LPF1_states) /
    Master_control_fuzzy_standalo_P.LPF1_DenCoef[0];
  Master_control_fuzzy_standalo_B.LPF1 =
    Master_control_fuzzy_standalo_P.LPF1_NumCoef[0] *
    Master_control_fuzzy_standal_DW.LPF1_tmp +
    Master_control_fuzzy_standalo_P.LPF1_NumCoef[1] *
    Master_control_fuzzy_standal_DW.LPF1_states;

  /* DiscreteIntegrator: '<S5>/s.d' */
  Master_control_fuzzy_standalo_B.sd =
    Master_control_fuzzy_standalo_P.sd_gainval *
    Master_control_fuzzy_standalo_B.LPF1 +
    Master_control_fuzzy_standal_DW.sd_DSTATE;

  /* Sum: '<S5>/Add1' */
  Master_control_fuzzy_standalo_B.Add1_h = Master_control_fuzzy_standalo_B.sd1 -
    Master_control_fuzzy_standalo_B.sd;

  /* MATLABSystem: '<S20>/Analog Input3' */
  if (Master_control_fuzzy_standal_DW.obj_p.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_c) {
    Master_control_fuzzy_standal_DW.obj_p.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_c;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_p.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_p.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* DiscreteTransferFcn: '<S20>/LPFr1' incorporates:
   *  Constant: '<S20>/Conversion_volt'
   *  MATLABSystem: '<S20>/Analog Input3'
   *  Product: '<S20>/Product8'
   */
  Master_control_fuzzy_standal_DW.LPFr1_tmp = ((real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion_volt_Value_l -
    Master_control_fuzzy_standalo_P.LPFr1_DenCoef[1] *
    Master_control_fuzzy_standal_DW.LPFr1_states) /
    Master_control_fuzzy_standalo_P.LPFr1_DenCoef[0];

  /* SampleTimeMath: '<S237>/TSamp' incorporates:
   *  DiscreteTransferFcn: '<S20>/LPFr1'
   *  Lookup_n-D: '<S20>/front right'
   *
   * About '<S237>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_o = look1_binlxpw
    (Master_control_fuzzy_standalo_P.LPFr1_NumCoef[0] *
     Master_control_fuzzy_standal_DW.LPFr1_tmp +
     Master_control_fuzzy_standalo_P.LPFr1_NumCoef[1] *
     Master_control_fuzzy_standal_DW.LPFr1_states,
     Master_control_fuzzy_standalo_P.frontright_bp01Data,
     Master_control_fuzzy_standalo_P.frontright_tableData, 2U) *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_o;

  /* Sum: '<S237>/Diff' incorporates:
   *  UnitDelay: '<S237>/UD'
   *
   * Block description for '<S237>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S237>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Diff_e =
    Master_control_fuzzy_standalo_B.TSamp_o -
    Master_control_fuzzy_standal_DW.UD_DSTATE_h;

  /* DiscreteTransferFcn: '<S8>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_tmp_e =
    (Master_control_fuzzy_standalo_B.Diff_e -
     Master_control_fuzzy_standalo_P.HF2_DenCoef_g[1] *
     Master_control_fuzzy_standal_DW.HF2_states_m) /
    Master_control_fuzzy_standalo_P.HF2_DenCoef_g[0];

  /* DiscreteTransferFcn: '<S8>/LPF2' incorporates:
   *  DiscreteTransferFcn: '<S8>/H.F2'
   */
  Master_control_fuzzy_standal_DW.LPF2_tmp_h =
    ((Master_control_fuzzy_standalo_P.HF2_NumCoef_f[0] *
      Master_control_fuzzy_standal_DW.HF2_tmp_e +
      Master_control_fuzzy_standalo_P.HF2_NumCoef_f[1] *
      Master_control_fuzzy_standal_DW.HF2_states_m) -
     Master_control_fuzzy_standalo_P.LPF2_DenCoef_j[1] *
     Master_control_fuzzy_standal_DW.LPF2_states_j) /
    Master_control_fuzzy_standalo_P.LPF2_DenCoef_j[0];
  Master_control_fuzzy_standalo_B.LPF2_b =
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_c[0] *
    Master_control_fuzzy_standal_DW.LPF2_tmp_h +
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_c[1] *
    Master_control_fuzzy_standal_DW.LPF2_states_j;

  /* DiscreteIntegrator: '<S8>/s.d1' */
  Master_control_fuzzy_standalo_B.sd1_i =
    Master_control_fuzzy_standalo_P.sd1_gainval_m *
    Master_control_fuzzy_standalo_B.LPF2_b +
    Master_control_fuzzy_standal_DW.sd1_DSTATE_c;

  /* Gain: '<S9>/Gain4' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Product: '<S9>/Product6'
   */
  Master_control_fuzzy_standalo_B.Gain4 = Master_control_fuzzy_standalo_B.Add1_n
    * Master_control_fuzzy_standalo_P.Constant2_Value *
    Master_control_fuzzy_standalo_P.Gain4_Gain;

  /* DiscreteTransferFcn: '<S9>/H.F3' */
  Master_control_fuzzy_standal_DW.HF3_tmp =
    (Master_control_fuzzy_standalo_B.Gain4 -
     Master_control_fuzzy_standalo_P.HF3_DenCoef[1] *
     Master_control_fuzzy_standal_DW.HF3_states) /
    Master_control_fuzzy_standalo_P.HF3_DenCoef[0];

  /* DiscreteTransferFcn: '<S9>/LPF3' incorporates:
   *  DiscreteTransferFcn: '<S9>/H.F3'
   */
  Master_control_fuzzy_standal_DW.LPF3_tmp =
    ((Master_control_fuzzy_standalo_P.HF3_NumCoef[0] *
      Master_control_fuzzy_standal_DW.HF3_tmp +
      Master_control_fuzzy_standalo_P.HF3_NumCoef[1] *
      Master_control_fuzzy_standal_DW.HF3_states) -
     Master_control_fuzzy_standalo_P.LPF3_DenCoef[1] *
     Master_control_fuzzy_standal_DW.LPF3_states) /
    Master_control_fuzzy_standalo_P.LPF3_DenCoef[0];
  Master_control_fuzzy_standalo_B.LPF3 =
    Master_control_fuzzy_standalo_P.LPF3_NumCoef[0] *
    Master_control_fuzzy_standal_DW.LPF3_tmp +
    Master_control_fuzzy_standalo_P.LPF3_NumCoef[1] *
    Master_control_fuzzy_standal_DW.LPF3_states;

  /* DiscreteIntegrator: '<S9>/HEAVE_VEL2' */
  Master_control_fuzzy_standalo_B.HEAVE_VEL2 =
    Master_control_fuzzy_standalo_P.HEAVE_VEL2_gainval *
    Master_control_fuzzy_standalo_B.LPF3 +
    Master_control_fuzzy_standal_DW.HEAVE_VEL2_DSTATE;

  /* Sum: '<S9>/Add2' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  Master_control_fuzzy_standalo_B.Add2_k =
    Master_control_fuzzy_standalo_B.HEAVE_VEL2 +
    Master_control_fuzzy_standalo_P.Constant3_Value;

  /* DiscreteTransferFcn: '<S8>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_tmp_o =
    (Master_control_fuzzy_standalo_B.Add2_k -
     Master_control_fuzzy_standalo_P.HF1_DenCoef_c[1] *
     Master_control_fuzzy_standal_DW.HF1_states_e) /
    Master_control_fuzzy_standalo_P.HF1_DenCoef_c[0];

  /* DiscreteTransferFcn: '<S8>/LPF1' incorporates:
   *  DiscreteTransferFcn: '<S8>/H.F1'
   */
  Master_control_fuzzy_standal_DW.LPF1_tmp_n =
    ((Master_control_fuzzy_standalo_P.HF1_NumCoef_c[0] *
      Master_control_fuzzy_standal_DW.HF1_tmp_o +
      Master_control_fuzzy_standalo_P.HF1_NumCoef_c[1] *
      Master_control_fuzzy_standal_DW.HF1_states_e) -
     Master_control_fuzzy_standalo_P.LPF1_DenCoef_i[1] *
     Master_control_fuzzy_standal_DW.LPF1_states_f) /
    Master_control_fuzzy_standalo_P.LPF1_DenCoef_i[0];
  Master_control_fuzzy_standalo_B.LPF1_g =
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_k[0] *
    Master_control_fuzzy_standal_DW.LPF1_tmp_n +
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_k[1] *
    Master_control_fuzzy_standal_DW.LPF1_states_f;

  /* DiscreteIntegrator: '<S8>/s.d' */
  Master_control_fuzzy_standalo_B.sd_k =
    Master_control_fuzzy_standalo_P.sd_gainval_h *
    Master_control_fuzzy_standalo_B.LPF1_g +
    Master_control_fuzzy_standal_DW.sd_DSTATE_f;

  /* Sum: '<S8>/Add1' */
  Master_control_fuzzy_standalo_B.Add1_ha =
    Master_control_fuzzy_standalo_B.sd1_i - Master_control_fuzzy_standalo_B.sd_k;

  /* MATLABSystem: '<S23>/Analog Input3' */
  if (Master_control_fuzzy_standal_DW.obj.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_d) {
    Master_control_fuzzy_standal_DW.obj.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_d;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* DiscreteTransferFcn: '<S23>/l2' incorporates:
   *  Constant: '<S23>/Conversion_volt'
   *  MATLABSystem: '<S23>/Analog Input3'
   *  Product: '<S23>/Product8'
   */
  Master_control_fuzzy_standal_DW.l2_tmp = ((real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion_volt_Value_p -
    Master_control_fuzzy_standalo_P.l2_DenCoef[1] *
    Master_control_fuzzy_standal_DW.l2_states) /
    Master_control_fuzzy_standalo_P.l2_DenCoef[0];

  /* SampleTimeMath: '<S240>/TSamp' incorporates:
   *  DiscreteTransferFcn: '<S23>/l2'
   *  Lookup_n-D: '<S23>/Rleft'
   *
   * About '<S240>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_g = look1_binlxpw
    (Master_control_fuzzy_standalo_P.l2_NumCoef[0] *
     Master_control_fuzzy_standal_DW.l2_tmp +
     Master_control_fuzzy_standalo_P.l2_NumCoef[1] *
     Master_control_fuzzy_standal_DW.l2_states,
     Master_control_fuzzy_standalo_P.Rleft_bp01Data,
     Master_control_fuzzy_standalo_P.Rleft_tableData, 2U) *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_oi;

  /* Sum: '<S240>/Diff' incorporates:
   *  UnitDelay: '<S240>/UD'
   *
   * Block description for '<S240>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S240>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Diff_l =
    Master_control_fuzzy_standalo_B.TSamp_g -
    Master_control_fuzzy_standal_DW.UD_DSTATE_o;

  /* DiscreteTransferFcn: '<S7>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_tmp_o =
    (Master_control_fuzzy_standalo_B.Diff_l -
     Master_control_fuzzy_standalo_P.HF2_DenCoef_l[1] *
     Master_control_fuzzy_standal_DW.HF2_states_b) /
    Master_control_fuzzy_standalo_P.HF2_DenCoef_l[0];

  /* DiscreteTransferFcn: '<S7>/LPF2' incorporates:
   *  DiscreteTransferFcn: '<S7>/H.F2'
   */
  Master_control_fuzzy_standal_DW.LPF2_tmp_il =
    ((Master_control_fuzzy_standalo_P.HF2_NumCoef_d[0] *
      Master_control_fuzzy_standal_DW.HF2_tmp_o +
      Master_control_fuzzy_standalo_P.HF2_NumCoef_d[1] *
      Master_control_fuzzy_standal_DW.HF2_states_b) -
     Master_control_fuzzy_standalo_P.LPF2_DenCoef_d[1] *
     Master_control_fuzzy_standal_DW.LPF2_states_m) /
    Master_control_fuzzy_standalo_P.LPF2_DenCoef_d[0];
  Master_control_fuzzy_standalo_B.LPF2_i =
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_p[0] *
    Master_control_fuzzy_standal_DW.LPF2_tmp_il +
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_p[1] *
    Master_control_fuzzy_standal_DW.LPF2_states_m;

  /* DiscreteIntegrator: '<S7>/s.d1' */
  Master_control_fuzzy_standalo_B.sd1_p =
    Master_control_fuzzy_standalo_P.sd1_gainval_n *
    Master_control_fuzzy_standalo_B.LPF2_i +
    Master_control_fuzzy_standal_DW.sd1_DSTATE_k;

  /* Gain: '<S9>/Gain5' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Product: '<S9>/Product7'
   */
  Master_control_fuzzy_standalo_B.Gain5 = Master_control_fuzzy_standalo_B.Add3 *
    Master_control_fuzzy_standalo_P.Constant4_Value *
    Master_control_fuzzy_standalo_P.Gain5_Gain;

  /* DiscreteTransferFcn: '<S9>/H.F4' */
  Master_control_fuzzy_standal_DW.HF4_tmp =
    (Master_control_fuzzy_standalo_B.Gain5 -
     Master_control_fuzzy_standalo_P.HF4_DenCoef[1] *
     Master_control_fuzzy_standal_DW.HF4_states) /
    Master_control_fuzzy_standalo_P.HF4_DenCoef[0];

  /* DiscreteTransferFcn: '<S9>/LPF4' incorporates:
   *  DiscreteTransferFcn: '<S9>/H.F4'
   */
  Master_control_fuzzy_standal_DW.LPF4_tmp =
    ((Master_control_fuzzy_standalo_P.HF4_NumCoef[0] *
      Master_control_fuzzy_standal_DW.HF4_tmp +
      Master_control_fuzzy_standalo_P.HF4_NumCoef[1] *
      Master_control_fuzzy_standal_DW.HF4_states) -
     Master_control_fuzzy_standalo_P.LPF4_DenCoef[1] *
     Master_control_fuzzy_standal_DW.LPF4_states) /
    Master_control_fuzzy_standalo_P.LPF4_DenCoef[0];
  Master_control_fuzzy_standalo_B.LPF4 =
    Master_control_fuzzy_standalo_P.LPF4_NumCoef[0] *
    Master_control_fuzzy_standal_DW.LPF4_tmp +
    Master_control_fuzzy_standalo_P.LPF4_NumCoef[1] *
    Master_control_fuzzy_standal_DW.LPF4_states;

  /* DiscreteIntegrator: '<S9>/HEAVE_VEL3' */
  Master_control_fuzzy_standalo_B.HEAVE_VEL3 =
    Master_control_fuzzy_standalo_P.HEAVE_VEL3_gainval *
    Master_control_fuzzy_standalo_B.LPF4 +
    Master_control_fuzzy_standal_DW.HEAVE_VEL3_DSTATE;

  /* Sum: '<S9>/Add3' incorporates:
   *  Constant: '<S9>/Constant5'
   */
  Master_control_fuzzy_standalo_B.Add3_c =
    Master_control_fuzzy_standalo_B.HEAVE_VEL3 +
    Master_control_fuzzy_standalo_P.Constant5_Value;

  /* DiscreteTransferFcn: '<S7>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_tmp_k =
    (Master_control_fuzzy_standalo_B.Add3_c -
     Master_control_fuzzy_standalo_P.HF1_DenCoef_j[1] *
     Master_control_fuzzy_standal_DW.HF1_states_i) /
    Master_control_fuzzy_standalo_P.HF1_DenCoef_j[0];

  /* DiscreteTransferFcn: '<S7>/LPF1' incorporates:
   *  DiscreteTransferFcn: '<S7>/H.F1'
   */
  Master_control_fuzzy_standal_DW.LPF1_tmp_o =
    ((Master_control_fuzzy_standalo_P.HF1_NumCoef_m[0] *
      Master_control_fuzzy_standal_DW.HF1_tmp_k +
      Master_control_fuzzy_standalo_P.HF1_NumCoef_m[1] *
      Master_control_fuzzy_standal_DW.HF1_states_i) -
     Master_control_fuzzy_standalo_P.LPF1_DenCoef_f[1] *
     Master_control_fuzzy_standal_DW.LPF1_states_a) /
    Master_control_fuzzy_standalo_P.LPF1_DenCoef_f[0];
  Master_control_fuzzy_standalo_B.LPF1_k =
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_o[0] *
    Master_control_fuzzy_standal_DW.LPF1_tmp_o +
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_o[1] *
    Master_control_fuzzy_standal_DW.LPF1_states_a;

  /* DiscreteIntegrator: '<S7>/s.d' */
  Master_control_fuzzy_standalo_B.sd_a =
    Master_control_fuzzy_standalo_P.sd_gainval_i *
    Master_control_fuzzy_standalo_B.LPF1_k +
    Master_control_fuzzy_standal_DW.sd_DSTATE_h;

  /* Sum: '<S7>/Add1' */
  Master_control_fuzzy_standalo_B.Add1_m = Master_control_fuzzy_standalo_B.sd1_p
    - Master_control_fuzzy_standalo_B.sd_a;

  /* MATLABSystem: '<S21>/Analog Input3' */
  if (Master_control_fuzzy_standal_DW.obj_e.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_m) {
    Master_control_fuzzy_standal_DW.obj_e.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_m;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_e.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_e.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* DiscreteTransferFcn: '<S21>/r2' incorporates:
   *  Constant: '<S21>/Conversion_volt'
   *  MATLABSystem: '<S21>/Analog Input3'
   *  Product: '<S21>/Product8'
   */
  Master_control_fuzzy_standal_DW.r2_tmp = ((real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Conversion_volt_Value_j -
    Master_control_fuzzy_standalo_P.r2_DenCoef[1] *
    Master_control_fuzzy_standal_DW.r2_states) /
    Master_control_fuzzy_standalo_P.r2_DenCoef[0];

  /* SampleTimeMath: '<S238>/TSamp' incorporates:
   *  DiscreteTransferFcn: '<S21>/r2'
   *  Lookup_n-D: '<S21>/1-D Lookup Table1'
   *
   * About '<S238>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_e = look1_binlxpw
    (Master_control_fuzzy_standalo_P.r2_NumCoef[0] *
     Master_control_fuzzy_standal_DW.r2_tmp +
     Master_control_fuzzy_standalo_P.r2_NumCoef[1] *
     Master_control_fuzzy_standal_DW.r2_states,
     Master_control_fuzzy_standalo_P.uDLookupTable1_bp01Data,
     Master_control_fuzzy_standalo_P.uDLookupTable1_tableData, 2U) *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_ox;

  /* Sum: '<S238>/Diff' incorporates:
   *  UnitDelay: '<S238>/UD'
   *
   * Block description for '<S238>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S238>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Diff_p =
    Master_control_fuzzy_standalo_B.TSamp_e -
    Master_control_fuzzy_standal_DW.UD_DSTATE_f;

  /* Saturate: '<S6>/Saturation1' */
  if (Master_control_fuzzy_standalo_B.Diff_p >
      Master_control_fuzzy_standalo_P.Saturation1_UpperSat) {
    Master_control_fuzzy_standalo_B.roll_b =
      Master_control_fuzzy_standalo_P.Saturation1_UpperSat;
  } else if (Master_control_fuzzy_standalo_B.Diff_p <
             Master_control_fuzzy_standalo_P.Saturation1_LowerSat) {
    Master_control_fuzzy_standalo_B.roll_b =
      Master_control_fuzzy_standalo_P.Saturation1_LowerSat;
  } else {
    Master_control_fuzzy_standalo_B.roll_b =
      Master_control_fuzzy_standalo_B.Diff_p;
  }

  /* End of Saturate: '<S6>/Saturation1' */

  /* DiscreteTransferFcn: '<S6>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_tmp_g =
    (Master_control_fuzzy_standalo_B.roll_b -
     Master_control_fuzzy_standalo_P.HF2_DenCoef_i[1] *
     Master_control_fuzzy_standal_DW.HF2_states_j) /
    Master_control_fuzzy_standalo_P.HF2_DenCoef_i[0];

  /* DiscreteTransferFcn: '<S6>/LPF2' incorporates:
   *  DiscreteTransferFcn: '<S6>/H.F2'
   */
  Master_control_fuzzy_standal_DW.LPF2_tmp_hp =
    ((Master_control_fuzzy_standalo_P.HF2_NumCoef_e[0] *
      Master_control_fuzzy_standal_DW.HF2_tmp_g +
      Master_control_fuzzy_standalo_P.HF2_NumCoef_e[1] *
      Master_control_fuzzy_standal_DW.HF2_states_j) -
     Master_control_fuzzy_standalo_P.LPF2_DenCoef_i[1] *
     Master_control_fuzzy_standal_DW.LPF2_states_b) /
    Master_control_fuzzy_standalo_P.LPF2_DenCoef_i[0];
  Master_control_fuzzy_standalo_B.LPF2_a =
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_l[0] *
    Master_control_fuzzy_standal_DW.LPF2_tmp_hp +
    Master_control_fuzzy_standalo_P.LPF2_NumCoef_l[1] *
    Master_control_fuzzy_standal_DW.LPF2_states_b;

  /* DiscreteIntegrator: '<S6>/s.d1' */
  Master_control_fuzzy_standalo_B.sd1_n =
    Master_control_fuzzy_standalo_P.sd1_gainval_l *
    Master_control_fuzzy_standalo_B.LPF2_a +
    Master_control_fuzzy_standal_DW.sd1_DSTATE_i;

  /* Gain: '<S9>/Gain6' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Product: '<S9>/Product8'
   */
  Master_control_fuzzy_standalo_B.Gain6 = Master_control_fuzzy_standalo_B.Add4_n
    * Master_control_fuzzy_standalo_P.Constant6_Value *
    Master_control_fuzzy_standalo_P.Gain6_Gain;

  /* DiscreteTransferFcn: '<S9>/H.F5' */
  Master_control_fuzzy_standal_DW.HF5_tmp =
    (Master_control_fuzzy_standalo_B.Gain6 -
     Master_control_fuzzy_standalo_P.HF5_DenCoef[1] *
     Master_control_fuzzy_standal_DW.HF5_states) /
    Master_control_fuzzy_standalo_P.HF5_DenCoef[0];

  /* DiscreteTransferFcn: '<S9>/LPF5' incorporates:
   *  DiscreteTransferFcn: '<S9>/H.F5'
   */
  Master_control_fuzzy_standal_DW.LPF5_tmp =
    ((Master_control_fuzzy_standalo_P.HF5_NumCoef[0] *
      Master_control_fuzzy_standal_DW.HF5_tmp +
      Master_control_fuzzy_standalo_P.HF5_NumCoef[1] *
      Master_control_fuzzy_standal_DW.HF5_states) -
     Master_control_fuzzy_standalo_P.LPF5_DenCoef[1] *
     Master_control_fuzzy_standal_DW.LPF5_states) /
    Master_control_fuzzy_standalo_P.LPF5_DenCoef[0];
  Master_control_fuzzy_standalo_B.LPF5 =
    Master_control_fuzzy_standalo_P.LPF5_NumCoef[0] *
    Master_control_fuzzy_standal_DW.LPF5_tmp +
    Master_control_fuzzy_standalo_P.LPF5_NumCoef[1] *
    Master_control_fuzzy_standal_DW.LPF5_states;

  /* DiscreteIntegrator: '<S9>/HEAVE_VEL4' */
  Master_control_fuzzy_standalo_B.HEAVE_VEL4 =
    Master_control_fuzzy_standalo_P.HEAVE_VEL4_gainval *
    Master_control_fuzzy_standalo_B.LPF5 +
    Master_control_fuzzy_standal_DW.HEAVE_VEL4_DSTATE;

  /* Sum: '<S9>/Add4' incorporates:
   *  Constant: '<S9>/Constant7'
   */
  Master_control_fuzzy_standalo_B.roll_b_p =
    Master_control_fuzzy_standalo_B.HEAVE_VEL4 +
    Master_control_fuzzy_standalo_P.Constant7_Value;

  /* Saturate: '<S6>/Saturation2' */
  if (Master_control_fuzzy_standalo_B.roll_b_p >
      Master_control_fuzzy_standalo_P.Saturation2_UpperSat) {
    /* Sum: '<S9>/Add4' */
    Master_control_fuzzy_standalo_B.roll_b_p =
      Master_control_fuzzy_standalo_P.Saturation2_UpperSat;
  } else {
    if (Master_control_fuzzy_standalo_B.roll_b_p <
        Master_control_fuzzy_standalo_P.Saturation2_LowerSat) {
      /* Sum: '<S9>/Add4' */
      Master_control_fuzzy_standalo_B.roll_b_p =
        Master_control_fuzzy_standalo_P.Saturation2_LowerSat;
    }
  }

  /* End of Saturate: '<S6>/Saturation2' */

  /* DiscreteTransferFcn: '<S6>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_tmp_h =
    (Master_control_fuzzy_standalo_B.roll_b_p -
     Master_control_fuzzy_standalo_P.HF1_DenCoef_a[1] *
     Master_control_fuzzy_standal_DW.HF1_states_g) /
    Master_control_fuzzy_standalo_P.HF1_DenCoef_a[0];

  /* DiscreteTransferFcn: '<S6>/LPF1' incorporates:
   *  DiscreteTransferFcn: '<S6>/H.F1'
   */
  Master_control_fuzzy_standal_DW.LPF1_tmp_h =
    ((Master_control_fuzzy_standalo_P.HF1_NumCoef_k[0] *
      Master_control_fuzzy_standal_DW.HF1_tmp_h +
      Master_control_fuzzy_standalo_P.HF1_NumCoef_k[1] *
      Master_control_fuzzy_standal_DW.HF1_states_g) -
     Master_control_fuzzy_standalo_P.LPF1_DenCoef_h[1] *
     Master_control_fuzzy_standal_DW.LPF1_states_g) /
    Master_control_fuzzy_standalo_P.LPF1_DenCoef_h[0];
  Master_control_fuzzy_standalo_B.LPF1_ki =
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_b[0] *
    Master_control_fuzzy_standal_DW.LPF1_tmp_h +
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_b[1] *
    Master_control_fuzzy_standal_DW.LPF1_states_g;

  /* DiscreteIntegrator: '<S6>/s.d' */
  Master_control_fuzzy_standalo_B.sd_j =
    Master_control_fuzzy_standalo_P.sd_gainval_b *
    Master_control_fuzzy_standalo_B.LPF1_ki +
    Master_control_fuzzy_standal_DW.sd_DSTATE_m;

  /* Sum: '<S6>/Add1' */
  Master_control_fuzzy_standalo_B.Add1_k = Master_control_fuzzy_standalo_B.sd1_n
    - Master_control_fuzzy_standalo_B.sd_j;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtTo Workspace2Inport1' */
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[0] =
    Master_control_fuzzy_standalo_B.Add1_h;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[1] =
    Master_control_fuzzy_standalo_B.Add1_ha;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[2] =
    Master_control_fuzzy_standalo_B.Add1_m;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[3] =
    Master_control_fuzzy_standalo_B.Add1_k;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[4] =
    Master_control_fuzzy_standalo_B.sd1;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[5] =
    Master_control_fuzzy_standalo_B.sd1_i;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[6] =
    Master_control_fuzzy_standalo_B.sd1_p;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorkspac[7] =
    Master_control_fuzzy_standalo_B.sd1_n;

  /* S-Function (imu_mpu_6050): '<S17>/mpu6050' */
  imu_mpu_6050_Outputs_wrapper(&Master_control_fuzzy_standalo_B.mpu6050_o1,
    &Master_control_fuzzy_standalo_B.mpu6050_o2,
    &Master_control_fuzzy_standalo_B.mpu6050_o3,
    &Master_control_fuzzy_standalo_B.mpu6050_o4,
    &Master_control_fuzzy_standalo_B.mpu6050_o5,
    &Master_control_fuzzy_standalo_B.mpu6050_o6,
    &Master_control_fuzzy_standalo_B.mpu6050_o7,
    &Master_control_fuzzy_standal_DW.mpu6050_DSTATE);

  /* Sum: '<S17>/Add6' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant3'
   *  DataTypeConversion: '<S17>/Data Type Conversion2'
   *  Product: '<S17>/Divide2'
   */
  Master_control_fuzzy_standalo_B.Integrator_i = (real_T)
    Master_control_fuzzy_standalo_B.mpu6050_o3 /
    Master_control_fuzzy_standalo_P.Constant_Value +
    Master_control_fuzzy_standalo_P.Constant3_Value_n;

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Add8'
   */
  Master_control_fuzzy_standalo_B.Gain =
    (Master_control_fuzzy_standalo_B.Integrator_i -
     Master_control_fuzzy_standalo_P.Constant_Value_o) *
    Master_control_fuzzy_standalo_P.Gain_Gain;

  /* DiscreteTransferFcn: '<S9>/H.F' */
  Master_control_fuzzy_standal_DW.HF_tmp = (Master_control_fuzzy_standalo_B.Gain
    - Master_control_fuzzy_standalo_P.HF_DenCoef[1] *
    Master_control_fuzzy_standal_DW.HF_states) /
    Master_control_fuzzy_standalo_P.HF_DenCoef[0];

  /* DiscreteTransferFcn: '<S9>/LPF6' incorporates:
   *  DiscreteTransferFcn: '<S9>/H.F'
   */
  Master_control_fuzzy_standal_DW.LPF6_tmp =
    ((Master_control_fuzzy_standalo_P.HF_NumCoef[0] *
      Master_control_fuzzy_standal_DW.HF_tmp +
      Master_control_fuzzy_standalo_P.HF_NumCoef[1] *
      Master_control_fuzzy_standal_DW.HF_states) -
     Master_control_fuzzy_standalo_P.LPF6_DenCoef[1] *
     Master_control_fuzzy_standal_DW.LPF6_states) /
    Master_control_fuzzy_standalo_P.LPF6_DenCoef[0];
  Master_control_fuzzy_standalo_B.LPF6 =
    Master_control_fuzzy_standalo_P.LPF6_NumCoef[0] *
    Master_control_fuzzy_standal_DW.LPF6_tmp +
    Master_control_fuzzy_standalo_P.LPF6_NumCoef[1] *
    Master_control_fuzzy_standal_DW.LPF6_states;

  /* DiscreteIntegrator: '<S9>/HEAVE_VEL' */
  Master_control_fuzzy_standalo_B.HEAVE_VEL =
    Master_control_fuzzy_standalo_P.HEAVE_VEL_gainval *
    Master_control_fuzzy_standalo_B.LPF6 +
    Master_control_fuzzy_standal_DW.HEAVE_VEL_DSTATE;

  /* DiscreteTransferFcn: '<S9>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_tmp_a =
    (Master_control_fuzzy_standalo_B.HEAVE_VEL -
     Master_control_fuzzy_standalo_P.HF1_DenCoef_jq[1] *
     Master_control_fuzzy_standal_DW.HF1_states_k) /
    Master_control_fuzzy_standalo_P.HF1_DenCoef_jq[0];

  /* DiscreteTransferFcn: '<S9>/LPF1' incorporates:
   *  DiscreteTransferFcn: '<S9>/H.F1'
   */
  Master_control_fuzzy_standal_DW.LPF1_tmp_i =
    ((Master_control_fuzzy_standalo_P.HF1_NumCoef_f[0] *
      Master_control_fuzzy_standal_DW.HF1_tmp_a +
      Master_control_fuzzy_standalo_P.HF1_NumCoef_f[1] *
      Master_control_fuzzy_standal_DW.HF1_states_k) -
     Master_control_fuzzy_standalo_P.LPF1_DenCoef_e[1] *
     Master_control_fuzzy_standal_DW.LPF1_states_h) /
    Master_control_fuzzy_standalo_P.LPF1_DenCoef_e[0];
  Master_control_fuzzy_standalo_B.LPF1_j =
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_h[0] *
    Master_control_fuzzy_standal_DW.LPF1_tmp_i +
    Master_control_fuzzy_standalo_P.LPF1_NumCoef_h[1] *
    Master_control_fuzzy_standal_DW.LPF1_states_h;

  /* DiscreteIntegrator: '<S9>/HEAVE_disp' */
  Master_control_fuzzy_standalo_B.HEAVE_disp =
    Master_control_fuzzy_standalo_P.HEAVE_disp_gainval *
    Master_control_fuzzy_standalo_B.LPF1_j +
    Master_control_fuzzy_standal_DW.HEAVE_disp_DSTATE;

  /* Product: '<S17>/Divide3' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DataTypeConversion: '<S17>/Data Type Conversion4'
   */
  Master_control_fuzzy_standalo_B.Divide3 = (real_T)
    Master_control_fuzzy_standalo_B.mpu6050_o5 /
    Master_control_fuzzy_standalo_P.Constant1_Value_k;

  /* Gain: '<S17>/gx' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Sum: '<S17>/Add5'
   */
  Master_control_fuzzy_standalo_B.gx = (Master_control_fuzzy_standalo_B.Divide3
    + Master_control_fuzzy_standalo_P.Constant4_Value_i) *
    Master_control_fuzzy_standalo_P.gx_Gain;

  /* Product: '<S17>/Divide1' incorporates:
   *  Constant: '<S17>/Constant'
   *  DataTypeConversion: '<S17>/Data Type Conversion1'
   */
  Master_control_fuzzy_standalo_B.SignPreSat_m = (real_T)
    Master_control_fuzzy_standalo_B.mpu6050_o2 /
    Master_control_fuzzy_standalo_P.Constant_Value;

  /* Product: '<S17>/Divide' incorporates:
   *  Constant: '<S17>/Constant'
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   */
  Master_control_fuzzy_standalo_B.Divide = (real_T)
    Master_control_fuzzy_standalo_B.mpu6050_o1 /
    Master_control_fuzzy_standalo_P.Constant_Value;

  /* Sum: '<S148>/Add2' incorporates:
   *  Constant: '<S148>/Constant'
   */
  Master_control_fuzzy_standalo_B.Integrator_i +=
    Master_control_fuzzy_standalo_P.Constant_Value_b;

  /* Math: '<S148>/Az2' */
  Master_control_fuzzy_standalo_B.Integrator_i *=
    Master_control_fuzzy_standalo_B.Integrator_i;

  /* Gain: '<S148>/roll' incorporates:
   *  Math: '<S148>/Ax2'
   *  Sqrt: '<S148>/Sqrt1'
   *  Sum: '<S148>/Add1'
   *  Trigonometry: '<S148>/Atan1'
   */
  Master_control_fuzzy_standalo_B.roll = Master_control_fu_rt_atan2d_snf
    (Master_control_fuzzy_standalo_B.SignPreSat_m, sqrt
     (Master_control_fuzzy_standalo_B.Divide *
      Master_control_fuzzy_standalo_B.Divide +
      Master_control_fuzzy_standalo_B.Integrator_i)) *
    Master_control_fuzzy_standalo_P.roll_Gain;

  /* Sum: '<S17>/Add4' incorporates:
   *  Delay: '<S17>/Delay1'
   *  Gain: '<S17>/Gain2'
   *  Gain: '<S17>/Gain3'
   *  Sum: '<S17>/Add3'
   */
  Master_control_fuzzy_standalo_B.Add4 =
    (Master_control_fuzzy_standal_DW.Delay1_DSTATE +
     Master_control_fuzzy_standalo_B.gx) *
    Master_control_fuzzy_standalo_P.Gain2_Gain +
    Master_control_fuzzy_standalo_P.Gain3_Gain_b *
    Master_control_fuzzy_standalo_B.roll;

  /* Sum: '<S17>/Add9' incorporates:
   *  Constant: '<S17>/Constant7'
   */
  Master_control_fuzzy_standalo_B.Add9 = Master_control_fuzzy_standalo_B.Add4 -
    Master_control_fuzzy_standalo_P.Constant7_Value_f;

  /* Saturate: '<Root>/Saturation1' */
  if (Master_control_fuzzy_standalo_B.Add9 >
      Master_control_fuzzy_standalo_P.Saturation1_UpperSat_b) {
    Master_control_fuzzy_standalo_B.roll_i =
      Master_control_fuzzy_standalo_P.Saturation1_UpperSat_b;
  } else if (Master_control_fuzzy_standalo_B.Add9 <
             Master_control_fuzzy_standalo_P.Saturation1_LowerSat_p) {
    Master_control_fuzzy_standalo_B.roll_i =
      Master_control_fuzzy_standalo_P.Saturation1_LowerSat_p;
  } else {
    Master_control_fuzzy_standalo_B.roll_i =
      Master_control_fuzzy_standalo_B.Add9;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* SampleTimeMath: '<S49>/TSamp'
   *
   * About '<S49>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_l =
    Master_control_fuzzy_standalo_B.roll_i *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_oy;

  /* Sum: '<S49>/Diff' incorporates:
   *  UnitDelay: '<S49>/UD'
   *
   * Block description for '<S49>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S49>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Diff_c =
    Master_control_fuzzy_standalo_B.TSamp_l -
    Master_control_fuzzy_standal_DW.UD_DSTATE_g;

  /* Product: '<S17>/Divide4' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DataTypeConversion: '<S17>/Data Type Conversion5'
   */
  Master_control_fuzzy_standalo_B.Divide4 = (real_T)
    Master_control_fuzzy_standalo_B.mpu6050_o6 /
    Master_control_fuzzy_standalo_P.Constant1_Value_k;

  /* Gain: '<S17>/gy' incorporates:
   *  Constant: '<S17>/Constant5'
   *  Sum: '<S17>/Add7'
   */
  Master_control_fuzzy_standalo_B.gy = (Master_control_fuzzy_standalo_B.Divide4
    - Master_control_fuzzy_standalo_P.Constant5_Value_o) *
    Master_control_fuzzy_standalo_P.gy_Gain;

  /* Sum: '<S148>/Add' incorporates:
   *  Math: '<S148>/Ay2'
   */
  Master_control_fuzzy_standalo_B.Integrator_i +=
    Master_control_fuzzy_standalo_B.SignPreSat_m *
    Master_control_fuzzy_standalo_B.SignPreSat_m;

  /* Sqrt: '<S148>/Sqrt' */
  Master_control_fuzzy_standalo_B.Integrator_i = sqrt
    (Master_control_fuzzy_standalo_B.Integrator_i);

  /* Gain: '<S148>/pitch' incorporates:
   *  Gain: '<S148>/pitch1'
   *  Trigonometry: '<S148>/Atan'
   */
  Master_control_fuzzy_standalo_B.pitch = Master_control_fu_rt_atan2d_snf
    (Master_control_fuzzy_standalo_P.pitch1_Gain *
     Master_control_fuzzy_standalo_B.Divide,
     Master_control_fuzzy_standalo_B.Integrator_i) *
    Master_control_fuzzy_standalo_P.pitch_Gain;

  /* Sum: '<S17>/Add2' incorporates:
   *  Delay: '<S17>/Delay'
   *  Gain: '<S17>/Gain'
   *  Gain: '<S17>/Gain1'
   *  Sum: '<S17>/Add1'
   */
  Master_control_fuzzy_standalo_B.Add2 =
    (Master_control_fuzzy_standal_DW.Delay_DSTATE +
     Master_control_fuzzy_standalo_B.gy) *
    Master_control_fuzzy_standalo_P.Gain_Gain_i +
    Master_control_fuzzy_standalo_P.Gain1_Gain *
    Master_control_fuzzy_standalo_B.pitch;

  /* Sum: '<S17>/Add8' incorporates:
   *  Constant: '<S17>/Constant6'
   */
  Master_control_fuzzy_standalo_B.Add8 = Master_control_fuzzy_standalo_B.Add2 -
    Master_control_fuzzy_standalo_P.Constant6_Value_m;

  /* Saturate: '<Root>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Add8 >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat) {
    Master_control_fuzzy_standalo_B.Pitch =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat;
  } else if (Master_control_fuzzy_standalo_B.Add8 <
             Master_control_fuzzy_standalo_P.Saturation_LowerSat) {
    Master_control_fuzzy_standalo_B.Pitch =
      Master_control_fuzzy_standalo_P.Saturation_LowerSat;
  } else {
    Master_control_fuzzy_standalo_B.Pitch = Master_control_fuzzy_standalo_B.Add8;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* SampleTimeMath: '<S48>/TSamp'
   *
   * About '<S48>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_m =
    Master_control_fuzzy_standalo_B.Pitch *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_d;

  /* Sum: '<S48>/Diff' incorporates:
   *  UnitDelay: '<S48>/UD'
   *
   * Block description for '<S48>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S48>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Diff_d =
    Master_control_fuzzy_standalo_B.TSamp_m -
    Master_control_fuzzy_standal_DW.UD_DSTATE_c;

  /* Clock: '<Root>/Clock' */
  Master_control_fuzzy_standalo_B.Clock =
    Master_control_fuzzy_standalo_B.Filter_ny;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtTo WorkspaceInport1' */
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_o[0] =
    Master_control_fuzzy_standalo_B.Gain;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_o[1] =
    Master_control_fuzzy_standalo_B.Pitch;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_o[2] =
    Master_control_fuzzy_standalo_B.roll_i;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_o[3] =
    Master_control_fuzzy_standalo_B.HEAVE_disp;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_o[4] =
    Master_control_fuzzy_standalo_B.Diff_c;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_o[5] =
    Master_control_fuzzy_standalo_B.Diff_d;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_o[6] =
    Master_control_fuzzy_standalo_B.Clock;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtTo Workspace1Inport1' */
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_g[0] =
    Master_control_fuzzy_standalo_B.Diff;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_g[1] =
    Master_control_fuzzy_standalo_B.Diff_e;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_g[2] =
    Master_control_fuzzy_standalo_B.Diff_l;
  Master_control_fuzzy_standalo_B.TmpSignalConversionAtToWorksp_g[3] =
    Master_control_fuzzy_standalo_B.Diff_p;

  /* Abs: '<S10>/Abs2' */
  Master_control_fuzzy_standalo_B.Filter_ny = fabs
    (Master_control_fuzzy_standalo_B.LPF6);

  /* Saturate: '<S10>/Saturation2' */
  if (Master_control_fuzzy_standalo_B.Filter_ny >
      Master_control_fuzzy_standalo_P.Saturation2_UpperSat_a) {
    Master_control_fuzzy_standalo_B.Filter_ny =
      Master_control_fuzzy_standalo_P.Saturation2_UpperSat_a;
  } else {
    if (Master_control_fuzzy_standalo_B.Filter_ny <
        Master_control_fuzzy_standalo_P.Saturation2_LowerSat_f) {
      Master_control_fuzzy_standalo_B.Filter_ny =
        Master_control_fuzzy_standalo_P.Saturation2_LowerSat_f;
    }
  }

  /* End of Saturate: '<S10>/Saturation2' */

  /* Abs: '<S10>/Abs1' */
  Master_control_fuzzy_standalo_B.Integrator_i = fabs
    (Master_control_fuzzy_standalo_B.Diff_c);

  /* Saturate: '<S10>/Saturation1' */
  if (Master_control_fuzzy_standalo_B.Integrator_i >
      Master_control_fuzzy_standalo_P.Saturation1_UpperSat_m) {
    Master_control_fuzzy_standalo_B.Integrator_i =
      Master_control_fuzzy_standalo_P.Saturation1_UpperSat_m;
  } else {
    if (Master_control_fuzzy_standalo_B.Integrator_i <
        Master_control_fuzzy_standalo_P.Saturation1_LowerSat_i) {
      Master_control_fuzzy_standalo_B.Integrator_i =
        Master_control_fuzzy_standalo_P.Saturation1_LowerSat_i;
    }
  }

  /* End of Saturate: '<S10>/Saturation1' */

  /* Abs: '<S10>/Abs' */
  Master_control_fuzzy_standalo_B.SignPreSat_i = fabs
    (Master_control_fuzzy_standalo_B.Diff_d);

  /* Saturate: '<S10>/Saturation' */
  if (Master_control_fuzzy_standalo_B.SignPreSat_i >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_d) {
    Master_control_fuzzy_standalo_B.SignPreSat_i =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_d;
  } else {
    if (Master_control_fuzzy_standalo_B.SignPreSat_i <
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_d) {
      Master_control_fuzzy_standalo_B.SignPreSat_i =
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_d;
    }
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S10>/Fuzzy Logic  Controller' */
  /* MATLAB Function: '<S56>/Evaluate Rule Antecedents' incorporates:
   *  SignalConversion: '<S58>/TmpSignal ConversionAt SFunction Inport1'
   */
  Master_control_fuzzy_standalo_B.SignPreSat_m = 0.0;
  Master_control_fuzzy_standalo_B.inputMFCache[0] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.Filter_ny, k);
  Master_control_fuzzy_standalo_B.inputMFCache[1] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.Filter_ny, j);
  Master_control_fuzzy_standalo_B.inputMFCache[2] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.Filter_ny, i);
  Master_control_fuzzy_standalo_B.inputMFCache[3] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.Integrator_i,
    h);
  Master_control_fuzzy_standalo_B.inputMFCache[4] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.Integrator_i,
    g);
  Master_control_fuzzy_standalo_B.inputMFCache[5] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.Integrator_i,
    f);
  Master_control_fuzzy_standalo_B.inputMFCache[6] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.SignPreSat_i,
    e);
  Master_control_fuzzy_standalo_B.inputMFCache[7] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.SignPreSat_i,
    d);
  Master_control_fuzzy_standalo_B.inputMFCache[8] =
    Master_control_fuzzy_stan_trimf(Master_control_fuzzy_standalo_B.SignPreSat_i,
    c);
  for (Master_control_fuzzy_standalo_B.ruleID = 0;
       Master_control_fuzzy_standalo_B.ruleID < 9;
       Master_control_fuzzy_standalo_B.ruleID++) {
    Master_control_fuzzy_standalo_B.Filter_ny = 1.0;
    Master_control_fuzzy_standalo_B.Integrator_i =
      Master_control_fuzzy_standalo_B.inputMFCache[b[Master_control_fuzzy_standalo_B.ruleID]
      - 1];
    if (1.0 > Master_control_fuzzy_standalo_B.Integrator_i) {
      Master_control_fuzzy_standalo_B.Filter_ny =
        Master_control_fuzzy_standalo_B.Integrator_i;
    }

    Master_control_fuzzy_standalo_B.Integrator_i =
      Master_control_fuzzy_standalo_B.inputMFCache[b[Master_control_fuzzy_standalo_B.ruleID
      + 9] + 2];
    if (Master_control_fuzzy_standalo_B.Filter_ny >
        Master_control_fuzzy_standalo_B.Integrator_i) {
      Master_control_fuzzy_standalo_B.Filter_ny =
        Master_control_fuzzy_standalo_B.Integrator_i;
    }

    Master_control_fuzzy_standalo_B.Integrator_i =
      Master_control_fuzzy_standalo_B.inputMFCache[b[Master_control_fuzzy_standalo_B.ruleID
      + 18] + 5];
    if (Master_control_fuzzy_standalo_B.Filter_ny >
        Master_control_fuzzy_standalo_B.Integrator_i) {
      Master_control_fuzzy_standalo_B.Filter_ny =
        Master_control_fuzzy_standalo_B.Integrator_i;
    }

    Master_control_fuzzy_standalo_B.SignPreSat_m +=
      Master_control_fuzzy_standalo_B.Filter_ny;
    Master_control_fuzzy_standalo_B.antecedentOutputs[Master_control_fuzzy_standalo_B.ruleID]
      = Master_control_fuzzy_standalo_B.Filter_ny;
  }

  /* MATLAB Function: '<S56>/Evaluate Rule Consequents' incorporates:
   *  Constant: '<S56>/Output Sample Points'
   */
  memset(&Master_control_fuzzy_standalo_B.aggregatedOutputs[0], 0, 150U * sizeof
         (real_T));
  Mast_createMamdaniOutputMFCache
    (Master_control_fuzzy_standalo_P.OutputSamplePoints_Value,
     Master_control_fuzzy_standalo_B.outputMFCache);
  for (Master_control_fuzzy_standalo_B.outputID = 0;
       Master_control_fuzzy_standalo_B.outputID < 3;
       Master_control_fuzzy_standalo_B.outputID++) {
    Master_control_fuzzy_standalo_B.q0 = Master_control_fuzzy_standa_abs(3 *
      Master_control_fuzzy_standalo_B.outputID);
    for (Master_control_fuzzy_standalo_B.ruleID = 0;
         Master_control_fuzzy_standalo_B.ruleID < 9;
         Master_control_fuzzy_standalo_B.ruleID++) {
      Master_control_fuzzy_standalo_B.q1 = b_0[9 *
        Master_control_fuzzy_standalo_B.outputID +
        Master_control_fuzzy_standalo_B.ruleID];
      if ((Master_control_fuzzy_standalo_B.q0 < 0) &&
          (Master_control_fuzzy_standalo_B.q1 < MIN_int32_T
           - Master_control_fuzzy_standalo_B.q0)) {
        Master_control_fuzzy_standalo_B.q1 = MIN_int32_T;
      } else if ((Master_control_fuzzy_standalo_B.q0 > 0) &&
                 (Master_control_fuzzy_standalo_B.q1 > MAX_int32_T
                  - Master_control_fuzzy_standalo_B.q0)) {
        Master_control_fuzzy_standalo_B.q1 = MAX_int32_T;
      } else {
        Master_control_fuzzy_standalo_B.q1 += Master_control_fuzzy_standalo_B.q0;
      }

      for (Master_control_fuzzy_standalo_B.sampleID = 0;
           Master_control_fuzzy_standalo_B.sampleID < 50;
           Master_control_fuzzy_standalo_B.sampleID++) {
        Master_control_fuzzy_standalo_B.outputMFCache_m[0] =
          Master_control_fuzzy_standalo_B.outputMFCache[(9 *
          Master_control_fuzzy_standalo_B.sampleID +
          Master_control_fuzzy_standalo_B.q1) - 1];
        Master_control_fuzzy_standalo_B.outputMFCache_m[1] =
          Master_control_fuzzy_standalo_B.antecedentOutputs[Master_control_fuzzy_standalo_B.ruleID];
        Master_control_fuzzy_standalo_B.rtb_aggregatedOutputs_tmp = 50 *
          Master_control_fuzzy_standalo_B.outputID +
          Master_control_fuzzy_standalo_B.sampleID;
        Master_control_fuzzy_standalo_B.rtb_aggregatedOutputs_c[0] =
          Master_control_fuzzy_standalo_B.aggregatedOutputs[Master_control_fuzzy_standalo_B.rtb_aggregatedOutputs_tmp];
        Master_control_fuzzy_standalo_B.rtb_aggregatedOutputs_c[1] =
          Master_contro_evaluateAndMethod
          (Master_control_fuzzy_standalo_B.outputMFCache_m);
        Master_control_fuzzy_standalo_B.aggregatedOutputs[Master_control_fuzzy_standalo_B.rtb_aggregatedOutputs_tmp]
          = Master_control_evaluateOrMethod
          (Master_control_fuzzy_standalo_B.rtb_aggregatedOutputs_c);
      }
    }

    /* MATLAB Function: '<S56>/Defuzzify Outputs' incorporates:
     *  MATLAB Function: '<S56>/Evaluate Rule Antecedents'
     */
    if (Master_control_fuzzy_standalo_B.SignPreSat_m == 0.0) {
      Master_control_fuzzy_standalo_B.TmpSignalConversionAtSFunct[Master_control_fuzzy_standalo_B.outputID]
        = ((real_T)b_1[Master_control_fuzzy_standalo_B.outputID + 3] + (real_T)
           b_1[Master_control_fuzzy_standalo_B.outputID]) / 2.0;
    } else {
      Master_control_fuzzy_standalo_B.Filter_ny = 0.0;
      Master_control_fuzzy_standalo_B.Integrator_i =
        Master_control_fuzzy_standalo_B.aggregatedOutputs[50 *
        Master_control_fuzzy_standalo_B.outputID];
      for (Master_control_fuzzy_standalo_B.ruleID = 0;
           Master_control_fuzzy_standalo_B.ruleID < 49;
           Master_control_fuzzy_standalo_B.ruleID++) {
        Master_control_fuzzy_standalo_B.Integrator_i +=
          Master_control_fuzzy_standalo_B.aggregatedOutputs[(50 *
          Master_control_fuzzy_standalo_B.outputID +
          Master_control_fuzzy_standalo_B.ruleID) + 1];
      }

      if (Master_control_fuzzy_standalo_B.Integrator_i == 0.0) {
        Master_control_fuzzy_standalo_B.TmpSignalConversionAtSFunct[Master_control_fuzzy_standalo_B.outputID]
          = (Master_control_fuzzy_standalo_P.OutputSamplePoints_Value[147 +
             Master_control_fuzzy_standalo_B.outputID] +
             Master_control_fuzzy_standalo_P.OutputSamplePoints_Value[Master_control_fuzzy_standalo_B.outputID])
          / 2.0;
      } else {
        for (Master_control_fuzzy_standalo_B.ruleID = 0;
             Master_control_fuzzy_standalo_B.ruleID < 50;
             Master_control_fuzzy_standalo_B.ruleID++) {
          Master_control_fuzzy_standalo_B.Filter_ny +=
            Master_control_fuzzy_standalo_P.OutputSamplePoints_Value[3 *
            Master_control_fuzzy_standalo_B.ruleID +
            Master_control_fuzzy_standalo_B.outputID] *
            Master_control_fuzzy_standalo_B.aggregatedOutputs[50 *
            Master_control_fuzzy_standalo_B.outputID +
            Master_control_fuzzy_standalo_B.ruleID];
        }

        Master_control_fuzzy_standalo_B.TmpSignalConversionAtSFunct[Master_control_fuzzy_standalo_B.outputID]
          = 1.0 / Master_control_fuzzy_standalo_B.Integrator_i *
          Master_control_fuzzy_standalo_B.Filter_ny;
      }
    }

    /* End of MATLAB Function: '<S56>/Defuzzify Outputs' */
  }

  /* End of MATLAB Function: '<S56>/Evaluate Rule Consequents' */
  /* End of Outputs for SubSystem: '<S10>/Fuzzy Logic  Controller' */

  /* Gain: '<S10>/gain' */
  Master_control_fuzzy_standalo_B.Filter_ny =
    Master_control_fuzzy_standalo_P.gain_Gain *
    Master_control_fuzzy_standalo_B.HEAVE_disp;

  /* SampleTimeMath: '<S53>/TSamp'
   *
   * About '<S53>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_j =
    Master_control_fuzzy_standalo_B.Filter_ny *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_n;

  /* Sum: '<S10>/Add' incorporates:
   *  Gain: '<S10>/gain1'
   *  Product: '<S10>/Product'
   *  Sum: '<S53>/Diff'
   *  UnitDelay: '<S53>/UD'
   *
   * Block description for '<S53>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S53>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.SignPreSat_m =
    (Master_control_fuzzy_standalo_B.TSamp_j -
     Master_control_fuzzy_standal_DW.UD_DSTATE_cy) *
    Master_control_fuzzy_standalo_B.TmpSignalConversionAtSFunct[0] +
    Master_control_fuzzy_standalo_P.gain1_Gain *
    Master_control_fuzzy_standalo_B.Filter_ny;

  /* Gain: '<S10>/g2' */
  Master_control_fuzzy_standalo_B.Filter_ny =
    Master_control_fuzzy_standalo_P.g2_Gain *
    Master_control_fuzzy_standalo_B.Pitch;

  /* SampleTimeMath: '<S54>/TSamp'
   *
   * About '<S54>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_ga =
    Master_control_fuzzy_standalo_B.Filter_ny *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_a;

  /* Sum: '<S10>/Add1' incorporates:
   *  Gain: '<S10>/gain3'
   *  Product: '<S10>/Product1'
   *  Sum: '<S54>/Diff'
   *  UnitDelay: '<S54>/UD'
   *
   * Block description for '<S54>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S54>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Filter_ny =
    (Master_control_fuzzy_standalo_B.TSamp_ga -
     Master_control_fuzzy_standal_DW.UD_DSTATE_e) *
    Master_control_fuzzy_standalo_B.TmpSignalConversionAtSFunct[2] +
    Master_control_fuzzy_standalo_P.gain3_Gain *
    Master_control_fuzzy_standalo_B.Filter_ny;

  /* Gain: '<S10>/g3' */
  Master_control_fuzzy_standalo_B.Integrator_i =
    Master_control_fuzzy_standalo_P.g3_Gain *
    Master_control_fuzzy_standalo_B.roll_i;

  /* SampleTimeMath: '<S55>/TSamp'
   *
   * About '<S55>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Master_control_fuzzy_standalo_B.TSamp_k =
    Master_control_fuzzy_standalo_B.Integrator_i *
    Master_control_fuzzy_standalo_P.TSamp_WtEt_g;

  /* Sum: '<S10>/Add2' incorporates:
   *  Gain: '<S10>/gain5'
   *  Product: '<S10>/Product2'
   *  Sum: '<S55>/Diff'
   *  UnitDelay: '<S55>/UD'
   *
   * Block description for '<S55>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S55>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standalo_B.Integrator_i =
    (Master_control_fuzzy_standalo_B.TSamp_k -
     Master_control_fuzzy_standal_DW.UD_DSTATE_e2) *
    Master_control_fuzzy_standalo_B.TmpSignalConversionAtSFunct[1] +
    Master_control_fuzzy_standalo_P.gain5_Gain *
    Master_control_fuzzy_standalo_B.Integrator_i;

  /* If: '<S45>/If loop ' */
  if (Master_control_fuzzy_standalo_B.Diff_e == 0.0) {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    Master_contro_IfActionSubsystem
      (&Master_control_fuzzy_standalo_B.Integrator_e,
       &Master_control_fuzzy_standalo_P.IfActionSubsystem_c);

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S45>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* MinMax: '<S8>/MinMax' incorporates:
     *  Inport: '<S47>/df'
     */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_B.Diff_e;

    /* End of Outputs for SubSystem: '<S45>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S45>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* Update for If: '<S45>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_e);

    /* End of Update for SubSystem: '<S45>/If Action Subsystem1' */
  }

  /* End of If: '<S45>/If loop ' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Abs: '<S8>/Abs1'
   *  Product: '<S8>/Divide'
   */
  Master_control_fuzzy_standalo_B.Integrator_e =
    Master_control_fuzzy_standalo_B.Add2_k /
    Master_control_fuzzy_standalo_B.Integrator_e;
  Master_control_fuzzy_standalo_B.Integrator_e = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* MATLAB Function: '<S8>/MATLAB Function' */
  Master_control_f_MATLABFunction(Master_control_fuzzy_standalo_B.Add2_k,
    Master_control_fuzzy_standalo_B.Diff_e,
    &Master_control_fuzzy_standalo_B.SignPreIntegrator,
    &Master_control_fuzzy_standalo_B.sf_MATLABFunction_nb);

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   */
  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.SignPreIntegrator;
  if ((Master_control_fuzzy_standalo_P.Constant1_Value_i <
       Master_control_fuzzy_standalo_B.Integrator_e) || rtIsNaN
      (Master_control_fuzzy_standalo_B.Integrator_e)) {
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Constant1_Value_i;
  }

  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.Diff_e;

  /* Saturate: '<S8>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Integrator_e >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_j) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_j;
  } else {
    if (Master_control_fuzzy_standalo_B.Integrator_e <
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_a) {
      /* MinMax: '<S8>/MinMax' */
      Master_control_fuzzy_standalo_B.Integrator_e =
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_a;
    }
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Gain: '<S10>/Gain6'
   *  Gain: '<S10>/Gain7'
   *  Gain: '<S10>/Gain9'
   *  Sum: '<Root>/DF r1'
   *  Sum: '<S10>/R1'
   */
  Master_control_fuzzy_standalo_B.Integrator_e +=
    (Master_control_fuzzy_standalo_P.Gain6_Gain_a *
     Master_control_fuzzy_standalo_B.SignPreSat_m +
     Master_control_fuzzy_standalo_P.Gain9_Gain *
     Master_control_fuzzy_standalo_B.Filter_ny) +
    Master_control_fuzzy_standalo_P.Gain7_Gain *
    Master_control_fuzzy_standalo_B.Integrator_i;

  /* Saturate: '<S3>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Integrator_e >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_a) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_a;
  } else {
    if (Master_control_fuzzy_standalo_B.Integrator_e <
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_k) {
      /* MinMax: '<S8>/MinMax' */
      Master_control_fuzzy_standalo_B.Integrator_e =
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_k;
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Abs: '<S3>/Abs' */
  Master_control_fuzzy_standalo_B.IntegralGain_d = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* If: '<S3>/If loop ' */
  if (Master_control_fuzzy_standalo_B.IntegralGain_d <= 400.0) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    Master_contro_IfActionSubsystem
      (&Master_control_fuzzy_standalo_B.IntegralGain_d,
       &Master_control_fuzzy_standalo_P.IfActionSubsystem_e);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
  } else {
    /* Update for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* Update for If: '<S3>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_j);

    /* End of Update for SubSystem: '<S3>/If Action Subsystem1' */
  }

  /* End of If: '<S3>/If loop ' */

  /* If: '<S41>/If loop ' */
  if (Master_control_fuzzy_standalo_B.Diff_l == 0.0) {
    /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    Master_contro_IfActionSubsystem
      (&Master_control_fuzzy_standalo_B.Integrator_e,
       &Master_control_fuzzy_standalo_P.IfActionSubsystem_p);

    /* End of Outputs for SubSystem: '<S41>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* MinMax: '<S8>/MinMax' incorporates:
     *  Inport: '<S43>/df'
     */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_B.Diff_l;

    /* End of Outputs for SubSystem: '<S41>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* Update for If: '<S41>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_c);

    /* End of Update for SubSystem: '<S41>/If Action Subsystem1' */
  }

  /* End of If: '<S41>/If loop ' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Abs: '<S7>/Abs1'
   *  Product: '<S7>/Divide'
   */
  Master_control_fuzzy_standalo_B.Integrator_e =
    Master_control_fuzzy_standalo_B.Add3_c /
    Master_control_fuzzy_standalo_B.Integrator_e;
  Master_control_fuzzy_standalo_B.Integrator_e = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* MATLAB Function: '<S7>/MATLAB Function' */
  Master_control_f_MATLABFunction(Master_control_fuzzy_standalo_B.Add3_c,
    Master_control_fuzzy_standalo_B.Diff_l,
    &Master_control_fuzzy_standalo_B.SignPreIntegrator,
    &Master_control_fuzzy_standalo_B.sf_MATLABFunction_d);

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Product: '<S7>/Product2'
   */
  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.SignPreIntegrator;

  /* MinMax: '<S7>/MinMax' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  if ((Master_control_fuzzy_standalo_P.Constant1_Value_h <
       Master_control_fuzzy_standalo_B.Integrator_e) || rtIsNaN
      (Master_control_fuzzy_standalo_B.Integrator_e)) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Constant1_Value_h;
  }

  /* End of MinMax: '<S7>/MinMax' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Product: '<S7>/Product3'
   */
  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.Diff_l;

  /* Saturate: '<S7>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Integrator_e >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_m) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_m;
  } else {
    if (Master_control_fuzzy_standalo_B.Integrator_e <
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_p) {
      /* MinMax: '<S8>/MinMax' */
      Master_control_fuzzy_standalo_B.Integrator_e =
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_p;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Sum: '<Root>/Df l2' incorporates:
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  Sum: '<S10>/L2'
   */
  Master_control_fuzzy_standalo_B.Dfl2 =
    ((Master_control_fuzzy_standalo_P.Gain1_Gain_f *
      Master_control_fuzzy_standalo_B.SignPreSat_m -
      Master_control_fuzzy_standalo_P.Gain3_Gain_e *
      Master_control_fuzzy_standalo_B.Filter_ny) -
     Master_control_fuzzy_standalo_P.Gain2_Gain_b *
     Master_control_fuzzy_standalo_B.Integrator_i) +
    Master_control_fuzzy_standalo_B.Integrator_e;

  /* Saturate: '<S4>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Dfl2 >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_mr) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_mr;
  } else if (Master_control_fuzzy_standalo_B.Dfl2 <
             Master_control_fuzzy_standalo_P.Saturation_LowerSat_h) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_LowerSat_h;
  } else {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_B.Dfl2;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Abs: '<S4>/Abs' */
  Master_control_fuzzy_standalo_B.IntegralGain_a = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* If: '<S4>/If loop ' */
  if (Master_control_fuzzy_standalo_B.IntegralGain_a <= 400.0) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    Master_contro_IfActionSubsystem
      (&Master_control_fuzzy_standalo_B.IntegralGain_a,
       &Master_control_fuzzy_standalo_P.IfActionSubsystem_ej);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  } else {
    /* Update for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Update for If: '<S4>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_f);

    /* End of Update for SubSystem: '<S4>/If Action Subsystem1' */
  }

  /* End of If: '<S4>/If loop ' */
  /* If: '<S37>/If loop ' */
  if (Master_control_fuzzy_standalo_B.roll_b == 0.0) {
    /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    Master_contro_IfActionSubsystem
      (&Master_control_fuzzy_standalo_B.Integrator_e,
       &Master_control_fuzzy_standalo_P.IfActionSubsystem_n);

    /* End of Outputs for SubSystem: '<S37>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S37>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    /* MinMax: '<S8>/MinMax' incorporates:
     *  Inport: '<S39>/df'
     */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_B.roll_b;

    /* End of Outputs for SubSystem: '<S37>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S37>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    /* Update for If: '<S37>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_g);

    /* End of Update for SubSystem: '<S37>/If Action Subsystem1' */
  }

  /* End of If: '<S37>/If loop ' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Abs: '<S6>/Abs1'
   *  Product: '<S6>/Divide'
   */
  Master_control_fuzzy_standalo_B.Integrator_e =
    Master_control_fuzzy_standalo_B.roll_b_p /
    Master_control_fuzzy_standalo_B.Integrator_e;
  Master_control_fuzzy_standalo_B.Integrator_e = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* MATLAB Function: '<S6>/MATLAB Function' */
  Master_control_f_MATLABFunction(Master_control_fuzzy_standalo_B.roll_b_p,
    Master_control_fuzzy_standalo_B.roll_b,
    &Master_control_fuzzy_standalo_B.SignPreIntegrator,
    &Master_control_fuzzy_standalo_B.sf_MATLABFunction_n);

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Product: '<S6>/Product2'
   */
  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.SignPreIntegrator;

  /* MinMax: '<S6>/MinMax' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  if ((Master_control_fuzzy_standalo_P.Constant1_Value_be <
       Master_control_fuzzy_standalo_B.Integrator_e) || rtIsNaN
      (Master_control_fuzzy_standalo_B.Integrator_e)) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Constant1_Value_be;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Product: '<S6>/Product3'
   */
  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.roll_b;

  /* Saturate: '<S6>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Integrator_e >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_l) {
    Master_control_fuzzy_standalo_B.Saturation =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_l;
  } else if (Master_control_fuzzy_standalo_B.Integrator_e <
             Master_control_fuzzy_standalo_P.Saturation_LowerSat_o) {
    Master_control_fuzzy_standalo_B.Saturation =
      Master_control_fuzzy_standalo_P.Saturation_LowerSat_o;
  } else {
    Master_control_fuzzy_standalo_B.Saturation =
      Master_control_fuzzy_standalo_B.Integrator_e;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Gain: '<S10>/Gain10'
   *  Gain: '<S10>/Gain11'
   *  Gain: '<S10>/Gain12'
   *  Sum: '<Root>/DF r2'
   *  Sum: '<S10>/R2'
   */
  Master_control_fuzzy_standalo_B.Integrator_e =
    ((Master_control_fuzzy_standalo_P.Gain10_Gain *
      Master_control_fuzzy_standalo_B.SignPreSat_m -
      Master_control_fuzzy_standalo_P.Gain12_Gain *
      Master_control_fuzzy_standalo_B.Filter_ny) +
     Master_control_fuzzy_standalo_P.Gain11_Gain *
     Master_control_fuzzy_standalo_B.Integrator_i) +
    Master_control_fuzzy_standalo_B.Saturation;

  /* Saturate: '<S2>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Integrator_e >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_la) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_la;
  } else {
    if (Master_control_fuzzy_standalo_B.Integrator_e <
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_hm) {
      /* MinMax: '<S8>/MinMax' */
      Master_control_fuzzy_standalo_B.Integrator_e =
        Master_control_fuzzy_standalo_P.Saturation_LowerSat_hm;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Abs: '<S2>/Abs' */
  Master_control_fuzzy_standalo_B.IntegralGain_e = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* If: '<S2>/If loop ' */
  if (Master_control_fuzzy_standalo_B.IntegralGain_e <= 400.0) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    Master_contro_IfActionSubsystem
      (&Master_control_fuzzy_standalo_B.IntegralGain_e,
       &Master_control_fuzzy_standalo_P.IfActionSubsystem_b);

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Update for If: '<S2>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_b);

    /* End of Update for SubSystem: '<S2>/If Action Subsystem1' */
  }

  /* End of If: '<S2>/If loop ' */
  /* Sum: '<S10>/L1' incorporates:
   *  Gain: '<S10>/Gain4'
   *  Gain: '<S10>/Gain5'
   *  Gain: '<S10>/Gain8'
   */
  Master_control_fuzzy_standalo_B.L1 =
    (Master_control_fuzzy_standalo_P.Gain4_Gain_n *
     Master_control_fuzzy_standalo_B.SignPreSat_m +
     Master_control_fuzzy_standalo_P.Gain8_Gain *
     Master_control_fuzzy_standalo_B.Filter_ny) -
    Master_control_fuzzy_standalo_P.Gain5_Gain_g *
    Master_control_fuzzy_standalo_B.Integrator_i;

  /* If: '<S33>/If loop ' */
  if (Master_control_fuzzy_standalo_B.Diff == 0.0) {
    /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    Master_contro_IfActionSubsystem
      (&Master_control_fuzzy_standalo_B.Integrator_e,
       &Master_control_fuzzy_standalo_P.IfActionSubsystem_f);

    /* End of Outputs for SubSystem: '<S33>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* MinMax: '<S8>/MinMax' incorporates:
     *  Inport: '<S35>/df'
     */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_B.Diff;

    /* End of Outputs for SubSystem: '<S33>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S33>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Update for If: '<S33>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_n);

    /* End of Update for SubSystem: '<S33>/If Action Subsystem1' */
  }

  /* End of If: '<S33>/If loop ' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Abs: '<S5>/Abs1'
   *  Product: '<S5>/Divide'
   */
  Master_control_fuzzy_standalo_B.Integrator_e =
    Master_control_fuzzy_standalo_B.Add1 /
    Master_control_fuzzy_standalo_B.Integrator_e;
  Master_control_fuzzy_standalo_B.Integrator_e = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* MATLAB Function: '<S5>/MATLAB Function' */
  Master_control_f_MATLABFunction(Master_control_fuzzy_standalo_B.Add1,
    Master_control_fuzzy_standalo_B.Diff,
    &Master_control_fuzzy_standalo_B.SignPreIntegrator,
    &Master_control_fuzzy_standalo_B.sf_MATLABFunction);

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Product: '<S5>/Product2'
   */
  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.SignPreIntegrator;

  /* MinMax: '<S5>/MinMax' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  if ((Master_control_fuzzy_standalo_P.Constant1_Value_hw <
       Master_control_fuzzy_standalo_B.Integrator_e) || rtIsNaN
      (Master_control_fuzzy_standalo_B.Integrator_e)) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Constant1_Value_hw;
  }

  /* End of MinMax: '<S5>/MinMax' */

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Product: '<S5>/Product3'
   */
  Master_control_fuzzy_standalo_B.Integrator_e *=
    Master_control_fuzzy_standalo_B.Diff;

  /* Saturate: '<S5>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Integrator_e >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_h) {
    Master_control_fuzzy_standalo_B.Saturation_c =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_h;
  } else if (Master_control_fuzzy_standalo_B.Integrator_e <
             Master_control_fuzzy_standalo_P.Saturation_LowerSat_p3) {
    Master_control_fuzzy_standalo_B.Saturation_c =
      Master_control_fuzzy_standalo_P.Saturation_LowerSat_p3;
  } else {
    Master_control_fuzzy_standalo_B.Saturation_c =
      Master_control_fuzzy_standalo_B.Integrator_e;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Sum: '<Root>/DF l1' */
  Master_control_fuzzy_standalo_B.DFl1 = Master_control_fuzzy_standalo_B.L1 +
    Master_control_fuzzy_standalo_B.Saturation_c;

  /* Saturate: '<S1>/Saturation' */
  if (Master_control_fuzzy_standalo_B.DFl1 >
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_b) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_UpperSat_b;
  } else if (Master_control_fuzzy_standalo_B.DFl1 <
             Master_control_fuzzy_standalo_P.Saturation_LowerSat_e) {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_P.Saturation_LowerSat_e;
  } else {
    /* MinMax: '<S8>/MinMax' */
    Master_control_fuzzy_standalo_B.Integrator_e =
      Master_control_fuzzy_standalo_B.DFl1;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Abs: '<S1>/Abs' */
  Master_control_fuzzy_standalo_B.Merge = fabs
    (Master_control_fuzzy_standalo_B.Integrator_e);

  /* If: '<S1>/If loop ' */
  if (Master_control_fuzzy_standalo_B.Merge <= 400.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    Master_contro_IfActionSubsystem(&Master_control_fuzzy_standalo_B.Merge,
      &Master_control_fuzzy_standalo_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  } else {
    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Update for If: '<S1>/If loop ' */
    srUpdateBC(Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRan_fz);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem1' */
  }

  /* End of If: '<S1>/If loop ' */
  /* MinMax: '<S8>/MinMax' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion3'
   */
  Master_control_fuzzy_standalo_B.Integrator_e =
    Master_control_fuzzy_standalo_B.mpu6050_o4;

  /* Product: '<S17>/Divide6' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  Master_control_fuzzy_standalo_B.Divide6 =
    Master_control_fuzzy_standalo_B.Integrator_e /
    Master_control_fuzzy_standalo_P.Constant2_Value_l;

  /* Lookup_n-D: '<Root>/1-D Lookup Table4' */
  Master_control_fuzzy_standalo_B.uDLookupTable4 = look1_binlxpw
    (Master_control_fuzzy_standalo_B.IntegralGain_d,
     Master_control_fuzzy_standalo_P.uDLookupTable4_bp01Data,
     Master_control_fuzzy_standalo_P.uDLookupTable4_tableData, 1U);

  /* Outputs for Atomic SubSystem: '<Root>/feedback2' */
  /* DiscreteTransferFcn: '<S13>/LPF' */
  Master_control_fuzzy_standalo_B.SignPreIntegrator =
    Master_control_fuzzy_standalo_P.LPF_NumCoef_p *
    Master_control_fuzzy_standal_DW.LPF_states_f;

  /* Lookup_n-D: '<S13>/1-D Lookup Table2' */
  Master_control_fuzzy_standalo_B.uDLookupTable2_ov = look1_binlxpw
    (Master_control_fuzzy_standalo_B.SignPreIntegrator,
     Master_control_fuzzy_standalo_P.uDLookupTable2_bp01Data_p,
     Master_control_fuzzy_standalo_P.uDLookupTable2_tableData_g, 1U);

  /* MATLABSystem: '<S13>/Analog Input1' */
  if (Master_control_fuzzy_standal_DW.obj_n.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_h) {
    Master_control_fuzzy_standal_DW.obj_n.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_h;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_n.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_n.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S13>/Product2' incorporates:
   *  Constant: '<S13>/Constant1'
   *  MATLABSystem: '<S13>/Analog Input1'
   */
  Master_control_fuzzy_standalo_B.Product2 = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Constant1_Value_b;

  /* Update for DiscreteTransferFcn: '<S13>/LPF' */
  Master_control_fuzzy_standal_DW.LPF_states_f =
    (Master_control_fuzzy_standalo_B.Product2 -
     Master_control_fuzzy_standalo_P.LPF_DenCoef_b[1] *
     Master_control_fuzzy_standal_DW.LPF_states_f) /
    Master_control_fuzzy_standalo_P.LPF_DenCoef_b[0];

  /* End of Outputs for SubSystem: '<Root>/feedback2' */

  /* Sum: '<Root>/Add4' */
  Master_control_fuzzy_standalo_B.IntegralGain_d =
    Master_control_fuzzy_standalo_B.uDLookupTable4 -
    Master_control_fuzzy_standalo_B.uDLookupTable2_ov;

  /* MinMax: '<S8>/MinMax' incorporates:
   *  DiscreteIntegrator: '<S133>/Integrator'
   */
  Master_control_fuzzy_standalo_B.Integrator_e =
    Master_control_fuzzy_standal_DW.Integrator_DSTATE;

  /* Gain: '<S136>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S128>/Filter'
   *  Gain: '<S127>/Derivative Gain'
   *  Sum: '<S128>/SumD'
   */
  Master_control_fuzzy_standalo_B.FilterCoefficient =
    (Master_control_fuzzy_standalo_P.frontright_D *
     Master_control_fuzzy_standalo_B.IntegralGain_d -
     Master_control_fuzzy_standal_DW.Filter_DSTATE) *
    Master_control_fuzzy_standalo_P.frontright_N;

  /* Sum: '<S142>/Sum' incorporates:
   *  Gain: '<S138>/Proportional Gain'
   */
  Master_control_fuzzy_standalo_B.SignPreSat_m =
    (Master_control_fuzzy_standalo_P.frontright_P *
     Master_control_fuzzy_standalo_B.IntegralGain_d +
     Master_control_fuzzy_standalo_B.Integrator_e) +
    Master_control_fuzzy_standalo_B.FilterCoefficient;

  /* Saturate: '<S140>/Saturation' */
  if (Master_control_fuzzy_standalo_B.SignPreSat_m >
      Master_control_fuzzy_standalo_P.frontright_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_m =
      Master_control_fuzzy_standalo_P.frontright_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_m <
             Master_control_fuzzy_standalo_P.frontright_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_m =
      Master_control_fuzzy_standalo_P.frontright_LowerSaturationLimit;
  } else {
    Master_control_fuzzy_standalo_B.Saturation_m =
      Master_control_fuzzy_standalo_B.SignPreSat_m;
  }

  /* End of Saturate: '<S140>/Saturation' */

  /* S-Function (pin_5_PWM): '<Root>/PWM_F_R' */
  pin_5_PWM_Outputs_wrapper(&Master_control_fuzzy_standalo_B.Saturation_m,
    &Master_control_fuzzy_standal_DW.PWM_F_R_DSTATE,
    &Master_control_fuzzy_standalo_P.PWM_F_R_P1, 1);

  /* Lookup_n-D: '<Root>/1-D Lookup Table2' */
  Master_control_fuzzy_standalo_B.uDLookupTable2 = look1_binlxpw
    (Master_control_fuzzy_standalo_B.IntegralGain_a,
     Master_control_fuzzy_standalo_P.uDLookupTable2_bp01Data_lb,
     Master_control_fuzzy_standalo_P.uDLookupTable2_tableData_o, 1U);

  /* Outputs for Atomic SubSystem: '<Root>/feedback1' */
  /* DiscreteTransferFcn: '<S12>/LPF' */
  Master_control_fuzzy_standalo_B.SignPreIntegrator =
    Master_control_fuzzy_standalo_P.LPF_NumCoef_d *
    Master_control_fuzzy_standal_DW.LPF_states_g;

  /* Lookup_n-D: '<S12>/1-D Lookup Table2' */
  Master_control_fuzzy_standalo_B.uDLookupTable2_p = look1_binlxpw
    (Master_control_fuzzy_standalo_B.SignPreIntegrator,
     Master_control_fuzzy_standalo_P.uDLookupTable2_bp01Data_c,
     Master_control_fuzzy_standalo_P.uDLookupTable2_tableData_b, 1U);

  /* MATLABSystem: '<S12>/Analog Input1' */
  if (Master_control_fuzzy_standal_DW.obj_ku.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_n) {
    Master_control_fuzzy_standal_DW.obj_ku.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_n;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_ku.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_ku.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S12>/Product2' incorporates:
   *  Constant: '<S12>/Constant1'
   *  MATLABSystem: '<S12>/Analog Input1'
   */
  Master_control_fuzzy_standalo_B.Product2 = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Constant1_Value_j;

  /* Update for DiscreteTransferFcn: '<S12>/LPF' */
  Master_control_fuzzy_standal_DW.LPF_states_g =
    (Master_control_fuzzy_standalo_B.Product2 -
     Master_control_fuzzy_standalo_P.LPF_DenCoef_m[1] *
     Master_control_fuzzy_standal_DW.LPF_states_g) /
    Master_control_fuzzy_standalo_P.LPF_DenCoef_m[0];

  /* End of Outputs for SubSystem: '<Root>/feedback1' */

  /* Sum: '<Root>/Add3' */
  Master_control_fuzzy_standalo_B.IntegralGain_a =
    Master_control_fuzzy_standalo_B.uDLookupTable2 -
    Master_control_fuzzy_standalo_B.uDLookupTable2_p;

  /* Gain: '<S181>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S173>/Filter'
   *  Gain: '<S172>/Derivative Gain'
   *  Sum: '<S173>/SumD'
   */
  Master_control_fuzzy_standalo_B.FilterCoefficient_b =
    (Master_control_fuzzy_standalo_P.rearleft_D *
     Master_control_fuzzy_standalo_B.IntegralGain_a -
     Master_control_fuzzy_standal_DW.Filter_DSTATE_o) *
    Master_control_fuzzy_standalo_P.rearleft_N;

  /* Sum: '<S187>/Sum' incorporates:
   *  DiscreteIntegrator: '<S178>/Integrator'
   *  Gain: '<S183>/Proportional Gain'
   */
  Master_control_fuzzy_standalo_B.Integrator_i =
    (Master_control_fuzzy_standalo_P.rearleft_P *
     Master_control_fuzzy_standalo_B.IntegralGain_a +
     Master_control_fuzzy_standal_DW.Integrator_DSTATE_e) +
    Master_control_fuzzy_standalo_B.FilterCoefficient_b;

  /* Saturate: '<S185>/Saturation' */
  if (Master_control_fuzzy_standalo_B.Integrator_i >
      Master_control_fuzzy_standalo_P.rearleft_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_cm =
      Master_control_fuzzy_standalo_P.rearleft_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.Integrator_i <
             Master_control_fuzzy_standalo_P.rearleft_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_cm =
      Master_control_fuzzy_standalo_P.rearleft_LowerSaturationLimit;
  } else {
    Master_control_fuzzy_standalo_B.Saturation_cm =
      Master_control_fuzzy_standalo_B.Integrator_i;
  }

  /* End of Saturate: '<S185>/Saturation' */

  /* S-Function (pin_4_PWM): '<Root>/PWM_R_L' */
  pin_4_PWM_Outputs_wrapper(&Master_control_fuzzy_standalo_B.Saturation_cm,
    &Master_control_fuzzy_standal_DW.PWM_R_L_DSTATE,
    &Master_control_fuzzy_standalo_P.PWM_R_L_P1, 1);

  /* Lookup_n-D: '<Root>/1-D Lookup Table5' */
  Master_control_fuzzy_standalo_B.uDLookupTable5 = look1_binlxpw
    (Master_control_fuzzy_standalo_B.IntegralGain_e,
     Master_control_fuzzy_standalo_P.uDLookupTable5_bp01Data,
     Master_control_fuzzy_standalo_P.uDLookupTable5_tableData, 1U);

  /* Outputs for Atomic SubSystem: '<Root>/feedback3' */
  /* DiscreteTransferFcn: '<S14>/LPF' */
  Master_control_fuzzy_standalo_B.SignPreIntegrator =
    Master_control_fuzzy_standalo_P.LPF_NumCoef_j *
    Master_control_fuzzy_standal_DW.LPF_states;

  /* Lookup_n-D: '<S14>/1-D Lookup Table2' */
  Master_control_fuzzy_standalo_B.uDLookupTable2_o = look1_binlxpw
    (Master_control_fuzzy_standalo_B.SignPreIntegrator,
     Master_control_fuzzy_standalo_P.uDLookupTable2_bp01Data_l,
     Master_control_fuzzy_standalo_P.uDLookupTable2_tableData_k, 1U);

  /* MATLABSystem: '<S14>/Analog Input1' */
  if (Master_control_fuzzy_standal_DW.obj_a.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_i) {
    Master_control_fuzzy_standal_DW.obj_a.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_i;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_a.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_a.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S14>/Product2' incorporates:
   *  Constant: '<S14>/Constant1'
   *  MATLABSystem: '<S14>/Analog Input1'
   */
  Master_control_fuzzy_standalo_B.Product2 = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Constant1_Value_o;

  /* Update for DiscreteTransferFcn: '<S14>/LPF' */
  Master_control_fuzzy_standal_DW.LPF_states =
    (Master_control_fuzzy_standalo_B.Product2 -
     Master_control_fuzzy_standalo_P.LPF_DenCoef_k[1] *
     Master_control_fuzzy_standal_DW.LPF_states) /
    Master_control_fuzzy_standalo_P.LPF_DenCoef_k[0];

  /* End of Outputs for SubSystem: '<Root>/feedback3' */

  /* Sum: '<Root>/Add5' */
  Master_control_fuzzy_standalo_B.IntegralGain_e =
    Master_control_fuzzy_standalo_B.uDLookupTable5 -
    Master_control_fuzzy_standalo_B.uDLookupTable2_o;

  /* Gain: '<S225>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S217>/Filter'
   *  Gain: '<S216>/Derivative Gain'
   *  Sum: '<S217>/SumD'
   */
  Master_control_fuzzy_standalo_B.FilterCoefficient_l =
    (Master_control_fuzzy_standalo_P.rearright_D *
     Master_control_fuzzy_standalo_B.IntegralGain_e -
     Master_control_fuzzy_standal_DW.Filter_DSTATE_i) *
    Master_control_fuzzy_standalo_P.rearright_N;

  /* Sum: '<S231>/Sum' incorporates:
   *  DiscreteIntegrator: '<S222>/Integrator'
   *  Gain: '<S227>/Proportional Gain'
   */
  Master_control_fuzzy_standalo_B.SignPreSat_i =
    (Master_control_fuzzy_standalo_P.rearright_P *
     Master_control_fuzzy_standalo_B.IntegralGain_e +
     Master_control_fuzzy_standal_DW.Integrator_DSTATE_b) +
    Master_control_fuzzy_standalo_B.FilterCoefficient_l;

  /* Saturate: '<S229>/Saturation' */
  if (Master_control_fuzzy_standalo_B.SignPreSat_i >
      Master_control_fuzzy_standalo_P.rearright_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_c1 =
      Master_control_fuzzy_standalo_P.rearright_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_i <
             Master_control_fuzzy_standalo_P.rearright_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_c1 =
      Master_control_fuzzy_standalo_P.rearright_LowerSaturationLimit;
  } else {
    Master_control_fuzzy_standalo_B.Saturation_c1 =
      Master_control_fuzzy_standalo_B.SignPreSat_i;
  }

  /* End of Saturate: '<S229>/Saturation' */

  /* S-Function (pin_3_PWM): '<Root>/PWM_R_R' */
  pin_3_PWM_Outputs_wrapper(&Master_control_fuzzy_standalo_B.Saturation_c1,
    &Master_control_fuzzy_standal_DW.PWM_R_R_DSTATE,
    &Master_control_fuzzy_standalo_P.PWM_R_R_P1, 1);

  /* Lookup_n-D: '<Root>/1-D Lookup Table' */
  Master_control_fuzzy_standalo_B.uDLookupTable = look1_binlxpw
    (Master_control_fuzzy_standalo_B.Merge,
     Master_control_fuzzy_standalo_P.uDLookupTable_bp01Data,
     Master_control_fuzzy_standalo_P.uDLookupTable_tableData, 1U);

  /* Outputs for Atomic SubSystem: '<Root>/feedback' */
  /* DiscreteTransferFcn: '<S11>/LPF' */
  Master_control_fuzzy_standalo_B.SignPreIntegrator =
    Master_control_fuzzy_standalo_P.LPF_NumCoef *
    Master_control_fuzzy_standal_DW.LPF_states_o;

  /* Lookup_n-D: '<S11>/1-D Lookup Table2' */
  Master_control_fuzzy_standalo_B.uDLookupTable2_c = look1_binlxpw
    (Master_control_fuzzy_standalo_B.SignPreIntegrator,
     Master_control_fuzzy_standalo_P.uDLookupTable2_bp01Data,
     Master_control_fuzzy_standalo_P.uDLookupTable2_tableData, 1U);

  /* MATLABSystem: '<S11>/Analog Input1' */
  if (Master_control_fuzzy_standal_DW.obj_i.SampleTime !=
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_k) {
    Master_control_fuzzy_standal_DW.obj_i.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_k;
  }

  MW_AnalogIn_Start(Master_control_fuzzy_standal_DW.obj_i.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (Master_control_fuzzy_standal_DW.obj_i.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput3_d_0, 3);

  /* Product: '<S11>/Product2' incorporates:
   *  Constant: '<S11>/Constant1'
   *  MATLABSystem: '<S11>/Analog Input1'
   */
  Master_control_fuzzy_standalo_B.Product2 = (real_T)rtb_AnalogInput3_d_0 *
    Master_control_fuzzy_standalo_P.Constant1_Value;

  /* Update for DiscreteTransferFcn: '<S11>/LPF' */
  Master_control_fuzzy_standal_DW.LPF_states_o =
    (Master_control_fuzzy_standalo_B.Product2 -
     Master_control_fuzzy_standalo_P.LPF_DenCoef[1] *
     Master_control_fuzzy_standal_DW.LPF_states_o) /
    Master_control_fuzzy_standalo_P.LPF_DenCoef[0];

  /* End of Outputs for SubSystem: '<Root>/feedback' */

  /* Sum: '<Root>/Add2' */
  Master_control_fuzzy_standalo_B.Switch =
    Master_control_fuzzy_standalo_B.uDLookupTable -
    Master_control_fuzzy_standalo_B.uDLookupTable2_c;

  /* Gain: '<S92>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S84>/Filter'
   *  Gain: '<S83>/Derivative Gain'
   *  Sum: '<S84>/SumD'
   */
  Master_control_fuzzy_standalo_B.FilterCoefficient_br =
    (Master_control_fuzzy_standalo_P.frontleft_D *
     Master_control_fuzzy_standalo_B.Switch -
     Master_control_fuzzy_standal_DW.Filter_DSTATE_n) *
    Master_control_fuzzy_standalo_P.frontleft_N;

  /* Sum: '<S98>/Sum' incorporates:
   *  DiscreteIntegrator: '<S89>/Integrator'
   *  Gain: '<S94>/Proportional Gain'
   */
  Master_control_fuzzy_standalo_B.SignPreIntegrator =
    (Master_control_fuzzy_standalo_P.frontleft_P *
     Master_control_fuzzy_standalo_B.Switch +
     Master_control_fuzzy_standal_DW.Integrator_DSTATE_g) +
    Master_control_fuzzy_standalo_B.FilterCoefficient_br;

  /* Saturate: '<S96>/Saturation' */
  if (Master_control_fuzzy_standalo_B.SignPreIntegrator >
      Master_control_fuzzy_standalo_P.frontleft_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_e =
      Master_control_fuzzy_standalo_P.frontleft_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.SignPreIntegrator <
             Master_control_fuzzy_standalo_P.frontleft_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.Saturation_e =
      Master_control_fuzzy_standalo_P.frontleft_LowerSaturationLimit;
  } else {
    Master_control_fuzzy_standalo_B.Saturation_e =
      Master_control_fuzzy_standalo_B.SignPreIntegrator;
  }

  /* End of Saturate: '<S96>/Saturation' */

  /* S-Function (pin_6_PWM): '<Root>/pwm_fL' */
  pin_6_PWM_Outputs_wrapper(&Master_control_fuzzy_standalo_B.Saturation_e,
    &Master_control_fuzzy_standal_DW.pwm_fL_DSTATE,
    &Master_control_fuzzy_standalo_P.pwm_fL_P1, 1);

  /* Gain: '<S82>/ZeroGain' */
  Master_control_fuzzy_standalo_B.Filter_ny =
    Master_control_fuzzy_standalo_P.ZeroGain_Gain *
    Master_control_fuzzy_standalo_B.SignPreIntegrator;

  /* DeadZone: '<S82>/DeadZone' */
  if (Master_control_fuzzy_standalo_B.SignPreIntegrator >
      Master_control_fuzzy_standalo_P.frontleft_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator -=
      Master_control_fuzzy_standalo_P.frontleft_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.SignPreIntegrator >=
             Master_control_fuzzy_standalo_P.frontleft_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreIntegrator -=
      Master_control_fuzzy_standalo_P.frontleft_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S82>/DeadZone' */

  /* RelationalOperator: '<S82>/NotEqual' */
  rtb_NotEqual = (Master_control_fuzzy_standalo_B.Filter_ny !=
                  Master_control_fuzzy_standalo_B.SignPreIntegrator);

  /* Signum: '<S82>/SignPreSat' */
  if (Master_control_fuzzy_standalo_B.SignPreIntegrator < 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = -1.0;
  } else if (Master_control_fuzzy_standalo_B.SignPreIntegrator > 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 1.0;
  } else if (Master_control_fuzzy_standalo_B.SignPreIntegrator == 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S82>/SignPreSat' */

  /* DataTypeConversion: '<S82>/DataTypeConv1' */
  Master_control_fuzzy_standalo_B.Filter_ny = floor
    (Master_control_fuzzy_standalo_B.SignPreIntegrator);
  if (rtIsNaN(Master_control_fuzzy_standalo_B.Filter_ny) || rtIsInf
      (Master_control_fuzzy_standalo_B.Filter_ny)) {
    Master_control_fuzzy_standalo_B.Filter_ny = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.Filter_ny = fmod
      (Master_control_fuzzy_standalo_B.Filter_ny, 256.0);
  }

  /* Gain: '<S86>/Integral Gain' */
  Master_control_fuzzy_standalo_B.Switch *=
    Master_control_fuzzy_standalo_P.frontleft_I;

  /* Signum: '<S82>/SignPreIntegrator' */
  if (Master_control_fuzzy_standalo_B.Switch < 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = -1.0;
  } else if (Master_control_fuzzy_standalo_B.Switch > 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 1.0;
  } else if (Master_control_fuzzy_standalo_B.Switch == 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S82>/SignPreIntegrator' */

  /* DataTypeConversion: '<S82>/DataTypeConv2' */
  Master_control_fuzzy_standalo_B.d0 = floor
    (Master_control_fuzzy_standalo_B.SignPreIntegrator);
  if (rtIsNaN(Master_control_fuzzy_standalo_B.d0) || rtIsInf
      (Master_control_fuzzy_standalo_B.d0)) {
    Master_control_fuzzy_standalo_B.d0 = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.d0 = fmod(Master_control_fuzzy_standalo_B.d0,
      256.0);
  }

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S82>/Constant1'
   *  DataTypeConversion: '<S82>/DataTypeConv1'
   *  DataTypeConversion: '<S82>/DataTypeConv2'
   *  Logic: '<S82>/AND3'
   *  RelationalOperator: '<S82>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)(Master_control_fuzzy_standalo_B.Filter_ny < 0.0 ?
        (int32_T)(int8_T)-(int8_T)(uint8_T)
        -Master_control_fuzzy_standalo_B.Filter_ny : (int32_T)(int8_T)(uint8_T)
        Master_control_fuzzy_standalo_B.Filter_ny) ==
                       (Master_control_fuzzy_standalo_B.d0 < 0.0 ? (int32_T)
                        (int8_T)-(int8_T)(uint8_T)
                        -Master_control_fuzzy_standalo_B.d0 : (int32_T)(int8_T)
                        (uint8_T)Master_control_fuzzy_standalo_B.d0))) {
    Master_control_fuzzy_standalo_B.Switch =
      Master_control_fuzzy_standalo_P.Constant1_Value_ig;
  }

  /* End of Switch: '<S82>/Switch' */
  /* Gain: '<S215>/ZeroGain' */
  Master_control_fuzzy_standalo_B.Filter_ny =
    Master_control_fuzzy_standalo_P.ZeroGain_Gain_l *
    Master_control_fuzzy_standalo_B.SignPreSat_i;

  /* DeadZone: '<S215>/DeadZone' */
  if (Master_control_fuzzy_standalo_B.SignPreSat_i >
      Master_control_fuzzy_standalo_P.rearright_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.SignPreSat_i -=
      Master_control_fuzzy_standalo_P.rearright_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_i >=
             Master_control_fuzzy_standalo_P.rearright_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.SignPreSat_i = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreSat_i -=
      Master_control_fuzzy_standalo_P.rearright_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S215>/DeadZone' */

  /* RelationalOperator: '<S215>/NotEqual' */
  rtb_NotEqual = (Master_control_fuzzy_standalo_B.Filter_ny !=
                  Master_control_fuzzy_standalo_B.SignPreSat_i);

  /* Signum: '<S215>/SignPreSat' */
  if (Master_control_fuzzy_standalo_B.SignPreSat_i < 0.0) {
    Master_control_fuzzy_standalo_B.SignPreSat_i = -1.0;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_i > 0.0) {
    Master_control_fuzzy_standalo_B.SignPreSat_i = 1.0;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_i == 0.0) {
    Master_control_fuzzy_standalo_B.SignPreSat_i = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreSat_i = (rtNaN);
  }

  /* End of Signum: '<S215>/SignPreSat' */

  /* Gain: '<S219>/Integral Gain' */
  Master_control_fuzzy_standalo_B.IntegralGain_e *=
    Master_control_fuzzy_standalo_P.rearright_I;

  /* Signum: '<S215>/SignPreIntegrator' */
  if (Master_control_fuzzy_standalo_B.IntegralGain_e < 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = -1.0;
  } else if (Master_control_fuzzy_standalo_B.IntegralGain_e > 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 1.0;
  } else if (Master_control_fuzzy_standalo_B.IntegralGain_e == 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S215>/SignPreIntegrator' */

  /* DataTypeConversion: '<S215>/DataTypeConv1' */
  if (rtIsNaN(Master_control_fuzzy_standalo_B.SignPreSat_i)) {
    Master_control_fuzzy_standalo_B.Filter_ny = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.Filter_ny = fmod
      (Master_control_fuzzy_standalo_B.SignPreSat_i, 256.0);
  }

  /* DataTypeConversion: '<S215>/DataTypeConv2' */
  Master_control_fuzzy_standalo_B.d0 = floor
    (Master_control_fuzzy_standalo_B.SignPreIntegrator);
  if (rtIsNaN(Master_control_fuzzy_standalo_B.d0) || rtIsInf
      (Master_control_fuzzy_standalo_B.d0)) {
    Master_control_fuzzy_standalo_B.d0 = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.d0 = fmod(Master_control_fuzzy_standalo_B.d0,
      256.0);
  }

  /* Switch: '<S215>/Switch' incorporates:
   *  Constant: '<S215>/Constant1'
   *  DataTypeConversion: '<S215>/DataTypeConv1'
   *  DataTypeConversion: '<S215>/DataTypeConv2'
   *  Logic: '<S215>/AND3'
   *  RelationalOperator: '<S215>/Equal1'
   */
  if (rtb_NotEqual && ((Master_control_fuzzy_standalo_B.Filter_ny < 0.0 ?
                        (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -Master_control_fuzzy_standalo_B.Filter_ny : (int32_T)
                        (int8_T)(uint8_T)
                        Master_control_fuzzy_standalo_B.Filter_ny) ==
                       (Master_control_fuzzy_standalo_B.d0 < 0.0 ? (int32_T)
                        (int8_T)-(int8_T)(uint8_T)
                        -Master_control_fuzzy_standalo_B.d0 : (int32_T)(int8_T)
                        (uint8_T)Master_control_fuzzy_standalo_B.d0))) {
    Master_control_fuzzy_standalo_B.Switch_e =
      Master_control_fuzzy_standalo_P.Constant1_Value_l;
  } else {
    Master_control_fuzzy_standalo_B.Switch_e =
      Master_control_fuzzy_standalo_B.IntegralGain_e;
  }

  /* End of Switch: '<S215>/Switch' */
  /* Gain: '<S171>/ZeroGain' */
  Master_control_fuzzy_standalo_B.Filter_ny =
    Master_control_fuzzy_standalo_P.ZeroGain_Gain_f *
    Master_control_fuzzy_standalo_B.Integrator_i;

  /* DeadZone: '<S171>/DeadZone' */
  if (Master_control_fuzzy_standalo_B.Integrator_i >
      Master_control_fuzzy_standalo_P.rearleft_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.Integrator_i -=
      Master_control_fuzzy_standalo_P.rearleft_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.Integrator_i >=
             Master_control_fuzzy_standalo_P.rearleft_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.Integrator_i = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.Integrator_i -=
      Master_control_fuzzy_standalo_P.rearleft_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S171>/DeadZone' */

  /* RelationalOperator: '<S171>/NotEqual' */
  rtb_NotEqual = (Master_control_fuzzy_standalo_B.Filter_ny !=
                  Master_control_fuzzy_standalo_B.Integrator_i);

  /* Signum: '<S171>/SignPreSat' */
  if (Master_control_fuzzy_standalo_B.Integrator_i < 0.0) {
    Master_control_fuzzy_standalo_B.Integrator_i = -1.0;
  } else if (Master_control_fuzzy_standalo_B.Integrator_i > 0.0) {
    Master_control_fuzzy_standalo_B.Integrator_i = 1.0;
  } else if (Master_control_fuzzy_standalo_B.Integrator_i == 0.0) {
    Master_control_fuzzy_standalo_B.Integrator_i = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.Integrator_i = (rtNaN);
  }

  /* End of Signum: '<S171>/SignPreSat' */

  /* Gain: '<S175>/Integral Gain' */
  Master_control_fuzzy_standalo_B.IntegralGain_a *=
    Master_control_fuzzy_standalo_P.rearleft_I;

  /* Signum: '<S171>/SignPreIntegrator' */
  if (Master_control_fuzzy_standalo_B.IntegralGain_a < 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = -1.0;
  } else if (Master_control_fuzzy_standalo_B.IntegralGain_a > 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 1.0;
  } else if (Master_control_fuzzy_standalo_B.IntegralGain_a == 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S171>/SignPreIntegrator' */

  /* DataTypeConversion: '<S171>/DataTypeConv1' */
  if (rtIsNaN(Master_control_fuzzy_standalo_B.Integrator_i)) {
    Master_control_fuzzy_standalo_B.Filter_ny = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.Filter_ny = fmod
      (Master_control_fuzzy_standalo_B.Integrator_i, 256.0);
  }

  /* DataTypeConversion: '<S171>/DataTypeConv2' */
  Master_control_fuzzy_standalo_B.d0 = floor
    (Master_control_fuzzy_standalo_B.SignPreIntegrator);
  if (rtIsNaN(Master_control_fuzzy_standalo_B.d0) || rtIsInf
      (Master_control_fuzzy_standalo_B.d0)) {
    Master_control_fuzzy_standalo_B.d0 = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.d0 = fmod(Master_control_fuzzy_standalo_B.d0,
      256.0);
  }

  /* Switch: '<S171>/Switch' incorporates:
   *  Constant: '<S171>/Constant1'
   *  DataTypeConversion: '<S171>/DataTypeConv1'
   *  DataTypeConversion: '<S171>/DataTypeConv2'
   *  Logic: '<S171>/AND3'
   *  RelationalOperator: '<S171>/Equal1'
   */
  if (rtb_NotEqual && ((Master_control_fuzzy_standalo_B.Filter_ny < 0.0 ?
                        (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -Master_control_fuzzy_standalo_B.Filter_ny : (int32_T)
                        (int8_T)(uint8_T)
                        Master_control_fuzzy_standalo_B.Filter_ny) ==
                       (Master_control_fuzzy_standalo_B.d0 < 0.0 ? (int32_T)
                        (int8_T)-(int8_T)(uint8_T)
                        -Master_control_fuzzy_standalo_B.d0 : (int32_T)(int8_T)
                        (uint8_T)Master_control_fuzzy_standalo_B.d0))) {
    Master_control_fuzzy_standalo_B.Switch_g =
      Master_control_fuzzy_standalo_P.Constant1_Value_hh;
  } else {
    Master_control_fuzzy_standalo_B.Switch_g =
      Master_control_fuzzy_standalo_B.IntegralGain_a;
  }

  /* End of Switch: '<S171>/Switch' */
  /* Gain: '<S126>/ZeroGain' */
  Master_control_fuzzy_standalo_B.Filter_ny =
    Master_control_fuzzy_standalo_P.ZeroGain_Gain_j *
    Master_control_fuzzy_standalo_B.SignPreSat_m;

  /* DeadZone: '<S126>/DeadZone' */
  if (Master_control_fuzzy_standalo_B.SignPreSat_m >
      Master_control_fuzzy_standalo_P.frontright_UpperSaturationLimit) {
    Master_control_fuzzy_standalo_B.SignPreSat_m -=
      Master_control_fuzzy_standalo_P.frontright_UpperSaturationLimit;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_m >=
             Master_control_fuzzy_standalo_P.frontright_LowerSaturationLimit) {
    Master_control_fuzzy_standalo_B.SignPreSat_m = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreSat_m -=
      Master_control_fuzzy_standalo_P.frontright_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S126>/DeadZone' */

  /* RelationalOperator: '<S126>/NotEqual' */
  rtb_NotEqual = (Master_control_fuzzy_standalo_B.Filter_ny !=
                  Master_control_fuzzy_standalo_B.SignPreSat_m);

  /* Signum: '<S126>/SignPreSat' */
  if (Master_control_fuzzy_standalo_B.SignPreSat_m < 0.0) {
    Master_control_fuzzy_standalo_B.SignPreSat_m = -1.0;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_m > 0.0) {
    Master_control_fuzzy_standalo_B.SignPreSat_m = 1.0;
  } else if (Master_control_fuzzy_standalo_B.SignPreSat_m == 0.0) {
    Master_control_fuzzy_standalo_B.SignPreSat_m = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreSat_m = (rtNaN);
  }

  /* End of Signum: '<S126>/SignPreSat' */

  /* Gain: '<S130>/Integral Gain' */
  Master_control_fuzzy_standalo_B.IntegralGain_d *=
    Master_control_fuzzy_standalo_P.frontright_I;

  /* Signum: '<S126>/SignPreIntegrator' */
  if (Master_control_fuzzy_standalo_B.IntegralGain_d < 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = -1.0;
  } else if (Master_control_fuzzy_standalo_B.IntegralGain_d > 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 1.0;
  } else if (Master_control_fuzzy_standalo_B.IntegralGain_d == 0.0) {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.SignPreIntegrator = (rtNaN);
  }

  /* End of Signum: '<S126>/SignPreIntegrator' */

  /* DataTypeConversion: '<S126>/DataTypeConv1' */
  if (rtIsNaN(Master_control_fuzzy_standalo_B.SignPreSat_m)) {
    Master_control_fuzzy_standalo_B.Filter_ny = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.Filter_ny = fmod
      (Master_control_fuzzy_standalo_B.SignPreSat_m, 256.0);
  }

  /* DataTypeConversion: '<S126>/DataTypeConv2' */
  Master_control_fuzzy_standalo_B.d0 = floor
    (Master_control_fuzzy_standalo_B.SignPreIntegrator);
  if (rtIsNaN(Master_control_fuzzy_standalo_B.d0) || rtIsInf
      (Master_control_fuzzy_standalo_B.d0)) {
    Master_control_fuzzy_standalo_B.d0 = 0.0;
  } else {
    Master_control_fuzzy_standalo_B.d0 = fmod(Master_control_fuzzy_standalo_B.d0,
      256.0);
  }

  /* Switch: '<S126>/Switch' incorporates:
   *  Constant: '<S126>/Constant1'
   *  DataTypeConversion: '<S126>/DataTypeConv1'
   *  DataTypeConversion: '<S126>/DataTypeConv2'
   *  Logic: '<S126>/AND3'
   *  RelationalOperator: '<S126>/Equal1'
   */
  if (rtb_NotEqual && ((Master_control_fuzzy_standalo_B.Filter_ny < 0.0 ?
                        (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -Master_control_fuzzy_standalo_B.Filter_ny : (int32_T)
                        (int8_T)(uint8_T)
                        Master_control_fuzzy_standalo_B.Filter_ny) ==
                       (Master_control_fuzzy_standalo_B.d0 < 0.0 ? (int32_T)
                        (int8_T)-(int8_T)(uint8_T)
                        -Master_control_fuzzy_standalo_B.d0 : (int32_T)(int8_T)
                        (uint8_T)Master_control_fuzzy_standalo_B.d0))) {
    Master_control_fuzzy_standalo_B.Switch_k =
      Master_control_fuzzy_standalo_P.Constant1_Value_d;
  } else {
    Master_control_fuzzy_standalo_B.Switch_k =
      Master_control_fuzzy_standalo_B.IntegralGain_d;
  }

  /* End of Switch: '<S126>/Switch' */

  /* Update for DiscreteTransferFcn: '<S22>/LPFl1' */
  Master_control_fuzzy_standal_DW.LPFl1_states =
    Master_control_fuzzy_standal_DW.LPFl1_tmp;

  /* Update for UnitDelay: '<S239>/UD'
   *
   * Block description for '<S239>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE =
    Master_control_fuzzy_standalo_B.TSamp;

  /* Update for DiscreteTransferFcn: '<S5>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_states =
    Master_control_fuzzy_standal_DW.HF2_tmp;

  /* Update for DiscreteTransferFcn: '<S5>/LPF2' */
  Master_control_fuzzy_standal_DW.LPF2_states =
    Master_control_fuzzy_standal_DW.LPF2_tmp;

  /* Update for DiscreteIntegrator: '<S5>/s.d1' */
  Master_control_fuzzy_standal_DW.sd1_DSTATE =
    Master_control_fuzzy_standalo_P.sd1_gainval *
    Master_control_fuzzy_standalo_B.LPF2 + Master_control_fuzzy_standalo_B.sd1;

  /* Update for DiscreteTransferFcn: '<S9>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_states_a =
    Master_control_fuzzy_standal_DW.HF2_tmp_k;

  /* Update for DiscreteTransferFcn: '<S9>/LPF2' */
  Master_control_fuzzy_standal_DW.LPF2_states_e =
    Master_control_fuzzy_standal_DW.LPF2_tmp_i;

  /* Update for DiscreteIntegrator: '<S9>/HEAVE_VEL1' */
  Master_control_fuzzy_standal_DW.HEAVE_VEL1_DSTATE =
    Master_control_fuzzy_standalo_P.HEAVE_VEL1_gainval *
    Master_control_fuzzy_standalo_B.LPF2_d +
    Master_control_fuzzy_standalo_B.HEAVE_VEL1;

  /* Update for DiscreteTransferFcn: '<S5>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_states =
    Master_control_fuzzy_standal_DW.HF1_tmp;

  /* Update for DiscreteTransferFcn: '<S5>/LPF1' */
  Master_control_fuzzy_standal_DW.LPF1_states =
    Master_control_fuzzy_standal_DW.LPF1_tmp;

  /* Update for DiscreteIntegrator: '<S5>/s.d' */
  Master_control_fuzzy_standal_DW.sd_DSTATE =
    Master_control_fuzzy_standalo_P.sd_gainval *
    Master_control_fuzzy_standalo_B.LPF1 + Master_control_fuzzy_standalo_B.sd;

  /* Update for DiscreteTransferFcn: '<S20>/LPFr1' */
  Master_control_fuzzy_standal_DW.LPFr1_states =
    Master_control_fuzzy_standal_DW.LPFr1_tmp;

  /* Update for UnitDelay: '<S237>/UD'
   *
   * Block description for '<S237>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_h =
    Master_control_fuzzy_standalo_B.TSamp_o;

  /* Update for DiscreteTransferFcn: '<S8>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_states_m =
    Master_control_fuzzy_standal_DW.HF2_tmp_e;

  /* Update for DiscreteTransferFcn: '<S8>/LPF2' */
  Master_control_fuzzy_standal_DW.LPF2_states_j =
    Master_control_fuzzy_standal_DW.LPF2_tmp_h;

  /* Update for DiscreteIntegrator: '<S8>/s.d1' */
  Master_control_fuzzy_standal_DW.sd1_DSTATE_c =
    Master_control_fuzzy_standalo_P.sd1_gainval_m *
    Master_control_fuzzy_standalo_B.LPF2_b +
    Master_control_fuzzy_standalo_B.sd1_i;

  /* Update for DiscreteTransferFcn: '<S9>/H.F3' */
  Master_control_fuzzy_standal_DW.HF3_states =
    Master_control_fuzzy_standal_DW.HF3_tmp;

  /* Update for DiscreteTransferFcn: '<S9>/LPF3' */
  Master_control_fuzzy_standal_DW.LPF3_states =
    Master_control_fuzzy_standal_DW.LPF3_tmp;

  /* Update for DiscreteIntegrator: '<S9>/HEAVE_VEL2' */
  Master_control_fuzzy_standal_DW.HEAVE_VEL2_DSTATE =
    Master_control_fuzzy_standalo_P.HEAVE_VEL2_gainval *
    Master_control_fuzzy_standalo_B.LPF3 +
    Master_control_fuzzy_standalo_B.HEAVE_VEL2;

  /* Update for DiscreteTransferFcn: '<S8>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_states_e =
    Master_control_fuzzy_standal_DW.HF1_tmp_o;

  /* Update for DiscreteTransferFcn: '<S8>/LPF1' */
  Master_control_fuzzy_standal_DW.LPF1_states_f =
    Master_control_fuzzy_standal_DW.LPF1_tmp_n;

  /* Update for DiscreteIntegrator: '<S8>/s.d' */
  Master_control_fuzzy_standal_DW.sd_DSTATE_f =
    Master_control_fuzzy_standalo_P.sd_gainval_h *
    Master_control_fuzzy_standalo_B.LPF1_g +
    Master_control_fuzzy_standalo_B.sd_k;

  /* Update for DiscreteTransferFcn: '<S23>/l2' */
  Master_control_fuzzy_standal_DW.l2_states =
    Master_control_fuzzy_standal_DW.l2_tmp;

  /* Update for UnitDelay: '<S240>/UD'
   *
   * Block description for '<S240>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_o =
    Master_control_fuzzy_standalo_B.TSamp_g;

  /* Update for DiscreteTransferFcn: '<S7>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_states_b =
    Master_control_fuzzy_standal_DW.HF2_tmp_o;

  /* Update for DiscreteTransferFcn: '<S7>/LPF2' */
  Master_control_fuzzy_standal_DW.LPF2_states_m =
    Master_control_fuzzy_standal_DW.LPF2_tmp_il;

  /* Update for DiscreteIntegrator: '<S7>/s.d1' */
  Master_control_fuzzy_standal_DW.sd1_DSTATE_k =
    Master_control_fuzzy_standalo_P.sd1_gainval_n *
    Master_control_fuzzy_standalo_B.LPF2_i +
    Master_control_fuzzy_standalo_B.sd1_p;

  /* Update for DiscreteTransferFcn: '<S9>/H.F4' */
  Master_control_fuzzy_standal_DW.HF4_states =
    Master_control_fuzzy_standal_DW.HF4_tmp;

  /* Update for DiscreteTransferFcn: '<S9>/LPF4' */
  Master_control_fuzzy_standal_DW.LPF4_states =
    Master_control_fuzzy_standal_DW.LPF4_tmp;

  /* Update for DiscreteIntegrator: '<S9>/HEAVE_VEL3' */
  Master_control_fuzzy_standal_DW.HEAVE_VEL3_DSTATE =
    Master_control_fuzzy_standalo_P.HEAVE_VEL3_gainval *
    Master_control_fuzzy_standalo_B.LPF4 +
    Master_control_fuzzy_standalo_B.HEAVE_VEL3;

  /* Update for DiscreteTransferFcn: '<S7>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_states_i =
    Master_control_fuzzy_standal_DW.HF1_tmp_k;

  /* Update for DiscreteTransferFcn: '<S7>/LPF1' */
  Master_control_fuzzy_standal_DW.LPF1_states_a =
    Master_control_fuzzy_standal_DW.LPF1_tmp_o;

  /* Update for DiscreteIntegrator: '<S7>/s.d' */
  Master_control_fuzzy_standal_DW.sd_DSTATE_h =
    Master_control_fuzzy_standalo_P.sd_gainval_i *
    Master_control_fuzzy_standalo_B.LPF1_k +
    Master_control_fuzzy_standalo_B.sd_a;

  /* Update for DiscreteTransferFcn: '<S21>/r2' */
  Master_control_fuzzy_standal_DW.r2_states =
    Master_control_fuzzy_standal_DW.r2_tmp;

  /* Update for UnitDelay: '<S238>/UD'
   *
   * Block description for '<S238>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_f =
    Master_control_fuzzy_standalo_B.TSamp_e;

  /* Update for DiscreteTransferFcn: '<S6>/H.F2' */
  Master_control_fuzzy_standal_DW.HF2_states_j =
    Master_control_fuzzy_standal_DW.HF2_tmp_g;

  /* Update for DiscreteTransferFcn: '<S6>/LPF2' */
  Master_control_fuzzy_standal_DW.LPF2_states_b =
    Master_control_fuzzy_standal_DW.LPF2_tmp_hp;

  /* Update for DiscreteIntegrator: '<S6>/s.d1' */
  Master_control_fuzzy_standal_DW.sd1_DSTATE_i =
    Master_control_fuzzy_standalo_P.sd1_gainval_l *
    Master_control_fuzzy_standalo_B.LPF2_a +
    Master_control_fuzzy_standalo_B.sd1_n;

  /* Update for DiscreteTransferFcn: '<S9>/H.F5' */
  Master_control_fuzzy_standal_DW.HF5_states =
    Master_control_fuzzy_standal_DW.HF5_tmp;

  /* Update for DiscreteTransferFcn: '<S9>/LPF5' */
  Master_control_fuzzy_standal_DW.LPF5_states =
    Master_control_fuzzy_standal_DW.LPF5_tmp;

  /* Update for DiscreteIntegrator: '<S9>/HEAVE_VEL4' */
  Master_control_fuzzy_standal_DW.HEAVE_VEL4_DSTATE =
    Master_control_fuzzy_standalo_P.HEAVE_VEL4_gainval *
    Master_control_fuzzy_standalo_B.LPF5 +
    Master_control_fuzzy_standalo_B.HEAVE_VEL4;

  /* Update for DiscreteTransferFcn: '<S6>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_states_g =
    Master_control_fuzzy_standal_DW.HF1_tmp_h;

  /* Update for DiscreteTransferFcn: '<S6>/LPF1' */
  Master_control_fuzzy_standal_DW.LPF1_states_g =
    Master_control_fuzzy_standal_DW.LPF1_tmp_h;

  /* Update for DiscreteIntegrator: '<S6>/s.d' */
  Master_control_fuzzy_standal_DW.sd_DSTATE_m =
    Master_control_fuzzy_standalo_P.sd_gainval_b *
    Master_control_fuzzy_standalo_B.LPF1_ki +
    Master_control_fuzzy_standalo_B.sd_j;

  /* Update for S-Function (imu_mpu_6050): '<S17>/mpu6050' */

  /* S-Function "imu_mpu_6050_wrapper" Block: <S17>/mpu6050 */
  imu_mpu_6050_Update_wrapper(&Master_control_fuzzy_standalo_B.mpu6050_o1,
    &Master_control_fuzzy_standalo_B.mpu6050_o2,
    &Master_control_fuzzy_standalo_B.mpu6050_o3,
    &Master_control_fuzzy_standalo_B.mpu6050_o4,
    &Master_control_fuzzy_standalo_B.mpu6050_o5,
    &Master_control_fuzzy_standalo_B.mpu6050_o6,
    &Master_control_fuzzy_standalo_B.mpu6050_o7,
    &Master_control_fuzzy_standal_DW.mpu6050_DSTATE);

  /* Update for DiscreteTransferFcn: '<S9>/H.F' */
  Master_control_fuzzy_standal_DW.HF_states =
    Master_control_fuzzy_standal_DW.HF_tmp;

  /* Update for DiscreteTransferFcn: '<S9>/LPF6' */
  Master_control_fuzzy_standal_DW.LPF6_states =
    Master_control_fuzzy_standal_DW.LPF6_tmp;

  /* Update for DiscreteIntegrator: '<S9>/HEAVE_VEL' */
  Master_control_fuzzy_standal_DW.HEAVE_VEL_DSTATE =
    Master_control_fuzzy_standalo_P.HEAVE_VEL_gainval *
    Master_control_fuzzy_standalo_B.LPF6 +
    Master_control_fuzzy_standalo_B.HEAVE_VEL;

  /* Update for DiscreteTransferFcn: '<S9>/H.F1' */
  Master_control_fuzzy_standal_DW.HF1_states_k =
    Master_control_fuzzy_standal_DW.HF1_tmp_a;

  /* Update for DiscreteTransferFcn: '<S9>/LPF1' */
  Master_control_fuzzy_standal_DW.LPF1_states_h =
    Master_control_fuzzy_standal_DW.LPF1_tmp_i;

  /* Update for DiscreteIntegrator: '<S9>/HEAVE_disp' */
  Master_control_fuzzy_standal_DW.HEAVE_disp_DSTATE =
    Master_control_fuzzy_standalo_P.HEAVE_disp_gainval *
    Master_control_fuzzy_standalo_B.LPF1_j +
    Master_control_fuzzy_standalo_B.HEAVE_disp;

  /* Update for Delay: '<S17>/Delay1' */
  Master_control_fuzzy_standal_DW.Delay1_DSTATE =
    Master_control_fuzzy_standalo_B.Add4;

  /* Update for UnitDelay: '<S49>/UD'
   *
   * Block description for '<S49>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_g =
    Master_control_fuzzy_standalo_B.TSamp_l;

  /* Update for Delay: '<S17>/Delay' */
  Master_control_fuzzy_standal_DW.Delay_DSTATE =
    Master_control_fuzzy_standalo_B.Add2;

  /* Update for UnitDelay: '<S48>/UD'
   *
   * Block description for '<S48>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_c =
    Master_control_fuzzy_standalo_B.TSamp_m;

  /* Update for UnitDelay: '<S53>/UD'
   *
   * Block description for '<S53>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_cy =
    Master_control_fuzzy_standalo_B.TSamp_j;

  /* Update for UnitDelay: '<S54>/UD'
   *
   * Block description for '<S54>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_e =
    Master_control_fuzzy_standalo_B.TSamp_ga;

  /* Update for UnitDelay: '<S55>/UD'
   *
   * Block description for '<S55>/UD':
   *
   *  Store in Global RAM
   */
  Master_control_fuzzy_standal_DW.UD_DSTATE_e2 =
    Master_control_fuzzy_standalo_B.TSamp_k;

  /* Update for DiscreteIntegrator: '<S133>/Integrator' */
  Master_control_fuzzy_standal_DW.Integrator_DSTATE +=
    Master_control_fuzzy_standalo_P.Integrator_gainval *
    Master_control_fuzzy_standalo_B.Switch_k;

  /* Update for DiscreteIntegrator: '<S128>/Filter' */
  Master_control_fuzzy_standal_DW.Filter_DSTATE +=
    Master_control_fuzzy_standalo_P.Filter_gainval *
    Master_control_fuzzy_standalo_B.FilterCoefficient;

  /* Update for S-Function (pin_5_PWM): '<Root>/PWM_F_R' */

  /* S-Function "pin_5_PWM_wrapper" Block: <Root>/PWM_F_R */
  pin_5_PWM_Update_wrapper(&Master_control_fuzzy_standalo_B.Saturation_m,
    &Master_control_fuzzy_standal_DW.PWM_F_R_DSTATE,
    &Master_control_fuzzy_standalo_P.PWM_F_R_P1, 1);

  /* Update for DiscreteIntegrator: '<S178>/Integrator' */
  Master_control_fuzzy_standal_DW.Integrator_DSTATE_e +=
    Master_control_fuzzy_standalo_P.Integrator_gainval_d *
    Master_control_fuzzy_standalo_B.Switch_g;

  /* Update for DiscreteIntegrator: '<S173>/Filter' */
  Master_control_fuzzy_standal_DW.Filter_DSTATE_o +=
    Master_control_fuzzy_standalo_P.Filter_gainval_l *
    Master_control_fuzzy_standalo_B.FilterCoefficient_b;

  /* Update for S-Function (pin_4_PWM): '<Root>/PWM_R_L' */

  /* S-Function "pin_4_PWM_wrapper" Block: <Root>/PWM_R_L */
  pin_4_PWM_Update_wrapper(&Master_control_fuzzy_standalo_B.Saturation_cm,
    &Master_control_fuzzy_standal_DW.PWM_R_L_DSTATE,
    &Master_control_fuzzy_standalo_P.PWM_R_L_P1, 1);

  /* Update for DiscreteIntegrator: '<S222>/Integrator' */
  Master_control_fuzzy_standal_DW.Integrator_DSTATE_b +=
    Master_control_fuzzy_standalo_P.Integrator_gainval_i *
    Master_control_fuzzy_standalo_B.Switch_e;

  /* Update for DiscreteIntegrator: '<S217>/Filter' */
  Master_control_fuzzy_standal_DW.Filter_DSTATE_i +=
    Master_control_fuzzy_standalo_P.Filter_gainval_la *
    Master_control_fuzzy_standalo_B.FilterCoefficient_l;

  /* Update for S-Function (pin_3_PWM): '<Root>/PWM_R_R' */

  /* S-Function "pin_3_PWM_wrapper" Block: <Root>/PWM_R_R */
  pin_3_PWM_Update_wrapper(&Master_control_fuzzy_standalo_B.Saturation_c1,
    &Master_control_fuzzy_standal_DW.PWM_R_R_DSTATE,
    &Master_control_fuzzy_standalo_P.PWM_R_R_P1, 1);

  /* Update for DiscreteIntegrator: '<S89>/Integrator' */
  Master_control_fuzzy_standal_DW.Integrator_DSTATE_g +=
    Master_control_fuzzy_standalo_P.Integrator_gainval_l *
    Master_control_fuzzy_standalo_B.Switch;

  /* Update for DiscreteIntegrator: '<S84>/Filter' */
  Master_control_fuzzy_standal_DW.Filter_DSTATE_n +=
    Master_control_fuzzy_standalo_P.Filter_gainval_f *
    Master_control_fuzzy_standalo_B.FilterCoefficient_br;

  /* Update for S-Function (pin_6_PWM): '<Root>/pwm_fL' */

  /* S-Function "pin_6_PWM_wrapper" Block: <Root>/pwm_fL */
  pin_6_PWM_Update_wrapper(&Master_control_fuzzy_standalo_B.Saturation_e,
    &Master_control_fuzzy_standal_DW.pwm_fL_DSTATE,
    &Master_control_fuzzy_standalo_P.pwm_fL_P1, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)Master_control_fuzzy_standal_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, (real_T)
                    ((Master_control_fuzzy_standal_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Master_control_fuzzy_standal_M)!=-1) &&
        !((rtmGetTFinal(Master_control_fuzzy_standal_M)-
           Master_control_fuzzy_standal_M->Timing.t[0]) >
          Master_control_fuzzy_standal_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Master_control_fuzzy_standal_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Master_control_fuzzy_standal_M)) {
      rtmSetErrorStatus(Master_control_fuzzy_standal_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Master_control_fuzzy_standal_M->Timing.t[0] =
    (++Master_control_fuzzy_standal_M->Timing.clockTick0) *
    Master_control_fuzzy_standal_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Master_control_fuzzy_standal_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Master_control_fuzzy_standalone_new_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Master_control_fuzzy_standal_M, 0,
                sizeof(RT_MODEL_Master_control_fuzzy_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Master_control_fuzzy_standal_M->solverInfo,
                          &Master_control_fuzzy_standal_M->Timing.simTimeStep);
    rtsiSetTPtr(&Master_control_fuzzy_standal_M->solverInfo, &rtmGetTPtr
                (Master_control_fuzzy_standal_M));
    rtsiSetStepSizePtr(&Master_control_fuzzy_standal_M->solverInfo,
                       &Master_control_fuzzy_standal_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Master_control_fuzzy_standal_M->solverInfo,
                          (&rtmGetErrorStatus(Master_control_fuzzy_standal_M)));
    rtsiSetRTModelPtr(&Master_control_fuzzy_standal_M->solverInfo,
                      Master_control_fuzzy_standal_M);
  }

  rtsiSetSimTimeStep(&Master_control_fuzzy_standal_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Master_control_fuzzy_standal_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Master_control_fuzzy_standal_M,
             &Master_control_fuzzy_standal_M->Timing.tArray[0]);
  rtmSetTFinal(Master_control_fuzzy_standal_M, -1);
  Master_control_fuzzy_standal_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Master_control_fuzzy_standal_M->Sizes.checksums[0] = (1660447902U);
  Master_control_fuzzy_standal_M->Sizes.checksums[1] = (2943983298U);
  Master_control_fuzzy_standal_M->Sizes.checksums[2] = (1195869684U);
  Master_control_fuzzy_standal_M->Sizes.checksums[3] = (327002243U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[47];
    Master_control_fuzzy_standal_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRan_fz;
    systemRan[3] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_b.IfActionSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_b;
    systemRan[5] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_j;
    systemRan[7] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_ej.IfActionSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_f;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_f.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_n;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_n.IfActionSubsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_g;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_c;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &Master_control_fuzzy_standal_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Master_control_fuzzy_standal_M->extModeInfo,
      &Master_control_fuzzy_standal_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Master_control_fuzzy_standal_M->extModeInfo,
                        Master_control_fuzzy_standal_M->Sizes.checksums);
    rteiSetTPtr(Master_control_fuzzy_standal_M->extModeInfo, rtmGetTPtr
                (Master_control_fuzzy_standal_M));
  }

  /* block I/O */
  (void) memset(((void *) &Master_control_fuzzy_standalo_B), 0,
                sizeof(B_Master_control_fuzzy_standa_T));

  /* states (dwork) */
  (void) memset((void *)&Master_control_fuzzy_standal_DW, 0,
                sizeof(DW_Master_control_fuzzy_stand_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Master_control_fuzzy_standal_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_inter_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;

    /* Start for MATLABSystem: '<S22>/Analog Input3' */
    Master_control_fuzzy_standal_DW.obj_k.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_k.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_k.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_k.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_l = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_k,
      &Master_control_fuzzy_standal_DW.gobj_0_h);
    Master_control_fuzzy_standal_DW.obj_k.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_mh;
    obj = &Master_control_fuzzy_standal_DW.obj_k;
    Master_control_fuzzy_standal_DW.obj_k.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_k.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(6U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_k.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    Master_control_fuzzy_standal_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Analog Input2' */
    Master_control_fuzzy_standal_DW.obj_ku2.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_ku2.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_ku2.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_ku2.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_m = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_ku2,
      &Master_control_fuzzy_standal_DW.gobj_0_k);
    Master_control_fuzzy_standal_DW.obj_ku2.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput2_SampleTime;
    obj = &Master_control_fuzzy_standal_DW.obj_ku2;
    Master_control_fuzzy_standal_DW.obj_ku2.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_ku2.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(0U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_ku2.MW_ANALOGIN_HANDLE, trigger_val,
       0U);
    Master_control_fuzzy_standal_DW.obj_ku2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Analog Input1' */
    Master_control_fuzzy_standal_DW.obj_er.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_er.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_er.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_er.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_g = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_er,
      &Master_control_fuzzy_standal_DW.gobj_0_m);
    Master_control_fuzzy_standal_DW.obj_er.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime;
    obj = &Master_control_fuzzy_standal_DW.obj_er;
    Master_control_fuzzy_standal_DW.obj_er.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_er.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(1U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_er.MW_ANALOGIN_HANDLE, trigger_val,
       0U);
    Master_control_fuzzy_standal_DW.obj_er.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Analog Input3' */
    Master_control_fuzzy_standal_DW.obj_kt.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_kt.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_kt.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_kt.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_h = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_kt,
      &Master_control_fuzzy_standal_DW.gobj_0_ng);
    Master_control_fuzzy_standal_DW.obj_kt.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime;
    obj = &Master_control_fuzzy_standal_DW.obj_kt;
    Master_control_fuzzy_standal_DW.obj_kt.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_kt.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(2U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_kt.MW_ANALOGIN_HANDLE, trigger_val,
       0U);
    Master_control_fuzzy_standal_DW.obj_kt.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Analog Input4' */
    Master_control_fuzzy_standal_DW.obj_io.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_io.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_io.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_io.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_a = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_io,
      &Master_control_fuzzy_standal_DW.gobj_0_i);
    Master_control_fuzzy_standal_DW.obj_io.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput4_SampleTime;
    obj = &Master_control_fuzzy_standal_DW.obj_io;
    Master_control_fuzzy_standal_DW.obj_io.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_io.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(11U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_io.MW_ANALOGIN_HANDLE, trigger_val,
       0U);
    Master_control_fuzzy_standal_DW.obj_io.isSetupComplete = true;

    /* Start for If: '<S50>/If loop ' */
    Master_control_fuzzy_standal_DW.Ifloop_ActiveSubsystem = -1;

    /* Start for IfAction SubSystem: '<S50>/If Action Subsystem' */
    Master_control_MovingRMS3_Start(&Master_control_fuzzy_standal_DW.MovingRMS,
      &Master_control_fuzzy_standalo_P.MovingRMS);
    Master_control_MovingRMS3_Start(&Master_control_fuzzy_standal_DW.MovingRMS1,
      &Master_control_fuzzy_standalo_P.MovingRMS1);
    Master_control_MovingRMS3_Start(&Master_control_fuzzy_standal_DW.MovingRMS2,
      &Master_control_fuzzy_standalo_P.MovingRMS2);

    /* Start for MATLABSystem: '<S51>/Moving RMS3' */
    Master_control_MovingRMS3_Start(&Master_control_fuzzy_standal_DW.MovingRMS3,
      &Master_control_fuzzy_standalo_P.MovingRMS3);

    /* End of Start for SubSystem: '<S50>/If Action Subsystem' */

    /* Start for MATLABSystem: '<S20>/Analog Input3' */
    Master_control_fuzzy_standal_DW.obj_p.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_p.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_p.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_p.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_f = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_p,
      &Master_control_fuzzy_standal_DW.gobj_0_c);
    Master_control_fuzzy_standal_DW.obj_p.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_c;
    obj = &Master_control_fuzzy_standal_DW.obj_p;
    Master_control_fuzzy_standal_DW.obj_p.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_p.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(5U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_p.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    Master_control_fuzzy_standal_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S23>/Analog Input3' */
    Master_control_fuzzy_standal_DW.obj.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj,
      &Master_control_fuzzy_standal_DW.gobj_0);
    Master_control_fuzzy_standal_DW.obj.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_d;
    obj = &Master_control_fuzzy_standal_DW.obj;
    Master_control_fuzzy_standal_DW.obj.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(4U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    Master_control_fuzzy_standal_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S21>/Analog Input3' */
    Master_control_fuzzy_standal_DW.obj_e.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_e.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_e.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_e.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_o = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_e,
      &Master_control_fuzzy_standal_DW.gobj_0_n);
    Master_control_fuzzy_standal_DW.obj_e.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput3_SampleTime_m;
    obj = &Master_control_fuzzy_standal_DW.obj_e;
    Master_control_fuzzy_standal_DW.obj_e.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_e.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(3U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_e.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    Master_control_fuzzy_standal_DW.obj_e.isSetupComplete = true;

    /* Start for Atomic SubSystem: '<Root>/feedback2' */
    /* Start for MATLABSystem: '<S13>/Analog Input1' */
    Master_control_fuzzy_standal_DW.obj_n.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_n.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_n.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_n.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_b = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_n,
      &Master_control_fuzzy_standal_DW.gobj_0_h2);
    Master_control_fuzzy_standal_DW.obj_n.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_h;
    obj = &Master_control_fuzzy_standal_DW.obj_n;
    Master_control_fuzzy_standal_DW.obj_n.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_n.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(9U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_n.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    Master_control_fuzzy_standal_DW.obj_n.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/feedback2' */

    /* Start for Atomic SubSystem: '<Root>/feedback1' */
    /* Start for MATLABSystem: '<S12>/Analog Input1' */
    Master_control_fuzzy_standal_DW.obj_ku.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_ku.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_ku.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_ku.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_bk = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_ku,
      &Master_control_fuzzy_standal_DW.gobj_0_j);
    Master_control_fuzzy_standal_DW.obj_ku.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_n;
    obj = &Master_control_fuzzy_standal_DW.obj_ku;
    Master_control_fuzzy_standal_DW.obj_ku.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_ku.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(8U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_ku.MW_ANALOGIN_HANDLE, trigger_val,
       0U);
    Master_control_fuzzy_standal_DW.obj_ku.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/feedback1' */

    /* Start for Atomic SubSystem: '<Root>/feedback3' */
    /* Start for MATLABSystem: '<S14>/Analog Input1' */
    Master_control_fuzzy_standal_DW.obj_a.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_a.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_a.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_a.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_c = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_a,
      &Master_control_fuzzy_standal_DW.gobj_0_o);
    Master_control_fuzzy_standal_DW.obj_a.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_i;
    obj = &Master_control_fuzzy_standal_DW.obj_a;
    Master_control_fuzzy_standal_DW.obj_a.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_a.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(7U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_a.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    Master_control_fuzzy_standal_DW.obj_a.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/feedback3' */

    /* Start for Atomic SubSystem: '<Root>/feedback' */
    /* Start for MATLABSystem: '<S11>/Analog Input1' */
    Master_control_fuzzy_standal_DW.obj_i.matlabCodegenIsDeleted = true;
    Master_control_fuzzy_standal_DW.obj_i.isInitialized = 0;
    Master_control_fuzzy_standal_DW.obj_i.SampleTime = -1.0;
    Master_control_fuzzy_standal_DW.obj_i.matlabCodegenIsDeleted = false;
    Master_control_fuzzy_standal_DW.objisempty_i = true;
    arduino_AnalogInput_set_pinNumb(&Master_control_fuzzy_standal_DW.obj_i,
      &Master_control_fuzzy_standal_DW.gobj_0_oz);
    Master_control_fuzzy_standal_DW.obj_i.SampleTime =
      Master_control_fuzzy_standalo_P.AnalogInput1_SampleTime_k;
    obj = &Master_control_fuzzy_standal_DW.obj_i;
    Master_control_fuzzy_standal_DW.obj_i.isSetupComplete = false;
    Master_control_fuzzy_standal_DW.obj_i.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(10U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (Master_control_fuzzy_standal_DW.obj_i.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    Master_control_fuzzy_standal_DW.obj_i.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/feedback' */

    /* InitializeConditions for DiscreteTransferFcn: '<S22>/LPFl1' */
    Master_control_fuzzy_standal_DW.LPFl1_states =
      Master_control_fuzzy_standalo_P.LPFl1_InitialStates;

    /* InitializeConditions for UnitDelay: '<S239>/UD'
     *
     * Block description for '<S239>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE =
      Master_control_fuzzy_standalo_P.DiscreteDerivative1_ICPrevScale;

    /* InitializeConditions for DiscreteTransferFcn: '<S5>/H.F2' */
    Master_control_fuzzy_standal_DW.HF2_states =
      Master_control_fuzzy_standalo_P.HF2_InitialStates;

    /* InitializeConditions for DiscreteTransferFcn: '<S5>/LPF2' */
    Master_control_fuzzy_standal_DW.LPF2_states =
      Master_control_fuzzy_standalo_P.LPF2_InitialStates;

    /* InitializeConditions for DiscreteIntegrator: '<S5>/s.d1' */
    Master_control_fuzzy_standal_DW.sd1_DSTATE =
      Master_control_fuzzy_standalo_P.sd1_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/H.F2' */
    Master_control_fuzzy_standal_DW.HF2_states_a =
      Master_control_fuzzy_standalo_P.HF2_InitialStates_c;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/LPF2' */
    Master_control_fuzzy_standal_DW.LPF2_states_e =
      Master_control_fuzzy_standalo_P.LPF2_InitialStates_b;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/HEAVE_VEL1' */
    Master_control_fuzzy_standal_DW.HEAVE_VEL1_DSTATE =
      Master_control_fuzzy_standalo_P.HEAVE_VEL1_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S5>/H.F1' */
    Master_control_fuzzy_standal_DW.HF1_states =
      Master_control_fuzzy_standalo_P.HF1_InitialStates;

    /* InitializeConditions for DiscreteTransferFcn: '<S5>/LPF1' */
    Master_control_fuzzy_standal_DW.LPF1_states =
      Master_control_fuzzy_standalo_P.LPF1_InitialStates;

    /* InitializeConditions for DiscreteIntegrator: '<S5>/s.d' */
    Master_control_fuzzy_standal_DW.sd_DSTATE =
      Master_control_fuzzy_standalo_P.sd_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S20>/LPFr1' */
    Master_control_fuzzy_standal_DW.LPFr1_states =
      Master_control_fuzzy_standalo_P.LPFr1_InitialStates;

    /* InitializeConditions for UnitDelay: '<S237>/UD'
     *
     * Block description for '<S237>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_h =
      Master_control_fuzzy_standalo_P.DiscreteDerivative1_ICPrevSca_m;

    /* InitializeConditions for DiscreteTransferFcn: '<S8>/H.F2' */
    Master_control_fuzzy_standal_DW.HF2_states_m =
      Master_control_fuzzy_standalo_P.HF2_InitialStates_p;

    /* InitializeConditions for DiscreteTransferFcn: '<S8>/LPF2' */
    Master_control_fuzzy_standal_DW.LPF2_states_j =
      Master_control_fuzzy_standalo_P.LPF2_InitialStates_k;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/s.d1' */
    Master_control_fuzzy_standal_DW.sd1_DSTATE_c =
      Master_control_fuzzy_standalo_P.sd1_IC_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/H.F3' */
    Master_control_fuzzy_standal_DW.HF3_states =
      Master_control_fuzzy_standalo_P.HF3_InitialStates;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/LPF3' */
    Master_control_fuzzy_standal_DW.LPF3_states =
      Master_control_fuzzy_standalo_P.LPF3_InitialStates;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/HEAVE_VEL2' */
    Master_control_fuzzy_standal_DW.HEAVE_VEL2_DSTATE =
      Master_control_fuzzy_standalo_P.HEAVE_VEL2_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S8>/H.F1' */
    Master_control_fuzzy_standal_DW.HF1_states_e =
      Master_control_fuzzy_standalo_P.HF1_InitialStates_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S8>/LPF1' */
    Master_control_fuzzy_standal_DW.LPF1_states_f =
      Master_control_fuzzy_standalo_P.LPF1_InitialStates_e;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/s.d' */
    Master_control_fuzzy_standal_DW.sd_DSTATE_f =
      Master_control_fuzzy_standalo_P.sd_IC_b;

    /* InitializeConditions for DiscreteTransferFcn: '<S23>/l2' */
    Master_control_fuzzy_standal_DW.l2_states =
      Master_control_fuzzy_standalo_P.l2_InitialStates;

    /* InitializeConditions for UnitDelay: '<S240>/UD'
     *
     * Block description for '<S240>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_o =
      Master_control_fuzzy_standalo_P.DiscreteDerivative1_ICPrevSca_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S7>/H.F2' */
    Master_control_fuzzy_standal_DW.HF2_states_b =
      Master_control_fuzzy_standalo_P.HF2_InitialStates_b;

    /* InitializeConditions for DiscreteTransferFcn: '<S7>/LPF2' */
    Master_control_fuzzy_standal_DW.LPF2_states_m =
      Master_control_fuzzy_standalo_P.LPF2_InitialStates_ks;

    /* InitializeConditions for DiscreteIntegrator: '<S7>/s.d1' */
    Master_control_fuzzy_standal_DW.sd1_DSTATE_k =
      Master_control_fuzzy_standalo_P.sd1_IC_e;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/H.F4' */
    Master_control_fuzzy_standal_DW.HF4_states =
      Master_control_fuzzy_standalo_P.HF4_InitialStates;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/LPF4' */
    Master_control_fuzzy_standal_DW.LPF4_states =
      Master_control_fuzzy_standalo_P.LPF4_InitialStates;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/HEAVE_VEL3' */
    Master_control_fuzzy_standal_DW.HEAVE_VEL3_DSTATE =
      Master_control_fuzzy_standalo_P.HEAVE_VEL3_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S7>/H.F1' */
    Master_control_fuzzy_standal_DW.HF1_states_i =
      Master_control_fuzzy_standalo_P.HF1_InitialStates_j0;

    /* InitializeConditions for DiscreteTransferFcn: '<S7>/LPF1' */
    Master_control_fuzzy_standal_DW.LPF1_states_a =
      Master_control_fuzzy_standalo_P.LPF1_InitialStates_a;

    /* InitializeConditions for DiscreteIntegrator: '<S7>/s.d' */
    Master_control_fuzzy_standal_DW.sd_DSTATE_h =
      Master_control_fuzzy_standalo_P.sd_IC_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S21>/r2' */
    Master_control_fuzzy_standal_DW.r2_states =
      Master_control_fuzzy_standalo_P.r2_InitialStates;

    /* InitializeConditions for UnitDelay: '<S238>/UD'
     *
     * Block description for '<S238>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_f =
      Master_control_fuzzy_standalo_P.DiscreteDerivative1_ICPrevSca_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S6>/H.F2' */
    Master_control_fuzzy_standal_DW.HF2_states_j =
      Master_control_fuzzy_standalo_P.HF2_InitialStates_m;

    /* InitializeConditions for DiscreteTransferFcn: '<S6>/LPF2' */
    Master_control_fuzzy_standal_DW.LPF2_states_b =
      Master_control_fuzzy_standalo_P.LPF2_InitialStates_f;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/s.d1' */
    Master_control_fuzzy_standal_DW.sd1_DSTATE_i =
      Master_control_fuzzy_standalo_P.sd1_IC_l;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/H.F5' */
    Master_control_fuzzy_standal_DW.HF5_states =
      Master_control_fuzzy_standalo_P.HF5_InitialStates;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/LPF5' */
    Master_control_fuzzy_standal_DW.LPF5_states =
      Master_control_fuzzy_standalo_P.LPF5_InitialStates;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/HEAVE_VEL4' */
    Master_control_fuzzy_standal_DW.HEAVE_VEL4_DSTATE =
      Master_control_fuzzy_standalo_P.HEAVE_VEL4_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S6>/H.F1' */
    Master_control_fuzzy_standal_DW.HF1_states_g =
      Master_control_fuzzy_standalo_P.HF1_InitialStates_l;

    /* InitializeConditions for DiscreteTransferFcn: '<S6>/LPF1' */
    Master_control_fuzzy_standal_DW.LPF1_states_g =
      Master_control_fuzzy_standalo_P.LPF1_InitialStates_c;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/s.d' */
    Master_control_fuzzy_standal_DW.sd_DSTATE_m =
      Master_control_fuzzy_standalo_P.sd_IC_o;

    /* InitializeConditions for S-Function (imu_mpu_6050): '<S17>/mpu6050' */

    /* S-Function Block: <S17>/mpu6050 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Master_control_fuzzy_standal_DW.mpu6050_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/H.F' */
    Master_control_fuzzy_standal_DW.HF_states =
      Master_control_fuzzy_standalo_P.HF_InitialStates;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/LPF6' */
    Master_control_fuzzy_standal_DW.LPF6_states =
      Master_control_fuzzy_standalo_P.LPF6_InitialStates;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/HEAVE_VEL' */
    Master_control_fuzzy_standal_DW.HEAVE_VEL_DSTATE =
      Master_control_fuzzy_standalo_P.HEAVE_VEL_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/H.F1' */
    Master_control_fuzzy_standal_DW.HF1_states_k =
      Master_control_fuzzy_standalo_P.HF1_InitialStates_n;

    /* InitializeConditions for DiscreteTransferFcn: '<S9>/LPF1' */
    Master_control_fuzzy_standal_DW.LPF1_states_h =
      Master_control_fuzzy_standalo_P.LPF1_InitialStates_p;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/HEAVE_disp' */
    Master_control_fuzzy_standal_DW.HEAVE_disp_DSTATE =
      Master_control_fuzzy_standalo_P.HEAVE_disp_IC;

    /* InitializeConditions for Delay: '<S17>/Delay1' */
    Master_control_fuzzy_standal_DW.Delay1_DSTATE =
      Master_control_fuzzy_standalo_P.Delay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S49>/UD'
     *
     * Block description for '<S49>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_g =
      Master_control_fuzzy_standalo_P.DiscreteDerivative5_ICPrevScale;

    /* InitializeConditions for Delay: '<S17>/Delay' */
    Master_control_fuzzy_standal_DW.Delay_DSTATE =
      Master_control_fuzzy_standalo_P.Delay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S48>/UD'
     *
     * Block description for '<S48>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_c =
      Master_control_fuzzy_standalo_P.DiscreteDerivative4_ICPrevScale;

    /* InitializeConditions for UnitDelay: '<S53>/UD'
     *
     * Block description for '<S53>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_cy =
      Master_control_fuzzy_standalo_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for UnitDelay: '<S54>/UD'
     *
     * Block description for '<S54>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_e =
      Master_control_fuzzy_standalo_P.DiscreteDerivative1_ICPrevSc_mb;

    /* InitializeConditions for UnitDelay: '<S55>/UD'
     *
     * Block description for '<S55>/UD':
     *
     *  Store in Global RAM
     */
    Master_control_fuzzy_standal_DW.UD_DSTATE_e2 =
      Master_control_fuzzy_standalo_P.DiscreteDerivative2_ICPrevScale;

    /* InitializeConditions for DiscreteIntegrator: '<S133>/Integrator' */
    Master_control_fuzzy_standal_DW.Integrator_DSTATE =
      Master_control_fuzzy_standalo_P.frontright_InitialConditionForI;

    /* InitializeConditions for DiscreteIntegrator: '<S128>/Filter' */
    Master_control_fuzzy_standal_DW.Filter_DSTATE =
      Master_control_fuzzy_standalo_P.frontright_InitialConditionForF;

    /* InitializeConditions for S-Function (pin_5_PWM): '<Root>/PWM_F_R' */

    /* S-Function Block: <Root>/PWM_F_R */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Master_control_fuzzy_standal_DW.PWM_F_R_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S178>/Integrator' */
    Master_control_fuzzy_standal_DW.Integrator_DSTATE_e =
      Master_control_fuzzy_standalo_P.rearleft_InitialConditionForInt;

    /* InitializeConditions for DiscreteIntegrator: '<S173>/Filter' */
    Master_control_fuzzy_standal_DW.Filter_DSTATE_o =
      Master_control_fuzzy_standalo_P.rearleft_InitialConditionForFil;

    /* InitializeConditions for S-Function (pin_4_PWM): '<Root>/PWM_R_L' */

    /* S-Function Block: <Root>/PWM_R_L */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Master_control_fuzzy_standal_DW.PWM_R_L_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S222>/Integrator' */
    Master_control_fuzzy_standal_DW.Integrator_DSTATE_b =
      Master_control_fuzzy_standalo_P.rearright_InitialConditionForIn;

    /* InitializeConditions for DiscreteIntegrator: '<S217>/Filter' */
    Master_control_fuzzy_standal_DW.Filter_DSTATE_i =
      Master_control_fuzzy_standalo_P.rearright_InitialConditionForFi;

    /* InitializeConditions for S-Function (pin_3_PWM): '<Root>/PWM_R_R' */

    /* S-Function Block: <Root>/PWM_R_R */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Master_control_fuzzy_standal_DW.PWM_R_R_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator' */
    Master_control_fuzzy_standal_DW.Integrator_DSTATE_g =
      Master_control_fuzzy_standalo_P.frontleft_InitialConditionForIn;

    /* InitializeConditions for DiscreteIntegrator: '<S84>/Filter' */
    Master_control_fuzzy_standal_DW.Filter_DSTATE_n =
      Master_control_fuzzy_standalo_P.frontleft_InitialConditionForFi;

    /* InitializeConditions for S-Function (pin_6_PWM): '<Root>/pwm_fL' */

    /* S-Function Block: <Root>/pwm_fL */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Master_control_fuzzy_standal_DW.pwm_fL_DSTATE = initVector[0];
        }
      }
    }

    /* SystemInitialize for IfAction SubSystem: '<S50>/If Action Subsystem' */
    Master_control__MovingRMS3_Init(&Master_control_fuzzy_standal_DW.MovingRMS);
    Master_control__MovingRMS3_Init(&Master_control_fuzzy_standal_DW.MovingRMS1);
    Master_control__MovingRMS3_Init(&Master_control_fuzzy_standal_DW.MovingRMS2);

    /* SystemInitialize for MATLABSystem: '<S51>/Moving RMS3' */
    Master_control__MovingRMS3_Init(&Master_control_fuzzy_standal_DW.MovingRMS3);

    /* SystemInitialize for Outport: '<S51>/acc_s_rms FL' */
    Master_control_fuzzy_standalo_B.MovingRMS.MovingRMS3 =
      Master_control_fuzzy_standalo_P.acc_s_rmsFL_Y0;

    /* SystemInitialize for Outport: '<S51>/acc_s_rmsFR' */
    Master_control_fuzzy_standalo_B.MovingRMS1.MovingRMS3 =
      Master_control_fuzzy_standalo_P.acc_s_rmsFR_Y0;

    /* SystemInitialize for Outport: '<S51>/acc_s_rms RL' */
    Master_control_fuzzy_standalo_B.MovingRMS2.MovingRMS3 =
      Master_control_fuzzy_standalo_P.acc_s_rmsRL_Y0;

    /* SystemInitialize for Outport: '<S51>/acc_s_rms RR' */
    Master_control_fuzzy_standalo_B.MovingRMS3.MovingRMS3 =
      Master_control_fuzzy_standalo_P.acc_s_rmsRR_Y0;

    /* End of SystemInitialize for SubSystem: '<S50>/If Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<S50>/If Action Subsystem1' */
    /* SystemInitialize for Outport: '<S52>/Calib_acc_FL' */
    Master_control_fuzzy_standalo_B.Add2_b =
      Master_control_fuzzy_standalo_P.Calib_acc_FL_Y0;

    /* SystemInitialize for Outport: '<S52>/Calib_acc_FR' */
    Master_control_fuzzy_standalo_B.Add1_n =
      Master_control_fuzzy_standalo_P.Calib_acc_FR_Y0;

    /* SystemInitialize for Outport: '<S52>/Calib_acc_RL' */
    Master_control_fuzzy_standalo_B.Add3 =
      Master_control_fuzzy_standalo_P.Calib_acc_RL_Y0;

    /* SystemInitialize for Outport: '<S52>/Calib_acc_RR' */
    Master_control_fuzzy_standalo_B.Add4_n =
      Master_control_fuzzy_standalo_P.Calib_acc_RR_Y0;

    /* End of SystemInitialize for SubSystem: '<S50>/If Action Subsystem1' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/feedback2' */
    /* InitializeConditions for DiscreteTransferFcn: '<S13>/LPF' */
    Master_control_fuzzy_standal_DW.LPF_states_f =
      Master_control_fuzzy_standalo_P.LPF_InitialStates_c;

    /* End of SystemInitialize for SubSystem: '<Root>/feedback2' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/feedback1' */
    /* InitializeConditions for DiscreteTransferFcn: '<S12>/LPF' */
    Master_control_fuzzy_standal_DW.LPF_states_g =
      Master_control_fuzzy_standalo_P.LPF_InitialStates_g;

    /* End of SystemInitialize for SubSystem: '<Root>/feedback1' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/feedback3' */
    /* InitializeConditions for DiscreteTransferFcn: '<S14>/LPF' */
    Master_control_fuzzy_standal_DW.LPF_states =
      Master_control_fuzzy_standalo_P.LPF_InitialStates_h;

    /* End of SystemInitialize for SubSystem: '<Root>/feedback3' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/feedback' */
    /* InitializeConditions for DiscreteTransferFcn: '<S11>/LPF' */
    Master_control_fuzzy_standal_DW.LPF_states_o =
      Master_control_fuzzy_standalo_P.LPF_InitialStates;

    /* End of SystemInitialize for SubSystem: '<Root>/feedback' */
  }
}

/* Model terminate function */
void Master_control_fuzzy_standalone_new_terminate(void)
{
  /* Terminate for MATLABSystem: '<S22>/Analog Input3' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_k);

  /* Terminate for MATLABSystem: '<S9>/Analog Input2' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_ku2);

  /* Terminate for MATLABSystem: '<S9>/Analog Input1' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_er);

  /* Terminate for MATLABSystem: '<S9>/Analog Input3' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_kt);

  /* Terminate for MATLABSystem: '<S9>/Analog Input4' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_io);

  /* Terminate for IfAction SubSystem: '<S50>/If Action Subsystem' */
  Master_control__MovingRMS3_Term(&Master_control_fuzzy_standal_DW.MovingRMS);
  Master_control__MovingRMS3_Term(&Master_control_fuzzy_standal_DW.MovingRMS1);
  Master_control__MovingRMS3_Term(&Master_control_fuzzy_standal_DW.MovingRMS2);

  /* Terminate for MATLABSystem: '<S51>/Moving RMS3' */
  Master_control__MovingRMS3_Term(&Master_control_fuzzy_standal_DW.MovingRMS3);

  /* End of Terminate for SubSystem: '<S50>/If Action Subsystem' */

  /* Terminate for MATLABSystem: '<S20>/Analog Input3' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_p);

  /* Terminate for MATLABSystem: '<S23>/Analog Input3' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj);

  /* Terminate for MATLABSystem: '<S21>/Analog Input3' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_e);

  /* Terminate for Atomic SubSystem: '<Root>/feedback2' */
  /* Terminate for MATLABSystem: '<S13>/Analog Input1' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_n);

  /* End of Terminate for SubSystem: '<Root>/feedback2' */

  /* Terminate for Atomic SubSystem: '<Root>/feedback1' */
  /* Terminate for MATLABSystem: '<S12>/Analog Input1' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_ku);

  /* End of Terminate for SubSystem: '<Root>/feedback1' */

  /* Terminate for Atomic SubSystem: '<Root>/feedback3' */
  /* Terminate for MATLABSystem: '<S14>/Analog Input1' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_a);

  /* End of Terminate for SubSystem: '<Root>/feedback3' */

  /* Terminate for Atomic SubSystem: '<Root>/feedback' */
  /* Terminate for MATLABSystem: '<S11>/Analog Input1' */
  matlabCodegenHandle_matlabCod_j(&Master_control_fuzzy_standal_DW.obj_i);

  /* End of Terminate for SubSystem: '<Root>/feedback' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
