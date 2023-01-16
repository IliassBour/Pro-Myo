/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xorgqr.c
 *
 * Code generation for function 'xorgqr'
 *
 */

/* Include files */
#include "xorgqr.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ec_emlrtRSI = { 14, /* lineNo */
  "xorgqr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xorgqr.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 60, /* lineNo */
  "ceval_xorgqr",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xorgqr.m"/* pathName */
};

/* Function Definitions */
void xorgqr(const emlrtStack *sp, real_T A[121002], const real_T tau[2])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'o', 'r', 'g', 'q', 'r' };

  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T info;
  boolean_T b_p;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ec_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_dorgqr(102, (ptrdiff_t)60501, (ptrdiff_t)2, (ptrdiff_t)2, &A
    [0], (ptrdiff_t)60501, &tau[0]);
  info = (int32_T)info_t;
  b_st.site = &fc_emlrtRSI;
  if (info != 0) {
    p = true;
    b_p = false;
    if (info == -7) {
      b_p = true;
    } else {
      if (info == -5) {
        b_p = true;
      }
    }

    if (!b_p) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&b_st, &q_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
      }
    }
  } else {
    p = false;
  }

  if (p) {
    for (info = 0; info < 121002; info++) {
      A[info] = rtNaN;
    }
  }
}

/* End of code generation (xorgqr.c) */
