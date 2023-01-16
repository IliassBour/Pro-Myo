/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filtfilt.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef FILTFILT_H
#define FILTFILT_H

/* Include Files */
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void filtfilt(const double b[5], const double a[5], double x[60501]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for filtfilt.h
 *
 * [EOF]
 */
