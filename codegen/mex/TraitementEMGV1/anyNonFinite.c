/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * anyNonFinite.c
 *
 * Code generation for function 'anyNonFinite'
 *
 */

/* Include files */
#include "anyNonFinite.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
boolean_T anyNonFinite(const real_T x[16])
{
  int32_T k;
  boolean_T p;
  p = true;
  for (k = 0; k < 16; k++) {
    if ((!p) || (muDoubleScalarIsInf(x[k]) || muDoubleScalarIsNaN(x[k]))) {
      p = false;
    }
  }

  return !p;
}

/* End of code generation (anyNonFinite.c) */
