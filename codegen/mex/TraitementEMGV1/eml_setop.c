/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.c
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "eml_setop.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "issorted.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo t_emlrtRTEI = { 213,/* lineNo */
  13,                                  /* colNo */
  "do_vectors",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 216,/* lineNo */
  13,                                  /* colNo */
  "do_vectors",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 380,/* lineNo */
  5,                                   /* colNo */
  "do_vectors",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 391,/* lineNo */
  9,                                   /* colNo */
  "do_vectors",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 418,/* lineNo */
  5,                                   /* colNo */
  "do_vectors",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 194,/* lineNo */
  24,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 195,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 196,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 386,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 397,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 422,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

/* Function Definitions */
void do_vectors(const emlrtStack *sp, const emxArray_int32_T *a, const
                emxArray_int32_T *b, emxArray_int32_T *c, emxArray_int32_T *ia,
                emxArray_int32_T *ib)
{
  int32_T ak;
  int32_T b_ialast;
  int32_T b_iblast;
  int32_T bk;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T na;
  int32_T nb;
  int32_T nc;
  int32_T ncmax;
  int32_T nia;
  int32_T nib;
  na = a->size[0];
  nb = b->size[0];
  ncmax = a->size[0] + b->size[0];
  iafirst = c->size[0];
  c->size[0] = ncmax;
  emxEnsureCapacity_int32_T(sp, c, iafirst, &vc_emlrtRTEI);
  iafirst = ia->size[0];
  ia->size[0] = a->size[0];
  emxEnsureCapacity_int32_T(sp, ia, iafirst, &wc_emlrtRTEI);
  iafirst = ib->size[0];
  ib->size[0] = b->size[0];
  emxEnsureCapacity_int32_T(sp, ib, iafirst, &xc_emlrtRTEI);
  if (!issorted(a)) {
    emlrtErrorWithMessageIdR2018a(sp, &t_emlrtRTEI,
      "Coder:toolbox:eml_setop_unsortedA", "Coder:toolbox:eml_setop_unsortedA",
      0);
  }

  if (!issorted(b)) {
    emlrtErrorWithMessageIdR2018a(sp, &u_emlrtRTEI,
      "Coder:toolbox:eml_setop_unsortedB", "Coder:toolbox:eml_setop_unsortedB",
      0);
  }

  nc = -1;
  nia = 0;
  nib = 0;
  iafirst = 1;
  ialast = 0;
  ibfirst = 0;
  iblast = 0;
  while ((ialast + 1 <= na) && (iblast + 1 <= nb)) {
    b_ialast = ialast + 1;
    ak = a->data[ialast];
    while ((b_ialast < a->size[0]) && (a->data[b_ialast] == ak)) {
      b_ialast++;
    }

    ialast = b_ialast - 1;
    b_iblast = iblast + 1;
    bk = b->data[iblast];
    while ((b_iblast < b->size[0]) && (b->data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast - 1;
    if (ak == bk) {
      nc++;
      c->data[nc] = ak;
      nia++;
      ia->data[nia - 1] = iafirst;
      ialast = b_ialast;
      iafirst = b_ialast + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c->data[nc] = ak;
      ia->data[nia - 1] = iafirst;
      ialast = b_ialast;
      iafirst = b_ialast + 1;
    } else {
      nc++;
      nib++;
      c->data[nc] = bk;
      ib->data[nib - 1] = ibfirst + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    }
  }

  while (ialast + 1 <= na) {
    b_ialast = ialast + 1;
    while ((b_ialast < a->size[0]) && (a->data[b_ialast] == a->data[ialast])) {
      b_ialast++;
    }

    nc++;
    nia++;
    c->data[nc] = a->data[ialast];
    ia->data[nia - 1] = iafirst;
    ialast = b_ialast;
    iafirst = b_ialast + 1;
  }

  while (iblast + 1 <= nb) {
    b_iblast = iblast + 1;
    while ((b_iblast < b->size[0]) && (b->data[b_iblast] == b->data[iblast])) {
      b_iblast++;
    }

    nc++;
    nib++;
    c->data[nc] = b->data[iblast];
    ib->data[nib - 1] = ibfirst + 1;
    iblast = b_iblast;
    ibfirst = b_iblast;
  }

  if (a->size[0] > 0) {
    if (nia > a->size[0]) {
      emlrtErrorWithMessageIdR2018a(sp, &v_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    iafirst = ia->size[0];
    if (1 > nia) {
      ia->size[0] = 0;
    } else {
      ia->size[0] = nia;
    }

    emxEnsureCapacity_int32_T(sp, ia, iafirst, &yc_emlrtRTEI);
  }

  if (b->size[0] > 0) {
    if (nib > b->size[0]) {
      emlrtErrorWithMessageIdR2018a(sp, &w_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    iafirst = ib->size[0];
    if (1 > nib) {
      ib->size[0] = 0;
    } else {
      ib->size[0] = nib;
    }

    emxEnsureCapacity_int32_T(sp, ib, iafirst, &ad_emlrtRTEI);
  }

  if (ncmax > 0) {
    if (nc + 1 > ncmax) {
      emlrtErrorWithMessageIdR2018a(sp, &x_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    iafirst = c->size[0];
    if (1 > nc + 1) {
      c->size[0] = 0;
    } else {
      c->size[0] = nc + 1;
    }

    emxEnsureCapacity_int32_T(sp, c, iafirst, &bd_emlrtRTEI);
  }
}

/* End of code generation (eml_setop.c) */
