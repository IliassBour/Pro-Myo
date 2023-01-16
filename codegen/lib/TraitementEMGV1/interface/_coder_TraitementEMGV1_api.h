/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_TraitementEMGV1_api.h
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Jan-2023 12:44:59
 */

#ifndef _CODER_TRAITEMENTEMGV1_API_H
#define _CODER_TRAITEMENTEMGV1_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T position[285];
  real_T vitesse[285];
  real_T EMG[242004];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus

extern "C" {

#endif

  /* Function Declarations */
  void TraitementEMGV1(struct0_T *P, real_T Rect[60501], real_T MAW1[60501],
                       real_T MAW2[60501], real_T MAW3[60501], real_T
                       *TempsPousse, real_T *TempsRecov);
  void TraitementEMGV1_api(const mxArray * const prhs[1], int32_T nlhs, const
    mxArray *plhs[6]);
  void TraitementEMGV1_atexit(void);
  void TraitementEMGV1_initialize(void);
  void TraitementEMGV1_terminate(void);
  void TraitementEMGV1_xil_shutdown(void);
  void TraitementEMGV1_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_TraitementEMGV1_api.h
 *
 * [EOF]
 */
