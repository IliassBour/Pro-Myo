/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * psdfreqvec.c
 *
 * Code generation for function 'psdfreqvec'
 *
 */

/* Include files */
#include "psdfreqvec.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pd_emlrtRSI = { 44, /* lineNo */
  "psdfreqvec",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\siglib\\psdfreqvec.m"/* pathName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 62,/* lineNo */
  1,                                   /* colNo */
  "psdfreqvec",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\siglib\\psdfreqvec.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 146,/* lineNo */
  13,                                  /* colNo */
  "psdfreqvec",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\siglib\\psdfreqvec.m"/* pName */
};

/* Function Definitions */
void psdfreqvec(const emlrtStack *sp, real_T varargin_4, emxArray_real_T *w)
{
  emlrtStack st;
  emxArray_real_T *w1;
  real_T Fs1;
  real_T freq_res;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &w1, 2, &lb_emlrtRTEI, true);
  st.site = &pd_emlrtRSI;
  if (muDoubleScalarIsNaN(varargin_4)) {
    Fs1 = 6.2831853071795862;
  } else {
    Fs1 = varargin_4;
  }

  freq_res = Fs1 / 16384.0;
  i = w1->size[0] * w1->size[1];
  w1->size[0] = 1;
  w1->size[1] = 16384;
  emxEnsureCapacity_real_T(&st, w1, i, &lb_emlrtRTEI);
  for (i = 0; i < 16384; i++) {
    w1->data[i] = freq_res * (real_T)i;
  }

  w1->data[8192] = Fs1 / 2.0;
  w1->data[16383] = Fs1 - freq_res;
  i = w->size[0];
  w->size[0] = 16384;
  emxEnsureCapacity_real_T(&st, w, i, &mb_emlrtRTEI);
  for (i = 0; i < 16384; i++) {
    w->data[i] = w1->data[i];
  }

  emxFree_real_T(&w1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (psdfreqvec.c) */
