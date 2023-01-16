/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computepsd.c
 *
 * Code generation for function 'computepsd'
 *
 */

/* Include files */
#include "computepsd.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ud_emlrtRSI = { 47, /* lineNo */
  "computepsd",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 45, /* lineNo */
  "computepsd",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 38, /* lineNo */
  "computepsd",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 9,  /* lineNo */
  "isodd",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\isodd.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 27, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo nb_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 44,/* lineNo */
  7,                                   /* colNo */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 1,/* lineNo */
  22,                                  /* colNo */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 45,/* lineNo */
  7,                                   /* colNo */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 47,/* lineNo */
  4,                                   /* colNo */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 40,/* lineNo */
  7,                                   /* colNo */
  "computepsd",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\computepsd.m"/* pName */
};

/* Function Definitions */
void computepsd(const emlrtStack *sp, const emxArray_real_T *Sxx1, const
                emxArray_real_T *w2, const char_T range[8], emxArray_real_T
                *varargout_1, emxArray_real_T *varargout_2, char_T
                varargout_3_data[], int32_T varargout_3_size[2])
{
  static const char_T b[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *Sxx_unscaled;
  emxArray_real_T *varargin_2;
  real_T Sxx_unscaled_data[1];
  real_T varargin_3_data[1];
  int32_T input_sizes[2];
  int32_T c_input_sizes_idx_0;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T result;
  int16_T b_input_sizes_idx_0;
  int16_T sizes_idx_0;
  int8_T input_sizes_idx_0;
  boolean_T empty_non_axis_sizes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (memcmp(&range[0], &b[0], 8) == 0) {
    emxInit_real_T(sp, &Sxx_unscaled, 2, &tb_emlrtRTEI, true);
    st.site = &wd_emlrtRSI;
    b_st.site = &xd_emlrtRSI;
    loop_ub = Sxx1->size[1];
    i = Sxx_unscaled->size[0] * Sxx_unscaled->size[1];
    Sxx_unscaled->size[0] = 8193;
    Sxx_unscaled->size[1] = Sxx1->size[1];
    emxEnsureCapacity_real_T(sp, Sxx_unscaled, i, &pb_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 8193; i1++) {
        if (i1 + 1 > Sxx1->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, Sxx1->size[0], &h_emlrtBCI,
            sp);
        }

        Sxx_unscaled->data[i1 + Sxx_unscaled->size[0] * i] = Sxx1->data[i1 +
          Sxx1->size[0] * i];
      }
    }

    emxInit_real_T(sp, &varargin_2, 2, &qb_emlrtRTEI, true);
    st.site = &vd_emlrtRSI;
    loop_ub = Sxx1->size[1] - 1;
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 8191;
    varargin_2->size[1] = Sxx1->size[1];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &qb_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      for (i1 = 0; i1 < 8191; i1++) {
        varargin_2->data[i1 + varargin_2->size[0] * i] = 2.0 *
          Sxx_unscaled->data[(i1 + Sxx_unscaled->size[0] * i) + 1];
      }
    }

    loop_ub = Sxx1->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      varargin_3_data[i] = Sxx_unscaled->data[Sxx_unscaled->size[0] * i + 8192];
    }

    b_st.site = &ae_emlrtRSI;
    if (Sxx1->size[1] != 0) {
      result = Sxx1->size[1];
    } else if (varargin_2->size[1] != 0) {
      result = (int16_T)Sxx1->size[1];
    } else if (Sxx1->size[1] != 0) {
      result = Sxx1->size[1];
    } else {
      if (Sxx1->size[1] > 0) {
        result = Sxx1->size[1];
      } else {
        result = 0;
      }

      if ((int16_T)Sxx1->size[1] > result) {
        result = 1;
      }

      if (Sxx1->size[1] > result) {
        result = Sxx1->size[1];
      }
    }

    c_st.site = &be_emlrtRSI;
    if ((Sxx1->size[1] != result) && (Sxx1->size[1] != 0)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if (((int16_T)Sxx1->size[1] != result) && (varargin_2->size[1] != 0)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    if ((Sxx1->size[1] != result) && (Sxx1->size[1] != 0)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes || (Sxx1->size[1] != 0)) {
      input_sizes_idx_0 = 1;
    } else {
      input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || (varargin_2->size[1] != 0)) {
      b_input_sizes_idx_0 = 8191;
    } else {
      b_input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || (Sxx1->size[1] != 0)) {
      sizes_idx_0 = 1;
    } else {
      sizes_idx_0 = 0;
    }

    loop_ub = Sxx1->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      Sxx_unscaled_data[i] = Sxx_unscaled->data[Sxx_unscaled->size[0] * i];
    }

    emxFree_real_T(&Sxx_unscaled);
    c_input_sizes_idx_0 = b_input_sizes_idx_0;
    i = varargout_1->size[0] * varargout_1->size[1];
    i1 = input_sizes_idx_0 + b_input_sizes_idx_0;
    varargout_1->size[0] = i1 + sizes_idx_0;
    varargout_1->size[1] = result;
    emxEnsureCapacity_real_T(sp, varargout_1, i, &rb_emlrtRTEI);
    for (i = 0; i < result; i++) {
      loop_ub = input_sizes_idx_0;
      for (i2 = 0; i2 < loop_ub; i2++) {
        varargout_1->data[varargout_1->size[0] * i] =
          Sxx_unscaled_data[input_sizes_idx_0 * i];
      }
    }

    for (i = 0; i < result; i++) {
      for (i2 = 0; i2 < c_input_sizes_idx_0; i2++) {
        varargout_1->data[(i2 + input_sizes_idx_0) + varargout_1->size[0] * i] =
          varargin_2->data[i2 + varargin_2->size[0] * i];
      }
    }

    emxFree_real_T(&varargin_2);
    for (i = 0; i < result; i++) {
      loop_ub = sizes_idx_0;
      for (i2 = 0; i2 < loop_ub; i2++) {
        varargout_1->data[i1 + varargout_1->size[0] * i] =
          varargin_3_data[sizes_idx_0 * i];
      }
    }

    input_sizes[0] = 1;
    input_sizes[1] = 8193;
    st.site = &ud_emlrtRSI;
    indexShapeCheck(&st, w2->size[0], input_sizes);
    i = varargout_2->size[0];
    varargout_2->size[0] = 8193;
    emxEnsureCapacity_real_T(sp, varargout_2, i, &sb_emlrtRTEI);
    for (i = 0; i < 8193; i++) {
      if (i + 1 > w2->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, w2->size[0], &i_emlrtBCI, sp);
      }

      varargout_2->data[i] = w2->data[i];
    }
  } else {
    i = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx1->size[0];
    varargout_1->size[1] = Sxx1->size[1];
    emxEnsureCapacity_real_T(sp, varargout_1, i, &nb_emlrtRTEI);
    loop_ub = Sxx1->size[0] * Sxx1->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargout_1->data[i] = Sxx1->data[i];
    }

    i = varargout_2->size[0];
    varargout_2->size[0] = w2->size[0];
    emxEnsureCapacity_real_T(sp, varargout_2, i, &ob_emlrtRTEI);
    loop_ub = w2->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargout_2->data[i] = w2->data[i];
    }
  }

  loop_ub = varargout_1->size[0] * varargout_1->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargout_1->data[i] /= 1000.0;
  }

  varargout_3_size[0] = 1;
  varargout_3_size[1] = 2;
  varargout_3_data[0] = 'H';
  varargout_3_data[1] = 'z';
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (computepsd.c) */
