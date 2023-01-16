/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgerc.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "xgerc.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int m
 *                int n
 *                double alpha1
 *                int ix0
 *                const double y[2]
 *                double A[121002]
 *                int ia0
 * Return Type  : void
 */
void xgerc(int m, int n, double alpha1, int ix0, const double y[2], double A
           [121002], int ia0)
{
  double temp;
  int i;
  int ijA;
  int ix;
  int j;
  int jA;
  int jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        i = m + jA;
        for (ijA = jA; ijA < i; ijA++) {
          A[ijA - 1] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 60501;
    }
  }
}

/*
 * File trailer for xgerc.c
 *
 * [EOF]
 */
