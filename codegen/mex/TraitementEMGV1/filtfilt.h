/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filtfilt.h
 *
 * Code generation for function 'filtfilt'
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
void filtfilt(TraitementEMGV1StackData *SD, const emlrtStack *sp, const real_T
              b[5], const real_T a[5], const real_T x[60501], real_T y[60501]);

/* End of code generation (filtfilt.h) */
