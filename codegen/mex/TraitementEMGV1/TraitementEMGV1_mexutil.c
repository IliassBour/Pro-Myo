/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * TraitementEMGV1_mexutil.c
 *
 * Code generation for function 'TraitementEMGV1_mexutil'
 *
 */

/* Include files */
#include "TraitementEMGV1_mexutil.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/* End of code generation (TraitementEMGV1_mexutil.c) */
