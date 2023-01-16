/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.c
 *
 * Code generation for function 'insertionsort'
 *
 */

/* Include files */
#include "insertionsort.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void insertionsort(int32_T x[10], const cell_wrap_38 cmp_tunableEnvironment[2])
{
  int32_T idx;
  int32_T k;
  int32_T xc;
  boolean_T exitg1;
  boolean_T varargout_1;
  for (k = 0; k < 9; k++) {
    xc = x[k + 1] - 1;
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      if (cmp_tunableEnvironment[0].f1[xc] < cmp_tunableEnvironment[0].f1[x[idx]
          - 1]) {
        varargout_1 = true;
      } else if (cmp_tunableEnvironment[0].f1[xc] == cmp_tunableEnvironment[0].
                 f1[x[idx] - 1]) {
        varargout_1 = (cmp_tunableEnvironment[1].f1[xc] <
                       cmp_tunableEnvironment[1].f1[x[idx] - 1]);
      } else {
        varargout_1 = false;
      }

      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }

    x[idx + 1] = xc + 1;
  }
}

/* End of code generation (insertionsort.c) */
