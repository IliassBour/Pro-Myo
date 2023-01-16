/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * butter.c
 *
 * Code generation for function 'butter'
 *
 */

/* Include files */
#include "butter.h"
#include "TraitementEMGV1_data.h"
#include "bilinear.h"
#include "eig.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo we_emlrtRSI = { 68, /* lineNo */
  "butter",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 81, /* lineNo */
  "butterImpl",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 83, /* lineNo */
  "butterImpl",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 103,/* lineNo */
  "butterImpl",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo bf_emlrtRSI = { 119,/* lineNo */
  "butterImpl",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 123,/* lineNo */
  "butterImpl",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 130,/* lineNo */
  "butterImpl",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 144,/* lineNo */
  "butterImpl",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\butter.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 186,/* lineNo */
  "zp2ss",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\controllib\\general\\zp2ss.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 185,/* lineNo */
  "zp2ss",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\controllib\\general\\zp2ss.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 180,/* lineNo */
  "zp2ss",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\controllib\\general\\zp2ss.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 63, /* lineNo */
  "lp2bp",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\lp2bp.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 64, /* lineNo */
  "lp2bp",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\lp2bp.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 26, /* lineNo */
  "poly",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m"/* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 161,/* lineNo */
  5,                                   /* colNo */
  "iirchk",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\private\\iirchk.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "vector_poly",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m"/* pName */
};

/* Function Definitions */
void butter(const emlrtStack *sp, const real_T Wn[2], real_T varargout_1[5],
            real_T varargout_2[5])
{
  static const int8_T iv[8] = { -1, 0, 0, -1, 0, 0, 0, 0 };

  static const int8_T a[5] = { 1, 0, -2, 0, 1 };

  static const int8_T iv1[5] = { 1, 0, -2, 0, 1 };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  creal_T kern[5];
  creal_T x[4];
  real_T Wn1[16];
  real_T ad[16];
  real_T B[4];
  real_T b_Wn1[4];
  real_T c[4];
  real_T t[4];
  real_T b_kern_im;
  real_T b_kern_re;
  real_T im;
  real_T kern_im;
  real_T kern_re;
  real_T q;
  real_T r;
  real_T re;
  real_T u_idx_0;
  real_T u_idx_1;
  int32_T Wn1_tmp;
  int32_T i;
  int32_T k;
  boolean_T varargin_1[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &we_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &vc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(Wn[k])) && (!muDoubleScalarIsNaN(Wn[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:butter:expectedFinite", 3, 4, 2, "Wn");
  }

  b_st.site = &ye_emlrtRSI;
  varargin_1[0] = (Wn[0] <= 0.0);
  varargin_1[1] = (Wn[1] <= 0.0);
  p = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!varargin_1[k]) {
      k++;
    } else {
      p = true;
      exitg1 = true;
    }
  }

  guard1 = false;
  if (p) {
    guard1 = true;
  } else {
    varargin_1[0] = (Wn[0] >= 1.0);
    varargin_1[1] = (Wn[1] >= 1.0);
    p = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!varargin_1[k]) {
        k++;
      } else {
        p = true;
        exitg1 = true;
      }
    }

    if (p) {
      guard1 = true;
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
      "signal:iirchk:FreqsMustBeWithinUnitInterval",
      "signal:iirchk:FreqsMustBeWithinUnitInterval", 0);
  }

  u_idx_0 = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[0] / 2.0);
  u_idx_1 = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[1] / 2.0);
  b_st.site = &af_emlrtRSI;
  re = 0.70710678118654746;
  for (k = 2; k >= 2; k--) {
    re -= -0.70710678118654746;
  }

  c_st.site = &hf_emlrtRSI;
  c_st.site = &gf_emlrtRSI;
  im = 1.0 - -re * 0.0;
  t[1] = im;
  t[0] = -re - im * 0.0;
  t[3] = 0.0;
  t[2] = -1.0;
  for (i = 0; i < 2; i++) {
    re = t[i + 2];
    im = t[i];
    B[i] = im + re * 0.0;
    B[i + 2] = im * 0.0 + re;
  }

  c_st.site = &ff_emlrtRSI;
  q = u_idx_1 - u_idx_0;
  b_st.site = &bf_emlrtRSI;
  u_idx_1 *= u_idx_0;
  if (u_idx_1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  u_idx_1 = muDoubleScalarSqrt(u_idx_1);
  b_st.site = &cf_emlrtRSI;
  c_st.site = &mf_emlrtRSI;
  d_st.site = &vc_emlrtRSI;
  p = ((!muDoubleScalarIsInf(u_idx_1)) && (!muDoubleScalarIsNaN(u_idx_1)));
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &g_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 5, Wo,");
  }

  c_st.site = &nf_emlrtRSI;
  d_st.site = &vc_emlrtRSI;
  p = ((!muDoubleScalarIsInf(q)) && (!muDoubleScalarIsNaN(q)));
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &g_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 6, Bw,");
  }

  q = u_idx_1 / q;
  Wn1[0] = u_idx_1 * (B[0] / q);
  Wn1[8] = u_idx_1;
  Wn1[1] = u_idx_1 * (B[1] / q);
  Wn1[9] = u_idx_1 * 0.0;
  Wn1[4] = u_idx_1 * (B[2] / q);
  Wn1[12] = u_idx_1 * 0.0;
  Wn1[5] = u_idx_1 * (B[3] / q);
  Wn1[13] = u_idx_1;
  for (i = 0; i < 4; i++) {
    Wn1_tmp = i << 1;
    k = i << 2;
    Wn1[k + 2] = u_idx_1 * (real_T)iv[Wn1_tmp];
    Wn1[k + 3] = u_idx_1 * (real_T)iv[Wn1_tmp + 1];
  }

  b_Wn1[0] = u_idx_1 * (1.0 / q);
  b_Wn1[2] = u_idx_1 * 0.0;
  c[0] = 0.0;
  c[2] = 0.0;
  b_Wn1[1] = u_idx_1 * (0.0 / q);
  b_Wn1[3] = u_idx_1 * 0.0;
  c[1] = 1.0;
  c[3] = 0.0;
  b_st.site = &df_emlrtRSI;
  bilinear(&b_st, Wn1, b_Wn1, c, 0.0, ad, B, t, &q);
  b_st.site = &ef_emlrtRSI;
  c_st.site = &lg_emlrtRSI;
  d_st.site = &lg_emlrtRSI;
  eig(&d_st, ad, x);
  if (muDoubleScalarIsInf(x[0].re) || muDoubleScalarIsInf(x[0].im) ||
      (muDoubleScalarIsNaN(x[0].re) || muDoubleScalarIsNaN(x[0].im))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
      "Coder:toolbox:nonfiniteValuesNotSupported",
      "Coder:toolbox:nonfiniteValuesNotSupported", 0);
  }

  if (muDoubleScalarIsInf(x[1].re) || muDoubleScalarIsInf(x[1].im) ||
      (muDoubleScalarIsNaN(x[1].re) || muDoubleScalarIsNaN(x[1].im))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
      "Coder:toolbox:nonfiniteValuesNotSupported",
      "Coder:toolbox:nonfiniteValuesNotSupported", 0);
  }

  if (muDoubleScalarIsInf(x[2].re) || muDoubleScalarIsInf(x[2].im) ||
      (muDoubleScalarIsNaN(x[2].re) || muDoubleScalarIsNaN(x[2].im))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
      "Coder:toolbox:nonfiniteValuesNotSupported",
      "Coder:toolbox:nonfiniteValuesNotSupported", 0);
  }

  if (muDoubleScalarIsInf(x[3].re) || muDoubleScalarIsInf(x[3].im) ||
      (muDoubleScalarIsNaN(x[3].re) || muDoubleScalarIsNaN(x[3].im))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
      "Coder:toolbox:nonfiniteValuesNotSupported",
      "Coder:toolbox:nonfiniteValuesNotSupported", 0);
  }

  kern[0].re = 1.0;
  kern[0].im = 0.0;
  kern[1].re = -x[0].re - -x[0].im * 0.0;
  kern[1].im = -x[0].re * 0.0 + -x[0].im;
  kern[2].re = -x[1].re * kern[1].re - -x[1].im * kern[1].im;
  kern[2].im = -x[1].re * kern[1].im + -x[1].im * kern[1].re;
  re = x[1].re;
  im = x[1].im;
  for (k = 2; k >= 2; k--) {
    kern[1].re -= re - im * 0.0;
    kern[1].im -= re * 0.0 + im;
  }

  kern[3].re = -x[2].re * kern[2].re - -x[2].im * kern[2].im;
  kern[3].im = -x[2].re * kern[2].im + -x[2].im * kern[2].re;
  re = x[2].re;
  im = x[2].im;
  for (k = 3; k >= 2; k--) {
    q = kern[k - 2].im;
    u_idx_0 = kern[k - 2].re;
    kern[k - 1].re -= re * u_idx_0 - im * q;
    kern[k - 1].im -= re * q + im * u_idx_0;
  }

  kern[4].re = -x[3].re * kern[3].re - -x[3].im * kern[3].im;
  kern[4].im = -x[3].re * kern[3].im + -x[3].im * kern[3].re;
  re = x[3].re;
  im = x[3].im;
  for (k = 4; k >= 2; k--) {
    q = kern[k - 2].im;
    u_idx_0 = kern[k - 2].re;
    kern[k - 1].re -= re * u_idx_0 - im * q;
    kern[k - 1].im -= re * q + im * u_idx_0;
  }

  u_idx_0 = 2.0 * muDoubleScalarAtan2(u_idx_1, 4.0);
  q = u_idx_0 * 0.0;
  kern_re = 0.0;
  kern_im = 0.0;
  b_kern_re = 0.0;
  b_kern_im = 0.0;
  for (k = 0; k < 5; k++) {
    re = kern[k].re;
    varargout_2[k] = re;
    u_idx_1 = (real_T)k * q;
    im = (real_T)k * -u_idx_0;
    kern[k].re = u_idx_1;
    kern[k].im = im;
    if (im == 0.0) {
      u_idx_1 = muDoubleScalarExp(u_idx_1);
      im = 0.0;
      kern[k].re = u_idx_1;
      kern[k].im = 0.0;
    } else {
      r = muDoubleScalarExp(u_idx_1 / 2.0);
      u_idx_1 = r * (r * muDoubleScalarCos(im));
      im = r * (r * muDoubleScalarSin(im));
      kern[k].re = u_idx_1;
      kern[k].im = im;
    }

    kern_re += u_idx_1 * re - im * 0.0;
    kern_im += u_idx_1 * 0.0 + im * re;
    Wn1_tmp = iv1[k];
    b_kern_re += u_idx_1 * (real_T)Wn1_tmp - im * 0.0;
    b_kern_im += u_idx_1 * 0.0 + im * (real_T)Wn1_tmp;
  }

  for (i = 0; i < 5; i++) {
    Wn1_tmp = a[i];
    u_idx_1 = (real_T)Wn1_tmp * kern_re;
    re = (real_T)Wn1_tmp * kern_im;
    if (b_kern_im == 0.0) {
      if (re == 0.0) {
        q = u_idx_1 / b_kern_re;
      } else if (u_idx_1 == 0.0) {
        q = 0.0;
      } else {
        q = u_idx_1 / b_kern_re;
      }
    } else if (b_kern_re == 0.0) {
      if (u_idx_1 == 0.0) {
        q = re / b_kern_im;
      } else if (re == 0.0) {
        q = 0.0;
      } else {
        q = re / b_kern_im;
      }
    } else {
      q = muDoubleScalarAbs(b_kern_re);
      u_idx_0 = muDoubleScalarAbs(b_kern_im);
      if (q > u_idx_0) {
        q = b_kern_im / b_kern_re;
        q = (u_idx_1 + q * re) / (b_kern_re + q * b_kern_im);
      } else if (u_idx_0 == q) {
        if (b_kern_re > 0.0) {
          u_idx_0 = 0.5;
        } else {
          u_idx_0 = -0.5;
        }

        if (b_kern_im > 0.0) {
          im = 0.5;
        } else {
          im = -0.5;
        }

        q = (u_idx_1 * u_idx_0 + re * im) / q;
      } else {
        q = b_kern_re / b_kern_im;
        q = (q * u_idx_1 + re) / (b_kern_im + q * b_kern_re);
      }
    }

    varargout_1[i] = q;
  }
}

/* End of code generation (butter.c) */
