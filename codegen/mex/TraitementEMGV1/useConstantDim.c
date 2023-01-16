/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * useConstantDim.c
 *
 * Code generation for function 'useConstantDim'
 *
 */

/* Include files */
#include "useConstantDim.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ke_emlrtRSI = { 32, /* lineNo */
  "useConstantDim",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 99, /* lineNo */
  "ndlooper",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "useConstantDim",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pName */
};

/* Function Definitions */
void useConstantDim(const emlrtStack *sp, emxArray_real_T *varargin_2, int32_T
                    varargin_3)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T x_data[1];
  int32_T b;
  int32_T b_k;
  int32_T k;
  int32_T loop_ub;
  int32_T x_data_tmp;
  int32_T x_size_idx_0;
  int32_T x_size_idx_1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (1 == varargin_3) {
    st.site = &ke_emlrtRSI;
    if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
      b = varargin_2->size[1];
      for (k = 0; k < b; k++) {
        loop_ub = varargin_2->size[0];
        for (b_k = 0; b_k <= loop_ub - 2; b_k++) {
          varargin_2->data[(int16_T)(b_k + 1)] += varargin_2->data[b_k];
        }
      }
    }
  } else {
    st.site = &ke_emlrtRSI;
    b_st.site = &le_emlrtRSI;
    if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
      b = varargin_2->size[1];
      for (k = 0; k <= b - 2; k++) {
        x_size_idx_0 = varargin_2->size[0];
        x_size_idx_1 = varargin_2->size[1];
        loop_ub = varargin_2->size[0] * varargin_2->size[1];
        for (x_data_tmp = 0; x_data_tmp < loop_ub; x_data_tmp++) {
          x_data[x_data_tmp] = varargin_2->data[x_data_tmp];
        }

        loop_ub = varargin_2->size[0];
        for (b_k = 0; b_k < loop_ub; b_k++) {
          x_data_tmp = ((int16_T)(b_k + 1) + x_size_idx_0 * ((int16_T)((int16_T)
            (k + 1) + 1) - 1)) - 1;
          x_data[x_data_tmp] += x_data[b_k + x_size_idx_0 * k];
        }

        x_data_tmp = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = x_size_idx_0;
        varargin_2->size[1] = x_size_idx_1;
        emxEnsureCapacity_real_T(&b_st, varargin_2, x_data_tmp, &cd_emlrtRTEI);
        for (x_data_tmp = 0; x_data_tmp < x_size_idx_1; x_data_tmp++) {
          for (loop_ub = 0; loop_ub < x_size_idx_0; loop_ub++) {
            varargin_2->data[loop_ub + varargin_2->size[0] * x_data_tmp] =
              x_data[loop_ub + x_size_idx_0 * x_data_tmp];
          }
        }
      }
    }
  }
}

/* End of code generation (useConstantDim.c) */
