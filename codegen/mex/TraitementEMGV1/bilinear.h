/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bilinear.h
 *
 * Code generation for function 'bilinear'
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
void bilinear(const emlrtStack *sp, const real_T z[16], const real_T p[4], const
              real_T k[4], real_T fs, real_T zd[16], real_T pd[4], real_T kd[4],
              real_T *dd);

/* End of code generation (bilinear.h) */
