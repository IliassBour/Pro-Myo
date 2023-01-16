/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlartg.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef XZLARTG_H
#define XZLARTG_H

/* Include Files */
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>
#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void b_xzlartg(const creal_T f, const creal_T g, double *cs, creal_T *sn);
  void xzlartg(const creal_T f, const creal_T g, double *cs, creal_T *sn,
               creal_T *r);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xzlartg.h
 *
 * [EOF]
 */
