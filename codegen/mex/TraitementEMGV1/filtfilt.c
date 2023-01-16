/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filtfilt.c
 *
 * Code generation for function 'filtfilt'
 *
 */

/* Include files */
#include "filtfilt.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_internal_types.h"
#include "TraitementEMGV1_types.h"
#include "filter.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include "warning.h"
#include "blas.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "mwmathutil.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo di_emlrtRSI = { 99, /* lineNo */
  "filtfilt",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo ei_emlrtRSI = { 112,/* lineNo */
  "efiltfilt",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo fi_emlrtRSI = { 113,/* lineNo */
  "efiltfilt",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 114,/* lineNo */
  "efiltfilt",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo hi_emlrtRSI = { 129,/* lineNo */
  "efiltfilt",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo ii_emlrtRSI = { 136,/* lineNo */
  "efiltfilt",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo ji_emlrtRSI = { 251,/* lineNo */
  "getCoeffsAndInitialConditions",     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo ki_emlrtRSI = { 13, /* lineNo */
  "sparse",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pathName */
};

static emlrtRSInfo li_emlrtRSI = { 140,/* lineNo */
  "sparse/sparse",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo mi_emlrtRSI = { 221,/* lineNo */
  "sparse/sparse",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 1435,/* lineNo */
  "sparse/mldivide",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo si_emlrtRSI = { 153,/* lineNo */
  "CXSparseAPI/iteratedSolve",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo ui_emlrtRSI = { 304,/* lineNo */
  "CXSparseAPI/iteratedLU",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo yi_emlrtRSI = { 321,/* lineNo */
  "ffOneChan",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo aj_emlrtRSI = { 322,/* lineNo */
  "ffOneChan",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo bj_emlrtRSI = { 324,/* lineNo */
  "ffOneChan",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo cj_emlrtRSI = { 337,/* lineNo */
  "ffOneChan",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo dj_emlrtRSI = { 338,/* lineNo */
  "ffOneChan",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "sparse",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 195,/* lineNo */
  42,                                  /* colNo */
  "sparse",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 251,/* lineNo */
  24,                                  /* colNo */
  "filtfilt",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\filtfilt.m"/* pName */
};

/* Function Declarations */
static void ffOneChan(TraitementEMGV1StackData *SD, const emlrtStack *sp, const
                      real_T b_data[], const real_T a_data[], real_T xc[60501],
                      const real_T zi_data[]);

/* Function Definitions */
static void ffOneChan(TraitementEMGV1StackData *SD, const emlrtStack *sp, const
                      real_T b_data[], const real_T a_data[], real_T xc[60501],
                      const real_T zi_data[])
{
  emlrtStack st;
  real_T unusedU0[12];
  real_T xt[12];
  real_T yc3[12];
  real_T b_a_data[5];
  real_T b_b_data[5];
  real_T b_zi_data[4];
  real_T zo_data[4];
  real_T a1;
  real_T b_a1;
  real_T d;
  int32_T zo_size[1];
  int32_T j;
  int32_T k;
  int32_T naxpy;
  int32_T yc3_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  a1 = a_data[0];
  b_a1 = a_data[0];
  d = 2.0 * xc[0];
  for (yc3_tmp = 0; yc3_tmp < 12; yc3_tmp++) {
    xt[yc3_tmp] = -xc[12 - yc3_tmp] + d;
  }

  for (yc3_tmp = 0; yc3_tmp < 5; yc3_tmp++) {
    b_b_data[yc3_tmp] = b_data[yc3_tmp];
    b_a_data[yc3_tmp] = a_data[yc3_tmp];
  }

  b_zi_data[0] = zi_data[0] * xt[0];
  b_zi_data[1] = zi_data[1] * xt[0];
  b_zi_data[2] = zi_data[2] * xt[0];
  b_zi_data[3] = zi_data[3] * xt[0];
  st.site = &yi_emlrtRSI;
  filter(&st, b_b_data, b_a_data, xt, b_zi_data, unusedU0, zo_data, zo_size);
  for (yc3_tmp = 0; yc3_tmp < 5; yc3_tmp++) {
    b_b_data[yc3_tmp] = b_data[yc3_tmp];
    b_a_data[yc3_tmp] = a_data[yc3_tmp];
  }

  st.site = &aj_emlrtRSI;
  b_filter(&st, b_b_data, b_a_data, xc, zo_data, SD->u1.f0.yc2, b_zi_data,
           zo_size);
  d = 2.0 * xc[60500];
  for (yc3_tmp = 0; yc3_tmp < 12; yc3_tmp++) {
    xt[yc3_tmp] = -xc[60499 - yc3_tmp] + d;
  }

  st.site = &bj_emlrtRSI;
  for (yc3_tmp = 0; yc3_tmp < 5; yc3_tmp++) {
    b_b_data[yc3_tmp] = b_data[yc3_tmp];
    b_a_data[yc3_tmp] = a_data[yc3_tmp];
  }

  if (muDoubleScalarIsInf(a_data[0]) || muDoubleScalarIsNaN(a_data[0])) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite",
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite", 0);
  } else if (a_data[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else {
    if (a_data[0] != 1.0) {
      for (k = 0; k < 5; k++) {
        b_b_data[k] /= a1;
      }

      b_a_data[1] /= a_data[0];
      b_a_data[2] /= a_data[0];
      b_a_data[3] /= a_data[0];
      b_a_data[4] /= a_data[0];
      b_a_data[0] = 1.0;
    }
  }

  yc3[0] = b_zi_data[0];
  yc3[1] = b_zi_data[1];
  yc3[2] = b_zi_data[2];
  yc3[3] = b_zi_data[3];
  memset(&yc3[4], 0, 8U * sizeof(real_T));
  for (k = 0; k < 12; k++) {
    if (12 - k < 5) {
      naxpy = 11 - k;
    } else {
      naxpy = 4;
    }

    for (j = 0; j <= naxpy; j++) {
      yc3_tmp = k + j;
      yc3[yc3_tmp] += xt[k] * b_b_data[j];
    }

    if (11 - k < 4) {
      naxpy = 10 - k;
    } else {
      naxpy = 3;
    }

    d = yc3[k];
    for (j = 0; j <= naxpy; j++) {
      yc3_tmp = (k + j) + 1;
      yc3[yc3_tmp] += -d * b_a_data[j + 1];
    }
  }

  a1 = yc3[11];
  for (yc3_tmp = 0; yc3_tmp < 5; yc3_tmp++) {
    b_b_data[yc3_tmp] = b_data[yc3_tmp];
    b_a_data[yc3_tmp] = a_data[yc3_tmp];
  }

  for (yc3_tmp = 0; yc3_tmp < 12; yc3_tmp++) {
    xt[yc3_tmp] = yc3[11 - yc3_tmp];
  }

  memcpy(&yc3[0], &xt[0], 12U * sizeof(real_T));
  b_zi_data[0] = zi_data[0] * a1;
  b_zi_data[1] = zi_data[1] * a1;
  b_zi_data[2] = zi_data[2] * a1;
  b_zi_data[3] = zi_data[3] * a1;
  st.site = &cj_emlrtRSI;
  filter(&st, b_b_data, b_a_data, yc3, b_zi_data, unusedU0, zo_data, zo_size);
  st.site = &dj_emlrtRSI;
  for (yc3_tmp = 0; yc3_tmp < 5; yc3_tmp++) {
    b_b_data[yc3_tmp] = b_data[yc3_tmp];
    b_a_data[yc3_tmp] = a_data[yc3_tmp];
  }

  if (a_data[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
      "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else {
    if (a_data[0] != 1.0) {
      for (k = 0; k < 5; k++) {
        b_b_data[k] /= b_a1;
      }

      b_a_data[1] /= a_data[0];
      b_a_data[2] /= a_data[0];
      b_a_data[3] /= a_data[0];
      b_a_data[4] /= a_data[0];
      b_a_data[0] = 1.0;
    }
  }

  SD->u1.f0.yc5[0] = zo_data[0];
  SD->u1.f0.yc5[1] = zo_data[1];
  SD->u1.f0.yc5[2] = zo_data[2];
  SD->u1.f0.yc5[3] = zo_data[3];
  memset(&SD->u1.f0.yc5[4], 0, 60497U * sizeof(real_T));
  for (k = 0; k < 60501; k++) {
    naxpy = 60501 - k;
    naxpy = muIntScalarMin_sint32(naxpy, 5);
    d = SD->u1.f0.yc2[60500 - k];
    for (j = 0; j < naxpy; j++) {
      yc3_tmp = k + j;
      SD->u1.f0.yc5[yc3_tmp] += d * b_b_data[j];
    }

    naxpy = 60500 - k;
    naxpy = muIntScalarMin_sint32(naxpy, 4);
    a1 = -SD->u1.f0.yc5[k];
    for (j = 0; j < naxpy; j++) {
      yc3_tmp = (k + j) + 1;
      SD->u1.f0.yc5[yc3_tmp] += a1 * b_a_data[j + 1];
    }
  }

  for (yc3_tmp = 0; yc3_tmp < 60501; yc3_tmp++) {
    xc[yc3_tmp] = SD->u1.f0.yc5[60500 - yc3_tmp];
  }
}

void filtfilt(TraitementEMGV1StackData *SD, const emlrtStack *sp, const real_T
              b[5], const real_T a[5], const real_T x[60501], real_T y[60501])
{
  static const int8_T cidxInt[10] = { 1, 1, 1, 1, 2, 3, 4, 2, 3, 4 };

  static const int8_T ridxInt[10] = { 1, 2, 3, 4, 2, 3, 4, 1, 2, 3 };

  cs_di* cxA;
  cs_din * N;
  cs_dis * S;
  cell_wrap_38 this_tunableEnvironment[2];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  emxArray_real_T *y_d;
  real_T vals[10];
  real_T outBuff[4];
  real_T tol;
  int32_T sortedIndices[10];
  int32_T cptr;
  int32_T currRowIdx;
  int32_T ridx;
  int8_T b_cidxInt[10];
  int8_T b_ridxInt[10];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &di_emlrtRSI;
  b_st.site = &ei_emlrtRSI;
  validateattributes(&b_st, b);
  b_st.site = &fi_emlrtRSI;
  validateattributes(&b_st, a);
  b_st.site = &gi_emlrtRSI;
  c_st.site = &vc_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 60501)) {
    if ((!muDoubleScalarIsInf(x[cptr])) && (!muDoubleScalarIsNaN(x[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:filtfilt:expectedFinite", 3, 4, 5, "input");
  }

  emxInit_real_T(&c_st, &y_d, 1, &ec_emlrtRTEI, true);
  emxInit_int32_T(&c_st, &y_colidx, 1, &ec_emlrtRTEI, true);
  emxInit_int32_T(&c_st, &y_rowidx, 1, &ec_emlrtRTEI, true);
  b_st.site = &hi_emlrtRSI;
  vals[0] = a[1] + 1.0;
  vals[1] = a[2];
  vals[4] = 1.0;
  vals[7] = -1.0;
  vals[2] = a[3];
  vals[5] = 1.0;
  vals[8] = -1.0;
  vals[3] = a[4];
  vals[6] = 1.0;
  vals[9] = -1.0;
  outBuff[0] = b[1] - b[0] * a[1];
  outBuff[1] = b[2] - b[0] * a[2];
  outBuff[2] = b[3] - b[0] * a[3];
  outBuff[3] = b[4] - b[0] * a[4];
  c_st.site = &ji_emlrtRSI;
  d_st.site = &ki_emlrtRSI;
  for (cptr = 0; cptr < 10; cptr++) {
    sortedIndices[cptr] = cptr + 1;
  }

  e_st.site = &li_emlrtRSI;
  for (ridx = 0; ridx < 10; ridx++) {
    this_tunableEnvironment[0].f1[ridx] = cidxInt[ridx];
    this_tunableEnvironment[1].f1[ridx] = ridxInt[ridx];
  }

  introsort(sortedIndices, this_tunableEnvironment);
  for (cptr = 0; cptr < 10; cptr++) {
    ridx = sortedIndices[cptr];
    b_cidxInt[cptr] = cidxInt[ridx - 1];
    b_ridxInt[cptr] = ridxInt[ridx - 1];
  }

  ridx = y_d->size[0];
  y_d->size[0] = 10;
  emxEnsureCapacity_real_T(&d_st, y_d, ridx, &cc_emlrtRTEI);
  ridx = y_colidx->size[0];
  y_colidx->size[0] = 5;
  emxEnsureCapacity_int32_T(&d_st, y_colidx, ridx, &dc_emlrtRTEI);
  y_colidx->data[0] = 1;
  ridx = y_rowidx->size[0];
  y_rowidx->size[0] = 10;
  emxEnsureCapacity_int32_T(&d_st, y_rowidx, ridx, &cc_emlrtRTEI);
  for (ridx = 0; ridx < 10; ridx++) {
    y_d->data[ridx] = 0.0;
    y_rowidx->data[ridx] = 0;
  }

  cptr = 0;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 1)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[1] = cptr + 1;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 2)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[2] = cptr + 1;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 3)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[3] = cptr + 1;
  while ((cptr + 1 <= 10) && (b_cidxInt[cptr] == 4)) {
    y_rowidx->data[cptr] = b_ridxInt[cptr];
    cptr++;
  }

  y_colidx->data[4] = cptr + 1;
  for (cptr = 0; cptr < 10; cptr++) {
    y_d->data[cptr] = vals[sortedIndices[cptr] - 1];
  }

  e_st.site = &mi_emlrtRSI;
  cptr = 1;
  ridx = y_colidx->data[0];
  y_colidx->data[0] = 1;
  while (ridx < y_colidx->data[1]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[1]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[1];
  y_colidx->data[1] = cptr;
  while (ridx < y_colidx->data[2]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[2]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[2];
  y_colidx->data[2] = cptr;
  while (ridx < y_colidx->data[3]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[3]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  ridx = y_colidx->data[3];
  y_colidx->data[3] = cptr;
  while (ridx < y_colidx->data[4]) {
    tol = 0.0;
    currRowIdx = y_rowidx->data[ridx - 1];
    while ((ridx < y_colidx->data[4]) && (y_rowidx->data[ridx - 1] == currRowIdx))
    {
      tol += y_d->data[ridx - 1];
      ridx++;
    }

    if (tol != 0.0) {
      y_d->data[cptr - 1] = tol;
      y_rowidx->data[cptr - 1] = currRowIdx;
      cptr++;
    }
  }

  y_colidx->data[4] = cptr;
  c_st.site = &ji_emlrtRSI;
  d_st.site = &ri_emlrtRSI;
  e_st.site = &si_emlrtRSI;
  cxA = makeCXSparseMatrix(y_colidx->data[4] - 1, 4, 4, &y_colidx->data[0],
    &y_rowidx->data[0], &y_d->data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    f_st.site = &ui_emlrtRSI;
    b_warning(&f_st);
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(y_colidx->data[4] - 1, 4, 4, &y_colidx->data[0],
      &y_rowidx->data[0], &y_d->data[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    solve_from_qr_di(N, S, (double *)&outBuff[0], 4, 4);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    solve_from_lu_di(N, S, (double *)&outBuff[0], 4);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }

  emxFree_int32_T(&y_rowidx);
  emxFree_int32_T(&y_colidx);
  emxFree_real_T(&y_d);
  memcpy(&y[0], &x[0], 60501U * sizeof(real_T));
  b_st.site = &ii_emlrtRSI;
  ffOneChan(SD, &b_st, b, a, y, outBuff);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (filtfilt.c) */
