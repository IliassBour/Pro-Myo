/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * movmean.c
 *
 * Code generation for function 'movmean'
 *
 */

/* Include files */
#include "movmean.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_movmean(const real_T x[60501], real_T y[60501])
{
  real_T b_y;
  int32_T b_k;
  int32_T iLeft;
  int32_T k;
  int32_T vlen;
  for (k = 0; k < 60501; k++) {
    if (k + 1 <= 500) {
      iLeft = -501;
    } else {
      iLeft = k - 1001;
    }

    if (k + 501 > 60501) {
      b_k = 60000;
    } else {
      b_k = k;
    }

    vlen = b_k - iLeft;
    if (vlen == 0) {
      b_y = 0.0;
    } else {
      b_y = x[iLeft + 501];
      for (b_k = 2; b_k <= vlen; b_k++) {
        b_y += x[(iLeft + b_k) + 500];
      }
    }

    y[k] = b_y / (real_T)vlen;
  }
}

void movmean(const real_T x[60501], real_T y[60501])
{
  real_T b_y;
  int32_T b_k;
  int32_T iLeft;
  int32_T k;
  int32_T vlen;
  for (k = 0; k < 60501; k++) {
    if (k + 1 <= 250) {
      iLeft = -251;
    } else {
      iLeft = k - 501;
    }

    if (k + 251 > 60501) {
      b_k = 60250;
    } else {
      b_k = k;
    }

    vlen = b_k - iLeft;
    if (vlen == 0) {
      b_y = 0.0;
    } else {
      b_y = x[iLeft + 251];
      for (b_k = 2; b_k <= vlen; b_k++) {
        b_y += x[(iLeft + b_k) + 250];
      }
    }

    y[k] = b_y / (real_T)vlen;
  }
}

/* End of code generation (movmean.c) */
