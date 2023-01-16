/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "xgetrf.h"
#include "TraitementEMGV1_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yf_emlrtRSI = { 30, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 50, /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 58, /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 45, /* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, real_T A[16], int32_T ipiv[4], int32_T *info)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T s;
  real_T smax;
  int32_T b_j;
  int32_T b_tmp;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jp1j;
  int32_T jy;
  int32_T k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  *info = 0;
  for (j = 0; j < 3; j++) {
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    n = 4 - j;
    jy = 0;
    ix = b_tmp;
    smax = muDoubleScalarAbs(A[b_tmp]);
    for (k = 2; k <= n; k++) {
      ix++;
      s = muDoubleScalarAbs(A[ix]);
      if (s > smax) {
        jy = k - 1;
        smax = s;
      }
    }

    if (A[b_tmp + jy] != 0.0) {
      if (jy != 0) {
        jy += j;
        ipiv[j] = jy + 1;
        smax = A[j];
        A[j] = A[jy];
        A[jy] = smax;
        smax = A[j + 4];
        A[j + 4] = A[jy + 4];
        A[jy + 4] = smax;
        smax = A[j + 8];
        A[j + 8] = A[jy + 8];
        A[jy + 8] = smax;
        smax = A[j + 12];
        A[j + 12] = A[jy + 12];
        A[jy + 12] = smax;
      }

      k = (b_tmp - j) + 4;
      b_st.site = &ag_emlrtRSI;
      for (jy = jp1j; jy <= k; jy++) {
        A[jy - 1] /= A[b_tmp];
      }
    } else {
      *info = j + 1;
    }

    n = 2 - j;
    jy = b_tmp + 4;
    b_st.site = &bg_emlrtRSI;
    c_st.site = &cg_emlrtRSI;
    d_st.site = &yb_emlrtRSI;
    e_st.site = &ac_emlrtRSI;
    jp1j = b_tmp + 6;
    f_st.site = &bc_emlrtRSI;
    for (b_j = 0; b_j <= n; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = b_tmp + 1;
        k = (jp1j - j) + 2;
        f_st.site = &cc_emlrtRSI;
        if ((jp1j <= k) && (k > 2147483646)) {
          g_st.site = &nb_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        for (ijA = jp1j; ijA <= k; ijA++) {
          A[ijA - 1] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 4;
      jp1j += 4;
    }
  }

  if ((*info == 0) && (!(A[15] != 0.0))) {
    *info = 4;
  }
}

/* End of code generation (xgetrf.c) */
