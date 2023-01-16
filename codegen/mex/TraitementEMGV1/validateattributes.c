/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * validateattributes.c
 *
 * Code generation for function 'validateattributes'
 *
 */

/* Include files */
#include "validateattributes.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void validateattributes(const emlrtStack *sp, const real_T a[5])
{
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 5)) {
    if ((!muDoubleScalarIsInf(a[k])) && (!muDoubleScalarIsNaN(a[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:filtfilt:expectedFinite", 3, 4, 5, "input");
  }
}

/* End of code generation (validateattributes.c) */
