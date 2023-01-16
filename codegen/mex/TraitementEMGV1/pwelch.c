/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pwelch.c
 *
 * Code generation for function 'pwelch'
 *
 */

/* Include files */
#include "pwelch.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include "welch.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = { 170,/* lineNo */
  "pwelch",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\pwelch.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 126,/* lineNo */
  "welch",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 54, /* lineNo */
  "welch",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\welch.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 37, /* lineNo */
  "welchparse",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\+signal\\+internal\\+spectral\\welchparse.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 30, /* lineNo */
  "welchparse",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\+signal\\+internal\\+spectral\\welchparse.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 111,/* lineNo */
  "parse_inputs",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\+signal\\+internal\\+spectral\\welchparse.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 380,/* lineNo */
  "welch_options",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\+signal\\+internal\\+spectral\\welchparse.m"/* pathName */
};

/* Function Definitions */
void pwelch(const emlrtStack *sp, const real_T x[60501], emxArray_real_T
            *varargout_1, emxArray_real_T *varargout_2)
{
  static const char_T t0_range[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T units_size[2];
  int32_T k;
  char_T units_data[10];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &rc_emlrtRSI;
  c_st.site = &tc_emlrtRSI;
  d_st.site = &uc_emlrtRSI;
  e_st.site = &vc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 60501)) {
    if ((!muDoubleScalarIsInf(x[k])) && (!muDoubleScalarIsNaN(x[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&e_st, &g_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:pwelch:expectedFinite", 3, 4, 1, "x");
  }

  e_st.site = &vc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 60501)) {
    if (!muDoubleScalarIsNaN(x[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&e_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:pwelch:expectedNonNaN", 3, 4, 1, "x");
  }

  c_st.site = &sc_emlrtRSI;
  d_st.site = &wc_emlrtRSI;
  b_st.site = &qc_emlrtRSI;
  localComputeSpectra(&b_st, x, t0_range, varargout_1, varargout_2, units_data,
                      units_size);
}

/* End of code generation (pwelch.c) */
