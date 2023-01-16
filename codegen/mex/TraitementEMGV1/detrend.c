/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detrend.c
 *
 * Code generation for function 'detrend'
 *
 */

/* Include files */
#include "detrend.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_types.h"
#include "mtimes.h"
#include "qr.h"
#include "rt_nonfinite.h"
#include "trisolve.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = { 174, /* lineNo */
  "detrend",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\detrend.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 186, /* lineNo */
  "chooseDetrendMethod",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\detrend.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 385, /* lineNo */
  "CPPDetrend",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\detrend.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 389, /* lineNo */
  "CPPDetrend",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\detrend.m"/* pathName */
};

/* Function Declarations */
static void CPPDetrend(TraitementEMGV1StackData *SD, const emlrtStack *sp, const
  real_T x[60501], real_T bp, const real_T s[60501], real_T y[60501]);

/* Function Definitions */
static void CPPDetrend(TraitementEMGV1StackData *SD, const emlrtStack *sp, const
  real_T x[60501], real_T bp, const real_T s[60501], real_T y[60501])
{
  emlrtStack st;
  real_T R[4];
  real_T QtxdR[2];
  real_T b_y[2];
  real_T absAkk;
  real_T mn;
  real_T mx;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 60501; i++) {
    SD->f2.z1[i] = muDoubleScalarMax((s[i] - bp) / s[60500], 0.0);
  }

  for (i = 0; i < 60501; i++) {
    SD->f2.W[i] = SD->f2.z1[i];
  }

  for (i = 0; i < 60501; i++) {
    SD->f2.W[i + 60501] = 1.0;
  }

  st.site = &r_emlrtRSI;
  qr(SD, &st, SD->f2.W, SD->f2.Q, R);
  mtimes(SD->f2.Q, x, b_y);
  QtxdR[0] = b_y[0];
  QtxdR[1] = b_y[1];
  trisolve(R, QtxdR);
  mx = muDoubleScalarAbs(R[0]);
  mn = mx;
  absAkk = muDoubleScalarAbs(R[3]);
  if ((absAkk > mx) || muDoubleScalarIsNaN(absAkk)) {
    mx = absAkk;
  } else {
    if (absAkk < mx) {
      mn = absAkk;
    }
  }

  if (mn / mx < 1.0E-10) {
    st.site = &t_emlrtRSI;
    warning(&st);
  }

  b_mtimes(SD->f2.W, QtxdR, y);
  for (i = 0; i < 60501; i++) {
    y[i] = x[i] - y[i];
  }
}

void detrend(TraitementEMGV1StackData *SD, const emlrtStack *sp, const real_T x
             [60501], real_T y[60501])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  int32_T yk;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  SD->f3.y[0] = 0;
  yk = 0;
  for (k = 0; k < 60500; k++) {
    yk++;
    SD->f3.y[k + 1] = yk;
  }

  for (yk = 0; yk < 60501; yk++) {
    SD->f3.s[yk] = SD->f3.y[yk];
  }

  st.site = &o_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  CPPDetrend(SD, &b_st, x, SD->f3.s[0], SD->f3.s, y);
}

/* End of code generation (detrend.c) */
