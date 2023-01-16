/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computepsd.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "computepsd.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *Sxx1
 *                const emxArray_real_T *w2
 *                const char range[8]
 *                emxArray_real_T *varargout_1
 *                emxArray_real_T *varargout_2
 *                char varargout_3_data[]
 *                int varargout_3_size[2]
 * Return Type  : void
 */
void computepsd(const emxArray_real_T *Sxx1, const emxArray_real_T *w2, const
                char range[8], emxArray_real_T *varargout_1, emxArray_real_T
                *varargout_2, char varargout_3_data[], int varargout_3_size[2])
{
  static const char b[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  emxArray_real_T *Sxx_unscaled;
  emxArray_real_T *varargin_2;
  double Sxx_unscaled_data[1];
  double varargin_3_data[1];
  int c_input_sizes_idx_0;
  int i;
  int i1;
  int i2;
  int result;
  int ret;
  short b_input_sizes_idx_0;
  short sizes_idx_0;
  signed char input_sizes_idx_0;
  boolean_T empty_non_axis_sizes;
  ret = memcmp(&range[0], &b[0], 8);
  if (ret == 0) {
    emxInit_real_T(&Sxx_unscaled, 2);
    ret = Sxx1->size[1];
    i = Sxx_unscaled->size[0] * Sxx_unscaled->size[1];
    Sxx_unscaled->size[0] = 8193;
    Sxx_unscaled->size[1] = Sxx1->size[1];
    emxEnsureCapacity_real_T(Sxx_unscaled, i);
    for (i = 0; i < ret; i++) {
      for (i1 = 0; i1 < 8193; i1++) {
        Sxx_unscaled->data[i1 + Sxx_unscaled->size[0] * i] = Sxx1->data[i1 +
          Sxx1->size[0] * i];
      }
    }

    emxInit_real_T(&varargin_2, 2);
    ret = Sxx1->size[1] - 1;
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 8191;
    varargin_2->size[1] = Sxx1->size[1];
    emxEnsureCapacity_real_T(varargin_2, i);
    for (i = 0; i <= ret; i++) {
      for (i1 = 0; i1 < 8191; i1++) {
        varargin_2->data[i1 + varargin_2->size[0] * i] = 2.0 *
          Sxx_unscaled->data[(i1 + Sxx_unscaled->size[0] * i) + 1];
      }
    }

    ret = Sxx1->size[1] - 1;
    for (i = 0; i <= ret; i++) {
      varargin_3_data[i] = Sxx_unscaled->data[Sxx_unscaled->size[0] * i + 8192];
    }

    if (Sxx1->size[1] != 0) {
      result = Sxx1->size[1];
    } else if (varargin_2->size[1] != 0) {
      result = (short)Sxx1->size[1];
    } else if (Sxx1->size[1] != 0) {
      result = Sxx1->size[1];
    } else {
      if (Sxx1->size[1] > 0) {
        result = Sxx1->size[1];
      } else {
        result = 0;
      }

      if ((short)Sxx1->size[1] > result) {
        result = 1;
      }

      if (Sxx1->size[1] > result) {
        result = Sxx1->size[1];
      }
    }

    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes || (Sxx1->size[1] != 0)) {
      input_sizes_idx_0 = 1;
    } else {
      input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || (varargin_2->size[1] != 0)) {
      b_input_sizes_idx_0 = 8191;
    } else {
      b_input_sizes_idx_0 = 0;
    }

    if (empty_non_axis_sizes || (Sxx1->size[1] != 0)) {
      sizes_idx_0 = 1;
    } else {
      sizes_idx_0 = 0;
    }

    ret = Sxx1->size[1] - 1;
    for (i = 0; i <= ret; i++) {
      Sxx_unscaled_data[i] = Sxx_unscaled->data[Sxx_unscaled->size[0] * i];
    }

    emxFree_real_T(&Sxx_unscaled);
    c_input_sizes_idx_0 = b_input_sizes_idx_0;
    i = varargout_1->size[0] * varargout_1->size[1];
    i1 = input_sizes_idx_0 + b_input_sizes_idx_0;
    varargout_1->size[0] = i1 + sizes_idx_0;
    varargout_1->size[1] = result;
    emxEnsureCapacity_real_T(varargout_1, i);
    for (i = 0; i < result; i++) {
      ret = input_sizes_idx_0;
      for (i2 = 0; i2 < ret; i2++) {
        varargout_1->data[varargout_1->size[0] * i] =
          Sxx_unscaled_data[input_sizes_idx_0 * i];
      }
    }

    for (i = 0; i < result; i++) {
      for (i2 = 0; i2 < c_input_sizes_idx_0; i2++) {
        varargout_1->data[(i2 + input_sizes_idx_0) + varargout_1->size[0] * i] =
          varargin_2->data[i2 + varargin_2->size[0] * i];
      }
    }

    emxFree_real_T(&varargin_2);
    for (i = 0; i < result; i++) {
      ret = sizes_idx_0;
      for (i2 = 0; i2 < ret; i2++) {
        varargout_1->data[i1 + varargout_1->size[0] * i] =
          varargin_3_data[sizes_idx_0 * i];
      }
    }

    i = varargout_2->size[0];
    varargout_2->size[0] = 8193;
    emxEnsureCapacity_real_T(varargout_2, i);
    for (i = 0; i < 8193; i++) {
      varargout_2->data[i] = w2->data[i];
    }
  } else {
    i = varargout_1->size[0] * varargout_1->size[1];
    varargout_1->size[0] = Sxx1->size[0];
    varargout_1->size[1] = Sxx1->size[1];
    emxEnsureCapacity_real_T(varargout_1, i);
    ret = Sxx1->size[0] * Sxx1->size[1];
    for (i = 0; i < ret; i++) {
      varargout_1->data[i] = Sxx1->data[i];
    }

    i = varargout_2->size[0];
    varargout_2->size[0] = w2->size[0];
    emxEnsureCapacity_real_T(varargout_2, i);
    ret = w2->size[0];
    for (i = 0; i < ret; i++) {
      varargout_2->data[i] = w2->data[i];
    }
  }

  ret = varargout_1->size[0] * varargout_1->size[1];
  for (i = 0; i < ret; i++) {
    varargout_1->data[i] /= 1000.0;
  }

  varargout_3_size[0] = 1;
  varargout_3_size[1] = 2;
  varargout_3_data[0] = 'H';
  varargout_3_data[1] = 'z';
}

/*
 * File trailer for computepsd.c
 *
 * [EOF]
 */
