/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TraitementEMGV1_emxutil.h
 *
 * Code generation for function 'TraitementEMGV1_emxutil'
 *
 */

#pragma once

/* Include files */
#include "TraitementEMGV1_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_uint16_T(const emlrtStack *sp, emxArray_uint16_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxFree_creal_T(emxArray_creal_T **pEmxArray);
void emxFree_int32_T(emxArray_int32_T **pEmxArray);
void emxFree_real_T(emxArray_real_T **pEmxArray);
void emxFree_uint16_T(emxArray_uint16_T **pEmxArray);
void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush);
void emxInit_uint16_T(const emlrtStack *sp, emxArray_uint16_T **pEmxArray,
                      int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                      boolean_T doPush);

/* End of code generation (TraitementEMGV1_emxutil.h) */
