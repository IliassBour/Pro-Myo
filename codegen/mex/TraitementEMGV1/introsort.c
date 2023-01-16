/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "introsort.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_internal_types.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void introsort(int32_T x[10], const cell_wrap_38 cmp_tunableEnvironment[2])
{
  insertionsort(x, cmp_tunableEnvironment);
}

/* End of code generation (introsort.c) */
