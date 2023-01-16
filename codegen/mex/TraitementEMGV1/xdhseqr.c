/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdhseqr.c
 *
 * Code generation for function 'xdhseqr'
 *
 */

/* Include files */
#include "xdhseqr.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xrot.h"
#include "xzlarfg.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kh_emlrtRSI = { 263,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo oh_emlrtRSI = { 359,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

static emlrtRSInfo ph_emlrtRSI = { 365,/* lineNo */
  "eml_dlahqr",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xdhseqr.m"/* pathName */
};

/* Function Definitions */
int32_T eml_dlahqr(const emlrtStack *sp, real_T h[16])
{
  emlrtStack st;
  real_T v[3];
  real_T aa;
  real_T ab;
  real_T ba;
  real_T bb;
  real_T rt1r;
  real_T rt2r;
  real_T s;
  real_T s_tmp;
  real_T tst;
  int32_T L;
  int32_T b;
  int32_T b_k;
  int32_T hoffset;
  int32_T i;
  int32_T info;
  int32_T its;
  int32_T j;
  int32_T k;
  int32_T kdefl;
  int32_T m;
  int32_T nr;
  int32_T sum1_tmp;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T goto150;
  st.prev = sp;
  st.tls = sp->tls;
  info = 0;
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 0.0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[7] = 0.0;
  kdefl = 0;
  i = 3;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    L = 1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L)) {
        hoffset = k + ((k - 1) << 2);
        ba = muDoubleScalarAbs(h[hoffset]);
        if (ba <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          nr = k + (k << 2);
          bb = muDoubleScalarAbs(h[nr]);
          tst = muDoubleScalarAbs(h[hoffset - 1]) + bb;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h[(k + ((k - 2) << 2)) - 1]);
            }

            if (k + 2 <= 4) {
              tst += muDoubleScalarAbs(h[nr + 1]);
            }
          }

          if (ba <= 2.2204460492503131E-16 * tst) {
            tst = muDoubleScalarAbs(h[nr - 1]);
            if (ba > tst) {
              ab = ba;
              ba = tst;
            } else {
              ab = tst;
            }

            tst = muDoubleScalarAbs(h[hoffset - 1] - h[nr]);
            if (bb > tst) {
              aa = bb;
              bb = tst;
            } else {
              aa = tst;
            }

            s = aa + ab;
            if (ba * (ab / s) <= muDoubleScalarMax(4.0083367200179456E-292,
                 2.2204460492503131E-16 * (bb * (aa / s)))) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k + 1;
      if (k + 1 > 1) {
        h[k + ((k - 1) << 2)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          s = muDoubleScalarAbs(h[i + ((i - 1) << 2)]) + muDoubleScalarAbs(h[(i
            + ((i - 2) << 2)) - 1]);
          tst = 0.75 * s + h[i + (i << 2)];
          aa = -0.4375 * s;
          ab = s;
          bb = tst;
        } else if (kdefl - kdefl / 10 * 10 == 0) {
          nr = k + (k << 2);
          s = muDoubleScalarAbs(h[nr + 1]) + muDoubleScalarAbs(h[(k + ((k + 1) <<
            2)) + 2]);
          tst = 0.75 * s + h[nr];
          aa = -0.4375 * s;
          ab = s;
          bb = tst;
        } else {
          nr = i + ((i - 1) << 2);
          tst = h[nr - 1];
          ab = h[nr];
          aa = h[(i + (i << 2)) - 1];
          bb = h[i + (i << 2)];
        }

        s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(aa)) +
             muDoubleScalarAbs(ab)) + muDoubleScalarAbs(bb);
        if (s == 0.0) {
          rt1r = 0.0;
          ba = 0.0;
          rt2r = 0.0;
          bb = 0.0;
        } else {
          tst /= s;
          ab /= s;
          aa /= s;
          bb /= s;
          ba = (tst + bb) / 2.0;
          tst = (tst - ba) * (bb - ba) - aa * ab;
          ab = muDoubleScalarSqrt(muDoubleScalarAbs(tst));
          if (tst >= 0.0) {
            rt1r = ba * s;
            rt2r = rt1r;
            ba = ab * s;
            bb = -ba;
          } else {
            rt1r = ba + ab;
            rt2r = ba - ab;
            if (muDoubleScalarAbs(rt1r - bb) <= muDoubleScalarAbs(rt2r - bb)) {
              rt1r *= s;
              rt2r = rt1r;
            } else {
              rt2r *= s;
              rt1r = rt2r;
            }

            ba = 0.0;
            bb = 0.0;
          }
        }

        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          nr = m + ((m - 1) << 2);
          tst = h[nr];
          s_tmp = h[nr - 1];
          ab = s_tmp - rt2r;
          s = (muDoubleScalarAbs(ab) + muDoubleScalarAbs(bb)) +
            muDoubleScalarAbs(tst);
          aa = tst / s;
          nr = m + (m << 2);
          v[0] = (aa * h[nr - 1] + (s_tmp - rt1r) * (ab / s)) - ba * (bb / s);
          tst = h[nr];
          v[1] = aa * (((s_tmp + tst) - rt1r) - rt2r);
          v[2] = aa * h[nr + 1];
          s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(v[1])) +
            muDoubleScalarAbs(v[2]);
          v[0] /= s;
          v[1] /= s;
          v[2] /= s;
          if ((m == k + 1) || (muDoubleScalarAbs(h[m - 1]) * (muDoubleScalarAbs
                (v[1]) + muDoubleScalarAbs(v[2])) <= 2.2204460492503131E-16 *
                               muDoubleScalarAbs(v[0]) * ((muDoubleScalarAbs(h[0])
                 + muDoubleScalarAbs(s_tmp)) + muDoubleScalarAbs(tst)))) {
            exitg3 = true;
          } else {
            m--;
          }
        }

        for (b_k = m; b_k <= i; b_k++) {
          hoffset = (i - b_k) + 2;
          nr = muIntScalarMin_sint32(3, hoffset);
          if (b_k > m) {
            hoffset = (b_k + ((b_k - 2) << 2)) - 1;
            for (j = 0; j < nr; j++) {
              v[j] = h[j + hoffset];
            }
          }

          tst = v[0];
          st.site = &kh_emlrtRSI;
          bb = xzlarfg(&st, nr, &tst, v);
          v[0] = tst;
          if (b_k > m) {
            h[(b_k + ((b_k - 2) << 2)) - 1] = tst;
            h[b_k + ((b_k - 2) << 2)] = 0.0;
            if (b_k < i) {
              h[b_k + 1] = 0.0;
            }
          } else {
            if (m > k + 1) {
              h[b_k - 1] *= 1.0 - bb;
            }
          }

          rt1r = v[1];
          tst = bb * v[1];
          if (nr == 3) {
            s = v[2];
            ba = bb * v[2];
            for (j = b_k; j < 5; j++) {
              nr = b_k + ((j - 1) << 2);
              aa = (h[nr - 1] + rt1r * h[nr]) + s * h[nr + 1];
              h[nr - 1] -= aa * bb;
              h[nr] -= aa * tst;
              h[nr + 1] -= aa * ba;
            }

            hoffset = b_k + 3;
            nr = i + 1;
            b = muIntScalarMin_sint32(hoffset, nr);
            for (j = 0; j < b; j++) {
              nr = j + ((b_k - 1) << 2);
              ab = h[nr];
              hoffset = j + (b_k << 2);
              sum1_tmp = j + ((b_k + 1) << 2);
              aa = (ab + rt1r * h[hoffset]) + s * h[sum1_tmp];
              h[nr] = ab - aa * bb;
              h[hoffset] -= aa * tst;
              h[sum1_tmp] -= aa * ba;
            }
          } else {
            if (nr == 2) {
              for (j = b_k; j < 5; j++) {
                nr = b_k + ((j - 1) << 2);
                ab = h[nr - 1];
                aa = ab + rt1r * h[nr];
                h[nr - 1] = ab - aa * bb;
                h[nr] -= aa * tst;
              }

              for (j = 0; j <= i; j++) {
                nr = j + ((b_k - 1) << 2);
                hoffset = j + (b_k << 2);
                aa = h[nr] + rt1r * h[hoffset];
                h[nr] -= aa * bb;
                h[hoffset] -= aa * tst;
              }
            }
          }
        }

        its++;
      }
    }

    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((L != i + 1) && (L == i)) {
        hoffset = i + (i << 2);
        rt1r = h[hoffset - 1];
        nr = i + ((i - 1) << 2);
        s = h[nr];
        tst = h[hoffset];
        xdlanv2(&h[(i + ((i - 1) << 2)) - 1], &rt1r, &s, &tst, &ab, &aa, &ba,
                &bb, &s_tmp, &rt2r);
        h[hoffset - 1] = rt1r;
        h[nr] = s;
        h[hoffset] = tst;
        if (4 > i + 1) {
          st.site = &oh_emlrtRSI;
          xrot(&st, 3 - i, h, i + ((i + 1) << 2), (i + ((i + 1) << 2)) + 1,
               s_tmp, rt2r);
        }

        st.site = &ph_emlrtRSI;
        b_xrot(&st, i - 1, h, ((i - 1) << 2) + 1, (i << 2) + 1, s_tmp, rt2r);
      }

      kdefl = 0;
      i = L - 2;
    }
  }

  return info;
}

/* End of code generation (xdhseqr.c) */
