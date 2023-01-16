/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeperiodogram.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef COMPUTEPERIODOGRAM_H
#define COMPUTEPERIODOGRAM_H

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
  void computeperiodogram(const emxArray_real_T *x, double Fs, emxArray_real_T
    *Pxx, emxArray_real_T *F);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for computeperiodogram.h
 *
 * [EOF]
 */
