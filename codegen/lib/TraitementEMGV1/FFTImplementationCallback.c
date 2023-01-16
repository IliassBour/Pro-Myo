/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FFTImplementationCallback.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "FFTImplementationCallback.h"
#include "TraitementEMGV1_emxutil.h"
#include "TraitementEMGV1_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_creal_T *y
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 * Return Type  : void
 */
void c_FFTImplementationCallback_doH(const emxArray_real_T *x, emxArray_creal_T *
  y, const emxArray_real_T *costab, const emxArray_real_T *sintab)
{
  emxArray_creal_T *reconVar1;
  emxArray_creal_T *reconVar2;
  double hcostab_data[4097];
  double hsintab_data[4097];
  double b_y_im;
  double temp2_im;
  double temp2_re;
  double temp_im;
  double temp_re;
  double y_im;
  int bitrevIndex_data[8192];
  int wrapIndex_data[8192];
  int i;
  int iheight;
  int ihi;
  int istart;
  int iy;
  int j;
  int ju;
  int k;
  int temp_re_tmp;
  boolean_T tst;
  for (i = 0; i < 4096; i++) {
    iy = ((i + 1) << 1) - 2;
    hcostab_data[i] = costab->data[iy];
    hsintab_data[i] = sintab->data[iy];
  }

  emxInit_creal_T(&reconVar1, 1);
  emxInit_creal_T(&reconVar2, 1);
  iy = reconVar1->size[0];
  reconVar1->size[0] = 8192;
  emxEnsureCapacity_creal_T(reconVar1, iy);
  iy = reconVar2->size[0];
  reconVar2->size[0] = 8192;
  emxEnsureCapacity_creal_T(reconVar2, iy);
  ju = 0;
  iy = 1;
  for (i = 0; i < 8192; i++) {
    reconVar1->data[i].re = sintab->data[i] + 1.0;
    reconVar1->data[i].im = -costab->data[i];
    reconVar2->data[i].re = 1.0 - sintab->data[i];
    reconVar2->data[i].im = costab->data[i];
    if (i + 1 != 1) {
      wrapIndex_data[i] = 8193 - i;
    } else {
      wrapIndex_data[0] = 1;
    }

    bitrevIndex_data[i] = 0;
  }

  for (k = 0; k < 8191; k++) {
    bitrevIndex_data[k] = iy;
    iy = 8192;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju + 1;
  }

  bitrevIndex_data[8191] = iy;
  ju = 0;
  for (i = 0; i < 6722; i++) {
    iy = bitrevIndex_data[i];
    y->data[iy - 1].re = x->data[ju];
    y->data[iy - 1].im = x->data[ju + 1];
    ju += 2;
  }

  for (i = 0; i <= 8190; i += 2) {
    temp_re = y->data[i + 1].re;
    temp_im = y->data[i + 1].im;
    y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
    y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
    y->data[i].re += temp_re;
    y->data[i].im += temp_im;
  }

  iy = 2;
  ju = 4;
  k = 2048;
  iheight = 8189;
  while (k > 0) {
    for (i = 0; i < iheight; i += ju) {
      temp_re_tmp = i + iy;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = k; j < 4096; j += k) {
      temp2_re = hcostab_data[j];
      temp2_im = hsintab_data[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = temp2_re * y->data[temp_re_tmp].re - temp2_im * y->
          data[temp_re_tmp].im;
        temp_im = temp2_re * y->data[temp_re_tmp].im + temp2_im * y->
          data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ju;
      }

      istart++;
    }

    k /= 2;
    iy = ju;
    ju += ju;
    iheight -= iy;
  }

  temp_re = y->data[0].re;
  temp_im = y->data[0].im;
  y_im = y->data[0].re * reconVar1->data[0].im + y->data[0].im * reconVar1->
    data[0].re;
  temp2_re = y->data[0].re;
  b_y_im = -y->data[0].im;
  y->data[0].re = 0.5 * ((y->data[0].re * reconVar1->data[0].re - y->data[0].im *
    reconVar1->data[0].im) + (temp2_re * reconVar2->data[0].re - b_y_im *
    reconVar2->data[0].im));
  y->data[0].im = 0.5 * (y_im + (temp2_re * reconVar2->data[0].im + b_y_im *
    reconVar2->data[0].re));
  y->data[8192].re = 0.5 * ((temp_re * reconVar2->data[0].re - temp_im *
    reconVar2->data[0].im) + (temp_re * reconVar1->data[0].re - -temp_im *
    reconVar1->data[0].im));
  y->data[8192].im = 0.5 * ((temp_re * reconVar2->data[0].im + temp_im *
    reconVar2->data[0].re) + (temp_re * reconVar1->data[0].im + -temp_im *
    reconVar1->data[0].re));
  for (i = 0; i < 4095; i++) {
    temp_re = y->data[i + 1].re;
    temp_im = y->data[i + 1].im;
    iy = wrapIndex_data[i + 1];
    temp2_re = y->data[iy - 1].re;
    temp2_im = y->data[iy - 1].im;
    y_im = y->data[i + 1].re * reconVar1->data[i + 1].im + y->data[i + 1].im *
      reconVar1->data[i + 1].re;
    b_y_im = -y->data[iy - 1].im;
    y->data[i + 1].re = 0.5 * ((y->data[i + 1].re * reconVar1->data[i + 1].re -
      y->data[i + 1].im * reconVar1->data[i + 1].im) + (temp2_re *
      reconVar2->data[i + 1].re - b_y_im * reconVar2->data[i + 1].im));
    y->data[i + 1].im = 0.5 * (y_im + (temp2_re * reconVar2->data[i + 1].im +
      b_y_im * reconVar2->data[i + 1].re));
    y->data[i + 8193].re = 0.5 * ((temp_re * reconVar2->data[i + 1].re - temp_im
      * reconVar2->data[i + 1].im) + (temp2_re * reconVar1->data[i + 1].re -
      -temp2_im * reconVar1->data[i + 1].im));
    y->data[i + 8193].im = 0.5 * ((temp_re * reconVar2->data[i + 1].im + temp_im
      * reconVar2->data[i + 1].re) + (temp2_re * reconVar1->data[i + 1].im +
      -temp2_im * reconVar1->data[i + 1].re));
    y->data[iy - 1].re = 0.5 * ((temp2_re * reconVar1->data[iy - 1].re -
      temp2_im * reconVar1->data[iy - 1].im) + (temp_re * reconVar2->data[iy - 1]
      .re - -temp_im * reconVar2->data[iy - 1].im));
    y->data[iy - 1].im = 0.5 * ((temp2_re * reconVar1->data[iy - 1].im +
      temp2_im * reconVar1->data[iy - 1].re) + (temp_re * reconVar2->data[iy - 1]
      .im + -temp_im * reconVar2->data[iy - 1].re));
    y->data[iy + 8191].re = 0.5 * ((temp2_re * reconVar2->data[iy - 1].re -
      temp2_im * reconVar2->data[iy - 1].im) + (temp_re * reconVar1->data[iy - 1]
      .re - -temp_im * reconVar1->data[iy - 1].im));
    y->data[iy + 8191].im = 0.5 * ((temp2_re * reconVar2->data[iy - 1].im +
      temp2_im * reconVar2->data[iy - 1].re) + (temp_re * reconVar1->data[iy - 1]
      .im + -temp_im * reconVar1->data[iy - 1].re));
  }

  temp_re = y->data[4096].re;
  temp_im = y->data[4096].im;
  y_im = y->data[4096].re * reconVar1->data[4096].im + y->data[4096].im *
    reconVar1->data[4096].re;
  temp2_re = y->data[4096].re;
  b_y_im = -y->data[4096].im;
  y->data[4096].re = 0.5 * ((y->data[4096].re * reconVar1->data[4096].re -
    y->data[4096].im * reconVar1->data[4096].im) + (temp2_re * reconVar2->data
    [4096].re - b_y_im * reconVar2->data[4096].im));
  y->data[4096].im = 0.5 * (y_im + (temp2_re * reconVar2->data[4096].im + b_y_im
    * reconVar2->data[4096].re));
  y->data[12288].re = 0.5 * ((temp_re * reconVar2->data[4096].re - temp_im *
    reconVar2->data[4096].im) + (temp_re * reconVar1->data[4096].re - -temp_im *
    reconVar1->data[4096].im));
  y->data[12288].im = 0.5 * ((temp_re * reconVar2->data[4096].im + temp_im *
    reconVar2->data[4096].re) + (temp_re * reconVar1->data[4096].im + -temp_im *
    reconVar1->data[4096].re));
  emxFree_creal_T(&reconVar2);
  emxFree_creal_T(&reconVar1);
}

/*
 * File trailer for FFTImplementationCallback.c
 *
 * [EOF]
 */
