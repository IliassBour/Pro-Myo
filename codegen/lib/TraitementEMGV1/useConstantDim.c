/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: useConstantDim.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "useConstantDim.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *varargin_2
 *                int varargin_3
 * Return Type  : void
 */
void useConstantDim(emxArray_real_T *varargin_2, int varargin_3)
{
  double x_data[1];
  int b_k;
  int i;
  int i1;
  int k;
  int loop_ub;
  int x_size_idx_0;
  int x_size_idx_1;
  if (1 == varargin_3) {
    if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
      i = varargin_2->size[1];
      for (k = 0; k < i; k++) {
        i1 = varargin_2->size[0];
        for (b_k = 0; b_k <= i1 - 2; b_k++) {
          varargin_2->data[(short)(b_k + 1)] += varargin_2->data[b_k];
        }
      }
    }
  } else {
    if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
      i = varargin_2->size[1];
      for (k = 0; k <= i - 2; k++) {
        x_size_idx_0 = varargin_2->size[0];
        x_size_idx_1 = varargin_2->size[1];
        loop_ub = varargin_2->size[0] * varargin_2->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          x_data[i1] = varargin_2->data[i1];
        }

        i1 = varargin_2->size[0];
        for (b_k = 0; b_k < i1; b_k++) {
          loop_ub = ((short)(b_k + 1) + x_size_idx_0 * ((short)((short)(k + 1) +
            1) - 1)) - 1;
          x_data[loop_ub] += x_data[b_k + x_size_idx_0 * k];
        }

        i1 = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = x_size_idx_0;
        varargin_2->size[1] = x_size_idx_1;
        emxEnsureCapacity_real_T(varargin_2, i1);
        for (i1 = 0; i1 < x_size_idx_1; i1++) {
          for (loop_ub = 0; loop_ub < x_size_idx_0; loop_ub++) {
            varargin_2->data[loop_ub + varargin_2->size[0] * i1] =
              x_data[loop_ub + x_size_idx_0 * i1];
          }
        }
      }
    }
  }
}

/*
 * File trailer for useConstantDim.c
 *
 * [EOF]
 */
