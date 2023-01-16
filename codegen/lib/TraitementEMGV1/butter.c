/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: butter.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "butter.h"
#include "TraitementEMGV1_data.h"
#include "poly.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * Arguments    : const double Wn[2]
 *                double varargout_1[5]
 *                double varargout_2[5]
 * Return Type  : void
 */
void butter(const double Wn[2], double varargout_1[5], double varargout_2[5])
{
  static const signed char iv[8] = { -1, 0, 0, -1, 0, 0, 0, 0 };

  static const signed char b_a[5] = { 1, 0, -2, 0, 1 };

  static const signed char iv1[5] = { 1, 0, -2, 0, 1 };

  creal_T kern[5];
  double b_t1_tmp[16];
  double t1[16];
  double t1_tmp[16];
  double B[4];
  double a[4];
  double Wn1;
  double b_kern_im;
  double b_kern_re;
  double im;
  double kern_im;
  double kern_re;
  double r;
  double s;
  double u_idx_0;
  double u_idx_1;
  int b_tmp;
  int i;
  int ijA;
  int ix;
  int j;
  int jA;
  int jp1j;
  int jy;
  int k;
  int mmj_tmp;
  signed char ipiv[4];
  signed char i1;
  u_idx_0 = 4.0 * tan(3.1415926535897931 * Wn[0] / 2.0);
  u_idx_1 = 4.0 * tan(3.1415926535897931 * Wn[1] / 2.0);
  s = 0.70710678118654746;
  for (k = 2; k >= 2; k--) {
    s -= -0.70710678118654746;
  }

  im = 1.0 - -s * 0.0;
  a[1] = im;
  a[0] = -s - im * 0.0;
  a[3] = 0.0;
  a[2] = -1.0;
  for (i = 0; i < 2; i++) {
    s = a[i + 2];
    im = a[i];
    B[i] = im + s * 0.0;
    B[i + 2] = im * 0.0 + s;
  }

  Wn1 = sqrt(u_idx_0 * u_idx_1);
  u_idx_0 = Wn1 / (u_idx_1 - u_idx_0);
  memset(&t1_tmp[0], 0, 16U * sizeof(double));
  t1_tmp[0] = 1.0;
  t1_tmp[5] = 1.0;
  t1_tmp[10] = 1.0;
  t1_tmp[15] = 1.0;
  b_t1_tmp[0] = Wn1 * (B[0] / u_idx_0) * 0.5 / 2.0;
  u_idx_1 = Wn1 * 0.5 / 2.0;
  b_t1_tmp[8] = u_idx_1;
  b_t1_tmp[1] = Wn1 * (B[1] / u_idx_0) * 0.5 / 2.0;
  s = Wn1 * 0.0 * 0.5 / 2.0;
  b_t1_tmp[9] = s;
  b_t1_tmp[4] = Wn1 * (B[2] / u_idx_0) * 0.5 / 2.0;
  b_t1_tmp[12] = s;
  b_t1_tmp[5] = Wn1 * (B[3] / u_idx_0) * 0.5 / 2.0;
  b_t1_tmp[13] = u_idx_1;
  for (i = 0; i < 4; i++) {
    jA = i << 1;
    jy = i << 2;
    b_t1_tmp[jy + 2] = Wn1 * (double)iv[jA] * 0.5 / 2.0;
    b_t1_tmp[jy + 3] = Wn1 * (double)iv[jA + 1] * 0.5 / 2.0;
  }

  for (i = 0; i < 16; i++) {
    s = t1_tmp[i];
    im = b_t1_tmp[i];
    t1[i] = s + im;
    s -= im;
    t1_tmp[i] = s;
  }

  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j = 0; j < 3; j++) {
    mmj_tmp = 2 - j;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    jy = 4 - j;
    jA = 0;
    ix = b_tmp;
    u_idx_0 = fabs(t1_tmp[b_tmp]);
    for (k = 2; k <= jy; k++) {
      ix++;
      s = fabs(t1_tmp[ix]);
      if (s > u_idx_0) {
        jA = k - 1;
        u_idx_0 = s;
      }
    }

    if (t1_tmp[b_tmp + jA] != 0.0) {
      if (jA != 0) {
        jy = j + jA;
        ipiv[j] = (signed char)(jy + 1);
        u_idx_0 = t1_tmp[j];
        t1_tmp[j] = t1_tmp[jy];
        t1_tmp[jy] = u_idx_0;
        u_idx_0 = t1_tmp[j + 4];
        t1_tmp[j + 4] = t1_tmp[jy + 4];
        t1_tmp[jy + 4] = u_idx_0;
        u_idx_0 = t1_tmp[j + 8];
        t1_tmp[j + 8] = t1_tmp[jy + 8];
        t1_tmp[jy + 8] = u_idx_0;
        u_idx_0 = t1_tmp[j + 12];
        t1_tmp[j + 12] = t1_tmp[jy + 12];
        t1_tmp[jy + 12] = u_idx_0;
      }

      i = (b_tmp - j) + 4;
      for (k = jp1j; k <= i; k++) {
        t1_tmp[k - 1] /= t1_tmp[b_tmp];
      }
    }

    jy = b_tmp + 4;
    jA = b_tmp;
    for (k = 0; k <= mmj_tmp; k++) {
      u_idx_0 = t1_tmp[jy];
      if (t1_tmp[jy] != 0.0) {
        ix = b_tmp + 1;
        i = jA + 6;
        jp1j = (jA - j) + 8;
        for (ijA = i; ijA <= jp1j; ijA++) {
          t1_tmp[ijA - 1] += t1_tmp[ix] * -u_idx_0;
          ix++;
        }
      }

      jy += 4;
      jA += 4;
    }

    i1 = ipiv[j];
    if (i1 != j + 1) {
      u_idx_0 = t1[j];
      t1[j] = t1[i1 - 1];
      t1[i1 - 1] = u_idx_0;
      u_idx_0 = t1[j + 4];
      t1[j + 4] = t1[i1 + 3];
      t1[i1 + 3] = u_idx_0;
      u_idx_0 = t1[j + 8];
      t1[j + 8] = t1[i1 + 7];
      t1[i1 + 7] = u_idx_0;
      u_idx_0 = t1[j + 12];
      t1[j + 12] = t1[i1 + 11];
      t1[i1 + 11] = u_idx_0;
    }
  }

  for (j = 0; j < 4; j++) {
    jA = j << 2;
    if (t1[jA] != 0.0) {
      for (k = 2; k < 5; k++) {
        jy = (k + jA) - 1;
        t1[jy] -= t1[jA] * t1_tmp[k - 1];
      }
    }

    if (t1[jA + 1] != 0.0) {
      for (k = 3; k < 5; k++) {
        jy = (k + jA) - 1;
        t1[jy] -= t1[jA + 1] * t1_tmp[k + 3];
      }
    }

    if (t1[jA + 2] != 0.0) {
      for (k = 4; k < 5; k++) {
        t1[jA + 3] -= t1[jA + 2] * t1_tmp[11];
      }
    }
  }

  for (j = 0; j < 4; j++) {
    jA = j << 2;
    s = t1[jA + 3];
    if (s != 0.0) {
      t1[jA + 3] = s / t1_tmp[15];
      for (k = 0; k < 3; k++) {
        jy = k + jA;
        t1[jy] -= t1[jA + 3] * t1_tmp[k + 12];
      }
    }

    s = t1[jA + 2];
    if (s != 0.0) {
      t1[jA + 2] = s / t1_tmp[10];
      for (k = 0; k < 2; k++) {
        jy = k + jA;
        t1[jy] -= t1[jA + 2] * t1_tmp[k + 8];
      }
    }

    s = t1[jA + 1];
    if (s != 0.0) {
      t1[jA + 1] = s / t1_tmp[5];
      for (k = 0; k < 1; k++) {
        t1[jA] -= t1[jA + 1] * t1_tmp[4];
      }
    }

    s = t1[jA];
    if (s != 0.0) {
      s /= t1_tmp[0];
      t1[jA] = s;
    }
  }

  poly(t1, kern);
  u_idx_1 = 2.0 * rt_atan2d_snf(Wn1, 4.0);
  u_idx_0 = u_idx_1 * 0.0;
  kern_re = 0.0;
  kern_im = 0.0;
  b_kern_re = 0.0;
  b_kern_im = 0.0;
  for (k = 0; k < 5; k++) {
    Wn1 = kern[k].re;
    varargout_2[k] = Wn1;
    s = (double)k * u_idx_0;
    im = (double)k * -u_idx_1;
    kern[k].re = s;
    kern[k].im = im;
    if (im == 0.0) {
      s = exp(s);
      im = 0.0;
      kern[k].re = s;
      kern[k].im = 0.0;
    } else {
      r = exp(s / 2.0);
      s = r * (r * cos(im));
      im = r * (r * sin(im));
      kern[k].re = s;
      kern[k].im = im;
    }

    kern_re += s * Wn1 - im * 0.0;
    kern_im += s * 0.0 + im * Wn1;
    jA = iv1[k];
    b_kern_re += s * (double)jA - im * 0.0;
    b_kern_im += s * 0.0 + im * (double)jA;
  }

  for (i = 0; i < 5; i++) {
    jA = b_a[i];
    u_idx_1 = (double)jA * kern_re;
    im = (double)jA * kern_im;
    if (b_kern_im == 0.0) {
      if (im == 0.0) {
        s = u_idx_1 / b_kern_re;
      } else if (u_idx_1 == 0.0) {
        s = 0.0;
      } else {
        s = u_idx_1 / b_kern_re;
      }
    } else if (b_kern_re == 0.0) {
      if (u_idx_1 == 0.0) {
        s = im / b_kern_im;
      } else if (im == 0.0) {
        s = 0.0;
      } else {
        s = im / b_kern_im;
      }
    } else {
      s = fabs(b_kern_re);
      u_idx_0 = fabs(b_kern_im);
      if (s > u_idx_0) {
        s = b_kern_im / b_kern_re;
        s = (u_idx_1 + s * im) / (b_kern_re + s * b_kern_im);
      } else if (u_idx_0 == s) {
        if (b_kern_re > 0.0) {
          u_idx_0 = 0.5;
        } else {
          u_idx_0 = -0.5;
        }

        if (b_kern_im > 0.0) {
          Wn1 = 0.5;
        } else {
          Wn1 = -0.5;
        }

        s = (u_idx_1 * u_idx_0 + im * Wn1) / s;
      } else {
        s = b_kern_re / b_kern_im;
        s = (s * u_idx_1 + im) / (b_kern_im + s * b_kern_re);
      }
    }

    varargout_1[i] = s;
  }
}

/*
 * File trailer for butter.c
 *
 * [EOF]
 */
