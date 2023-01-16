/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: detrend.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "detrend.h"
#include "qr.h"
#include "rt_nonfinite.h"
#include "trisolve.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void CPPDetrend(const double x[60501], double bp, const double s[60501],
  double y[60501]);

/* Function Definitions */
/*
 * Arguments    : const double x[60501]
 *                double bp
 *                const double s[60501]
 *                double y[60501]
 * Return Type  : void
 */
static void CPPDetrend(const double x[60501], double bp, const double s[60501],
  double y[60501])
{
  static double Q[121002];
  static double W[121002];
  double R[4];
  double QtxdR[2];
  double d;
  double d1;
  int b_i;
  int i;
  for (i = 0; i < 60501; i++) {
    W[i] = fmax((s[i] - bp) / s[60500], 0.0);
    W[i + 60501] = 1.0;
  }

  qr(W, Q, R);
  for (i = 0; i < 2; i++) {
    d = 0.0;
    for (b_i = 0; b_i < 60501; b_i++) {
      d += Q[b_i + 60501 * i] * x[b_i];
    }

    QtxdR[i] = d;
  }

  trisolve(R, QtxdR);
  d = QtxdR[0];
  d1 = QtxdR[1];
  for (b_i = 0; b_i < 60501; b_i++) {
    y[b_i] = x[b_i] - (W[b_i] * d + W[b_i + 60501] * d1);
  }
}

/*
 * Arguments    : const double x[60501]
 *                double y[60501]
 * Return Type  : void
 */
void detrend(const double x[60501], double y[60501])
{
  static double s[60501];
  static int b_y[60501];
  int k;
  int yk;
  b_y[0] = 0;
  yk = 0;
  for (k = 0; k < 60500; k++) {
    yk++;
    b_y[k + 1] = yk;
  }

  for (yk = 0; yk < 60501; yk++) {
    s[yk] = b_y[yk];
  }

  CPPDetrend(x, s[0], s, y);
}

/*
 * File trailer for detrend.c
 *
 * [EOF]
 */
