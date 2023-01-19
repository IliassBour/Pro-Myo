/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TraitementEMGV1.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef TRAITEMENTEMGV1_H
#define TRAITEMENTEMGV1_H

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
  extern void TraitementEMGV1(const struct0_T *P, double Rect[60501], double
    MAW1[60501], double MAW2[60501], double MAW3[60501], double *TempsPousse,
    double *TempsRecov);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for TraitementEMGV1.h
 *
 * [EOF]
 */
