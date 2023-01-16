/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgetrf.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gg_emlrtRSI = { 42, /* lineNo */
  "mrdiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 107,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 135,/* lineNo */
  "XtimesInvA",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

/* Function Definitions */
void mrdiv(const emlrtStack *sp, real_T A[4], const real_T B[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_A[16];
  real_T temp;
  int32_T ipiv[4];
  int32_T info;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &sf_emlrtRSI;
  c_st.site = &hg_emlrtRSI;
  memcpy(&b_A[0], &B[0], 16U * sizeof(real_T));
  d_st.site = &ig_emlrtRSI;
  xgetrf(&d_st, b_A, ipiv, &info);
  A[0] *= 1.0 / b_A[0];
  for (k = 0; k < 1; k++) {
    if (b_A[4] != 0.0) {
      A[1] -= b_A[4] * A[0];
    }
  }

  A[1] *= 1.0 / b_A[5];
  for (k = 0; k < 2; k++) {
    temp = b_A[k + 8];
    if (temp != 0.0) {
      A[2] -= temp * A[k];
    }
  }

  A[2] *= 1.0 / b_A[10];
  for (k = 0; k < 3; k++) {
    temp = b_A[k + 12];
    if (temp != 0.0) {
      A[3] -= temp * A[k];
    }
  }

  A[3] *= 1.0 / b_A[15];
  for (k = 4; k < 5; k++) {
    if (b_A[11] != 0.0) {
      A[2] -= b_A[11] * A[3];
    }
  }

  for (k = 3; k < 5; k++) {
    temp = b_A[k + 3];
    if (temp != 0.0) {
      A[1] -= temp * A[k - 1];
    }
  }

  for (k = 2; k < 5; k++) {
    temp = b_A[k + -1];
    if (temp != 0.0) {
      A[0] -= temp * A[k - 1];
    }
  }

  if (ipiv[2] != 3) {
    temp = A[2];
    A[2] = A[ipiv[2] - 1];
    A[ipiv[2] - 1] = temp;
  }

  if (ipiv[1] != 2) {
    temp = A[1];
    A[1] = A[ipiv[1] - 1];
    A[ipiv[1] - 1] = temp;
  }

  if (ipiv[0] != 1) {
    temp = A[0];
    A[0] = A[ipiv[0] - 1];
    A[ipiv[0] - 1] = temp;
  }

  if (info > 0) {
    c_st.site = &uf_emlrtRSI;
    d_st.site = &lf_emlrtRSI;
    b_warning(&d_st);
  }
}

/* End of code generation (mrdivide_helper.c) */
