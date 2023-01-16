/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "eig.h"
#include "TraitementEMGV1_data.h"
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xdhseqr.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 81, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 68, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 53, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 41, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 20, /* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 93, /* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 139,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 147,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 21, /* lineNo */
  "eigHermitianStandard",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHermitianStandard.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 35, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 52, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 54, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo wg_emlrtRSI = { 83, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo xg_emlrtRSI = { 18, /* lineNo */
  "xgehrd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgehrd.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 31, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 35, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo bh_emlrtRSI = { 43, /* lineNo */
  "xzgehrd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgehrd.m"/* pathName */
};

static emlrtRSInfo ch_emlrtRSI = { 84, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 91, /* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 58, /* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 32, /* lineNo */
  "xhseqr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 13, /* lineNo */
  "xdhseqr",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo yh_emlrtRSI = { 59, /* lineNo */
  "eigStandard",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStandard.m"/* pathName */
};

static emlrtRSInfo ai_emlrtRSI = { 44, /* lineNo */
  "eigStandard",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStandard.m"/* pathName */
};

static emlrtRSInfo bi_emlrtRSI = { 38, /* lineNo */
  "xgeev",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

static emlrtRSInfo ci_emlrtRSI = { 143,/* lineNo */
  "ceval_xgeev",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

/* Function Definitions */
void eig(const emlrtStack *sp, const real_T A[16], creal_T V[4])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 'e', 'v', 'x' };

  ptrdiff_t ihi_t;
  ptrdiff_t ilo_t;
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack st;
  real_T T[16];
  real_T scale[4];
  real_T wimag[4];
  real_T wreal[4];
  real_T tau[3];
  real_T abnrm;
  real_T rconde;
  real_T rcondv;
  real_T vleft;
  real_T vright;
  int32_T alpha1_tmp;
  int32_T b;
  int32_T b_i;
  int32_T exitg1;
  int32_T i;
  int32_T iac;
  int32_T ic0;
  int32_T im1n_tmp_tmp;
  int32_T in;
  int32_T ix;
  int32_T j;
  int32_T knt;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mg_emlrtRSI;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  if (anyNonFinite(A)) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
    V[2].re = rtNaN;
    V[2].im = 0.0;
    V[3].re = rtNaN;
    V[3].im = 0.0;
  } else {
    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 4)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= j) {
          if (!(A[i + (j << 2)] == A[j + (i << 2)])) {
            p = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (p) {
      st.site = &ng_emlrtRSI;
      b_st.site = &sg_emlrtRSI;
      memcpy(&T[0], &A[0], 16U * sizeof(real_T));
      c_st.site = &tg_emlrtRSI;
      if (anyNonFinite(A)) {
        for (b_i = 0; b_i < 16; b_i++) {
          T[b_i] = rtNaN;
        }

        b_i = 2;
        for (j = 0; j < 3; j++) {
          if (b_i <= 4) {
            memset(&T[(j * 4 + b_i) + -1], 0, (5 - b_i) * sizeof(real_T));
          }

          b_i++;
        }
      } else {
        c_st.site = &ug_emlrtRSI;
        d_st.site = &xg_emlrtRSI;
        scale[0] = 0.0;
        scale[1] = 0.0;
        scale[2] = 0.0;
        scale[3] = 0.0;
        for (i = 0; i < 3; i++) {
          im1n_tmp_tmp = i << 2;
          in = (i + 1) << 2;
          alpha1_tmp = (i + im1n_tmp_tmp) + 1;
          vright = T[alpha1_tmp];
          b_i = i + 3;
          b_i = muIntScalarMin_sint32(b_i, 4) + im1n_tmp_tmp;
          e_st.site = &yg_emlrtRSI;
          tau[i] = 0.0;
          f_st.site = &kb_emlrtRSI;
          vleft = xnrm2(&f_st, 2 - i, T, b_i);
          if (vleft != 0.0) {
            vleft = muDoubleScalarHypot(vright, vleft);
            if (vright >= 0.0) {
              vleft = -vleft;
            }

            if (muDoubleScalarAbs(vleft) < 1.0020841800044864E-292) {
              knt = 0;
              do {
                knt++;
                f_st.site = &jb_emlrtRSI;
                xscal(&f_st, 2 - i, 9.9792015476736E+291, T, b_i);
                vleft *= 9.9792015476736E+291;
                vright *= 9.9792015476736E+291;
              } while ((muDoubleScalarAbs(vleft) < 1.0020841800044864E-292) &&
                       (knt < 20));

              f_st.site = &ib_emlrtRSI;
              vleft = xnrm2(&f_st, 2 - i, T, b_i);
              vleft = muDoubleScalarHypot(vright, vleft);
              if (vright >= 0.0) {
                vleft = -vleft;
              }

              tau[i] = (vleft - vright) / vleft;
              f_st.site = &hb_emlrtRSI;
              xscal(&f_st, 2 - i, 1.0 / (vright - vleft), T, b_i);
              f_st.site = &gb_emlrtRSI;
              if ((1 <= knt) && (knt > 2147483646)) {
                g_st.site = &nb_emlrtRSI;
                check_forloop_overflow_error(&g_st);
              }

              for (b_i = 0; b_i < knt; b_i++) {
                vleft *= 1.0020841800044864E-292;
              }

              vright = vleft;
            } else {
              tau[i] = (vleft - vright) / vleft;
              f_st.site = &fb_emlrtRSI;
              xscal(&f_st, 2 - i, 1.0 / (T[(i + (i << 2)) + 1] - vleft), T, b_i);
              vright = vleft;
            }
          }

          T[alpha1_tmp] = 1.0;
          ic0 = in + 1;
          e_st.site = &ah_emlrtRSI;
          if (tau[i] != 0.0) {
            lastv = 2 - i;
            b_i = (alpha1_tmp - i) + 2;
            while ((lastv + 1 > 0) && (T[b_i] == 0.0)) {
              lastv--;
              b_i--;
            }

            lastc = 4;
            exitg2 = false;
            while ((!exitg2) && (lastc > 0)) {
              knt = in + lastc;
              j = knt;
              do {
                exitg1 = 0;
                if (j <= knt + (lastv << 2)) {
                  if (T[j - 1] != 0.0) {
                    exitg1 = 1;
                  } else {
                    j += 4;
                  }
                } else {
                  lastc--;
                  exitg1 = 2;
                }
              } while (exitg1 == 0);

              if (exitg1 == 1) {
                exitg2 = true;
              }
            }
          } else {
            lastv = -1;
            lastc = 0;
          }

          if (lastv + 1 > 0) {
            f_st.site = &ch_emlrtRSI;
            g_st.site = &ub_emlrtRSI;
            if (lastc != 0) {
              h_st.site = &vb_emlrtRSI;
              if (0 <= lastc - 1) {
                memset(&scale[0], 0, lastc * sizeof(real_T));
              }

              ix = alpha1_tmp;
              b_i = (in + (lastv << 2)) + 1;
              for (iac = ic0; iac <= b_i; iac += 4) {
                knt = 0;
                b = (iac + lastc) - 1;
                h_st.site = &eh_emlrtRSI;
                for (j = iac; j <= b; j++) {
                  scale[knt] += T[j - 1] * T[ix];
                  knt++;
                }

                ix++;
              }
            }

            f_st.site = &dh_emlrtRSI;
            g_st.site = &xb_emlrtRSI;
            h_st.site = &yb_emlrtRSI;
            i_st.site = &ac_emlrtRSI;
            if (!(-tau[i] == 0.0)) {
              knt = in;
              b_i = alpha1_tmp;
              j_st.site = &bc_emlrtRSI;
              for (j = 0; j <= lastv; j++) {
                if (T[b_i] != 0.0) {
                  vleft = T[b_i] * -tau[i];
                  ix = 0;
                  ic0 = knt + 1;
                  b = lastc + knt;
                  j_st.site = &cc_emlrtRSI;
                  if ((knt + 1 <= b) && (b > 2147483646)) {
                    k_st.site = &nb_emlrtRSI;
                    check_forloop_overflow_error(&k_st);
                  }

                  for (iac = ic0; iac <= b; iac++) {
                    T[iac - 1] += scale[ix] * vleft;
                    ix++;
                  }
                }

                b_i++;
                knt += 4;
              }
            }
          }

          e_st.site = &bh_emlrtRSI;
          xzlarf(&e_st, 3 - i, 3 - i, (i + im1n_tmp_tmp) + 2, tau[i], T, (i + in)
                 + 2, scale);
          T[alpha1_tmp] = vright;
        }

        c_st.site = &vg_emlrtRSI;
        d_st.site = &fh_emlrtRSI;
        e_st.site = &gh_emlrtRSI;
        b_i = eml_dlahqr(&e_st, T);
        if (b_i != 0) {
          c_st.site = &wg_emlrtRSI;
          c_warning(&c_st);
        }
      }

      V[0].re = T[0];
      V[0].im = 0.0;
      V[1].re = T[5];
      V[1].im = 0.0;
      V[2].re = T[10];
      V[2].im = 0.0;
      V[3].re = T[15];
      V[3].im = 0.0;
    } else {
      st.site = &og_emlrtRSI;
      b_st.site = &ai_emlrtRSI;
      c_st.site = &bi_emlrtRSI;
      memcpy(&T[0], &A[0], 16U * sizeof(real_T));
      info_t = LAPACKE_dgeevx(102, 'B', 'N', 'N', 'N', (ptrdiff_t)4, &T[0],
        (ptrdiff_t)4, &wreal[0], &wimag[0], &vleft, (ptrdiff_t)1, &vright,
        (ptrdiff_t)1, &ilo_t, &ihi_t, &scale[0], &abnrm, &rconde, &rcondv);
      b_i = (int32_T)info_t;
      d_st.site = &ci_emlrtRSI;
      if (b_i < 0) {
        if (b_i == -1010) {
          emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &p_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, b_i);
        }
      }

      V[0].re = wreal[0];
      V[0].im = wimag[0];
      V[1].re = wreal[1];
      V[1].im = wimag[1];
      V[2].re = wreal[2];
      V[2].im = wimag[2];
      V[3].re = wreal[3];
      V[3].im = wimag[3];
      if (b_i != 0) {
        b_st.site = &yh_emlrtRSI;
        d_warning(&b_st);
      }
    }
  }
}

/* End of code generation (eig.c) */
