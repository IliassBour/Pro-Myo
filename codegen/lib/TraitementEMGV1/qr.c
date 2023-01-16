/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: qr.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "qr.h"
#include "rt_nonfinite.h"
#include "xgeqrf.h"
#include "xorgqr.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[121002]
 *                double Q[121002]
 *                double R[4]
 * Return Type  : void
 */
void qr(const double A[121002], double Q[121002], double R[4])
{
  static double b_A[121002];
  double tau[2];
  int i;
  memcpy(&b_A[0], &A[0], 121002U * sizeof(double));
  xgeqrf(b_A, tau);
  R[0] = b_A[0];
  R[1] = 0.0;
  for (i = 0; i < 2; i++) {
    R[i + 2] = b_A[i + 60501];
  }

  xorgqr(b_A, tau);
  for (i = 0; i < 2; i++) {
    memcpy(&Q[i * 60501], &b_A[i * 60501], 60501U * sizeof(double));
  }
}

/*
 * File trailer for qr.c
 *
 * [EOF]
 */
