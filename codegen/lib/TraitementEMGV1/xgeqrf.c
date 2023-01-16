/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgeqrf.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "xgeqrf.h"
#include "TraitementEMGV1_rtwutil.h"
#include "rt_nonfinite.h"
#include "xgerc.h"
#include "xnrm2.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double A[121002]
 *                double tau[2]
 * Return Type  : void
 */
void xgeqrf(double A[121002], double tau[2])
{
  double work[2];
  double atmp;
  double beta1;
  double c;
  int exitg1;
  int i;
  int ia;
  int iac;
  int ix;
  int k;
  int knt;
  int lastv;
  work[0] = 0.0;
  work[1] = 0.0;
  atmp = A[0];
  tau[0] = 0.0;
  c = xnrm2(60500, A, 2);
  if (c != 0.0) {
    beta1 = rt_hypotd_snf(A[0], c);
    if (A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (k = 2; k < 60502; k++) {
          A[k - 1] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(atmp, xnrm2(60500, A, 2));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau[0] = (beta1 - atmp) / beta1;
      c = 1.0 / (atmp - beta1);
      for (k = 2; k < 60502; k++) {
        A[k - 1] *= c;
      }

      for (k = 0; k < knt; k++) {
        beta1 *= 1.0020841800044864E-292;
      }

      atmp = beta1;
    } else {
      tau[0] = (beta1 - A[0]) / beta1;
      c = 1.0 / (A[0] - beta1);
      for (k = 2; k < 60502; k++) {
        A[k - 1] *= c;
      }

      atmp = beta1;
    }
  }

  A[0] = atmp;
  atmp = A[0];
  A[0] = 1.0;
  if (tau[0] != 0.0) {
    lastv = 60501;
    knt = 60500;
    while ((lastv > 0) && (A[knt] == 0.0)) {
      lastv--;
      knt--;
    }

    knt = 1;
    ia = 60501;
    do {
      exitg1 = 0;
      if (ia + 1 <= lastv + 60501) {
        if (A[ia] != 0.0) {
          exitg1 = 1;
        } else {
          ia++;
        }
      } else {
        knt = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    lastv = 0;
    knt = 0;
  }

  if (lastv > 0) {
    if (knt != 0) {
      work[0] = 0.0;
      k = 0;
      i = lastv + 60501;
      for (iac = 60502; iac <= 60502; iac += 60501) {
        ix = 0;
        c = 0.0;
        for (ia = 60502; ia <= i; ia++) {
          c += A[ia - 1] * A[ix];
          ix++;
        }

        work[k] += c;
        k++;
      }
    }

    xgerc(lastv, knt, -tau[0], 1, work, A, 60502);
  }

  A[0] = atmp;
  atmp = A[60502];
  tau[1] = 0.0;
  c = xnrm2(60499, A, 60504);
  if (c != 0.0) {
    beta1 = rt_hypotd_snf(A[60502], c);
    if (A[60502] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (k = 60504; k < 121003; k++) {
          A[k - 1] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        atmp *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(atmp, xnrm2(60499, A, 60504));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau[1] = (beta1 - atmp) / beta1;
      c = 1.0 / (atmp - beta1);
      for (k = 60504; k < 121003; k++) {
        A[k - 1] *= c;
      }

      for (k = 0; k < knt; k++) {
        beta1 *= 1.0020841800044864E-292;
      }

      atmp = beta1;
    } else {
      tau[1] = (beta1 - A[60502]) / beta1;
      c = 1.0 / (A[60502] - beta1);
      for (k = 60504; k < 121003; k++) {
        A[k - 1] *= c;
      }

      atmp = beta1;
    }
  }

  A[60502] = atmp;
}

/*
 * File trailer for xgeqrf.c
 *
 * [EOF]
 */
