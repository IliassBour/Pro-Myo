/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trisolve.c
 *
 * Code generation for function 'trisolve'
 *
 */

/* Include files */
#include "trisolve.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void trisolve(const real_T A[4], real_T B[2])
{
  int32_T i;
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

/* End of code generation (trisolve.c) */
