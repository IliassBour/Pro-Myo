/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

/* Include Files */
#include "filter.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double b_data[]
 *                double a_data[]
 *                const double x[12]
 *                const double zi_data[]
 *                double y[12]
 *                double zf_data[]
 *                int zf_size[1]
 * Return Type  : void
 */
void filter(double b_data[], double a_data[], const double x[12], const double
            zi_data[], double y[12], double zf_data[], int zf_size[1])
{
  double a1;
  int j;
  int k;
  int naxpy;
  int y_tmp;
  a1 = a_data[0];
  if ((!rtIsInf(a_data[0])) && (!rtIsNaN(a_data[0])) && (!(a_data[0] == 0.0)) &&
      (a_data[0] != 1.0)) {
    for (k = 0; k < 5; k++) {
      b_data[k] /= a1;
    }

    a_data[1] /= a_data[0];
    a_data[2] /= a_data[0];
    a_data[3] /= a_data[0];
    a_data[4] /= a_data[0];
    a_data[0] = 1.0;
  }

  zf_size[0] = 4;
  zf_data[0] = 0.0;
  y[0] = zi_data[0];
  zf_data[1] = 0.0;
  y[1] = zi_data[1];
  zf_data[2] = 0.0;
  y[2] = zi_data[2];
  zf_data[3] = 0.0;
  y[3] = zi_data[3];
  memset(&y[4], 0, 8U * sizeof(double));
  for (k = 0; k < 12; k++) {
    if (12 - k < 5) {
      naxpy = 11 - k;
    } else {
      naxpy = 4;
    }

    for (j = 0; j <= naxpy; j++) {
      y_tmp = k + j;
      y[y_tmp] += x[k] * b_data[j];
    }

    if (11 - k < 4) {
      naxpy = 10 - k;
    } else {
      naxpy = 3;
    }

    a1 = -y[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y[y_tmp] += a1 * a_data[j + 1];
    }
  }

  for (j = 0; j < 1; j++) {
    zf_data[0] += x[8] * b_data[4];
  }

  for (j = 0; j < 2; j++) {
    zf_data[j] += x[9] * b_data[j + 3];
  }

  for (j = 0; j < 3; j++) {
    zf_data[j] += x[10] * b_data[j + 2];
  }

  for (j = 0; j < 4; j++) {
    zf_data[j] += x[11] * b_data[j + 1];
  }

  for (j = 0; j < 1; j++) {
    zf_data[0] += -y[8] * a_data[4];
  }

  for (j = 0; j < 2; j++) {
    zf_data[j] += -y[9] * a_data[j + 3];
  }

  for (j = 0; j < 3; j++) {
    zf_data[j] += -y[10] * a_data[j + 2];
  }

  for (j = 0; j < 4; j++) {
    zf_data[j] += -y[11] * a_data[j + 1];
  }
}

/*
 * File trailer for filter.c
 *
 * [EOF]
 */
