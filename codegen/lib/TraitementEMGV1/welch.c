/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: welch.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "welch.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "computeperiodogram.h"
#include "computepsd.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double x[60501]
 *                const char options_range[8]
 *                emxArray_real_T *Pxx
 *                emxArray_real_T *w
 *                char units_data[]
 *                int units_size[2]
 * Return Type  : void
 */
void localComputeSpectra(const double x[60501], const char options_range[8],
  emxArray_real_T *Pxx, emxArray_real_T *w, char units_data[], int units_size[2])
{
  emxArray_real_T b_w1;
  emxArray_real_T *Sxx1;
  emxArray_real_T *Sxxk;
  emxArray_real_T *b_x;
  emxArray_real_T *w1;
  int c_Sxx1[2];
  int b_Sxx1;
  int i;
  int ii;
  int loop_ub;
  emxInit_real_T(&Sxx1, 2);
  Sxx1->size[0] = 0;
  Sxx1->size[1] = 0;
  emxInit_real_T(&Sxxk, 1);
  emxInit_real_T(&b_x, 1);
  for (ii = 0; ii < 8; ii++) {
    i = 6722 * ii;
    loop_ub = (6722 * ii - i) + 13443;
    b_Sxx1 = b_x->size[0];
    b_x->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_x, b_Sxx1);
    for (b_Sxx1 = 0; b_Sxx1 <= loop_ub; b_Sxx1++) {
      b_x->data[b_Sxx1] = x[i + b_Sxx1];
    }

    computeperiodogram(b_x, 1000.0, Sxxk, w);
    if (ii + 1 == 1) {
      i = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = 16384;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_real_T(Sxx1, i);
      for (i = 0; i < 16384; i++) {
        Sxx1->data[i] = Sxxk->data[i];
      }
    } else {
      b_Sxx1 = Sxx1->size[0];
      i = Sxxk->size[0];
      Sxxk->size[0] = Sxx1->size[0];
      emxEnsureCapacity_real_T(Sxxk, i);
      loop_ub = Sxx1->size[0];
      for (i = 0; i < loop_ub; i++) {
        Sxxk->data[i] += Sxx1->data[i];
      }

      loop_ub = Sxx1->size[0];
      i = Sxx1->size[0] * Sxx1->size[1];
      Sxx1->size[0] = loop_ub;
      Sxx1->size[1] = 1;
      emxEnsureCapacity_real_T(Sxx1, i);
      for (i = 0; i < b_Sxx1; i++) {
        Sxx1->data[i] = Sxxk->data[i];
      }
    }
  }

  emxFree_real_T(&b_x);
  emxFree_real_T(&Sxxk);
  loop_ub = Sxx1->size[0] * Sxx1->size[1];
  for (i = 0; i < loop_ub; i++) {
    Sxx1->data[i] /= 8.0;
  }

  emxInit_real_T(&w1, 2);
  i = w1->size[0] * w1->size[1];
  w1->size[0] = 1;
  w1->size[1] = 16384;
  emxEnsureCapacity_real_T(w1, i);
  for (i = 0; i < 16384; i++) {
    w1->data[i] = 0.06103515625 * (double)i;
  }

  w1->data[8192] = 500.0;
  w1->data[16383] = 999.93896484375;
  b_w1 = *w1;
  c_Sxx1[0] = 16384;
  c_Sxx1[1] = 1;
  b_w1.size = &c_Sxx1[0];
  b_w1.numDimensions = 2;
  computepsd(Sxx1, &b_w1, options_range, Pxx, w, units_data, units_size);
  emxFree_real_T(&w1);
  emxFree_real_T(&Sxx1);
}

/*
 * File trailer for welch.c
 *
 * [EOF]
 */
