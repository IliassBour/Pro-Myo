/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xorgqr.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "xorgqr.h"
#include "rt_nonfinite.h"
#include "xgerc.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double A[121002]
 *                const double tau[2]
 * Return Type  : void
 */
void xorgqr(double A[121002], const double tau[2])
{
  double work[2];
  double c;
  int exitg1;
  int i;
  int ia;
  int iac;
  int ix;
  int iy;
  int lastc;
  int lastv;
  work[0] = 0.0;
  work[1] = 0.0;
  for (lastc = 60504; lastc < 121003; lastc++) {
    A[lastc - 1] *= -tau[1];
  }

  A[60502] = 1.0 - tau[1];
  A[60501] = 0.0;
  A[0] = 1.0;
  if (tau[0] != 0.0) {
    lastv = 60501;
    lastc = 0;
    while ((lastv > 0) && (A[lastc + 60500] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = 1;
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
        lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    if (lastc != 0) {
      work[0] = 0.0;
      iy = 0;
      i = lastv + 60501;
      for (iac = 60502; iac <= 60502; iac += 60501) {
        ix = 0;
        c = 0.0;
        for (ia = 60502; ia <= i; ia++) {
          c += A[ia - 1] * A[ix];
          ix++;
        }

        work[iy] += c;
        iy++;
      }
    }

    xgerc(lastv, lastc, -tau[0], 1, work, A, 60502);
  }

  for (lastc = 2; lastc < 60502; lastc++) {
    A[lastc - 1] *= -tau[0];
  }

  A[0] = 1.0 - tau[0];
}

/*
 * File trailer for xorgqr.c
 *
 * [EOF]
 */
