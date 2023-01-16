/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welch.h
 *
 * Code generation for function 'welch'
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
void localComputeSpectra(const emlrtStack *sp, const real_T x[60501], const
  char_T options_range[8], emxArray_real_T *Pxx, emxArray_real_T *w, char_T
  units_data[], int32_T units_size[2]);

/* End of code generation (welch.h) */
