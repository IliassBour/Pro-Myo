/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * findpeaks.c
 *
 * Code generation for function 'findpeaks'
 *
 */

/* Include files */
#include "findpeaks.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "eml_setop.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pj_emlrtRSI = { 151,/* lineNo */
  "findpeaks",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo qj_emlrtRSI = { 152,/* lineNo */
  "findpeaks",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo rj_emlrtRSI = { 162,/* lineNo */
  "findpeaks",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo sj_emlrtRSI = { 166,/* lineNo */
  "findpeaks",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo tj_emlrtRSI = { 170,/* lineNo */
  "findpeaks",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo uj_emlrtRSI = { 534,/* lineNo */
  "removeSmallPeaks",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo vj_emlrtRSI = { 795,/* lineNo */
  "combinePeaks",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo wj_emlrtRSI = { 23, /* lineNo */
  "union",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\union.m"/* pathName */
};

static emlrtRSInfo xj_emlrtRSI = { 70, /* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo ek_emlrtRSI = { 868,/* lineNo */
  "findPeaksSeparatedByMoreThanMinPeakDistance",/* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo fk_emlrtRSI = { 81, /* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo hk_emlrtRSI = { 921,/* lineNo */
  "keepAtMostNpPeaks",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  173,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  541,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "removeSmallPeaks",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  535,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "removeSmallPeaks",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  472,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "getAllPeaksCodegen",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  480,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "getAllPeaksCodegen",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  494,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "getAllPeaksCodegen",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  506,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "getAllPeaksCodegen",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  485,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "getAllPeaksCodegen",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  458,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "getAllPeaksCodegen",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  60501,                               /* iLast */
  536,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "removeSmallPeaks",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  60501,                               /* iLast */
  538,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "removeSmallPeaks",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  60501,                               /* iLast */
  538,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "removeSmallPeaks",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  545,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "removeSmallPeaks",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  545,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "removeSmallPeaks",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo fc_emlrtRTEI = { 422,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 423,/* lineNo */
  23,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 424,/* lineNo */
  27,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 509,/* lineNo */
  7,                                   /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 510,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 531,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 545,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 150,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 166,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 921,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = { 936,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 170,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 152,/* lineNo */
  11,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 868,/* lineNo */
  10,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 794,/* lineNo */
  40,                                  /* colNo */
  "findpeaks",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

/* Function Declarations */
static void combinePeaks(const emlrtStack *sp, const emxArray_int32_T *iPk,
  const emxArray_int32_T *iInf, emxArray_int32_T *iPkOut);

/* Function Definitions */
static void combinePeaks(const emlrtStack *sp, const emxArray_int32_T *iPk,
  const emxArray_int32_T *iInf, emxArray_int32_T *iPkOut)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *ia;
  emxArray_int32_T *ib;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &ia, 1, &uc_emlrtRTEI, true);
  emxInit_int32_T(sp, &ib, 1, &uc_emlrtRTEI, true);
  st.site = &vj_emlrtRSI;
  b_st.site = &wj_emlrtRSI;
  c_st.site = &xj_emlrtRSI;
  do_vectors(&c_st, iPk, iInf, iPkOut, ia, ib);
  emxFree_int32_T(&ib);
  emxFree_int32_T(&ia);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void findpeaks(const emlrtStack *sp, const real_T Yin[60501], emxArray_real_T
               *Ypk)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *b_idx;
  emxArray_int32_T *iInfinite;
  emxArray_int32_T *iInflect;
  emxArray_int32_T *iPk;
  emxArray_int32_T *idx;
  emxArray_int32_T *y;
  emxArray_uint16_T *b_iFinite;
  emxArray_uint16_T *iFinite;
  real_T yk;
  real_T ykfirst;
  int32_T i;
  int32_T k;
  int32_T kfirst;
  int32_T nInf;
  int32_T nInflect;
  int32_T nPk;
  char_T dir;
  char_T previousdir;
  boolean_T isinfyk;
  boolean_T isinfykfirst;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &iInflect, 1, &rc_emlrtRTEI, true);
  emxInit_uint16_T(sp, &iFinite, 1, &ic_emlrtRTEI, true);
  emxInit_int32_T(sp, &iInfinite, 1, &jc_emlrtRTEI, true);
  st.site = &pj_emlrtRSI;
  i = iFinite->size[0];
  iFinite->size[0] = 60501;
  emxEnsureCapacity_uint16_T(&st, iFinite, i, &fc_emlrtRTEI);
  i = iInfinite->size[0];
  iInfinite->size[0] = 60501;
  emxEnsureCapacity_int32_T(&st, iInfinite, i, &gc_emlrtRTEI);
  i = iInflect->size[0];
  iInflect->size[0] = 60501;
  emxEnsureCapacity_int32_T(&st, iInflect, i, &hc_emlrtRTEI);
  nPk = 0;
  nInf = 0;
  nInflect = 0;
  dir = 'n';
  kfirst = 0;
  ykfirst = rtInf;
  isinfykfirst = true;
  for (k = 0; k < 60501; k++) {
    yk = Yin[k];
    if (muDoubleScalarIsNaN(yk)) {
      yk = rtInf;
      isinfyk = true;
    } else if (muDoubleScalarIsInf(yk) && (yk > 0.0)) {
      isinfyk = true;
      nInf++;
      if (nInf > 60501) {
        emlrtDynamicBoundsCheckR2012b(60502, 1, 60501, &r_emlrtBCI, &st);
      }

      iInfinite->data[nInf - 1] = k + 1;
    } else {
      isinfyk = false;
    }

    if (yk != ykfirst) {
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
        if (kfirst >= 1) {
          nInflect++;
          if (nInflect > 60501) {
            emlrtDynamicBoundsCheckR2012b(60502, 1, 60501, &m_emlrtBCI, &st);
          }

          iInflect->data[nInflect - 1] = kfirst;
        }
      } else if (yk < ykfirst) {
        dir = 'd';
        if ('d' != previousdir) {
          nInflect++;
          if (nInflect > 60501) {
            emlrtDynamicBoundsCheckR2012b(60502, 1, 60501, &n_emlrtBCI, &st);
          }

          iInflect->data[nInflect - 1] = kfirst;
          if (previousdir == 'i') {
            nPk++;
            if (nPk > 60501) {
              emlrtDynamicBoundsCheckR2012b(60502, 1, 60501, &q_emlrtBCI, &st);
            }

            iFinite->data[nPk - 1] = (uint16_T)kfirst;
          }
        }
      } else {
        dir = 'i';
        if ('i' != previousdir) {
          nInflect++;
          if (nInflect > 60501) {
            emlrtDynamicBoundsCheckR2012b(60502, 1, 60501, &o_emlrtBCI, &st);
          }

          iInflect->data[nInflect - 1] = kfirst;
        }
      }

      ykfirst = yk;
      kfirst = k + 1;
      isinfykfirst = isinfyk;
    }
  }

  if ((!isinfykfirst) && ((nInflect == 0) || (iInflect->data[nInflect - 1] <
        60501)) && (nInflect + 1 > 60501)) {
    emlrtDynamicBoundsCheckR2012b(nInflect + 1, 1, 60501, &p_emlrtBCI, &st);
  }

  emxInit_uint16_T(&st, &b_iFinite, 1, &ic_emlrtRTEI, true);
  if (1 > nPk) {
    nInflect = 0;
  } else {
    nInflect = nPk;
  }

  i = b_iFinite->size[0];
  b_iFinite->size[0] = nInflect;
  emxEnsureCapacity_uint16_T(&st, b_iFinite, i, &ic_emlrtRTEI);
  for (i = 0; i < nInflect; i++) {
    b_iFinite->data[i] = iFinite->data[i];
  }

  i = iFinite->size[0];
  iFinite->size[0] = b_iFinite->size[0];
  emxEnsureCapacity_uint16_T(&st, iFinite, i, &ic_emlrtRTEI);
  nInflect = b_iFinite->size[0];
  for (i = 0; i < nInflect; i++) {
    iFinite->data[i] = b_iFinite->data[i];
  }

  emxFree_uint16_T(&b_iFinite);
  if (1 > nInf) {
    nInflect = 0;
  } else {
    nInflect = nInf;
  }

  i = iInflect->size[0];
  iInflect->size[0] = nInflect;
  emxEnsureCapacity_int32_T(&st, iInflect, i, &jc_emlrtRTEI);
  for (i = 0; i < nInflect; i++) {
    iInflect->data[i] = (uint16_T)iInfinite->data[i];
  }

  i = iInfinite->size[0];
  iInfinite->size[0] = iInflect->size[0];
  emxEnsureCapacity_int32_T(&st, iInfinite, i, &jc_emlrtRTEI);
  nInflect = iInflect->size[0];
  for (i = 0; i < nInflect; i++) {
    iInfinite->data[i] = iInflect->data[i];
  }

  st.site = &qj_emlrtRSI;
  i = iInflect->size[0];
  iInflect->size[0] = iFinite->size[0];
  emxEnsureCapacity_int32_T(&st, iInflect, i, &kc_emlrtRTEI);
  nPk = 0;
  kfirst = iFinite->size[0];
  b_st.site = &uj_emlrtRSI;
  for (k = 0; k < kfirst; k++) {
    if ((k + 1 < 1) || (k + 1 > iFinite->size[0])) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, iFinite->size[0], &l_emlrtBCI, &st);
    }

    if ((iFinite->data[k] < 1) || (iFinite->data[k] > 60501)) {
      emlrtDynamicBoundsCheckR2012b(iFinite->data[k], 1, 60501, &s_emlrtBCI, &st);
    }

    i = iFinite->data[k] - 1;
    ykfirst = Yin[i];
    if (ykfirst > rtMinusInf) {
      if ((i < 1) || (i > 60501)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 60501, &t_emlrtBCI, &st);
      }

      i = iFinite->data[k] + 1;
      if (i > 60501) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 60501, &u_emlrtBCI, &st);
      }

      if (ykfirst - muDoubleScalarMax(Yin[iFinite->data[k] - 2], Yin
           [iFinite->data[k]]) >= 0.0) {
        nPk++;
        if ((nPk < 1) || (nPk > iInflect->size[0])) {
          emlrtDynamicBoundsCheckR2012b(nPk, 1, iInflect->size[0], &k_emlrtBCI,
            &st);
        }

        iInflect->data[nPk - 1] = iFinite->data[k];
      }
    }
  }

  emxFree_uint16_T(&iFinite);
  if (1 > nPk) {
    nPk = 0;
  } else {
    if (1 > iInflect->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, iInflect->size[0], &v_emlrtBCI, &st);
    }

    if (nPk > iInflect->size[0]) {
      emlrtDynamicBoundsCheckR2012b(nPk, 1, iInflect->size[0], &w_emlrtBCI, &st);
    }
  }

  emxInit_int32_T(&st, &iPk, 1, &sc_emlrtRTEI, true);
  emxInit_int32_T(&st, &y, 2, &tc_emlrtRTEI, true);
  i = iInflect->size[0];
  iInflect->size[0] = nPk;
  emxEnsureCapacity_int32_T(&st, iInflect, i, &lc_emlrtRTEI);
  st.site = &rj_emlrtRSI;
  combinePeaks(&st, iInflect, iInfinite, iPk);
  st.site = &sj_emlrtRSI;
  b_st.site = &ek_emlrtRSI;
  c_st.site = &fe_emlrtRSI;
  d_st.site = &fk_emlrtRSI;
  if (iPk->size[0] < 1) {
    kfirst = 0;
  } else {
    kfirst = iPk->size[0];
  }

  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = kfirst;
  emxEnsureCapacity_int32_T(&d_st, y, i, &mc_emlrtRTEI);
  emxFree_int32_T(&iInfinite);
  emxFree_int32_T(&iInflect);
  if (kfirst > 0) {
    y->data[0] = 1;
    nInflect = 1;
    for (k = 2; k <= kfirst; k++) {
      nInflect++;
      y->data[k - 1] = nInflect;
    }
  }

  emxInit_int32_T(&d_st, &idx, 1, &nc_emlrtRTEI, true);
  i = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(&st, idx, i, &nc_emlrtRTEI);
  nInflect = y->size[1];
  for (i = 0; i < nInflect; i++) {
    idx->data[i] = y->data[i];
  }

  emxFree_int32_T(&y);
  st.site = &tj_emlrtRSI;
  if (idx->size[0] > 60501) {
    emxInit_int32_T(&st, &b_idx, 1, &oc_emlrtRTEI, true);
    b_st.site = &hk_emlrtRSI;
    b_indexShapeCheck(&b_st, idx->size[0]);
    i = b_idx->size[0];
    b_idx->size[0] = 60501;
    emxEnsureCapacity_int32_T(&st, b_idx, i, &oc_emlrtRTEI);
    for (i = 0; i < 60501; i++) {
      b_idx->data[i] = idx->data[i];
    }

    i = idx->size[0];
    idx->size[0] = b_idx->size[0];
    emxEnsureCapacity_int32_T(&st, idx, i, &qc_emlrtRTEI);
    nInflect = b_idx->size[0];
    for (i = 0; i < nInflect; i++) {
      idx->data[i] = b_idx->data[i];
    }

    emxFree_int32_T(&b_idx);
  }

  nInflect = idx->size[0];
  for (i = 0; i < nInflect; i++) {
    if ((idx->data[i] < 1) || (idx->data[i] > iPk->size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx->data[i], 1, iPk->size[0], &j_emlrtBCI,
        sp);
    }
  }

  i = Ypk->size[0];
  Ypk->size[0] = idx->size[0];
  emxEnsureCapacity_real_T(sp, Ypk, i, &pc_emlrtRTEI);
  nInflect = idx->size[0];
  for (i = 0; i < nInflect; i++) {
    Ypk->data[i] = Yin[iPk->data[idx->data[i] - 1] - 1];
  }

  emxFree_int32_T(&iPk);
  emxFree_int32_T(&idx);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (findpeaks.c) */
