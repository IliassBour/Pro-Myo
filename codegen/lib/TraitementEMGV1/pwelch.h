/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pwelch.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef PWELCH_H
#define PWELCH_H

/* Include Files */
#include "TraitementEMGV1_types.h"
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void pwelch(const double x[60501], emxArray_real_T *varargout_1,
              emxArray_real_T *varargout_2);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for pwelch.h
 *
 * [EOF]
 */
