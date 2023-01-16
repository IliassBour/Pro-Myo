/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "TraitementEMGV1_data.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo se_emlrtRSI = { 144,/* lineNo */
  "eml_find",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 402,/* lineNo */
  "find_first_indices",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = { 392,/* lineNo */
  1,                                   /* colNo */
  "find_first_indices",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 81,/* lineNo */
  1,                                   /* colNo */
  "eml_find",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

/* Function Definitions */
void eml_find(const emlrtStack *sp, const boolean_T x_data[], const int32_T
              x_size[2], int32_T i_data[], int32_T i_size[1])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T iv[2];
  int32_T idx;
  int32_T ii;
  int32_T k;
  int32_T nx;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nx = x_size[0] * x_size[1];
  k = (1 <= nx);
  if (k > nx) {
    emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  st.site = &se_emlrtRSI;
  idx = 0;
  i_size[0] = k;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }

  if (idx > k) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (k == 1) {
    if (idx == 0) {
      i_size[0] = 0;
    }
  } else {
    nx = (1 <= idx);
    iv[0] = 1;
    iv[1] = nx;
    b_st.site = &te_emlrtRSI;
    indexShapeCheck(&b_st, 0, iv);
    i_size[0] = nx;
  }
}

/* End of code generation (find.c) */
