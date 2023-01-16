/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TraitementEMGV1_emxutil.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef TRAITEMENTEMGV1_EMXUTIL_H
#define TRAITEMENTEMGV1_EMXUTIL_H

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
  extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);
  extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
  extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
  extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
  extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
  extern void emxFree_real_T(emxArray_real_T **pEmxArray);
  extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);
  extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
  extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for TraitementEMGV1_emxutil.h
 *
 * [EOF]
 */
