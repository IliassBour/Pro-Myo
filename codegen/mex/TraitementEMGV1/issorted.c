/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * issorted.c
 *
 * Code generation for function 'issorted'
 *
 */

/* Include files */
#include "issorted.h"
#include "TraitementEMGV1_data.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
boolean_T issorted(const emxArray_int32_T *x)
{
  int32_T b_n;
  int32_T dim;
  int32_T k;
  int32_T n;
  uint16_T subs[2];
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T y;
  y = true;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  if (x->size[0] != 0) {
    if (dim <= 1) {
      n = x->size[0];
    } else {
      n = 1;
    }

    if (n != 1) {
      if (dim == 2) {
        n = -1;
      } else {
        n = 0;
      }

      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= n)) {
        if (dim == 1) {
          b_n = x->size[0] - 1;
        } else {
          b_n = x->size[0];
        }

        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k <= b_n - 1)) {
          subs[0] = (uint16_T)(k + 1);
          subs[1] = 1U;
          subs[dim - 1]++;
          if (x->data[k] > x->data[subs[0] - 1]) {
            y = false;
          }

          if (!y) {
            exitg2 = true;
          } else {
            k++;
          }
        }

        if (!y) {
          exitg1 = true;
        } else {
          k = 1;
        }
      }
    }
  }

  return y;
}

/* End of code generation (issorted.c) */
