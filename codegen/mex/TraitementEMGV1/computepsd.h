/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computepsd.h
 *
 * Code generation for function 'computepsd'
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
void computepsd(const emlrtStack *sp, const emxArray_real_T *Sxx1, const
                emxArray_real_T *w2, const char_T range[8], emxArray_real_T
                *varargout_1, emxArray_real_T *varargout_2, char_T
                varargout_3_data[], int32_T varargout_3_size[2]);

/* End of code generation (computepsd.h) */
