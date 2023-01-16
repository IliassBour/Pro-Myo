/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: trisolve.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "trisolve.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double A[4]
 *                double B[2]
 * Return Type  : void
 */
void trisolve(const double A[4], double B[2])
{
  int i;
  if (B[1] != 0.0) {
    B[1] /= A[3];
    for (i = 0; i < 1; i++) {
      B[0] -= B[1] * A[2];
    }
  }

  if (B[0] != 0.0) {
    B[0] /= A[0];
  }
}

/*
 * File trailer for trisolve.c
 *
 * [EOF]
 */
