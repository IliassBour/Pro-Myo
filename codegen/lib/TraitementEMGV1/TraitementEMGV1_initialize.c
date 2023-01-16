/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TraitementEMGV1_initialize.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "TraitementEMGV1_initialize.h"
#include "TraitementEMGV1_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void TraitementEMGV1_initialize(void)
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_TraitementEMGV1 = true;
}

/*
 * File trailer for TraitementEMGV1_initialize.c
 *
 * [EOF]
 */
