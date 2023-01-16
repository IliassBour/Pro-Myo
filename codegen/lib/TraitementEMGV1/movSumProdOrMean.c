/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movSumProdOrMean.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "movSumProdOrMean.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[60501]
 *                double y[60501]
 * Return Type  : void
 */
void b_vmovfun(const double x[60501], double y[60501])
{
  double b_y;
  int b_k;
  int iLeft;
  int k;
  int vlen;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(iLeft,b_k,vlen,b_y)

  for (k = 0; k < 60501; k++) {
    if (k + 1 <= 250) {
      iLeft = -250;
    } else {
      iLeft = k - 500;
    }

    if (k + 251 > 60501) {
      b_k = 60251;
    } else {
      b_k = k + 1;
    }

    vlen = b_k - iLeft;
    if (vlen == 0) {
      b_y = 0.0;
    } else {
      b_y = x[iLeft + 250];
      for (b_k = 2; b_k <= vlen; b_k++) {
        b_y += x[(iLeft + b_k) + 249];
      }
    }

    y[k] = b_y / (double)vlen;
  }
}

/*
 * Arguments    : const double x[60501]
 *                double y[60501]
 * Return Type  : void
 */
void c_vmovfun(const double x[60501], double y[60501])
{
  double b_y;
  int b_k;
  int iLeft;
  int k;
  int vlen;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(iLeft,b_k,vlen,b_y)

  for (k = 0; k < 60501; k++) {
    if (k + 1 <= 500) {
      iLeft = -500;
    } else {
      iLeft = k - 1000;
    }

    if (k + 501 > 60501) {
      b_k = 60001;
    } else {
      b_k = k + 1;
    }

    vlen = b_k - iLeft;
    if (vlen == 0) {
      b_y = 0.0;
    } else {
      b_y = x[iLeft + 500];
      for (b_k = 2; b_k <= vlen; b_k++) {
        b_y += x[(iLeft + b_k) + 499];
      }
    }

    y[k] = b_y / (double)vlen;
  }
}

/*
 * Arguments    : const double x[60501]
 *                double y[60501]
 * Return Type  : void
 */
void vmovfun(const double x[60501], double y[60501])
{
  double b_y;
  int b_k;
  int iLeft;
  int k;
  int vlen;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(iLeft,b_k,vlen,b_y)

  for (k = 0; k < 60501; k++) {
    if (k + 1 <= 50) {
      iLeft = -50;
    } else {
      iLeft = k - 100;
    }

    if (k + 51 > 60501) {
      b_k = 60451;
    } else {
      b_k = k + 1;
    }

    vlen = b_k - iLeft;
    if (vlen == 0) {
      b_y = 0.0;
    } else {
      b_y = x[iLeft + 50];
      for (b_k = 2; b_k <= vlen; b_k++) {
        b_y += x[(iLeft + b_k) + 49];
      }
    }

    y[k] = b_y / (double)vlen;
  }
}

/*
 * File trailer for movSumProdOrMean.c
 *
 * [EOF]
 */
