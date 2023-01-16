/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bilinear.c
 *
 * Code generation for function 'bilinear'
 *
 */

/* Include files */
#include "bilinear.h"
#include "TraitementEMGV1_data.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgetrf.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo if_emlrtRSI = { 20, /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 42, /* lineNo */
  "mldiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 168,/* lineNo */
  "bilinear",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\bilinear.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 169,/* lineNo */
  "bilinear",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\bilinear.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 170,/* lineNo */
  "bilinear",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\bilinear.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 171,/* lineNo */
  "bilinear",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\bilinear.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 109,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 124,/* lineNo */
  "InvAtimesX",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 26, /* lineNo */
  "xgetrfs",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrfs.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 20, /* lineNo */
  "mrdivide_helper",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

/* Function Definitions */
void bilinear(const emlrtStack *sp, const real_T z[16], const real_T p[4], const
              real_T k[4], real_T fs, real_T zd[16], real_T pd[4], real_T kd[4],
              real_T *dd)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T t1_tmp[16];
  real_T t2[16];
  real_T Y[4];
  real_T d;
  real_T temp;
  int32_T ipiv[4];
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T jBcol;
  int32_T zd_tmp;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  memset(&t2[0], 0, 16U * sizeof(real_T));
  t2[0] = 1.0;
  t2[5] = 1.0;
  t2[10] = 1.0;
  t2[15] = 1.0;
  for (jBcol = 0; jBcol < 16; jBcol++) {
    temp = z[jBcol] * 0.5 / 2.0;
    d = t2[jBcol];
    zd[jBcol] = d + temp;
    d -= temp;
    t2[jBcol] = d;
  }

  st.site = &of_emlrtRSI;
  b_st.site = &if_emlrtRSI;
  c_st.site = &jf_emlrtRSI;
  d_st.site = &sf_emlrtRSI;
  e_st.site = &tf_emlrtRSI;
  f_st.site = &vf_emlrtRSI;
  memcpy(&t1_tmp[0], &t2[0], 16U * sizeof(real_T));
  g_st.site = &wf_emlrtRSI;
  xgetrf(&g_st, t1_tmp, ipiv, &info);
  for (i = 0; i < 3; i++) {
    jBcol = ipiv[i];
    if (jBcol != i + 1) {
      temp = zd[i];
      zd[i] = zd[jBcol - 1];
      zd[jBcol - 1] = temp;
      temp = zd[i + 4];
      zd[i + 4] = zd[jBcol + 3];
      zd[jBcol + 3] = temp;
      temp = zd[i + 8];
      zd[i + 8] = zd[jBcol + 7];
      zd[jBcol + 7] = temp;
      temp = zd[i + 12];
      zd[i + 12] = zd[jBcol + 11];
      zd[jBcol + 11] = temp;
    }
  }

  for (j = 0; j < 4; j++) {
    jBcol = j << 2;
    if (zd[jBcol] != 0.0) {
      for (i = 2; i < 5; i++) {
        zd_tmp = (i + jBcol) - 1;
        zd[zd_tmp] -= zd[jBcol] * t1_tmp[i - 1];
      }
    }

    if (zd[jBcol + 1] != 0.0) {
      for (i = 3; i < 5; i++) {
        zd_tmp = (i + jBcol) - 1;
        zd[zd_tmp] -= zd[jBcol + 1] * t1_tmp[i + 3];
      }
    }

    if (zd[jBcol + 2] != 0.0) {
      for (i = 4; i < 5; i++) {
        zd[jBcol + 3] -= zd[jBcol + 2] * t1_tmp[11];
      }
    }
  }

  for (j = 0; j < 4; j++) {
    jBcol = j << 2;
    temp = zd[jBcol + 3];
    if (temp != 0.0) {
      zd[jBcol + 3] = temp / t1_tmp[15];
      for (i = 0; i < 3; i++) {
        zd_tmp = i + jBcol;
        zd[zd_tmp] -= zd[jBcol + 3] * t1_tmp[i + 12];
      }
    }

    temp = zd[jBcol + 2];
    if (temp != 0.0) {
      zd[jBcol + 2] = temp / t1_tmp[10];
      for (i = 0; i < 2; i++) {
        zd_tmp = i + jBcol;
        zd[zd_tmp] -= zd[jBcol + 2] * t1_tmp[i + 8];
      }
    }

    temp = zd[jBcol + 1];
    if (temp != 0.0) {
      zd[jBcol + 1] = temp / t1_tmp[5];
      for (i = 0; i < 1; i++) {
        zd[jBcol] -= zd[jBcol + 1] * t1_tmp[4];
      }
    }

    temp = zd[jBcol];
    if (temp != 0.0) {
      temp /= t1_tmp[0];
      zd[jBcol] = temp;
    }
  }

  if (info > 0) {
    e_st.site = &uf_emlrtRSI;
    f_st.site = &lf_emlrtRSI;
    b_warning(&f_st);
  }

  st.site = &pf_emlrtRSI;
  b_st.site = &if_emlrtRSI;
  c_st.site = &jf_emlrtRSI;
  d_st.site = &sf_emlrtRSI;
  pd[0] = p[0];
  pd[1] = p[1];
  pd[2] = p[2];
  pd[3] = p[3];
  e_st.site = &tf_emlrtRSI;
  f_st.site = &vf_emlrtRSI;
  memcpy(&t1_tmp[0], &t2[0], 16U * sizeof(real_T));
  g_st.site = &wf_emlrtRSI;
  xgetrf(&g_st, t1_tmp, ipiv, &info);
  if (ipiv[0] != 1) {
    pd[0] = pd[ipiv[0] - 1];
    pd[ipiv[0] - 1] = p[0];
  }

  if (ipiv[1] != 2) {
    temp = pd[1];
    pd[1] = pd[ipiv[1] - 1];
    pd[ipiv[1] - 1] = temp;
  }

  if (ipiv[2] != 3) {
    temp = pd[2];
    pd[2] = pd[ipiv[2] - 1];
    pd[ipiv[2] - 1] = temp;
  }

  if (pd[0] != 0.0) {
    for (i = 2; i < 5; i++) {
      pd[i - 1] -= pd[0] * t1_tmp[i - 1];
    }
  }

  if (pd[1] != 0.0) {
    for (i = 3; i < 5; i++) {
      pd[i - 1] -= pd[1] * t1_tmp[i + 3];
    }
  }

  if (pd[2] != 0.0) {
    for (i = 4; i < 5; i++) {
      pd[3] -= pd[2] * t1_tmp[11];
    }
  }

  if (pd[3] != 0.0) {
    pd[3] /= t1_tmp[15];
    for (i = 0; i < 3; i++) {
      pd[i] -= pd[3] * t1_tmp[i + 12];
    }
  }

  if (pd[2] != 0.0) {
    pd[2] /= t1_tmp[10];
    for (i = 0; i < 2; i++) {
      pd[i] -= pd[2] * t1_tmp[i + 8];
    }
  }

  if (pd[1] != 0.0) {
    pd[1] /= t1_tmp[5];
    for (i = 0; i < 1; i++) {
      pd[0] -= pd[1] * t1_tmp[4];
    }
  }

  if (pd[0] != 0.0) {
    pd[0] /= t1_tmp[0];
  }

  if (info > 0) {
    e_st.site = &uf_emlrtRSI;
    f_st.site = &lf_emlrtRSI;
    b_warning(&f_st);
  }

  pd[0] *= 0.70710678118654746;
  pd[1] *= 0.70710678118654746;
  pd[2] *= 0.70710678118654746;
  pd[3] *= 0.70710678118654746;
  st.site = &qf_emlrtRSI;
  kd[0] = 0.70710678118654757 * k[0];
  kd[1] = 0.70710678118654757 * k[1];
  kd[2] = 0.70710678118654757 * k[2];
  kd[3] = 0.70710678118654757 * k[3];
  b_st.site = &fg_emlrtRSI;
  mrdiv(&b_st, kd, t2);
  st.site = &rf_emlrtRSI;
  Y[0] = k[0];
  Y[1] = k[1];
  Y[2] = k[2];
  Y[3] = k[3];
  b_st.site = &fg_emlrtRSI;
  mrdiv(&b_st, Y, t2);
  *dd = (((Y[0] * p[0] + Y[1] * p[1]) + Y[2] * p[2]) + Y[3] * p[3]) * 0.5 / 2.0
    + fs;
}

/* End of code generation (bilinear.c) */
