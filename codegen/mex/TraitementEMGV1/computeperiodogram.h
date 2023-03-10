/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeperiodogram.h
 *
 * Code generation for function 'computeperiodogram'
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
void computeperiodogram(const emlrtStack *sp, const emxArray_real_T *x, real_T
  Fs, emxArray_real_T *Pxx, emxArray_real_T *F);

/* End of code generation (computeperiodogram.h) */
