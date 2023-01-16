/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computepsd.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef COMPUTEPSD_H
#define COMPUTEPSD_H

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
  void computepsd(const emxArray_real_T *Sxx1, const emxArray_real_T *w2, const
                  char range[8], emxArray_real_T *varargout_1, emxArray_real_T
                  *varargout_2, char varargout_3_data[], int varargout_3_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for computepsd.h
 *
 * [EOF]
 */
