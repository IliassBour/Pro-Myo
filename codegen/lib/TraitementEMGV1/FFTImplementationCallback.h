/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FFTImplementationCallback.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

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
  void c_FFTImplementationCallback_doH(const emxArray_real_T *x,
    emxArray_creal_T *y, const emxArray_real_T *costab, const emxArray_real_T
    *sintab);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for FFTImplementationCallback.h
 *
 * [EOF]
 */
