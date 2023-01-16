/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: welch.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef WELCH_H
#define WELCH_H

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
  void localComputeSpectra(const double x[60501], const char options_range[8],
    emxArray_real_T *Pxx, emxArray_real_T *w, char units_data[], int units_size
    [2]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for welch.h
 *
 * [EOF]
 */
