/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzhgeqz.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef XZHGEQZ_H
#define XZHGEQZ_H

/* Include Files */
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void xzhgeqz(const creal_T A[16], int ilo, int ihi, int *info, creal_T alpha1
               [4], creal_T beta1[4]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xzhgeqz.h
 *
 * [EOF]
 */