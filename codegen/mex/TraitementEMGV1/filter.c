/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include "filter.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void b_filter(const emlrtStack *sp, real_T b_data[], real_T a_data[], const
              real_T x[60501], const real_T zi_data[], real_T y[60501], real_T
              zf_data[], int32_T zf_size[1])
{
  real_T a1;
  int32_T j;
  int32_T k;
  int32_T naxpy;
  int32_T y_tmp;
  a1 = a_data[0];
  if (muDoubleScalarIsInf(a_data[0]) || muDoubleScalarIsNaN(a_data[0])) {
    emlrtErrorWithMessageIdR2018a(sp, &s_emlrtRTEI,
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite",
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite", 0);
  } else if (a_data[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(sp, &r_emlrtRTEI,
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else {
    if (a_data[0] != 1.0) {
      for (k = 0; k < 5; k++) {
        b_data[k] /= a1;
      }

      a_data[1] /= a_data[0];
      a_data[2] /= a_data[0];
      a_data[3] /= a_data[0];
      a_data[4] /= a_data[0];
      a_data[0] = 1.0;
    }
  }

  zf_size[0] = 4;
  zf_data[0] = 0.0;
  zf_data[1] = 0.0;
  zf_data[2] = 0.0;
  zf_data[3] = 0.0;
  y[0] = zi_data[0];
  y[1] = zi_data[1];
  y[2] = zi_data[2];
  y[3] = zi_data[3];
  memset(&y[4], 0, 60497U * sizeof(real_T));
  for (k = 0; k < 60501; k++) {
    naxpy = 60501 - k;
    naxpy = muIntScalarMin_sint32(naxpy, 5);
    for (j = 0; j < naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b_data[j];
    }

    naxpy = 60500 - k;
    naxpy = muIntScalarMin_sint32(naxpy, 4);
    a1 = -y[k];
    for (j = 0; j < naxpy; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += a1 * a_data[j + 1];
    }
  }

  for (j = 0; j < 1; j++) {
    zf_data[0] += x[60497] * b_data[4];
  }

  for (j = 0; j < 2; j++) {
    zf_data[j] += x[60498] * b_data[j + 3];
  }

  for (j = 0; j < 3; j++) {
    zf_data[j] += x[60499] * b_data[j + 2];
  }

  for (j = 0; j < 4; j++) {
    zf_data[j] += x[60500] * b_data[j + 1];
  }

  for (j = 0; j < 1; j++) {
    zf_data[0] += -y[60497] * a_data[4];
  }

  for (j = 0; j < 2; j++) {
    zf_data[j] += -y[60498] * a_data[j + 3];
  }

  for (j = 0; j < 3; j++) {
    zf_data[j] += -y[60499] * a_data[j + 2];
  }

  for (j = 0; j < 4; j++) {
    zf_data[j] += -y[60500] * a_data[j + 1];
  }
}

void filter(const emlrtStack *sp, real_T b_data[], real_T a_data[], const real_T
            x[12], const real_T zi_data[], real_T y[12], real_T zf_data[],
            int32_T zf_size[1])
{
  real_T a1;
  int32_T j;
  int32_T k;
  int32_T naxpy;
  int32_T y_tmp;
  a1 = a_data[0];
  if (muDoubleScalarIsInf(a_data[0]) || muDoubleScalarIsNaN(a_data[0])) {
    emlrtErrorWithMessageIdR2018a(sp, &s_emlrtRTEI,
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite",
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite", 0);
  } else if (a_data[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(sp, &r_emlrtRTEI,
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else {
    if (a_data[0] != 1.0) {
      for (k = 0; k < 5; k++) {
        b_data[k] /= a1;
      }

      a_data[1] /= a_data[0];
      a_data[2] /= a_data[0];
      a_data[3] /= a_data[0];
      a_data[4] /= a_data[0];
      a_data[0] = 1.0;
    }
  }

  zf_size[0] = 4;
  zf_data[0] = 0.0;
  zf_data[1] = 0.0;
  zf_data[2] = 0.0;
  zf_data[3] = 0.0;
  y[0] = zi_data[0];
  y[1] = zi_data[1];
  y[2] = zi_data[2];
  y[3] = zi_data[3];
  memset(&y[4], 0, 8U * sizeof(real_T));
  for (k = 0; k < 12; k++) {
    if (12 - k < 5) {
      naxpy = 11 - k;
    } else {
      naxpy = 4;
    }

    for (j = 0; j <= naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b_data[j];
    }

    if (11 - k < 4) {
      naxpy = 10 - k;
    } else {
      naxpy = 3;
    }

    a1 = y[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += -a1 * a_data[j + 1];
    }
  }

  for (j = 0; j < 1; j++) {
    zf_data[0] += x[8] * b_data[4];
  }

  for (j = 0; j < 2; j++) {
    zf_data[j] += x[9] * b_data[j + 3];
  }

  for (j = 0; j < 3; j++) {
    zf_data[j] += x[10] * b_data[j + 2];
  }

  for (j = 0; j < 4; j++) {
    zf_data[j] += x[11] * b_data[j + 1];
  }

  for (j = 0; j < 1; j++) {
    zf_data[0] += -y[8] * a_data[4];
  }

  for (j = 0; j < 2; j++) {
    zf_data[j] += -y[9] * a_data[j + 3];
  }

  for (j = 0; j < 3; j++) {
    zf_data[j] += -y[10] * a_data[j + 2];
  }

  for (j = 0; j < 4; j++) {
    zf_data[j] += -y[11] * a_data[j + 1];
  }
}

/* End of code generation (filter.c) */
