/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: poly.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "poly.h"
#include "TraitementEMGV1_rtwutil.h"
#include "eigStandard.h"
#include "rt_nonfinite.h"
#include "xhseqr.h"
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[16]
 *                creal_T c[5]
 * Return Type  : void
 */
void poly(const double x[16], creal_T c[5])
{
  creal_T V[4];
  double T[16];
  double work[4];
  double tau[3];
  double alpha1_tmp;
  double beta1;
  double d;
  double temp;
  int alpha1_tmp_tmp;
  int b_i;
  int c_i;
  int coltop;
  int exitg1;
  int i;
  int i1;
  int ia;
  int in;
  int ix;
  int jA;
  int knt;
  int lastc;
  int lastv;
  boolean_T exitg2;
  boolean_T p;
  p = true;
  for (i = 0; i < 16; i++) {
    if ((!p) || (rtIsInf(x[i]) || rtIsNaN(x[i]))) {
      p = false;
    }
  }

  if (!p) {
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
    coltop = 0;
    exitg2 = false;
    while ((!exitg2) && (coltop < 4)) {
      b_i = 0;
      do {
        exitg1 = 0;
        if (b_i <= coltop) {
          if (!(x[b_i + (coltop << 2)] == x[coltop + (b_i << 2)])) {
            p = false;
            exitg1 = 1;
          } else {
            b_i++;
          }
        } else {
          coltop++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (p) {
      p = true;
      for (i = 0; i < 16; i++) {
        temp = x[i];
        T[i] = temp;
        if ((!p) || (rtIsInf(temp) || rtIsNaN(temp))) {
          p = false;
        }
      }

      if (!p) {
        for (c_i = 0; c_i < 16; c_i++) {
          T[c_i] = rtNaN;
        }

        i = 2;
        for (coltop = 0; coltop < 3; coltop++) {
          if (i <= 4) {
            memset(&T[(coltop * 4 + i) + -1], 0, (5 - i) * sizeof(double));
          }

          i++;
        }
      } else {
        work[0] = 0.0;
        work[1] = 0.0;
        work[2] = 0.0;
        work[3] = 0.0;
        for (b_i = 0; b_i < 3; b_i++) {
          i = b_i << 2;
          in = (b_i + 1) << 2;
          alpha1_tmp_tmp = (b_i + i) + 1;
          alpha1_tmp = T[alpha1_tmp_tmp];
          if (b_i + 3 < 4) {
            lastv = b_i + 1;
          } else {
            lastv = 2;
          }

          coltop = (lastv + i) + 2;
          tau[b_i] = 0.0;
          temp = b_xnrm2(2 - b_i, T, coltop);
          if (temp != 0.0) {
            beta1 = rt_hypotd_snf(alpha1_tmp, temp);
            if (alpha1_tmp >= 0.0) {
              beta1 = -beta1;
            }

            if (fabs(beta1) < 1.0020841800044864E-292) {
              knt = 0;
              c_i = (coltop - b_i) + 1;
              do {
                knt++;
                for (i = coltop; i <= c_i; i++) {
                  T[i - 1] *= 9.9792015476736E+291;
                }

                beta1 *= 9.9792015476736E+291;
                alpha1_tmp *= 9.9792015476736E+291;
              } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

              beta1 = rt_hypotd_snf(alpha1_tmp, b_xnrm2(2 - b_i, T, coltop));
              if (alpha1_tmp >= 0.0) {
                beta1 = -beta1;
              }

              tau[b_i] = (beta1 - alpha1_tmp) / beta1;
              temp = 1.0 / (alpha1_tmp - beta1);
              c_i = (coltop - b_i) + 1;
              for (i = coltop; i <= c_i; i++) {
                T[i - 1] *= temp;
              }

              for (i = 0; i < knt; i++) {
                beta1 *= 1.0020841800044864E-292;
              }

              alpha1_tmp = beta1;
            } else {
              tau[b_i] = (beta1 - alpha1_tmp) / beta1;
              temp = 1.0 / (alpha1_tmp - beta1);
              c_i = (coltop - b_i) + 1;
              for (i = coltop; i <= c_i; i++) {
                T[i - 1] *= temp;
              }

              alpha1_tmp = beta1;
            }
          }

          T[alpha1_tmp_tmp] = 1.0;
          coltop = in + 1;
          if (tau[b_i] != 0.0) {
            lastv = 2 - b_i;
            i = (alpha1_tmp_tmp - b_i) + 2;
            while ((lastv + 1 > 0) && (T[i] == 0.0)) {
              lastv--;
              i--;
            }

            lastc = 4;
            exitg2 = false;
            while ((!exitg2) && (lastc > 0)) {
              knt = in + lastc;
              ia = knt;
              do {
                exitg1 = 0;
                if (ia <= knt + (lastv << 2)) {
                  if (T[ia - 1] != 0.0) {
                    exitg1 = 1;
                  } else {
                    ia += 4;
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
            if (lastc != 0) {
              if (0 <= lastc - 1) {
                memset(&work[0], 0, lastc * sizeof(double));
              }

              ix = alpha1_tmp_tmp;
              c_i = (in + (lastv << 2)) + 1;
              for (knt = coltop; knt <= c_i; knt += 4) {
                i = 0;
                i1 = (knt + lastc) - 1;
                for (ia = knt; ia <= i1; ia++) {
                  work[i] += T[ia - 1] * T[ix];
                  i++;
                }

                ix++;
              }
            }

            if (!(-tau[b_i] == 0.0)) {
              jA = in;
              knt = alpha1_tmp_tmp;
              for (coltop = 0; coltop <= lastv; coltop++) {
                if (T[knt] != 0.0) {
                  temp = T[knt] * -tau[b_i];
                  ix = 0;
                  c_i = jA + 1;
                  i1 = lastc + jA;
                  for (i = c_i; i <= i1; i++) {
                    T[i - 1] += work[ix] * temp;
                    ix++;
                  }
                }

                knt++;
                jA += 4;
              }
            }
          }

          jA = (b_i + in) + 2;
          if (tau[b_i] != 0.0) {
            lastv = 3 - b_i;
            i = (alpha1_tmp_tmp - b_i) + 2;
            while ((lastv > 0) && (T[i] == 0.0)) {
              lastv--;
              i--;
            }

            lastc = 2 - b_i;
            exitg2 = false;
            while ((!exitg2) && (lastc + 1 > 0)) {
              coltop = jA + (lastc << 2);
              ia = coltop;
              do {
                exitg1 = 0;
                if (ia <= (coltop + lastv) - 1) {
                  if (T[ia - 1] != 0.0) {
                    exitg1 = 1;
                  } else {
                    ia++;
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
            lastv = 0;
            lastc = -1;
          }

          if (lastv > 0) {
            if (lastc + 1 != 0) {
              if (0 <= lastc) {
                memset(&work[0], 0, (lastc + 1) * sizeof(double));
              }

              i = 0;
              c_i = jA + (lastc << 2);
              for (knt = jA; knt <= c_i; knt += 4) {
                ix = alpha1_tmp_tmp;
                temp = 0.0;
                i1 = (knt + lastv) - 1;
                for (ia = knt; ia <= i1; ia++) {
                  temp += T[ia - 1] * T[ix];
                  ix++;
                }

                work[i] += temp;
                i++;
              }
            }

            if (!(-tau[b_i] == 0.0)) {
              knt = 0;
              for (coltop = 0; coltop <= lastc; coltop++) {
                if (work[knt] != 0.0) {
                  temp = work[knt] * -tau[b_i];
                  ix = alpha1_tmp_tmp;
                  c_i = lastv + jA;
                  for (i = jA; i < c_i; i++) {
                    T[i - 1] += T[ix] * temp;
                    ix++;
                  }
                }

                knt++;
                jA += 4;
              }
            }
          }

          T[alpha1_tmp_tmp] = alpha1_tmp;
        }

        xhseqr(T);
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
      eigStandard(x, V);
    }
  }

  c[0].re = 1.0;
  c[0].im = 0.0;
  c[1].re = -V[0].re - -V[0].im * 0.0;
  c[1].im = -V[0].re * 0.0 + -V[0].im;
  c[2].re = -V[1].re * c[1].re - -V[1].im * c[1].im;
  c[2].im = -V[1].re * c[1].im + -V[1].im * c[1].re;
  temp = V[1].re;
  beta1 = V[1].im;
  for (i = 2; i >= 2; i--) {
    c[1].re -= temp - beta1 * 0.0;
    c[1].im -= temp * 0.0 + beta1;
  }

  c[3].re = -V[2].re * c[2].re - -V[2].im * c[2].im;
  c[3].im = -V[2].re * c[2].im + -V[2].im * c[2].re;
  temp = V[2].re;
  beta1 = V[2].im;
  for (i = 3; i >= 2; i--) {
    alpha1_tmp = c[i - 2].im;
    d = c[i - 2].re;
    c[i - 1].re -= temp * d - beta1 * alpha1_tmp;
    c[i - 1].im -= temp * alpha1_tmp + beta1 * d;
  }

  c[4].re = -V[3].re * c[3].re - -V[3].im * c[3].im;
  c[4].im = -V[3].re * c[3].im + -V[3].im * c[3].re;
  temp = V[3].re;
  beta1 = V[3].im;
  for (i = 4; i >= 2; i--) {
    alpha1_tmp = c[i - 2].im;
    d = c[i - 2].re;
    c[i - 1].re -= temp * d - beta1 * alpha1_tmp;
    c[i - 1].im -= temp * alpha1_tmp + beta1 * d;
  }
}

/*
 * File trailer for poly.c
 *
 * [EOF]
 */
