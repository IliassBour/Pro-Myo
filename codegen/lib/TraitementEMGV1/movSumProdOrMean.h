/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movSumProdOrMean.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef MOVSUMPRODORMEAN_H
#define MOVSUMPRODORMEAN_H

/* Include Files */
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_vmovfun(const double x[60501], double y[60501]);
  void c_vmovfun(const double x[60501], double y[60501]);
  void vmovfun(const double x[60501], double y[60501]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for movSumProdOrMean.h
 *
 * [EOF]
 */
