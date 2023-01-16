/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqrf.c
 *
 * Code generation for function 'xgeqrf'
 *
 */

/* Include files */
#include "xgeqrf.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 27, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 91, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

/* Function Definitions */
void xgeqrf(const emlrtStack *sp, real_T A[121002], real_T tau[2])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 'q', 'r', 'f' };

  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T info;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_dgeqrf(102, (ptrdiff_t)60501, (ptrdiff_t)2, &A[0], (ptrdiff_t)
    60501, &tau[0]);
  info = (int32_T)info_t;
  b_st.site = &eb_emlrtRSI;
  if (info != 0) {
    p = true;
    if (info != -4) {
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
    for (info = 0; info < 2; info++) {
      for (i = 0; i < 60501; i++) {
        A[info * 60501 + i] = rtNaN;
      }

      tau[info] = rtNaN;
    }
  }
}

/* End of code generation (xgeqrf.c) */
