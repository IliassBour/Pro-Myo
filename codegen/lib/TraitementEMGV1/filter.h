/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef FILTER_H
#define FILTER_H

/* Include Files */
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void filter(double b_data[], double a_data[], const double x[12], const double
              zi_data[], double y[12], double zf_data[], int zf_size[1]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for filter.h
 *
 * [EOF]
 */
