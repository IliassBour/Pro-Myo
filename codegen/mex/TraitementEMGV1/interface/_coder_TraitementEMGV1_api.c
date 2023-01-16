/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_TraitementEMGV1_api.c
 *
 * Code generation for function '_coder_TraitementEMGV1_api'
 *
 */

/* Include files */
#include "_coder_TraitementEMGV1_api.h"
#include "TraitementEMGV1.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_mexutil.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const real_T u[60501]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[285]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[242004]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[285]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *P, const
  char_T *identifier, struct0_T *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[242004]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = { "position", "vitesse", "EMG" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "position";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "position")),
                     &thisId, y->position);
  thisId.fIdentifier = "vitesse";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "vitesse")),
                     &thisId, y->vitesse);
  thisId.fIdentifier = "EMG";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "EMG")),
                     &thisId, y->EMG);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const real_T u[60501])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 60501 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[285])
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[242004])
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[285])
{
  static const int32_T dims[2] = { 1, 285 };

  real_T (*r)[285];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[285])emlrtMxGetData(src);
  for (i = 0; i < 285; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *P, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(P), &thisId, y);
  emlrtDestroyArray(&P);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[242004])
{
  static const int32_T dims[2] = { 60501, 4 };

  real_T (*r)[242004];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[242004])emlrtMxGetData(src);
  for (i = 0; i < 242004; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

void TraitementEMGV1_api(TraitementEMGV1StackData *SD, const mxArray * const
  prhs[1], int32_T nlhs, const mxArray *plhs[6])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T (*MAW1)[60501];
  real_T (*MAW2)[60501];
  real_T (*MAW3)[60501];
  real_T (*Rect)[60501];
  real_T TempsPousse;
  real_T TempsRecov;
  st.tls = emlrtRootTLSGlobal;
  Rect = (real_T (*)[60501])mxMalloc(sizeof(real_T [60501]));
  MAW1 = (real_T (*)[60501])mxMalloc(sizeof(real_T [60501]));
  MAW2 = (real_T (*)[60501])mxMalloc(sizeof(real_T [60501]));
  MAW3 = (real_T (*)[60501])mxMalloc(sizeof(real_T [60501]));

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "P", &SD->f5.P);

  /* Invoke the target function */
  TraitementEMGV1(SD, &st, &SD->f5.P, *Rect, *MAW1, *MAW2, *MAW3, &TempsPousse,
                  &TempsRecov);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*Rect);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*MAW1);
  }

  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(*MAW2);
  }

  if (nlhs > 3) {
    plhs[3] = b_emlrt_marshallOut(*MAW3);
  }

  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(TempsPousse);
  }

  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(TempsRecov);
  }
}

/* End of code generation (_coder_TraitementEMGV1_api.c) */
