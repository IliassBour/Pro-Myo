/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TraitementEMGV1.c
 *
 * Code generation for function 'TraitementEMGV1'
 *
 */

/* Include files */
#include "TraitementEMGV1.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_mexutil.h"
#include "TraitementEMGV1_types.h"
#include "butter.h"
#include "colon.h"
#include "detrend.h"
#include "filtfilt.h"
#include "find.h"
#include "findpeaks.h"
#include "mean.h"
#include "movmean.h"
#include "pwelch.h"
#include "rt_nonfinite.h"
#include "useConstantDim.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 51,  /* lineNo */
  5,                                   /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtRSInfo emlrtRSI = { 14,    /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 17,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 18,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 19,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 21,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 22,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 23,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 24,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 26,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 27,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 31,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 32,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 33,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 36,  /* lineNo */
  "TraitementEMGV1",                   /* fcnName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 47, /* lineNo */
  "function_handle/parenReference",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\function_handle.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 103,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 17, /* lineNo */
  "log10",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\log10.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 33, /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 14, /* lineNo */
  "cumsum",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 16, /* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 10, /* lineNo */
  "round",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 39, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo ve_emlrtRSI = { 22, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo kj_emlrtRSI = { 22, /* lineNo */
  "movmean",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\movmean.m"/* pathName */
};

static emlrtRSInfo lj_emlrtRSI = { 37, /* lineNo */
  "movSumProdOrMean",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\movSumProdOrMean.m"/* pathName */
};

static emlrtRSInfo mj_emlrtRSI = { 63, /* lineNo */
  "applyVectorFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyVectorFunction.m"/* pathName */
};

static emlrtRSInfo nj_emlrtRSI = { 36, /* lineNo */
  "@(x)vmovfun(op,x,nx,kleft,kright,omitnan,ep,fillval,ytype)",/* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\movSumProdOrMean.m"/* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "log10",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\log10.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  53,                                  /* colNo */
  "sumX",                              /* aName */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  19,                                  /* lineNo */
  5,                                   /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  11,                                  /* colNo */
  "PSD",                               /* aName */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  63,                                  /* colNo */
  "PSD",                               /* aName */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  58,                                  /* colNo */
  "PSD",                               /* aName */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  35,                                  /* colNo */
  "PSD",                               /* aName */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  24,                                  /* colNo */
  "sumX",                              /* aName */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 22,    /* lineNo */
  24,                                  /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  18,                                  /* colNo */
  "F",                                 /* aName */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m",    /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo y_emlrtRTEI = { 19,/* lineNo */
  31,                                  /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 19,/* lineNo */
  16,                                  /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 22,/* lineNo */
  19,                                  /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 1,/* lineNo */
  62,                                  /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 22,/* lineNo */
  30,                                  /* colNo */
  "TraitementEMGV1",                   /* fName */
  "D:\\TESTEMG\\TraitementEMGV1.m"     /* pName */
};

/* Function Definitions */
void TraitementEMGV1(TraitementEMGV1StackData *SD, const emlrtStack *sp, const
                     struct0_T *P, real_T Rect[60501], real_T MAW1[60501],
                     real_T MAW2[60501], real_T MAW3[60501], real_T *TempsPousse,
                     real_T *TempsRecov)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *F;
  emxArray_real_T *PSD;
  emxArray_real_T *b_PSD;
  emxArray_real_T *c_PSD;
  emxArray_real_T *jk_emlrtRSI;
  emxArray_real_T *y;
  real_T a[5];
  real_T b[5];
  real_T dv[2];
  real_T Fc_data[1];
  real_T totalX;
  real_T tpush;
  real_T trecov;
  int32_T PSD_size[2];
  int32_T ii_data[1];
  int32_T ii_size[1];
  int32_T Fc_size_idx_0;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T nx;
  boolean_T PSD_data[16384];
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
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /*     %% 1-Données */
  /* P = load('Course400mPiste.mat'); */
  /*  Fréquence d'échantillonage (Hz) */
  /*  Vecteur temps de l'échantillon */
  /*  Largeur de fenêtre #1 */
  /*  Largeur de fenêtre #2 */
  /*  Largeur de fenêtre #3 */
  /*     %% 2-Éliminer DC et tendance linéaire */
  totalX = P->EMG[181503];
  for (k = 0; k < 60500; k++) {
    totalX += P->EMG[k + 181504];
  }

  totalX /= 60501.0;

  /*  Éliminer le DC */
  for (i = 0; i < 60501; i++) {
    SD->f4.Y[i] = P->EMG[i + 181503] - totalX;
  }

  emxInit_real_T(sp, &PSD, 2, &db_emlrtRTEI, true);
  emxInit_real_T(sp, &F, 1, &eb_emlrtRTEI, true);
  st.site = &emlrtRSI;
  detrend(SD, &st, SD->f4.Y, SD->f4.X);

  /*  Élminier la tendance linéaire */
  /*     %% 3-Filtrer */
  st.site = &b_emlrtRSI;
  pwelch(&st, SD->f4.X, PSD, F);

  /*  Estimation de la densité spectrale de puissance du signal */
  st.site = &c_emlrtRSI;
  p = false;
  i = PSD->size[0] * PSD->size[1];
  for (k = 0; k < i; k++) {
    if (p || (PSD->data[k] < 0.0)) {
      p = true;
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      5, "log10");
  }

  b_st.site = &ge_emlrtRSI;
  nx = PSD->size[0] * PSD->size[1];
  c_st.site = &he_emlrtRSI;
  for (k = 0; k < nx; k++) {
    PSD->data[k] = muDoubleScalarLog10(PSD->data[k]);
  }

  loop_ub = PSD->size[0] * PSD->size[1];
  for (i = 0; i < loop_ub; i++) {
    PSD->data[i] *= 10.0;
  }

  /*  Conversion en dB/Hz */
  if ((PSD->size[0] == 0) || (PSD->size[1] == 0)) {
    nx = 0;
  } else {
    nx = muIntScalarMax_sint32(PSD->size[0], 1);
  }

  i = (int32_T)muDoubleScalarRound(0.9 * (real_T)nx);
  if (i > PSD->size[0]) {
    i = 0;
    k = 0;
  } else {
    if ((i < 1) || (i > PSD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, PSD->size[0], &e_emlrtBCI, sp);
    }

    i--;
    if (PSD->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(PSD->size[0], 1, PSD->size[0], &d_emlrtBCI,
        sp);
    }

    k = PSD->size[0];
  }

  if (1 > PSD->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, PSD->size[1], &b_emlrtBCI, sp);
  }

  emlrtSubAssignSizeCheckR2012b(&PSD->size[0], 1, &PSD->size[0], 1, &emlrtECI,
    sp);
  if (1 > PSD->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, PSD->size[1], &c_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &b_PSD, 1, &y_emlrtRTEI, true);
  nx = PSD->size[0] - 1;
  loop_ub = k - i;
  k = b_PSD->size[0];
  b_PSD->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_PSD, k, &y_emlrtRTEI);
  for (k = 0; k < loop_ub; k++) {
    b_PSD->data[k] = PSD->data[i + k];
  }

  st.site = &d_emlrtRSI;
  totalX = mean(b_PSD);
  i = b_PSD->size[0];
  b_PSD->size[0] = PSD->size[0];
  emxEnsureCapacity_real_T(sp, b_PSD, i, &ab_emlrtRTEI);
  for (i = 0; i <= nx; i++) {
    b_PSD->data[i] = PSD->data[i] - totalX;
  }

  loop_ub = b_PSD->size[0];
  for (i = 0; i < loop_ub; i++) {
    PSD->data[i] = b_PSD->data[i];
  }

  emxFree_real_T(&b_PSD);

  /*  Éliminer le bruit */
  st.site = &e_emlrtRSI;
  b_st.site = &ie_emlrtRSI;
  nx = 2;
  if (PSD->size[0] != 1) {
    nx = 1;
  }

  c_st.site = &je_emlrtRSI;
  useConstantDim(&c_st, PSD, nx);

  /*  Somme cumulée du PSD */
  if (1 > PSD->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, PSD->size[1], &emlrtBCI, sp);
  }

  if ((PSD->size[0] == 0) || (PSD->size[1] == 0)) {
    nx = 0;
  } else {
    nx = muIntScalarMax_sint32(PSD->size[0], 1);
  }

  emxInit_real_T(sp, &y, 2, &fb_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  totalX = 0.9 * (real_T)nx;
  b_st.site = &fe_emlrtRSI;
  if (PSD->size[0] < totalX) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (muDoubleScalarFloor(totalX) == totalX) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)muDoubleScalarFloor((real_T)PSD->size[0] - totalX) + 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &bb_emlrtRTEI);
    loop_ub = (int32_T)muDoubleScalarFloor((real_T)PSD->size[0] - totalX);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = totalX + (real_T)i;
    }
  } else {
    c_st.site = &de_emlrtRSI;
    eml_float_colon(&c_st, totalX, PSD->size[0], y);
  }

  st.site = &f_emlrtRSI;
  b_st.site = &qe_emlrtRSI;
  nx = y->size[1];
  c_st.site = &he_emlrtRSI;
  for (k = 0; k < nx; k++) {
    y->data[k] = muDoubleScalarRound(y->data[k]);
  }

  emxInit_real_T(&b_st, &c_PSD, 1, &cb_emlrtRTEI, true);
  i = c_PSD->size[0];
  c_PSD->size[0] = y->size[1];
  emxEnsureCapacity_real_T(sp, c_PSD, i, &cb_emlrtRTEI);
  loop_ub = y->size[1];
  for (i = 0; i < loop_ub; i++) {
    if (y->data[i] != (int32_T)muDoubleScalarFloor(y->data[i])) {
      emlrtIntegerCheckR2012b(y->data[i], &emlrtDCI, sp);
    }

    k = (int32_T)y->data[i];
    if ((k < 1) || (k > PSD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(k, 1, PSD->size[0], &f_emlrtBCI, sp);
    }

    c_PSD->data[i] = PSD->data[k - 1];
  }

  emxFree_real_T(&y);
  st.site = &f_emlrtRSI;
  totalX = mean(c_PSD);

  /*  Moyenne des derniers 10% de la somme cumulée */
  st.site = &g_emlrtRSI;
  totalX *= 0.95;
  PSD_size[0] = PSD->size[0];
  PSD_size[1] = PSD->size[1];
  loop_ub = PSD->size[0] * PSD->size[1];
  emxFree_real_T(&c_PSD);
  for (i = 0; i < loop_ub; i++) {
    PSD_data[i] = (PSD->data[i] >= totalX);
  }

  emxFree_real_T(&PSD);
  b_st.site = &re_emlrtRSI;
  eml_find(&b_st, PSD_data, PSD_size, ii_data, ii_size);

  /*  Identification de l'index correspondant à la fréquence de coupure */
  st.site = &h_emlrtRSI;
  Fc_size_idx_0 = ii_size[0];
  loop_ub = ii_size[0];
  for (i = 0; i < loop_ub; i++) {
    k = ii_data[i];
    if ((k < 1) || (k > F->size[0])) {
      emlrtDynamicBoundsCheckR2012b(k, 1, F->size[0], &g_emlrtBCI, &st);
    }

    Fc_data[i] = F->data[k - 1];
  }

  emxFree_real_T(&F);
  b_st.site = &qe_emlrtRSI;
  nx = ii_size[0];
  c_st.site = &he_emlrtRSI;
  for (k = 0; k < nx; k++) {
    Fc_data[0] = muDoubleScalarRound(Fc_data[0]);
  }

  /*  Fréquence de coupure */
  st.site = &i_emlrtRSI;
  for (i = 0; i < Fc_size_idx_0; i++) {
    Fc_data[i] /= 500.0;
  }

  b_st.site = &ve_emlrtRSI;
  c_st.site = &be_emlrtRSI;
  if (ii_size[0] != 1) {
    emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  dv[0] = 0.04;
  dv[1] = Fc_data[0];
  st.site = &i_emlrtRSI;
  butter(&st, dv, b, a);

  /*  Filtre passe-bande (20 Hz à Fc) */
  st.site = &j_emlrtRSI;
  filtfilt(SD, &st, b, a, SD->f4.X, SD->f4.Y);

  /*  Filtre d'ordre 2 */
  /*     %% 4-Rectifier */
  for (k = 0; k < 60501; k++) {
    Rect[k] = muDoubleScalarAbs(SD->f4.Y[k]);
  }

  /*  Rectification par valeur absolue */
  st.site = &k_emlrtRSI;
  b_st.site = &kj_emlrtRSI;
  c_st.site = &lj_emlrtRSI;
  d_st.site = &mj_emlrtRSI;
  e_st.site = &td_emlrtRSI;
  f_st.site = &nj_emlrtRSI;
  for (k = 0; k < 60501; k++) {
    if (k + 1 <= 50) {
      nx = -51;
    } else {
      nx = k - 101;
    }

    if (k + 51 > 60501) {
      loop_ub = 60450;
    } else {
      loop_ub = k;
    }

    loop_ub -= nx;
    if (loop_ub == 0) {
      totalX = 0.0;
    } else {
      totalX = Rect[nx + 51];
      for (Fc_size_idx_0 = 2; Fc_size_idx_0 <= loop_ub; Fc_size_idx_0++) {
        totalX += Rect[(nx + Fc_size_idx_0) + 50];
      }
    }

    MAW1[k] = totalX / (real_T)loop_ub;
  }

  emxInit_real_T(&f_st, &jk_emlrtRSI, 1, &eb_emlrtRTEI, true);

  /*  Moyenne mobile centrée #1 */
  st.site = &l_emlrtRSI;
  movmean(Rect, MAW2);

  /*  Moyenne mobile centrée #2 */
  st.site = &m_emlrtRSI;
  b_movmean(Rect, MAW3);

  /*  Moyenne mobile centrée #3 */
  /*     %% 5-Analyser */
  st.site = &n_emlrtRSI;
  findpeaks(&st, MAW1, jk_emlrtRSI);

  /*  Identifier les pics */
  trecov = 0.0;
  tpush = 0.0;
  totalX = Rect[0];
  emxFree_real_T(&jk_emlrtRSI);
  for (k = 0; k < 60500; k++) {
    totalX += Rect[k + 1];
  }

  totalX /= 60501.0;
  for (nx = 0; nx < 56211; nx++) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, MAW1[nx] < totalX)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
      trecov += 0.001;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
      tpush += 0.001;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  *TempsPousse = tpush / 128.0;
  emlrtDisplayR2012b(emlrt_marshallOut(*TempsPousse), "TempsPousse", &emlrtRTEI,
                     sp);
  *TempsRecov = trecov / 128.0;
  emlrtDisplayR2012b(emlrt_marshallOut(*TempsRecov), "TempsRecov", &b_emlrtRTEI,
                     sp);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (TraitementEMGV1.c) */
