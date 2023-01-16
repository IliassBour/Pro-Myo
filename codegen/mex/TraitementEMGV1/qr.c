/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qr.c
 *
 * Code generation for function 'qr'
 *
 */

/* Include files */
#include "qr.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include "xgeqrf.h"
#include "xorgqr.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 25,  /* lineNo */
  "qr",                                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\qr.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 35,  /* lineNo */
  "eml_qr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_qr.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 153,/* lineNo */
  "qr_econ",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_qr.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 162,/* lineNo */
  "qr_econ",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_qr.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 174,/* lineNo */
  "qr_econ",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_qr.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 189,/* lineNo */
  "unpackQR",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eml_qr.m"/* pathName */
};

/* Function Definitions */
void qr(TraitementEMGV1StackData *SD, const emlrtStack *sp, const real_T A
        [121002], real_T Q[121002], real_T R[4])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T tau[2];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &y_emlrtRSI;
  memcpy(&SD->u1.f1.A[0], &A[0], 121002U * sizeof(real_T));
  c_st.site = &ab_emlrtRSI;
  xgeqrf(&c_st, SD->u1.f1.A, tau);
  c_st.site = &bb_emlrtRSI;
  R[0] = SD->u1.f1.A[0];
  R[1] = 0.0;
  c_st.site = &bb_emlrtRSI;
  for (i = 0; i < 2; i++) {
    R[i + 2] = SD->u1.f1.A[i + 60501];
  }

  c_st.site = &cb_emlrtRSI;
  d_st.site = &dc_emlrtRSI;
  xorgqr(&d_st, SD->u1.f1.A, tau);
  for (i = 0; i < 2; i++) {
    memcpy(&Q[i * 60501], &SD->u1.f1.A[i * 60501], 60501U * sizeof(real_T));
  }
}

/* End of code generation (qr.c) */
