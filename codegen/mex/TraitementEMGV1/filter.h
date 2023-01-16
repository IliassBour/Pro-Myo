/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_filter(const emlrtStack *sp, real_T b_data[], real_T a_data[], const
              real_T x[60501], const real_T zi_data[], real_T y[60501], real_T
              zf_data[], int32_T zf_size[1]);
void filter(const emlrtStack *sp, real_T b_data[], real_T a_data[], const real_T
            x[12], const real_T zi_data[], real_T y[12], real_T zf_data[],
            int32_T zf_size[1]);

/* End of code generation (filter.h) */
