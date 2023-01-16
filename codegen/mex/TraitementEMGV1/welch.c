/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * welch.c
 *
 * Code generation for function 'welch'
 *
 */

/* Include files */
#include "welch.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "computeperiodogram.h"
#include "computepsd.h"
#include "psdfreqvec.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xc_emlrtRSI = { 391,/* lineNo */
  "localComputeSpectra",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 408,/* lineNo */
  "localComputeSpectra",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 413,/* lineNo */
  "localComputeSpectra",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pathName */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  398,                                 /* lineNo */
  22,                                  /* colNo */
  "localComputeSpectra",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  398,                                 /* lineNo */
  22,                                  /* colNo */
  "localComputeSpectra",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 391,/* lineNo */
  40,                                  /* colNo */
  "welch",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 395,/* lineNo */
  14,                                  /* colNo */
  "welch",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 398,/* lineNo */
  22,                                  /* colNo */
  "welch",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 398,/* lineNo */
  14,                                  /* colNo */
  "welch",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 377,/* lineNo */
  7,                                   /* colNo */
  "welch",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 373,/* lineNo */
  26,                                  /* colNo */
  "welch",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pName */
};

/* Function Definitions */
void localComputeSpectra(const emlrtStack *sp, const real_T x[60501], const
  char_T options_range[8], emxArray_real_T *Pxx, emxArray_real_T *w, char_T
  units_data[], int32_T units_size[2])
{
  emlrtStack st;
  emxArray_real_T c_w;
  emxArray_real_T *Sxx1;
  emxArray_real_T *Sxxk;
  emxArray_real_T *b_w;
  emxArray_real_T *b_x;
  int32_T c_Sxx1[2];
  int32_T b_Sxx1;
  int32_T i;
  int32_T ii;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &Sxx1, 2, &yb_emlrtRTEI, true);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  emxInit_real_T(sp, &Sxxk, 1, &wb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_w, 1, &ac_emlrtRTEI, true);
  emxInit_real_T(sp, &b_x, 1, &ub_emlrtRTEI, true);
  for (ii = 0; ii < 8; ii++) {
    i = 6722 * ii;
    loop_ub = (6722 * ii - i) + 13443;
    b_Sxx1 = b_x->size[0];
    b_x->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, b_x, b_Sxx1, &ub_emlrtRTEI);
    for (b_Sxx1 = 0; b_Sxx1 <= loop_ub; b_Sxx1++) {
      b_x->data[b_Sxx1] = x[i + b_Sxx1];
    }

    st.site = &xc_emlrtRSI;
    computeperiodogram(&st, b_x, 1000.0, Sxxk, b_w);
    if (ii + 1 == 1) {
      i = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 16384;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_real_T(sp, Sxx1, i, &vb_emlrtRTEI);
      for (i = 0; i < 16384; i++) {
        Sxx1->data[i] = Sxxk->data[i];
      }
    } else {
      if (1 != Sxx1->size[1]) {
        emlrtDimSizeEqCheckR2012b(1, Sxx1->size[1], &b_emlrtECI, sp);
      }

      b_Sxx1 = Sxx1->size[0];
      if (Sxx1->size[0] != 16384) {
        emlrtSizeEqCheck1DR2012b(Sxx1->size[0], 16384, &c_emlrtECI, sp);
      }

      i = Sxxk->size[0];
      Sxxk->size[0] = Sxx1->size[0];
      emxEnsureCapacity_real_T(sp, Sxxk, i, &wb_emlrtRTEI);
      loop_ub = Sxx1->size[0];
      for (i = 0; i < loop_ub; i++) {
        Sxxk->data[i] += Sxx1->data[i];
      }

      loop_ub = Sxx1->size[0];
      i = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = loop_ub;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_real_T(sp, Sxx1, i, &xb_emlrtRTEI);
      for (i = 0; i < b_Sxx1; i++) {
        Sxx1->data[i] = Sxxk->data[i];
      }
    }
  }

  emxFree_real_T(&b_x);
  emxFree_real_T(&Sxxk);
  loop_ub = Sxx1->size[0] * Sxx1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Sxx1->data[i] /= 8.0;
  }

  st.site = &yc_emlrtRSI;
  psdfreqvec(&st, 1000.0, b_w);
  loop_ub = b_w->size[0];
  c_w = *b_w;
  c_Sxx1[0] = loop_ub;
  c_Sxx1[1] = 1;
  c_w.size = &c_Sxx1[0];
  c_w.numDimensions = 2;
  st.site = &ad_emlrtRSI;
  computepsd(&st, Sxx1, &c_w, options_range, Pxx, w, units_data, units_size);
  emxFree_real_T(&b_w);
  emxFree_real_T(&Sxx1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (welch.c) */
