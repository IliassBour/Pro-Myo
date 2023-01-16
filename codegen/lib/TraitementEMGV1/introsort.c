/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: introsort.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "introsort.h"
#include "TraitementEMGV1_internal_types.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : int x[10]
 *                const cell_wrap_38 cmp_tunableEnvironment[2]
 * Return Type  : void
 */
void introsort(int x[10], const cell_wrap_38 cmp_tunableEnvironment[2])
{
  insertionsort(x, cmp_tunableEnvironment);
}

/*
 * File trailer for introsort.c
 *
 * [EOF]
 */
